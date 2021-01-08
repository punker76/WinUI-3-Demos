#include "pch.h"
#include "BoardingPassWindow.xaml.h"
#if __has_include("BoardingPassWindow.g.cpp")
#include "BoardingPassWindow.g.cpp"
#endif

#include "BoardingPassWindow.xaml.h"
using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    BoardingPassWindow::BoardingPassWindow()
    {
        std::string strDate;
        std::string strTime;
        m_SelectedFlight =  SelectedFlight();
        winrt::hstring hstrDepartureDate = m_SelectedFlight.DepartureDate();
        SplitDateTime(to_string(hstrDepartureDate), strTime, strDate);
        m_DepartureDate = to_hstring(strDate);
        m_DepartureDate = DepartureDate();
        m_FlightCode = m_SelectedFlight.FlightCode();
        m_FlightCode = FlightCode();
        InitializeComponent();        
    }    
    ContosoAirlinePOSCpp::Flight BoardingPassWindow::SelectedFlight()
    {
        INavigationService _navigation;
        ContosoAirlinePOSCpp::SearchQuery Query;
        _navigation.GetSearchQuery(Query);
        return Query.SelectedFlight();
    }
    hstring BoardingPassWindow::DepartureDate()
    {
        return m_DepartureDate;
    }
    hstring BoardingPassWindow::FlightCode()
    {
        return m_FlightCode;
    }
    void BoardingPassWindow::SplitDateTime(std::string strInput, std::string& strTime, std::string& strDate)
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
                std::string strNewString1 = strInput.substr(0, nIndex);
                if (!strNewString1.empty())
                {
                    strDate = strNewString1;
                }
            }
        }
    }
    
}
