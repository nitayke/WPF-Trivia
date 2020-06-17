using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

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
        // join room
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            Window window = new JoinRoom();
            window.Show();
            Close();
        }
        // create room
        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            Window window = new CreateRoom();
            window.Show();
            Close();
        }
        // my status
        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            Window window = new MyScore();
            window.Show();
            Close();
        }
        // best scores
        private void Button_Click_6(object sender, RoutedEventArgs e)
        {
            Window window = new BestScores();
            window.Show();
            Close();
        }
    }
}
