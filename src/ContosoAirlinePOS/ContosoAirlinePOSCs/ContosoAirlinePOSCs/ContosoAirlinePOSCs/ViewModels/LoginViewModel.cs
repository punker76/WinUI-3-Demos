using ContosoAirlinePOSCs.Services.Navigation;
using System.Windows.Input;

namespace ContosoAirlinePOSCs.ViewModels
{
    public class LoginViewModel : ViewModelBase
    {
        private INavigationService _navigationService;
        public LoginViewModel(
            INavigationService navigationService)
        {
            _navigationService = navigationService;
        }

        private string _username;
        public string Username
        {
            get { return _username; }
            set { _username = value; OnPropertyChanged(nameof(Username)); }
        }

        private string _password;
        public string Password
        {
            get { return _password; }
            set { _password = value; OnPropertyChanged(nameof(Password)); }
        }

        private string _message;
        public string Message
        {
            get { return _message; }
            set { _message = value; OnPropertyChanged(nameof(Message)); }
        }

        public ICommand LoginCommand => new Command(() => Login());

        private void Login()
        {
            _navigationService.NavigateTo<ShellViewModel>();
        }
    }
}
