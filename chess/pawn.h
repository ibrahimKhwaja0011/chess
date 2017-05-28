using namespace std;
class Pawn{
private:
	char W_pawn;
	char B_pawn;
public:
	char getW_Pawn() //set and get value functions
	{
		W_pawn='P';
		return W_pawn;
	}

	char getB_Pawn()
	{
		B_pawn='p';
		return B_pawn;
	}

	bool ValidMove(char xPass[][8],int indexRow,int indexCol
					,int indexRow2,int indexCol2,char PieceGetter)
	{
		char pieceGetter2=xPass[indexRow2][indexCol2];
		
		if((pieceGetter2=='p' || pieceGetter2=='q' || 
			pieceGetter2=='f' || pieceGetter2=='h' || 
			pieceGetter2=='b' || pieceGetter2=='k') && 

			(PieceGetter=='p' || PieceGetter=='q' || 
			PieceGetter=='f' || PieceGetter=='h' || 
			PieceGetter=='b' || PieceGetter=='k')){
				return false;
		}
	
		else if((pieceGetter2=='P' || pieceGetter2=='Q' || 
			pieceGetter2=='F' || pieceGetter2=='H' || 
			pieceGetter2=='B' || pieceGetter2=='K') && 

			(PieceGetter=='P' || PieceGetter=='Q' || 
			PieceGetter=='F' || PieceGetter=='H' || 
			PieceGetter=='B' || PieceGetter=='K'))
			{
				return false;
			}
		


		
		int differ4Row=0;
		int differ4Col=0;
		if (PieceGetter=='P'){
		differ4Row=indexRow-indexRow2;
									//if 2 then double jump , if one then single block jump
		differ4Col=indexCol-indexCol2;
		}
		else if(PieceGetter=='p'){
		
		differ4Row=indexRow2-indexRow;
									//if 2 then double jump , if one then single block jump
		differ4Col=indexCol2-indexCol;

		}
		if(xPass[indexRow2][indexCol2]==NULL && ( differ4Row ==2 || differ4Row == 1 ) && differ4Col==0)
		{ //above if condition is for stright movement 
			xPass[indexRow2][indexCol2]=PieceGetter;
			xPass[indexRow][indexCol]=NULL;
			return true;
		}
		else if (xPass[indexRow2][indexCol2]!=NULL && ( differ4Row ==2 || differ4Row == 1 ) && (differ4Col==1 || differ4Col==-1 ) )
		{ //diagonal movement
			if(PieceGetter	>= 'A' && PieceGetter	<= 'Z')		//white one on strikeing black one
			{ 
				if( xPass[indexRow2][indexCol2] !='P'  && xPass[indexRow2][indexCol2] !='Q'&& 
					xPass[indexRow2][indexCol2] !='K' && xPass[indexRow2][indexCol2] !='B' &&
					xPass[indexRow2][indexCol2] !='F' && xPass[indexRow2][indexCol2] !='H'  ) 
					//check if not of similar type
				{
					xPass[indexRow2][indexCol2]=PieceGetter;
					xPass[indexRow][indexCol]=NULL;
					return true;
				}
				else if( ! (PieceGetter	>= 'A' && PieceGetter	<= 'Z')	){	//white one on strikeing black one
				
					cout<<"\n Unable To Cut My Own Piece \n";
					return false;
				}
			}

			else if(PieceGetter	>= 'a' && PieceGetter	<= 'z')		//white one on strikeing black one
			{ 
				if( xPass[indexRow2][indexCol2] !='p'  && xPass[indexRow2][indexCol2] !='q'&& 
					xPass[indexRow2][indexCol2] !='k' && xPass[indexRow2][indexCol2] !='b' &&
					xPass[indexRow2][indexCol2] !='f' && xPass[indexRow2][indexCol2] !='h'  ) 
					//check if not of similar type
				{
					xPass[indexRow2][indexCol2]=PieceGetter;
					xPass[indexRow][indexCol]=NULL;
					return true;
				}
				else if( ! (PieceGetter	>= 'a' && PieceGetter	<= 'z')	){	//white one on strikeing black one
				
					cout<<"\n Unable To Cut My Own Piece \n";
					return false;
				}
			}


			else 
				return false;
		}
		return false;
	}
};
