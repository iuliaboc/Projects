using Dictionary.Models;
using Dictionary.ViewModels.Commands;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace Dictionary.ViewModels
{
    public class EntertainmentModel
    {
        public static int count = 0;
        public static int raspunsuriCorecte = 0;
        public static string raspuns;
        public static string verifica= "";
        public static string background = "";
        public static Word curent;
        public Visibility sfarsitJoc;
        static string path = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\dictionar.json";
        public static string json = File.ReadAllText(path);
        private static ObservableCollection<Word> items = JsonConvert.DeserializeObject<ObservableCollection<Word>>(json);
        public List<Word> Cuvinte = new List<Word>();

        public Comenzi StartCommand { get; private set; }
        public Comenzi NextCommand { get; private set; }
        public Comenzi FinishCommand { get; private set; }

        public EntertainmentModel()
        {
            sfarsitJoc = Visibility.Hidden;
            StartCommand = new Comenzi(start);
            NextCommand = new Comenzi(next);
            FinishCommand = new Comenzi(finish);
        }
        public string Raspuns
        {
            get { return raspuns; }
            set { raspuns = value; OnPropertyChanged("Raspuns"); }
        }
        public Word Curent
        {
            get { return curent; }
            set { curent = value; OnPropertyChanged("Curent"); }
        }
        public string Verifica
        {
            get { return verifica; }
            set { verifica = value; OnPropertyChanged("Verifica"); }
        }
        public string Background
        {
            get { return background; }
            set { background = value; OnPropertyChanged("BackGround"); }
        }


        public void start()
        {
            var rand = new Random();

            for(int index=0;index<5;index++)
            {
                int pozitie = rand.Next(items.Count);
                int decizie = rand.Next(2);
                Word cuvant = items[pozitie];
                if(decizie==0)
                {
                    cuvant.Imagine = "";
                }
                else
                {
                    cuvant.Descriere = "";
                }
                Cuvinte.Add(cuvant);
            }

            curent = new Word(Cuvinte[count++]);
            Curent = curent;
        }

        public void next()
        {
            if(raspuns == curent.Nume)
            {
                verifica = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\Images\\corect.png";
                raspunsuriCorecte++;
            }
            else
            {
                verifica = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\Images\\gresit.png";
            }
            if(count<5)
            {
                curent = new Word(Cuvinte[count++]);
            }
            else
            {
                sfarsitJoc = Visibility.Visible;
            }
        }

        public void finish()
        {
            curent = new Word();
            if(raspunsuriCorecte>2)
            {
                verifica = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\Images\\win.png";
            }
            else
            {
                verifica = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\Images\\lose.jpg";
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void OnPropertyChanged(string property)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(property));
            }
        }

    }
}
