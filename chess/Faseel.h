class Faseel{
private:
	char W_faseel;
	char B_faseel;
public:
	char getW_Faseel()
	{
		W_faseel='F';
		return W_faseel;
	}

	char getB_Faseel()
	{
		B_faseel='f';
		return B_faseel;
	}

	bool ValidMove(char xPass[][8],int indexRow,int indexCol ,int indexRow2,int indexCol2,char PieceGetter)
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
		
		if(indexRow2==indexRow && indexCol2<indexCol)
		{
			if(xPass[indexRow2][indexCol2]!=NULL)
			{
				int diffCol=indexCol-indexCol2;
				int countL=indexCol-1;

				for(int x=0;x<diffCol;x++) //if destination is not equal to null
				{
					if(xPass[indexRow2][countL]!=NULL && countL!=indexCol2)
					{
						return false;
					}
					else if(xPass[indexRow2][countL]==NULL && countL!=indexCol2)
					{
						countL--;
					}
					else if(xPass[indexRow2][countL]!=NULL && countL==indexCol2)
					{
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
						}
					}
				}
			}
			else if(xPass[indexRow2][indexCol2]==NULL)
			{
				int diffCol=indexCol-indexCol2;
				int countL=indexCol-1;
				for(int x=0;x<diffCol;x++) //if destination is equal to null
				{
					if(xPass[indexRow2][countL]!=NULL && countL!=indexCol2)
					{
						return false;
					}
					else if(xPass[indexRow2][countL]==NULL && countL!=indexCol2)
					{
						countL--;
					}
					else if(xPass[indexRow2][countL]==NULL && countL==indexCol2)
					{
						xPass[indexRow2][indexCol2]=PieceGetter;
						xPass[indexRow][indexCol]=NULL;
						return true;
					}
				}
			}
		}

		else if(indexRow2==indexRow && indexCol2>indexCol)
		{
			if(xPass[indexRow2][indexCol2]!=NULL)
			{
				int diffCol=indexCol2-indexCol;
				int countL=indexCol+1;

				for(int x=0;x<diffCol;x++) //if destination is not equal to null
				{
					if(xPass[indexRow2][countL]!=NULL && countL!=indexCol2)
					{
						return false;
					}
					else if(xPass[indexRow2][countL]==NULL && countL!=indexCol2)
					{
						countL++;
					}
					else if(xPass[indexRow2][countL]!=NULL && countL==indexCol2)
					{
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
						}
					}
				}
			}
			else if(xPass[indexRow2][indexCol2]==NULL)
			{
				int diffCol=indexCol2-indexCol;
				int countL=indexCol+1;
				for(int x=0;x<diffCol;x++) //if destination is not equal  null
				{
					if(xPass[indexRow2][countL]!=NULL && countL!=indexCol2)
					{
						return false;
					}
					else if(xPass[indexRow2][countL]==NULL && countL!=indexCol2)
					{
						countL++;
					}
					else if(xPass[indexRow2][countL]==NULL && countL==indexCol2)
					{
						xPass[indexRow2][indexCol2]=PieceGetter;
						xPass[indexRow][indexCol]=NULL;
						return true;
					}
				}
			}
		}
	
		else if(indexCol2==indexCol && indexRow2<indexRow)
		{
			if(xPass[indexRow2][indexCol2]!=NULL)
			{
				int diffCol=indexRow-indexRow2;
				int countL=indexRow-1;

				for(int x=0;x<diffCol;x++) //if destination is not equal to null
				{
					if(xPass[countL][indexCol2]!=NULL && countL!=indexRow2)
					{
						return false;
					}
					else if(xPass[countL][indexCol2]==NULL && countL!=indexRow2)
					{
						countL--;
					}
					else if(xPass[countL][indexCol2]!=NULL && countL==indexRow2)
					{
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
						}
					}
				}
			}
			else if(xPass[indexRow2][indexCol2]==NULL)
			{
				int diffCol=indexRow-indexRow2;
				int countL=indexRow-1;
				for(int x=0;x<diffCol;x++) //if destination is equal to null
				{
					if(xPass[countL][indexCol2]!=NULL && countL!=indexRow2)
					{
						return false;
					}
					else if(xPass[countL][indexCol2]==NULL && countL!=indexRow2)
					{
						countL--;
					}
					else if(xPass[countL][indexCol2]==NULL && countL==indexRow2)
					{
						xPass[indexRow2][indexCol2]=PieceGetter;
						xPass[indexRow][indexCol]=NULL;
						return true;
					}
				}
			}
		}

		else if(indexCol2==indexCol && indexRow2>indexRow)
		{
			if(xPass[indexRow2][indexCol2]!=NULL)
			{
				int diffCol=indexRow2-indexRow;
				int countL=indexRow+1;

				for(int x=0;x<diffCol;x++) //if destination is not equal to null
				{
					if(xPass[countL][indexCol2]!=NULL && countL!=indexRow2)
					{
						return false;
					}
					else if(xPass[countL][indexCol2]==NULL && countL!=indexRow2)
					{
						countL++;
					}
					else if(xPass[countL][indexCol2]!=NULL && countL==indexRow2)
					{
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
						}
					}
				}
			}
			else if(xPass[indexRow2][indexCol2]==NULL)
			{
				int diffCol=indexRow2-indexRow;
				int countL=indexRow+1;
				for(int x=0;x<diffCol;x++) //if destination is not equal  null
				{
					if(xPass[countL][indexCol2]!=NULL && countL!=indexRow2)
					{
						return false;
					}
					else if(xPass[countL][indexCol2]==NULL && countL!=indexRow2)
					{
						countL++;
					}
					else if(xPass[countL][indexCol2]==NULL && countL==indexRow2)
					{
						xPass[indexRow2][indexCol2]=PieceGetter;
						xPass[indexRow][indexCol]=NULL;
						return true;
					}
				}
			}
		}
		return false;
		}
};
