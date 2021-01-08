using Microsoft.UI.Xaml.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Converters
{
    public class TimeSpanToStringConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, string language)
        {
            TimeSpan timeSpan = (TimeSpan)value;

            // for hours
            if (timeSpan.TotalHours == 1 && timeSpan.Minutes == 0)
            {
                return string.Format("{0} hr", timeSpan.ToString("%h"));
            }
            else if (timeSpan.TotalHours > 1 && timeSpan.Minutes == 0)
            {
                return string.Format("{0} hrs", timeSpan.ToString("%h"));
            }
            else if (timeSpan.TotalHours > 1 && timeSpan.Minutes > 0)
            {
                return string.Format("{0} hrs {1} mins", timeSpan.ToString("%h"), timeSpan.ToString("mm"));
            }
            // for minutes
            else
            {
                return string.Format("{0} mins", timeSpan.ToString("mm"));
            }
        }

        public object ConvertBack(object value, Type targetType, object parameter, string language)
        {
            throw new NotImplementedException();
        }
    }
}
