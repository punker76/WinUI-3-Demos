using ContosoAirlinePOSCs.Pages;
using ContosoAirlinePOSCs.ViewModels;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Services.Navigation
{
    class NavigationService : INavigationService
    {
        private Frame _shellFrame;

        public void InitializeFrame(Frame rootFrame)
        {
            _shellFrame = rootFrame;
            NavigateTo<LoginViewModel>();
        }

        public void NavigateTo<T>() where T : ViewModelBase
        {
            InternalNavigateTo(typeof(T), null);
        }

        public void NavigateTo<T>(object parameter) where T : ViewModelBase
        {
            InternalNavigateTo(typeof(T), parameter);
        }

        public void RemoveFromBackStack()
        {
            _shellFrame?.BackStack.Remove(_shellFrame.BackStack.Last());
        }

        private void InternalNavigateTo(Type viewModelType, object parameter)
        {
            var pageType = GetPageTypeForViewModel(viewModelType);
            _shellFrame?.Navigate(pageType, parameter);

            var content = _shellFrame.Content;
            if (content is ShellPage shellPage)
            {
                var navigationView = (shellPage.Content as Panel).Children.OfType<NavigationView>().First();
                var navFrame = (navigationView.Content as Panel).Children.OfType<Frame>().First();
                _shellFrame = navFrame;

                // navigate to book flight viewmodel
                NavigateTo<BookFlightViewModel>();
            }
        }

        private Type GetPageTypeForViewModel(Type viewModelType)
        {
            var viewName = viewModelType.FullName.Replace("ViewModel", "Page");
            var viewModelAssemblyName = viewModelType.GetTypeInfo().Assembly.FullName;
            var viewAssemblyName = string.Format(CultureInfo.InvariantCulture, "{0}, {1}", viewName, viewModelAssemblyName);
            var viewType = Type.GetType(viewAssemblyName);
            return viewType;
        }
    }
}
