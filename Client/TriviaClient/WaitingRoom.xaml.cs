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
        }
        //private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        //{
        //    JoinRoomRequest joinRoomRequest = new JoinRoomRequest
        //    {
        //        roomId = Communicator.roomId
        //    };
        //    string req = JsonConvert.SerializeObject(joinRoomRequest);
        //    Communicator.Send(req, 9);
        //    Communicator.Send("", 3);
        //}

        // close room
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            JoinRoomRequest joinRoomRequest = new JoinRoomRequest
            {
                roomId = Communicator.roomId
            };
            string req = JsonConvert.SerializeObject(joinRoomRequest);
            Communicator.Send(req, 9);
            NavigationService.Navigate(new AfterLogging());
        }
    }
}
