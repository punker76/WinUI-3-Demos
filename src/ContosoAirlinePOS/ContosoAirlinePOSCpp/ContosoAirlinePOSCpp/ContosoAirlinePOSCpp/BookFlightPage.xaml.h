#pragma once

#include "BookFlightPage.g.h"
#include "BookFlightViewModel.h"

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct BookFlightPage : BookFlightPageT<BookFlightPage>
    {
        BookFlightPage();
        ContosoAirlinePOSCpp::BookFlightViewModel ViewModel();

        void FlyingToAutoSuggestBox_SuggestionChosen(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender,
            winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args);

        void FlyingFromAutoSuggestBox_SuggestionChosen(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender,
            winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args);

    private:
        ContosoAirlinePOSCpp::BookFlightViewModel m_viewModel{ nullptr };
    };
}

namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct BookFlightPage : BookFlightPageT<BookFlightPage, implementation::BookFlightPage>
    {
    };
}
