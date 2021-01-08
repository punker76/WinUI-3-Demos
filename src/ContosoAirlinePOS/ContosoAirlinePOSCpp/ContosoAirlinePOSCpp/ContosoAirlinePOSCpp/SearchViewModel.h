#pragma once
#include "SearchViewModel.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct SearchViewModel : SearchViewModelT<SearchViewModel>
    {
        SearchViewModel();

        Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::BookingResult> SearchResults();
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
        Windows::Foundation::Collections::IObservableVector<ContosoAirlinePOSCpp::BookingResult> m_bookingResults{ nullptr };
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
    struct SearchViewModel : SearchViewModelT<SearchViewModel, implementation::SearchViewModel>
    {
    };
}
