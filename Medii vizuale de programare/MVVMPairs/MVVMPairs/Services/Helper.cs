using MVVMPairs.Models;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MVVMPairs.Services
{
    class Helper
    {
        public static Cell CurrentCell { get; set; }
        public static Cell PreviousCell { get; set; }
        public static ObservableCollection<ObservableCollection<Cell>> InitGameBoard()
        {
            ObservableCollection<ObservableCollection<Cell>> matrix = new ObservableCollection<ObservableCollection<Cell>>();

            for (int line = 0; line < 8; ++line)
            {
                ObservableCollection<Cell> row = new ObservableCollection<Cell>();
                for (int column = 0; column < 8; ++column)
                {
                    if (line % 2 == column % 2)
                    {
                        row.Add(new Cell(line, column, "/MVVMPairs;component/Resources/wrongEmpty.jpg"));

                    }
                    else
                    {
                        if (line < 3)
                        {
                            row.Add(new Cell(line, column, "/MVVMPairs;component/Resources/red.jpg"));
                        }
                        else if (line < 5)
                        {
                            row.Add(new Cell(line, column, "/MVVMPairs;component/Resources/empty.jpg"));
                        }
                        else
                        {
                            row.Add(new Cell(line, column, "/MVVMPairs;component/Resources/blue.jpg"));
                        }
                    }
                }
                matrix.Add(row);
            }
            return matrix;
        }
    }
}
