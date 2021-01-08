#include "pch.h"
#include "IFlightSearchService.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    IFlightSearchService::IFlightSearchService()
    {
        pm_mockRepository = MockRepository::CreateMockRepositoryInstace();
    }
    std::vector<Booking> winrt::ContosoAirlinePOSCpp::implementation::IFlightSearchService::SearchBookings(SearchQuery queryObject)
    {
        return std::vector<Booking>();
    }

    std::vector<Airport> winrt::ContosoAirlinePOSCpp::implementation::IFlightSearchService::GetAllAirports()
    {
        if (pm_mockRepository)
        {
            return pm_mockRepository->DestinationsAirport();
        }        
    }

    std::vector<Airport> winrt::ContosoAirlinePOSCpp::implementation::IFlightSearchService::GetDestinations(Airport sourceAirport)
    {
        return std::vector<Airport>();
    }
    
    std::tuple<std::vector<Flight>, std::vector<Flight>> winrt::ContosoAirlinePOSCpp::implementation::IFlightSearchService::GetRecentDepartureArrivals()
    {
        std::vector<Flight> vecDepartures;
        Flight              DepartureFlight[NUMBER_OF_FLIGHT];
        Airport             DepartureAirport[NUMBER_OF_FLIGHT];
        std::vector<Flight> vecArrivals;
        Flight              ArrivalFlight[NUMBER_OF_FLIGHT];
        Airport             ArrivalAirport[NUMBER_OF_FLIGHT];        
        std::string         strDepartureTime;
        std::string         strArrivalTime;
        
        strDepartureTime = GetTimeForFlight(1, " AM");
        DepartureFlight[0].Departure(to_hstring(strDepartureTime));
        DepartureAirport[0].AirportCode(L"TXL");
        DepartureAirport[0].CityName(L"Berlin");
        DepartureFlight[0].Destination(DepartureAirport[0]);
        DepartureFlight[0].FlightCode(L"HG 7895");
        DepartureFlight[0].FlightStatus(L"Boarding");
        DepartureFlight[0].Gate(L"T 11");
        vecDepartures.push_back(DepartureFlight[0]);        

        strDepartureTime.empty();
        strDepartureTime = GetTimeForFlight(3, " AM");
        DepartureFlight[1].Departure(to_hstring(strDepartureTime) );
        DepartureAirport[1].AirportCode(L"LCY");
        DepartureAirport[1].CityName(L"London");
        DepartureFlight[1].Destination(DepartureAirport[1]);
        DepartureFlight[1].FlightCode(L"KJ 2596");
        DepartureFlight[1].FlightStatus(L"Cancelled");
        DepartureFlight[1].Gate(L"T 6");
        vecDepartures.push_back(DepartureFlight[1]);

        strDepartureTime.empty();
        strDepartureTime = GetTimeForFlight(10, " PM");
        DepartureFlight[2].Departure(to_hstring(strDepartureTime));
        DepartureAirport[2].AirportCode(L"DXB");
        DepartureAirport[2].CityName(L"Dubai");
        DepartureFlight[2].Destination(DepartureAirport[2]);
        DepartureFlight[2].FlightCode(L"LK 5888");
        DepartureFlight[2].FlightStatus(L"Delayed");
        DepartureFlight[2].Gate(L"T 2");
        vecDepartures.push_back(DepartureFlight[2]);

        strDepartureTime.empty();
        strDepartureTime = GetTimeForFlight(4, " PM");
        DepartureFlight[3].Departure(to_hstring(strDepartureTime));
        DepartureAirport[3].AirportCode(L"CDG");
        DepartureAirport[3].CityName(L"Paris");
        DepartureFlight[3].Destination(DepartureAirport[3]);
        DepartureFlight[3].FlightCode(L"HG 7895");
        DepartureFlight[3].FlightStatus(L"Boarding");
        DepartureFlight[3].Gate(L"T 11");
        vecDepartures.push_back(DepartureFlight[3]);

        strDepartureTime.empty();
        strDepartureTime = GetTimeForFlight(20, " AM");
        DepartureFlight[4].Departure(to_hstring(strDepartureTime));
        DepartureAirport[4].AirportCode(L"LAX");
        DepartureAirport[4].CityName(L"Los Angeles");
        DepartureFlight[4].Destination(DepartureAirport[4]);
        DepartureFlight[4].FlightCode(L"CN 1457");
        DepartureFlight[4].FlightStatus(L"On Time");
        DepartureFlight[4].Gate(L"T 8");
        vecDepartures.push_back(DepartureFlight[4]);

        strDepartureTime.empty();
        strDepartureTime = GetTimeForFlight(20, " AM");
        DepartureFlight[5].Departure(to_hstring(strDepartureTime));
        DepartureAirport[5].AirportCode(L"ATL");
        DepartureAirport[5].CityName(L"Atlanta");
        DepartureFlight[5].Destination(DepartureAirport[5]);
        DepartureFlight[5].FlightCode(L"LK 6581");
        DepartureFlight[5].FlightStatus(L"On Time");
        DepartureFlight[5].Gate(L"T 3");
        vecDepartures.push_back(DepartureFlight[5]);

        strDepartureTime.empty();
        strDepartureTime = GetTimeForFlight(1, " AM");
        DepartureFlight[6].Departure(to_hstring(strDepartureTime));
        DepartureAirport[6].AirportCode(L"BOM");
        DepartureAirport[6].CityName(L"Mumbai");
        DepartureFlight[6].Destination(DepartureAirport[6]);
        DepartureFlight[6].FlightCode(L"CN 8743");
        DepartureFlight[6].FlightStatus(L"On Time");
        DepartureFlight[6].Gate(L"T 7");
        vecDepartures.push_back(DepartureFlight[6]);
        
        strArrivalTime = GetTimeForFlight(1, " PM");
        ArrivalFlight[0].Arrival(to_hstring(strArrivalTime));
        ArrivalAirport[0].AirportCode(L"CDG");
        ArrivalAirport[0].CityName(L"Paris");
        ArrivalFlight[0].Source(ArrivalAirport[0]);
        ArrivalFlight[0].FlightCode(L"HG 2498");
        ArrivalFlight[0].FlightStatus(L"Boarding");
        ArrivalFlight[0].Gate(L"T 1");
        vecArrivals.push_back(ArrivalFlight[0]);

        strArrivalTime.empty();
        strArrivalTime = GetTimeForFlight(10, " PM");
        ArrivalFlight[1].Arrival(to_hstring(strArrivalTime));
        ArrivalAirport[1].AirportCode(L"ATL");
        ArrivalAirport[1].CityName(L"Atlanta");
        ArrivalFlight[1].Source(ArrivalAirport[1]);
        ArrivalFlight[1].FlightCode(L"KJ 1457");
        ArrivalFlight[1].FlightStatus(L"Cancelled");
        ArrivalFlight[1].Gate(L"T 16");
        vecArrivals.push_back(ArrivalFlight[1]);

        strArrivalTime.empty();
        strArrivalTime = GetTimeForFlight(12, " PM");
        ArrivalFlight[2].Arrival(to_hstring(strArrivalTime));
        ArrivalAirport[2].AirportCode(L"LAX");
        ArrivalAirport[2].CityName(L"Los Angeles");
        ArrivalFlight[2].Source(ArrivalAirport[2]);
        ArrivalFlight[2].FlightCode(L"LK 4761");
        ArrivalFlight[2].FlightStatus(L"Delayed");
        ArrivalFlight[2].Gate(L"T 23");
        vecArrivals.push_back(ArrivalFlight[2]);

        strArrivalTime.empty();
        strArrivalTime = GetTimeForFlight(14, " PM");
        ArrivalFlight[3].Arrival(to_hstring(strArrivalTime));
        ArrivalAirport[3].AirportCode(L"TXL");
        ArrivalAirport[3].CityName(L"Berlin");
        ArrivalFlight[3].Source(ArrivalAirport[3]);
        ArrivalFlight[3].FlightCode(L"HG 2945");
        ArrivalFlight[3].FlightStatus(L"Boarding");
        ArrivalFlight[3].Gate(L"T 12");
        vecArrivals.push_back(ArrivalFlight[3]);

        strArrivalTime.empty();
        strArrivalTime = GetTimeForFlight(20, " AM");
        ArrivalFlight[4].Arrival(to_hstring(strArrivalTime));
        ArrivalAirport[4].AirportCode(L"DXB");
        ArrivalAirport[4].CityName(L"Dubai");
        ArrivalFlight[4].Source(ArrivalAirport[4]);
        ArrivalFlight[4].FlightCode(L"CN 3531");
        ArrivalFlight[4].FlightStatus(L"On Time");
        ArrivalFlight[4].Gate(L"T 5");
        vecArrivals.push_back(ArrivalFlight[4]);

        strArrivalTime.empty();
        strArrivalTime = GetTimeForFlight(24, " AM");
        ArrivalFlight[5].Arrival(to_hstring(strArrivalTime));
        ArrivalAirport[5].AirportCode(L"BOM");
        ArrivalAirport[5].CityName(L"Mumbai");
        ArrivalFlight[5].Source(ArrivalAirport[5]);
        ArrivalFlight[5].FlightCode(L"LK 8751");
        ArrivalFlight[5].FlightStatus(L"On Time");
        ArrivalFlight[5].Gate(L"T 7");
        vecArrivals.push_back(ArrivalFlight[5]);

        strArrivalTime.empty();
        strArrivalTime = GetTimeForFlight(24, " PM");
        ArrivalFlight[6].Arrival(to_hstring(strArrivalTime));
        ArrivalAirport[6].AirportCode(L"LCY");
        ArrivalAirport[6].CityName(L"London");
        ArrivalFlight[6].Source(ArrivalAirport[6]);
        ArrivalFlight[6].FlightCode(L"CN 6582");
        ArrivalFlight[6].FlightStatus(L"On Time");
        ArrivalFlight[6].Gate(L"T 8");
        vecArrivals.push_back(ArrivalFlight[6]);


        return std::tuple<std::vector<Flight>, std::vector<Flight>>(vecDepartures,vecArrivals);
    }
    std::string IFlightSearchService::GetTimeForFlight(int nHours , std::string strTime)
    {
        auto currentTime = std::chrono::system_clock::now();
        auto tt = std::chrono::system_clock::to_time_t(currentTime);
        tm local_tm = *localtime(&tt);

        tm today_date = {
            /* .tm_sec  = */ 0,
            /* .tm_min  = */ 0,
            /* .tm_hour = */ 0,
            /* .tm_mday = */ (local_tm.tm_mday),
            /* .tm_mon  = */ (local_tm.tm_mon),
            /* .tm_year = */ (local_tm.tm_year)
        };

        auto today = std::chrono::system_clock::from_time_t(mktime(&today_date));
        std::chrono::system_clock::time_point DepartureTime;
        std::time_t timeDeparture;
        std::string strDepartureDateTime;
        std::string strDepartureTime;
        DepartureTime = today + std::chrono::hours(nHours);
        timeDeparture = std::chrono::system_clock::to_time_t(DepartureTime);

        if (pm_mockRepository)
        {
            strDepartureTime = pm_mockRepository->GetCurrentDateTime(timeDeparture);
            pm_mockRepository->SplitDateTime(strDepartureTime, strDepartureTime);
            strDepartureTime.append(strTime);
        }
        return strDepartureTime;
    }
    IFlightSearchService::~IFlightSearchService()
    {
        if (pm_mockRepository != nullptr)
        {
            MockRepository::DeleteMockRepositoryInstance();
            pm_mockRepository = nullptr;
        }
    }
}