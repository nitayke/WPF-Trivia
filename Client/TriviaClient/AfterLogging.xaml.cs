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
        private void JoinRoom_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new JoinRoom());
        }
        private void CreateRoom_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new CreateRoom());
        }
        private void MyStatus_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new MyScore());
        }
        private void BestScores_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new BestScores());
        }
        private void Signout_Click(object sender, RoutedEventArgs e)
        {
            Communicator.Send("", 3);
            MainWindow.isLoggedIn = false;
            NavigationService.Navigate(new Menu());
        }
        private void Quit_Click(object sender, RoutedEventArgs e)
        {
            Communicator.Send("", 3);
            Environment.Exit(0);
        }
    }
}
