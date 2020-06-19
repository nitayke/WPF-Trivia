using System.Windows;
using System.Windows.Controls;
using Newtonsoft.Json;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for Login.xaml
    /// </summary>
    public partial class Login : Page
    {
        public Login()
        {
            InitializeComponent();
        }

        private void username_GotFocus(object sender, RoutedEventArgs e)
        {
            ((TextBox)sender).Text = "";
        }

        private void password_GotFocus(object sender, RoutedEventArgs e)
        {
            ((PasswordBox)sender).Password = "";
        }

        private void Login_Click(object sender, RoutedEventArgs e)
        {
            LoginRequest request = new LoginRequest();
            MainWindow.username = username.Text;
            request.username = username.Text;
            request.password = password.Password;
            string answer = Communicator.Send(JsonConvert.SerializeObject(request), 0);
            switch (answer[15])
            {
                case '1':
                    wrong_data.Text = "Username doesn't exists! Please try again.";
                    break;
                case '2':
                    wrong_data.Text = "Wrong password! Please try again.";
                    break;
                case '3':
                    wrong_data.Text = "User already connected! Please try again.";
                    break;
                default:
                    MainWindow.isLoggedIn = true;
                    NavigationService.Navigate(new AfterLogging());
                    break;
            }
        }

        private void Back_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Menu());
        }
    }
}
