#include "pch.h"
#include "PassengerFormControl.xaml.h"
#if __has_include("PassengerFormControl.g.cpp")
#include "PassengerFormControl.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    PassengerFormControl::PassengerFormControl()
    {
        InitializeComponent();
    }
}
