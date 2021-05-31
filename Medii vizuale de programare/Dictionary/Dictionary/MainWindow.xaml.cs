using Dictionary.Models;
using Dictionary.ViewModels;
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

namespace Dictionary
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

        private void Administrativ_Click(object sender, RoutedEventArgs e)
        {
            DataContext = new AdministrativModel();
        }

        private void Cautare_Click(object sender, RoutedEventArgs e)
        {
            DataContext = new CautareModel();
        }

        private void Entertainment_Click(object sender, RoutedEventArgs e)
        {
            DataContext = new EntertainmentModel();
        }

    }
}
