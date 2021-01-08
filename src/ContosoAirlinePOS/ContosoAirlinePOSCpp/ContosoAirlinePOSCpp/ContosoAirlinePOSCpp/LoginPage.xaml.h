#pragma once

#include "LoginViewModel.h"
#include "LoginPage.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct LoginPage : LoginPageT<LoginPage>
    {
        LoginPage();        
        ContosoAirlinePOSCpp::LoginViewModel ViewModel();
                
        private:
        ContosoAirlinePOSCpp::LoginViewModel m_MainLoginViewModel{ nullptr };
    };
}

namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct LoginPage : LoginPageT<LoginPage, implementation::LoginPage>
    {
    };
}

