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
using ContosoAirlinePOSCs.IndividualPagesXAML;
using ContosoAirlinePOSCs.Models;
using ContosoAirlinePOSCs.Pages;
using System.ComponentModel;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace ContosoAirlinePOSCs
{
    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class FlightReservationWindow : Window
    {
        private SearchQuery _queryObject;

        public FlightReservationWindow(SearchQuery queryObject)
        {
            this.InitializeComponent();

            _queryObject = queryObject;

            ShellFrame.Navigate(typeof(FlightReservationPage), _queryObject);

            PaymentButton.Click += PaymentButton_Click;
        }

        int currentStep = 0;
        private void PaymentButton_Click(object sender, RoutedEventArgs e)
        {
            switch (currentStep)
            {
                case 0:
                    ShellFrame.Navigate(typeof(PaymentPage));
                    break;
                case 1:
                    ShellFrame.Navigate(typeof(BoardingPass));
                    PaymentButton.Content = "Finish";
                    break;
                case 2:
                    this.Close();
                    break;
            }

            currentStep++;
        }
    }
}
