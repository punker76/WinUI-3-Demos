#pragma once
#include <ppltasks.h>
#include <string>
#include "User.h"
using namespace concurrency;
using namespace std;
namespace winrt::ContosoAirlinePOSCpp::implementation
{
    class IAuthenticationService
    {
        //Windows::Foundation::IAsyncAction
        //Task<User> SignInAsync(string employeeId, string password); 
        
        Windows::Foundation::IAsyncOperation<User> SignInAsync(string employeeId, string password);
         //task<User>SignInAsync(string employeeId, string password){}
    };
}