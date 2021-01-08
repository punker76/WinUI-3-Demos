using ContosoAirlinePOSCs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Repository
{
    public interface IRepository
    {
        List<Airport> GetAllDestinations();
        List<Airport> GetDestinationsForSource(Airport departureAirport);
        List<Flight> GetAllSchedules();
        List<Flight> SearchFlights(Airport source, Airport destination, DateTime date);
    }
}
