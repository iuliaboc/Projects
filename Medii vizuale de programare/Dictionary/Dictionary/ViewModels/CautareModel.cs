using Dictionary.Models;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dictionary.ViewModels
{
    
    public class CautareModel
    {
        static string path = "E:\\Cursuri\\Anul 2\\Semestrul 2\\MVP\\Dictionary\\Dictionary\\dictionar.json";
        public static string json = File.ReadAllText(path);
        private static ObservableCollection<Word> items = JsonConvert.DeserializeObject<ObservableCollection<Word>>(json);
        public event PropertyChangedEventHandler PropertyChanged;
        public static string categorie;
        public static string cautare;
        public static List<Word> cuvintePeCategorii = new List<Word>();
        public static ObservableCollection<Word> cuvintePeCautari = new ObservableCollection<Word>();
        public static Word cuvantAles;


        public Word CuvantAles
        {
            get { return cuvantAles; }
            set { cuvantAles = value; OnPropertyChanged("CuvantAles"); }
        }

        public ObservableCollection<Word> CuvintePeCautari
        {
            get { return cuvintePeCautari; }
            set { cuvintePeCautari = value; OnPropertyChanged("CuvintePeCautari"); }
        }

        public string Cautare
        {
            get { return cautare; }
            set
            {
                cautare = value;
                OnPropertyChanged("Cautare");
                cuvintePeCautari.Clear();
                foreach(Word cuvant in cuvintePeCategorii)
                {
                    bool seamana = true;
                    for(int index = 0; index<cautare.Length; index++)
                    {
                        if(cautare.Length <= cuvant.Nume.Length)
                        {
                            if(cautare[index] != cuvant.Nume[index])
                            {
                                seamana = false;
                            }
                        }
                        else
                        {
                            seamana = false;
                        }
                    }
                    if(seamana)
                    {
                        cuvintePeCautari.Add(cuvant);
                    }
                }
            }
        }

        public string Categorie
        {
            get { return categorie; }
            set { categorie = value; OnPropertyChanged(Categorie);
                cuvintePeCategorii.Clear();
                    foreach(Word cuvant in items)
                    {
                        if(cuvant.Categorie==categorie)
                        {
                            cuvintePeCategorii.Add(cuvant);
                        }
                    }

                }
        }
        public List<string> Categorii
        {
            get
            {
                List<string> i = new List<string>();
                foreach(Word cuvant in items)
                {
                    i.Add(cuvant.Categorie);
                }
                return i.Distinct().ToList();
            }
        }

        private void OnPropertyChanged(string property)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(property));
            }
        }
    }
}
