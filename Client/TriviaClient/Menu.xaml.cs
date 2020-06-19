using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for Menu.xaml
    /// </summary>
    public partial class Menu : Page
    {
        public Menu()
        {
            InitializeComponent();
        }
        private void Login_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Login());
        }
        private void Signup_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Signup());
        }
        private void Quit_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }
    }
}
