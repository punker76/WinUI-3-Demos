using ContosoAirlinePOSCs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Services.FlightBooking
{
    public interface IFlightBookingService
    {
        Task<Dictionary<string, List<Flight>>> SearchFlightAsync(SearchQuery queryObject);
        Task<Booking> BookFlightAsync(int flightId, List<People> passengers);
        Task<Booking> GetBookingInformation(int bookingId);
        Task<Flight> GetFlightInformation(int flightId);
    }
}
