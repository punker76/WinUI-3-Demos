#pragma once

#include "ShellPage.g.h"
#include "ShellViewModel.h"
#include "INavigationService.h"
#include <Generated Files\winrt\impl\Microsoft.UI.Xaml.Controls.2.h>
#include <Generated Files\winrt\impl\Windows.UI.Xaml.Navigation.0.h>

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    using winrt::Microsoft::UI::Xaml::Controls::NavigationView;    
    
    struct ShellPage : ShellPageT<ShellPage>
    {
        ShellPage();

        ContosoAirlinePOSCpp::ShellViewModel ViewModel();

        void NavView_Loaded(Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

        void NavView_ItemInvoked(Windows::Foundation::IInspectable const& /* sender */,
            winrt::Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs const& args);

        void MainContentFrame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

        void NavView_BackRequested(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, 
            winrt::Microsoft::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args);

        void LogoutOption_Click(winrt::Windows::Foundation::IInspectable const& sender,
            winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        ContosoAirlinePOSCpp::ShellViewModel m_shellViewModel;
        INavigationService m_navigationService;
    };
}

namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct ShellPage : ShellPageT<ShellPage, implementation::ShellPage>
    {
    };
}
