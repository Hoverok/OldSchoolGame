#include "Logus.h"
#include "Langas.h"
#include <fstream>
#include <windows.h>
#include <iostream>
#include <iomanip>
HANDLE console1 = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

//architektura skaitoma is txt file
//gaunamas char
//pagal ji funkcijos tikrina ar gali pajudet kur zaidejas nori
Logus::Logus()
{//masyvai eina M[y][x]
	currK = { 1,22 }; //starting koordinate
	SetConsoleCursorPosition(console1, currK); //kur pradesim zaidyma
	ifstream reader("Solid.txt");
	for (int i = 0; i <24; i++) {
		for (int j = 0; j < 60; j++) {

			reader >> F[i][j];
		}
	}
	reader.close();
	// skaitau is failo i masyva zaidimo lauka struktura
	//# koordinate uzimta
	//- koordinate laisva
	u = 94, l = 60, r = 62, d = 118;  //zaidejo avataras ziuri i diff puses
	SetConsoleTextAttribute(console1, 112);  //spalva field
	cout << u;
	//F[bottomY-4][1];
	prize = 0;
	win = 0;
}


void Logus::set_move(char x) {
	move = x;
}



///****** TESTING STUFF********//////////
//Tikrina ar galima pereiti i sita vieta
void Logus::testing_wall() {   // movement w a s d
							   //resetinu b
	b = 0;         // kai nauja koordinate == #, b = 0;
	switch (move) {
	case 'w':       //tikrina masyve
		if (F[currK.Y - 1][currK.X] == '#') b = 0;
		else b = 1;
		break;
	case 'a':
		if (F[currK.Y][currK.X - 1] == '#') b = 0;
		else b = 1;
		break;
	case 's':
		if (F[currK.Y + 1][currK.X] == '#') b = 0;
		else b = 1;
		break;
	case 'd':
		if (F[currK.Y][currK.X + 1] == '#') b = 0;
		else b = 1;
		break;
	default:
		b = 0;
		break;
	}
}

void Logus::testing_prize() {   // movement w a s d
	if (b == 1) {


		switch (move) {
		case 'w':       //tikrina masyve
			if (F[currK.Y - 1][currK.X] == '$') prize = 1;
			else prize = 0;
			break;
		case 'a':
			if (F[currK.Y][currK.X - 1] == '$') prize = 1;
			else prize = 0;
			break;
		case 's':
			if (F[currK.Y + 1][currK.X] == '$') prize = 1;
			else prize = 0;
			break;
		case 'd':
			if (F[currK.Y][currK.X + 1] == '$') prize = 1;
			else prize = 0;
			break;
		default:
			prize = 0;
			break;
		}

	}

}




void Logus::testing_win() {  //tikrina ar pasiektas paskutine koordinate
	if (b == 1) {
		switch (move) {
		case 'w':       //tikrina masyve
			if (F[currK.Y - 1][currK.X] == '!') win = 1;
			else win = 0;
			break;
		case 'a':
			if (F[currK.Y][currK.X - 1] == '!') win = 1;
			else win = 0;
			break;
		case 's':
			if (F[currK.Y + 1][currK.X] == '!') win = 1;
			else win = 0;
			break;
		case 'd':
			if (F[currK.Y][currK.X + 1] == '!') win = 1;
			else win = 0;
			break;
		default:
			win = 0;
			break;
		}
	}

}

bool Logus::end_it() {  //jeigu pask koordinate pasiekta
	if (win == 1) {          //isvalo ekrana ir siuncia isejima is loopo maine
		SetConsoleTextAttribute(console1, 15);
		system("CLS");
		currK = { 14,12 };
		SetConsoleCursorPosition(console1, currK);
		SetConsoleTextAttribute(console1, 79);
		cout << "  THE END!\n";
	}
	return win;
}




//jeigu i pasirenkta vieta galima pereiti (b == 1), tai galima
//movement- istrina zaidejo avatara esamoje vietoje
//keicia current koordinates
//braizo zaidejo avatara naujoje vietoje
void Logus::movement() {
	if (b) {// judame ir atnaujiname avatara

		switch (move) {
		case 'w':
			SetConsoleCursorPosition(console1, currK);
			cout << ' '; // kur buvo - tuscias
			currK.Y--;  //x tas pats, judam i virsu
			SetConsoleCursorPosition(console1, currK);
			cout << u;
			break;
		case 'a':
			SetConsoleCursorPosition(console1, currK);
			cout << ' '; // kur buvo - tuscias
			currK.X--;  //y tas pats, judam i kaire
			SetConsoleCursorPosition(console1, currK);
			cout << l;
			break;
		case 's':
			SetConsoleCursorPosition(console1, currK);
			cout << ' '; // kur buvo - tuscias
			currK.Y++;
			SetConsoleCursorPosition(console1, currK);
			cout << d;
			break;
		case 'd':
			SetConsoleCursorPosition(console1, currK);
			cout << ' '; // kur ka tik buvo buvo - tuscias
			currK.X++;
			SetConsoleCursorPosition(console1, currK);
			cout << r; //kur dabar
			break;
		default:
			SetConsoleCursorPosition(console1, currK);
			break;
		}
		if (prize) { // jeigu $ buvo paimtas
			F[22][58] = '!';

			F[bottomY - 4][1] = '-';
			COORD T = { 58,22 };
			SetConsoleCursorPosition(console1, T); //cia darom isejima
			SetConsoleTextAttribute(console1, 159);
			cout << '!';
			SetConsoleCursorPosition(console1, currK);//resetinam cursor ir spalva
			SetConsoleTextAttribute(console1, 112);
			prize = 0; // kad tai ivyktu tik 1 karta
		}
	}

	else if (!b) {        // NEjudame,bet atnaujiname avatara
		switch (move) {
		case 'w':
			SetConsoleCursorPosition(console1, currK);
			cout << u;
			break;
		case 'a':
			SetConsoleCursorPosition(console1, currK);
			cout << l;
			break;
		case 's':
			SetConsoleCursorPosition(console1, currK);
			cout << d;
			break;
		case 'd':
			SetConsoleCursorPosition(console1, currK);
			cout << r;
			break;
		default:
			SetConsoleCursorPosition(console1, currK);
			break;
		}
	}

}

