using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Models
{
    public class SearchQuery
    {
        public Airport Source { get; set; }
        public Airport Destination { get; set; }
        public DateTime TravelDate { get; set; }
        public bool IsRoundTrip { get; set; }
        public DateTime ReturnDate { get; set; }
        public string TravelClass { get; set; }
        public bool IsNonStop { get; set; }
        public int AdultsCount { get; set; }
        public int ChildrenCount { get; set; }
        public int FlightId { get; set; }
    }
}
