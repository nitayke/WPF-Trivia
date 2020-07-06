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
            string answer = Communicator.Send(JsonConvert.SerializeObject(request), (byte)ReqCode.LOGIN);
            switch ((answer[15] + 48)) // status answer
            {
                case (char)LoginCode.LOGIN_USERNAME_NOT_EXISTS:
                    wrong_data.Text = "Username doesn't exists! Please try again.";
                    break;
                case (char)LoginCode.LOGIN_WRONG_PASSWORD:
                    wrong_data.Text = "Wrong password! Please try again.";
                    break;
                case (char)LoginCode.LOGIN_USER_ALREADY_CONNECTED:
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

        private void Page_KeyDown(object sender, System.Windows.Input.KeyEventArgs e)
        {
            if (e.Key == System.Windows.Input.Key.Enter)
            {
                Login_Click(0, new RoutedEventArgs());
            }
        }
    }
}
