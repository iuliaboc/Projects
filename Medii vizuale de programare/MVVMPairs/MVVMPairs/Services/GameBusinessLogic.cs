using MVVMPairs.Models;
using MVVMPairs.ViewModels;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

namespace MVVMPairs.Services
{
    class GameBusinessLogic
    {
        int isEmpty = 0;
        int currentPlayer = 0;
        public ObservableCollection<ObservableCollection<Cell>> cells;
        public GameBusinessLogic(ObservableCollection<ObservableCollection<Cell>> cells)
        {
            this.cells = cells;
        }

        private bool TurnCard(Cell cell)
        {
            if (cell.Image == "/MVVMPairs;component/Resources/red.jpg")
            {
                Helper.PreviousCell = cell;
                cells.ElementAt(cell.X).ElementAt(cell.Y).Image = "/MVVMPairs;component/Resources/redClicked.jpg";
                return true;
            }
            else if (cell.Image == "/MVVMPairs;component/Resources/blue.jpg")
            {
                Helper.PreviousCell = cell;
                cells.ElementAt(cell.X).ElementAt(cell.Y).Image = "/MVVMPairs;component/Resources/blueClicked.jpg";
                return true;
            }
            else if (cell.Image == "/MVVMPairs;component/Resources/blueKing.jpg")
            {
                Helper.PreviousCell = cell;
                cells.ElementAt(cell.X).ElementAt(cell.Y).Image = "/MVVMPairs;component/Resources/blueKingClicked.jpg";
                return true;
            }
            else if (cell.Image == "/MVVMPairs;component/Resources/redKing.jpg")
            {
                Helper.PreviousCell = cell;
                cells.ElementAt(cell.X).ElementAt(cell.Y).Image = "/MVVMPairs;component/Resources/redKingClicked.jpg";
                return true;
            }

            return false;
        }

        public void SwitchPieces(Cell currentCell, Cell middle, Cell previousCell)
        {
            string aux = previousCell.Image;
            if(aux == "/MVVMPairs;component/Resources/blueClicked.jpg")
            {
                if (currentCell.X == 0)
                {
                    aux = "/MVVMPairs;component/Resources/blueKing.jpg";
                }
                else
                {
                    aux = "/MVVMPairs;component/Resources/blue.jpg";
                }
            } 
            else if(aux == "/MVVMPairs;component/Resources/blueKingClicked.jpg")
            {
                aux = "/MVVMPairs;component/Resources/blueKing.jpg";
            }
            else if(aux == "/MVVMPairs;component/Resources/redClicked.jpg")
            {
                if (currentCell.X == 7)
                {
                    aux = "/MVVMPairs;component/Resources/redKing.jpg";
                }
                else
                {
                    aux = "/MVVMPairs;component/Resources/red.jpg";
                }
            }
            else if (aux == "/MVVMPairs;component/Resources/redKingClicked.jpg")
            {
                aux = "/MVVMPairs;component/Resources/redKing.jpg";
            }
            cells.ElementAt(previousCell.X).ElementAt(previousCell.Y).Image = currentCell.Image;
            cells.ElementAt(currentCell.X).ElementAt(currentCell.Y).Image = aux;
            if(middle != null)
            {
                cells.ElementAt(middle.X).ElementAt(middle.Y).Image = "/MVVMPairs;component/Resources/empty.jpg";
            }

        }
        public bool PlacePiece(Cell currentCell, Cell previousCell)
        {
            bool ok = false;
            if (previousCell.Image == "/MVVMPairs;component/Resources/redClicked.jpg")
            {
                if (previousCell.X + 1 == currentCell.X && (previousCell.Y - 1 == currentCell.Y || previousCell.Y + 1 == currentCell.Y))
                {
                    SwitchPieces(currentCell, null, previousCell);
                    ok = true;
                }
            }
            else if (previousCell.Image == "/MVVMPairs;component/Resources/blueClicked.jpg")
            {
                if (previousCell.X - 1 == currentCell.X && (previousCell.Y - 1 == currentCell.Y || previousCell.Y + 1 == currentCell.Y))
                {
                    SwitchPieces(currentCell, null, previousCell);
                    ok = true;
                }
            }
            else if (previousCell.Image == "/MVVMPairs;component/Resources/redKingClicked.jpg" || previousCell.Image == "/MVVMPairs;component/Resources/blueKingClicked.jpg")
            {
                if ((previousCell.X + 1 == currentCell.X || previousCell.X - 1 == currentCell.X) && (previousCell.Y - 1 == currentCell.Y || previousCell.Y + 1 == currentCell.Y))
                {
                    SwitchPieces(currentCell, null, previousCell);
                    ok = true;
                }
            }
            return ok;
        }

        public bool SimpleJump(Cell currentCell, Cell previousCell)
        {
            Cell middleCell;
            bool ok = false;

            if(previousCell.X == currentCell.X + 2)
            {
                if(currentCell.Y == previousCell.Y -2)
                {
                    if (previousCell.Image == "/MVVMPairs;component/Resources/blueKingClicked.jpg" || previousCell.Image == "/MVVMPairs;component/Resources/blueClicked.jpg")
                    {
                        middleCell = cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y + 1);
                        if (middleCell.Image == "/MVVMPairs;component/Resources/red.jpg" || middleCell.Image == "/MVVMPairs;component/Resources/redKing.jpg")
                        {
                            SwitchPieces(currentCell, middleCell, previousCell);
                            ok = true;
                        }
                    }
                    else if(previousCell.Image == "/MVVMPairs;component/Resources/redKingClicked.jpg")
                    {
                        middleCell = cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y + 1);
                        if (middleCell.Image == "/MVVMPairs;component/Resources/blue.jpg" || middleCell.Image == "/MVVMPairs;component/Resources/blueKing.jpg")
                        {
                            SwitchPieces(currentCell, middleCell, previousCell);
                            ok = true;
                        }
                    }
                }
                else if(currentCell.Y == previousCell.Y + 2)
                {
                    if (previousCell.Image == "/MVVMPairs;component/Resources/blueKingClicked.jpg" || previousCell.Image == "/MVVMPairs;component/Resources/blueClicked.jpg")
                    {
                        middleCell = cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y - 1);
                        if (middleCell.Image == "/MVVMPairs;component/Resources/red.jpg" || middleCell.Image == "/MVVMPairs;component/Resources/redKing.jpg")
                        {
                            SwitchPieces(currentCell, middleCell, previousCell);
                            ok = true;
                        }
                    }
                    else if (previousCell.Image == "/MVVMPairs;component/Resources/redKingClicked.jpg")
                    {
                        middleCell = cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y - 1);
                        if (middleCell.Image == "/MVVMPairs;component/Resources/blue.jpg" || middleCell.Image == "/MVVMPairs;component/Resources/blueKing.jpg")
                        {
                            SwitchPieces(currentCell, middleCell, previousCell);
                            ok = true;
                        }
                    }
                }
            }
            else if(previousCell.X == currentCell.X - 2)
            {
                if (currentCell.Y == previousCell.Y - 2)
                {
                    if (previousCell.Image == "/MVVMPairs;component/Resources/redKingClicked.jpg" || previousCell.Image == "/MVVMPairs;component/Resources/redClicked.jpg")
                    {
                        middleCell = cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y + 1);
                        if (middleCell.Image == "/MVVMPairs;component/Resources/blue.jpg" || middleCell.Image == "/MVVMPairs;component/Resources/blueKing.jpg")
                        {
                            SwitchPieces(currentCell, middleCell, previousCell);
                            ok = true;
                        }
                    }
                    else if (previousCell.Image == "/MVVMPairs;component/Resources/blueKingClicked.jpg")
                    {
                        middleCell = cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y + 1);
                        if (middleCell.Image == "/MVVMPairs;component/Resources/red.jpg" || middleCell.Image == "/MVVMPairs;component/Resources/redKing.jpg")
                        {
                            SwitchPieces(currentCell, middleCell, previousCell);
                            ok = true;
                        }
                    }
                }
                else if (currentCell.Y == previousCell.Y + 2)
                {
                    if (previousCell.Image == "/MVVMPairs;component/Resources/redKingClicked.jpg" || previousCell.Image == "/MVVMPairs;component/Resources/redClicked.jpg")
                    {
                        middleCell = cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y - 1);
                        if (middleCell.Image == "/MVVMPairs;component/Resources/blue.jpg" || middleCell.Image == "/MVVMPairs;component/Resources/blueKing.jpg")
                        {
                            SwitchPieces(currentCell, middleCell, previousCell);
                            ok = true;
                        }
                    }
                    else if (previousCell.Image == "/MVVMPairs;component/Resources/blueKingClicked.jpg")
                    {
                        middleCell = cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y - 1);
                        if (middleCell.Image == "/MVVMPairs;component/Resources/red.jpg" || middleCell.Image == "/MVVMPairs;component/Resources/redKing.jpg")
                        {
                            SwitchPieces(currentCell, middleCell, previousCell);
                            ok = true;
                        }
                    }
                }
            }
            if (!ok)
            {
                if (previousCell.Image == "/MVVMPairs;component/Resources/redClicked.jpg")
                {
                    cells.ElementAt(previousCell.X).ElementAt(previousCell.Y).Image = "/MVVMPairs;component/Resources/red.jpg";
                }
                else if (previousCell.Image == "/MVVMPairs;component/Resources/redKingClicked.jpg")
                {
                    cells.ElementAt(previousCell.X).ElementAt(previousCell.Y).Image = "/MVVMPairs;component/Resources/redKing.jpg";
                }
                else if (previousCell.Image == "/MVVMPairs;component/Resources/blueClicked.jpg")
                {
                    cells.ElementAt(previousCell.X).ElementAt(previousCell.Y).Image = "/MVVMPairs;component/Resources/blue.jpg";
                }
                else if (previousCell.Image == "/MVVMPairs;component/Resources/blueKingClicked.jpg")
                {
                    cells.ElementAt(previousCell.X).ElementAt(previousCell.Y).Image = "/MVVMPairs;component/Resources/blueKing.jpg";
                }
            }
            return ok;
        }

        public Cell FindNext(Cell currentCell)
        {
            if (currentCell.Image == "/MVVMPairs;component/Resources/red.jpg" || currentCell.Image == "/MVVMPairs;component/Resources/redKing.jpg")
            {
                if (currentCell.X + 2 < 8)
                {
                    if (currentCell.Y - 2 >= 0)
                    {
                        if ((cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y - 1).Image == "/MVVMPairs;component/Resources/blue.jpg"
                        || cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y - 1).Image == "/MVVMPairs;component/Resources/blueKing.jpg")
                        && cells.ElementAt(currentCell.X + 2).ElementAt(currentCell.Y - 2).Image == "/MVVMPairs;component/Resources/empty.jpg")
                        {
                            if(currentCell.Image == "/MVVMPairs;component/Resources/red.jpg")
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/redClicked.jpg";
                            }
                            else
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/redKingClicked.jpg";
                            }
                            return cells.ElementAt(currentCell.X + 2).ElementAt(currentCell.Y - 2);
                        }
                    }
                    if (currentCell.Y + 2 < 8)
                    {
                        if ((cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y + 1).Image == "/MVVMPairs;component/Resources/blue.jpg"
                        || cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y + 1).Image == "/MVVMPairs;component/Resources/blueKing.jpg")
                        && cells.ElementAt(currentCell.X + 2).ElementAt(currentCell.Y + 2).Image == "/MVVMPairs;component/Resources/empty.jpg")
                        {
                            if (currentCell.Image == "/MVVMPairs;component/Resources/red.jpg")
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/redClicked.jpg";
                            }
                            else
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/redKingClicked.jpg";
                            }
                            return cells.ElementAt(currentCell.X + 2).ElementAt(currentCell.Y + 2);
                        }
                    }
                }
                if (currentCell.Image == "/MVVMPairs;component/Resources/redKing.jpg")
                {
                    if (currentCell.X - 2 >= 0)
                    {
                        if (currentCell.Y - 2 >= 0)
                        {
                            if ((cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y - 1).Image == "/MVVMPairs;component/Resources/blue.jpg"
                            || cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y - 1).Image == "/MVVMPairs;component/Resources/blueKing.jpg")
                            && cells.ElementAt(currentCell.X - 2).ElementAt(currentCell.Y - 2).Image == "/MVVMPairs;component/Resources/empty.jpg")
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/redKingClicked.jpg";
                                return cells.ElementAt(currentCell.X - 2).ElementAt(currentCell.Y - 2);
                            }
                        }
                        if (currentCell.Y + 2 < 8)
                        {
                            if ((cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y + 1).Image == "/MVVMPairs;component/Resources/blue.jpg"
                            || cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y + 1).Image == "/MVVMPairs;component/Resources/blueKing.jpg")
                            && cells.ElementAt(currentCell.X - 2).ElementAt(currentCell.Y + 2).Image == "/MVVMPairs;component/Resources/empty.jpg")
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/redKingClicked.jpg";
                                return cells.ElementAt(currentCell.X - 2).ElementAt(currentCell.Y + 2);
                            }
                        }
                    }
                }
            }
            else if (currentCell.Image == "/MVVMPairs;component/Resources/blue.jpg" || currentCell.Image == "/MVVMPairs;component/Resources/blueKing.jpg")
            {
                if (currentCell.X - 2 >= 0)
                {
                    if (currentCell.Y - 2 >= 0)
                    {
                        if ((cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y - 1).Image == "/MVVMPairs;component/Resources/red.jpg"
                        || cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y - 1).Image == "/MVVMPairs;component/Resources/redKing.jpg")
                        && cells.ElementAt(currentCell.X - 2).ElementAt(currentCell.Y - 2).Image == "/MVVMPairs;component/Resources/empty.jpg")
                        {
                            if (currentCell.Image == "/MVVMPairs;component/Resources/blue.jpg")
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/blueClicked.jpg";
                            }
                            else
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/blueKingClicked.jpg";
                            }
                            return cells.ElementAt(currentCell.X - 2).ElementAt(currentCell.Y - 2);
                        }
                    }
                    if (currentCell.Y + 2 < 8)
                    {
                        if ((cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y + 1).Image == "/MVVMPairs;component/Resources/red.jpg"
                        || cells.ElementAt(currentCell.X - 1).ElementAt(currentCell.Y + 1).Image == "/MVVMPairs;component/Resources/redKing.jpg")
                        && cells.ElementAt(currentCell.X - 2).ElementAt(currentCell.Y + 2).Image == "/MVVMPairs;component/Resources/empty.jpg")
                        {
                            if (currentCell.Image == "/MVVMPairs;component/Resources/blue.jpg")
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/blueClicked.jpg";
                            }
                            else
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/blueKingClicked.jpg";
                            }
                            return cells.ElementAt(currentCell.X - 2).ElementAt(currentCell.Y + 2);
                        }
                    }
                }
                if(currentCell.Image == "/MVVMPairs;component/Resources/blueKing.jpg")
                {
                    if (currentCell.X + 2 < 8)
                    {
                        if (currentCell.Y - 2 >= 0)
                        {
                            if ((cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y - 1).Image == "/MVVMPairs;component/Resources/red.jpg"
                            || cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y - 1).Image == "/MVVMPairs;component/Resources/redKing.jpg")
                            && cells.ElementAt(currentCell.X + 2).ElementAt(currentCell.Y - 2).Image == "/MVVMPairs;component/Resources/empty.jpg")
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/blueKingClicked.jpg";
                                return cells.ElementAt(currentCell.X + 2).ElementAt(currentCell.Y - 2);
                            }
                        }
                        if (currentCell.Y + 2 < 8)
                        {
                            if ((cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y + 1).Image == "/MVVMPairs;component/Resources/red.jpg"
                            || cells.ElementAt(currentCell.X + 1).ElementAt(currentCell.Y + 1).Image == "/MVVMPairs;component/Resources/redKing.jpg")
                            && cells.ElementAt(currentCell.X + 2).ElementAt(currentCell.Y + 2).Image == "/MVVMPairs;component/Resources/empty.jpg")
                            {
                                currentCell.Image = "/MVVMPairs;component/Resources/blueKingClicked.jpg";
                                return cells.ElementAt(currentCell.X + 2).ElementAt(currentCell.Y + 2);
                            }
                        }
                    }
                }
            }
            return null;
        }
        public bool MultipleJump(Cell currentCell, Cell previousCell)
        {
            bool continua = true;
            bool ok = false;
            while(continua)
            {
                if(SimpleJump(currentCell, previousCell))
                {
                    ok = true;
                    previousCell = currentCell;
                    currentCell = FindNext(previousCell);
                    if(currentCell == null)
                    {
                        continua = false;
                    }
                }
                else
                {
                    continua = false;
                }
            }
            return ok;
        }

        public string Win()
        {
            bool red = false;
            bool blue = false;
            for(int line = 0; line < 8; ++line)
            {
                for(int column = 0; column < 8; ++column)
                {
                    if(cells.ElementAt(line).ElementAt(column).Image == "/MVVMPairs;component/Resources/blue.jpg")
                    {
                        blue = true;
                    }
                    if (cells.ElementAt(line).ElementAt(column).Image == "/MVVMPairs;component/Resources/red.jpg")
                    {
                        red = true;
                    }
                    if(blue == true && red == true)
                    {
                        return "";
                    }
                }
            }
            if(red == false)
            {
                return "Blue";
            } else
            {
                return "Red";
            }
        }
        public bool Move(Cell currentCell)
        {
            bool ok = false;
            Helper.CurrentCell = currentCell;
            if(PlacePiece(currentCell,Helper.PreviousCell))
            {
                ok = true;
                Helper.PreviousCell = null;
            }
            else if(MultipleJump(currentCell,Helper.PreviousCell))
            {
                ok = true;
                Helper.PreviousCell = null;
            }

            string check = Win();
            if(check != "")
            {
                _ = MessageBox.Show(check + " player won! Congratulation!");
                System.Diagnostics.Process.Start(Application.ResourceAssembly.Location);
                Application.Current.Shutdown();
            }
            return ok;
        }

        public void ClickAction(Cell obj)
        {
            if (isEmpty % 2 == 0)
            {
                if (currentPlayer % 2 == 0 && (obj.Image == "/MVVMPairs;component/Resources/red.jpg" || obj.Image == "/MVVMPairs;component/Resources/redKing.jpg"))
                {
                    isEmpty++;
                    currentPlayer++;
                    TurnCard(obj);
                }
                if (currentPlayer % 2 != 0 && (obj.Image == "/MVVMPairs;component/Resources/blue.jpg" || obj.Image == "/MVVMPairs;component/Resources/blueKing.jpg"))
                {
                    isEmpty++;
                    currentPlayer++;
                    TurnCard(obj);
                }
            }
            else
            {
                if (obj.Image == "/MVVMPairs;component/Resources/empty.jpg")
                {
                    if (Move(obj))
                    {
                        isEmpty++;
                    }
                }
                else
                {
                    isEmpty--;
                    currentPlayer--;
                    if(Helper.PreviousCell.Image == "/MVVMPairs;component/Resources/redClicked.jpg")
                    {
                        cells.ElementAt(Helper.PreviousCell.X).ElementAt(Helper.PreviousCell.Y).Image = "/MVVMPairs;component/Resources/red.jpg";
                    } 
                    else if(Helper.PreviousCell.Image == "/MVVMPairs;component/Resources/redKingClicked.jpg")
                    {
                        cells.ElementAt(Helper.PreviousCell.X).ElementAt(Helper.PreviousCell.Y).Image = "/MVVMPairs;component/Resources/redKing.jpg";
                    }
                    else if (Helper.PreviousCell.Image == "/MVVMPairs;component/Resources/blueClicked.jpg")
                    {
                        cells.ElementAt(Helper.PreviousCell.X).ElementAt(Helper.PreviousCell.Y).Image = "/MVVMPairs;component/Resources/blue.jpg";
                    }
                    else if (Helper.PreviousCell.Image == "/MVVMPairs;component/Resources/blueKingClicked.jpg")
                    {
                        cells.ElementAt(Helper.PreviousCell.X).ElementAt(Helper.PreviousCell.Y).Image = "/MVVMPairs;component/Resources/blueKing.jpg";
                    }
                    Helper.PreviousCell = null;
                }
            }
        }
    }
}
