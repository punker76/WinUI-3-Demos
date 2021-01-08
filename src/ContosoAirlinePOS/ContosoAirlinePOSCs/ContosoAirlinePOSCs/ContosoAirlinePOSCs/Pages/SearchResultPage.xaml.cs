using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using ContosoAirlinePOSCs.ViewModels;
using ContosoAirlinePOSCs.Models;
using ContosoAirlinePOSCs.IoC;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace ContosoAirlinePOSCs.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class SearchResultPage : Page
    {
        public SearchResultPage()
        {
            this.InitializeComponent();
        }

        public SearchResultViewModel ViewModel { get; set; }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);

            var query = e.Parameter as SearchQuery;

            ViewModel = DIHelper.Resolve<SearchResultViewModel>();
            ViewModel.Initialize(query);
        }

        private void BookFlightButton_Clicked(object sender, RoutedEventArgs e)
        {
            var selectedFlight = (sender as Button).DataContext as Flight;
            ViewModel.Query.FlightId = selectedFlight.FlightId;

            ViewModel.InitializeFlightBooking(ViewModel.Query);
        }
    }
}
