using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Models
{
    public class Flight : ModelBase
    {
        private int _flightId;
        public int FlightId
        {
            get { return _flightId; }
            set { _flightId = value; OnPropertyChanged(); }
        }

        private string _flightCode;
        public string FlightCode
        {
            get { return _flightCode; }
            set { _flightCode = value; OnPropertyChanged(); }
        }


        private Airport _source;
        public Airport Source
        {
            get { return _source; }
            set { _source = value; OnPropertyChanged(); }
        }

        private Airport _destination;
        public Airport Destination
        {
            get { return _destination; }
            set { _destination = value; OnPropertyChanged(); }
        }

        private DateTime _departure;
        public DateTime Departure
        {
            get { return _departure; }
            set { _departure = value; OnPropertyChanged(); }
        }

        private DateTime _arrival;
        public DateTime Arrival
        {
            get { return _arrival; }
            set { _arrival = value; OnPropertyChanged(); }
        }

        private TimeSpan _duration;
        public TimeSpan Duration
        {
            get { return _duration; }
            set { _duration = value; OnPropertyChanged(); }
        }

        private int _hops;
        public int Hops
        {
            get { return _hops; }
            set { _hops = value; OnPropertyChanged(); }
        }

        private List<Booking> _bookings;
        public List<Booking> Bookings
        {
            get { return _bookings; }
            set { _bookings = value; OnPropertyChanged(); }
        }

        private double _ticketPrice;
        public double TicketPrice
        {
            get { return _ticketPrice; }
            set { _ticketPrice = value; OnPropertyChanged(); }
        }

        private string _flightStatus;
        public string FlightStatus
        {
            get { return _flightStatus; }
            set { _flightStatus = value; OnPropertyChanged(); }
        }

        private string _gate;
        public string Gate
        {
            get { return _gate; }
            set { _gate = value; OnPropertyChanged(); }
        }


        public Flight Copy()
        {
            Flight flight = new Flight()
            {
                FlightCode = this.FlightCode,
                Departure = this.Departure,
                Arrival = this.Arrival,
                Source = this.Source,
                Destination = this.Destination,
                Duration = this.Duration,
                Hops = this.Hops
            };

            return flight;
        }
    }
}
