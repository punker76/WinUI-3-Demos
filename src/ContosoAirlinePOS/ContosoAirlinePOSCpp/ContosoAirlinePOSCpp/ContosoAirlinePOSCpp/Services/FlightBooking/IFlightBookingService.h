#pragma once
#include <ppltasks.h>
#include <string>
#include <map>
#include <vector>
#include "SearchQuery.h"
#include "Flight.h"
#include "Booking.h"
#include "People.h"

using namespace concurrency;
using namespace std;
namespace winrt::ContosoAirlinePOSCpp::implementation
{
	class IFlightBookingService
	{
		Windows::Foundation::IAsyncOperation<map<string, vector<Flight>>> SearchFlightAsync(SearchQuery queryObject);
		Windows::Foundation::IAsyncOperation<Booking> BookFlightAsync(int flightId, vector<People> passengers);
		Windows::Foundation::IAsyncOperation<Booking> GetBookingInformation(int bookingId);
	};
}