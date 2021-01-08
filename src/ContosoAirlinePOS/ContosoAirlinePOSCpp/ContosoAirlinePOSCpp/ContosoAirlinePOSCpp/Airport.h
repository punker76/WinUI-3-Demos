#pragma once
#include "Airport.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct Airport : AirportT<Airport>
    {
        Airport() = default;

        hstring AirportCode();
        void AirportCode(hstring const& value);
        hstring AirportName();
        void AirportName(hstring const& value);
        hstring CityName();
        void CityName(hstring const& value);
        double AverageFlyingHours();
        void AverageFlyingHours(double value);
        double Weight();
        void Weight(double value);
        hstring AirportFullName();
        hstring AirportSearchKey();
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::hstring m_airportCode;
        winrt::hstring m_airportName;
        winrt::hstring m_cityName;
        double m_weight;
        double m_averageFlyHrs;
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
    struct Airport : AirportT<Airport, implementation::Airport>
    {
    };
}