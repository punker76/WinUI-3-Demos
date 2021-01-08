#pragma once
#include "SearchResultPage.g.h"
#include "SearchResultViewModel.h"
#include "SearchResultViewModel.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct SearchResultPage : SearchResultPageT<SearchResultPage>
    {
        SearchResultPage();        
        ContosoAirlinePOSCpp::SearchResultViewModel ViewModel();
        void BookFlightButton_Clicked(winrt::Windows::Foundation::IInspectable const& sender, 
            winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    private:
        ContosoAirlinePOSCpp::SearchResultViewModel m_SearchResultViewModel{ nullptr };
    };
}

namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct SearchResultPage : SearchResultPageT<SearchResultPage, implementation::SearchResultPage>
    {
    };
}
