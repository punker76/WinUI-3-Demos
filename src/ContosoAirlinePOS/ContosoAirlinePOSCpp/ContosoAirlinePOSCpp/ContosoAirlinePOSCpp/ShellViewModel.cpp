#include "pch.h"
#include "ShellViewModel.h"
#include "ShellViewModel.g.cpp"
#include "MenuItem.h"
#include "INavigationService.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    ShellViewModel::ShellViewModel()
    {
        LoadMenuItems();
    }
    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> ShellViewModel::MenuItems()
    {
        return m_menuItems;
    }
    winrt::event_token ShellViewModel::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void ShellViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }

    void ShellViewModel::LoadMenuItems()
    {
        ContosoAirlinePOSCpp::MenuItem _menuItem1 = winrt::make<winrt::ContosoAirlinePOSCpp::implementation::MenuItem>();
        ContosoAirlinePOSCpp::MenuItem _menuItem2 = winrt::make<winrt::ContosoAirlinePOSCpp::implementation::MenuItem>();


        _menuItem1.Name(L"Book Flight");
        _menuItem1.Icon(L"\uE709");
        
        _menuItem2.Name(L"Search");
        _menuItem2.Icon(L"\uE721");

        m_menuItems = winrt::single_threaded_observable_vector<Windows::Foundation::IInspectable>();
        m_menuItems.Append(_menuItem1);
        m_menuItems.Append(_menuItem2);

        m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"MenuItems" });
    }
    void ShellViewModel::GetEnumFromMenuName(const hstring hMenuName, eMenuName& MenuItem)
    {
        if (wcscmp(hMenuName.c_str(), L"BookFlightViewModel") == 0)
        {
            MenuItem = eMenuName::eBookFlight;
        }
        else if (wcscmp(hMenuName.c_str(), L"SearchViewModel") == 0)
        {
            MenuItem = eMenuName::eSearchFlight;
        }
    }
    void ShellViewModel::NavigateToMenuItem(ContosoAirlinePOSCpp::MenuItem item)
    {
        eMenuName MenuItem;
        INavigationService _navigation;
        GetEnumFromMenuName(item.Name(), MenuItem);
        switch (MenuItem)
        {
        case eMenuName::eBookFlight:
            _navigation.NavigateTo( xaml_typename<ContosoAirlinePOSCpp::BookFlightPage>() );
            break;
        }        
    }
}
