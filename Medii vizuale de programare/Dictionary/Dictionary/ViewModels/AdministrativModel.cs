using Dictionary.Models;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;
using System.Windows.Controls;
using System.Windows;
using System.Windows.Input;
using System.Windows.Data;
using Dictionary.ViewModels.Commands;
using Microsoft.Win32;

namespace Dictionary.ViewModels
{
    public class AdministrativModel
    {
        public Word curent = new Word();//{ Id = -1, Nume = "Adauga/Modifica/Sterge", Descriere = "Adauga/Modifica/Sterge", Categorie = "Adauga/Modifica/Sterge", Imagine = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\Images\\No-image-available.jpg" };
        static string path = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\dictionar.json";
        public static string json = File.ReadAllText(path);
        private static ObservableCollection<Word> items = JsonConvert.DeserializeObject<ObservableCollection<Word>>(json);

        public event PropertyChangedEventHandler PropertyChanged;

        public Comenzi UpdateCommand { get; private set; }
        public Comenzi AddCommand { get; private set; }
        public Comenzi DeleteCommand { get; private set; }



        public AdministrativModel()
        {
            UpdateCommand = new Comenzi(update);
            AddCommand = new Comenzi(add);
            DeleteCommand = new Comenzi(delete);
        }
        public ObservableCollection<Word> Date
        {
            get { return items;  }
            set { items = value; OnPropertyChanged("Date");}
        }
        public Word Curent
        {
            get { return curent; }
            set { curent = value; OnPropertyChanged("Curent"); }
        }
        private void OnPropertyChanged(string property)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(property));
            }
        }

        public void add()
        {
            bool found = false;
            foreach (Word cuvant in items)
            {
                if (cuvant.Id == curent.Id)
                {
                    found = true;
                    break;
                }
            }
            if (!items.Contains(curent) && found == false)
            {
                if (curent.Imagine == null)
                {
                    curent.Imagine = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\Images\\No-image-available.jpg";
                }
                items.Add(new Word(curent));
                Curent.Initialize();
                String encoded = JsonConvert.SerializeObject(items);
                System.IO.File.WriteAllText(path, encoded);
            }
        }
        public void update()
        {
            foreach (Word cuvant in items)
            {
                if (cuvant.Id == curent.Id)
                {
                    cuvant.Nume = curent.Nume;
                    cuvant.Categorie = curent.Categorie;
                    cuvant.Descriere = curent.Descriere;
                    if(curent.Imagine == null)
                    {
                        cuvant.Imagine = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\Images\\No-image-available.jpg";
                    }
                    else
                    {
                        cuvant.Imagine = curent.Imagine;
                    }
                    Curent.Initialize();
                    String encoded = JsonConvert.SerializeObject(items);
                    System.IO.File.WriteAllText(path, encoded);
                    break;
                }
            }
        }

        public void delete()
        {
            foreach (Word cuvant in items)
            {
                if (cuvant.Id == curent.Id)
                {
                    items.Remove(items.Where(i => i.Id == curent.Id).Single());
                    Curent.Initialize();
                    String encoded = JsonConvert.SerializeObject(items);
                    System.IO.File.WriteAllText(path, encoded);
                    break;
                }
            }
        }
        ICommand _loadImageCommand;
        public ICommand LoadImageCommand
        {
            get
            {
                if (_loadImageCommand == null)
                {
                    _loadImageCommand = new RelayCommand(param => LoadImage());
                }
                return _loadImageCommand;
            }
        }

        private void LoadImage()
        {
            OpenFileDialog open = new OpenFileDialog();
            open.DefaultExt = (".png");
            open.Filter = "Pictures (.jpg;.gif;*.png)|*.jpg;*.gif;*.png";

            if (open.ShowDialog() == true)
                curent.Imagine = open.FileName;
        }

    }
}
