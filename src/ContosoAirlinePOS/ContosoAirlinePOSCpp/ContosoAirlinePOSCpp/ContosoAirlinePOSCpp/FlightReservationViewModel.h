#pragma once
#include "FlightReservationViewModel.g.h"
#include "INavigationService.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct FlightReservationViewModel : FlightReservationViewModelT<FlightReservationViewModel>
    {
        FlightReservationViewModel();

        ContosoAirlinePOSCpp::SearchQuery QueryObject();
        void QueryObject(ContosoAirlinePOSCpp::SearchQuery const& value);
        ContosoAirlinePOSCpp::Flight SelectedFlight();
        void SelectedFlight(ContosoAirlinePOSCpp::Flight const& value);
        Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::People> Passengers();
        void Passengers(Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::People> const& value);
        double InvoiceAmount();
        void InvoiceAmount(double value);
        std::string GetArrivalTime();
        std::string GetDepartureTime();
        void SplitDateTime(std::string strInput, std::string& strTime);

        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        Flight m_flight{ nullptr };
        SearchQuery m_queryObject{ nullptr };
        Windows::Foundation::Collections::IObservableVector<People> m_passengers{ nullptr };
        double m_invoiceAmount{ 0 };

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
