// myGame1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <curses.h>
#include "monster_data.h"

#define BUFFSIZE 1024

	int myDice = 1;
	int eneDice = 1;
	int key = 0;
	int turn = 0;

	bool autoMode = false;

	int choose = 1;

	int myMaxHP = 20;
	int myHP = myMaxHP;
	int eneMaxHP = 15;
	int eneHP = eneMaxHP;
	int speed = 1;

	int myMaxDP = 20;
	int myDP = 0;
	int eneMaxDP = 15;
	int eneDP = 0;

void Roll(int judg,int Dice) {
	if (judg == 0) {
		for (int j = 0; j <= 10; j++) {
			mvaddstr(j + 10, 30, "+");
			mvaddstr(j + 10, 40, "+");
		}
		for (int k = 0; k <= 10; k++) {
			mvaddstr(10, k + 30, "+");
			mvaddstr(20, k + 30, "+");
		}
		if (Dice == 1) {
			mvaddstr(15, 35, "*");
		}
		else if (Dice == 2) {
			mvaddstr(12, 38, "*");
			mvaddstr(18, 32, "*");
		}
		else if (Dice == 3) {
			mvaddstr(15, 35, "*");
			mvaddstr(12, 38, "*");
			mvaddstr(18, 32, "*");
		}
		else if (Dice == 4) {
			mvaddstr(18, 32, "*");
			mvaddstr(12, 38, "*");
			mvaddstr(18, 38, "*");
			mvaddstr(12, 32, "*");
		}
		else if (Dice == 5) {
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
	}
	else {
		for (int j = 0; j <= 10; j++) {
			mvaddstr(j + 10, 80, "+");
			mvaddstr(j + 10, 90, "+");
		}
		for (int k = 0; k <= 10; k++) {
			mvaddstr(10, k + 80, "+");
			mvaddstr(20, k + 80, "+");
		}
		if (Dice == 1) {
			mvaddstr(15, 85, "*");
		}
		else if (Dice == 2) {
			mvaddstr(12, 88, "*");
			mvaddstr(18, 82, "*");
		}
		else if (Dice == 3) {
			mvaddstr(15, 85, "*");
			mvaddstr(12, 88, "*");
			mvaddstr(18, 82, "*");
		}
		else if (Dice == 4) {
			mvaddstr(18, 82, "*");
			mvaddstr(12, 88, "*");
			mvaddstr(18, 88, "*");
			mvaddstr(12, 82, "*");
		}
		else if (Dice == 5) {
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
}

void display() {
	mvprintw(8, 30, "HP:%d/%d", myHP, myMaxHP);
	mvprintw(9, 30, "DP:%d/%d", myDP, myMaxDP);

	mvprintw(8, 80, "HP:%d/%d", eneHP, eneMaxHP);
	mvprintw(9, 80, "DP:%d/%d", eneDP, eneMaxDP);

	mvaddstr(6, 20, "You");
	mvprintw(6, 90, "%s", monster1.monster_name);

	mvprintw(3, 10, "(S)speed ×%d",speed);
	if (autoMode) {
		mvaddstr(2, 10, "(A)Auto Mode : ON");
	}
	else {
		mvaddstr(2, 10, "(A)Auto Mode : OFF");
	}
	refresh();
}

void modeSwitch() {
	if (autoMode) {
		autoMode = false;
		speed = 1;
		timeout(1);
	}
	else {
		autoMode = true;
		speed = 10;
		timeout(0);
	}
}
void speedSet() {
	speed = speed * 2;
	if (speed >= 8) {
		speed = 1;
	}
	erase();
	display();
	mvaddstr(7, 40, "Please push Z");
}

int main() {



	if (initscr() == NULL) {
		return 1;
	}

	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);


	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	timeout(0);


	while (1) {
		display();

		mvaddstr(7, 40, "Please push Z");

		while (1) {
			srand((unsigned)time(NULL));
			key = getch();

			if (key == 'a') {
				modeSwitch();
				if (autoMode) {
					break;
				}
			}
			else if (key == 's') {
				speedSet();
			}
			else if (key == 'z') {
				break;
			}
		}
		myDice = rand() % 6 + 1;

		Roll(0, myDice);

		srand((unsigned)time(NULL) + 1);

		while (1) {
			eneDice = rand() % 6 + 1;
			if (eneDice != myDice) {
				break;
			}
		}

		Roll(1, eneDice);

		if (myDice > eneDice) {
			turn = 0;
		}
		else {
			turn = 1;
		}

		Sleep(1000 / speed);

		while (1) {
			attrset(COLOR_PAIR(0));

			erase();

			display();
			srand((unsigned)time(NULL));

			if (turn == 0) {
				timeout(1);
				choose = 1;
				mvaddstr(7, 40, "your turn");
				refresh();
				Sleep(1000 / speed);

				erase();
				display();

				mvaddstr(7, 40, "Please push Z");
				refresh();
				while (1) {
					key = getch();

					myDice = rand() % 6 + 1;

					if (key == 's'&&!autoMode) {
						speedSet();
					}

					if (key == 'a') {
						modeSwitch();
						erase();
						display();
						mvaddstr(7, 40, "Please push Z");
					}

					if (autoMode) {
						timeout(0);
						break;
					}

					if (key == 'z') {
						break;
					}
				}



				Roll(0, myDice);

				Sleep(1000 / speed);
				if (autoMode) {
					choose = rand() % myDice + 1;
					key = getch();

					if (key == 'a') {
						modeSwitch();
						erase();
						display();

						mvaddstr(7, 40, "Please push Z");
					}
				}
				else {
					while (1) {
						for (int i = 1; i <= 6; i++) {
							attrset(COLOR_PAIR(0));
							if (i == choose) {
								attrset(COLOR_PAIR(1));
							}
							if (i > myDice) {
								attrset(COLOR_PAIR(2));
							}
							mvprintw(22 + i, 8, "%d.%s(%s)", i, monster1.m1.move_name, monster1.m1.move_exp);
						}
						refresh();

						key = getch();
						
						if (key == 's'&&!autoMode) {
							speedSet();
							attrset(COLOR_PAIR(0));
							erase();
							display();
							mvaddstr(7, 40, "Please push Z");
							Roll(0, myDice);
						}

						if (key == 'a') {
							modeSwitch();
							if (autoMode) {
								attrset(COLOR_PAIR(0));
								erase();
								display();
								mvaddstr(7, 40, "Please push Z");
								Roll(0, myDice);
								break;
							}
						}

						if (key == 'z') {
							break;
						}

						if (key == KEY_DOWN && choose <= 5 && choose < myDice) {
							choose++;
						}
						else if (key == KEY_UP && choose >= 2) {
							choose--;
						}
					}
				}
				turn = 1;

			}
			else {
				mvaddstr(7, 40, "enemy turn");
				refresh();
				Sleep(1000 / speed);

				key = getch();

				if (key == 'a') {
					modeSwitch();
				}
				if (key == 's'&&!autoMode) {
					speedSet();
				}

				erase();
				display();

				eneDice = rand() % 6 + 1;

				Roll(1, eneDice);

				Sleep(1000 / speed);

				key = getch();

				if (key == 'a') {
					modeSwitch();
				}
				if (key == 's'&&!autoMode) {
					speedSet();
				}

				choose = rand() % eneDice + 1;

				num = eneDice;

				myHP -= monster1.m4.att_point;

				erase();

				mvprintw(7, 40, "%s", monster1.m4.move_name);

				mvprintw(7, 30, "-%d", monster1.m4.att_point);

				display();

				Sleep(2000 / speed);

				key = getch();

				if (key == 'a') {
					modeSwitch();
				}
				if (key == 's'&&!autoMode) {
					speedSet();
				}

				turn = 0;
			}

			if (myHP <= 0) {
				erase();
				mvprintw(7, 40, "%s win", monster1.monster_name);
				display();
				break;
			}
		}
		while (1);
		break;
	}

}


