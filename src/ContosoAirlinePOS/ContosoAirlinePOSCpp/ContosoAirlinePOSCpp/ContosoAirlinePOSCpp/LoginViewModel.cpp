#include "pch.h"
#include "LoginViewModel.h"
#include "MockRepository.h"
#include "INavigationService.h"
#include "LoginViewModel.g.cpp"
#include <Generated Files\winrt\Windows.UI.Xaml.Interop.h>


namespace winrt::ContosoAirlinePOSCpp::implementation
{
    hstring LoginViewModel::Username()
    {
        return m_username;
    }
    void LoginViewModel::Username(hstring const& value)
    {
        if (m_username != value)
        {
            m_username = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Username" });
        }
    }
    hstring LoginViewModel::Password()
    {
        return m_password;
    }
    void LoginViewModel::Password(hstring const& value)
    {
        if (m_password != value)
        {
            m_password = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Password" });
        }
    }
   
    winrt::event_token LoginViewModel::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void LoginViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
    hstring LoginViewModel::Message()
    {
        return m_message;
    }
    void LoginViewModel::Message(hstring const& value)
    {
        if (m_message != value)
        {
            m_message = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Message" });
        }
    }
    void LoginViewModel::LoginPressed()
    {
        INavigationService _navigationService;
        _navigationService.NavigateTo(xaml_typename<ShellPage>());
    }    
}

