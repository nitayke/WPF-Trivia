using System.Windows;
using System.Windows.Controls;
using Newtonsoft.Json;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for Signup.xaml
    /// </summary>
    public partial class Signup : Page
    {
        public Signup()
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

        private void email_GotFocus(object sender, RoutedEventArgs e)
        {
            ((TextBox)sender).Text = "";
        }
        private void Back_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Menu());
        }
        private void Register_Click(object sender, RoutedEventArgs e)
        {
            SignupRequest request = new SignupRequest();
            request.username = username.Text;
            request.password = password.Password;
            request.email = email.Text;
            if (request.username == "" || request.password == "" || request.email == "")
            {
                wrong_data.Text = "Wrong input! Please try again.";
                return;
            }
            string answer = Communicator.Send(JsonConvert.SerializeObject(request), (byte)ReqCode.SIGNUP);
            switch (answer[15] - 48)
            {
                case (char)SignupCode.SIGNUP_USERNAME_EXISTS:
                    wrong_data.Text = "Username exists! Please try again.";
                    break;
                case (char)SignupCode.SIGNUP_SUCCESS:
                    NavigationService.Navigate(new AfterLogging());
                    break;
            }
        }

        private void Page_KeyDown(object sender, System.Windows.Input.KeyEventArgs e)
        {
            if (e.Key == System.Windows.Input.Key.Enter)
            {
                Register_Click(0, new RoutedEventArgs());
            }
        }
    }
}
