using System.Windows;
using System.Windows.Controls;

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
    }
}
