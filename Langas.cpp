#include "Langas.h"
#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//logikos Langas klaseje nera, tik visuals
Langas::Langas() //nesikeis
{
	xkoord = 1;    // kiek tarpu is desines iki lango
	ykoord = 0;    // kol kas neturi reiksmes programai
	koordtop = 1;  // kiek tarpu is virsaus iki lango
	koord1 = { xkoord,ykoord };
	spalva = 112;
	SetConsoleTextAttribute(console, spalva);
	//tl- top left kampas, br- bottom right, hor- horizantali linija, diaR-diag linija su issakojimu i RIGHT
	tl2 = 201, tr2 = 187, bl2 = 200, br2 = 188, hor2 = 205, diag2 = 186;  // isorines sienos, ascII kodas
	tl1 = 218, tr1 = 191, bl1 = 192, br1 = 217, hor1 = 196, diag1 = 179, diagL = 180, diagR = 195, horU = 193, horD = 194, cross = 197, fb = 254;  // vidinies linijos, ascII
	bottomY = 22, rightX = 58;  // atstumai iki lango paskutiniu eiluciu/stulpeliu
}

void Langas::piesti_langa() {

	xkoord = 58;   //kiek columns bus lange
	ykoord = 22;   //kiek rows bus lange
				   // pildom visa 120 x 45 langa, paliksiu vietos remeliui
	for (int y = 0; y < ykoord; y++)  // ykoord rows
	{
		koord1.Y = koordtop + y;       //pradeda piesti nuo koordtop, ykoord kartu(rows)
		SetConsoleCursorPosition(console, koord1);
		cout << std::setw(xkoord) << ' ';  // kiekviena row fillina su xkoord kiekiu tarpu
	}

}
short Langas::get_bottomY() {  //prireiks vaiku funkcijose
	return bottomY;
}

short Langas::get_rightX() {   //prireiks vaiku funkcijose
	return rightX;
}


void Langas::index() {
	x = 0;
	y = bottomY + 2;
	ko = { x,y };
	SetConsoleCursorPosition(console, ko);
	
		
			

				SetConsoleTextAttribute(console, 94);
				cout << "$ key";

				SetConsoleTextAttribute(console, 31);
				cout << "! exit";

				SetConsoleTextAttribute(console, 41);
				cout << "w up";

				SetConsoleTextAttribute(console, 75);
				cout <<"s down" ;

				SetConsoleTextAttribute(console, 15);
				cout << "a left";

				SetConsoleTextAttribute(console, 207);
				cout << "d right" ;

				SetConsoleTextAttribute(console, 15);
				
}

//piesa remeli aplink lango
void Langas::piesti_remeli() {

	SetConsoleTextAttribute(console, 63); // remelis tures kita spalva

	COORD tempkoord2;         // kad piesti 2 linijas iskart o ne po 1             
	COORD tempkoord = { 0, 0 }; //top left kampas
	SetConsoleCursorPosition(console, tempkoord);
	cout << tl2;

	tempkoord = { rightX + 1, 0 }; //top right kampas
	SetConsoleCursorPosition(console, tempkoord);
	cout << tr2;

	tempkoord = { rightX + 1, bottomY + 1 }; //bottom right kampas
	SetConsoleCursorPosition(console, tempkoord);
	cout << br2;

	tempkoord = { 0, bottomY + 1 }; //bottom left kampas
	SetConsoleCursorPosition(console, tempkoord);
	cout << bl2;

	//horizantalios linijos
	tempkoord = { 1,0 };   // top left kampas.X+1
	tempkoord2 = { 1,bottomY + 1 }; // bottom left kampas.X+1
	SetConsoleCursorPosition(console, tempkoord); // nuo top left iki top right horiz linija
	for (int i = 0; i < 58; i++) cout << hor2;
	SetConsoleCursorPosition(console, tempkoord2); // nuo bottom left iki bottom right horiz linija
	for (int i = 0; i < 58; i++) cout << hor2;

	//vertikalios linijos
	tempkoord = { 0,1 }; // top left kampas.Y+1
	tempkoord2 = { rightX + 1,1 }; //top right kampas.Y+1
	for (int i = 0; i < 22; ++i) {
		tempkoord.Y = koordtop + i;   // koordtop- kiek tarpu iki lango
		tempkoord2.Y = koordtop + i;  // braizys iskart 2
		SetConsoleCursorPosition(console, tempkoord);  // braizom vert kaire linija
		cout << diag2;
		SetConsoleCursorPosition(console, tempkoord2);  // braizom vert kaire linija
		cout << diag2;
	}
}


//map vertikalios sienos viduje
//ilgas makaronas
void Langas::piesti_vert() {
	SetConsoleTextAttribute(console, 63);
	x = 4;
	y = bottomY + 1;
	ko = { x,y };
	for (int i = 0; i < 2; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.Y -= 2;
	SetConsoleCursorPosition(console, ko);
	cout << br1; //!!!!!!!!!!!!!!!

	for (int i = 0; i < 8; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}
	ko.Y--;
	SetConsoleCursorPosition(console, ko);
	cout << diagR; //!!!!!!!!!!!!!!!!!!!!
	ko.X++;
	SetConsoleCursorPosition(console, ko);
	cout << hor1;

	ko.X--;
	for (int i = 0; i < 8; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.X = 6;
	ko.Y = bottomY + 1;
	for (int i = 0; i < 8; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.Y -= 2;
	SetConsoleCursorPosition(console, ko);
	cout << bl1;

	ko.Y--;
	SetConsoleCursorPosition(console, ko);
	cout << diag1;
	ko.Y--;
	SetConsoleCursorPosition(console, ko);
	cout << diag1;

	ko.Y--;
	SetConsoleCursorPosition(console, ko);
	cout << diagL;

	for (int i = 0; i < 7; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.X += 4;
	ko.Y = bottomY;

	for (int i = 0; i < 2; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.Y -= 2;
	SetConsoleCursorPosition(console, ko);
	cout << diag1;

	ko.Y--;
	for (int i = 0; i < 3; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.X += 4;
	ko.Y = bottomY + 1;
	for (int i = 0; i < 7; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.Y--;
	SetConsoleCursorPosition(console, ko);
	cout << tl1;

	ko.Y -= 2;
	ko.X += 9;
	SetConsoleCursorPosition(console, ko);
	cout << br1;

	for (int i = 0; i < 12; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.Y = 0;
	ko.X += 14;
	for (int i = 0; i < 6; i++) {
		++ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.Y += 2;
	SetConsoleCursorPosition(console, ko);
	cout << tl1;

	for (int i = 0; i < 5; i++) {
		++ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.Y++;

	SetConsoleCursorPosition(console, ko);
	cout << cross;

	for (int i = 0; i < 6; i++) {
		++ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.Y += 2;
	SetConsoleCursorPosition(console, ko);
	cout << diagR;

	ko.X += 2;
	SetConsoleCursorPosition(console, ko);
	cout << br1;

	ko.Y--;
	SetConsoleCursorPosition(console, ko);
	cout << diag1;

	ko.Y--;
	SetConsoleCursorPosition(console, ko);
	cout << tl1;

	ko.X += 8;
	SetConsoleCursorPosition(console, ko);
	cout << br1;

	for (int i = 0; i < 5; i++) {
		--ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}

	ko.Y--;

	SetConsoleCursorPosition(console, ko);
	cout << tr1;

	ko.X += 8;
	ko.Y -= 2;

	for (int i = 0; i < 9; i++) {
		++ko.Y;
		SetConsoleCursorPosition(console, ko);
		cout << diag1;
	}
	ko.Y++;
	SetConsoleCursorPosition(console, ko);
	cout << br1;

	ko.Y = bottomY - 8;
	ko.X = 21;
	SetConsoleCursorPosition(console, ko);
	cout << diag1;


	SetConsoleTextAttribute(console, 15);
}

/*** piest_vert pabaiga ***/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*** piest_hor ***/

void Langas::piesti_hor() {
	SetConsoleTextAttribute(console, 63);
	x = 0;
	y = bottomY - 3;
	ko = { x, y };

	for (int i = 0; i < 3; i++) {
		++ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << hor1;
	}

	ko.X += 3;
	ko.Y -= 6;

	for (int i = 0; i < 3; i++) {
		++ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << hor1;
	}

	ko.X++;
	SetConsoleCursorPosition(console, ko);
	cout << horD;

	for (int i = 0; i < 10; i++) {
		++ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << hor1;
	}

	ko.X++;
	SetConsoleCursorPosition(console, ko);
	cout << horD;

	ko.X += 4;
	ko.Y += 1;
	SetConsoleCursorPosition(console, ko);
	cout << tl1;

	for (int i = 0; i < 11; i++) {
		++ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << hor1;
	}


	ko.X++;
	ko.Y -= 6;
	for (int i = 0; i < 18; i++) {
		++ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << hor1;
	}

	ko.Y = bottomY;
	for (int i = 0; i < 6; i++) {
		--ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << hor1;
	}

	ko.X--;
	SetConsoleCursorPosition(console, ko);
	cout << tl1;

	ko.X--;
	ko.Y -= 2;
	for (int i = 0; i < 7; i++) {
		--ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << hor1;
	}

	ko.Y -= 6;
	ko.X--;
	for (int i = 0; i < 7; i++) {
		++ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << hor1;
	}

	ko.X -= 26;
	ko.Y++;

	for (int i = 0; i < 5; i++) {
		--ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << hor1;
	}

	ko.X += 6;
	SetConsoleCursorPosition(console, ko);
	cout << horU;


	ko.X = 38;
	ko.Y = bottomY;
	SetConsoleCursorPosition(console, ko);
	cout << hor1;
}


/*** piest_hor pabaiga ***/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*** piest_blokus ***/

void Langas::piesti_blokus() {
	ko.X = 22;
	ko.Y = bottomY - 8;
	for (int i = 0; i < 6; i++)  // ykoord rows
	{
		ko.Y++;       //pradeda piesti nuo koordtop, ykoord kartu(rows)
		SetConsoleCursorPosition(console, ko);
		for (int j = 0; j < 4; j++) {
			cout << fb;
		}
	}

	ko.X = 58;
	ko.Y = bottomY + 1;
	for (int i = 0; i < 11; i++)  // ykoord rows
	{
		ko.Y--;       //pradeda piesti nuo koordtop, ykoord kartu(rows)
		SetConsoleCursorPosition(console, ko);
		cout << fb;
	}

	ko.Y -= 3;
	ko.X--;
	for (int i = 0; i < 8; i++)  // ykoord rows
	{
		ko.Y--;      //pradeda piesti nuo koordtop, ykoord kartu(rows)

		SetConsoleCursorPosition(console, ko);
		for (int j = 0; j < 2; j++) {
			cout << fb;
		}
	}

	ko.X = 52;
	for (int i = 0; i < 4; i++) {
		--ko.X;
		SetConsoleCursorPosition(console, ko);
		cout << fb;
	}

	ko.Y += 1;
	for (int i = 0; i < 5; i++)  // ykoord rows
	{
		ko.Y++;      //pradeda piesti nuo koordtop, ykoord kartu(rows)

		SetConsoleCursorPosition(console, ko);
		for (int j = 0; j < 4; j++) {
			cout << fb;
		}
	}

	ko.X -= 3;
	ko.Y++;
	for (int i = 0; i < 5; i++)  // ykoord rows
	{
		ko.Y--;      //pradeda piesti nuo koordtop, ykoord kartu(rows)

		SetConsoleCursorPosition(console, ko);
		for (int j = 0; j < 2; j++) {
			cout << fb;
		}
	}

	ko.Y -= 2;
	ko.X--;
	for (int i = 0; i < 2; i++) {
		ko.X++;
		SetConsoleCursorPosition(console, ko);
		cout << fb;
	}

	ko.X = 26;
	SetConsoleCursorPosition(console, ko);
	cout << fb;

	ko.Y++;
	ko.X++;
	for (int i = 0; i < 2; i++) {
		ko.X--;
		SetConsoleCursorPosition(console, ko);
		cout << fb;
	}
}

void Langas::piesti_prize() {  // piesa rakta 
	unsigned char dolla = 36;
	ko = { 1,bottomY - 4 };
	SetConsoleCursorPosition(console, ko);
	SetConsoleTextAttribute(console, 94);
	cout << dolla;
	SetConsoleTextAttribute(console, 112);
}