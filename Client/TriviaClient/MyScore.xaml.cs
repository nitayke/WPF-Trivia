using System;
using System.Windows;
using System.Windows.Controls;

namespace TriviaClient
{
    public partial class MyScore : Page
    {
        public MyScore()
        {
            InitializeComponent();

            //games_num;
            //right_answers;
            //wrong_answers;
            //avg_time;
        }
        // back
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new AfterLogging());
        }
    }
}
