using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Dictionary.Models
{
    public class Word
    {
        private int id;
        private string nume;
        private string descriere;
        private string categorie;
        private string imagine;

        public event PropertyChangedEventHandler PropertyChanged;

        public Word(Word newWord)
        {
            this.Id = newWord.Id;
            this.Nume = newWord.Nume;
            this.Categorie = newWord.Categorie;
            this.Descriere = newWord.Descriere;
            this.Imagine = newWord.Imagine;
        }

        public Word()
        {

        }
        public int Id
        {
            get { return id; }
            set { id = value; OnPropertyChanged("Id"); }
        }
        public string Nume
        {
            get { return nume; }
            set { nume = value; OnPropertyChanged("Nume"); }
        }
        public string Descriere
        {
            get { return descriere; }
            set { descriere = value; OnPropertyChanged("Descriere"); }
        }
        public string Categorie
        {
            get { return categorie; }
            set { categorie = value; OnPropertyChanged("Categorie"); }
        }
        public string Imagine
        {
            get { return imagine; }
            set { imagine = value; OnPropertyChanged("Imagine"); }
        }

        public void Initialize()
        {
            Id = 0;
            Nume = "";
            Descriere = "";
            Categorie = "";
            Imagine = "";
        }

        protected void OnPropertyChanged([CallerMemberName] string name = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }
    }
}
