#include "pch.h"
#include "MainWindow.h"
#include "MainWindow.g.cpp"

#include <chrono>
#include <tchar.h>
#include <psapi.h>
#include <filesystem>
#include <iostream>
#include <fstream>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Storage::Streams;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Documents;
using namespace Microsoft::UI::Xaml::Controls;


namespace winrt::DemoBuildCpp::implementation
{
	MainWindow::MainWindow()
	{
		InitializeComponent();
	}
}

void winrt::DemoBuildCpp::implementation::MainWindow::OnThemeRadioButtonChecked(IInspectable const& sender, RoutedEventArgs const& e)
{
	RadioButton radiobutton = sender.as<RadioButton>();
	if (radiobutton != nullptr && radiobutton.Tag() != nullptr)
	{
		winrt::hstring selectedTheme = unbox_value<winrt::hstring>(radiobutton.Tag());

		SplitView splitView = radiobutton.XamlRoot().Content().as<SplitView>();
		if (winrt::to_string(selectedTheme) == "Dark") {
			splitView.RequestedTheme(Microsoft::UI::Xaml::ElementTheme::Dark);
		}
		else
		{
			splitView.RequestedTheme(Microsoft::UI::Xaml::ElementTheme::Light);
		}
	}
}



void winrt::DemoBuildCpp::implementation::MainWindow::OnRun(IInspectable const& sender, RoutedEventArgs const& e)
{
	std::string list;
	winrt::hstring filePath = folderTextBox().Text();

	// Create a Path object from given path string
	std::filesystem::path pathObj(winrt::to_string(filePath));
	// Check if path exists and is of a regular file
	if (std::filesystem::exists(pathObj) && std::filesystem::is_directory(pathObj))
	{
		statusTextBlock().Text(L"Status: running");

		int depth = (int)numberBox().Value();

		list.clear();
		auto start = std::chrono::high_resolution_clock::now();
		ListDirectories(winrt::to_string(filePath), depth, list);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds> (diff);   // truncated

		richTextBlock().Blocks().Clear();
		Paragraph paragraph = Paragraph();
		Run run = Run();
		run.Text(winrt::to_hstring(list));
		paragraph.Inlines().Append(run);
		richTextBlock().Blocks().Append(paragraph);
		std::string status;
		status.append("Status: completed in ");
		status.append(std::to_string(ms.count()));
		status.append(" ms");
		statusTextBlock().Text(winrt::to_hstring(status));
	}
}

void winrt::DemoBuildCpp::implementation::MainWindow::ListDirectories(std::string dir, int depth, std::string& list)
{
	if (depth < 0)
		return;
	std::filesystem::path pathObj(dir);
	for (auto& p : std::filesystem::directory_iterator(pathObj, std::filesystem::directory_options::follow_directory_symlink))
	{
		try
		{
			if (std::filesystem::is_directory(p))
			{
				list.append(p.path().generic_string());
				list.append("\n");

				ListDirectories(p.path().generic_string(), depth - 1, list);
			}
		}
		catch (const std::filesystem::filesystem_error& e) {}
	}
}



void winrt::DemoBuildCpp::implementation::MainWindow::OnHelp(IInspectable const& sender, RoutedEventArgs const& e)
{
	teachingTip().IsOpen(true);
}


void winrt::DemoBuildCpp::implementation::MainWindow::OnSettings(IInspectable const& sender, RoutedEventArgs const& e)
{
	splitView().IsPaneOpen(!splitView().IsPaneOpen());
}


void winrt::DemoBuildCpp::implementation::MainWindow::OnPaneOpened(SplitView const& sender, IInspectable const& args)
{
	std::string currentTheme;
	if (sender.RequestedTheme() == ElementTheme::Default) 
	{
		Application::Current().RequestedTheme() == ApplicationTheme::Dark ? currentTheme = "Dark" : currentTheme = "Light";
	}
	else
	{
		sender.RequestedTheme() == ElementTheme::Dark ? currentTheme = "Dark" : currentTheme = "Light";
	}
	for (auto uielememnt : themePanel().Children())
	{
		RadioButton radiobutton = uielememnt.as<RadioButton>();
		winrt::hstring selectedTheme = unbox_value<winrt::hstring>(radiobutton.Tag());
		if (winrt::to_string(selectedTheme) == currentTheme) {
			radiobutton.IsChecked(true);
			break;
		}
	}
}

void winrt::DemoBuildCpp::implementation::MainWindow::PickFolder()
{
	winrt::Windows::Storage::Pickers::FolderPicker picker;
	HWND hwnd = GetActiveWindow();

	const auto initializeWithWindow = picker.as<IInitializeWithWindow>();
	winrt::check_hresult(initializeWithWindow->Initialize(hwnd));

	const auto task = picker.PickSingleFolderAsync();
	task.Completed([](const IAsyncOperation<winrt::Windows::Storage::StorageFolder>& result, AsyncStatus const status) mutable
	{
		const auto storageFolder = result.get();
		if ((status == AsyncStatus::Completed) && storageFolder)
		{
			winrt::hstring path = storageFolder.Path();

		}
		else
		{

		}
	});
}

void winrt::DemoBuildCpp::implementation::MainWindow::OnBrowse(IInspectable const& sender, RoutedEventArgs const& e)
{
	//PickFolder();

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr))
	{
		IFileOpenDialog* pFileOpen;

		// Create the FileOpenDialog object.
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		if (SUCCEEDED(hr))
		{
			DWORD dwFlags;
			// Before setting, always get the options first in order 
		    // not to override existing options.
			hr = pFileOpen->GetOptions(&dwFlags);
			if (SUCCEEDED(hr))
			{
				// In this case, get shell items only for file system items.
				hr = pFileOpen->SetOptions(dwFlags | FOS_PICKFOLDERS);
				if (SUCCEEDED(hr))
				{

					// Show the Open dialog box.
					hr = pFileOpen->Show(NULL);

					// Get the file name from the dialog box.
					if (SUCCEEDED(hr))
					{
						IShellItem* pItem;
						hr = pFileOpen->GetResult(&pItem);
						if (SUCCEEDED(hr))
						{
							PWSTR pszFilePath;
							hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

							// Display the file name to the user.
							if (SUCCEEDED(hr))
							{
								folderTextBox().Text(pszFilePath);
								CoTaskMemFree(pszFilePath);
							}
							pItem->Release();
						}
					}
					pFileOpen->Release();
				}
			}
		}
		CoUninitialize();
	}
}

void winrt::DemoBuildCpp::implementation::MainWindow::OnWindowMinimize(IInspectable const& sender, RoutedEventArgs const& e)
{
	const int SHOWMINIMIZED_PARAM = 2;
	HWND hwnd = GetActiveWindow();
	ShowWindow(hwnd, SHOWMINIMIZED_PARAM);
}


void winrt::DemoBuildCpp::implementation::MainWindow::OnWindowMaximize(IInspectable const& sender, RoutedEventArgs const& e)
{
	const int SHOWMAXIMIZED_PARAM = 3;
	HWND hwnd = GetActiveWindow();
	ShowWindow(hwnd, SHOWMAXIMIZED_PARAM);
}


void winrt::DemoBuildCpp::implementation::MainWindow::OnWindowNormalize(IInspectable const& sender, RoutedEventArgs const& e)
{
	const int SHOWNORMAL_PARAM = 1;
	HWND hwnd = GetActiveWindow();
	ShowWindow(hwnd, SHOWNORMAL_PARAM);
}

void winrt::DemoBuildCpp::implementation::MainWindow::OnSendToBottom(IInspectable const& sender, RoutedEventArgs const& e)
{
	HWND hwnd = GetActiveWindow();
	SetWindowPos(hwnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

}


void winrt::DemoBuildCpp::implementation::MainWindow::OnAbout(IInspectable const& sender, RoutedEventArgs const& e)
{
	splitView().IsPaneOpen(false);

	std::string description = "";
	DWORD currentProcess = GetCurrentProcessId();
	description.append(PrintProcessNameAndID(currentProcess));
	cdTextBlock().Text(winrt::to_hstring(description));
	contentDialog().XamlRoot() = gridRoot().XamlRoot();
	contentDialog().ShowAsync();
}


std::string winrt::DemoBuildCpp::implementation::MainWindow::PrintProcessNameAndID(DWORD processID)
{
	std::string description = "";

	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;
		HMODULE hMods[1024];

		if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
		{
			for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
			{
				TCHAR szModName[MAX_PATH];

				// Get the full path to the module's file.

				if (GetModuleFileNameEx(hProcess, hMods[i], szModName,
					sizeof(szModName) / sizeof(TCHAR)))
				{
					// Print the process name and identifier.
					std::wstring des(szModName);
					description.append(des.begin(), des.end());
					description.append("\n");
				}
			}

		}

		// Release the handle to the process.

		CloseHandle(hProcess);
		return description;
	}
}


void winrt::DemoBuildCpp::implementation::MainWindow::OnKeyDownTextBox(IInspectable const& sender, Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e)
{
	if (e.Key() == Windows::System::VirtualKey::Enter)
	{
		OnRun(nullptr, nullptr);
	}
}


