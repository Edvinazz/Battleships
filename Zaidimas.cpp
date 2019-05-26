#include "pch.h"
#include <iostream>

using namespace std;

class Ships {
public:
	void Ivestis() {
		cin >> PosX >> PosY;
		if (PosX > 9 || PosX < 0 || PosY > 9 || PosY < 0) {
			cout << "Pakartokite ivedima:";
			cin >> PosX >> PosY;
		}
	}
	Ships() : PosX(0), PosY(0) {}
	~Ships() {}
	Ships(int PosX, int PosY) {
		this->PosX = PosX;
		this->PosY = PosY;		
	}

	int GetX() {
		return PosX;
	}
	int GetY() {
		return PosX;
	}


private:
	int PosX;
	int PosY;
};	Ships r1[10]; Ships r2[10];

int mas[10][10];
int mas2[10][10];

void map() {
	cout << "Tavo laivai:" << endl;
	cout << "  0|1|2|3|4|5|6|7|8|9|"<<endl;
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
		for (int j = 0; j < 10; j++) {
			for (int a = 0; a < 10; a++) {
				if (r1[a].GetX() == i && r1[a].GetY() == j) {
					mas[i][j] = 1;
				}
			}
			cout << mas[i][j] << " ";
		}
			cout << endl;

	}

	cout << "Priesininko laivai:" << endl;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << mas2[i][j] << " ";
		}
		cout << endl;
	}
}



int main()
{

	



	map();



}