#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;

// Have Set Size to 500 while submission else it takes a lot of time to compile
// Program works fine with 999 size also.

char displayGrid[500][500];
int mainGrid[500][500];
int numOfBoxesLeft=0;

void saveGame(int gridSize, int winSequence, int numOfPlayers, int currentTurn)
	{
		string fileName;
		ofstream myFile;
		cout<<"\nSave file as?\nInput: ";
		cin>>fileName;
		fileName = fileName+".txt";
		myFile.open(fileName.c_str());
		myFile << gridSize << endl;
		myFile << winSequence << endl;
		myFile << numOfPlayers << endl;
		myFile << currentTurn <<endl;
        for(int i=0; i<gridSize; i++)
            {
                for(int j=0; j<gridSize; j++)
                    {
                        myFile << mainGrid[i][j] <<endl;
                    }
            }
        cout<<"\nFile Successfully Saved!";
		myFile.close();
	}

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
void setDisplayGrid(int gridSize)
	{
		for(int i=0; i<gridSize; i++)
		{
			for(int j=0; j<gridSize; j++)
				{
					switch(mainGrid[i][j])
					{
						case -1:
						displayGrid[i][j] = ' ';
						break;

						case 27:
						displayGrid[i][j] = 'X';
						break;

						case 1:
						displayGrid[i][j] = 'O';
						break;

						default:
						displayGrid[i][j]  = mainGrid[i][j] + 63;
						break;
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
			y++;
			}
		return k;
	}

bool checkDiagonal2(int id,int x, int y, int winSequence)
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
					if(mainGrid[x-j][y+j]==id)
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
			x--;
			y++;
			}
		return k;
	}

bool checkAll(int id,int x,int y, int winSequence)
	{
		if(id>28)
			{
				id=27;
			}
		bool k=false;
		// cout<<"\nComing inside Check All";
		// cout<<"\nPassed Parameters:\nid"<<id<<"\nx: "<<x<<"\ny: "<<y<<"\nwinSequence: "<<winSequence;
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
		k=checkDiagonal2(id,(x+(winSequence-1)),(y-(winSequence-1)),winSequence);
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

bool isHorizontalTied(int startX, int startY, int winSequence, int ogX, int ogY)
	{
		//cout<<"\nInside isHorizontalTied()\n";
		//cout<<"\nogX is : "<<ogX+1;
		//cout<<"\nogY is : "<<ogY+1;
		bool k=true;
		for(int i=1;i<=winSequence; i++)
			{
			k=true;
			//cout<<"\n i: "<<i<<" ";
			for(int j = 0; j<winSequence; j++)
				{
					//cout<<"\nChecking at value "<<startX+1<<","<<startY+j+1<<" : "<<mainGrid[ogX][ogY]<<"\n";
					if(mainGrid[startX][startY+j]==mainGrid[ogX][ogY] || mainGrid[startX][startY+j]==-1)
						{
							k = k&true;
						}
					else
						{
							k = k&false;
							break;
						}

				}
			if(k==true)
				{
					return false;
				}
			startY++;
			}
		return true;
	}

bool isVerticalTied(int startX, int startY, int winSequence, int ogX, int ogY)
	{
		//cout<<"\nInside isVerticalTied()\n";
		//cout<<"\nogX is : "<<ogX+1;
		//cout<<"\nogY is : "<<ogY+1;
		bool k=true;
		for(int i=1;i<=winSequence; i++)
			{
			k=true;
			//cout<<"\n i: "<<i<<" ";
			for(int j = 0; j<winSequence; j++)
				{
					//cout<<"\nChecking at value "<<startX+j+1<<","<<startY+1<<" : "<<mainGrid[ogX][ogY]<<"\n";
					if(mainGrid[startX+j][startY]==mainGrid[ogX][ogY] || mainGrid[startX+j][startY]==-1)
						{
							k = k&true;
						}
					else
						{
							k = k&false;
							break;
						}

				}
			if(k==true)
				{
					return false;
				}
			startX++;
			}
		return true;
	}

bool isDiagonalTied(int startX, int startY, int winSequence, int ogX, int ogY)
	{
		//cout<<"\nInside isDiagonalTied()\n";
		//cout<<"\nogX is : "<<ogX+1;
		//cout<<"\nogY is : "<<ogY+1;
		bool k=true;
		for(int i=1;i<=winSequence; i++)
			{
			k=true;
			//cout<<"\n i: "<<i<<" ";
			for(int j = 0; j<winSequence; j++)
				{
					//cout<<"\nChecking at value "<<startX+j+1<<","<<startY+j+1<<" : "<<mainGrid[ogX][ogY]<<"\n";
					if(mainGrid[startX+j][startY+j]==mainGrid[ogX][ogY] || mainGrid[startX+j][startY+j]==-1)
						{
							//cout<<"\nDoing k=k&true because value at"<<startX+j+1<<","<<startY+j+1<<"is "<<mainGrid[ogX][ogY]<<" or -1\n";
							k = k&true;
						}
					else
						{
							k = k&false;
							break;
						}

				}
			if(k==true)
				{
					return false;
				}
			startX++;
			startY++;
			}
		return true;
	}

bool isDiagonal2Tied(int startX, int startY, int winSequence, int ogX, int ogY)
	{
		//cout<<"\nInside isDiagonal2Tied()\n";
		//cout<<"\nogX is : "<<ogX+1;
		//cout<<"\nogY is : "<<ogY+1;
		bool k=true;
		for(int i=1;i<=winSequence; i++)
			{
			k=true;
			//cout<<"\n i: "<<i<<" ";
			for(int j = 0; j<winSequence; j++)
				{
					//cout<<"\nChecking at value "<<startX-j+1<<","<<startY+j+1<<" : "<<mainGrid[ogX][ogY]<<"\n";
					if(mainGrid[startX-j][startY+j]==mainGrid[ogX][ogY] || mainGrid[startX-j][startY+j]==-1)
						{
							//cout<<"\nDoing k=k&true because value at"<<startX-j+1<<","<<startY+j+1<<"is "<<mainGrid[ogX][ogY]<<" or -1\n";
							k = k&true;
						}
					else
						{
							k = k&false;
							break;
						}

				}
			if(k==true)
				{
					return false;
				}
			startX--;
			startY++;
			}
		return true;
	}

bool checkAllTied(int x, int y, int gridSize, int winSequence)
	{
		//cout<<"\nInside checkAllTied()\n";
		if(isHorizontalTied(x,(y-(winSequence-1)),winSequence,x,y)==false)
		{
			return false;
		}
		else if(isVerticalTied((x-(winSequence-1)),y,winSequence,x,y)==false)
		{
			return false;
		}
		else if(isDiagonalTied((x-(winSequence-1)),(y-(winSequence-1)),winSequence,x,y)==false)
		{
			return false;
		}
		else if(isDiagonal2Tied((x+(winSequence-1)),(y-(winSequence-1)),winSequence,x,y)==false)
		{
			return false;
		}
		else
		{
			return true;
		}

	}

bool isBoardTied(int gridSize, int winSequence)
	{
		//cout<<"\nInside isBoardTied()";
		for(int i=0; i<gridSize; i++)
			{
				for(int j=0; j<gridSize; j++)
					{
						if(mainGrid[i][j]!=-1)
							{
								//cout<<"\n\n\nChecking for value "<<i+1<<","<<j+1<<"\n";
								if(checkAllTied(i,j,gridSize,winSequence)==false)
								{
									return false;
								}
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
		char a;
		int numOfPlayers;
		bool k = false;
		bool correctInput = false;
		bool gameOver = false;
		char input2 = 'N';
		char input3;
		char input4;
		bool flag3=false;
		bool flag4=false;
		bool flag5=false;
		bool flag6=true;
		string fileName;
		ifstream myFile;
		cout<<"\t\t\tWelcome to the game of TicTacToe!! ";
        cout<<"\n\t\t       -----------------------------------";
        cout<<"\nChoose an option: ";
     	cout<<"\n1.Start a new game";
     	cout<<"\n2.Load a saved game";
     	while(i>0)
     	{
     	cout<<"\nInput: ";
     	cin>>a;
     	if(a=='1')
     		{
     			goto A;
     		}
     	else if (a=='2')
     		{
     			flag6 = false;
     			goto B;
     		}
     	else
     		{
     			cout<<"\nWrong Input Please Try Again!";
     		}
     	}
     	A:
     	system("cls");
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
     	numOfBoxesLeft = gridSize*gridSize;
     	//cout<<"\nNumber of Boxes : "<<numOfBoxesLeft;
     	k=false;
     	while(k==false)
     		{
     			cout<<"\nEnter the Win Sequence: ";
     			cin>>winSequence;
     			if(winSequence>gridSize)
     				{
     					cout<<"\nThis win Sequence wouldn't give a winner! Please Enter Again.";
     				}
     			else if(winSequence<3)
     				{
     					cout<<"\nThat win Sequence is too small! Please Enter Again.";
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
		int counter;
		B:
		system("cls");
				if(flag6 == false)
					{
						int loop=1;
						while(loop>0)
							{
								cout<<"\nEnter the file name : ";
								cin>>fileName;
								fileName = fileName+".txt";
								myFile.open(fileName.c_str());
								if(myFile.fail())
									{
										cout<<"\nFile not present. Please enter valid file name.";
										cout<<"\nError Code : ";
									}
								else
									{
										myFile >> gridSize;
										myFile >> winSequence;
										myFile >> numOfPlayers;
										myFile >> counter;
										if(counter > 27)
												{
													counter = 27;
												}
										for(int row=0; row<gridSize; row++)
											{
												for(int column=0; column<gridSize; column++)
													{
														myFile >> mainGrid[row][column];
													}
											}
										displayGridfn[gridSize,1];
										loop=0;
										setDisplayGrid(gridSize);
										id[0] = 27;
										system("cls");
										goto D;
									}
							}
						flag6=true;
					}

		while(gameOver == false && input2 == 'N')
			{
				gameOver = isBoardFull(gridSize);
				if(gameOver==true)
					{
						cout<<"\nOops! The board is full and unfortunately the game is a tie. \nSee you next time!";
						break;
					}
				for(counter=0 ; counter<numOfPlayers && gameOver==false && input2 == 'N'; counter++)
       				{
       					D:
       					displayGridfn(gridSize,1); //Flag1 for Char Grid, Flag2 for main Grid
       					//displayGridfn(gridSize,2);
       					//cout<<"counter : "<<counter;
       					//displayGridfn(gridSize,2);
       					cout<<"\nPlayer "<<Players[counter]<<"'s Chance : \n\nwinSequence is "<<winSequence;
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
		       							if(input3 == 'Y')
		       								{
		       									saveGame(gridSize, winSequence, numOfPlayers, counter);
		       								}
		       							flag3=true;
		       							flag5=true;
		       							break;
		       						}
		       					else if(input2 == 'N')
		       						{
		       							flag3=true;
		       							flag5=true;
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
       					numOfBoxesLeft--;
       					//cout<<"\nnumOfBoxes left : "<<numOfBoxesLeft;
       					displayGrid[x-1][y-1] = Players[counter];
       					mainGrid[x-1][y-1]= id[counter];
       					gameOver = checkAll(id[counter],x-1,y-1,winSequence);
       					system("cls");
       					if(gameOver==true)
       						{
       							displayGridfn(gridSize,1);
       							cout<<"\n\n\t\tCONGRATULATIONS "<<Players[counter]<<" !!! "<<Players[counter]<<" has won the game!\n\n\n";
       							flag5=false;
       							break;
       						}
       					gameOver = isBoardFull(gridSize);
       					if(gameOver == true)
       						{
       							displayGridfn(gridSize,1);
       							cout<<"\nOops! The board is full and it is a TIE!";
       							flag5=false;
       							break;
       						}
       					gameOver = isBoardTied(gridSize, winSequence);
       					if(gameOver == true)
       						{
       							displayGridfn(gridSize,1);
       							cout<<"\nOops! No winning is possible from here on!";
       							flag5=false;
       							break;
       						}
       				}
			}
	if(flag5==false)
		{
		cout<<"\n\nDo you want to start afresh?(Y/N)";
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
	system("cls");
	cout<<"\n\n\n\t\t\t\tByeBye! See you soon!\n\n\n";
	}
