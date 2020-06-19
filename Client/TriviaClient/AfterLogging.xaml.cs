using System.Windows;
using System.Windows.Controls;
using System;

namespace TriviaClient
{
    public partial class AfterLogging : Page
    {
        public AfterLogging()
        {
            InitializeComponent();
        }
        // join room
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new JoinRoom());
        }
        // create room
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new CreateRoom());
        }
        // my status
        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new MyScore());
        }
        // best scores
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new BestScores());
        }
        // sign out
        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            Communicator.Send("", 3);
            MainWindow.isLoggedIn = false;
            NavigationService.Navigate(new Menu());
        }
        // quit
        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            Communicator.Send("", 3);
            Environment.Exit(0);
        }
    }
}
