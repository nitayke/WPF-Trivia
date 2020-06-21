﻿using System.Windows;
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
            string answer = Communicator.Send(JsonConvert.SerializeObject(request), 1);
            switch (answer[15])
            {
                case '1':
                    wrong_data.Text = "Username exists! Please try again.";
                    break;
                default:
                    NavigationService.Navigate(new AfterLogging());
                    break;
            }
        }
    }
}
