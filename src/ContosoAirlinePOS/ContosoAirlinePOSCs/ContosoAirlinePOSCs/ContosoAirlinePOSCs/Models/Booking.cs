using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Models
{
    public class Booking
    {
        private int _bookingId;
        public int BookingId
        {
            get { return _bookingId; }
            set { _bookingId = value; }
        }

        private string _registeredMobileNumber;
        public string RegisteredMobileNumber
        {
            get { return _registeredMobileNumber; }
            set { _registeredMobileNumber = value; }
        }

        private string _registeredEmailAddress;
        public string RegisteredEmailAddress
        {
            get { return _registeredEmailAddress; }
            set { _registeredEmailAddress = value; }
        }

        private DateTime _dateOfBooking;
        public DateTime DateOfBooking
        {
            get { return _dateOfBooking; }
            set { _dateOfBooking = value; }
        }

        private int _flightId;
        public int FlightId
        {
            get { return _flightId; }
            set { _flightId = value; }
        }

        private List<People> _passengers;
        public List<People> Passengers
        {
            get { return _passengers; }
            set { _passengers = value; }
        }

        private double _invoiceAmount;
        public double InvoiceAmount
        {
            get { return _invoiceAmount; }
            set { _invoiceAmount = value; }
        }

        private string _transactionId;
        public string TransactionId
        {
            get { return _transactionId; }
            set { _transactionId = value; }
        }
    }
}
