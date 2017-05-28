# include "chess1.h"
# include <fstream>
void main(){
	int filer=0;
	fstream f1;
	f1.open("dash1.txt");
	SetConsoleTextAttribute(console,  FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char var;
	system("cls");
	while(!f1.eof()){
		f1.get(var);
		cout<<var;
	}
	cout<<endl;
	system("pause");
	system("cls");

	chess c;
	c.driver();
	exit(1);
}
