#pragma once
#include "Booking.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct Booking : BookingT<Booking>
    {
        Booking() = default;

        hstring BookingId();
        void BookingId(hstring const& value);
        hstring RegisteredMobileNumber();
        void RegisteredMobileNumber(hstring const& value);
        hstring RegisteredEmailAddress();
        void RegisteredEmailAddress(hstring const& value);
        hstring DateOfBooking();
        void DateOfBooking(hstring const& value);
        int32_t FlightId();
        void FlightId(int32_t value);
        hstring TransactionId();
        void TransactionId(hstring const& value);
        float InvoiceAmount();
        void InvoiceAmount(float value);
        int32_t Passengers();
        void Passengers(int32_t value);
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::hstring m_bookingID;
        winrt::hstring m_registerMobileNumber;
        winrt::hstring m_registerEmailAddress;
        winrt::hstring m_dateOfBooking;
        int32_t        m_flightID;
        int32_t        m_passengers;
        winrt::hstring m_transactionID;
        float          m_invoiceAmount;
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;

        template <class T>
        void UpdateValue(hstring const& propertyName, T& var, T value)
        {
            if (var != value)
            {
                var = value;
                RaisePropertyChanged(propertyName);
            }
        }

        void RaisePropertyChanged(hstring const& propertyName)
        {
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
        }
    };
}

namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct Booking : BookingT<Booking, implementation::Booking>
    {
    };
}