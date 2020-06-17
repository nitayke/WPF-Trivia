using Newtonsoft.Json;
using System.Windows;

namespace TriviaClient
{
    public partial class signup : Window
    {
        public signup()
        {
            InitializeComponent();
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var window = new MainWindow();
            window.Show();
            Close();
        }
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            var window = new AfterLogging();
            SignupRequest request = new SignupRequest();
            request.username = username.Text;
            request.password = password.Password;
            request.email = email.Text;
            string answer = Communicator.Send(JsonConvert.SerializeObject(request), 1);
            switch (answer[15])
            {
                case '1':
                    wrong_data.Text = "Username exists! Please try again.";
                    break;
                default:
                    window.Show();
                    Close();
                    break;
            }
        }
    }
}