#pragma once
#include "SearchResultViewModel.g.h"
#include "INavigationService.h"
#include "FlightReservationPage.g.h"
#include "MockRepository.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct SearchResultViewModel : SearchResultViewModelT<SearchResultViewModel>
    {
    public:
        SearchResultViewModel();        
        ContosoAirlinePOSCpp::SearchQuery Query();
        void Query(ContosoAirlinePOSCpp::SearchQuery const& value);
        Windows::Foundation::Collections::IObservableVector<Flight> SearchResults();
        void SearchResults(Windows::Foundation::Collections::IObservableVector<Flight> const& value);
        void GetSearchResults();
        void BookFlight(Flight const& selectedFlight);
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        ContosoAirlinePOSCpp::SearchQuery m_Query;
        Windows::Foundation::Collections::IObservableVector<Flight> m_SearchResults{ nullptr };
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct SearchResultViewModel : SearchResultViewModelT<SearchResultViewModel, implementation::SearchResultViewModel>
    {
    };
}

