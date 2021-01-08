#include "pch.h"
#include "ShellPage.xaml.h"
#if __has_include("ShellPage.g.cpp")
#include "ShellPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Navigation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    ShellPage::ShellPage()
    {
        m_shellViewModel = winrt::make<ContosoAirlinePOSCpp::implementation::ShellViewModel>();

        InitializeComponent();

        m_navigationService.InitializeFrame(MainContentFrame());
    }

    ContosoAirlinePOSCpp::ShellViewModel ShellPage::ViewModel()
    {
        return m_shellViewModel;
    }
    
    void ShellPage::NavView_Loaded(Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        m_navigationService.NavigateTo(xaml_typename<ContosoAirlinePOSCpp::BookFlightPage>());
    }

    void ShellPage::NavView_ItemInvoked(Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs const& args)
    {        
        if (!args.IsSettingsInvoked())
        {
            auto tag = winrt::unbox_value<hstring>(args.InvokedItemContainer().Tag());
            if (wcscmp(tag.c_str(), L"Search") == 0)
            {
                m_navigationService.NavigateTo(xaml_typename<ContosoAirlinePOSCpp::SearchPage>());
            }
            else if (wcscmp(tag.c_str(), L"Book Flight") == 0) 
            {
                m_navigationService.NavigateTo(xaml_typename<ContosoAirlinePOSCpp::BookFlightPage>());
            }
        }
        else 
        {
            m_navigationService.NavigateTo(xaml_typename<ContosoAirlinePOSCpp::SettingsPage>());
        }
    }

    void ShellPage::LogoutOption_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        auto parent = Parent().as<IInspectable>();
        auto frame = unbox_value<winrt::Microsoft::UI::Xaml::Controls::Frame>(parent);
        frame.GoBack();
    }

    void ShellPage::MainContentFrame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {
        // enable or disable back navigation on NavigationView
        MenuNav().IsBackEnabled(MainContentFrame().CanGoBack());
    }

    void ShellPage::NavView_BackRequested(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args)
    {
        if (MainContentFrame().CanGoBack()) 
        {
            MainContentFrame().GoBack();
        }
    }
}