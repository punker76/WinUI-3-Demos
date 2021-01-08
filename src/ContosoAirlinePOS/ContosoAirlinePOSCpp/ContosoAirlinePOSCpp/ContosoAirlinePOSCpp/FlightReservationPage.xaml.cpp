#include "pch.h"
#include "FlightReservationPage.xaml.h"
#if __has_include("FlightReservationPage.g.cpp")
#include "FlightReservationPage.g.cpp"
#endif

using namespace std;
using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    FlightReservationPage::FlightReservationPage()
    {
        m_ViewModel = winrt::make<ContosoAirlinePOSCpp::implementation::FlightReservationViewModel>();
        InitializeComponent();
    }

    ContosoAirlinePOSCpp::FlightReservationViewModel FlightReservationPage::ViewModel()
    {
        return m_ViewModel;
    }

    void FlightReservationPage::PaymentButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        INavigationService _navigationService;
        _navigationService.NavigateTo(xaml_typename<ContosoAirlinePOSCpp::BoardingPassWindow>());
    }

    typedef int(_stdcall* RENDERSEATLAYOUT)();
    typedef void(_stdcall* CLOSERENDERSEATLAYOUT)();
    void FlightReservationPage::SeatSelectionButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        TCHAR buffer[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, buffer, MAX_PATH);
        string strExeFilePath(&buffer[0], &buffer[MAX_PATH]);

        if (!strExeFilePath.empty())
        {
            string strExeName = "ContosoAirlinePOSCpp.exe";
            string strDLLName = "ContosoSeatBooking.dll";
            int nIndex = strExeFilePath.find(strExeName);
            if (nIndex != 0)
            {
                string strFullDllPath = strExeFilePath.replace(nIndex, sizeof(strExeName), strDLLName);
                if (!strFullDllPath.empty())
                {
                    HINSTANCE hInstance = ::LoadLibraryExA(strFullDllPath.c_str(), 0, LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
                    if (hInstance != nullptr)
                    {
                        RENDERSEATLAYOUT        objRenderSeatLayout;
                        CLOSERENDERSEATLAYOUT   objCloseRenderSeatLayout;
                        objRenderSeatLayout = (RENDERSEATLAYOUT)GetProcAddress(hInstance, "RenderSeatLayout");
                        if (objRenderSeatLayout != nullptr)
                        {
                            int nSeatRender = objRenderSeatLayout();

                            if (nSeatRender != 0)
                            {
                                objCloseRenderSeatLayout = (CLOSERENDERSEATLAYOUT)GetProcAddress(hInstance, "Close");
                                if (objCloseRenderSeatLayout != nullptr)
                                {
                                    objCloseRenderSeatLayout();
                                }

                                if (hInstance)
                                {
                                    FreeLibrary(hInstance);
                                    hInstance = nullptr;
                                }
                            }
                        }
                    }
                }
            }

        }
    }
}
