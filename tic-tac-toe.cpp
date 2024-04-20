//This is a 2 Player Tic-Tac-Toe Game 

#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;
void display(char arr[])
{
    //to display the board
    std::cout<<"  "<<arr[0]<<"  |  "<<arr[1]<<"  |  "<<arr[2]<<"  \t\t\t";
    std::cout<<"  1  |  2  |  3  \n";
    std::cout<<"-----------------\t\t\t-----------------\n";
    std::cout<<"  "<<arr[3]<<"  |  "<<arr[4]<<"  |  "<<arr[5]<<"  \t\t\t";
    std::cout<<"  4  |  5  |  6  \n";
    std::cout<<"-----------------\t\t\t-----------------\n";
    std::cout<<"  "<<arr[6]<<"  |  "<<arr[7]<<"  |  "<<arr[8]<<"  \t\t\t";
    std::cout<<"  7  |  8  |  9  \n";
}

int check_win(char arr[])
{
    int out=0;
    char win;

    //checking the winning condition across the columns
    for(int j = 0;j<3;j++)
    {
        if((arr[j]!= ' ') && (arr[j]==arr[j+3]) && (arr[j+3]==arr[j+6]))
        {
            win = arr[j];
            out = 1;
            break;
        }
    }

    //checking the winning condition across the rows
    for(int j = 0;j<9;j=j+3)
    {
        if((arr[j]!= ' ') && (arr[j]==arr[j+1]) && (arr[j+1]==arr[j+2]))
        {
            win = arr[j];
            out = 1;
            break;
        }
    }

    //checking the winning condition the across the diagonals
    if((arr[4]!= ' ') && ((arr[0]==arr[4] && arr[4] == arr[8])||(arr[2]==arr[4] && arr[4] == arr[6])))
    {
        win = arr[4];
        out = 1;
    }

    //declaring the winner
    if(win == 'X')
        std::cout<<"THE WINNER IS -----> PLAYER 1"<<endl;
    else if(win == 'O')
        std::cout<<"THE WINNER IS -----> PLAYER 2"<<endl;
    return out;
}

int main()
{
    //building the first screen
    char arr[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    std::cout<<"PLAYER 1 :: 'X'\nPLAYER 2 :: 'O'\t\t\tREFERENCE : \n";
    display(arr);
    std::cout<<"Enter the place's no. you want to click(according to the reference given)\n";
    int opt,flag;
    int i = 0,totalMoves = 0;

    //Game Starts here
    while(totalMoves != 9)
    {
        //first 4 moves are not uselful to check
        if(i>=4)
        {
            int out = check_win(arr);
            if(out == 1)
                break;
        }

        if(i%2==0)
            std::cout<<"PLAYER 1 :\nEnter your choice : ";
        else
            std::cout<<"PLAYER 2 :\nEnter your choice : ";

        //checking for exceptions and errors
        try
        {
            //Handling error if user enters anything other than integer
            while(!(cin >> opt))
            {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            }
            //Out of bound error handling
            if(opt<=0 || opt >= 10)
            {
                cout<<"Invalid position\n";
                i--;
                throw 0;
            }
            else
            {
                try
                {
                    //Handling situtation if position already occupied
                    if(arr[opt-1] != ' ')
                    {
                        if((i%2==0 && arr[opt-1] == 'X')||(i%2!=0 && arr[opt-1] == 'O'))
                            cout<<"Place already filled by you\n";
                        else if((i%2!=0 && arr[opt-1] == 'X')||(i%2==0 && arr[opt-1] == 'O'))
                            cout<<"Place already filled by oponent\n";
                        i--;
                        throw 'a';
                    }
                }
                catch(char x)
                {
                    i--;
                    continue;
                }
                if(i%2==0)
                    arr[opt-1]='X';
                else
                    arr[opt-1]='O';
                totalMoves++;
            }
        }
        catch(int x)
        {
            i--;
            continue;
        }
        catch(...)
        {
            std::cout<<"Wrong Input.......Try Again\n";
            i--;
            continue;
        }

        //clearing the screen and displaying new screen
        system("cls");
        std::cout<<"PLAYER 1 :: 'X'\nPLAYER 2 :: 'O'\n\t\t\tREFERENCE : \n";
        display(arr);
        std::cout<<"Enter the place's no. you want to click(according to the reference given)\n";
        i++;
    }

    //Match Draw condition : if the board is full and no one won the game
    if(totalMoves ==9 && check_win(arr)==0)
        std::cout<<"MATCH DRAW !!\n";
    //Game Ends here

    return 0;
}
