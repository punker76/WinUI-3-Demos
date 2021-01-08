using ContosoAirlinePOSCs.Models;
using ContosoAirlinePOSCs.Services.FlightBooking;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.ViewModels
{
    public class FlightReservationViewModel : ViewModelBase
    {
        private IFlightBookingService _flightBookingService;

        public FlightReservationViewModel(
            IFlightBookingService flightBookingService)
        {
            _flightBookingService = flightBookingService;
        }

        public async void Initialize(SearchQuery queryObject)
        {
            QueryObject = queryObject;

            _passengers = new ObservableCollection<People>();
            for (int i = 0; i < queryObject.AdultsCount; i++)
            {
                _passengers.Add(new People() { PassengerIndex = i + 1 });
            }

            SelectedFlight = await _flightBookingService.GetFlightInformation(queryObject.FlightId);
            OnPropertyChanged(nameof(InvoiceAmount));
        }

        private SearchQuery _queryObject;
        public SearchQuery QueryObject
        {
            get { return _queryObject; }
            set { _queryObject = value; OnPropertyChanged(); }
        }


        private Flight _selectedFlight;
        public Flight SelectedFlight
        {
            get { return _selectedFlight; }
            set { _selectedFlight = value; OnPropertyChanged(); }
        }


        private ObservableCollection<People> _passengers;
        public ObservableCollection<People> Passengers
        {
            get { return _passengers; }
            set { _passengers = value; OnPropertyChanged(); }
        }

        public double InvoiceAmount => _selectedFlight != null && _queryObject != null ? _selectedFlight.TicketPrice * _queryObject.AdultsCount : 0;
    }
}
