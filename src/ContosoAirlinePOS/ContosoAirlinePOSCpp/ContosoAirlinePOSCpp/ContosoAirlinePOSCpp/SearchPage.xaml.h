#pragma once

#include "SearchPage.g.h"
#include "SearchViewModel.h";

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    struct SearchPage : SearchPageT<SearchPage>
    {
        SearchPage();
        ContosoAirlinePOSCpp::SearchViewModel ViewModel();
    private:
        ContosoAirlinePOSCpp::SearchViewModel m_ViewModel{ nullptr };
    };
}

namespace winrt::ContosoAirlinePOSCpp::factory_implementation
{
    struct SearchPage : SearchPageT<SearchPage, implementation::SearchPage>
    {
    };
}
