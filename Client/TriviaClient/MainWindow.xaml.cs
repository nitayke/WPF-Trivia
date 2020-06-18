using System;
using System.Windows;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            while (!Communicator.Connect("127.0.0.1", 2222))
            {
                MessageBoxResult result = MessageBox.Show("Can't connect to server! click OK to try again or Cancel.", "Error", MessageBoxButton.OKCancel, MessageBoxImage.Warning);
                if (result == MessageBoxResult.Cancel)
                    Environment.Exit(0);
            }
        }
        public MainWindow(bool firstTime)
        {
            InitializeComponent();
        }
        // exit
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }
        // login
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            Window window = new login();
            window.Show();
            Close();
        }
        // signup
        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            Window window = new signup();
            window.Show();
            Close();
        }
    }
}
