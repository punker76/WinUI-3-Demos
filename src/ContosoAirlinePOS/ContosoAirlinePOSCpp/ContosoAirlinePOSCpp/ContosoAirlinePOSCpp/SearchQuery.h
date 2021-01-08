#pragma once
#include "SearchQuery.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct SearchQuery : SearchQueryT<SearchQuery>
    {
        SearchQuery();

        ContosoAirlinePOSCpp::Airport Source();
        void Source(ContosoAirlinePOSCpp::Airport const& value);
        ContosoAirlinePOSCpp::Airport Destination();
        void Destination(ContosoAirlinePOSCpp::Airport const& value);
        Windows::Foundation::IReference<Windows::Foundation::DateTime> TravelDate();
        void TravelDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> const& value);
        Windows::Foundation::IReference<Windows::Foundation::DateTime> ReturnDate();
        void ReturnDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> const& value);
        hstring TravelClass();
        void TravelClass(hstring const& value);
        Windows::Foundation::IReference<bool> RoundTrip();
        void RoundTrip(Windows::Foundation::IReference<bool> const& value);
        Windows::Foundation::IReference<bool> NonStop();
        void NonStop(Windows::Foundation::IReference<bool> const& value);
        int32_t AdultsCount();
        void AdultsCount(int32_t value);
        int32_t ChildrenCount();
        void ChildrenCount(int32_t value);
        int32_t FlightId();
        void FlightId(int32_t value);
        ContosoAirlinePOSCpp::Flight SelectedFlight();
        void SelectedFlight(ContosoAirlinePOSCpp::Flight const& value);

    private:
        ContosoAirlinePOSCpp::Airport   m_Source;
        ContosoAirlinePOSCpp::Airport   m_Destination;
        Windows::Foundation::IReference<Windows::Foundation::DateTime>  m_TravelDate;
        Windows::Foundation::IReference<Windows::Foundation::DateTime>  m_ReturnDate;
        winrt::hstring  m_TravelClass;
        Windows::Foundation::IReference<bool>   m_RoundTrip;
        Windows::Foundation::IReference<bool>   m_NonStop;
        int32_t     m_AdultsCount;
        int32_t     m_ChildernCount;
        int32_t     m_FlightID;
        Flight      m_SelectedFlight;
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct SearchQuery : SearchQueryT<SearchQuery, implementation::SearchQuery>
    {
    };
}