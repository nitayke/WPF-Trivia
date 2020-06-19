﻿using System.Windows;
using Newtonsoft.Json;
using System;

namespace TriviaClient
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public static bool isLoggedIn;
        public static bool openedRoom;
        public MainWindow()
        {
            InitializeComponent();
            isLoggedIn = false;
            openedRoom = false;
            while (!Communicator.Connect("127.0.0.1", 2222))
            {
                MessageBoxResult result = MessageBox.Show("Can't connect to server! Please click OK to try again or Cancel to cancel.",
                    "Connection Problem", MessageBoxButton.OKCancel, MessageBoxImage.Warning);
                if (result == MessageBoxResult.Cancel)
                    Environment.Exit(0);
            }
            frame.NavigationService.Navigate(new Menu());
        }
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (openedRoom) // then close the room
            {
                JoinRoomRequest joinRoomRequest = new JoinRoomRequest
                {
                    roomId = Communicator.roomId
                };
                string req = JsonConvert.SerializeObject(joinRoomRequest);
                Communicator.Send(req, 9);
            }
            if (isLoggedIn) // then logout
                Communicator.Send("", 3);
        }
    }
}
