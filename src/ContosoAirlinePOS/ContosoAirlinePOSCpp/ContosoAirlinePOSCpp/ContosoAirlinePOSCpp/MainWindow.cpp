#include "pch.h"
#include "MainWindow.h"
#include "INavigationService.h"
#include "MainWindow.g.cpp"
#include <winrt/Windows.UI.Xaml.Interop.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;
using namespace winrt::ContosoAirlinePOSCpp::implementation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    MainWindow::MainWindow()
    {
        INavigationService _navigationService;
        InitializeComponent();
        Frame rootFrame = MainFrame();
        _navigationService.InitializeFrame(rootFrame);
        _navigationService.NavigateTo(xaml_typename<LoginPage>());
    }

    void MainWindow::MainFrame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {
        if (!MainFrame().CanGoBack()) 
        {
            INavigationService _navigationService;
            _navigationService.InitializeFrame(MainFrame());
        }
    }
}
