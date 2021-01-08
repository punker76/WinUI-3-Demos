#pragma once
#include "Flight.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct Flight : FlightT<Flight>
    {
        Flight() = default;

        hstring FlightId();
        void FlightId(hstring const& value);
        hstring FlightCode();
        void FlightCode(hstring const& value);
        hstring Departure();
        void Departure(hstring const& value);
        hstring Arrival();
        void Arrival(hstring const& value);
        hstring Duration();
        void Duration(hstring const& value);
        int32_t Hops();
        void Hops(int32_t value);
        ContosoAirlinePOSCpp::Airport Source();
        void Source(ContosoAirlinePOSCpp::Airport const& value);
        ContosoAirlinePOSCpp::Airport Destination();
        void Destination(ContosoAirlinePOSCpp::Airport const& value);
        double TicketPrice();
        void TicketPrice(double value);
        hstring DepartureDate();
        hstring ArrivalDate();
        hstring DepartureTime();
        hstring ArrivalTime();
        hstring FlightStatus();
        void FlightStatus(hstring const& value);
        hstring Gate();
        void Gate(hstring const& value);
        void SplitDateTime(std::string strInput, std::string& strTime, std::string& strDate);
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::hstring m_flightID;
        winrt::hstring m_flightCode;
        winrt::hstring m_departure;
        winrt::hstring m_arrival;
        winrt::hstring m_duration;
        int32_t m_hops;
        Airport m_source;
        Airport m_destination;
        double  m_ticketPrice;
        winrt::hstring m_flightStatus;
        winrt::hstring m_gate;

        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct Flight : FlightT<Flight, implementation::Flight>
    {
    };
}
