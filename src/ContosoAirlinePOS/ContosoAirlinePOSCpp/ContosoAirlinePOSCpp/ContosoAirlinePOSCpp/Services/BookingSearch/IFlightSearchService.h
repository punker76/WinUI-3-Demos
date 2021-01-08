#pragma once
#include "Booking.g.h"
#include "Airport.g.h"
#include "Flight.g.h"
#include "SearchQuery.g.h"
#include "MockRepository.h"
#include <vector>
#define NUMBER_OF_FLIGHT 7

namespace winrt::ContosoAirlinePOSCpp::implementation
{
    class IFlightSearchService
    {
    public:
        IFlightSearchService();
        std::vector<Booking> SearchBookings(SearchQuery queryObject);
        std::vector<Airport> GetAllAirports();
        std::vector<Airport> GetDestinations(Airport sourceAirport);
        std::tuple<std::vector<Flight>, std::vector<Flight>> GetRecentDepartureArrivals();
        std::string GetTimeForFlight(int nHours,std::string strTime);
        ~IFlightSearchService();
    private:
        MockRepository *pm_mockRepository;
    };
}