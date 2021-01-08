using ContosoAirlinePOSCs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Services.Dashboard
{
    interface IDashboardService
    {
        Task<Schedule> GetArrivalsAndDeparturesForDateAsync(DateTime date);
        Task<FrequencyStats> GetTop5CitiesWithBookingStatsAsync();
        Task<double> GetOccupancyPercentage();
    }
}
