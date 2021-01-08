#pragma once
#include "BookFlightViewModel.g.h"
#include "SearchQuery.g.h"
#include "INavigationService.h"
#include "SearchResultPage.g.h"
#include "MockRepository.h"
#include "Services/BookingSearch/IFlightSearchService.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct BookFlightViewModel : BookFlightViewModelT<BookFlightViewModel>
    {
        BookFlightViewModel();

        Windows::Foundation::IReference<Windows::Foundation::DateTime> ReturnDate();
        void ReturnDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> const& value);
        Windows::Foundation::IReference<Windows::Foundation::DateTime> DepartureDate();
        void DepartureDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> const& value);
        hstring FlyingToInput();
        void FlyingToInput(hstring const& value);
        hstring FlyingFromInput();
        void FlyingFromInput(hstring const& value);
        ContosoAirlinePOSCpp::Airport SourceAirport();
        void SourceAirport(ContosoAirlinePOSCpp::Airport const& value);
        ContosoAirlinePOSCpp::Airport DestinationAirport();
        void DestinationAirport(ContosoAirlinePOSCpp::Airport const& value);
        Windows::Foundation::Collections::IObservableVector<Airport> SourceAirportSuggestions();
        void SourceAirportSuggestions(Windows::Foundation::Collections::IObservableVector<Airport> const& value);
        Windows::Foundation::Collections::IObservableVector<Airport> DestinationAirportSuggestions();
        void DestinationAirportSuggestions(Windows::Foundation::Collections::IObservableVector<Airport> const& value);
        int32_t NoOfChildrenPassengers();
        void NoOfChildrenPassengers(int32_t value);
        int32_t NoOfAdultPassengers();
        void NoOfAdultPassengers(int32_t value);
        int32_t SelectedStopPreference();
        void SelectedStopPreference(int32_t const& value);
        int32_t SelectedFlyingClass();
        void SelectedFlyingClass(int32_t const& value);
        Windows::Foundation::IReference<bool> IsOneWay();
        void IsOneWay(Windows::Foundation::IReference<bool> const& value);
        Windows::Foundation::IReference<bool> IsRoundTrip();
        void IsRoundTrip(Windows::Foundation::IReference<bool> const& value);
        Windows::Foundation::Collections::IObservableVector<hstring> FlyingClasses();
        void FlyingClasses(Windows::Foundation::Collections::IObservableVector<hstring> const& value);
        Windows::Foundation::Collections::IObservableVector<hstring> NoOfStops();
        void NoOfStops(Windows::Foundation::Collections::IObservableVector<hstring> const& value);
        Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> UpcomingArrivals();
        void UpcomingArrivals(Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> const& value);
        Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> UpcomingDepartures();
        void UpcomingDepartures(Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> const& value);
        void SearchFlightCommand();       
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        Windows::Foundation::IReference<Windows::Foundation::DateTime> m_returnDate;
        Windows::Foundation::IReference<Windows::Foundation::DateTime> m_departureDate;
        winrt::hstring m_flyingToInput;
        winrt::hstring m_flyingFromInput;
        Windows::Foundation::Collections::IObservableVector<Airport> m_destinationAirportSuggs{ nullptr };
        Windows::Foundation::Collections::IObservableVector<Airport> m_sourceAirportSuggs{ nullptr };
        int32_t     m_noChildPassengers;
        int32_t     m_noAdultPassengers;
        int32_t     m_seletctedStopPref;
        int32_t     m_selectedFlyingClass;
        Windows::Foundation::IReference<bool>    m_oneWay;
        Windows::Foundation::IReference<bool>    m_roundTrip;
        Windows::Foundation::Collections::IObservableVector<hstring> m_flyingClass;
        Windows::Foundation::Collections::IObservableVector<hstring> m_noOfStops;
        Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> m_upcomingArrivals;
        Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> m_upcomingDepartures;
        MockRepository* pm_MockRepository;
        ContosoAirlinePOSCpp::Airport m_SourceAiport;
        ContosoAirlinePOSCpp::Airport m_DestinationAiport;
        IFlightSearchService m_FlightSearchService;
        std::vector<ContosoAirlinePOSCpp::Airport> m_vecDestinationAirport;        
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;

    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct BookFlightViewModel : BookFlightViewModelT<BookFlightViewModel, implementation::BookFlightViewModel>
    {
    };
}

