#pragma once
#include <iostream>
#include <Time.h>
#include <string>
#include "Arquero.h"

using namespace std;

class Arbitro {

private:
	short nroIntentos;
public:

	Arbitro() {
		nroIntentos = 5;
	}
	Arbitro(short intentos) {
		nroIntentos = intentos;
	}

	~Arbitro() {}
	void juegaUsuario(Jugador& jug, Arquero& arq) {
		jug.patear();
		if (!arq.logroAtajar(jug)) {
			cout << "GOL!" << endl;
			jug.nroGoles += 1;
		}
		else {
			cout << "Atajo" << endl;
			arq.nroAtajadas += 1;
		}
	}

	void juegaMaquina(Jugador& jug, Arquero& arq) {
		jug.setPosicionTiro(1 + rand() % (9));
		short tiro = jug.getPosicionTiro();
		cout << "Posicion de Tiro: " << tiro << endl;
		if (!arq.logroAtajar(jug)) {
			cout << "GOL!" << endl;
			jug.nroGoles += 1;
		}
		else {
			cout << "Atajo" << endl;
			arq.nroAtajadas += 1;
		}
	}



	void setNroIntentos(short num) {
		nroIntentos = num;
	}
	short getNroIntentos() {
		return nroIntentos;
	}
};



