#include "pch.h"
#include "BookFlightPage.xaml.h"
#if __has_include("BookFlightPage.g.cpp")
#include "BookFlightPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    BookFlightPage::BookFlightPage()
    {
        m_viewModel = winrt::make<ContosoAirlinePOSCpp::implementation::BookFlightViewModel>();
        InitializeComponent();
    }

    ContosoAirlinePOSCpp::BookFlightViewModel BookFlightPage::ViewModel()
    {
        return m_viewModel;
    }

    void BookFlightPage::FlyingFromAutoSuggestBox_SuggestionChosen(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args)
    {
        Airport airport = unbox_value<Airport>(args.SelectedItem());
        m_viewModel.SourceAirport(airport);
        m_viewModel.FlyingFromInput(airport.AirportFullName());
    }

    void BookFlightPage::FlyingToAutoSuggestBox_SuggestionChosen(winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBox const& sender, winrt::Microsoft::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs const& args)
    {
        Airport airport = unbox_value<Airport>(args.SelectedItem());
        m_viewModel.DestinationAirport(airport);
        m_viewModel.FlyingToInput(airport.AirportFullName());
    }
}