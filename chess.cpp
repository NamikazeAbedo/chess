#include <iostream>
#include <string>


using namespace std;


//    the board in the termanal
    string board[8][8];
    // to calculate the plaee in board
    int row_from=0 , col_from=0 ;
    int row_to=0 , col_to=0 ;
    int take_from=0, take_to=0;
      string paice ="\0";



// Define pieces as strings
const string Rook_D = " ♖";
const string Rook_W = " ♜";

const string King_D = " ♔";
const string King_W = " ♚";


const string Queen_D = " ♕";
const string Queen_W = " ♛";

const string Knight_D = " ♘";
const string Knight_W = " ♞";

const string Pawn_D = " ♙";
const string Pawn_W = " ♟";

const string Bishop_D = " ♗";
const string Bishop_W = " ♝";

const string EMPTY_D = " ■";
const string EMPTY_W = " □";



void init_board();
void board_game(); 
void paice_movement(int *turns); 
bool legal_move(int turns);
bool turns_ofgame(int *turns);
bool check_rook_moves();
bool check_bishop_moves(); 
bool check_king_moves();
bool check_knight_moves();  
bool on_board(int row , int col);
bool check_pawn_moves(); 
bool is_opponent_piece(int row, int col) ;
bool Special_moves();
bool castling();
bool en_passant();
bool promotion();


//the object: Terminal Chess


//     Features to include:

    /*      // Standard chess board display in terminal ✅
//time day 1 note 1 > it easy i feel can do it just in 30 min that 
//progress  also i have plan  this time this week i wiil make fire 
// in termenal >0<
*/

   /*      // All pieces with movement rules  ✅

//time day 2 - note 1> fuck you fuck me fuck programming it 
// hared i bearly make the logic for the movemt i weast
// about a 4 h in this the problm is i couldnt use
//  the e9,d6 a1 in to move  my piese o i mange to use 
// %/ with the anothere boeard  and display it in the boead ^&^
// and that make me cunfused and waste so much time 


//time day 3 - note 2 >this shit is hared i did no progress
// all the day i watch  other code in githup an no want do it 
// like me they use gfc lib r game lib i and if i want to add this e3,e5..
// i need math and...and eljaber i bad at it ;-;


//time day 4 - note 3> thx chinlike me they use gfc lib r game
//  liba for deepseek it guided me in this bs code and make unerstaned
//  that im stupid i didnt say that im notusing ai in this one 
//   but we makeprogress i can say that i made about 60 % of this code
//  and that cool  but i need to reead maybe tomoroe 
*/ 

//         Special moves (castling, en passant, promotion)

// time day 5 and 6 - note 1> i spend the day reading my code bc i forget 
// the most of it 

//         Check/checkmate detection

//         Move input using algebraic notation (e.g., e2e4)


//     Features to skip (for now):

//         Move history/undo

//         AI opponent

//         Save/Load

//         Move history/undo



int main() {
    int turns = 1;
    init_board();
    
    while (true) {
        paice_movement(&turns);
        
    }
    return 0;
}
// the hared worker but the most lazyest function and in the same time bone back of my work it like me in so many way but much better 
void init_board() {
    // Fill board with empty squares (alternating colors)
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = EMPTY_D;
            } else {
                board[i][j] = EMPTY_W;
            }
        }
    }
    // Place all pieces
board[0][0] = Rook_D;
board[0][1] = Knight_D;
board[0][2] = Bishop_D;
board[0][3] = King_D;
board[0][4] = Queen_D;
board[0][5] = Bishop_D;
board[0][6] = Knight_D;
board[0][7] = Rook_D;
    
board[1][0] = Pawn_D;
board[1][1] = Pawn_D;
board[1][2] = Pawn_D;
board[1][3] = Pawn_D;
board[1][4] = Pawn_D;
board[1][5] = Pawn_D;
board[1][6] = Pawn_D;
board[1][7] = Pawn_D;
    
board[7][0] = Rook_W;
board[7][1] = Knight_W;
board[7][2] = Bishop_W;
board[7][3] = King_W;
board[7][4] = Queen_W;
board[7][5] = Bishop_W;
board[7][6] = Knight_W;
board[7][7] = Rook_W;
    
// Put a white pawn close to promotion (row 1, col 4)
board[1][4] = Pawn_W;  // Overwrites the black pawn at row 1, col 4

// And keep some black pawns on row 1
board[1][0] = Pawn_D;
board[1][1] = Pawn_D;
board[1][2] = Pawn_D;
board[1][3] = Pawn_D;
// board[1][4] is now Pawn_W
board[1][5] = Pawn_D;
board[1][6] = Pawn_D;
board[1][7] = Pawn_D;
    // // Place all pieces
    // board[0][0] = Rook_D;
    // board[0][1] = Knight_D;
    // board[0][2] = Bishop_D;
    // board[0][3] = King_D;
    // board[0][4] = Queen_D;
    // board[0][5] = Bishop_D;
    // board[0][6] = Knight_D;
    // board[0][7] = Rook_D;
    
    // board[1][0] = Pawn_D;
    // board[1][1] = Pawn_D;
    // board[1][2] = Pawn_D;
    // board[1][3] = Pawn_D;
    // board[1][4] = Pawn_D;
    // board[1][5] = Pawn_D;
    // board[1][6] = Pawn_D;
    // board[1][7] = Pawn_D;
    
    // board[7][0] = Rook_W;
    // board[7][1] = Knight_W;
    // board[7][2] = Bishop_W;
    // board[7][3] = King_W;
    // board[7][4] = Queen_W;
    // board[7][5] = Bishop_W;
    // board[7][6] = Knight_W;
    // board[7][7] = Rook_W;
    
    // board[6][0] = Pawn_W;
    // board[6][1] = Pawn_W;
    // board[6][2] = Pawn_W;
    // board[6][3] = Pawn_W;
    // board[6][4] = Pawn_W;
    // board[6][5] = Pawn_W;
    // board[6][6] = Pawn_W;
    // board[6][7] = Pawn_W;
}
// the game rule board,turns and othernstuff like the reprithing for the boared and checker

void emrty_squer(){
     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if((board[i][j]==  Pawn_W   || board[i][j]==Pawn_D) || 
            (board[i][j]==  Rook_W   || board[i][j]==Rook_D)    ||
            (board[i][j]==  Knight_W || board[i][j]==Knight_D)  ||
            (board[i][j]==  King_W   || board[i][j]==King_D)    ||
            (board[i][j]==  Queen_W  || board[i][j]==Queen_D)   ||
            (board[i][j]== Bishop_W  || board[i][j]==Bishop_D)) continue;
            else if((i + j) % 2 == 0) {
                board[i][j] = EMPTY_D;
            } else {
                board[i][j] = EMPTY_W;
            }
        }
    }
    
}
void paice_movement(int *turns) {
                                  board_game();

                    // Display the board map (1-64)
                    int board_mtx[8][8] = {0};
                    int board_mtx_num = 1;
                    
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            board_mtx[i][j] = board_mtx_num;
                            if (board_mtx_num < 10) {
                                cout << board_mtx_num << "  ";
                            } else {
                                cout << board_mtx_num << " ";
                            }
                            board_mtx_num++;
                        }
                        cout << endl;
                    }
                    
                    // Get user input
                    cout << "Enter the address of the piece you want to move: ";
                    cin >> take_from;
                    cout << "Enter the address of the piece to move to: ";
                    cin >> take_to;
                    
                    // Convert to board positions
                    row_from = (take_from - 1) / 8;
                    col_from = (take_from - 1) % 8;
                    row_to = (take_to - 1) / 8;
                    col_to = (take_to - 1) % 8;
                    
                    // Set the piece being moved
                    paice = board[row_from][col_from];
                    
                    // Check if the move is legal
                    if (legal_move(*turns)) {
                        
                        // Move the piece
                        string place_swaper_pc = board[row_from][col_from];
                        string place_swaper_emty = board[row_to][col_to];
                        
                        board[row_from][col_from] = place_swaper_emty;
                        board[row_to][col_to] = place_swaper_pc;
                        
                        if  (Special_moves())  emrty_squer();
                        emrty_squer();
                         
                        
                        // Increment turn counter only after successful move
                        (*turns)++;
                        cout << "Move successful!" << endl;

                    } else {
                       
                        cout << "Illegal move!" << endl;
                    }

}
void board_game() {
    
   
    cout << "   a  b  c  d  e  f  g  h" << endl;
    for (int i = 0; i < 8; i++) {
        cout << (8 - i) << " ";  // Chess uses 8-1 for rows
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << (8 - i) << endl;  // Right side row number
    }
    cout << "   a  b  c  d  e  f  g  h\n" << endl;

} 
bool legal_move(int turns){

                        if (turns_ofgame(&turns)){

                                if (paice == " ♖" || paice == " ♜"){
                                
                                    return  check_rook_moves();
                                        
                            
                                }
                               else if (paice == " ♗" || paice == " ♝") {
                                //    if (Special_moves()){
                                    return check_bishop_moves();
                                    //  }
                                }
                              else if (paice == " ♕"|| paice == " ♛") {
                                    return (check_bishop_moves()||  check_rook_moves());

                                }else if (paice == " ♙" || paice == " ♟") {
                                            return check_pawn_moves(); 
                                        }
                                else if (paice == " ♔" || paice == " ♚") {
                                        // if (Special_moves()){
                                            return check_king_moves(); 
                                        // }
                                        }
                                else if (paice == " ♘" || paice == " ♞") {
                                        return check_knight_moves();
                                    }
                                else {
                                    cout << "Piece type not yet supported!" << endl;
                                    return false;
                                }
                        }
                return false; 
}
bool is_opponent_piece(int row, int col) {
    string current = board[row_from][col_from];
    string target = board[row][col];
    
    // Check if current is white
    bool currentIsWhite = (current == Pawn_W || current == Rook_W ||
                           current == Knight_W || current == Bishop_W ||
                           current == Queen_W || current == King_W);
    
    // Check if current is black
    bool currentIsBlack = (current == Pawn_D || current == Rook_D ||
                           current == Knight_D || current == Bishop_D ||
                           current == Queen_D || current == King_D);
    
    // Check if target is white
    bool targetIsWhite = (target == Pawn_W || target == Rook_W ||
                          target == Knight_W || target == Bishop_W ||
                          target == Queen_W || target == King_W);
    
    // Check if target is black
    bool targetIsBlack = (target == Pawn_D || target == Rook_D ||
                          target == Knight_D || target == Bishop_D ||
                          target == Queen_D || target == King_D);
    
    // White captures black, Black captures white
    if (currentIsWhite && targetIsBlack) return true;
    if (currentIsBlack && targetIsWhite) return true;
    
    return false;
}
bool on_board(int row, int col) {
    if (row >= 0 && row <= 7 && col >= 0 && col <= 7) {
        return true;  // Inside the board
    }
    return false;     // Outside the board
}
bool turns_ofgame(int *turns) {
    bool whiteTurn = (*turns % 2 == 1);
    string piece = board[row_from][col_from];
    
    // Check if it's a black piece (Pawn_D, Rook_D, Knight_D, Bishop_D, Queen_D, King_D)
    if (whiteTurn) {
        if (piece == Pawn_D || piece == Rook_D || piece == Knight_D ||
            piece == Bishop_D || piece == Queen_D || piece == King_D) {
            cout << "It's White's turn! You can't move black pieces stupid black player." << endl;
            return false;
        }
    } else {
        // Check if it's a white piece (Pawn_W, Rook_W, Knight_W, Bishop_W, Queen_W, King_W)
        if (piece == Pawn_W || piece == Rook_W || piece == Knight_W ||
            piece == Bishop_W || piece == Queen_W || piece == King_W) {
            cout << "It's Black's turn! You can't move white pieces stupid white player." << endl;
            return false;
        }
    }
    return true;
}

// the the peaice movment

bool check_pawn_moves() {
    // Determine direction: White moves up (-1), Black moves down (+1)
    int direction = (paice == Pawn_W) ? -1 : 1;
    int start_row = (paice == Pawn_W) ? 6 : 1;
    
    // 1. Move 1 square forward
    if (row_to == row_from + direction && col_to == col_from) {
        if (board[row_to][col_to] == EMPTY_D || 
            board[row_to][col_to] == EMPTY_W) {
            return true;
        }
    }
    
    // 2. Move 2 squares forward (only from starting position)
    if (row_from == start_row && row_to == row_from + 2 * direction && col_to == col_from) {
        int middle_row = row_from + direction;
        // Check both squares are empty
        if ((board[middle_row][col_from] == EMPTY_D || 
             board[middle_row][col_from] == EMPTY_W) &&
            (board[row_to][col_to] == EMPTY_D || 
             board[row_to][col_to] == EMPTY_W)) {
            return true;
        }
    }
    
    // 3. Capture diagonally (left and right)
    if (row_to == row_from + direction && (col_to == col_from - 1 || col_to == col_from + 1)) {
        // Must be an opponent's piece (not empty)
        if (board[row_to][col_to] != EMPTY_D && 
            board[row_to][col_to] != EMPTY_W) {
            // Check if it's opponent's piece
            if (is_opponent_piece(row_to, col_to)) {
                return true;
            }
        }
    }
    
    return false;
}
bool check_rook_moves(){

    int rook_drecti[4][2] =  {{-1,0}, // Up,
                       {1,0},       {0,-1},// Left, Right
                             {0,1}}; // Down,
    
    for (int derc = 0; derc < 4; derc++) {
        int new_row = row_from + rook_drecti[derc][0];
        int new_col = col_from + rook_drecti[derc][1];
        
        //  if the new position is on the board
        while (on_board(new_row, new_col)) {
            // Found the destination!
            if (new_row == row_to && new_col == col_to) {
                return true;
            }
            // blocked by a piece!
            if (board[new_row][new_col] != EMPTY_D && 
                board[new_row][new_col] != EMPTY_W) {
                break;  // Stop moving in this direction
            }
            // mv one more step in the same direction
            new_row += rook_drecti[derc][0];
            new_col += rook_drecti[derc][1];
        }
    }
    return false; 

}
bool check_bishop_moves() {
    int bishop_drecti[4][2] = {{-1,-1},       {-1,1},
                                              
                               {1,-1},         {1,1}}; 
    
    for (int derc = 0; derc < 4; derc++) {
        int new_row = row_from + bishop_drecti[derc][0];
        int new_col = col_from + bishop_drecti[derc][1];
        
        while (on_board(new_row, new_col)) {
            if (new_row == row_to && new_col == col_to) {
                return true;
            }
            if (board[new_row][new_col] != EMPTY_D && 
                board[new_row][new_col] != EMPTY_W) {
                break;
            }
            new_row += bishop_drecti[derc][0];
            new_col += bishop_drecti[derc][1];
        }
    }
    return false;
}
bool check_king_moves() {
    int king_drecti[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},         {0,1},
        {1,-1},  {1,0}, {1,1}
    };
    
    for (int derc = 0; derc < 8; derc++) {
        int new_row = row_from + king_drecti[derc][0];
        int new_col = col_from + king_drecti[derc][1];
        
        if (!on_board(new_row, new_col)) {
            continue;
        }
        
        if (new_row == row_to && new_col == col_to) {
            // Empty square
            if (board[new_row][new_col] == EMPTY_D || 
                board[new_row][new_col] == EMPTY_W) {
                return true;
            }
            // Capture opponent
            if (is_opponent_piece(new_row, new_col)) {
                return true;
            }
            return false;
        }
    }
    return false;
}
bool check_knight_moves() {
    int knight_drecti[8][2] = {
        {-2,-1},           {-2,1},
  {-1,-2},                       {-1,2},

  {1,-2},                       {1,2},
        {2,-1},              {2,1}
    };
    
    for (int derc = 0; derc < 8; derc++) {
        int new_row = row_from + knight_drecti[derc][0];
        int new_col = col_from + knight_drecti[derc][1];
        
        // ✅ Check if this position is on the board
        if (!on_board(new_row, new_col)) {
            continue;
        }
        
        // ✅ Check if this is the destination
        if (new_row == row_to && new_col == col_to) {
            // ✅ Knight can move to empty square
            if (board[new_row][new_col] == EMPTY_D || 
                board[new_row][new_col] == EMPTY_W) {
                return true;
            }
            // ✅ Knight can capture opponent's piece
                if (is_opponent_piece(new_row, new_col)) {
                    return true;
                }
            // ❌ Can't move to own piece
            return false;
        }
    }
    return false;
}
// check_qween_moves it just bishop and rook

bool Special_moves(){

         if(promotion()){
          return true;
         } 
}
bool castling(){}
bool en_passant(){}
bool promotion(){

    int promotion_row= (paice == Pawn_W) ? 0 : (paice == Pawn_D)  ? 7 : -1 ;
    int choose;
  
   
        if (row_to == promotion_row ){
         
            cout << "enter the number of the paice that you want..."<< endl;
           
            if (paice == Pawn_W ){
                cout << "1) Rook   ♜. "<< endl;
                cout << "2) Queen  ♛."<< endl;
                cout << "3) Bishop ♝."<< endl;
                cout << "4) Knight ♞."<< endl;
           
           }
            else if (paice == Pawn_D ){
                cout << "1) Rook   ♖. "<< endl;
                cout << "2) Queen  ♕."<< endl;
                cout << "3) Bishop ♗."<< endl;
                cout << "4) Knight ♘."<< endl;
            }
            cout << "what the promotion that you want";
               cin >>choose;
             switch (choose)
             {
             case 1:
                if (paice== Pawn_W){
                   board[row_to][col_to]=Rook_W;
                }else board[row_to][col_to]=Rook_D;
                
                break;

             case 2:
                 if (paice== Pawn_W){
                   board[row_to][col_to]=Queen_W;
                }else board[row_to][col_to]=Queen_D;
                break;

             case 3:
                 if (paice== Pawn_W){
                   board[row_to][col_to]=Bishop_W;
                }else board[row_to][col_to]=Bishop_D;
                break;

             case 4:
                 if (paice== Pawn_W){
                   board[row_to][col_to]=Knight_W;
                }else board[row_to][col_to]=Knight_D;
                break;

             
             default:
                break;

               
             }
          return true;
      }
   
    
    
return false;
}
