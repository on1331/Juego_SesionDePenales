#pragma once
#include <iostream>
#include <Time.h>
#include <string>
#include "Jugador.h"

using namespace std;

class Arquero {
private:
	short numCuadros;
public:
	int posicionInicial; //cabeza del arquero
	int nroAtajadas;
	float altura;
	int* vectorCuerpo;

	Arquero() {
		numCuadros = 3;
		posicionInicial = 8;
		nroAtajadas = 0;
		altura = 1.75;
		vectorCuerpo = new int[numCuadros];
	}
	~Arquero() {}
	Arquero(float alt) {
		nroAtajadas = 0;
		altura = alt;
		if (altura > 1.70) {
			numCuadros = 3;
			posicionInicial = 8;
		}
		else {
			if (altura <= 0.85) {
				numCuadros = 1;
				posicionInicial = 2;
			}
			else {
				numCuadros = 2;
				posicionInicial = 5;
			}
		}
		vectorCuerpo = new int[numCuadros];
	}

	void defPosicionAtajada() { //definir la posicion del arquero al momento de atajar 

		//num_aleatorio = limInf + rand() % (limSup + 1 - limInf)
		if (numCuadros == 3) { //si el arquero ocupa 3 cuadros del arco
			////num random de 4-9 excepto el 5
			do {
				vectorCuerpo[0] = 4 + rand() % (6);
			} while (vectorCuerpo[0] == 5);

			switch (vectorCuerpo[0]) {
			case 4:
				vectorCuerpo[1] = 5;
				vectorCuerpo[2] = 6;
				break;
			case 6:
				vectorCuerpo[1] = 5;
				vectorCuerpo[2] = 4;
				break;
			case 7: {
				int m7[3][2] = { {4,1},{5,3},{8,9} };
				int indiceRandom7 = rand() % (3);
				vectorCuerpo[1] = m7[indiceRandom7][0];
				vectorCuerpo[2] = m7[indiceRandom7][1];
				break;}
			case 8: {
				vectorCuerpo[1] = 5;
				vectorCuerpo[2] = 2;
				break;}
			case 9: {
				int m9[3][2] = { {8,7},{5,1},{6,3} };
				int indiceRandom9 = rand() % (3);
				vectorCuerpo[1] = m9[indiceRandom9][0];
				vectorCuerpo[2] = m9[indiceRandom9][1];
				break;}
			}
		}
		else {

			if (numCuadros == 2) {
				vectorCuerpo[0] = 4 + rand() % (6); //num random 4-9
				switch (vectorCuerpo[0]) {
				case 4: {
					int v4[3] = { 1,2,5 };
					int indiceRand4 = rand() % (3);
					vectorCuerpo[1] = v4[indiceRand4];
					break;
				}
				case 5: {
					int v5[5] = { 4,1,2,3,6 };
					int indiceRand5 = rand() % (5);
					vectorCuerpo[1] = v5[indiceRand5];
					break;
				}
				case 6: {
					int v6[3] = { 5,2,3 };
					int indiceRand6 = rand() % (3);
					vectorCuerpo[1] = v6[indiceRand6];
					break;
				}
				case 7: {
					int v7[3] = { 4,5,8 };
					int indiceRand7 = rand() % (3);
					vectorCuerpo[1] = v7[indiceRand7];
					break;
				}
				case 8: {
					int v8[5] = { 7,4,5,6,9 };
					int indiceRand8 = rand() % (5);
					vectorCuerpo[1] = v8[indiceRand8];
					break;
				}
				case 9: {
					int v9[3] = { 8,5,6 };
					int indiceRand9 = rand() % (3);
					vectorCuerpo[1] = v9[indiceRand9];
					break;
				}
				}

			}
			else {
				vectorCuerpo[0] = 1 + rand() % (6); //numrandom 1-6

			}
		}
	}

	bool logroAtajar(Jugador jug) {
		int tiro = jug.getPosicionTiro();
		for (int i = 0; i < numCuadros; i++) {
			if (vectorCuerpo[i] == tiro) {
				return true;
			}
		}
		return false;
	}
	short getNumCuadros() {
		return numCuadros;
	}

};
