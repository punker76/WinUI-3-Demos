using ContosoAirlinePOSCs.Models;
using ContosoAirlinePOSCs.Repository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Services.BookingSearch
{
    public class FlightSearchService : IFlightSearchService
    {
        private IRepository _repository;
        public FlightSearchService(
            IRepository repository)
        {
            _repository = repository;
        }

        public List<Airport> GetAllAirports()
        {
            return _repository.GetAllDestinations();
        }

        public List<Airport> GetDestinations(Airport sourceAirport)
        {
            return _repository.GetDestinationsForSource(sourceAirport);
        }

        public Tuple<List<Flight>, List<Flight>> GetRecentDepartureArrivals()
        {
            var startTime = DateTime.Now;

            List<Flight> departures = new List<Flight>()
            {
                new Flight()
                {
                    Departure = startTime.AddHours(0.25d),
                    Destination = new Airport() { AirportCode = "TXL", CityName = "Berlin" },
                    FlightCode = "HG 7895",
                    FlightStatus = "Boarding",
                    Gate = "T 11"
                },
                new Flight()
                {
                    Departure = startTime.AddHours(1d),
                    Destination = new Airport() { AirportCode = "LCY", CityName = "London" },
                    FlightCode = "KJ 2596",
                    FlightStatus = "Cancelled",
                    Gate = "T 6"
                },
                new Flight()
                {
                    Departure = startTime.AddHours(1.15d),
                    Destination = new Airport() { AirportCode = "DXB", CityName = "Dubai" },
                    FlightCode = "LK 5888",
                    FlightStatus = "Delayed",
                    Gate = "T 2"
                },
                new Flight()
                {
                    Departure = startTime.AddHours(1.25d),
                    Destination = new Airport() { AirportCode = "CDG", CityName = "Paris" },
                    FlightCode = "HG 7895",
                    FlightStatus = "Boarding",
                    Gate = "T 11"
                },
                new Flight()
                {
                    Departure = startTime.AddHours(1.75d),
                    Destination = new Airport() { AirportCode = "LAX", CityName = "Los Angeles" },
                    FlightCode = "CN 1457",
                    FlightStatus = "On Time",
                    Gate = "T 8"
                },
                new Flight()
                {
                    Departure = startTime.AddHours(2.25d),
                    Destination = new Airport() { AirportCode = "ATL", CityName = "Atlanta" },
                    FlightCode = "LK 6581",
                    FlightStatus = "On Time",
                    Gate = "T 3"
                },
                new Flight()
                {
                    Departure = startTime.AddHours(3.50d),
                    Destination = new Airport() { AirportCode = "BOM", CityName = "Mumbai" },
                    FlightCode = "CN 8743",
                    FlightStatus = "On Time",
                    Gate = "T 7"
                }
            };

            List<Flight> arrivals = new List<Flight>()
            {
                new Flight()
                {
                    Arrival = startTime.AddHours(0.15d),
                    Source = new Airport() { AirportCode = "CDG", CityName = "Paris" },
                    FlightCode = "HG 2498",
                    FlightStatus = "Boarding",
                    Gate = "T 1"
                },
                new Flight()
                {
                    Arrival = startTime.AddHours(0.6d),
                    Source = new Airport() { AirportCode = "ATL", CityName = "Atlanta" },
                    FlightCode = "KJ 1457",
                    FlightStatus = "Cancelled",
                    Gate = "T 16"
                },
                new Flight()
                {
                    Arrival = startTime.AddHours(1.25d),
                    Source = new Airport() { AirportCode = "LAX", CityName = "Los Angeles" },
                    FlightCode = "LK 4761",
                    FlightStatus = "Delayed",
                    Gate = "T 23"
                },
                new Flight()
                {
                    Arrival = startTime.AddHours(1.65d),
                    Source = new Airport() { AirportCode = "TXL", CityName = "Berlin" },
                    FlightCode = "HG 2945",
                    FlightStatus = "Boarding",
                    Gate = "T 12"
                },
                new Flight()
                {
                    Arrival = startTime.AddHours(2.10d),
                    Source = new Airport() { AirportCode = "DXB", CityName = "Dubai" },
                    FlightCode = "CN 3531",
                    FlightStatus = "On Time",
                    Gate = "T 5"
                },
                new Flight()
                {
                    Arrival = startTime.AddHours(2.45d),
                    Source = new Airport() { AirportCode = "BOM", CityName = "Mumbai" },
                    FlightCode = "LK 8751",
                    FlightStatus = "On Time",
                    Gate = "T 7"
                },
                new Flight()
                {
                    Arrival = startTime.AddHours(3.20d),
                    Source = new Airport() { AirportCode = "LCY", CityName = "London" },
                    FlightCode = "CN 6582",
                    FlightStatus = "On Time",
                    Gate = "T 8"
                }
            };

            return new Tuple<List<Flight>, List<Flight>>(departures, arrivals);
        }

        public List<Booking> SearchBookings(SearchQuery queryObject)
        {
            throw new NotImplementedException();
        }
    }
}
