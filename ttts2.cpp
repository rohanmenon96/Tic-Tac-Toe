#include<iostream>
using namespace std;
// Numbering the Grid
// Take new/load game all inputs
int Grid[20][20];
void setGrid(int gridSize)
	{
		for(int i=0; i<gridSize; i++)
			{
				for(int j=0; j<gridSize; j++)
					{
						Grid[i][j] = 0;
					}
			}
	}
void displayGrid(int gridSize)
	{
		
		for(int i=0; i<gridSize; i++)
			{
				if(i==0)
					{
						cout<<"    "<<i+1<<" ";
					}
				else if(i>=9)
					{
						cout<<"  "<<i+1<<" ";
					}
				else
					{
						cout<<"  "<<i+1<<"  ";
					}
			}
		cout<<"\n";
		for(int i=0; i<gridSize; i++)
			{
				if(i<9)
					{
						cout<<i+1<<"  ";
					}
				else
					{
						cout<<i+1<<" ";
					}
				for(int j=0; j<gridSize; j++)
					{
						cout<<""<<Grid[i][j];
						if(j!=gridSize-1)
							{
								cout<<"  | ";
							} 
					}
				cout<<"\n";
				if(i!=(gridSize-1))
				{	
					for(int l=0; l<gridSize; l++)
					{
						if(l==0)
							{
								cout<<"   ---+";
							}
						else if(l==(gridSize-1))
							{
								cout<<"---";
							}
						else
							{
								cout<<"----+";
							}

					}
				}
				cout<<"\n";
			}
	}
int main()
    {
    	int a, numOfPlayers, gridSize;
    	bool k=false;
    	int i=1;
        cout<<"\t\t\tWelcome to the game of TicTacToe!! ";
        cout<<"\n\t\t\t   -----------------------------------";
        cout<<"\nChoose an option: ";
     	cout<<"\n1.Start a new game";
     	cout<<"\n2.Load a saved game\nInput : ";
     	cin>>a;
     	while(i>0)
     	{
     	if(a==1)
     		{
     			goto A;
     		}
     	else if (a==2)
     		{
     			goto B;
     			//Write this part of code
     		}
     	else
     		{
     			cout<<"\nWrong Input Please Try Again!";
     		}
     	}
		B:
     	cout<<"\nSorry! This part is still in progress!";
     	A:
     	while(k==false)
     		{
     			cout<<"\nEnter The Number of Players : ";
     			cin>>numOfPlayers;
     			if(numOfPlayers>26)
     				{
     					cout<<"\nSorry! The maximum number of players is 26! Please Enter Again.";
     				}
     			else if(numOfPlayers==1)
     				{
     					cout<<"\nTicTacToe requires minimum 2 players. Please Enter Again.";
     				}
     			else
     				{
     					k=true;
     				}

     		}
     	k=false;
     	while(k==false)
     		{
     			cout<<"\nEnter the size of the Grid: ";
     			cin>>gridSize;
     			if(gridSize<=(numOfPlayers-2))
     				{
     					cout<<"\nThis grid size wouldn't give a winner! Please Enter Again.";
     				}
     			else if(gridSize>999)
                    {
                        cout<<"\nGrid size should be less than 999. Please try again.";
                    }
                else
     				{
     					k=true;
     				}
     		}
        setGrid(gridSize);
        displayGrid(gridSize);
        return 0;
    }
