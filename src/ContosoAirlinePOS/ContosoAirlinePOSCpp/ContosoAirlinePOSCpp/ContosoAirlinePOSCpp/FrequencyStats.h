#pragma once
#include "FrequencyStats.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct FrequencyStats : FrequencyStatsT<FrequencyStats>
    {
        FrequencyStats() = default;

        ContosoAirlinePOSCpp::Airport FlightDetails();
        int32_t BookingCount();
        void BookingCount(int32_t value);
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        int32_t m_bookingCount;
        Airport m_airportDetails;

        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct FrequencyStats : FrequencyStatsT<FrequencyStats, implementation::FrequencyStats>
    {
    };
}

