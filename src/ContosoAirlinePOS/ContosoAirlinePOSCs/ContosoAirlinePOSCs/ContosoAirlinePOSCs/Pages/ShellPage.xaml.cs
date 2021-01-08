using System;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Navigation;
using ContosoAirlinePOSCs.ViewModels;
using ContosoAirlinePOSCs.IoC;

namespace ContosoAirlinePOSCs.Pages
{
    /// <summary>
    /// Navigation Shell Page
    /// </summary>
    public sealed partial class ShellPage : Page
    {
        public ShellPage()
        {
            this.InitializeComponent();
        }

        public ShellViewModel ViewModel { get; set; }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);
            ViewModel = DIHelper.Resolve<ShellViewModel>();

            MainContentFrame.Navigated += MainContentFrame_Navigated;
            MenuNav.BackRequested += MenuNav_BackRequested;
            LogoutOption.Click += LogoutOption_Click;
        }

        private void LogoutOption_Click(object sender, Microsoft.UI.Xaml.RoutedEventArgs e)
        {
            var parentFrame = this.Parent as Frame;
            if (parentFrame != null && parentFrame.CanGoBack)
                parentFrame.GoBack();
        }

        private void MenuNav_BackRequested(NavigationView sender, NavigationViewBackRequestedEventArgs args)
        {
            if (MainContentFrame.CanGoBack)
                MainContentFrame.GoBack();
        }

        private void MainContentFrame_Navigated(object sender, NavigationEventArgs e)
        {
            MenuNav.IsBackEnabled = MainContentFrame.CanGoBack;
        }

        private void NavMenu_ItemInvoked(NavigationView sender, NavigationViewItemInvokedEventArgs args)
        {
            FrameNavigationOptions navOptions = new FrameNavigationOptions();
            navOptions.TransitionInfoOverride = args.RecommendedNavigationTransitionInfo;
            Type pageType = typeof(SettingsPage);
            if (args.IsSettingsInvoked)
            {
                MainContentFrame.NavigateToType(pageType, null, navOptions);
            }
            else
            {
                var menuItem = args.InvokedItemContainer.DataContext as MenuItem;
                ViewModel.SelectedPageChangedCommand.Execute(menuItem);
            }
        }
    }
}
