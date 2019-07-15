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
	
	int speed = 1;

/*	int myMaxHP = 20;
	int myHP = myMaxHP;
	int eneMaxHP = 15;
	int eneHP = eneMaxHP;
	

	int myMaxDP = 20;
	int myDP = 0;
	int eneMaxDP = 15;
	int eneDP = 0;
	*/

void Roll(int judg,int Dice) //さいころ表示
{
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

void display() //画面初期化
{
	mvprintw(8, 30, "HP:%d/%d", p.HP, p.HP_MAX);
	mvprintw(9, 30, "DP:%d/%d", p.DP, p.DP_MAX);

	mvprintw(8, 80, "HP:%d/%d", monster[1].HP, monster[1].HP_MAX);
	mvprintw(9, 80, "DP:%d/%d", monster[1].DP, monster[1].DP_MAX);

	mvaddstr(6, 20, "You");
	mvprintw(6, 90, "%s", monster[1].monster_name);

	mvprintw(3, 10, "(S)speed ×%d",speed);
	if (autoMode) {
		mvaddstr(2, 10, "(A)Auto Mode : ON");
	}
	else {
		mvaddstr(2, 10, "(A)Auto Mode : OFF");
	}
	refresh();
}

void modeSwitch()//モード切替 
{
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
void speedSet()//速度切り替え
{	
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

			if (turn == 0) { // playerのターン
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

				myDice = 6;
				num = myDice;


				Roll(0, myDice);

				Sleep(1000 / speed);

				if (autoMode) {
					key = getch();

					if (key == 'a') {
						modeSwitch();
						erase();
						display();

						mvaddstr(7, 40, "Please push Z");
					}
					while (1) {
						choose = rand() % myDice + 1;
						if (p.m[choose - 1].DP_cons > 0 && p.DP < p.m[choose - 1].DP_cons) {
						}
						else {
							break;
						}
					}
					
				}
				else { 
					while (1) {
						attrset(COLOR_PAIR(0));
						for (int i = 1; i <= 6; i++) {
							if (i == choose) {
								attrset(COLOR_PAIR(1));
							}
							if (i > myDice) {
								attrset(COLOR_PAIR(2));
							}
							if (p.m[i - 1].DP_cons > 0 && p.DP < p.m[i - 1].DP_cons) {
								attrset(COLOR_PAIR(2));
							}
							mvprintw(22 + i, 8, "%d:%s", i, p.m[i-1].move_name);
							attrset(COLOR_PAIR(0));
						}
						refresh();

						key = getch();
						
						if (key == 's'&&!autoMode) {
							speedSet();
							erase();
							mvaddstr(7, 40, "Please push Z");
							for (int i = 1; i <= 6; i++) {
								if (i == choose) {
									attrset(COLOR_PAIR(1));
								}
								if (i > myDice) {
									attrset(COLOR_PAIR(2));
								}
								if (p.m[i - 1].DP_cons > 0 && p.DP < p.m[i - 1].DP_cons) {
									attrset(COLOR_PAIR(2));
								}
								mvprintw(22 + i, 8, "%d:%s", i, p.m[i - 1].move_name);
								attrset(COLOR_PAIR(0));
							}
							display();
							
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
							for (int i = choose+1; i <= 6; i++) {
								if (p.m[i - 1].DP_cons <= 0 || p.DP >= p.m[i - 1].DP_cons) {
									choose = i;
									break;
								}
							}
						}
						else if (key == KEY_UP && choose >= 2) {
							for (int i = choose-1; i >=1; i--) {
								if (p.m[i - 1].DP_cons <= 0 || p.DP >= p.m[i - 1].DP_cons) {
									choose = i;
									break;
								}
							}
						}
					}
					
				}
				erase();
				monster[1].HP -= p.m[choose - 1].att_point;
				p.DP -= p.m[choose - 1].DP_cons;
				if (p.DP > p.DP_MAX) {
					p.DP = p.DP_MAX;
				}

				mvprintw(7, 40, "%s", p.m[choose - 1].move_name);
				mvprintw(7, 90, "-%d", p.m[choose - 1].att_point);

				display();
				Sleep(2000 / speed);
				turn = 1;

			}
			else {// 相手のターン
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

				while (1) {
					choose = rand() % eneDice + 1;
					if (monster[1].m[choose - 1].DP_cons > 0 && monster[1].DP < p.m[choose - 1].DP_cons) {
					}
					else {
						break;
					}
				}
				

				p.HP -= monster[1].m[choose-1].att_point;
				monster[1].DP -= monster[1].m[choose - 1].DP_cons;
				if (monster[1].DP > monster[1].DP_MAX) {
					monster[1].DP = monster[1].DP_MAX;
				}
				erase();

				mvprintw(7, 40, "%s", monster[1].m[choose-1].move_name);

				mvprintw(7, 30, "-%d", monster[1].m[choose-1].att_point);

				

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

			if (p.HP <= 0) {
				erase();
				mvprintw(7, 40, "%s win", monster[1].monster_name);
				display();
				break;
			}else if (monster[1].HP <= 0) {
				erase();
				mvaddstr(7, 40, "Player win");
				display();
				break;
			}
		}
		while (1);
		break;
	}

}


