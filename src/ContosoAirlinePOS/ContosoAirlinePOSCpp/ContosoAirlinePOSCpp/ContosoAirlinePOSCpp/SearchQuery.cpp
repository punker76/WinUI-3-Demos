#include "pch.h"
#include "SearchQuery.h"
#include "SearchQuery.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    SearchQuery::SearchQuery()
    {

    }
    ContosoAirlinePOSCpp::Airport SearchQuery::Source()
    {
        return m_Source;
    }
    void SearchQuery::Source(ContosoAirlinePOSCpp::Airport const& value)
    {
        if (m_Source != value)
        {
            m_Source = value;
        }
    }
    ContosoAirlinePOSCpp::Airport SearchQuery::Destination()
    {
        return m_Destination;
    }
    void SearchQuery::Destination(ContosoAirlinePOSCpp::Airport const& value)
    {
        if (m_Destination != value)
        {
            m_Destination = value;
        }
    }
    Windows::Foundation::IReference<Windows::Foundation::DateTime> SearchQuery::TravelDate()
    {
        return m_TravelDate;
    }
    void SearchQuery::TravelDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> const& value)
    {
        if (m_TravelDate != value)
        {
            m_TravelDate = value;
        }
    }
    Windows::Foundation::IReference<Windows::Foundation::DateTime> SearchQuery::ReturnDate()
    {
        return m_ReturnDate;
    }
    void SearchQuery::ReturnDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> const& value)
    {
        if (m_ReturnDate != value)
        {
            m_ReturnDate = value;
        }
    }
    hstring SearchQuery::TravelClass()
    {
        return m_TravelClass;
    }
    void SearchQuery::TravelClass(hstring const& value)
    {
        if (m_TravelClass != value)
        {
            m_TravelClass = value;
        }
    }
    Windows::Foundation::IReference<bool> SearchQuery::RoundTrip()
    {
        return m_RoundTrip;
    }
    void SearchQuery::RoundTrip(Windows::Foundation::IReference<bool> const& value)
    {
        if (m_RoundTrip != value)
        {
            m_RoundTrip = value;
        }
    }
    Windows::Foundation::IReference<bool> SearchQuery::NonStop()
    {
        return m_NonStop;
    }
    void SearchQuery::NonStop(Windows::Foundation::IReference<bool> const& value)
    {
        if (m_NonStop != value)
        {
            m_NonStop = value;
        }
    }
    int32_t SearchQuery::AdultsCount()
    {
        return m_AdultsCount;
    }
    void SearchQuery::AdultsCount(int32_t value)
    {
        if (m_AdultsCount != value)
        {
            m_AdultsCount = value;
        }
    }
    int32_t SearchQuery::ChildrenCount()
    {
        return m_ChildernCount;
    }
    void SearchQuery::ChildrenCount(int32_t value)
    {
        if (m_ChildernCount != value)
        {
            m_ChildernCount = value;
        }
    }
    int32_t SearchQuery::FlightId()
    {
        return m_FlightID;
    }
    void SearchQuery::FlightId(int32_t value)
    {
        if (m_FlightID != value)
        {
            m_FlightID = value;
        }
    }

    ContosoAirlinePOSCpp::Flight SearchQuery::SelectedFlight()
    {
        return m_SelectedFlight;
    }
    void SearchQuery::SelectedFlight(ContosoAirlinePOSCpp::Flight const& value)
    {
        if (m_SelectedFlight != value)
        {
            m_SelectedFlight = value;
        }
    }
}
