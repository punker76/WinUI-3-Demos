using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Models
{
    public class FrequencyStats : ModelBase
    {
        private Airport _destination;
        public Airport Destination
        {
            get { return _destination; }
            set { _destination = value; }
        }

        private int _bookingCount;
        public int BookingCount
        {
            get { return _bookingCount; }
            set { _bookingCount = value; }
        }
    }
}
