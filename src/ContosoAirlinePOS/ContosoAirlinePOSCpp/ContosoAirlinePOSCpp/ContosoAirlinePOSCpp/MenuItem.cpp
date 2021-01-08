#include "pch.h"
#include "MenuItem.h"
#include "MenuItem.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    hstring MenuItem::Name()
    {
        return m_menuname;
    }
    void MenuItem::Name(hstring const& value)
    {
        if (m_menuname != value)
        {
            m_menuname = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Name" });
        }
    }
    hstring MenuItem::Icon()
    {
        return m_menuicon;
    }
    void MenuItem::Icon(hstring const& value)
    {
        if (m_menuicon != value)
        {
            m_menuicon = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Icon" });
        }
    }
    hstring MenuItem::ViewModelType()
    {
        return m_menuviewmodeltype;
    }
    void MenuItem::ViewModelType(hstring const& value)
    {
        if (m_menuviewmodeltype != value)
        {
            m_menuviewmodeltype = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"ViewModelType" });
        }
    }
    winrt::event_token MenuItem::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void MenuItem::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
