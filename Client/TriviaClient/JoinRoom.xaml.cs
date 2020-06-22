using System.Windows;
using System.Windows.Controls;
using Newtonsoft.Json;
using System.Windows.Media;
using System.Threading;
using System;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for JoinRoom.xaml
    /// </summary>
    public partial class JoinRoom : Page
    {
        private bool hasEntered;
        public JoinRoom()
        {
            InitializeComponent();
            hasEntered = false;
            Thread thread = new Thread(Refresh);
            thread.Start();
        }
        private void Back_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new AfterLogging());
            hasEntered = true; // to stop checking
        }
        private void Refresh()
        {
            while (!hasEntered)
            {
                Dispatcher.BeginInvoke(new Action(() =>
                {
                    room_list_panel.Children.Clear();
                }));
                string answer = Communicator.Send("", 4);
                answer = answer.Substring(answer.IndexOf('{'), answer.IndexOf('}') - 4);
                GetRoomsResponse response = JsonConvert.DeserializeObject<GetRoomsResponse>(answer);
                string[] rooms = response.rooms.Split(',');
                if (rooms[0] == "" && rooms.Length == 1)
                    return;
                Dispatcher.BeginInvoke(new Action(() =>
                {
                    foreach (string room in rooms)
                    {
                        Button button = new Button
                        {
                            Content = room.Substring(0, room.IndexOf(':')),
                            FontSize = 20,
                            FontFamily = new FontFamily("Tempus Sans ITC"),
                            Background = Brushes.Blue,
                            Margin = new Thickness(10),
                            Cursor = System.Windows.Input.Cursors.Hand
                        };
                        button.Click += Room_Choose_Click;
                        Communicator.roomId = int.Parse(room.Substring(room.IndexOf(':') + 1));
                        room_list_panel.Children.Add(button);
                    }
                }));
                Thread.Sleep(3000);
            }
        }
        private void Room_Choose_Click(object sender, RoutedEventArgs e)
        {
            hasEntered = true;
            WaitingRoom.roomName = ((Button)sender).Content.ToString();
            WaitingRoom.isAdmin = false;
            string msg = "{\"roomId\":" + Communicator.roomId.ToString() + "}";
            Communicator.Send(msg, 5);
            NavigationService.Navigate(new WaitingRoom());
        }
    }
}