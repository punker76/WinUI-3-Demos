#pragma once
#include "BoardingPassWindow.g.h"
#include "INavigationService.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct BoardingPassWindow : BoardingPassWindowT<BoardingPassWindow>
    {
        BoardingPassWindow();   
        ContosoAirlinePOSCpp::Flight SelectedFlight();
        hstring DepartureDate();
        hstring FlightCode();
        ContosoAirlinePOSCpp::Flight m_SelectedFlight;
        winrt::hstring m_DepartureDate;
        winrt::hstring m_FlightCode;
        void SplitDateTime(std::string strInput, std::string& strTime, std::string& strDate);
    };
}

namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct BoardingPassWindow : BoardingPassWindowT<BoardingPassWindow, implementation::BoardingPassWindow>
    {
    };
}
