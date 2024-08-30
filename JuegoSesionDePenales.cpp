#include <iostream>
#include <Time.h>
#include <string>
#include "Jugador.h"
#include "Arquero.h"
#include "Arbitro.h"
#include "Arco.h"

using namespace std;

int main() {
	srand(time(NULL));
	cout << "Juego de Penales" << endl;
	Jugador usuario;
	Jugador maquina;
	short op;
	do {
		cout << "Seleccione la dificultad" << endl;
		cout << "1. Facil" << endl;
		cout << "2. Medio" << endl;
		cout << "3. Dificil" << endl;
		cout << "Opcion: ";
		cin >> op;
		if (op < 1 || op>3)
			cout << "Opcion incorrecta, intente otra vez" << endl;
	} while (op < 1 || op>3);


	float altura = 0;
	switch (op) {
	case 1:
		altura = 0.7;
		cout << "===========" << endl;
		cout << "|| 7 8 9 ||" << endl;
		cout << "|| 4 5 6 ||" << endl;
		cout << "|| 1 x 3 ||" << endl;
		cout << "===========" << endl;
		break;

	case 2:
		altura = 1.6;
		cout << "===========" << endl;
		cout << "|| 7 8 9 ||" << endl;
		cout << "|| 4 x 6 ||" << endl;
		cout << "|| 1 x 3 ||" << endl;
		cout << "===========" << endl;
		break;

	case 3: 
		altura = 1.80;
		cout << "===========" << endl;
		cout << "|| 7 x 9 ||" << endl;
		cout << "|| 4 x 6 ||" << endl;
		cout << "|| 1 x 3 ||" << endl;
		cout << "===========" << endl;
		break;

	};
	Arquero arqueroUsuario(altura);
	Arquero arqueroMaquina(altura);
	Arbitro arbitro;
	Arco arco;

	int cont = 0;
	int limite = arbitro.getNroIntentos();
	while (true) {
		cont += 1;
		cout << "------------------" << endl;
		cout << "INTENTO Nro" << cont << endl;
		cout << "------------------" << endl;
		cout << "USUARIO" << endl;
		arqueroUsuario.defPosicionAtajada();
		arbitro.juegaUsuario(usuario, arqueroUsuario);
		arco.dibujarArco(usuario.getPosicionTiro(), arqueroUsuario);
		cout << "------------------" << endl;

		fflush(stdin);
		cout << "MAQUINA" << endl;
		arqueroMaquina.defPosicionAtajada();
		arbitro.juegaMaquina(maquina, arqueroMaquina);
		arco.dibujarArco(maquina.getPosicionTiro(), arqueroMaquina);


		if (cont == limite) {
			break;
		}
	}

	cout << endl;

	cout << "PUNTAJE TOTAL" << endl;
	cout << "Usuario-> " << usuario.nroGoles << endl;
	cout << "Maquina-> " << maquina.nroGoles << endl;

	cout << endl;
	if (usuario.nroGoles == maquina.nroGoles) {
		cout << "EMPATE, Iniciando tiros de muerte subita" << endl;
		/*Si después de los cinco tiros de cada equipo el marcador sigue empatado,
		se procederá a tiros de muerte súbita: En esta fase, se alternan los tiros
		entre equipos, y el primer equipo que anote y el otro falle, gana el partido.*/

		while (true) {
			usuario.nroGoles = 0;
			maquina.nroGoles = 0;
			cout << "==================" << endl;
			cout << "USUARIO" << endl;
			arqueroUsuario.defPosicionAtajada();
			arbitro.juegaUsuario(usuario, arqueroUsuario);
			arco.dibujarArco(usuario.getPosicionTiro(), arqueroUsuario);
			cout << "------------------" << endl;

			cout << "MAQUINA" << endl;
			arqueroMaquina.defPosicionAtajada();
			arbitro.juegaMaquina(maquina, arqueroMaquina);
			arco.dibujarArco(maquina.getPosicionTiro(), arqueroMaquina);
			

			if (usuario.nroGoles == 1 && maquina.nroGoles == 0) {
				cout << "Tu: " << usuario.nroGoles << endl;
				cout << "Maquina: " << maquina.nroGoles << endl;
				cout << "Por lo tanto ";
				cout << "** GANASTE! **" << endl;
				break;
			}
			else {
				if (usuario.nroGoles == 0 && maquina.nroGoles == 1) {
					cout << "Tu: " << usuario.nroGoles << endl;
					cout << "Maquina: " << maquina.nroGoles << endl;
					cout << "Por lo tanto ";
					cout << "** PERDISTE **" << endl;
					break;
				}
			}

		}

	}

	else {
		if (usuario.nroGoles > maquina.nroGoles)
			cout << "** GANASTE! **" << endl;
		else
			cout << "** PERDISTE **";
	}
	return 0;
}

