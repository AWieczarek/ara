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



bool CanMove(int player, std::string name, int player2, std::string name2, Pole board[17][34]){
    if(name=="charge"){
        if(name2=="notexist") return 0;
    }
    if(name=="tower"){

    }


}
