using System.Windows;
using Newtonsoft.Json;
using System.Windows.Controls;

namespace TriviaClient
{
    public partial class WaitingRoom : Page
    {
        public WaitingRoom()
        {
            InitializeComponent();
            MainWindow.openedRoom = true;
        }
        private void CloseRoom_Click(object sender, RoutedEventArgs e)
        {
            JoinRoomRequest joinRoomRequest = new JoinRoomRequest
            {
                roomId = Communicator.roomId
            };
            string req = JsonConvert.SerializeObject(joinRoomRequest);
            Communicator.Send(req, 9);
            NavigationService.Navigate(new AfterLogging());
        }
        // not finished
        private void Refresh_Click(object sender, RoutedEventArgs e)
        {
            string answer = Communicator.Send("", 7);
            answer = answer.Substring(answer.IndexOf('{'), answer.IndexOf('}') - 4);
            // we use that as a GetUsersInRoomResponse
            GetRoomsResponse response = JsonConvert.DeserializeObject<GetRoomsResponse>(answer);
            string[] rooms = response.rooms.Split(',');
            foreach (string room in rooms)
            {
                TextBlock textBlock = new TextBlock();
                textBlock.Text = room;
                textBlock.FontSize = 20;
                textBlock.FontFamily = new System.Windows.Media.FontFamily("Tempus Sans ITC");
                users_panel.Children.Add(textBlock);
            }
        }
        private void Start_Click(object sender, RoutedEventArgs e)
        {

        }
    }
}
