#include "pch.h"
#include "Flight.h"
#include "Flight.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    hstring Flight::FlightId()
    {
        return m_flightID;
    }
    void Flight::FlightId(hstring const& value)
    {
        if (m_flightID != value)
        {
            m_flightID = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"FlightId" });
        }
    }
    hstring Flight::FlightCode()
    {
        return m_flightCode;
    }
    void Flight::FlightCode(hstring const& value)
    {
        if (m_flightCode != value)
        {
            m_flightCode = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"FlightCode" });
        }
    }
    hstring Flight::Departure()
    {
        return m_departure;
    }
    void Flight::Departure(hstring const& value)
    {
        if (m_departure != value)
        {
            m_departure = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Departure" });
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"DepartureDate" });
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"DepartureTime" });
        }
    }
    hstring Flight::Arrival()
    {
        return m_arrival;
    }
    void Flight::Arrival(hstring const& value)
    {
        if (m_arrival != value)
        {
            m_arrival = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Arrival" });
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"ArrivalDate" });
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"ArrivalTime" });
        }
    }
    hstring Flight::Duration()
    {
        return m_duration;
    }
    void Flight::Duration(hstring const& value)
    {
        if (m_duration != value)
        {
            m_duration = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Duration" });
        }
    }
    int32_t Flight::Hops()
    {
        return m_hops;
    }
    void Flight::Hops(int32_t value)
    {
        if (m_hops != value)
        {
            m_hops = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Hops" });
        }
    }
    ContosoAirlinePOSCpp::Airport Flight::Source()
    {
        return m_source;
    }
    void Flight::Source(ContosoAirlinePOSCpp::Airport const& value)
    {
        if (m_source != value)
        {
            m_source = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Source" });
        }
    }
    ContosoAirlinePOSCpp::Airport Flight::Destination()
    {
        return m_destination;
    }
    void Flight::Destination(ContosoAirlinePOSCpp::Airport const& value)
    {
        if (m_destination != value)
        {
            m_destination = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Destination" });
        }
    }
    double Flight::TicketPrice()
    {
        return m_ticketPrice;
    }
    void Flight::TicketPrice(double value)
    {
        if (m_ticketPrice != value)
        {
            m_ticketPrice = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"TicketPrice" });
        }
    }
    winrt::event_token Flight::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void Flight::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
    hstring Flight::FlightStatus()
    {
        return m_flightStatus;
    }
    void Flight::FlightStatus(hstring const& value)
    {
        if (m_flightStatus != value)
        {
            m_flightStatus = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"FlightStatus" });
        }
    }
    hstring Flight::Gate()
    {
        return m_gate;
    }
    void Flight::Gate(hstring const& value)
    {
        if (m_gate != value)
        {
            m_gate = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Gate" });
        }
    }
    hstring Flight::DepartureDate()
    {
        std::string strTime;
        std::string strDate;
        SplitDateTime(to_string(m_departure), strTime, strDate);

        return to_hstring(strDate);
    }
    hstring Flight::ArrivalDate()
    {
        std::string strTime;
        std::string strDate;
        SplitDateTime(to_string(m_arrival), strTime, strDate);

        return to_hstring(strDate);
    }
    hstring Flight::DepartureTime()
    {
        std::string strTime;
        std::string strDate;
        SplitDateTime(to_string(m_departure), strTime, strDate);

        return to_hstring(strTime);
    }
    hstring Flight::ArrivalTime()
    {
        std::string strTime;
        std::string strDate;
        SplitDateTime(to_string(m_arrival), strTime, strDate);

        return to_hstring(strTime);
    }
    void Flight::SplitDateTime(std::string strInput, std::string& strTime, std::string& strDate)
    {
        //"2020-08-19.06:00:00"
        if (!strInput.empty())
        {
            int nIndex = (int)strInput.rfind(".");
            if (nIndex != 0)
            {
                std::string strNewString = strInput.substr(nIndex + 1);
                if (!strNewString.empty())
                {
                    strTime = strNewString;
                }               
                std::string strNewString1 = strInput.substr(0 , nIndex);
                if (!strNewString1.empty())
                {
                    strDate = strNewString1;
                }
            }
        }
    }
}
