#include <iostream>
#include <string.h>
#include <time.h>
#include <ctime>


using namespace std;

char board[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};

   char player1='X' ,
        player2='O';


   

//  struct player_data
//  {
//     string player1;
//     string player2;
    
   
//  };
void board_game(); 
void playing();
void menu();
void rules();
char win_check();
void the_playing_type();
void rangame();
 void change_theplayers();


int main (){

    char replay;
                cout << "____Tic-Tac-Toe(XO)Game_______________"  << endl;

        cout << "do you want to go to the manu[Y/N]..." ;
        cin >> replay;

     if (replay == 'Y' || replay == 'y' ){
                        menu();

     }
     else if (replay == 'N' || replay == 'n' ) {
                cout << "why then all this miss just to say no...(sorry the program dont handel rejaction will)" << endl;
                cout << "Beyy" << endl;
                            exit(0);

     }else cout << "fuck you";


                cout << "\n_________________________________________________"  << endl;

    
    return 0;

}
void rules(){
    
     char replay;
    cout << "_______________the rules_______________"  << endl;

    cout << "the player 1 is automatcly sing to X" << endl;
    cout << "the player 2 is automatcly sing to O\n" << endl;

            board_game();

    cout << "1 - you must to ame on take 3 squares in the board"<< "/n"
         <<   " the winner will be decllared automatcly the same apply on the loser." << endl;
    cout << "2 - the draw will be consider after no square of the 9 squares is laft" << endl;
    
     cout << "do you want to change it [Y/N]..." ;
     cin >> replay ;
     if (replay == 'Y' || replay == 'y' ) change_theplayers();
     else if (replay == 'N' || replay == 'n' ) menu();
     

}
void menu(){
    int choose;

          cout << "_______________the menu_______________"  << endl;
          cout << " 1 - the rules."<< endl;
          cout << " 2 - the playing type."<< endl;
          cout << " 3 - the wins menu."<< endl;
          cout << " 4 - Exit."<< endl;
          cout << "enter one of the number above...";
          cin  >> choose ;

          switch (choose)
          {
          case 1: rules(); break;
          case 2:
            the_playing_type();
             break;

          case 3: 
            // thewin lose draw menu();
              break;
          case 4:
               exit(0);
              break;
          
          default:
            break;
          }

  
}
void board_game(){
    cout << "\n  ╔═══╤═══╤═══╗" << endl;
    cout << "  ║ " << board[0][0] << " │ " << board[0][1] << " │ " << board[0][2] << " ║" << endl;
    cout << "  ╟───┼───┼───╢" << endl;
    cout << "  ║ " << board[1][0] << " │ " << board[1][1] << " │ " << board[1][2] << " ║" << endl;
    cout << "  ╟───┼───┼───╢" << endl;
    cout << "  ║ " << board[2][0] << " │ " << board[2][1] << " │ " << board[2][2] << " ║" << endl;
    cout << "  ╚═══╧═══╧═══╝" << endl;
     
}
void playing_turns(){


    int pos, row, col;
    char current_player= player1; 
    int playerchacker=9;
    for(int i = 0 ; i < 9 ; i++ ) {
    board_game();
    if (playerchacker % 2==0)
    cout << "the player 1 " << current_player << " must choose between the numbers [1-9]:" ;
    else
    cout << "the player 2 " << current_player << " must choose between the numbers [1-9]:" ;
        cin >> pos ;
        row = (pos - 1 )/ 3;
        col = (pos - 1 )% 3;

        if (pos < 0 || pos > 9  ){
            
            cout << "Invalid position! Choose just from [1-9]";
             i--;
                     playerchacker++;

             continue;

        }
                if ( board[row][col]=='O' || board[row][col]=='x' ){
            
            cout << "that sqeare is full need to choose another.";
             i--;
                     playerchacker++;

             continue;

        }
                 board[row][col] = current_player;

        if(current_player== player1) current_player= player2;
        
         else current_player= player1;


   char winner = win_check();

        if (i == 8 && winner == ' ') cout <<"Draw!!!!!\n";

        if (winner == 'X' || winner == 'O') {
                if (playerchacker % 2==0)
    cout << "the player 1 " << winner << " wins!\n" ;
    else
    cout << "the player 2 " << winner <<" wins!\n" ;
                                playerchacker--;

                                char replay;
                            
                 cout << "do you want..."<<endl;
                 cout << "[m/M] - to go to the menu"<<endl;
                 cout << "[E/e] - to Exit"<<endl;
                 cin >>replay;
                      if (replay == 'M' || replay == 'm' ) menu();
                        else if (replay == 'E' || replay == 'e' ) return;
     


    return menu();
     }

    }
          
  

}
void change_theplayers(){
//  here the player the swap or change characters in that resamble them in game that can be save next of them
    
   int reply;
    cout << "_______________change the players char_______________"  << endl;
    
        cout << "what do you want to do???"<< endl;
        cout << "1 - change the characters [X & O] to anothers ones."<< endl;
        cout << "2 - just swap them btw players."<< endl;
        cout << "3 - return to the menu."<< endl;
             cout << "choose the number of your option:" ;
             cin  >> reply;

             if (reply==1){
            //  the changer
                      cout << "the characters "<< player1 <<"in the player 1"<< endl;
                      cout << "choose another one:";
                         cin >> player1;
                      cout << "the characters "<< player2 <<"in the player 2"<< endl;
                      cout << "choose another one:";
                         cin >> player2;
                             cout << "the change is done!!!! "<< endl;
                        cout <<"in the player 1:"<<player1<<endl;
                        cout <<"in the player 2:"<<player2<<endl;

                        cout << "we returning to the menu..."<<endl;

                        menu();  
                    }
         
             else if (reply==2){
                   //  the swaper

                   char swaper=player1;
                        player1= player2;
                        player2=swaper;
                        cout << "the swap is done!!!! "<<endl;
                        cout <<"in the player 1:"<<player1<<endl;
                        cout <<"in the player 2:"<<player2<<endl;

                        cout << "we returning to the menu..."<<endl;

                        menu();                        
 
                    }
                      else if (reply==2) {  
                                    cout << "we returning to the menu..."<<endl;
                                    menu();                       
                    } 
            else {
            
                cout <<"there is no such a thing like this"<<endl;
                menu();   
            }
        
        



}
char win_check(){

       // rows
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return board[0][0];

    if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return board[1][0];

    if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return board[2][0];

    // columns
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return board[0][0];

    if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return board[0][1];

    if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return board[0][2];

    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
    

}
void rangame(){
        const char kbom = '*';
    char result[5];                    // Status: 'E' or '*'

}
void the_playing_type(){
    int choose;

          cout << "_______________the playing type_______________"  << endl;
          cout << " 1 - p1 vs p2."<< endl;
          cout << " 2 - p vs luck."<< endl;
          cout << " 3 - p vs ai."<< endl;
          cout << " 5 - menu."<< endl;
          cout << " 4 - Exit."<< endl;
          cout << "enter one of the number above...";
          cin  >> choose ;

          switch (choose)
          {
          case 1:  playing_turns(); break;
          case 2:
            // the_playing_type();
             break;

          case 3: 
            // the_playing_type();
              break;
          case 4:  menu();   break;
          case 5:  exit(0);  break;
          
          default:
            break;
          }

}



/*       # Understanding Row and Column Calculation

This is a **mathematical formula** that converts a position number
 (1-9) into **row and column coordinates** for a 3x3 grid.

 ## 🎯 **What It Does**

                                    When a player chooses a position (1-9), 
                                    you need to figure out **where** that is
                                    on your 3x3 board so you can place their 
                                    mark in the correct spot.

## 📊 **The Board Layout**

                                        Position:    1    2    3
                                                    4    5    6
                                                    7    8    9

                                        Row/Col:    (0,0) (0,1) (0,2)
                                                    (1,0) (1,1) (1,2)
                                                    (2,0) (2,1) (2,2)


## 🔢 **Breaking Down the Formula**

### **Row Calculation: `row = (pos - 1) / 3`**

                    This finds **which row** the position belongs to:

                    | Position | (pos - 1) | ÷ 3 | Row  |
                    |----------|-----------|-----|----- |
                    | 1 | 0 | 0 ÷ 3 = 0 | 0 (first row) |
                    | 2 | 1 | 1 ÷ 3 = 0 | 0 (first row) |
                    | 3 | 2 | 2 ÷ 3 = 0 | 0 (first row) |
                    | 4 | 3 | 3 ÷ 3 = 1 | 1 (second row)|
                    | 5 | 4 | 4 ÷ 3 = 1 | 1 (second row)|
                    | 6 | 5 | 5 ÷ 3 = 1 | 1 (second row)|
                    | 7 | 6 | 6 ÷ 3 = 2 | 2 (third row) |
                    | 8 | 7 | 7 ÷ 3 = 2 | 2 (third row) |
                    | 9 | 8 | 8 ÷ 3 = 2 | 2 (third row) |

> **Note:** In C++, when you divide integers, you get **integer division** (no decimals). So 3 ÷ 3 = 1, not 1.0

---

### **Column Calculation: `col = (pos - 1) % 3`**

            This finds **which column** the position belongs to:

                    | Position | (pos - 1) | % 3 | Column  |
                    |----------|-----------|-----|-------- |
                    | 1 | 0 | 0 % 3 = 0 | 0 (first column) |
                    | 2 | 1 | 1 % 3 = 1 | 1 (second column)|
                    | 3 | 2 | 2 % 3 = 2 | 2 (third column) |
                    | 4 | 3 | 3 % 3 = 0 | 0 (first column) |
                    | 5 | 4 | 4 % 3 = 1 | 1 (second column)|
                    | 6 | 5 | 5 % 3 = 2 | 2 (third column) |
                    | 7 | 6 | 6 % 3 = 0 | 0 (first column) |
                    | 8 | 7 | 7 % 3 = 1 | 1 (second column)|
                    | 9 | 8 | 8 % 3 = 2 | 2 (third column) |

> **Note:** `%` is the **modulo operator** - it gives you the **remainder** after division

---

## 🔍 **Why Subtract 1 First?**

Because:
- Players see positions as **1 through 9**
- But arrays in programming use **0 through 8** (zero-based indexing)

By subtracting 1, you convert the player's number into the **array index** you need.

---

## 💡 **Example Walkthrough**

### If player chooses position **5**:

**Step 1:** Convert to zero-based index
```
pos - 1 = 5 - 1 = 4
```

**Step 2:** Find the row
```
row = 4 / 3 = 1   (integer division)
```
→ Position 5 is in **row 1** (second row)

**Step 3:** Find the column
```
col = 4 % 3 = 1   (remainder of 4 ÷ 3 is 1)
```
→ Position 5 is in **column 1** (second column)

**Result:** Position 5 is at **board[1][1]** (the center)

---

## 🎮 **How It Works in Your Game**

```cpp
// Player chooses position 5
int pos = 5;

// Convert to row and column
int row = (pos - 1) / 3;    // row = 1
int col = (pos - 1) % 3;    // col = 1

// Place their mark
board[row][col] = 'X';      // board[1][1] = 'X'
```

---

## 📝 **Quick Reference Table**

| Player Input | Row | Col | Board Position |
|--------------|-----|-----|----------------|
| 1 | 0 | 0 | board[0][0] |
| 2 | 0 | 1 | board[0][1] |
| 3 | 0 | 2 | board[0][2] |
| 4 | 1 | 0 | board[1][0] |
| 5 | 1 | 1 | board[1][1] |
| 6 | 1 | 2 | board[1][2] |
| 7 | 2 | 0 | board[2][0] |
| 8 | 2 | 1 | board[2][1] |
| 9 | 2 | 2 | board[2][2] |

---

## 🧠 **Why This Works**

The formula works because:
- **Division** (`/`) groups things into rows of 3
- **Modulo** (`%`) finds the position within each row

Think of it like this:
- You have 9 numbers in a line
- You want to arrange them in 3 rows of 3
- The row is determined by how many complete groups of 3 you've passed
- The column is the position within the current group

---

## 💭 **Alternative Way to Think About It**

Imagine counting from 0 to 8:

```
Index:   0   1   2   3   4   5   6   7   8
         ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓
Position:1   2   3   4   5   6   7   8   9

Row 0:  0   1   2     ← These are positions 1, 2, 3
Row 1:  3   4   5     ← These are positions 4, 5, 6  
Row 2:  6   7   8     ← These are positions 7, 8, 9
```

- **Row** = index ÷ 3 (how many full rows have passed)
- **Column** = index % 3 (position within current row)

---

This formula is a **standard technique** in programming for converting between a flat list of items and a 2D grid layout!
*/ 