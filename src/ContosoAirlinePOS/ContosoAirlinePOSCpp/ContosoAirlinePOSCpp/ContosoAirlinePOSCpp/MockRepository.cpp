#include "pch.h"
#include "MockRepository.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{

    MockRepository* MockRepository::m_pMockpRepo = nullptr;
	MockRepository::MockRepository(){}
	MockRepository* MockRepository::CreateMockRepositoryInstace()
	{
		if (m_pMockpRepo == nullptr)
		{
			m_pMockpRepo = new MockRepository();
		}        
        
		return m_pMockpRepo;
	}
	void MockRepository::DeleteMockRepositoryInstance()
	{
		if (m_pMockpRepo != nullptr)
		{
			delete m_pMockpRepo;
			m_pMockpRepo = nullptr;
		}		
	}
	winrt::ContosoAirlinePOSCpp::Airport MockRepository::SourceAirport()
	{
		m_airportSource.AirportCode(L"JFK");
		m_airportSource.CityName(L"New York City, NY");
		m_airportSource.AirportName(L"John F. Kennedy International Airport");
		return m_airportSource;
	}
    std::vector<ContosoAirlinePOSCpp::Airport> MockRepository::DestinationsAirport()
    {
        std::vector< ContosoAirlinePOSCpp::Airport> vecDestinationAirport;
        Airport destnation[NUMBER_OF_AIRPORT];

        m_destinationAirport.clear();

        destnation[0].AirportCode(L"LAX");
        destnation[0].CityName(L"Los Angeles, CA");
        destnation[0].AirportName(L"Los Angeles International Airport");
        destnation[0].Weight(4);
        destnation[0].AverageFlyingHours((float)5.7);
        vecDestinationAirport.push_back(destnation[0]);

        destnation[1].AirportCode(L"ATL");
        destnation[1].CityName(L"Atlanta, GA");
        destnation[1].AirportName(L"Hartsfield–Jackson Atlanta International Airport");
        destnation[1].Weight(3);
        destnation[1].AverageFlyingHours((float)2.3);
        vecDestinationAirport.push_back(destnation[1]);

        destnation[2].AirportCode(L"ORD");
        destnation[2].CityName(L"Chicago, IL");
        destnation[2].AirportName(L"O'Hare International Airport");
        destnation[2].Weight(4);
        destnation[2].AverageFlyingHours((float)2.3);
        vecDestinationAirport.push_back(destnation[2]);

        destnation[3].AirportCode(L"DFW");
        destnation[3].CityName(L"Dallas, TX");
        destnation[3].AirportName(L"Dallas/Fort Worth International Airport");
        destnation[3].Weight(2);
        destnation[3].AverageFlyingHours((float)3.1);
        vecDestinationAirport.push_back(destnation[3]);

        destnation[4].AirportCode(L"DEN");
        destnation[4].CityName(L"Denver, CO");
        destnation[4].AirportName(L"Denver International Airport");
        destnation[4].Weight(2);
        destnation[4].AverageFlyingHours((float)4.1);
        vecDestinationAirport.push_back(destnation[4]);

        destnation[5].AirportCode(L"SFO");
        destnation[5].CityName(L"San Francisco, CA");
        destnation[5].AirportName(L"San Francisco International Airport");
        destnation[5].Weight(3);
        destnation[5].AverageFlyingHours((float)6.2);
        vecDestinationAirport.push_back(destnation[5]);

        destnation[6].AirportCode(L"SEA");
        destnation[6].CityName(L"Seattle, WA");
        destnation[6].AirportName(L"Seattle–Tacoma International Airport");
        destnation[6].Weight(4);
        destnation[6].AverageFlyingHours((float)6.1);
        vecDestinationAirport.push_back(destnation[6]);

        m_destinationAirport = vecDestinationAirport;
        return vecDestinationAirport;
    }

    std::vector<ContosoAirlinePOSCpp::Airport> MockRepository::GetAllAirports() 
    {
        std::vector<ContosoAirlinePOSCpp::Airport> airports;
        auto destinations = DestinationsAirport();

        for (int i = 0; i < destinations.size(); i++)
        {
            airports.push_back(destinations[i]);
        }

        airports.push_back(SourceAirport());
        return airports;
    }
    
    void MockRepository::GenerateFlights()
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

        const auto startTime = today + std::chrono::hours(5);        
        const auto endTime = today + std::chrono::hours(19);      
        std::vector<ContosoAirlinePOSCpp::Flight> flights;
        std::vector<ContosoAirlinePOSCpp::Flight> _schedules;
        int flightCode = 0;

        for each (auto & destination in m_destinationAirport)
        {
            int frequency = (int)(destination.Weight() * FLIGHT_MULTIPLYING_FACTOR);

            auto flightTime = startTime;
            std::chrono::duration<double> Timediff = endTime - startTime;
            int operatingBracket = ConvertSecondstoHours((int)Timediff.count());
            auto randomIterations = GetNRandomNumbersInRange(0, operatingBracket, frequency);
            for (int i = 0; i < frequency; i++)
            {
                Flight flight;
                std::string strFlightCode = GetFourDigitFlightCode(++flightCode);
                std::string hFlightCode = FLIGHT_CODE_PREFIX + strFlightCode;

                flight.FlightCode(winrt::to_hstring(hFlightCode));
                flight.Source(m_airportSource);
                flight.Destination(destination);

                auto DepartureTime = startTime + std::chrono::hours(randomIterations[i]);
                std::time_t timeDeparture = std::chrono::system_clock::to_time_t(DepartureTime);
                std::string ts = GetCurrentDateTime(timeDeparture);
                
                flight.Departure(winrt::to_hstring(ts));
                flight.Hops(0);

                double dbRandomNum = double(GetRandomNumberInRange(-1, 1) / 10.0);
                double dbFlyHours = double(destination.AverageFlyingHours());
                double timeArrival = dbFlyHours + dbRandomNum;
                std::time_t TotalJourneyTime = timeDeparture + (std::time_t)(timeArrival * 60 * 60);
                std::string ts1 = GetCurrentDateTime(TotalJourneyTime);
                flight.Arrival(winrt::to_hstring(ts1));

                auto timeDuration = difftime(TotalJourneyTime, timeDeparture);
                int hours =(int) (timeDuration / 60) / 60;
                int minutes = (int)(timeDuration / 60) - (hours * 60);
                flight.Duration(to_hstring(hours) + L" h " + to_hstring(minutes) + L" m");
                double dbTicketPrice = 250;
                flight.TicketPrice(dbTicketPrice);

                flights.push_back(flight);
            }
        }

        m_schedules = flights;
        
    }
    std::vector<int> MockRepository::GetNRandomNumbersInRange(int start, int end, int n)
    {
        int i = 0;
        std::vector<int> numbers;
        srand(time(0));
        for (i = 0; i < n; i++) 
        {
            int num = (rand() % (start - end + 1)) + end;
            numbers.push_back(num);            
        }
        return numbers;
    }
    int MockRepository::GetRandomNumberInRange(int start, int end)
    {
        int num = 0;
        srand(time(0));
        for (int i = 0; i < end; i++)
        {
            num = (rand() % (start - end + 1)) + end;
        }
        return num;
    }
    std::string MockRepository::GetFourDigitFlightCode(int code)
    {
        std::ostringstream oStringStream;
        oStringStream << code;
        // the str() coverts number into string 
        return oStringStream.str();
    }
    std::string MockRepository::TimeToString(std::time_t tInput)
    {
        time(&tInput);

        std::stringstream ss;
        ss << tInput;
        std::string ts = ss.str();
        return ts;
    }
    
    int MockRepository::ConvertSecondstoHours(int nSeconds)
    {
        int nHours = 0;
        if (nSeconds != 0)
        {
            nHours = nSeconds / 3600;
         }
        return nHours;
    }
    const std::string MockRepository::GetCurrentDateTime(std::time_t time_t)
    {
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&time_t);
        // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
        // for more information about date/time format
        strftime(buf, sizeof(buf), "%m-%d-%Y.%X", &tstruct);
        return buf;
    }
    void MockRepository::CurrentDateTime(struct tm  &tstruct)
    {
        time_t     now = time(0);        
        char       buf[80];
        tstruct = *localtime(&now);        
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);        
        return;
    }

    void MockRepository::ConvertFromStringToTime(std::string strInput, struct tm &tmStruct)
    {
        int yy =0 , month = 0, dd = 0, hh =0 , mm = 0, ss =0;      
        
        //"2020-08-04.17:56:53"
        sscanf(strInput.c_str(), "%4d-%2d-%2d.%2d:%2d:%2d", &yy, &month, &dd, &hh, &mm, &ss);
        tmStruct.tm_year = yy - 1900;
        tmStruct.tm_mon = month - 1;
        tmStruct.tm_mday = dd;
        tmStruct.tm_hour = hh;
        tmStruct.tm_min = mm;
        tmStruct.tm_sec = ss;
        tmStruct.tm_isdst = -1;
        return;
    }
    std::vector<ContosoAirlinePOSCpp::Flight> MockRepository::SearchFlights(ContosoAirlinePOSCpp::Airport source, ContosoAirlinePOSCpp::Airport destination)
    {
        m_schedules.clear();
        std::vector<ContosoAirlinePOSCpp::Flight> vecSerchedFlights;
        GenerateFlights();
        for (auto itrScheduledFlights = m_schedules.begin(); itrScheduledFlights != m_schedules.end(); itrScheduledFlights++)
        {
            if (itrScheduledFlights->Source().AirportCode() == source.AirportCode() &&
                itrScheduledFlights->Destination().AirportCode() == destination.AirportCode())
            {
                vecSerchedFlights.push_back(*itrScheduledFlights);
            }
        }
        return vecSerchedFlights;
    }

    void MockRepository::SplitDateTime(std::string strInput,std::string& strTime)
    {
        //"2020-08-19.06:00:00"
        if (!strInput.empty())
        {
            int nIndex = (int)strInput.rfind(".");
            if (nIndex !=0)
            {
                std::string strNewString = strInput.substr(nIndex +1);
                if (!strNewString.empty())
                {
                    strTime = strNewString;
                }
            }
        }
    }
}