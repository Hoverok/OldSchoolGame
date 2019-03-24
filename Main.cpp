#include <iostream>
#include <windows.h>  
#include <bitset>     
#include <iomanip>
#include <string>
#include "Langas.h"
#include "Logus.h"
#include "Enemies.h"
#include <fstream>
#include <conio.h>
using namespace std;

//paslepti cursor
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}



int main() {
	unsigned char c; //skaito key presses
	bool done;       // iseiti is main loopo
	hidecursor();     //slepti cursor
	Langas GameField; 
	GameField.piesti_langa();  //piesa tuscia kitos spalovs langa
	GameField.piesti_remeli(); //remelis aplink lango
	GameField.index();         // legendos paaiskinimas
	GameField.piesti_vert();   //piesa vertikalios linijos viduje
	GameField.piesti_hor();    //piesa hor linijos viduje
	GameField.piesti_blokus(); // piesas blokus
	GameField.piesti_prize();  //piesa rakta
	Logus log1;
	Enemies en1;
	while (c = _getch()) { // skaito key paspaudymus ir iraso i c
		log1.set_move(c);  // siuncia key press'a i klasse
		log1.testing_wall(); //tikrina ar galima ten pajudet
		log1.testing_prize();
		log1.testing_win();
		done = log1.end_it();//jei galas pasiektas, grazina true
		log1.movement(); //pats judejimas
		//en1.movlines();  neveikia =DD
		if (done) break;
	}
	cin.ignore();
}