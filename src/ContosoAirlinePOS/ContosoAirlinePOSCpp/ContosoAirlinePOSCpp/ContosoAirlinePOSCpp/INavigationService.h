#pragma once
#include "SearchQuery.g.h"
using namespace winrt;

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    class INavigationService
    {
    public:
        void InitializeFrame(winrt::Microsoft::UI::Xaml::Controls::Frame rootFrame);

        void NavigateTo(winrt::Windows::UI::Xaml::Interop::TypeName pageNavigateTo);
        
        void SetSearchQuery(SearchQuery _Query);

        void GetSearchQuery(SearchQuery& _Query);

        void RemoveFromBackStack();       
    
        static winrt::Microsoft::UI::Xaml::Controls::Frame m_Frame;

        static SearchQuery m_Query;
    };
}
