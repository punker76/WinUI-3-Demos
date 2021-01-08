using ContosoAirlinePOSCs.Models;
using ContosoAirlinePOSCs.Repository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Services.FlightBooking
{
    public class FlightBookingService : IFlightBookingService
    {
        private IRepository _repository;
        public FlightBookingService(IRepository repository)
        {
            _repository = repository;
        }

        public Task<Booking> BookFlightAsync(int flightId, List<People> passengers)
        {
            throw new NotImplementedException();
        }

        public Task<Booking> GetBookingInformation(int bookingId)
        {
            throw new NotImplementedException();
        }

        public async Task<Flight> GetFlightInformation(int flightId)
        {
            // delay the execution 
            // with 200ms
            await Task.Delay(200);

            var result = _repository.GetAllSchedules().Where(f => f.FlightId == flightId).FirstOrDefault();
            return result;
        }

        public async Task<Dictionary<string, List<Flight>>> SearchFlightAsync(SearchQuery queryObject)
        {
            Dictionary<string, List<Flight>> flightResult = new Dictionary<string, List<Flight>>();

            // delay the execution 
            // with 200ms
            await Task.Delay(200);

            if (queryObject.IsRoundTrip == false)
            {
                var sourceToDestinationFlights = _repository.SearchFlights(queryObject.Source, queryObject.Destination, queryObject.TravelDate);
                flightResult.Add("TO_DESTINATION", sourceToDestinationFlights);
                return flightResult;
            }
            else
            {
                throw new NotImplementedException();
            }
        }
    }
}
