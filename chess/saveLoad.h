# include <string>
# include <fstream>
using namespace std;
class Options{
public:
	void Ins(){
		system("cls");
	cout<<"\n @ Instruction Of Playing my version of chess\n";
	cout<<"\n @ A Single Move Consist Of Two turns ";
	cout<<"\n\tTurn # 1 : White ";
	cout<<"\n\tTurn # 2 : Black "; 
	cout<<"\n @ Each Turn Consist of Two Entries ";
	cout<<"\n @ First Entry : Row Index Entry";
	cout<<"\n @ Second Entry : Column Index Entry";
	cout<<"\n\n @ In-case of Pawn Promotion You Have To Change its Status";
	cout<<"\nFor Further Rules and Movement Rules \n Visit 'WikiPedia: https://en.wikipedia.org/wiki/Rules_of_chess" ;
	cout<<"\n\n";
	system("pause");
	system("cls");
	}
	void save(char xPass[][8])
	{
		fstream obj;
		obj.open("save.txt");
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				obj<<i;
				obj<<" ";
				obj<<j;
				obj<<" ";
				if(xPass[i][j]==NULL){
				obj<<"_";
				}
				else
				obj<<xPass[i][j];
				obj<<endl;
			}
	}
	}
	void Load(char xPass[][8]){
	int row;
	int col;
	char data;
	int length=8;
	fstream obj;
	obj.open("save.txt");
	while(!obj.eof())
	{
			obj>>row;
			obj>>col;
			obj>>data;
			if(data=='_'){
			xPass[row][col]=NULL;
			}
			else
				xPass[row][col]=data;
	}

	}
};