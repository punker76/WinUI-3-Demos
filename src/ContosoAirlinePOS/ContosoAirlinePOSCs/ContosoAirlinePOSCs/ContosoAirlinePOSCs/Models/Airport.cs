using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Models
{
    public class Airport : ModelBase
    {
        private string _airportCode;
        public string AirportCode
        {
            get { return _airportCode; }
            set { _airportCode = value; }
        }

        private string _airportName;
        public string AirportName
        {
            get { return _airportName; }
            set { _airportName = value; }
        }

        private string _cityName;
        public string CityName
        {
            get { return _cityName; }
            set { _cityName = value; }
        }


        private double _weight;
        public double Weight
        {
            get { return _weight; }
            set { _weight = value; }
        }

        private double _averageFlyingHours;
        public double AverageFlyingHours
        {
            get { return _averageFlyingHours; }
            set { _averageFlyingHours = value; }
        }

        public string AirportFullName => $"{_airportCode} - {_airportName}, {_cityName}";
    }
}
