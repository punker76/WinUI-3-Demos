#include "pch.h"
#include "Booking.h"
#include "Booking.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    hstring Booking::BookingId()
    {
        return m_bookingID;
    }
    void Booking::BookingId(hstring const& value)
    {
        if (m_bookingID != value)
        {
            m_bookingID = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"BookingId" });
        }
    }
    hstring Booking::RegisteredMobileNumber()
    {
        return m_registerMobileNumber;
    }
    void Booking::RegisteredMobileNumber(hstring const& value)
    {
        if (m_registerMobileNumber != value)
        {
            m_registerMobileNumber = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"RegisteredMobileNumber" });
        }
    }
    hstring Booking::RegisteredEmailAddress()
    {
        return m_registerEmailAddress;
    }
    void Booking::RegisteredEmailAddress(hstring const& value)
    {
        if (m_registerEmailAddress != value)
        {
            m_registerEmailAddress = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"RegisteredEmailAddress" });
        }
    }
    hstring Booking::DateOfBooking()
    {
        return m_dateOfBooking;
    }
    void Booking::DateOfBooking(hstring const& value)
    {
        if (m_dateOfBooking != value)
        {
            m_dateOfBooking = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"DateOfBooking" });
        }
    }
    int32_t Booking::FlightId()
    {
        return m_flightID;
    }
    void Booking::FlightId(int32_t value)
    {
        if (m_flightID != value)
        {
            m_flightID = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"FlightId" });
        }
    }
    hstring Booking::TransactionId()
    {
        return m_transactionID;
    }
    void Booking::TransactionId(hstring const& value)
    {
        if (m_transactionID != value)
        {
            m_transactionID = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"TransactionId" });
        }
    }
    float Booking::InvoiceAmount()
    {
        return m_invoiceAmount;
    }
    void Booking::InvoiceAmount(float value)
    {
        UpdateValue<float>(L"InvoiceAmount", m_invoiceAmount, value);
    }
    int32_t Booking::Passengers()
    {
        return m_passengers;
    }
    void Booking::Passengers(int32_t value)
    {
        if (m_passengers != value)
        {
            m_passengers = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Passengers" });
        }
    }
    winrt::event_token Booking::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void Booking::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
