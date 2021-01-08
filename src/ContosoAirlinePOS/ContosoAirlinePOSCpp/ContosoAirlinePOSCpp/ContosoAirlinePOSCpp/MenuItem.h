#pragma once
#include "MenuItem.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct MenuItem : MenuItemT<MenuItem>
    {
        MenuItem() = default;

        hstring Name();
        void Name(hstring const& value);
        hstring Icon();
        void Icon(hstring const& value);
        hstring ViewModelType();
        void ViewModelType(hstring const& value);
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
        winrt::hstring m_menuname;
        winrt::hstring m_menuicon;
        winrt::hstring m_menuviewmodeltype;
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

