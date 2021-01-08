using ContosoAirlinePOSCs.Helpers;
using ContosoAirlinePOSCs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Repository
{
    public class MockRepository : IRepository
    {
        public MockRepository()
        {
            GenerateFlights();
        }

        private Airport _source = new Airport() 
        {
            AirportCode = "JFK",
            CityName = "New York City, NY",
            AirportName = "John F. Kennedy International Airport"
        };

        private Airport[] _destinations = new Airport[] 
        {
            new Airport()
            {
                AirportCode = "LAX",
                CityName = "Los Angeles, CA",
                AirportName = "Los Angeles International Airport",
                Weight = 4,
                AverageFlyingHours = 5.7
            },
            new Airport()
            {
                AirportCode = "ATL",
                CityName = "Atlanta, GA",
                AirportName = "Hartsfield–Jackson Atlanta International Airport",
                Weight = 3,
                AverageFlyingHours = 2.3
            },
            new Airport() {
                AirportCode = "ORD",
                CityName = "Chicago, IL",
                AirportName = "O'Hare International Airport",
                Weight = 4,
                AverageFlyingHours = 2.3
            },
            new Airport()
            {
                AirportCode = "DFW",
                CityName = "Dallas, TX",
                AirportName = "Dallas/Fort Worth International Airport",
                Weight = 2,
                AverageFlyingHours = 3.3
            },
            new Airport()
            {
                AirportCode = "DEN",
                CityName = "Denver, CO",
                AirportName = "Denver International Airport",
                Weight = 2,
                AverageFlyingHours = 4.1
            },
            new Airport()
            {
                AirportCode = "SFO",
                CityName = "San Francisco, CA",
                AirportName = "San Francisco International Airport",
                Weight = 3,
                AverageFlyingHours = 6.2
            },
            new Airport()
            {
                AirportCode = "SEA",
                CityName = "Seattle, WA",
                AirportName = "Seattle–Tacoma International Airport",
                Weight = 4,
                AverageFlyingHours = 6.1
            }
        };

        private List<Flight> _schedules = null;

        private const double FLIGHT_MULTIPLYING_FACTOR = 1d;
        private const string FLIGHT_CODE_PREFIX = "CN ";
        private const int DAY_BRACKET = 40;

        private void GenerateFlights()
        {
            // Steps
            // 1. Generate flights and frequency for a day
            // 2. Duplicate the flights for each day with new flightID

            var startTime = DateTime.Now.Date.AddHours(5);
            var endTime = DateTime.Now.Date.AddHours(19);

            // 1. Generate flights and frequency for a day
            List<Flight> flights = new List<Flight>();

            int flightCode = 0;
            foreach (var destination in _destinations)
            {
                int frequency = (int)(destination.Weight * FLIGHT_MULTIPLYING_FACTOR);

                var flightTime = startTime;
                int operatingBracket = (int)(endTime - startTime).TotalHours;
                var randomIterations = GetNRandomNumbersInRange(0, operatingBracket, frequency);
                for (int i = 0; i < frequency; i++)
                {
                    Flight flight = new Flight()
                    {
                        FlightCode = FLIGHT_CODE_PREFIX + GetFourDigitFlightCode(++flightCode),
                        Source = _source,
                        Destination = destination,
                        Departure = startTime.AddHours(randomIterations[i]),
                        Hops = 0
                    };
                    flight.Arrival = flight.Departure.AddHours(destination.AverageFlyingHours + (((double)GetRandomNumberInRange(-1, 1)) / 10d));
                    flight.Duration = flight.Arrival - flight.Departure;
                    flights.Add(flight);
                }
            }

            // 2. Duplicate the flights for each day with new flightsID
            _schedules = new List<Flight>();

            var currentDate = DateTime.Now.Date;
            var startDate = currentDate.AddDays(0 - DAY_BRACKET);
            var endDate = currentDate.AddDays(DAY_BRACKET);
            int daySpan = (int)(endDate - startDate).TotalDays;

            int flightId = 0;

            for (int i = 0; i < daySpan; i++)
            {
                var date = startDate.AddDays(i);
                foreach (var flight in flights)
                {
                    var dateDiff = date - flight.Departure.Date;

                    var f = flight.Copy();
                    f.FlightId = ++flightId;
                    f.Departure = f.Departure.AddDays((int)dateDiff.TotalDays);
                    f.Arrival = f.Arrival.AddDays((int)dateDiff.TotalDays);
                    f.TicketPrice = GetRandomNumberInRange(110, 240);

                    _schedules.Add(f);
                }
            }
        }

        private string GetFourDigitFlightCode(int code)
        {
            return code.ToString("D4");
        }

        private List<int> GetNRandomNumbersInRange(int start, int end, int n)
        {
            List<int> numbers = new List<int>();
            for (int i = start; i < end; i++) { numbers.Add(i); }
            numbers.Shuffle();
            return numbers.GetRange(0, n);
        }

        private int GetRandomNumberInRange(int start, int end)
        {
            Random r = new Random();
            return r.Next(start, end);
        }

        public List<Airport> GetAllDestinations()
        {
            var list = new List<Airport>(_destinations);
            list.Add(_source);
            return list;
        }

        public List<Flight> GetAllSchedules()
        {
            return _schedules;
        }

        public List<Airport> GetDestinationsForSource(Airport departureAirport)
        {
            return _schedules.Where(s => s.Source == departureAirport)
                                    .Select(s => s.Destination).Distinct().ToList();
        }

        public List<Flight> SearchFlights(Airport source, Airport destination, DateTime date)
        {
            return _schedules.Where(s => s.Source == source && s.Destination == destination && s.Departure.Date == date.Date).ToList();
        }
    }
}
