#include "pch.h"
#include "People.h"
#include "People.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    int32_t People::PassengerIndex()
    {
        return m_passengerIndex;
    }
    void People::PassengerIndex(int32_t value)
    {
        if (m_passengerIndex != value)
        {
            m_passengerIndex = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"PassengerIndex" });
        }
    }

    hstring People::FirstName()
    {
        return m_firstName;
    }
    void People::FirstName(hstring const& value)
    {
        if (m_firstName != value)
        {
            m_firstName = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"FirstName" });
        }
    }
    hstring People::LastName()
    {
        return m_lastName;
    }
    void People::LastName(hstring const& value)
    {
        if (m_lastName != value)
        {
            m_lastName = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"LastName" });
        }
    }
    hstring People::Gender()
    {
        return m_gender;
    }
    void People::Gender(hstring const& value)
    {
        if (m_gender != value)
        {
            m_gender = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Gender" });
        }
    }
    winrt::event_token People::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void People::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
