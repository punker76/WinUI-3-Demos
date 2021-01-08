#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "PassengerFormControl.g.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct PassengerFormControl : PassengerFormControlT<PassengerFormControl>
    {
        PassengerFormControl();
    };
}

namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct PassengerFormControl : PassengerFormControlT<PassengerFormControl, implementation::PassengerFormControl>
    {
    };
}
