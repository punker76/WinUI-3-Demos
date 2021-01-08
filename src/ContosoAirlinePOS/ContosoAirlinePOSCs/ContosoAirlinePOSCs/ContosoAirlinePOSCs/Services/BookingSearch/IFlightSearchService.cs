using ContosoAirlinePOSCs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Services.BookingSearch
{
    public interface IFlightSearchService
    {
        List<Booking> SearchBookings(SearchQuery queryObject);
        List<Airport> GetAllAirports();
        List<Airport> GetDestinations(Airport sourceAirport);
        Tuple<List<Flight>, List<Flight>> GetRecentDepartureArrivals();
    }
}
