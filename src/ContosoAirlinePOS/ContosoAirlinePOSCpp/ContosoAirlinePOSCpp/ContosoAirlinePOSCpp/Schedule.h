#pragma once
#include "Schedule.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct Schedule : ScheduleT<Schedule>
    {
        Schedule() = default;

        hstring Date();
        void Date(hstring const& value);
        Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> FlightArrivals();
        Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> FlightDepts();
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::hstring m_schduleDate;
        Windows::Foundation::Collections::IObservableVector< ContosoAirlinePOSCpp::Flight> m_flightArrivals;
        Windows::Foundation::Collections::IObservableVector< ContosoAirlinePOSCpp::Flight> m_flightDepts;

        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct Schedule : ScheduleT<Schedule, implementation::Schedule>
    {
    };
}
