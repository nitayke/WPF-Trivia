using System;
using System.Windows;

namespace TriviaClient
{
    public partial class BestScores : Window
    {
        public BestScores()
        {
            InitializeComponent();
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Window window = new MainWindow();
            window.Show();
            Close();
        }
    }
}
