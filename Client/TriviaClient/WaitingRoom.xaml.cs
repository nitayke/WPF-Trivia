using System.Windows;
using Newtonsoft.Json;
using System.Windows.Controls;
using System.Threading;

namespace TriviaClient
{
    public partial class WaitingRoom : Page
    {
        public static string roomName;
        private bool gameStarted;
        public WaitingRoom()
        {
            InitializeComponent();
            MainWindow.openedRoom = true;
            gameStarted = false;
            connected.Text = roomName + " אתה מחובר לחדר ";
            ThreadStart thread = new ThreadStart(Refresh);
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
            MainWindow.openedRoom = false;
        }
        private void Refresh()
        {
            users_panel.Children.Clear();
            string answer = Communicator.Send("{\"roomId\":" + Communicator.roomId.ToString() + "}", 7);
            answer = answer.Substring(answer.IndexOf('{'), answer.IndexOf('}') - 4);
            // we use that as a GetUsersInRoomResponse
            GetRoomsResponse response = JsonConvert.DeserializeObject<GetRoomsResponse>(answer);
            string[] users = response.rooms.Split(',');
            if (users[0] == "" && users.Length == 1)
                return;
            foreach (string user in users)
            {
                TextBlock textBlock = new TextBlock();
                textBlock.Text = user;
                textBlock.FontSize = 20;
                textBlock.FontFamily = new System.Windows.Media.FontFamily("Tempus Sans ITC");
                textBlock.Margin = new Thickness(5);
                users_panel.Children.Add(textBlock);
            }
        }
        private void Start_Click(object sender, RoutedEventArgs e)
        {
            // it's for the next version
        }
    }
}
