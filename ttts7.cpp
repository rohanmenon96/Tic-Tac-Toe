#include<iostream>
#include<stdlib.h>
using namespace std;
//Change Grid Size
char displayGrid[102][102];
int mainGrid[102][102];
void setMainGrid(int gridSize, int flag)
	{
		if(flag==0)
			{
				for(int i=0; i<gridSize; i++)
					{
						for(int j=0; j<gridSize; j++)
							{
								mainGrid[i][j]=-1;
							}
					}
			}

	}
void setGrid(int gridSize)
	{
		for(int i=0; i<gridSize; i++)
			{
				for(int j=0; j<gridSize; j++)
					{
						displayGrid[i][j] = ' ';
					}
			}
	}
void displayGridfn(int gridSize, int flag)
	{

			//For Showing the X Co-ordinate Numbers
			for(int i=0; i<gridSize; i++)
				{
					if(i==0)
						{
							cout<<"     "<<i+1<<" ";
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
			//This is for in-between the --- lines.
			for(int i=0; i<gridSize; i++)
				{
					if(i<9)
						{
							cout<<i+1<<"   ";
						}
					else if(i>98)
						{
							cout<<i+1<<" ";
						}
					else
						{
							cout<<i+1<<"  ";
						}
					for(int j=0; j<gridSize; j++)
						{
							if(flag==1)
							{
							cout<<""<<displayGrid[i][j];
							}
							else
							{
							cout<<""<<mainGrid[i][j];
							}
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
									cout<<"    ---+";
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
bool checkHorizontal(int id,int x, int y, int winSequence)
	{
		bool k=true;
		//cout<<"\nComing Inside checkHorizontal\n";
		//cout<<"\nPassed Parameters:\nid"<<id<<"\nx: "<<x<<"\ny: "<<y<<"\nwinSequence: "<<winSequence<<"\n";
		for(int i=1;i<=winSequence; i++) //Horiontal Addition
			{
			k=true;
			//cout<<"\ni : "<<i;
			for(int j = 0; j<winSequence; j++)	// Checking the 4 numbers
				{
					//cout<<"\nChecking at  position "<<x+1<<","<<y+j+1<<"\n";
					if(mainGrid[x][y+j]==id)
						{
						    //cout<<"Doing k&true as value at current position is "<<mainGrid[x][y+j];
							k = k&true;
						}
					else
						{
						    //cout<<"Doing k&false as value at current position is "<<mainGrid[x][y+j];
							k = k&false;
							//cout<<"\nBreaking out of the loop\n";
							break;
						}

				}
			//cout<<"\nValue of k is "<<k<<"\n";
			if(k==true)
				{
					return k;
				}
			y++;
			}
		return k;

	}
bool checkVertical(int id,int x, int y, int winSequence)
	{
		bool k=true;
		//cout<<"\nComing Inside checkHorizontal\n";
		//cout<<"\nPassed Parameters:\nid"<<id<<"\nx: "<<x<<"\ny: "<<y<<"\nwinSequence: "<<winSequence<<"\n";
		for(int i=1;i<=winSequence; i++) //Horiontal Addition
			{
			k=true;
			//cout<<"\ni : "<<i;
			for(int j = 0; j<winSequence; j++)	// Checking the 4 numbers
				{
					//cout<<"\nChecking at  position "<<x+1<<","<<y+j+1<<"\n";
					if(mainGrid[x+j][y]==id)
						{
						    //cout<<"Doing k&true as value at current position is "<<mainGrid[x][y+j];
							k = k&true;
						}
					else
						{
						    //cout<<"Doing k&false as value at current position is "<<mainGrid[x][y+j];
							k = k&false;
							//cout<<"\nBreaking out of the loop\n";
							break;
						}

				}
			//cout<<"\nValue of k is "<<k<<"\n";
			if(k==true)
				{
					return k;
				}
			x++;
			}
		return k;

	}
bool checkDiagonal(int id,int x, int y, int winSequence)
	{
		bool k=true;
		//cout<<"\nComing Inside checkHorizontal\n";
		//cout<<"\nPassed Parameters:\nid"<<id<<"\nx: "<<x<<"\ny: "<<y<<"\nwinSequence: "<<winSequence<<"\n";
		for(int i=1;i<=winSequence; i++) //Horiontal Addition
			{
			k=true;
			//cout<<"\ni : "<<i;
			for(int j = 0; j<winSequence; j++)	// Checking the 4 numbers
				{
					//cout<<"\nChecking at  position "<<x+1<<","<<y+j+1<<"\n";
					if(mainGrid[x+j][y+j]==id)
						{
						    //cout<<"Doing k&true as value at current position is "<<mainGrid[x][y+j];
							k = k&true;
						}
					else
						{
						    //cout<<"Doing k&false as value at current position is "<<mainGrid[x][y+j];
							k = k&false;
							//cout<<"\nBreaking out of the loop\n";
							break;
						}

				}
			//cout<<"\nValue of k is "<<k<<"\n";
			if(k==true)
				{
					return k;
				}
			x++;
			}
		return k;

	}
bool checkAll(int id,int x,int y, int winSequence)
	{
		bool k=false;
		//cout<<"\nComing inside Check All";
		//cout<<"\nPassed Parameters:\nid"<<id<<"\nx: "<<x<<"\ny: "<<y<<"\nwinSequence: "<<winSequence;
		k=checkHorizontal(id,x,(y-(winSequence-1)),winSequence);
		if(k==true)
			{
				return k;
			}
		k=checkVertical(id,(x-(winSequence-1)),y,winSequence);
		if(k==true)
			{
				return k;
			}
		k=checkDiagonal(id,(x-(winSequence-1)),(y-(winSequence-1)),winSequence);
		if(k==true)
			{
				return k;
			}
		return k;
	}
bool isBoardFull(int gridSize)
	{
		for(int i=0; i<gridSize; i++)
			{
				for(int j=0; j<gridSize; j++)
					{
						if(mainGrid[i][j]==-1)
							{
								return false;
							}
					}

			}
		return true;
	}
int main()
	{
		char Players[] = {'X','O','A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','Y','Z'};
		int id[27];
		for(int i=1; i<=26;i++)
			{
				id[i]=i; //Setting Unique IDs for every player
			}
		C:
		int gridSize = 0;
		int i=1;
		int x,y, winSequence;
		int a,numOfPlayers;
		bool k = false;
		bool correctInput = false;
		bool gameOver = false;
		char input2 = 'N';
		char input3;
		char input4;
		bool flag3=false;
		bool flag4=false;
		cout<<"\t\t\tWelcome to the game of TicTacToe!! ";
        cout<<"\n\t\t       -----------------------------------";
        cout<<"\nChoose an option: ";
     	cout<<"\n1.Start a new game";
     	cout<<"\n2.Load a saved game\nInput : ";
     	cin>>a;
     	system("cls");
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
     	cout<<"\nSorry! This part is still in progress!\nAutomatically Starting a new game...\n";
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
     			else if(gridSize<3)
	     			{
	     				cout<<"\nThe Minimum grid size is 3. Please Enter Again.";
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
     	k=false;
     	while(k==false)
     		{
     			cout<<"\nEnter the Win Sequence: ";
     			cin>>winSequence;
     			if(winSequence>gridSize)
     				{
     					cout<<"\nThis win Sequence wouldn't give a winner! Please Enter Again.";
     				}
                else
     				{
     					k=true;
     				}
     		}
     	system("cls");
		setGrid(gridSize);
		setMainGrid(gridSize,0);
		id[0] = 27;
		while(gameOver == false && input2 == 'N')
			{
				gameOver = isBoardFull(gridSize);
				if(gameOver==true)
					{
						cout<<"\nOops! The board is full and unfortunately the game is a tie. \nSee you next time!";
						break;
					}
				for(int counter=0 ; counter<numOfPlayers && gameOver==false && input2 == 'N'; counter++)
       				{
       					displayGridfn(gridSize,1); //Flag1 for Char Grid, Flag2 for main Grid
       					//displayGridfn(gridSize,2);
       					cout<<"\nPlayer "<<Players[counter]<<"'s Chance : \n";
       					while(flag3==false)
       						{
       							cout<<"\nDo you want to Quit the game? Enter 'Q' to Quit and 'N' to continue\n";
		       					cout<<"Input: ";
		       					cin>>input2;
		       					//cout<<"\nInput2 is "<<input2;
		       					if(input2=='Q')
		       						{
		       							cout<<"\nDo you want to save the game? (Y/N)\nInput: ";
		       							cin>>input3;
		       							flag3=true;
		       							break;
		       						}
		       					else if(input2 == 'N')
		       						{
		       							flag3=true;
		       							break;
		       						}
		       					else
		       						{
		       							cout<<"\nPlease enter a correct input!";
		       						}
       						}
       					flag3=false;
       					while(correctInput==false && input2== 'N')
       						{
       							cout<<"\nEnter the co-ordinates : ";
       							cin>>x;
       							cin>>y;
       							if(x>gridSize ||y>gridSize)
       								{
       									cout<<"\nPlease Enter Correct Inputs. \nEnter Again: ";
       								}
       							else if(mainGrid[x-1][y-1]!=-1)
       								{
       									cout<<"\nThat Box is Already Occupied! \nPlease enter other input : ";
       								}
       							else
       								{
       									correctInput=true;
       								}
       						}
       					if(input2=='Q')
       						{
       							break;
       						}
       					correctInput=false;
       					displayGrid[x-1][y-1] = Players[counter];
       					mainGrid[x-1][y-1]= id[counter];
       					gameOver = checkAll(id[counter],x-1,y-1,winSequence);
       					system("cls");
       					if(gameOver==true)
       						{
       							displayGridfn(gridSize,1);
       							cout<<"\n\n\t\tCONGRATULATIONS "<<Players[counter]<<" !!! "<<Players[counter]<<" has won the game!\n\n\n";
       							break;
       						}
       					gameOver = isBoardFull(gridSize);
       					if(gameOver == true)
       						{
       							displayGridfn(gridSize,1);
       							cout<<"\nOops! The board is full and it is a TIE! \n\nDo you want to start afresh?(Y/N)";
       							while(flag4==false)
       								{
       								    cout<<"\n\nInput : ";
       									cin>>input4;
		       							if(input4=='N')
		       								{
		       									system("cls");
		       									flag4=true;
		       								}
		       							else if(input4 == 'Y')
		       								{
		       									system("cls");
		       									flag4=true;
		       									goto C;
		       								}
		       							else
		       								{
		       									cout<<"\nPlease Enter a correct input!";
		       								}
       								}
       						}
       				}
			}
	system("cls");
	cout<<"\n\n\n\t\t\t\tByeBye! See you soon!\n\n\n";
	}
