class Queen{
private:
	char W_queen;
	char B_queen;
public:
	char getW_Queen()
	{
		W_queen='Q';
		return W_queen;
	}

	char getB_Queen()
	{
		B_queen='q';
		return B_queen;
	}
	/////////////////////////////////////////////////
	//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
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
		
		else if(indexRow2<indexRow && indexCol2<indexCol) // for upper left Part
		{

		int dummyRow=indexRow-1;
		int dummyCol=indexCol-1;

			if(xPass[indexRow2][indexCol2]==NULL)
			{
				while(dummyRow!=0 || dummyCol!=0)
				{
				
					if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						return false;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						dummyRow--;
						dummyCol--;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow==indexRow2 && dummyCol==indexCol2 ))
					{
						xPass[indexRow2][indexCol2]=PieceGetter;
						xPass[indexRow][indexCol]=NULL;
						return true;
					}
					else 
					{
					return false;
					}
				}
			}
			else if(xPass[indexRow2][indexCol2]!=NULL)
			{
				while(dummyRow!=0 || dummyCol!=0)
				{
					if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						return false;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						dummyRow--;
						dummyCol--;
					}
					else if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow==indexRow2 && dummyCol==indexCol2 ))
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
					else 
					{
						return false;
					}
				}
			}
		}
		//////////////////////////////////////////////////////
		else if(indexRow2>indexRow && indexCol2>indexCol) // for lower Right Part
		{

		int dummyRow=indexRow+1;
		int dummyCol=indexCol+1;

			if(xPass[indexRow2][indexCol2]==NULL)
			{
				while(dummyRow!=0 || dummyCol!=0)
				{
				
					if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						return false;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						dummyRow++;
						dummyCol++;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow==indexRow2 && dummyCol==indexCol2 ))
					{
						xPass[indexRow2][indexCol2]=PieceGetter;
						xPass[indexRow][indexCol]=NULL;
						return true;
					}
					else
						{
							return false; 
					}
				}
				return false;
			}
			else if(xPass[indexRow2][indexCol2]!=NULL)
			{
				while(dummyRow!=0 || dummyCol!=0)
				{
					if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						return false;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						dummyRow++;
						dummyCol++;
					}
					else if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow==indexRow2 && dummyCol==indexCol2 ))
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
					else 
					{
					return false;
					}
				}
			}
		}
		/////////////////////////////////////////////////////
		else if(indexRow2<indexRow && indexCol2>indexCol) // for upper Right Part
		{

		int dummyRow=indexRow-1;
		int dummyCol=indexCol+1;

			if(xPass[indexRow2][indexCol2]==NULL)
			{
				while(dummyRow!=0 || dummyCol!=0)
				{
				
					if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						return false;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow==indexRow2 && dummyCol==indexCol2 ))
					{
						xPass[indexRow2][indexCol2]=PieceGetter;
						xPass[indexRow][indexCol]=NULL;
						return true;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						dummyRow--;
						dummyCol++;
					}
					else 
					{
						return false;
					}
				}
			}
			else if(xPass[indexRow2][indexCol2]!=NULL)
			{
				while(dummyRow!=0 || dummyCol!=0)
				{
					if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						return false;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						dummyRow--;
						dummyCol++;
					}
					else if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow==indexRow2 && dummyCol==indexCol2 ))
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
					else {
					return false;
					}
				}
			}
		}
		////////////////////////////////////////////////////
		else if(indexRow2>indexRow && indexCol2<indexCol) // for lower left Part
		{

		int dummyRow=indexRow+1;
		int dummyCol=indexCol-1;

			if(xPass[indexRow2][indexCol2]==NULL)
			{
				while(dummyRow!=0 || dummyCol!=0)
				{
				
					if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						return false;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						dummyRow++;
						dummyCol--;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow==indexRow2 && dummyCol==indexCol2 ))
					{
						xPass[indexRow2][indexCol2]=PieceGetter;
						xPass[indexRow][indexCol]=NULL;
						return true;
					}
					else 
					{
					return false;
					}
				}
			}
			else if(xPass[indexRow2][indexCol2]!=NULL)
			{
				while(dummyRow!=0 || dummyCol!=0)
				{
					if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						return false;
					}
					else if(xPass[dummyRow][dummyCol]==NULL && (dummyRow!=indexRow2 && dummyCol!=indexCol2 ))
					{
						dummyRow++;
						dummyCol--;
					}
					else if(xPass[dummyRow][dummyCol]!=NULL && (dummyRow==indexRow2 && dummyCol==indexCol2 ))
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
					else 
					{
					return false;
					}
				}
			}
		}
		///////////////////////////////////////////////////
	
		///////////////////////////////////////////////////
	//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
	else if(indexRow2==indexRow && indexCol2<indexCol)
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
	/////////////////////////////////////////////////
	return false;
	}
};
