using System;
using System.Windows;
using Newtonsoft.Json;

namespace TriviaClient
{
    public partial class login : Window
    {
        public login()
        {
            InitializeComponent();
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var window = new MainWindow();
            window.Show();
            this.Close();
        }
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            var window = new AfterLogging();
            LoginRequest request = new LoginRequest();
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
                    window.Show();
                    Close();
                    break;
            }
        }
    }
}
