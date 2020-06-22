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
        public static bool isAdmin;
        public WaitingRoom()
        {
            InitializeComponent();
            MainWindow.openedRoom = true;
            gameStarted = false;
            connected.Text = roomName + " אתה מחובר לחדר ";
            Thread thread = new Thread(Refresh);
            thread.Start();
            if (isAdmin)
            {
                Button start = new Button
                {
                    Style = FindResource("BTNCORNER") as Style,
                    Width = 200,
                    Height = 30,
                    Content = "Start Game",
                    FontFamily = new System.Windows.Media.FontFamily("Tempus Sans ITC"),
                    FontSize = 20
                };
                start.Click += Start_Click;
                stack_panel.Children.Add(start);
            }
            else
            {
                leave.Content = "Leave Room";
            }
        }
        private void Refresh()
        {
            while (!gameStarted)
            {
                int hasBegun = RefreshUsersList();
                if (!isAdmin)
                {
                    checkGame(hasBegun);
                }
                Thread.Sleep(3000);
            }
        }
        private void Start_Click(object sender, RoutedEventArgs e)
        {
            gameStarted = true;
        }
        private int RefreshUsersList()
        {
            Dispatcher.BeginInvoke(new Action(() =>
            {
                users_panel.Children.Clear();
            }));
            string answer = Communicator.Send("", 13);
            //string answer = Communicator.Send("{\"roomId\":" + Communicator.roomId.ToString() + "}", 7);
            answer = answer.Substring(answer.IndexOf('{'), answer.IndexOf('}') - 4);
            // we use that as a GetUsersInRoomResponse
            GetRoomStateResponse response = JsonConvert.DeserializeObject<GetRoomStateResponse>(answer);
            string[] users = response.players.Split(',');
            if (users[0] == "" && users.Length == 1)
                return -1;
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
            return response.hasGameBegun;
        }
        private void checkGame(int hasBegun)
        {
            if (hasBegun == 1)
            {
                Start_Click(0, new RoutedEventArgs());
            }
            else if (hasBegun == -1)
            {
                Communicator.Send("", 14);
                Dispatcher.BeginInvoke(new Action(() =>
                {
                    NavigationService.Navigate(new AfterLogging());
                }));
                MainWindow.openedRoom = false;
                gameStarted = true;
            }
        }
        private void CloseRoom_Click(object sender, RoutedEventArgs e)
        {
            JoinRoomRequest joinRoomRequest = new JoinRoomRequest
            {
                roomId = Communicator.roomId
            };
            string req = JsonConvert.SerializeObject(joinRoomRequest);
            int code = isAdmin ? 9 : 12;
            Communicator.Send(req, (byte)code);
            NavigationService.Navigate(new AfterLogging());
            MainWindow.openedRoom = false;
            gameStarted = true; // to stop checking
        }
    }
}
