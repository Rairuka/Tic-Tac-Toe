//making a game of tic tac toe

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define clear std::cout << "\033[2J\033[1;1H"; //clears screen


class tracker{
    public:
    std::string Player1;
    std::string Player2;
    int p1Count,p2Count;
    int currentTurn;
    int gameFinished=0;

    //draws whos turn it is
    void whosTurnDraw(){   
        using namespace std;

        if (gameFinished==0)
        {
            if (currentTurn==1)
            {
                cout << "Turn:" << Player1 << endl;
            currentTurn++;
            }
            else if(currentTurn==2)
            {
            cout << "Turn:" << Player2 << endl;
            currentTurn--;
            }
        } 

        if (gameFinished==1)
        {
            if (currentTurn==1)
            {
                cout << "Turn:" << Player1 << endl;
            }
            else if(currentTurn==2)
            {
                cout << "Turn:" << Player2 << endl;
            } 
        }     
        
    }
};

class window: public tracker{
    public:
    std::string pos[10]={"0","1","2","3","4","5","6","7","8","9"};

    //draw board
    void draw(){
        using namespace std;

        clear;
        cout << pos[1] << " | " << pos[2] << " | " << pos[3] << endl;
        cout << "__________\n";
        cout << pos[4] << " | " << pos[5] << " | " << pos[6] << endl;
        cout << "__________\n";
        cout << pos[7] << " | " << pos[8] << " | " << pos[9] << endl;
        cout << "\n\n";
        
        
    }

    //changes the numbers to marks
    void changeXO(int num){
        
        if (currentTurn==1){
            pos[num]="X";
            currentTurn++;  
        }
        else if (currentTurn==2)
        {
            pos[num]="O";
            currentTurn--;
        }
    }

    //checker function
    void checker(int a, int b, int c){
        using namespace std;

        if ((pos[a]==pos[b]) && (pos[a]==pos[c])){
            gameFinished = 1;
            if (pos[a]=="X"){
                cout << Player1 << " has won the game.\n"; 
            }
            else
            {
                cout << Player2 << " has won the game\n";
            }
            
        }

    }
};


int main(){
    using namespace std;

    //making objects
    tracker trackerObj; window windowObj;

    //vars
    int num;

    //introduction
    clear;
    cout << "Welcome to Tic Tac Toe\n";
    cout << "Please enter player 1's name\n";
    cin >> trackerObj.Player1;
    cout << "\nPlease enter player 2's name\n";
    cin >> trackerObj.Player2;
    cout << "Press any key to continue...\n";
    cin.ignore();
    cin.get();
    
    //object attribute setters
    windowObj.Player1=trackerObj.Player1;
    windowObj.Player2=trackerObj.Player2;
    
    //turn decider
    srand(time(0)); //setting seed
    trackerObj.currentTurn=rand() % 2 + 1; //choosing the player to start
    windowObj.currentTurn=trackerObj.currentTurn; //setting classes to same val

    //initial start of game
    windowObj.draw();
    trackerObj.whosTurnDraw();

    //the game continued
    while(windowObj.gameFinished == 0 ){
    cout << "Enter the number you wish to place a mark\n";
    cin >> num;
    windowObj.changeXO(num);
    windowObj.draw();

    //victory checker
    windowObj.checker(1,2,3);
    windowObj.checker(4,5,6);
    windowObj.checker(7,8,9);
    windowObj.checker(1,4,7);
    windowObj.checker(2,5,8);
    windowObj.checker(3,6,9);
    windowObj.checker(1,5,9);
    windowObj.checker(3,5,7);

    //whos turn drawer
    if (windowObj.gameFinished==0)
    {
        trackerObj.whosTurnDraw();
    }


    }
    return 0;
}

