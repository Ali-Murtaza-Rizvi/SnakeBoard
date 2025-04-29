#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <windows.h>
using namespace std;
//Validations
void Enterinput(int i) {
  char key;
  cout<<"Player "<<i<<" Turn"<<endl;
  while (1) {
    cout << "press Enter to roll Dice";
    key = _getch();//The _getch() function is commonly used for reading a single character without echoing it to the screen
    cout << endl;
    if (key != 13){//ASCII Value Enter key
      cout << "Invalid input" << endl;
    } else {
      break;
    }
  }
}
void Enterinput() {
  char key;
  while (1) {
    cout << "press Enter to roll Dice";
    key = _getch();
    cout << endl;
    if (key != 13) {
      cout << "Invalid input" << endl;
    } else {
      break;
    }
  }
}
//to get enter on Main screen
void GetEnter() {
  char key;
  while (1) {
    key = _getch();
    cout << endl;
    if (key != 13) {
      cout << "Invalid input" << endl;
    } else {
      break;
    }
  }
}
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
class Snake_And_Ladder {
private:
  const int boardSize;
  stack<int> player1Positions, player2Positions;
  bool check1,check2;
  int undo1,undo2;
public:
  Snake_And_Ladder() : boardSize(100){
    // Set initial positions to 0 for each player
    player1Positions.push(0);
    player2Positions.push(0);
    check1 = false;//is player eligible to move
    check2 = false;//isplayer eligible to move
    undo1= 3;//no of undos per player
    undo2=3;
  }
  void restart(){
    while(!player1Positions.empty()){
      player1Positions.pop();
    }
    while(!player2Positions.empty()){
      player2Positions.pop();
    }
    player1Positions.push(0);
    player2Positions.push(0);
    check1 = false;
    check2 = false;
    undo1= 3;
    undo2=3;
  }
  void undo(stack<int> &p) {
    if (p.size() > 1) {
      p.pop();
    }
  }
  int rollDie() {
    int x = rand() % 6 + 1;
    cout << "You rolled a " << x << "." << endl;
    if (x == 6) {
        int u = rand() % 6 + 1; 
        cout << "You got 6, and rolled an additional " << u << "." << endl;
        x += u;
    }
    return x; 
    }
  void printBoard() {
   cout<<"\t\t\t_____________________________________________________________________________________________"<<endl;
   cout<<"\t\t\t_____________________________________________________________________________________________"<<endl<<endl;
    for (int i = 9; i >= 0; --i) {
      cout << "\t\t\t||";
      if(i%2==0){
      for (int j = 1; j <= 10; ++j) {
        int position = i * 10 + j;
        if (!player1Positions.empty() && player1Positions.top() == position && !player2Positions.empty() && player2Positions.top() == position) {
          SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE);
          cout << " P1/P2 "; // i did it to makesure to print both players when on same position
          SetConsoleTextAttribute(h, 15);
          cout<<"|";
        } else if (!player1Positions.empty() && player1Positions.top() == position) {
          SetConsoleTextAttribute(h, 15);
          SetConsoleTextAttribute(h,BACKGROUND_BLUE);
          cout << "   P1   ";
          SetConsoleTextAttribute(h, 15);
          cout<<"|";
        } else if (!player2Positions.empty() && player2Positions.top() == position) {
          SetConsoleTextAttribute(h, 15);
          SetConsoleTextAttribute(h, BACKGROUND_RED);
          cout << "   P2   ";
          SetConsoleTextAttribute(h, 15);
          cout<<"|";
        }else if(position == 54 || position == 30){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S1  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		else if(position == 47 || position == 26){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S2  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		else if(position == 75 || position == 56){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S3  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		else if(position == 88 || position == 70){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S4  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		else if(position == 99 || position == 2){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S5  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		//ladders
		else if(position == 7 || position == 14){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L1  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		else if(position == 15 || position == 34){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L2  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		else if(position == 28 || position == 50){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L3  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		else if(position == 36 || position == 44){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L4  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		else if(position == 42 || position == 63){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L5  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		 else {
          if (position < 10) {
            cout << "    " << position << "   |";
          } else if (position == 100) {
            cout << "   " << position << "  |";
          } else {
            cout << "   " << position << "   |";
          }
        }
      }
      cout << "|"<<endl;
    }
    else{
      for (int j = 10; j >= 1; --j) {
        int position = i * 10 + j;
        if (!player1Positions.empty() && player1Positions.top() == position && !player2Positions.empty() && player2Positions.top() == position) {
          SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE);
          cout << " P1/P2 "; // i did it to make sure to print both players when on same position
          SetConsoleTextAttribute(h, 15);
          cout<<"|";
        } else if (!player1Positions.empty() && player1Positions.top() == position) {
          SetConsoleTextAttribute(h, 15);
          SetConsoleTextAttribute(h,BACKGROUND_BLUE);
          cout << "   P1   ";
          SetConsoleTextAttribute(h, 15);
          cout<<"|";
        } else if (!player2Positions.empty() && player2Positions.top() == position) {
          SetConsoleTextAttribute(h, 15);
          SetConsoleTextAttribute(h, BACKGROUND_RED);
          cout << "   P2   ";
          SetConsoleTextAttribute(h, 15);
          cout<<"|";
        } else if(position == 54 || position == 30){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S1  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		else if(position == 47 || position == 26){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S2  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		else if(position == 75 || position == 56){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S3  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		else if(position == 88 || position == 70){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S4  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		else if(position == 99 || position == 2){
        	SetConsoleTextAttribute(h, BACKGROUND_GREEN);
          	cout << "    S5  ";
          	SetConsoleTextAttribute(h, 15);
          	cout<<"|";
		}
		//ladders
		else if(position == 7 || position == 14){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L1  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		else if(position == 15 || position == 34){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L2  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		else if(position == 28 || position == 50){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L3  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		else if(position == 36 || position == 44){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L4  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		else if(position == 42 || position == 63){
        	SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);
	        cout << "    L5  ";
	        SetConsoleTextAttribute(h, 15);
	        cout<<"|";
		}
		 else {
          if (position < 10) {
            cout << "    " << position << "   |";
          } else if (position == 100) {
            cout << "   " << position << "  |";
          } else {
            cout << "   " << position << "   |";
          }
        }
      }
      cout << "|"<<endl;
      }
      cout<<"\t\t\t_____________________________________________________________________________________________"<<endl;
      }
    cout<<"\t\t\t_____________________________________________________________________________________________"<<endl<<endl;
  }
  void player1_turn() {
    char choice;
    int roll;
    while (1) {
       roll = rollDie();
      cout << "Player 1 rolled a " << roll << ". " << endl;
      if (roll >= 6) {
        check1 = true;
      }
      if (check1 == true && player1Positions.top() + roll <= 100) {
        int newPosition1 = player1Positions.top() + roll;
        player1Positions.push(newPosition1);
        cout << "Player 1 is now at position " << newPosition1 << ". " << endl;
        // Check for snakes and ladders
        switch (newPosition1) {
        //Snakes
        case 54:
          cout<< "Oops! Player 1 landed on a Snake. Move back to position 30. ";
          player1Positions.top() = 30;
        break;
        case 47:
          cout
              << "Oops! Player 1 landed on a Snake. Move back to position 26. ";
          player1Positions.top() = 26;
          break;
        case 75:
          cout
              << "Oops! Player 1 landed on a Snake. Move back to position 56. ";
          player1Positions.top() = 56;
          break;
        case 88:
          cout
              << "Oops! Player 1 landed on a Snake. Move back to position 70. ";
          player1Positions.top() = 70;
          break;
        case 99:
          cout << "Oops! Player 1 landed on a Snake. Move back to position 2. ";
          player1Positions.top() = 2;
          break;
        //ladders
        case 42:
          cout << "Hooray! Player 1 climbed a ladder. Move forward to position 63. ";
          player1Positions.top() = 63;
          break;
        case 7:
          cout << "Hooray! Player 1 climbed a ladder. Move forward to position 14. ";
          player1Positions.top() = 14;
          break;
        case 15:
          cout << "Hooray! Player 1 climbed a ladder. Move forward to position 34. ";
          player1Positions.top() = 34;
          break;
        case 28:
          cout << "Hooray! Player 1 climbed a ladder. Move forward to position 50. ";
          player1Positions.top() = 50;
          break;
        case 36:
          cout << "Hooray! Player 1 climbed a ladder. Move forward to position 44. ";
          player1Positions.top() = 44;
          break;
        }
        cout << endl;
        if (newPosition1 >= boardSize) {
          return;
        }
      } else {
        cout << "Player 1 is locked" << endl;
      }
      printBoard();
      cout << "You want to Undo Move? Press Y ";
       string line;
        getline(cin, line);
      if (!line.empty() && line.size() == 1 && (line[0] == 'y' || line[0] == 'Y')) {
          choice = line[0];
      } else {
        choice = 'N';
      }
      if (choice == 'Y' || choice == 'y') {
        if (undo1 > 0) {
          undo(player1Positions);
          undo1--;
          Enterinput();
          system("cls");
		  continue;
        } else {
          cout << "Not enough Undos left" << endl;
        }
      }
      break;
    }
  }
  void player2_turn() {
    char choice;
    int roll;
    while (1) {
      roll = rollDie();
      cout << "Player 2 rolled a " << roll << ". " << endl;
      if (roll >= 6) {
        check2 = true;
      }
      if (check2 == true && player2Positions.top() + roll <= 100) {
        int newPosition2 = player2Positions.top() + roll;
        player2Positions.push(newPosition2);
        cout << "Player 2 is now at position " << newPosition2 << ". " << endl;
        // Check for snakes and ladders
        switch (newPosition2) {
        //Snakes
        case 54:
          cout<< "Oops! Player 2 landed on a Snake. Move back to position 30. ";
          player2Positions.top() = 30;
        break;
        case 47:
          cout
              << "Oops! Player 2 landed on a Snake. Move back to position 26. ";
          player2Positions.top() = 26;
          break;
        case 75:
          cout
              << "Oops! Player 2 landed on a Snake. Move back to position 56. ";
          player2Positions.top() = 56;
          break;
        case 88:
          cout
              << "Oops! Player 2 landed on a Snake. Move back to position 70. ";
          player2Positions.top() = 70;
          break;
        case 99:
          cout << "Oops! Player 2 landed on a Snake. Move back to position 2. ";
          player2Positions.top() = 2;
          break;
        //ladders
        case 42:
          cout << "Hooray! Player 2 climbed a ladder. Move forward to position 63. ";
          player2Positions.top() = 63;
          break;
        case 7:
          cout << "Hooray! Player 2 climbed a ladder. Move forward to position 14. ";
          player2Positions.top() = 14;
          break;
        case 15:
          cout << "Hooray! Player 2 climbed a ladder. Move forward to position 34. ";
          player2Positions.top() = 34;
          break;
        case 28:
          cout << "Hooray! Player 2 climbed a ladder. Move forward to position 50. ";
          player2Positions.top() = 50;
          break;
        case 36:
          cout << "Hooray! Player 2 climbed a ladder. Move forward to position 44. ";
          player2Positions.top() = 44;
          break;
        }
        cout << endl;
        if (newPosition2 >= boardSize) {
          return;
        }
      } else {
        cout << "Player 2 is locked" << endl;
      }
      printBoard();
      cout << "You want to Undo Move? press Y ";
       string line;
        getline(cin, line);
      if (!line.empty() && line.size() == 1 && (line[0] == 'y' || line[0] == 'Y')) {
          choice = line[0];
      } else {
        choice = 'N';
      }
      if (choice == 'Y' || choice == 'y') {
        if (undo2 > 0) {
          undo(player2Positions);
          undo2--;
          Enterinput();
          system("cls");
          continue; 
        } else {
          cout << "Not enough Undos left" << endl;
        }
      }
      break;
    }
  }
  void play() {
    char choice;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout << "                                                             __                             |     |" << endl;
	cout << "                                                           -<__)                            |     |" << endl;
	cout << "                                                              /                              ----- " << endl;
	cout << "                                                             /           WELCOME            |     |" << endl;
	cout << "                                                            /                               |     |" << endl;
	cout << "                                                           /                TO               ----- " << endl;
	cout << "                                                          /                                 |     |" << endl;
	cout << "                                                         /           SNAKES  &  LADDERS     |     |" << endl;
	cout << "                                                        /                                    ----- " << endl;
	cout << "                                                8______/________                            |     |" << endl;
	cout << "                                                      (_________)                           |     |" << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ Reach position 100 to win._ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<< endl;
    cout<<endl<<endl;
	cout << "                                                                Press Enter To Start the Game ";
    GetEnter();
    system("cls");
    printBoard();//initial board
    while (1) {	
      Enterinput(1);//??enter  print Player 1 Turn
      system("cls");
      player1_turn();
      if (player1Positions.top() >= boardSize) {
        printBoard();
        cout << "Player 1 reached position 100 and won the game" << endl;
        cout<<"You want to Restart? press Y ";
        string line;
        getline(cin, line);
      if (!line.empty() && line.size() == 1 && (line[0] == 'y' || line[0] == 'Y')) {
          choice = line[0];
      } else {
        choice = 'N';
      }
        if(choice == 'Y' || choice == 'y'){
          restart();
          continue;
        }else{
          return;
        }
      }
      Enterinput(2);
      system("cls");
	  player2_turn();
      if (player2Positions.top() >= boardSize) {
        printBoard();
        cout << "Player 2 reached position 100 and won the game" << endl;
        cout<<"You want to Restart? press Y ";
         string line;
        getline(cin, line);
      if (!line.empty() && line.size() == 1 && (line[0] == 'y' || line[0] == 'Y')) {
          choice = line[0];
      } else {
        choice = 'N';
      }
        if(choice == 'Y' || choice == 'y'){
          restart();
          continue;
        }else{
          return;
        }
      } 
    }
  }
};
int main() {
  // Seed the random number generator with the current time
  srand(static_cast<unsigned int>(time(0)));
  Snake_And_Ladder game;
  game.play();
  system("cls");
  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout << "                                                             __                             |     |" << endl;
	cout << "                                                           -<__)                            |     |" << endl;
	cout << "                                                              /                              ----- " << endl;
	cout << "                                                             /                              |     |" << endl;
	cout << "                                                            /       Thanks for playing!     |     |" << endl;
	cout << "                                                           /                                 ----- " << endl;
	cout << "                                                          /              Goodbye            |     |" << endl;
	cout << "                                                         /                                  |     |" << endl;
	cout << "                                                        /                                    ----- " << endl;
	cout << "                                                8______/________                            |     |" << endl;
	cout << "                                                      (_________)                           |     |" << endl;

  return 0;
}
