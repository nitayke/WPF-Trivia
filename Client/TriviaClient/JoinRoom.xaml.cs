using System.Windows;
using System.Windows.Controls;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for JoinRoom.xaml
    /// </summary>
    public partial class JoinRoom : Page
    {
        // TODO: MainWindow.openedRoom = true;
        public JoinRoom()
        {
            InitializeComponent();
        }
        // back
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new AfterLogging());
        }
    }
}
