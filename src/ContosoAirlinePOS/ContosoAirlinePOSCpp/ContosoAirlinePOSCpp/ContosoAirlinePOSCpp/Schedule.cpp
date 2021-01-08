#include "pch.h"
#include "Schedule.h"
#include "Schedule.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    hstring Schedule::Date()
    {
        return m_schduleDate;
    }
    void Schedule::Date(hstring const& value)
    {
        if (m_schduleDate != value)
        {
            m_schduleDate = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Date" });
        }
    }
    Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> Schedule::FlightArrivals()
    {
        return m_flightArrivals;
    }
    Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::Flight> Schedule::FlightDepts()
    {
        return m_flightDepts;
    }
    winrt::event_token Schedule::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void Schedule::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
