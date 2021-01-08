#pragma once
#include "People.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct People : PeopleT<People>
    {
        People() = default;

        int32_t PassengerIndex();
        void PassengerIndex(int32_t value);
        hstring FirstName();
        void FirstName(hstring const& value);
        hstring LastName();
        void LastName(hstring const& value);
        hstring Gender();
        void Gender(hstring const& value);
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        int32_t m_passengerIndex;
        winrt::hstring m_firstName;
        winrt::hstring m_lastName;
        winrt::hstring m_gender;

        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct People : PeopleT<People, implementation::People>
    {
    };
}

