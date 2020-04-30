#pragma once

#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime

#include "MainWindow.g.h"

#pragma pop_macro("GetCurrentTime")

namespace winrt::Blank_App_WinUI_Desktop_Cpp::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Blank_App_WinUI_Desktop_Cpp::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
