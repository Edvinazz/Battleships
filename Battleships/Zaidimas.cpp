#include "pch.h"
#include <iostream>
#include <ctime>
#include "Zaidimas.h"
using namespace std;

int mas[10][10];
int mas2[10][10];
void Laivai(int a) {
	
}
void Priesininkas() {

}

void map(int i, bool test) {

	if (test) {		
		if (mas[r1[i].PosX][r1[i].PosY] == 0) {
			mas[r1[i].PosX][r1[i].PosY] = 1;
		}
		else if (mas[r1[i].PosX][r1[i].PosY] == 1) {
			cout << "Iveskite kitas koordinates(x, y): ";
			r1[i].Ivestis();
			map(i, test);
		}

	}
	system("cls");
	cout << "Tavo laivai:" << endl;
	cout << "  0|1|2|3|4|5|6|7|8|9|"<<endl;
	for (int i = 0; i < 10; i++) {
		cout << i << "|";
		for (int j = 0; j < 10; j++) {
			if (mas[i][j] == 0) {
				cout << "*" << " ";
			}
			else if (mas[i][j] == 2) {
				cout << "+" << " ";
			}
			else if (mas[i][j] == 3) {
				cout << "-" << " ";
			}
			else {
				cout << mas[i][j] << " ";
			}
		}
			cout << endl;

	}

	cout << "Priesininko laivai:" << endl;


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << "*" << " ";
		}
		cout << endl;
	}
}

bool Puolimas(int q, int w) {
	if (mas[q][w] == 3 || mas[q][w] == 2) {
		cout << "Cia jau buvo sauta, kartokite is naujo: ";
		return false;
	}
	if (mas[q][w] == 1) {
		mas[q][w] = 2;
		cout << "Pataikyta.";
		return true;
	}
	else {
		mas[q][w] = 3;
		return true;
	}
}



int main()
{	
	int laivai = 10;
	map(0, false);
	cout << "Iveskite savo laivu koordinates(10 laivu): ";
	srand((unsigned)time(NULL));
	bool test = true;
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << " laivas (x ir y): ";
		r1[i].Ivestis();
		map(i, test);
	}
	test = false;

	while (laivai != 0) {
		cout << "Iveskite puolimo koordinates: ";
		int q, w;
		cin >> q >> w;
		Puolimas(q, w);
		map(0, false);
	}
		
	




}