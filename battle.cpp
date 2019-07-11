// myGame1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <curses.h>

#define BUFFSIZE 1024


int main() {
	int myDice = 1;
	int eneDice = 1;
	int key = 0;
	int turn = 0;

	int myMaxHP = 20;
	int myHP = myMaxHP;
	int eneMaxHP = 15;
	int eneHP = eneMaxHP;

	int myMaxDP = 20;
	int myDP = 0;
	int eneMaxDP = 15;
	int eneDP = 0;


	int myAttack = 3;
	int eneAttack = 2;

	if (initscr() == NULL) {
		return 1;
	}

	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);


	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	timeout(0);


	while (1) {
		mvprintw(8, 30, "HP:%d/%d", myHP, myMaxHP);
		mvprintw(9, 30, "DP:%d/%d", myDP, myMaxDP);

		mvprintw(8, 80, "HP:%d/%d", eneHP, eneMaxHP);
		mvprintw(9, 80, "DP:%d/%d", eneDP, eneMaxDP);

		mvaddstr(7, 40, "Please push A");

		srand((unsigned)time(NULL));
		key = getch();
		if (key == 'a') {
			myDice = rand() % 6 + 1;
			for (int j = 0; j <= 10; j++) {
				mvaddstr(j + 10, 30, "+");
				mvaddstr(j + 10, 40, "+");
			}
			for (int k = 0; k <= 10; k++) {
				mvaddstr(10, k + 30, "+");
				mvaddstr(20, k + 30, "+");
			}
			if (myDice == 1) {
				mvaddstr(15, 35, "*");
			}
			else if (myDice == 2) {
				mvaddstr(12, 38, "*");
				mvaddstr(18, 32, "*");
			}
			else if (myDice == 3) {
				mvaddstr(15, 35, "*");
				mvaddstr(12, 38, "*");
				mvaddstr(18, 32, "*");
			}
			else if (myDice == 4) {
				mvaddstr(18, 32, "*");
				mvaddstr(12, 38, "*");
				mvaddstr(18, 38, "*");
				mvaddstr(12, 32, "*");
			}
			else if (myDice == 5) {
				mvaddstr(15, 35, "*");
				mvaddstr(18, 32, "*");
				mvaddstr(12, 38, "*");
				mvaddstr(18, 38, "*");
				mvaddstr(12, 32, "*");
			}
			else {
				mvaddstr(15, 38, "*");
				mvaddstr(15, 32, "*");
				mvaddstr(18, 32, "*");
				mvaddstr(12, 38, "*");
				mvaddstr(18, 38, "*");
				mvaddstr(12, 32, "*");
			}
			refresh();

			srand((unsigned)time(NULL) + 1);
			while (1) {
				eneDice = rand() % 6 + 1;
				if (eneDice != myDice) {
					break;
				}
			}
			for (int j = 0; j <= 10; j++) {
				mvaddstr(j + 10, 80, "+");
				mvaddstr(j + 10, 90, "+");
			}
			for (int k = 0; k <= 10; k++) {
				mvaddstr(10, k + 80, "+");
				mvaddstr(20, k + 80, "+");
			}
			if (eneDice == 1) {
				mvaddstr(15, 85, "*");
			}
			else if (eneDice == 2) {
				mvaddstr(12, 88, "*");
				mvaddstr(18, 82, "*");
			}
			else if (eneDice == 3) {
				mvaddstr(15, 85, "*");
				mvaddstr(12, 88, "*");
				mvaddstr(18, 82, "*");
			}
			else if (eneDice == 4) {
				mvaddstr(18, 82, "*");
				mvaddstr(12, 88, "*");
				mvaddstr(18, 88, "*");
				mvaddstr(12, 82, "*");
			}
			else if (eneDice == 5) {
				mvaddstr(15, 85, "*");
				mvaddstr(18, 82, "*");
				mvaddstr(12, 88, "*");
				mvaddstr(18, 88, "*");
				mvaddstr(12, 82, "*");
			}
			else {
				mvaddstr(15, 88, "*");
				mvaddstr(15, 82, "*");
				mvaddstr(18, 82, "*");
				mvaddstr(12, 88, "*");
				mvaddstr(18, 88, "*");
				mvaddstr(12, 82, "*");
			}
			refresh();
			if (myDice > eneDice) {
				mvaddstr(7, 40, "your turn    ");
				turn = 0;
			}
			else {
				mvaddstr(7, 40, "enemy turn    ");
				turn = 1;
			}
			refresh();
			Sleep(2000);
			erase();
			mvprintw(8, 30, "HP:%d/%d", myHP, myMaxHP);
			mvprintw(9, 30, "DP:%d/%d", myDP, myMaxDP);

			mvprintw(8, 80, "HP:%d/%d", eneHP, eneMaxHP);
			mvprintw(9, 80, "DP:%d/%d", eneDP, eneMaxDP);

			srand((unsigned)time(NULL));
			if (turn == 0) {
				mvaddstr(7, 40, "Please push A");
				while (1) {
					key = getch();
					if (key == 'a') {
						break;
					}
				}

				myDice = rand();

				for (int j = 0; j <= 10; j++) {
					mvaddstr(j + 10, 30, "+");
					mvaddstr(j + 10, 40, "+");
				}
				for (int k = 0; k <= 10; k++) {
					mvaddstr(10, k + 30, "+");
					mvaddstr(20, k + 30, "+");
				}
				if (myDice == 1) {
					mvaddstr(15, 35, "*");
				}
				else if (myDice == 2) {
					mvaddstr(12, 38, "*");
					mvaddstr(18, 32, "*");
				}
				else if (myDice == 3) {
					mvaddstr(15, 35, "*");
					mvaddstr(12, 38, "*");
					mvaddstr(18, 32, "*");
				}
				else if (myDice == 4) {
					mvaddstr(18, 32, "*");
					mvaddstr(12, 38, "*");
					mvaddstr(18, 38, "*");
					mvaddstr(12, 32, "*");
				}
				else if (myDice == 5) {
					mvaddstr(15, 35, "*");
					mvaddstr(18, 32, "*");
					mvaddstr(12, 38, "*");
					mvaddstr(18, 38, "*");
					mvaddstr(12, 32, "*");
				}
				else {
					mvaddstr(15, 38, "*");
					mvaddstr(15, 32, "*");
					mvaddstr(18, 32, "*");
					mvaddstr(12, 38, "*");
					mvaddstr(18, 38, "*");
					mvaddstr(12, 32, "*");
				}
				refresh();

				int choose;
				
				choose = 1;

				timeout(1);

				while (1) {
					attrset(COLOR_PAIR(0));
					for (int i = 1; i <= 6; i++) {
						attrset(COLOR_PAIR(0));
						if (i == choose) {
							attrset(COLOR_PAIR(1));
						}
						mvprintw(22+i, 8 , "%d.", i);
					}
					refresh();
					
					key = getch();

					if (key == 'a') {
						break;
					}

					if (key == KEY_DOWN&&choose <= 5) {
						choose++;
					}
					else if (key == KEY_UP&&choose >= 2) {
						choose--;
					}

					
				}



			}
			else {
				eneDice = rand() % 6 + 1;

				for (int j = 0; j <= 10; j++) {
					mvaddstr(j + 10, 80, "+");
					mvaddstr(j + 10, 90, "+");
				}
				for (int k = 0; k <= 10; k++) {
					mvaddstr(10, k + 80, "+");
					mvaddstr(20, k + 80, "+");
				}
				if (eneDice == 1) {
					mvaddstr(15, 85, "*");
				}
				else if (eneDice == 2) {
					mvaddstr(12, 88, "*");
					mvaddstr(18, 82, "*");
				}
				else if (eneDice == 3) {
					mvaddstr(15, 85, "*");
					mvaddstr(12, 88, "*");
					mvaddstr(18, 82, "*");
				}
				else if (eneDice == 4) {
					mvaddstr(18, 82, "*");
					mvaddstr(12, 88, "*");
					mvaddstr(18, 88, "*");
					mvaddstr(12, 82, "*");
				}
				else if (eneDice == 5) {
					mvaddstr(15, 85, "*");
					mvaddstr(18, 82, "*");
					mvaddstr(12, 88, "*");
					mvaddstr(18, 88, "*");
					mvaddstr(12, 82, "*");
				}
				else {
					mvaddstr(15, 88, "*");
					mvaddstr(15, 82, "*");
					mvaddstr(18, 82, "*");
					mvaddstr(12, 88, "*");
					mvaddstr(18, 88, "*");
					mvaddstr(12, 82, "*");
				}
				refresh();
			}

			while (1);
			break;
		}

	}
}