# include <iostream>
# include <windows.h>
# include <iomanip>
# include <string>
# include <fstream>
# include "Horse.h"
# include "king.h"
# include "queen.h"
# include "Bishop.h"
# include "pawn.h"
# include "Faseel.h"
# include "saveLoad.h"

HANDLE console =GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

int sideRulers=0;
bool W_destroyed=true;
bool B_destroyed=true;
class chess : public Horse , public King ,public Queen , public Bishop , public Faseel , public Pawn , public Options{

protected:
	char **arr;
	int size;
public:
	chess();
	~chess();
	void driver();
	void intPieces(char [][8]);
	void drawCurrent(char [][8]);
	void InputChecker(int &);
	void ValidMove();
	void inTarget(int & , int &);
	bool check_M(char [][8],bool);
};
chess :: chess(){
	this->size=8;
	this->arr=new char*[size];
	for(int lizer=0;lizer<size;lizer++)
	{
		arr[lizer]=new char [size];
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			arr[i][j]=NULL;
		}
	}
}

chess :: ~chess(){
	for (int i=0; i<=size; i++)
		delete [] arr[i];
	delete [] arr;
}

void chess :: driver()
{

	bool validMove=false;
	bool gameRunning=true;
	bool turnCounter=true;
	string optChoice;
	char PieceGetter='\0';
	int indexRow=0, indexRow2=0;
	int indexCol=0, indexCol2=0;
	const int size2=8;
	char copyArr[size2][size2];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			copyArr[i][j]=arr[i][j];
		}
	}

	intPieces(copyArr)	;
	bool options=true;

	while(gameRunning) 
	{
		system("cls");

		if (options==true)
		{
chessAg:
			system("cls");
			cout<<"\n\t\t\t     WELCOME TO CHESS\t\t\t\n\n\n\n\n\n\n";
			cout<<"\n\t\t WRITE 'new'   TO PLAY THE NEW GAME \n";
			cout<<"\n\t\t WRITE 'guide' To READ THE INSTRUCTION \n";
			cout<<"\n\t\t WRITE 'save'  To SAVE THE CURRENT GAME \n";
			cout<<"\n\t\t WRITE 'exit'  To EXIT FROM THE CURRENT GAME \n";
			cout<<"\n\t\t WRITE 'load'  To LOAD PREVIOUSLY SAVED GAME \n";

			cout<<"\n\t\t Enter Your Choice Plz ... :) ";
			cin>>optChoice;

			if(optChoice=="guide" || optChoice=="GUIDE"){
				Options :: Ins();
				goto chessAg;
			}
			else if(optChoice=="save" || optChoice=="SAVE"){
				Options :: save(copyArr);
				cout<<"\n Game Saved Succesfully \n";
				system("pause");
				system("cls");
			}
			else if(optChoice=="exit" || optChoice=="EXIT"){
				exit(1);
			}
			else if(optChoice=="load" || optChoice=="Load"){
				Options :: Load(copyArr);
				//copyArr[2][4]='F';
				system("cls");
			}
			else if(optChoice=="new" || optChoice=="NEW"){
				intPieces(copyArr);
				system("cls");
			}
			else {
				cout<<"Enter Valid Input ";
				goto chessAg;
			}
			options=false;

		}
		for(int jam=0;jam<8;jam++)
		{
			if(copyArr[0][jam]=='P')
			{
				cout<<"\nOooo Its White Pawn's Promotion Time ";
				cout<<"\nPlz Enter The Type To want to change the Pawn To (e.g : Q)";
				char inWPawn;
				cin>>inWPawn;
ifN1:
				if(inWPawn=='H' ||inWPawn=='K'|| inWPawn=='Q' || inWPawn=='B' || inWPawn=='F')
				{
					copyArr[0][jam]=inWPawn;
				}
				else 
				{
					cout<<"\nEnter Valid Character :";
					cin>>inWPawn;
					goto ifN1;
				}

			}
			else if(copyArr[7][jam]=='p')
			{
				cout<<"\nOooo Its Black Pawn's Promotion Time ";
				cout<<"\nPlz Enter The Type To want to change the Pawn To (e.g : q)";
				char inWPawn;
				cin>>inWPawn;
ifN:
				if(inWPawn=='h' ||inWPawn=='k'|| inWPawn=='q' || inWPawn=='b' || inWPawn=='f')
				{
					copyArr[7][jam]=inWPawn;
				}
				else 
				{
					cout<<"\nEnter Valid Character :";
					cin>>inWPawn;
					goto ifN;
				}

			}
		}
		bool king_Chk=false;
		king_Chk=check_M(copyArr,turnCounter);
		if(king_Chk==true)
			{
				cout<<"\n King is under Check";
				cout<<"\n  Bye Bye :)";
				system("pause");
				//exit(1);
			}
		drawCurrent(copyArr) ;
		if(turnCounter==true)	//white turn
		{
			/*king_Chk=check_M(copyArr,turnCounter);
			if(king_Chk==true)
			{
				cout<<"\n White King is under Check";
				cout<<"\n Black is the Winner ";
				system("pause");
				exit(1);
			}*/
			SetConsoleTextAttribute(console,  FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
			cout<<"\n White's Turn ";
			SetConsoleTextAttribute(console,10);
			cout<<"\n Source Loction";
			cout<<"\n\t Enter The Row Index (0-7): ";
			cin>>indexRow;
			InputChecker(indexRow);		//check either input is correct or not

			cout<<"\n\t Enter The Column Index (0-7): ";
			cin>>indexCol;
			InputChecker(indexCol);		//check either input is correct or not

			PieceGetter=copyArr[indexRow][indexCol];
			if (PieceGetter==NULL)
			{
				cout<<"\n You Have Selected an Empty Block . Select A Right One \n";
				turnCounter=true;
				//goto controller;
			}
			else if(PieceGetter=='P') // for Pawn 
			{
				inTarget(indexRow2,indexCol2);
				validMove=Pawn :: ValidMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=false;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}
			}
			else if(PieceGetter=='K') //for white king
			{
				inTarget(indexRow2,indexCol2);
				validMove=King ::validMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=false;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}

			}

			else if(PieceGetter=='H') //for white horse
			{
				inTarget(indexRow2,indexCol2);
				validMove=Horse ::validMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=false;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}

			}

			else if(PieceGetter=='F') //for white Faseel
			{
				inTarget(indexRow2,indexCol2);
				validMove=Faseel :: ValidMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=false;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}

			}
			else if(PieceGetter=='B') //for white Bishop
			{
				inTarget(indexRow2,indexCol2);
				validMove=Bishop :: ValidMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true){
					turnCounter=false;
					cout<<"\nMove Completed ";
				}
				else{
					cout<<"\n Enter Valid Move \n";
				}

			}
			else if(PieceGetter=='Q') //for white Queen
			{
				inTarget(indexRow2,indexCol2);
				validMove=Queen :: ValidMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=false;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}

			}
		}
		else if (turnCounter==false)
		{
			/*king_Chk=check_M(copyArr,turnCounter);
			if(king_Chk==true)
			{s
				cout<<"\n Black King is under Check";
				cout<<"\n White is the Winner ";
				system("pause");
				exit(1);
			}*/
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY );
			cout<<"\n Black's Turn ";
			SetConsoleTextAttribute(console,10);
			cout<<"\n Source Loction";
			cout<<"\n\t Enter The Row Index (0-7): ";
			cin>>indexRow;
			InputChecker(indexRow);		//check either input is correct or not
			cout<<"\n\t Enter The Column Index (0-7): ";
			cin>>indexCol;
			InputChecker(indexCol);		//check either input is correct or not
			PieceGetter=copyArr[indexRow][indexCol];
			if (PieceGetter==NULL)
			{
				cout<<"\n You Have Selected an Empty Block . Select A Right One \n";
				turnCounter=false;
				//goto controller;
			}
			else if(PieceGetter=='p') // for black Pawn 
			{
				inTarget(indexRow2,indexCol2);

				validMove=Pawn :: ValidMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);

				if (validMove==true){
					turnCounter=true;
					cout<<"\nMove Completed ";
				}
				else {
					cout<<"\n Enter Valid Move \n ";
				}

			}

			else if(PieceGetter=='k') //for black king
			{
				inTarget(indexRow2,indexCol2);
				validMove=King ::validMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=true;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}

			}
			else if(PieceGetter=='h') //for black horse
			{
				inTarget(indexRow2,indexCol2);
				validMove=Horse ::validMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=true;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}

			}
			else if(PieceGetter=='f') //for white Faseel
			{
				inTarget(indexRow2,indexCol2);
				validMove=Faseel :: ValidMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=true;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}
			}
			else if(PieceGetter=='b') //for white Bishop
			{
				inTarget(indexRow2,indexCol2);
				validMove=Bishop :: ValidMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=true;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}

			}
			else if(PieceGetter=='q') //for white Queen
			{
				inTarget(indexRow2,indexCol2);
				validMove=Queen :: ValidMove(copyArr,indexRow,indexCol,indexRow2,indexCol2,PieceGetter);
				if (validMove==true)
				{
					turnCounter=true;
					cout<<"\nMove Completed ";
				}
				else
				{
					cout<<"\n Enter Valid Move \n";
				}

			}
		}
		cout<<"\n Want to Check Out Different Options Press 'y' \nOtherWise Press any other Key\n";
		cout<<"\n Enter Key : ";
		char yes;
		cin>>yes;
		if(yes=='y' || yes=='Y')
		{
			options=true;
		}
		bool finisher=true;
		int k1=64,k2=64,k3=64;
		int i1=0,j1=0;
		while(k1>0)
		{
			if(copyArr[i1][j1]!=NULL)
			{
				finisher=false;
				break;
			}
			if(j1==7)
			{
				j1=0;
				i1++;
			}
			k1--;
			j1++;
		}
		i1=0,j1=0;
		W_destroyed=true;
		while(k2>0)
		{
			if(copyArr[i1][j1]=='K')
			{
				W_destroyed=false;
				break;
			}
			if(j1==7)
			{
				j1=0;
				i1++;
			}
			k2--;
			j1++;
		}
		i1=0,j1=0;
		B_destroyed=true;
		while(k3>0)
		{
			if(copyArr[i1][j1]=='k')
			{
				B_destroyed=false;
				break;
			}
			if(j1==7)
			{
				j1=0;
				i1++;
			}
			k3--;
			j1++;
		}

		if(finisher==true)
		{
			gameRunning=false;
		}
		else if(W_destroyed==true || B_destroyed==true)
		{
			gameRunning=false;
		}

	}
	cout<<"\n Game Ended :-)";
	if(W_destroyed==true)
	{
		cout<<"\n Black has Won ";
		cout<<"\n Game Ended :-)";
		system("pause");
		//exit(1);
	}
	else if(B_destroyed==true)
	{
		cout<<"\n White has Won ";
		cout<<"\n Game Ended :-)";
		system("pause");
		exit(1);
	}
}

void chess :: intPieces(char xPass[][8]){
	//white setting first (downwords)
	xPass[7][0]=getW_Faseel(); //white Faseel (Rooks)
	xPass[7][7]=getW_Faseel(); //

	xPass[7][1]=getW_Bishop(); //white Bishops
	xPass[7][6]=getW_Bishop();

	xPass[7][2]=getW_Horse();  //white Bishops
	xPass[7][5]=getW_Horse();

	xPass[7][3]=getW_Queen();	// queen 
	xPass[7][4]=getW_King();	//king


	for (int x = 0; x < size; x++) //for setting up White Pawns
	{
		xPass[6][x]=getW_Pawn();
	}


	// For Black Pieces

	xPass[0][0]=getB_Faseel(); // Black Faseel (Rooks)
	xPass[0][7]=getB_Faseel(); //

	xPass[0][1]=getB_Bishop(); // Black Bishops
	xPass[0][6]=getB_Bishop();

	xPass[0][2]=getB_Horse();  // Black Bishops
	xPass[0][5]=getB_Horse();

	xPass[0][3]=getB_Queen();	// queen 
	xPass[0][4]=getB_King();	// king


	for (int x = 0; x < size; x++) //for setting up White Pawns
	{
		xPass[1][x]=getB_Pawn();
	}
}


void chess :: drawCurrent(char xPass[][8])
{

	SetConsoleTextAttribute(console,14);
	cout<<"\n\n\t\t\t\t\t\t\n\n";
	SetConsoleTextAttribute(console,10);
	sideRulers=0;
	for (int row = 0; row < size; row++)
	{

		// Draws Horizontal Row Dividers
		cout << "   ";
		for (int col = 0; col < size; col++) 
		{
			cout << "-----";
		}
		cout << "-" << endl;


		// Draws Vertical Row Divider and Chess Piece
		SetConsoleTextAttribute(console,14);
		cout << sideRulers << "  ";
		SetConsoleTextAttribute(console,10);
		sideRulers++;

		for (int col = 0; col < 8; col++) 
		{
			cout << "| ";
			if (xPass[row][col] != NULL) 
			{
				if(xPass[row][col]>='a' && xPass[row][col] <='z')
				{
					SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY );
					cout<<xPass[row][col]<<" "; // printing if index is not null
					SetConsoleTextAttribute(console,10);
				}
				else if(xPass[row][col]>='A' && xPass[row][col] <='Z')
				{
					SetConsoleTextAttribute(console,  FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
					cout<<xPass[row][col]<<" "; // printing if index is not null
					SetConsoleTextAttribute(console,10);
				}
			} 
			else 
			{
				cout << "  ";
			}
			cout << " ";
		}

		// Draws Divider for end of Row
		cout << "|" << endl;

	}

	// Draws Horitonal Divider for last Row
	cout << "   ";
	for (int col = 0; col < 8; col++) {
		cout << "-----";
	}
	cout << "-" << endl;

	//Draw Bottom Index Indicator Line
	cout << "   ";
	for (int col = 0; col < 8; col++) {
		SetConsoleTextAttribute(console,14);
		cout << "  " << col << "  ";
		SetConsoleTextAttribute(console,10);
	}
	cout << endl << endl;

}


void chess :: InputChecker(int &x){

	while(x<0 || x>7)
	{
		cout<<"\n Invalid Index Entry , Enter Again \n";
		cin>>x;
	}

}
void chess :: inTarget(int &indexRow2, int &indexCol2){
	cout<<"\n Target Location ";
	cout<<"\n\t Enter The Row Index : ";
	cin>>indexRow2;
	InputChecker(indexRow2);		//check either input is correct or not
	cout<<"\n\t Enter The Column Index : ";
	cin>>indexCol2;
	InputChecker(indexCol2);		//check either input is correct or not 
}
bool chess :: check_M(char copyArr[][8], bool turnC)
{
	int WK_row=0;
	int WK_col=0;
	int BK_row=0;
	int BK_col=0;

	bool white_k=false;
	bool black_k=false;
	for (int qq = 0; qq < 8; qq++)
	{
		for (int ww = 0; ww < 8; ww++)
		{
			if(copyArr[qq][ww]=='K')
			{
				WK_row=qq;
				WK_col=ww;
			}
			else if(copyArr[qq][ww]=='k')
			{
				BK_row=qq;
				BK_col=ww;
			}
		}
	}
	bool Wchk_ret=false;
	
	for(int aa=0;aa<8;aa++)
	{
		for(int ss=0;ss<8;ss++)
		{
			if(turnC==true) //white turn
			{
			char PieceGetter=copyArr[aa][ss];
			if(copyArr[aa][ss]!=NULL && copyArr[aa][ss]>='a' && copyArr[aa][ss]<='z')
			{
				Wchk_ret=Pawn :: ValidMove(copyArr,aa,ss,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Queen :: ValidMove(copyArr,aa,ss,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Bishop :: ValidMove(copyArr,1,2,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Faseel :: ValidMove(copyArr,aa,ss,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Horse :: validMove(copyArr,aa,ss,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
			}
			else if(copyArr[aa][ss]!=NULL && copyArr[aa][ss]>='A' && copyArr[aa][ss]<='Z')
			{
				Wchk_ret=Pawn :: ValidMove(copyArr,aa,ss,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Queen :: ValidMove(copyArr,aa,ss,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Bishop :: ValidMove(copyArr,aa,ss,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Faseel :: ValidMove(copyArr,aa,ss,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Horse :: validMove(copyArr,aa,ss,BK_row,BK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
			}
			} //yes white

			if(turnC==false) //black turn
			{
			char PieceGetter=copyArr[aa][ss];
			if(copyArr[aa][ss]!=NULL && copyArr[aa][ss]>='a' && copyArr[aa][ss]<='z')
			{
				Wchk_ret=Pawn :: ValidMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Queen :: ValidMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Bishop :: ValidMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Faseel :: ValidMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Horse :: validMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
			}
			else if(copyArr[aa][ss]!=NULL && copyArr[aa][ss]>='A' && copyArr[aa][ss]<='Z')
			{
				Wchk_ret=Pawn :: ValidMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Queen :: ValidMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Bishop :: ValidMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Faseel :: ValidMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
				Wchk_ret=Horse :: validMove(copyArr,aa,ss,WK_row,WK_col,PieceGetter);
				if(Wchk_ret==true)
				{
					return true;
				}
			}
			} //yes black

		}
	}
	return false;
}