#include "pch.h"
#include <iostream>
#include <ctime>
#include "Zaidimas.h"

using namespace std;

int mas[10][10];
int mas2[10][10];
int laivai = 0;
int laivai2 = 0;

void MLaivai(int i, bool test) {
	if (test) {
		if (mas[r1[i].PosY][r1[i].PosX] == 0) {
			mas[r1[i].PosY][r1[i].PosX] = 1;

		}
		else if (mas[r1[i].PosY][r1[i].PosX] == 1) {
			cout << "Iveskite kitas koordinates(x, y): ";
			r1[i].Ivestis();
			MLaivai(i, test);
		}

	}
}

void PLaivai(int i, bool test) {
	if (test) {
		if (mas2[r2[i].PosY][r2[i].PosX] == 0) {
			mas2[r2[i].PosY][r2[i].PosX] = 1;

		}
		else if (mas2[r2[i].PosY][r2[i].PosX] == 1) {
			r2[i].Rand();
			PLaivai(i, test);
		}

	}
}

void map() {

	
	
	system("cls");
	cout << "Tavo laivai:" << endl;
	cout << "  0|1|2|3|4|5|6|7|8|9|" << endl;
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


	cout << "  0|1|2|3|4|5|6|7|8|9|" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << "|";
		for (int j = 0; j < 10; j++) {
			if (mas2[i][j] == 0) {
				cout << "*" << " ";
			}
			else if (mas2[i][j] == 2) {
				cout << "+" << " ";
			}
			else if (mas2[i][j] == 3) {
				cout << "-" << " ";
			}
			else {
				cout << mas2[i][j] << " ";
			}
		}
		cout << endl;

	}
}

bool Puolimas(int q, int w) {
	if (mas2[w][q] == 3 || mas2[w][q] == 2) {
		cout << "Cia jau buvo sauta, kartokite is naujo: ";
		cin >> q >> w;
		Puolimas(q, w);
		return false;
	}
	else if (mas2[w][q] == 1) {
		mas2[w][q] = 2;
		cout << "Pataikyta.";
		return true;

	}
	else {
		mas2[w][q] = 3;
		return false;
	}
}

bool Priesininkas() {
	int a = rand() % 10;
	int b = rand() % 10;
	if (mas[a][b] == 3 || mas[a][b] == 2) {
		Priesininkas();
		return false;
	}
	else if (mas[a][b] == 1) {
		mas[a][b] = 2;
		return true;

	}
	else {
		mas[a][b] = 3;
		return false;
	}

}
void Zaidimas() {
	int laivai = 0;
	int laivai2 = 0;
	map();
	cout << "Iveskite savo laivu koordinates(10 laivu): ";
	srand((unsigned)time(NULL));
	bool test = true;
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << " laivas (x ir y): ";
		r2[i].Rand();
		PLaivai(i, test);
		r1[i].Ivestis();
		MLaivai(i, test);
		map();
		laivai++;
		laivai2++;
		cout << "Laivu skaicius :" << laivai << "  ||";
		

	}

	test = false;

	while (laivai > 0 || laivai2 >0) {
		cout << "Iveskite puolimo koordinates: ";
		int q, w;
		cin >> q >> w;
		if (Puolimas(q, w) == true) {
			laivai2--;
		}
		if (Priesininkas() == true) {
			laivai--;
		}
		map();
		cout << "Jusu laivu skaicius :" << laivai << "  ||" << endl;
		cout << "Priesininko laivu skaicius :" << laivai2 << "  ||" << endl;

		if (laivai == 0) {
			cout << "Laimejo kompiuteris";
			return;
		}
		else if (laivai2 == 0){
			cout << "Sveikinimai, Jus laimejote laivu musi";
			return;
		}
	}


}
int main()
{	
	
	Zaidimas();
	
}