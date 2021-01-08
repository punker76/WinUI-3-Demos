#pragma once
#include "BookFlightPage.g.h"
#include "ShellViewModel.g.h"
#include "MenuItem.g.h"

using namespace std;

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    enum eMenuName
    {
        eBookFlight = 1,
        eSearchFlight
    };
    struct ShellViewModel : ShellViewModelT<ShellViewModel>
    {
    public:
        ShellViewModel();
        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> MenuItems();                       
        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;       
        void NavigateToMenuItem(ContosoAirlinePOSCpp::MenuItem item);

    private:
        void LoadMenuItems();
        void GetEnumFromMenuName(const hstring hMenuName, eMenuName& MenuItem);
        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> m_menuItems;        
        
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct ShellViewModel : ShellViewModelT<ShellViewModel, implementation::ShellViewModel>
    {
    };
}

