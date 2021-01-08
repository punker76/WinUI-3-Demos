#include "pch.h"
#include "SearchResultPage.xaml.h"
#if __has_include("SearchResultPage.g.cpp")
#include "SearchResultPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    SearchResultPage::SearchResultPage()
    {
        m_SearchResultViewModel = winrt::make<ContosoAirlinePOSCpp::implementation::SearchResultViewModel>();
        InitializeComponent();
    }
    
    ContosoAirlinePOSCpp::SearchResultViewModel SearchResultPage::ViewModel()
    {
        return m_SearchResultViewModel;
    }

    void SearchResultPage::BookFlightButton_Clicked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        auto button = unbox_value<winrt::Microsoft::UI::Xaml::Controls::Button>(sender);
        auto flight = button.DataContext().as<Flight>();
        m_SearchResultViewModel.BookFlight(flight);
    }
}
