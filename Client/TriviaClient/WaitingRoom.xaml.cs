using System.Windows;
using Newtonsoft.Json;

namespace TriviaClient
{
    public partial class WaitingRoom : Window
    {
        public WaitingRoom()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Window window = new AfterLogging();
            JoinRoomRequest joinRoomRequest = new JoinRoomRequest();
            joinRoomRequest.roomId = Communicator.roomId;
            string req = JsonConvert.SerializeObject(joinRoomRequest);
            Communicator.Send(req, 9);
            window.Show();
            Close();
        }
    }
}
