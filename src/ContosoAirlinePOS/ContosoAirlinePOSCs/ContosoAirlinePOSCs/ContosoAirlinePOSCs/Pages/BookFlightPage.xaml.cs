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
using System.Numerics;
using ContosoAirlinePOSCs.ViewModels;
using ContosoAirlinePOSCs.IoC;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace ContosoAirlinePOSCs.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class BookFlightPage : Page
    {
        public BookFlightPage()
        {
            this.InitializeComponent();

            QuickTravelGrid1.Translation += new Vector3(0, 0, 32);
            QuickTravelGrid2.Translation += new Vector3(0, 0, 32);
            QuickTravelGrid3.Translation += new Vector3(0, 0, 32);
            QuickTravelGrid4.Translation += new Vector3(0, 0, 32);
            FlightSearchGrid.Translation += new Vector3(0, 0, 32);
        }

        public BookFlightViewModel ViewModel { get; set; }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            ViewModel = DIHelper.Resolve<BookFlightViewModel>();
            ViewModel.Initialize();
        }
    }
}
