using System;
using System.Windows;
using System.Windows.Controls;
using Newtonsoft.Json;

namespace TriviaClient
{
    public partial class CreateRoom : Page
    {
        public CreateRoom()
        {
            InitializeComponent();
        }
        // back
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new AfterLogging());
        }
        // create room
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            try
            {
                if (roomname.Text == "" || int.Parse(num_questions.Text) == 0 || int.Parse(time.Text) == 0 ||
                int.Parse(num_players.Text) < 2)
                    error.Text = "Wrong input! Please try again.";
            }
            catch
            {
                error.Text = "Wrong input! Please try again.";
                return;
            }
            CreateRoomRequest request = new CreateRoomRequest
            {
                answerTimeout = int.Parse(time.Text),
                roomName = roomname.Text,
                questionCount = int.Parse(num_questions.Text),
                maxUsers = int.Parse(num_players.Text)
            };
            string ans = Communicator.Send(JsonConvert.SerializeObject(request), 6);
            CreateRoomResponse response;
            string subStr = ans.Substring(4, 23);
            response = JsonConvert.DeserializeObject<CreateRoomResponse>(subStr);
            Communicator.roomId = response.roomId;
            NavigationService.Navigate(new WaitingRoom());
        }
        private void GotFocusTextBox(object sender, RoutedEventArgs e)
        {
            ((TextBox)sender).Text = "";
        }
    }
}
