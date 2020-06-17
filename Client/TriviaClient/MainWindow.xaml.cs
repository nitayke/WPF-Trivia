﻿using System;
using System.Windows;
using System.Net;
using System.Net.Sockets;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        // exit
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }
        // login
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            Window window = new login();
            window.Show();
            Close();
        }
        // signup
        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            Window window = new signup();
            window.Show();
            Close();
        }
        // join room
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            Window window = new JoinRoom();
            window.Show();
            Close();
        }
        // create room
        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            Window window = new CreateRoom();
            window.Show();
            Close();
        }
        // my status
        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            Window window = new MyScore();
            window.Show();
            Close();
        }
        // best scores
        private void Button_Click_6(object sender, RoutedEventArgs e)
        {
            Window window = new BestScores();
            window.Show();
            Close();
        }
    }
}
