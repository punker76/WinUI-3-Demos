#pragma once
#include "SettingsPage.g.h"


namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct SettingsPage : SettingsPageT<SettingsPage>
    {
        SettingsPage();

        int32_t SelectedIndex();
        void SelectedIndex(int32_t value);
        Windows::Foundation::Collections::IObservableVector<hstring> Themes();
        void Themes(Windows::Foundation::Collections::IObservableVector<hstring> const& value);
        void SettingsPage::OnThemeChanged(Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs args);
    };
}
namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct SettingsPage : SettingsPageT<SettingsPage, implementation::SettingsPage>
    {
    };
}
