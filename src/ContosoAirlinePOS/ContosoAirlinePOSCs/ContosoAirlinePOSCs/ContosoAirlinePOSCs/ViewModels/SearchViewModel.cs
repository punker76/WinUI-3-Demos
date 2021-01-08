using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.ViewModels
{
    public class SearchViewModel : ViewModelBase
    {
        public List<ItemResult> SearchResults = new List<ItemResult>()
        {
            new ItemResult(01,"John Doe",8796079680,10001,900001,"JFK","JAX"),
            new ItemResult(01,"John Doe",8796079680,10001,900001,"JFK","JAX"),
            new ItemResult(01,"John Doe",8796079680,10001,900001,"JFK","JAX"),
            new ItemResult(01,"John Doe",8796079680,10001,900001,"JFK","JAX"),
            new ItemResult(01,"John Doe",8796079680,10001,900001,"JFK","JAX"),
        };

        public int SelectedIndex;
    }

    public class ItemResult {
        public ItemResult(int serial, string name,
            long contactNumber, int bookingID,
            int flightNumber,string destination, 
            string source)
            {
                this.FlightNumber = flightNumber;
                this.BookingID = bookingID;
                this.SerialNumber = serial;
                this.Source = source;
                this.Destination = destination;
                this.ContactNumber = contactNumber;
                this.CustomerName = name;
            }
        public int SerialNumber { get; set; }
        public string CustomerName { get; set; }
        public long ContactNumber { get; set; }
        public int BookingID { get; set; }
        public int FlightNumber { get; set; }
        public string Destination { get; set; }
        public string Source { get; set; }
    }
}
