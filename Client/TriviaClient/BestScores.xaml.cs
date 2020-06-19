using System.Windows;
using System.Windows.Controls;

namespace TriviaClient
{
    public partial class BestScores : Page
    {
        public BestScores()
        {
            InitializeComponent();
        }
        // back
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new AfterLogging());
        }
    }
}
