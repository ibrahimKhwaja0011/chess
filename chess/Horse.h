class Horse{
private:
	char W_horse;
	char B_horse;
public:

	char getW_Horse()
	{
		W_horse='H';
		return W_horse;
	}

	char getB_Horse()
	{
		B_horse='h';
		return B_horse;
	}

	bool validMove(char xPass[][8],int indexRow,int indexCol
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
		

		int diff4Row=indexRow2-indexRow;
		int diff4Col=indexCol2-indexCol;
		if(PieceGetter	>= 'A' && PieceGetter	<= 'Z')	
		{
			if((diff4Row==-1 && diff4Col==-2) || (diff4Row==-2 && diff4Col==-1) || (diff4Row==-2 && diff4Col==1)|| (diff4Row==-1 && diff4Col==2) || 
				(diff4Row==1 && diff4Col==-2) || (diff4Row==2 && diff4Col==-1)|| (diff4Row==1 && diff4Col==2)|| (diff4Row==2 && diff4Col==1) )
			{
				if( xPass[indexRow2][indexCol2] !='P'  && xPass[indexRow2][indexCol2] !='Q' && 
					xPass[indexRow2][indexCol2] !='K'  && xPass[indexRow2][indexCol2] !='B' &&
					xPass[indexRow2][indexCol2] !='F'  && xPass[indexRow2][indexCol2] !='H')
				{
					xPass[indexRow2][indexCol2]=PieceGetter;
					xPass[indexRow][indexCol]=NULL;
					return true;
				}
			}
			else
			{
				return false;
			}
		}

		if(PieceGetter	>= 'a' && PieceGetter	<= 'z')	
		{
			if((diff4Row==-1 && diff4Col==-2) || (diff4Row==-2 && diff4Col==-1) || (diff4Row==-2 && diff4Col==1)|| (diff4Row==-1 && diff4Col==2) || 
				(diff4Row==1 && diff4Col==-2) || (diff4Row==2 && diff4Col==-1)|| (diff4Row==1 && diff4Col==2)|| (diff4Row==2 && diff4Col==1) )
			{
				if( xPass[indexRow2][indexCol2] !='p'  && xPass[indexRow2][indexCol2] !='q' && 
					xPass[indexRow2][indexCol2] !='k'  && xPass[indexRow2][indexCol2] !='b' &&
					xPass[indexRow2][indexCol2] !='f'  && xPass[indexRow2][indexCol2] !='h')
				{
					xPass[indexRow2][indexCol2]=PieceGetter;
					xPass[indexRow][indexCol]=NULL;
					return true;
				}
			}
			else
			{
				return false;
			}
		}
		return false;
	}
};
