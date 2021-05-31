using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MVVMPairs.Models
{
    
    class Cell : INotifyPropertyChanged
    {
        public Cell(int x, int y, string image)
        {
            this.X = x;
            this.Y = y;
            this.Image = image;
        }

        /* Am optat sa fac proprietati notificabile aici; o alta varianta ar fi fost sa lucrez in Services cu obiecte ViewModel
        care sunt notificabile, dar aceasta optiune o gasesc mai potrivita pentru MVVM */
        //public int X { get; set; }
        //public int Y { get; set; }
        //public string DisplayedImage { get; set; }
        //public string HidenImage { get; set; }

        private int x;
        public int X
        {
            get { return x; }
            set
            {
                x = value;
                NotifyPropertyChanged("X");
            }
        }
        private int y;
        public int Y
        {
            get { return y; }
            set
            {
                y = value;
                NotifyPropertyChanged("Y");
            }
        }
        private string image;
        public string Image
        {
            get { return image; }
            set
            {
                image = value;
                NotifyPropertyChanged("Image");
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        protected void NotifyPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
    }
}
