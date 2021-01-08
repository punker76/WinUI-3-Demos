using ABI.System.Windows.Input;
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

namespace ContosoAirlinePOSCs.ViewModels
{
    public class SearchResultViewModel : ViewModelBase
    {
        private IFlightBookingService _flightBookingService;
        private INavigationService _navigationService;
        public SearchResultViewModel(
            IFlightBookingService flightBookingService,
            INavigationService navigationService)
        {
            _flightBookingService = flightBookingService;
            _navigationService = navigationService;
        }

        private SearchQuery _searchQuery;
        public SearchQuery Query
        {
            get { return _searchQuery; }
            set { _searchQuery = value; OnPropertyChanged(); }
        }

        private ObservableCollection<Flight> _searchResults;
        public ObservableCollection<Flight> SearchResults
        {
            get { return _searchResults; }
            set { _searchResults = value; OnPropertyChanged(); }
        }

        public void Initialize(SearchQuery searchQuery)
        {
            _searchQuery = searchQuery;
            SearchFlights();
        }

        public async void SearchFlights()
        {
            var searchResults = await _flightBookingService.SearchFlightAsync(_searchQuery);
            _searchResults = new ObservableCollection<Flight>(searchResults["TO_DESTINATION"]);
            OnPropertyChanged(nameof(SearchResults));
        }

        public void InitializeFlightBooking(SearchQuery queryObject)
        {
            _navigationService.NavigateTo<FlightReservationViewModel>(queryObject);
        }
    }
}
