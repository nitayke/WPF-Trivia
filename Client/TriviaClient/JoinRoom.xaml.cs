using System.Windows;
using System.Windows.Controls;
using Newtonsoft.Json;
using System.Windows.Media;
using System.Windows.Shapes;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for JoinRoom.xaml
    /// </summary>
    public partial class JoinRoom : Page
    {
        public JoinRoom()
        {
            InitializeComponent();
            Button_Click_1("", new RoutedEventArgs());
        }
        // back
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new AfterLogging());
        }
        // refresh
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            room_list_panel.Children.Clear();
            string answer = Communicator.Send("", 4);
            answer = answer.Substring(answer.IndexOf('{'), answer.IndexOf('}') - 4);
            GetRoomsResponse response = JsonConvert.DeserializeObject<GetRoomsResponse>(answer);
            string[] rooms = response.rooms.Split(',');
            if (rooms[0] == "" && rooms.Length == 1)
                return;
            foreach (string room in rooms)
            {
                Button button = new Button();
                button.Content = room.Substring(0, room.IndexOf(':'));
                Communicator.roomId = int.Parse(room.Substring(room.IndexOf(':')+1));
                button.FontSize = 20;
                button.FontFamily = new FontFamily("Tempus Sans ITC");
                button.Background = Brushes.Blue;
                button.Margin = new Thickness(10);
                button.Cursor = System.Windows.Input.Cursors.Hand;
                button.Click += Room_Choose_Click;
                room_list_panel.Children.Add(button);
            }
        }
        private void Room_Choose_Click(object sender, RoutedEventArgs e)
        {
            string msg = "{\"roomId\":" + Communicator.roomId.ToString() + "}";
            Communicator.Send(msg, 5);
            NavigationService.Navigate(new WaitingRoom());
        }
    }
}