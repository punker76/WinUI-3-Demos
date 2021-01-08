#include "pch.h"
#include "BookFlightViewModel.h"
#include "BookFlightViewModel.g.cpp"


namespace winrt::ContosoAirlinePOSCpp::implementation
{
    BookFlightViewModel::BookFlightViewModel()
    {
        pm_MockRepository = MockRepository::CreateMockRepositoryInstace();
        m_sourceAirportSuggs = winrt::single_threaded_observable_vector<Airport>();
        m_destinationAirportSuggs = winrt::single_threaded_observable_vector<Airport>();
        m_upcomingArrivals = winrt::single_threaded_observable_vector<Flight>();
        m_upcomingDepartures = winrt::single_threaded_observable_vector<Flight>();

        m_flyingClass = winrt::single_threaded_observable_vector<hstring>({ L"Economy", L"Business", L"First Class" });
        m_noOfStops = winrt::single_threaded_observable_vector<hstring>({ L"Non Stop", L"1+", L"2+" });
        m_selectedFlyingClass = 0;
        m_seletctedStopPref = 0;

        m_departureDate = winrt::clock::now();
        m_returnDate = winrt::clock::now() + std::chrono::hours(2*24);

        m_noAdultPassengers = 1;
        m_noChildPassengers = 0;

        m_oneWay = true;
        m_roundTrip = false;
        auto DepartureArrivals = m_FlightSearchService.GetRecentDepartureArrivals();
        auto Departures = std::get<0>(DepartureArrivals);
        for(auto &itrDeparture : Departures)
        {
            m_upcomingDepartures.Append(itrDeparture);
        }
        m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"UpcomingDepartures" });
        auto Arrivals = std::get<1>(DepartureArrivals);
        for (auto& itrArrival : Arrivals)
        {
            m_upcomingArrivals.Append(itrArrival);
        }
        m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"UpcomingArrivals" });
    }


    Windows::Foundation::IReference<Windows::Foundation::DateTime> BookFlightViewModel::ReturnDate()
    {
        return m_returnDate;
    }

    void BookFlightViewModel::ReturnDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> const& value)
    {
        if (m_returnDate != value)
        {
            m_returnDate = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"ReturnDate" });
        }
    }


    Windows::Foundation::IReference<Windows::Foundation::DateTime> BookFlightViewModel::DepartureDate()
    {
        return m_departureDate;
    }

    void BookFlightViewModel::DepartureDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> const& value)
    {
        if (m_departureDate != value)
        {
            m_departureDate = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"DepartureDate" });
        }
    }


    Windows::Foundation::Collections::IObservableVector<Airport> BookFlightViewModel::DestinationAirportSuggestions()
    {
        return m_destinationAirportSuggs;
    }

    void BookFlightViewModel::DestinationAirportSuggestions(Windows::Foundation::Collections::IObservableVector<Airport> const& value)
    {
        if (m_destinationAirportSuggs != value)
        {
            m_destinationAirportSuggs = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"DestinationAirportSuggestions" });
        }
    }


    hstring BookFlightViewModel::FlyingToInput()
    {
        return m_flyingToInput;
    }

    void BookFlightViewModel::FlyingToInput(hstring const& value)
    {
        if (m_flyingToInput != value)
        {        
            std::vector<Airport> vecDestinationAirport;
            if (pm_MockRepository)
            {
                vecDestinationAirport = pm_MockRepository->GetAllAirports();
            }

            if (m_destinationAirportSuggs.Size() > 0)
            {
                m_destinationAirportSuggs.Clear();
            }

            for (auto itrDestAirport = vecDestinationAirport.begin(); itrDestAirport != vecDestinationAirport.end(); itrDestAirport++)
            {
                std::string strAirportName = winrt::to_string((*itrDestAirport).AirportSearchKey());
                std::string strInputvalue = winrt::to_string(value);
                std::transform(strAirportName.begin(), strAirportName.end(), strAirportName.begin(), std::tolower);
                std::transform(strInputvalue.begin(), strInputvalue.end(), strInputvalue.begin(), std::tolower);
                if (strAirportName.find(strInputvalue) != (std::string::npos))
                {
                    m_destinationAirportSuggs.Append(*itrDestAirport);
                }
            }

            m_flyingToInput = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"FlyingToInput" });
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"DestinationAirportSuggestions" });
        }
    }


    hstring BookFlightViewModel::FlyingFromInput()
    {
        return m_flyingFromInput;
    }

    void BookFlightViewModel::FlyingFromInput(hstring const& value)
    {
        if (m_flyingFromInput != value)
        {
            std::vector<Airport> vecDestinationAirport;
            if (pm_MockRepository)
            {
                vecDestinationAirport = pm_MockRepository->GetAllAirports();
            }

            if (m_sourceAirportSuggs.Size() > 0)
            {
                m_sourceAirportSuggs.Clear();
            }

            for (auto itrDestAirport = vecDestinationAirport.begin(); itrDestAirport != vecDestinationAirport.end(); itrDestAirport++)
            {
                std::string strAirportName = winrt::to_string((*itrDestAirport).AirportSearchKey());
                std::string strInputvalue = winrt::to_string(value);
                std::transform(strAirportName.begin(), strAirportName.end(), strAirportName.begin(), std::tolower);
                std::transform(strInputvalue.begin(), strInputvalue.end(), strInputvalue.begin(), std::tolower);
                if (strAirportName.find(strInputvalue) != (std::string::npos))
                {
                    m_sourceAirportSuggs.Append(*itrDestAirport);
                }
            }

            m_flyingFromInput = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"FlyingFromInput" });
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"SourceAirportSuggestions" });
        }
    }


    ContosoAirlinePOSCpp::Airport BookFlightViewModel::SourceAirport()
    {
        return m_SourceAiport;
    }

    void BookFlightViewModel::SourceAirport(ContosoAirlinePOSCpp::Airport const& value)
    {
        if (m_SourceAiport != value) 
        {
            m_SourceAiport = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"SourceAirport" });
        }
    }


    ContosoAirlinePOSCpp::Airport BookFlightViewModel::DestinationAirport()
    {
        return m_DestinationAiport;
    }

    void BookFlightViewModel::DestinationAirport(ContosoAirlinePOSCpp::Airport const& value)
    {
        if (m_DestinationAiport != value)
        {
            m_DestinationAiport = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"DestinationAirport" });
        }
    }

    Windows::Foundation::Collections::IObservableVector<Airport> BookFlightViewModel::SourceAirportSuggestions()
    {
        return m_sourceAirportSuggs;
    }
    void BookFlightViewModel::SourceAirportSuggestions(Windows::Foundation::Collections::IObservableVector<Airport> const& value)
    {
        if (m_sourceAirportSuggs != value)
        {
            m_sourceAirportSuggs = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"SourceAirportSuggestions" });
        }
    }
    int32_t BookFlightViewModel::NoOfChildrenPassengers()
    {
        return m_noChildPassengers;
    }
    void BookFlightViewModel::NoOfChildrenPassengers(int32_t value)
    {
        if (m_noChildPassengers != value)
        {
            m_noChildPassengers = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"NoOfChildrenPassengers" });
        }
    }
    int32_t BookFlightViewModel::NoOfAdultPassengers()
    {
        return m_noAdultPassengers;
    }
    void BookFlightViewModel::NoOfAdultPassengers(int32_t value)
    {
        if (m_noAdultPassengers != value)
        {
            m_noAdultPassengers = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"NoOfAdultPassengers" });
        }
    }
    int32_t BookFlightViewModel::SelectedStopPreference()
    {
        return m_seletctedStopPref;
    }
    void BookFlightViewModel::SelectedStopPreference(int32_t const& value)
    {
        if (m_seletctedStopPref != value)
        {
            m_seletctedStopPref = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"SelectedStopPreference" });
        }
    }
    int32_t BookFlightViewModel::SelectedFlyingClass()
    {
        return m_selectedFlyingClass;
    }
    void BookFlightViewModel::SelectedFlyingClass(int32_t const& value)
    {
        if (m_selectedFlyingClass != value)
        {
            m_selectedFlyingClass = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"SelectedFlyingClass" });
        }
    }
    Windows::Foundation::IReference<bool> BookFlightViewModel::IsOneWay()
    {
        return m_oneWay;
    }
    void BookFlightViewModel::IsOneWay(Windows::Foundation::IReference<bool> const& value)
    {
        if (m_oneWay != value)
        {
            m_oneWay = value;
            m_roundTrip = !m_oneWay;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"IsOneWay" });
        }
    }
    Windows::Foundation::IReference<bool> BookFlightViewModel::IsRoundTrip()
    {
        return m_roundTrip;
    }
    void BookFlightViewModel::IsRoundTrip(Windows::Foundation::IReference<bool> const& value)
    {
        if (m_roundTrip != value)
        {
            m_roundTrip = value;
            m_oneWay = !m_roundTrip;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"IsRoundTrip" });
        }
    }
    Windows::Foundation::Collections::IObservableVector<hstring> BookFlightViewModel::FlyingClasses()
    {
        return m_flyingClass;
    }
    void BookFlightViewModel::FlyingClasses(Windows::Foundation::Collections::IObservableVector<hstring> const& value)
    {
        if (m_flyingClass != value)
        {
            m_flyingClass = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"FlyingClasses" });
        }
    }
    Windows::Foundation::Collections::IObservableVector<hstring> BookFlightViewModel::NoOfStops()
    {
        return m_noOfStops;
    }
    void BookFlightViewModel::NoOfStops(Windows::Foundation::Collections::IObservableVector<hstring> const& value)
    {
        if (m_noOfStops != value)
        {
            m_noOfStops = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"NoOfStops" });
        }
    }
    Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> BookFlightViewModel::UpcomingArrivals()
    {
        return m_upcomingArrivals;
    }
    void BookFlightViewModel::UpcomingArrivals(Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> const& value)
    {
        if (m_upcomingArrivals != value)
        {
            m_upcomingArrivals = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"UpcomingArrivals" });
        }
    }
    Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> BookFlightViewModel::UpcomingDepartures()
    {
        return m_upcomingDepartures;
    }
    void BookFlightViewModel::UpcomingDepartures(Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> const& value)
    {
        if (m_upcomingDepartures != value)
        {
            m_upcomingDepartures = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"UpcomingDepartures" });
        }
    }
    
    void BookFlightViewModel::SearchFlightCommand()
    {
        SearchQuery queryObject;
        INavigationService _navigationService;
        queryObject.Source(m_SourceAiport);
        queryObject.Destination(m_DestinationAiport);
        queryObject.ChildrenCount(m_noChildPassengers);
        queryObject.AdultsCount(m_noAdultPassengers);
        queryObject.NonStop(true);
        queryObject.RoundTrip(false);
        queryObject.TravelClass(L"Economy");
        queryObject.TravelDate(m_departureDate);
        _navigationService.SetSearchQuery(queryObject);
        _navigationService.NavigateTo(xaml_typename<ContosoAirlinePOSCpp::SearchResultPage>());                
    }    
    winrt::event_token BookFlightViewModel::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void BookFlightViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
