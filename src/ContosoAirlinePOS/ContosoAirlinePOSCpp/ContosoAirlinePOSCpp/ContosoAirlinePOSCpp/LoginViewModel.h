#pragma once
#include "LoginViewModel.g.h"


namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct LoginViewModel : LoginViewModelT<LoginViewModel>
    {
        LoginViewModel() = default;

        hstring Username();
        void Username(hstring const& value);
        hstring Password();
        void Password(hstring const& value);
        hstring Message();
        void Message(hstring const& value);
        void LoginPressed();

        winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

        
    private:
        winrt::hstring m_username;
        winrt::hstring m_password;
        winrt::hstring m_message;
        winrt::event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct LoginViewModel : LoginViewModelT<LoginViewModel, implementation::LoginViewModel>
    {
    };
}


