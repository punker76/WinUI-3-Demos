#include "pch.h"
#include "FlightReservationViewModel.h"
#include "FlightReservationViewModel.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    FlightReservationViewModel::FlightReservationViewModel()
    {
        INavigationService _navigationService;
        _navigationService.GetSearchQuery(m_queryObject);

        // add passengers
        m_passengers = winrt::single_threaded_observable_vector<People>();
        for (int i = 0; i < m_queryObject.AdultsCount(); i++) 
        {
            People passenger;
            m_passengers.Append(passenger);
        }
        m_invoiceAmount = (m_queryObject.SelectedFlight().TicketPrice()) * (m_queryObject.AdultsCount());
    }

    ContosoAirlinePOSCpp::SearchQuery FlightReservationViewModel::QueryObject()
    {
        return m_queryObject;
    }
    void FlightReservationViewModel::QueryObject(ContosoAirlinePOSCpp::SearchQuery const& value)
    {
        UpdateValue<SearchQuery>(L"QueryObject", m_queryObject, value);
    }
    ContosoAirlinePOSCpp::Flight FlightReservationViewModel::SelectedFlight()
    {
        return m_flight;
    }
    void FlightReservationViewModel::SelectedFlight(ContosoAirlinePOSCpp::Flight const& value)
    {
        UpdateValue<Flight>(L"SelectedFlight", m_flight, value);        
    }
    Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::People> FlightReservationViewModel::Passengers()
    {
        return m_passengers;
    }
    void FlightReservationViewModel::Passengers(Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::People> const& value)
    {
        UpdateValue<Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::People>>(L"Passengers", m_passengers, value);       
    }
    double FlightReservationViewModel::InvoiceAmount()
    {
        return m_invoiceAmount;
    }
    void FlightReservationViewModel::InvoiceAmount(double value)
    {
        UpdateValue<double>(L"InvoiceAmount", m_invoiceAmount, value);
    }
    winrt::event_token FlightReservationViewModel::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void FlightReservationViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }

    std::string FlightReservationViewModel::GetArrivalTime()
    {
        std::string strTime;
        winrt::hstring hstrArrivalDate = m_queryObject.SelectedFlight().ArrivalDate();
        SplitDateTime(winrt::to_string(hstrArrivalDate), strTime);
        return strTime;
    }
    std::string FlightReservationViewModel::GetDepartureTime()
    {
        std::string strTime;
        winrt::hstring hstrDepartureDate = m_queryObject.SelectedFlight().DepartureDate();
        SplitDateTime(winrt::to_string(hstrDepartureDate), strTime);
        return strTime;
    }
    void FlightReservationViewModel::SplitDateTime(std::string strInput, std::string& strTime)
    {
        //"2020-08-19.06:00:00"
        if (!strInput.empty())
        {
            int nIndex = (int)strInput.rfind(".");
            if (nIndex != 0)
            {
                std::string strNewString = strInput.substr(nIndex + 1);
                if (!strNewString.empty())
                {
                    strTime = strNewString;
                }
            }
        }
    }
}
