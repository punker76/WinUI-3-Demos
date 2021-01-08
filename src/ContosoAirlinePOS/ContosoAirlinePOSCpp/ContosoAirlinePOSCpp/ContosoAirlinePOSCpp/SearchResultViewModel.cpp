#include "pch.h"
#include "SearchResultViewModel.h"
#include "SearchResultViewModel.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    SearchResultViewModel::SearchResultViewModel()
    {
        m_SearchResults = winrt::single_threaded_observable_vector<Flight>();
        GetSearchResults();
    }    
    void SearchResultViewModel::GetSearchResults()
    {
        MockRepository* pMockRepository = MockRepository::CreateMockRepositoryInstace();
        if (pMockRepository)
        {
            INavigationService _Navigation;
            _Navigation.GetSearchQuery(m_Query);
            std::vector< ContosoAirlinePOSCpp::Flight> vecFlight = pMockRepository->SearchFlights(m_Query.Source(), m_Query.Destination());
            for (auto itrSearchFlight = vecFlight.begin(); itrSearchFlight != vecFlight.end(); itrSearchFlight++)
            {
                m_SearchResults.Append(*itrSearchFlight);
            }
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"SearchResults" });
        }
    }
    ContosoAirlinePOSCpp::SearchQuery SearchResultViewModel::Query()
    {
        return m_Query;
    }
    void SearchResultViewModel::Query(ContosoAirlinePOSCpp::SearchQuery const& value)
    {
        if (m_Query != value)
        {
            m_Query = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Query" });
        }
    }
    Windows::Foundation::Collections::IObservableVector<Flight> SearchResultViewModel::SearchResults()
    {
        return m_SearchResults;
    }
    void SearchResultViewModel::SearchResults(Windows::Foundation::Collections::IObservableVector<Flight> const& value)
    {
        if (m_SearchResults != value)
        {
            m_SearchResults = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"SearchResults" });
        }
    }

    void SearchResultViewModel::BookFlight(Flight const& selectedFlight)
    {
        INavigationService _navigationService;
        m_Query.SelectedFlight(selectedFlight);
        _navigationService.SetSearchQuery(m_Query);
        _navigationService.NavigateTo(xaml_typename<ContosoAirlinePOSCpp::FlightReservationPage>());
    }

    winrt::event_token SearchResultViewModel::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void SearchResultViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
