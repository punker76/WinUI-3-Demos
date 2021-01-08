#include "pch.h"
#include "BookingResult.h"
#include "BookingResult.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    int32_t BookingResult::SerialNumber()
    {
        return m_serialNumber;
    }
    void BookingResult::SerialNumber(int32_t value)
    {
        UpdateValue<int32_t>(L"SerialNumber", m_serialNumber, value);
    }
    int32_t BookingResult::BookingID()
    {
        return m_bookingID;
    }
    void BookingResult::BookingID(int32_t value)
    {
        UpdateValue<int32_t>(L"BookingID", m_bookingID, value);
    }
    hstring BookingResult::CustomerName()
    {
        return m_customerName;
    }
    void BookingResult::CustomerName(hstring const& value)
    {
        UpdateValue<hstring>(L"CustomerName", m_customerName, value);
    }
    hstring BookingResult::ContactNumber()
    {
        return m_contactNumber;
    }
    void BookingResult::ContactNumber(hstring const& value)
    {
        UpdateValue<hstring>(L"ContactNumber", m_contactNumber, value);
    }
    hstring BookingResult::FlightNumber()
    {
        return m_flightNumber;
    }
    void BookingResult::FlightNumber(hstring const& value)
    {
        UpdateValue<hstring>(L"FlightNumber", m_flightNumber, value);
    }
    hstring BookingResult::Source()
    {
        return m_source;
    }
    void BookingResult::Source(hstring const& value)
    {
        UpdateValue<hstring>(L"Source", m_source, value);
    }
    hstring BookingResult::Destination()
    {
        return m_destination;
    }
    void BookingResult::Destination(hstring const& value)
    {
        UpdateValue<hstring>(L"Destination", m_destination, value);
    }
    winrt::event_token BookingResult::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void BookingResult::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
