using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace ContosoAirlinePOSCs.ViewModels
{
    public class SettingsViewModel : ViewModelBase
    {
        public List<string> Themes = new List<string>
        {
            "Light","Dark","Windows Default"
        };
        private int _selectedIndex = 2;
        public int SelectedIndex
        {
            get => _selectedIndex;
            set 
            { 
                _selectedIndex = value;
                OnPropertyChanged(nameof(SelectedIndex));
            }
        }

        public void OnThemeChanged(object sender, SelectionChangedEventArgs args) {
            if (_selectedIndex.Equals(0))
            {
                ((sender as RadioButtons).XamlRoot.Content as Frame).RequestedTheme = ElementTheme.Light;
            }
            else if(_selectedIndex.Equals(1))
            {
                ((sender as RadioButtons).XamlRoot.Content as Frame).RequestedTheme = ElementTheme.Dark;
            }
            else if (_selectedIndex.Equals(2))
            {
                ((sender as RadioButtons).XamlRoot.Content as Frame).RequestedTheme = ElementTheme.Default;
            }
        }
    }

    public class ThemeType
    {
        private string _name;
        private ThemeValue _themeValue;

        public string Name {
            get {
                return _name;
            }
            set {
                this._name = Name;
            }
        }

        public ThemeValue Value {
            get {
                return _themeValue;
            }
            set {
                this._themeValue = Value;

            }
        }

        public enum ThemeValue { 
            Light,
            Dark,
            HighContrast
        }
    }
}
