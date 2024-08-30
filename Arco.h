#pragma once
#include <iostream>
#include <Time.h>
#include <string>
#include "Arquero.h"
using namespace std;



class Arco {
public:
	string grafArco[3][3];
	Arco() {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				grafArco[i][j] = "-";
			}
		}
	}

	void imprimirGraf() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << " " << grafArco[i][j] << " ";
			}
			cout << endl;
		}
	}
	void dibujarArco(int tiro, Arquero a) {
		int limite = a.getNumCuadros();

		string matrizGuia[3][3] = {
			{"7","8","9"}, {"4","5","6"} , {"1","2","3"}
		};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < limite; k++) {
					if (matrizGuia[i][j] == to_string(a.vectorCuerpo[k])) {
						grafArco[i][j] = "X";
					}
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (matrizGuia[i][j] == to_string(tiro)) {
					if (grafArco[i][j] == "X") {
						grafArco[i][j] = "!";
					}
					else {
						grafArco[i][j] = "O";
					}
					break;
				}
			}
		}
		imprimirGraf();
		resetearGrafArco();
	}

	void resetearGrafArco() {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				grafArco[i][j] = "-";
		}
	}
};


