#pragma once
#include "BookingResult.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct BookingResult : BookingResultT<BookingResult>
    {
        BookingResult() = default;

        int32_t SerialNumber();
        void SerialNumber(int32_t value);
        int32_t BookingID();
        void BookingID(int32_t value);
        hstring CustomerName();
        void CustomerName(hstring const& value);
        hstring ContactNumber();
        void ContactNumber(hstring const& value);
        hstring FlightNumber();
        void FlightNumber(hstring const& value);
        hstring Source();
        void Source(hstring const& value);
        hstring Destination();
        void Destination(hstring const& value);
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        int32_t m_serialNumber;
        int32_t m_bookingID;
        hstring m_customerName;
        hstring m_contactNumber;
        hstring m_flightNumber;
        hstring m_source;
        hstring m_destination;
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
    struct BookingResult : BookingResultT<BookingResult, implementation::BookingResult>
    {
    };
}
