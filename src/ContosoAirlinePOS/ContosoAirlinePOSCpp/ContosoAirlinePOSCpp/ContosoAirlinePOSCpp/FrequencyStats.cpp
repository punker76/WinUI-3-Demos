#include "pch.h"
#include "FrequencyStats.h"
#include "FrequencyStats.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    ContosoAirlinePOSCpp::Airport FrequencyStats::FlightDetails()
    {
        return m_airportDetails;
    }
    int32_t FrequencyStats::BookingCount()
    {
        return m_bookingCount;
    }
    void FrequencyStats::BookingCount(int32_t value)
    {
        if (m_bookingCount != value)
        {
            m_bookingCount = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"BookingCount" });
        }
    }
    winrt::event_token FrequencyStats::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void FrequencyStats::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
