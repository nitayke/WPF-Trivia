using System;
using System.Windows;

namespace TriviaClient
{
    public partial class AfterLogging : Window
    {
        public AfterLogging()
        {
            InitializeComponent();
        }
        // join room
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Window window = new JoinRoom();
            window.Show();
            Close();
        }
        // create room
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            Window window = new CreateRoom();
            window.Show();
            Close();
        }
        // my status
        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            Window window = new MyScore();
            window.Show();
            Close();
        }
        // best scores
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            Window window = new BestScores();
            window.Show();
            Close();
        }
        // sign out
        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            Window window = new MainWindow(true);
            Communicator.Send("", 3);
            window.Show();
            Close();
        }
        // quit
        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            Communicator.Send("", 3);
            Close();
        }
    }
}
