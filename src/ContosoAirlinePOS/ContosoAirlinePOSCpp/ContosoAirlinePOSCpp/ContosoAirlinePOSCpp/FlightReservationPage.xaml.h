#pragma once

#include "FlightReservationPage.g.h"
#include "FlightReservationViewModel.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct FlightReservationPage : FlightReservationPageT<FlightReservationPage>
    {
        FlightReservationPage();
        ContosoAirlinePOSCpp::FlightReservationViewModel ViewModel();
        void PaymentButton_Click(winrt::Windows::Foundation::IInspectable const& sender,
            winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void SeatSelectionButton_Click(winrt::Windows::Foundation::IInspectable const& sender,
            winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    private:
        ContosoAirlinePOSCpp::FlightReservationViewModel m_ViewModel{ nullptr };
    };
}

namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct FlightReservationPage : FlightReservationPageT<FlightReservationPage, implementation::FlightReservationPage>
    {
    };
}
