#pragma once
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
	Ships() : PosX(-1), PosY(-1) {}
	~Ships() {}
	Ships(int PosX, int PosY) {
		this->PosX = PosX;
		this->PosY = PosY;
	}

	void Rand() {

		PosX = rand() % 10;
		PosY = rand() % 10;

		cout << PosX << "   " << PosY << endl;
	}

public:
	int PosX;
	int PosY;
};	Ships r1[10]; Ships r2[10];