using System.Windows;
using Newtonsoft.Json;
using System.Windows.Controls;
using System.Threading;
using System;

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
            Thread thread = new Thread(Refresh);
            thread.Start();
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
            gameStarted = true; // to stop checking
        }
        private void Refresh()
        {
            while (!gameStarted)
            {
                Dispatcher.BeginInvoke(new Action(() =>
                {
                    users_panel.Children.Clear();
                }));
                string answer = Communicator.Send("{\"roomId\":" + Communicator.roomId.ToString() + "}", 7);
                answer = answer.Substring(answer.IndexOf('{'), answer.IndexOf('}') - 4);
                // we use that as a GetUsersInRoomResponse
                GetRoomsResponse response = JsonConvert.DeserializeObject<GetRoomsResponse>(answer);
                string[] users = response.rooms.Split(',');
                if (users[0] == "" && users.Length == 1)
                    return;
                foreach (string user in users)
                {
                    Dispatcher.BeginInvoke(new Action(() =>
                    {
                        TextBlock textBlock = new TextBlock
                        {
                            Text = user,
                            FontSize = 20,
                            FontFamily = new System.Windows.Media.FontFamily("Tempus Sans ITC"),
                            Margin = new Thickness(5)
                        };
                        users_panel.Children.Add(textBlock);
                    }));
                }
                Thread.Sleep(3000);
            }
        }
        private void Start_Click(object sender, RoutedEventArgs e)
        {
            gameStarted = true;
        }
    }
}
