using Newtonsoft.Json;
using System.Windows;
using System.Windows.Controls;
using System.Text;

namespace TriviaClient
{
    public partial class MyScore : Page
    {
        public MyScore()
        {
            InitializeComponent();
            string answer = Communicator.Send(MainWindow.username, 10);
            GetUserScoreResponse response = JsonConvert.DeserializeObject<GetUserScoreResponse>(answer);
            string[] arr = response.statistics.Split(',', ' ');
            games_num.Text = arr[0];
            right_answers.Text = arr[1];
            wrong_answers.Text = arr[2];
            avg_time.Text = arr[3];
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
