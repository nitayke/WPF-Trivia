﻿using System;
using System.Windows;

namespace TriviaClient
{
    public partial class MyScore : Window
    {
        public MyScore()
        {
            InitializeComponent();
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Window window = new AfterLogging();
            window.Show();
            Close();
        }
    }
}
