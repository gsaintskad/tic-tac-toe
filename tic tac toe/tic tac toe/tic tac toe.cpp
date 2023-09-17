#include<iostream>
#include<vector>
#include <windows.h>
#include<ctime>
#include"func`s.h"
#include"cell.h"
using namespace std;



int main(){
again://the link to restart game
	srand(time(NULL));
	vector<vector<cell>> field = { {},{},{} };
	cell c;
	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < field.size(); j++) {
			field[i].push_back(c);
		}
	}

	//cell`s definition
	cell O;
	O.entity = 'O';
	O.isActive = true;

	cell X;
	X.entity = 'X';
	X.isActive = true;

	    



	print(&field);


	bool active = true;
	int t = rand();
	int a=0, b=0;
	while (active) {
		t = t % 2;//turn randomizer

		if (t) {
			cout << "---== X TURN ==---" << endl;
			errX:
			cout << "CHOOSE VERTICAL POSITION FOR X (1-3) : ";
			cin >> a;
			cout << "CHOOSE HORIZONTAL POSITION FOR X (1-3) : ";
			cin >> b;
			if(a<1||a>3||b>3||b<1){
				cout << endl;
				cout << "INVALID VALUE!!!" << endl;
				cout << "WRITE AGAIN : "<<endl;
				goto errX;
			}
			if (field[a - 1][b - 1].isActive) {//field[0][2]
				cout << "THIS CELL ALREADY ACTIVE ! \nWRITE AGAIN : \n";
				goto errX;
			}
			field[a-1][b-1] = X;
			system("cls");
			print(&field);
			t++;
			
		}
		else{
		errO:
			cout << endl;
			cout << "---== O TURN ==---" << endl
				<< "CHOOSE VERTICAL POSITION FOR O (1-3) : ";
			cin >> a;
			cout<< "CHOOSE HORIZONTAL POSITION FOR O (1-3) : ";
			cin >> b;
			if (a < 1 || a>3 || b > 3 || b < 1) {
				cout << "INVALID VALUE!!" << endl;
				cout << "WRITE AGAIN\n";
				goto errO;
			}
			if (field[a - 1][b - 1].isActive) {
				cout << "THIS CELL ALREADY ACTIVE ! \nWRITE AGAIN : \n";
				goto errO;
			}
			field[a-1][b-1] = O;
			system("cls");
			print(&field);
			t++;
			
		}
		bool cond;
		cond = isFinished(field);
		if (cond) active = false;
		cond = wincheck(field);
		if (cond) active = false;
	}
	cout << "\n\n\n DO YOU WANT TO PLAY AGAIN ???    ( enter '+' to play again ) :   ";
	char answer;
	cin >> answer;
	if (answer == '+') {
		system("cls");
		goto again;
	}
	return 0;
}