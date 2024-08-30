#pragma once
#include <iostream>
#include <Time.h>
#include <string>

using namespace std;


class Jugador {
private:
	short posicionTiro;
public:
	int nroGoles;
	Jugador() {
		posicionTiro = 0;
		nroGoles = 0;
	}
	~Jugador() {}
	void patear()
	{
		while (true)
		{
			cout << "Direccion Tiro: ";
			cin >> posicionTiro;
			if (posicionTiro < 1 || posicionTiro > 9) {
				cout << "Posicion Incorrecta, intente de nuevo" << endl;
			}
			else
				break;
		}
	}
	void setPosicionTiro(int num) {
		posicionTiro = num;
	}
	short getPosicionTiro() {
		return posicionTiro;
	}
};


