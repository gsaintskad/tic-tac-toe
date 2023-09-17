#include"func`s.h"
#include<iostream>
#include<vector>
#include <windows.h>
#include<ctime>
#include"cell.h"
void print(vector<vector<cell>>* f) {
	for (int i = 0; i < f->size(); i++) {

		cout << "\t"<<"";
		for (int j = 0; j < f->size(); j++) {
			cout << ((*(&((*f)[i])))[j]).entity << "   ";
		}
		cout << "\n\n";
	};
}
bool isFinished(vector<vector<cell>>f) {
	int  act = 0;
	for (int i = 0; i < f.size(); i++) {
		for (int j = 0; j < f.size(); j++) {
			if (f[i][j].isActive) {
				act++;
			}
		}
	}
	if (act == 9) {
		cout << "\n---== DRAW !!! ==---\n";
		return 1;
	}
	else return 0;
}
bool wincheck(vector<vector<cell>>f) {
	cell c;
	bool k = true;

	//horizontal check
	for (int i = 0; i < f.size(); i++) {
		c = f[i][0];
		if (c.entity != '*') {
			if (f[i][0].entity == c.entity && f[i][1].entity == c.entity && f[i][2].entity == c.entity) {
				cout << "---==" << c.entity << " WINS !!!==---";
				return true;
			}
		}

	}
	//vertical check
	for (int i = 0; i < f.size(); i++) {
		c = f[0][i];
		if (c.entity != '*') {
			if (f[0][i].entity == c.entity) {
				if (f[1][i].entity == c.entity) {
					if (f[2][i].entity == c.entity) {
						cout << "---==" << c.entity << " WINS !!!==---";
						return true;
					}
				}
			}
		}
	}
	c = f[0][0];
	if (c.entity != '*') {

		if (f[1][1].entity == c.entity) {
			if (f[2][2].entity == c.entity) {
				cout << "---==" << c.entity << " WINS !!!==---";
				return true;
			}
		}

	}
	c = f[0][2];
	if (c.entity != '*') {
		if (f[1][1].entity == c.entity) {
			if (f[2][0].entity == c.entity) {
				cout << "---==" << c.entity << " WINS !!!==---";
				return true;
			}
		}

	}
	return 0;
}