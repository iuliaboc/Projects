using MVVMPairs.Models;
using MVVMPairs.Services;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MVVMPairs.ViewModels
{
    class GameVM
    {
        private GameBusinessLogic bl;
        public GameVM()
        {
            ObservableCollection<ObservableCollection<Cell>> board = Helper.InitGameBoard();
            bl = new GameBusinessLogic(board);
            GameBoard = CellBoardToCellVMBoard(bl.cells);
        }

        private ObservableCollection<ObservableCollection<CellVM>> CellBoardToCellVMBoard(ObservableCollection<ObservableCollection<Cell>> board)
        {
            ObservableCollection<ObservableCollection<CellVM>> result = new ObservableCollection<ObservableCollection<CellVM>>();
            for (int i = 0; i < board.Count; i++)
            {
                ObservableCollection<CellVM> line = new ObservableCollection<CellVM>();
                for (int j = 0; j < board[i].Count; j++)
                {
                    Cell c = board[i][j];
                    CellVM cellVM = new CellVM(c.X, c.Y,c.Image, bl);
                    line.Add(cellVM);
                }
                result.Add(line);
            }
            return result;
        }

        public ObservableCollection<ObservableCollection<CellVM>> GameBoard { get; set; }
    }
}
