#include "pch.h"
#include "SettingsPage.xaml.h"
#include "SettingsPage.g.cpp"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    SettingsPage::SettingsPage() 
    {
        InitializeComponent();
    }

    int selected_index = 2;

    int32_t SettingsPage::SelectedIndex()
    {
        return selected_index;
    }
    void SettingsPage::SelectedIndex(int32_t value)
    {
        selected_index = value;
    }

    auto themes = winrt::single_threaded_observable_vector<hstring>({ L"Light", L"Dark", L"Windows Default" });

    Windows::Foundation::Collections::IObservableVector<hstring> SettingsPage::Themes()
    {
        return themes;
    }

    void SettingsPage::OnThemeChanged(Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs args) 
    {
        winrt::Microsoft::UI::Xaml::Controls::RadioButtons radiobuttons = sender.as<winrt::Microsoft::UI::Xaml::Controls::RadioButtons>();
        if (selected_index == 0) {
            OutputDebugString(L"Dark Theme selected");
            radiobuttons.XamlRoot().Content().as<winrt::Microsoft::UI::Xaml::Controls::Frame>().RequestedTheme(Microsoft::UI::Xaml::ElementTheme::Light);
        }
        else if (selected_index == 1){
            OutputDebugString(L"Light Theme selected");
            radiobuttons.XamlRoot().Content().as<winrt::Microsoft::UI::Xaml::Controls::Frame>().RequestedTheme(Microsoft::UI::Xaml::ElementTheme::Dark);
        }  
        else if (selected_index == 2) {
            OutputDebugString(L"Windows defailt Theme selected");
            radiobuttons.XamlRoot().Content().as<winrt::Microsoft::UI::Xaml::Controls::Frame>().RequestedTheme(Microsoft::UI::Xaml::ElementTheme::Default);
        }
    }
}
