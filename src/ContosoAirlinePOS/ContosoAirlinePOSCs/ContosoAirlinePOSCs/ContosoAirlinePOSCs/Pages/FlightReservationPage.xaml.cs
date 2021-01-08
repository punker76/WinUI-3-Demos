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
using ContosoAirlinePOSCs.IoC;
using ContosoAirlinePOSCs.Models;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace ContosoAirlinePOSCs.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class FlightReservationPage : Page
    {
        public FlightReservationPage()
        {
            this.InitializeComponent();
        }

        public FlightReservationViewModel ViewModel { get; set; }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);

            var queryObject = e.Parameter as SearchQuery;

            ViewModel = DIHelper.Resolve<FlightReservationViewModel>();
            ViewModel.Initialize(queryObject);

            PaymentButton.Click += PaymentButton_Click;
        }

        private async void PaymentButton_Click(object sender, RoutedEventArgs e)
        {
            var result = await PaymentConfirmationDialog.ShowAsync();
            if (result == ContentDialogResult.Primary)
            {
                // open boarding pass window here
                BoardingPassWindow window = new BoardingPassWindow((sender as Button).DataContext);
                window.Activate();
            }
        }
    }
}
