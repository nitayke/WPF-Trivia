using Newtonsoft.Json;
using System.Windows;
using System.Windows.Controls;

namespace TriviaClient
{
    public partial class MyScore : Page
    {
        public MyScore()
        {
            InitializeComponent();
            string answer = Communicator.Send(MainWindow.username, (byte)ReqCode.GETUSERSCORE);
            answer = answer.Substring(5, answer.IndexOf('}')-4);
            GetUserScoreResponse response = JsonConvert.DeserializeObject<GetUserScoreResponse>(answer);
            string[] arr = response.statistics.Split(',');
            avg_time.Text = float.Parse(arr[0]) == -1.0 ? "0" : arr[0].Substring(0, 3);
            right_answers.Text = int.Parse(arr[1]) == -1 ? "0" : arr[1];
            wrong_answers.Text = int.Parse(arr[2]) == -1 ? "0" : arr[2];
            games_num.Text = int.Parse(arr[3]) == -1 ? "0" : arr[3];
        }
        private void Back_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new AfterLogging());
        }
    }
}
