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

namespace Dictionary.Views
{
    /// <summary>
    /// Interaction logic for Entertainment.xaml
    /// </summary>
    public partial class Entertainment : UserControl
    {
        private int count = 0;
        public Entertainment()
        {
            InitializeComponent();
        }

        private void Start_Click(object sender, RoutedEventArgs e)
        {
            count++;
            Button start = sender as Button;
            if(count >0)
            {
                start.Visibility = Visibility.Hidden;
            }
        }
        private void Next_Click(object sender, RoutedEventArgs e)
        {
            count++;
            Button start = sender as Button;
            if (count > 5)
            {
                start.Visibility = Visibility.Hidden;
            }
        }
      
    }
}
