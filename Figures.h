/*
    Pionek          - pawn
    Duch            - ghost
    Kawaleria       - cav
    Kr�l            - king
    Wie�a           - tower
    Szar�a          - charge
    Zagadka         - mystery

    pole przepa�ci  - notexist
    polec puste     - empty
*/
int abs(int x)
{
    return x > 0 ? x: -x;
}



bool CanMove(Pole board[17][34], int x, int y, int targetX, int targetY)
{
    if(board[x][y].name=="Pawn")
    {
        if(board[targetX][targetY].name=="empty")
            {
                if(targetX == x && targetY == y + 1 ||
                   targetX == x + 1 && targetY == y + 1 ||
                   targetX == x - 1 && targetY == y + 1) return 1;
                else return 0;
            }
        else return 0;
    }
}
