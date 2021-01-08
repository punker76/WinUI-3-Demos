using ContosoAirlinePOSCs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Services.Authentication
{
    interface IAuthenticationService
    {
        Task<User> SignInAsync(string employeeId, string password);
    }
}
