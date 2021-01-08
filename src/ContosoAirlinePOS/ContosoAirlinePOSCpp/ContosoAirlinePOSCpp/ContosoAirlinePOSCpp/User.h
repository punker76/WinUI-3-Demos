#pragma once
#include "User.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct User : UserT<User>
    {
        User() = default;

        hstring EmployeeId();
        void EmployeeId(hstring const& value);
        hstring Password();
        void Password(hstring const& value);
        hstring EmployeeName();
        void EmployeeName(hstring const& value);
        hstring ProfilePicture();
        void ProfilePicture(hstring const& value);
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::hstring m_employeeId;
        winrt::hstring m_password;
        winrt::hstring m_employeeName;
        winrt::hstring m_profilePicture;

        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct User : UserT<User, implementation::User>
    {
    };
}

