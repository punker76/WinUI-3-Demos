#include "pch.h"

#include "App.xaml.h"
#include "MainWindow.xaml.h"
#include "microsoft.ui.xaml.window.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace DemoBuildCpp;
using namespace DemoBuildCpp::implementation;


/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App()
{
    InitializeComponent();
    Suspending({ this, &App::OnSuspending });

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
    UnhandledException([this](IInspectable const&, UnhandledExceptionEventArgs const& e)
    {
        if (IsDebuggerPresent())
        {
            auto errorMessage = e.Message();
            __debugbreak();
        }
    });
#endif
}

void App::OnLaunched(LaunchActivatedEventArgs const&)
{
    HWND hwnd;
    window = make<MainWindow>();
    window.as<IWindowNative>()->get_WindowHandle(&hwnd);
    window.Activate();
    // Window doesn't have Height and Weight properties in WInUI 3 Desktop yet,
    // to set the Width and Height you can use the Win32 API SetWindowPos.
    //However, you should have to take care of the DPI scale factor
    setWindowSize(hwnd, 800, 600);
}

void winrt::DemoBuildCpp::implementation::App::setWindowSize(const HWND& hwnd, int width, int height)
{
    auto dpi = GetDpiForWindow(hwnd);
    float scalingFactor = static_cast<float>(dpi) / 96;
    RECT scale;
    scale.left = 0;
    scale.top = 0;
    scale.right = static_cast<LONG>(width * scalingFactor);
    scale.bottom = static_cast<LONG>(height * scalingFactor);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, scale.right - scale.left, scale.bottom - scale.top, SWP_NOMOVE);
}

void App::OnSuspending([[maybe_unused]] IInspectable const& sender, [[maybe_unused]] Windows::ApplicationModel::SuspendingEventArgs const& e)
{
    // This is never called in WInUi 3 in Desktop Preview 3
}