using ContosoAirlinePOSCs.Services.BookingSearch;
using ContosoAirlinePOSCs.Services.Navigation;
using System;
using System.Collections.ObjectModel;
using System.Linq;
using System.Windows.Input;

namespace ContosoAirlinePOSCs.ViewModels
{
    public class ShellViewModel : ViewModelBase
    {
        private INavigationService _navigationService;        

        public ShellViewModel(
            INavigationService navigationService)
        {
            _navigationService = navigationService;            

            LoadMenuItems();
        }

        private ObservableCollection<MenuItem> _menuItems;
        public ObservableCollection<MenuItem> MenuItems => _menuItems;

        public void LoadMenuItems()
        {
            _menuItems = new ObservableCollection<MenuItem>();

            _menuItems.Add(new MenuItem { Name = "Book Flight", Icon = "\uE709", ViewModelType = nameof(BookFlightViewModel) });
            _menuItems.Add(new MenuItem { Name = "Search", Icon = "\uE721", ViewModelType = nameof(SearchViewModel) });
        }

        public ICommand SelectedPageChangedCommand => new Command<MenuItem>((value) => NavigateToMenuItem(value));
        private void NavigateToMenuItem(MenuItem item)
        {
            switch (item.ViewModelType)
            {
                case nameof(BookFlightViewModel):
                    _navigationService.NavigateTo<BookFlightViewModel>();
                    break;
                case nameof(SearchViewModel):
                    _navigationService.NavigateTo<SearchViewModel>();
                    break;
            }
        }
    }

    public class MenuItem
    {
        public string Name { get; set; }
        public string Icon { get; set; }
        public string ViewModelType { get; set; }
    }
}
