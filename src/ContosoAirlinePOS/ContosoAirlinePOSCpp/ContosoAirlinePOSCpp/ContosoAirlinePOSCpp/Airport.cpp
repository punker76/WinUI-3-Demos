#include "pch.h"
#include "Airport.h"
#include "Airport.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    hstring Airport::AirportCode()
    {
        return m_airportCode;
    }

    void Airport::AirportCode(hstring const& value)
    {
        if (m_airportCode != value)
        {
            m_airportCode = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"AirportCode" });
        }
    }


    hstring Airport::AirportName()
    {
        return m_airportName;
    }

    void Airport::AirportName(hstring const& value)
    {
        if (m_airportName != value)
        {
            m_airportName = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"AirportName" });
        }
    }


    hstring Airport::CityName()
    {
        return m_cityName;
    }

    void Airport::CityName(hstring const& value)
    {
        if (m_cityName != value)
        {
            m_cityName = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"CityName" });
        }
    }


    double Airport::AverageFlyingHours()
    {
        return m_averageFlyHrs;
    }

    void Airport::AverageFlyingHours(double value)
    {
        UpdateValue<double>(L"AverageFlyingHours", m_averageFlyHrs, value);
    }


    double Airport::Weight()
    {
        return m_weight;
    }

    void Airport::Weight(double value)
    {
        UpdateValue<double>(L"Weight", m_weight, value);
    }

    hstring Airport::AirportFullName()
    {
        return m_airportCode + L" - " + m_airportName + L", " + m_cityName;
    }

    hstring Airport::AirportSearchKey() 
    {
        return m_airportCode + L" " + m_airportName + L" " + m_cityName;
    }

    winrt::event_token Airport::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }

    void Airport::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }    
}
