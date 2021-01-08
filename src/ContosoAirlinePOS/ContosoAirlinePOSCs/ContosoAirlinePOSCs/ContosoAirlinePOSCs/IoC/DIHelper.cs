using ContosoAirlinePOSCs.Repository;
using ContosoAirlinePOSCs.Services.BookingSearch;
using ContosoAirlinePOSCs.Services.FlightBooking;
using ContosoAirlinePOSCs.Services.Navigation;
using ContosoAirlinePOSCs.ViewModels;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TinyIoC;

namespace ContosoAirlinePOSCs.IoC
{
    /// <summary>
    /// Dependency Injection Helper class 
    /// utilizing TinyIoC
    /// </summary>
    public class DIHelper
    {
        private static TinyIoCContainer _container;

        static DIHelper()
        {
            _container = new TinyIoCContainer();

            // View models - by default, TinyIoC will register concrete classes as multi-instance.
            _container.Register<LoginViewModel>();
            _container.Register<ShellViewModel>();
            _container.Register<BookFlightViewModel>();
            _container.Register<SearchResultViewModel>();
            _container.Register<SearchViewModel>();
            _container.Register<SettingsViewModel>();

            // Services - by default, TinyIoC will register interface registrations as singletons.
            _container.Register<INavigationService, NavigationService>();
            _container.Register<IRepository, MockRepository>();
            _container.Register<IFlightSearchService, FlightSearchService>();
            _container.Register<IFlightBookingService, FlightBookingService>();
        }

        public static void RegisterSingleton<TInterface, T>() where TInterface : class where T : class, TInterface
        {
            _container.Register<TInterface, T>().AsSingleton();
        }

        public static T Resolve<T>() where T : class
        {
            return _container.Resolve<T>();
        }
    }
}
