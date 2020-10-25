using System.Windows;
using System.Windows.Controls;
using Newtonsoft.Json;

namespace TriviaClient
{
    public partial class BestScores : Page
    {
        public BestScores()
        {
            InitializeComponent();
            string answer = Communicator.Send("", (byte)ReqCode.GETSTATISTICS);
            answer = answer.Substring(5, answer.IndexOf('}') - 4);
            GetUserScoreResponse response = JsonConvert.DeserializeObject<GetUserScoreResponse>(answer);
            string[] arr = response.statistics.Split(',');
            if (arr.Length > 1 && int.Parse(arr[1]) >= 0)
                user_1.Text = arr[0] + "'s score is " + arr[1];
            else
            {
                user_1.FontSize = 18;
                user_1.Text = "No best scores! you should start playing!";
            }
            if (arr.Length > 3 && int.Parse(arr[3]) >= 0)
                user_2.Text = arr[2] + "'s score is " + arr[3];
            if (arr.Length > 5 && int.Parse(arr[5]) >= 0)
                user_3.Text = arr[4] + "'s score is " + arr[5];
            if (arr.Length > 7 && int.Parse(arr[7]) >= 0)
                user_4.Text = arr[6] + "'s score is " + arr[7];
            if (arr.Length > 9 && int.Parse(arr[9]) >= 0)
                user_5.Text = arr[8] + "'s score is " + arr[9];
        }
        private void Back_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new AfterLogging());
        }
    }
}
