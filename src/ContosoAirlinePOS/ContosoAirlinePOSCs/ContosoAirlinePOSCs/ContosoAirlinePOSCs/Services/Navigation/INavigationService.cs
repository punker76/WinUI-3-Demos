using ABI.Microsoft.UI.Xaml.Controls;
using ContosoAirlinePOSCs.ViewModels;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContosoAirlinePOSCs.Services.Navigation
{
    public interface INavigationService
    {
        void InitializeFrame(Microsoft.UI.Xaml.Controls.Frame rootFrame);

        void NavigateTo<T>() where T : ViewModelBase;

        void NavigateTo<T>(object parameter) where T : ViewModelBase;

        void RemoveFromBackStack();
    }
}
