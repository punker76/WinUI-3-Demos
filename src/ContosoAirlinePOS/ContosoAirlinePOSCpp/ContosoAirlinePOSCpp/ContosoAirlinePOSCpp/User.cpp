#include "pch.h"
#include "User.h"
#include "User.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    hstring User::EmployeeId()
    {
        return m_employeeId;
    }
    void User::EmployeeId(hstring const& value)
    {
        if (m_employeeId != value)
        {
            m_employeeId = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"EmployeeId" });
        }
    }
    hstring User::Password()
    {
        return m_password;
    }
    void User::Password(hstring const& value)
    {
        if (m_password != value)
        {
            m_password = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Password" });
        }
    }
    hstring User::EmployeeName()
    {
        return m_employeeName;
    }
    void User::EmployeeName(hstring const& value)
    {
        if (m_employeeName != value)
        {
            m_employeeName = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"EmployeeName" });
        }
    }
    hstring User::ProfilePicture()
    {
        return m_profilePicture;
    }
    void User::ProfilePicture(hstring const& value)
    {
        if (m_profilePicture != value)
        {
            m_profilePicture = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"ProfilePicture" });
        }
    }
    winrt::event_token User::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void User::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
