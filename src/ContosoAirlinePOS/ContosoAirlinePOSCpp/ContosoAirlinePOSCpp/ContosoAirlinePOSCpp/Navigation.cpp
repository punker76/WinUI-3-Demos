#include "pch.h"
#include "INavigationService.h"


namespace winrt::ContosoAirlinePOSCpp::implementation
{
	winrt::Microsoft::UI::Xaml::Controls::Frame INavigationService::m_Frame = 0;
	SearchQuery INavigationService::m_Query = { 0 };
	void INavigationService::InitializeFrame(winrt::Microsoft::UI::Xaml::Controls::Frame rootFrame)
	{
		m_Frame = rootFrame;		
	}

	void INavigationService::NavigateTo(winrt::Windows::UI::Xaml::Interop::TypeName pageNavigateTo)
	{
		m_Frame.Navigate(pageNavigateTo);		
	}
	void INavigationService::SetSearchQuery(SearchQuery _Query)
	{
		if (m_Query != _Query)
		{
			m_Query = _Query;
		}
	}

	void INavigationService::GetSearchQuery(SearchQuery& _Query)
	{
		_Query = m_Query;
	}	
	void INavigationService::RemoveFromBackStack()
	{

	}
}