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

int abs(int l){
    return x > 0 ? x: -x;
}

bool CanMove(Pole board[17][34], int x, int y, int targetX, int targetY){
    if(board[x][y].name=="charge"){
        if(board[targetX][targetY].name=="empty") return 1;

        else return 0;
    }
    if(board[x][y].name=="tower"){
         if(board[targetX][targetY].name=="empty") return 1;

         else return 0;
    }
    if(board[x][y].name=="ghost"){
        if(board[targetX][targetY].name=="empty"){
            return targetY - 
        }

        else return 0;
    }


}
