using ContosoAirlinePOSCs.Models;
using ContosoAirlinePOSCs.Services.BookingSearch;
using ContosoAirlinePOSCs.Services.FlightBooking;
using ContosoAirlinePOSCs.Services.Navigation;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace ContosoAirlinePOSCs.ViewModels
{
    public class BookFlightViewModel : ViewModelBase
    {
        private IFlightSearchService _flightSearchService;
        private INavigationService _navigationService;

        public BookFlightViewModel(
            IFlightSearchService flightSearchService,
            INavigationService navigationService)
        {
            _flightSearchService = flightSearchService;
            _navigationService = navigationService;

            _departureDate = DateTime.Now.Date;
            _returnDate = DateTime.Now.Date.AddDays(2);

            _selectedFlyingClass = FlyingClasses[0];
            _selectedStopPreference = NoOfStops[0];
            _noOfAdultPassengers = 1;
            _noOfChildrenPassengers = 0;
        }

        public void Initialize()
        {
            var recentFlights = _flightSearchService.GetRecentDepartureArrivals();
            UpcomingDepartures = recentFlights.Item1;
            UpcomingArrivals = recentFlights.Item2;
        }

        private bool _isRoundTrip = false;
        public bool IsRoundTrip
        {
            get { return _isRoundTrip; }
            set 
            {
                _isRoundTrip = value; 
                OnPropertyChanged(nameof(IsRoundTrip));
                OnPropertyChanged(nameof(IsOneWay));
            }
        }
        public bool IsOneWay
        {
            get { return !_isRoundTrip; }
            set
            {
                _isRoundTrip = !value;
                OnPropertyChanged(nameof(IsOneWay));
                OnPropertyChanged(nameof(IsRoundTrip));
            }
        }

        public List<string> FlyingClasses => new List<string>() { "Economy", "Business", "First Class" };
        private string _selectedFlyingClass;
        public string SelectedFlyingClass
        {
            get => _selectedFlyingClass;
            set { _selectedFlyingClass = value; OnPropertyChanged(nameof(SelectedFlyingClass)); }
        }


        public List<string> NoOfStops => new List<string>() { "Non Stop", "1+", "2+" };
        private string _selectedStopPreference;
        public string SelectedStopPreference
        {
            get => _selectedStopPreference;
            set { _selectedStopPreference = value; OnPropertyChanged(nameof(SelectedStopPreference)); }
        }


        private int _noOfAdultPassengers;
        public int NoOfAdultPassengers
        {
            get { return _noOfAdultPassengers; }
            set { _noOfAdultPassengers = value; OnPropertyChanged(nameof(NoOfAdultPassengers)); }
        }


        private int _noOfChildrenPassengers;
        public int NoOfChildrenPassengers
        {
            get { return _noOfChildrenPassengers; }
            set { _noOfChildrenPassengers = value; OnPropertyChanged(nameof(NoOfChildrenPassengers)); }
        }


        private string _flyingFromInput;
        public string FlyingFromInput
        {
            get { return _flyingFromInput; }
            set 
            {
                _flyingFromInput = value;
                OnPropertyChanged(nameof(FlyingFromInput));
                SourceAirportSuggestions = _flightSearchService.GetAllAirports()
                    .Where(a => a.AirportName.Contains(value, StringComparison.OrdinalIgnoreCase) || a.AirportCode.Contains(value, StringComparison.OrdinalIgnoreCase) || a.CityName.Contains(value, StringComparison.OrdinalIgnoreCase))
                    .ToList();

                var selectedAirport = _flightSearchService.GetAllAirports().Where(a => a.AirportFullName == value).FirstOrDefault();
                if (selectedAirport != null) _sourceAirport = selectedAirport;
            }
        }


        private List<Airport> _sourceAirportSuggestions;
        public List<Airport> SourceAirportSuggestions
        {
            get { return _sourceAirportSuggestions; }
            set { _sourceAirportSuggestions = value; OnPropertyChanged(nameof(SourceAirportSuggestions)); }
        }


        private Airport _sourceAirport;
        private Airport _destinationAirport;


        private string _flyingToInput;
        public string FlyingToInput
        {
            get { return _flyingToInput; }
            set
            {
                _flyingToInput = value;
                OnPropertyChanged(nameof(FlyingToInput));
                if (_sourceAirport != null)
                {
                    DestinationAirportSuggestions = _flightSearchService.GetDestinations(_sourceAirport)
                        .Where(a => a.AirportName.Contains(value, StringComparison.OrdinalIgnoreCase) || a.AirportCode.Contains(value, StringComparison.OrdinalIgnoreCase) || a.CityName.Contains(value, StringComparison.OrdinalIgnoreCase))
                        .ToList();
                    var selectedAirport = _flightSearchService.GetAllAirports().Where(a => a.AirportFullName == value).FirstOrDefault();
                    if (selectedAirport != null) _destinationAirport = selectedAirport;
                }
            }
        }


        private List<Airport> _destinationAirportSuggestions;
        public List<Airport> DestinationAirportSuggestions
        {
            get { return _destinationAirportSuggestions; }
            set { _destinationAirportSuggestions = value; OnPropertyChanged(nameof(DestinationAirportSuggestions)); }
        }

        
        private DateTimeOffset _departureDate;
        public DateTimeOffset DepartureDate
        {
            get { return _departureDate; }
            set { _departureDate = value; OnPropertyChanged(nameof(DepartureDate)); }
        }


        private DateTimeOffset _returnDate;
        public DateTimeOffset ReturnDate
        {
            get { return _returnDate; }
            set { _returnDate = value; OnPropertyChanged(nameof(ReturnDate)); }
        }

        private List<Flight> _upcomingDepartures;
        public List<Flight> UpcomingDepartures
        {
            get { return _upcomingDepartures; }
            set { _upcomingDepartures = value; OnPropertyChanged(); }
        }

        private List<Flight> _upcomingArrivals;
        public List<Flight> UpcomingArrivals
        {
            get { return _upcomingArrivals; }
            set { _upcomingArrivals = value; OnPropertyChanged(); }
        }

        public ICommand SearchFlightCommand => new Command(() => SearchFlight());

        private void SearchFlight()
        {
            SearchQuery queryObject = new SearchQuery()
            {
                Source = _sourceAirport,
                Destination = _destinationAirport,
                AdultsCount = _noOfAdultPassengers,
                ChildrenCount = _noOfChildrenPassengers,
                IsNonStop = true,
                IsRoundTrip = false,
                TravelClass = "Economy",
                TravelDate = _departureDate.DateTime
            };

            _navigationService.NavigateTo<SearchResultViewModel>(queryObject);
        }
    }
}
