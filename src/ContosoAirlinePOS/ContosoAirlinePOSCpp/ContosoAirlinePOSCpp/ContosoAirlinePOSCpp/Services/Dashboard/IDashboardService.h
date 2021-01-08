#pragma once
#include <ppltasks.h>
#include <string>
#include <datetimeapi.h>
#include "Schedule.h"
#include "FrequencyStats.h"

using namespace concurrency;
using namespace std;
namespace winrt::ContosoAirlinePOSCpp::implementation
{
    class IDashboardService
    {
        Windows::Foundation::IAsyncOperation<Schedule> GetArrivalsAndDeparturesForDateAsync(DateTime date);
        Windows::Foundation::IAsyncOperation<FrequencyStats> GetTop5CitiesWithBookingStatsAsync();
        Windows::Foundation::IAsyncOperation<double> GetOccupancyPercentage();
    };
}