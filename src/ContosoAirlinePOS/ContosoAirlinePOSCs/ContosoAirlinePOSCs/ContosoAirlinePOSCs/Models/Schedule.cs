using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Models
{
    public class Schedule : ModelBase
    {
        private DateTime _date;
        public DateTime Date
        {
            get { return _date; }
            set { _date = value; }
        }

        private List<Flight> _arrivals;
        public List<Flight> Arrivals
        {
            get { return _arrivals; }
            set { _arrivals = value; }
        }

        private List<Flight> _departures;
        public List<Flight> Departures
        {
            get { return _departures; }
            set { _departures = value; }
        }
    }
}
