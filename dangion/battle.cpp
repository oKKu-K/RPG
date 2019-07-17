
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <curses.h>
#include "monster_data.h"
#include "battle.h"

#define BUFFSIZE 1024



bool autoMode = false;

int number=0;


int speed = 1;


void Roll(int judg, int Dice) //さいころ表示
{
	attrset(COLOR_PAIR(3));
	for (int j = 0; j <= 10; j++) {
		for (int k = 0; k <= 10; k++) {
			mvaddstr(j + 10, 30 + k + judg * 50, " ");
		}
	}
	if (Dice == 1) {
		attrset(COLOR_PAIR(4));
		mvaddstr(15, 35 + judg * 50, "*");
	}
	else if (Dice == 2) {
		mvaddstr(12, 38 + judg * 50, "*");
		mvaddstr(18, 32 + judg * 50, "*");
	}
	else if (Dice == 3) {
		mvaddstr(15, 35 + judg * 50, "*");
		mvaddstr(12, 38 + judg * 50, "*");
		mvaddstr(18, 32 + judg * 50, "*");
	}
	else if (Dice == 4) {
		mvaddstr(18, 32 + judg * 50, "*");
		mvaddstr(12, 38 + judg * 50, "*");
		mvaddstr(18, 38 + judg * 50, "*");
		mvaddstr(12, 32 + judg * 50, "*");
	}
	else if (Dice == 5) {
		mvaddstr(15, 35 + judg * 50, "*");
		mvaddstr(18, 32 + judg * 50, "*");
		mvaddstr(12, 38 + judg * 50, "*");
		mvaddstr(18, 38 + judg * 50, "*");
		mvaddstr(12, 32 + judg * 50, "*");
	}
	else {
		mvaddstr(15, 38 + judg * 50, "*");
		mvaddstr(15, 32 + judg * 50, "*");
		mvaddstr(18, 32 + judg * 50, "*");
		mvaddstr(12, 38 + judg * 50, "*");
		mvaddstr(18, 38 + judg * 50, "*");
		mvaddstr(12, 32 + judg * 50, "*");
	}

	refresh();
	attrset(COLOR_PAIR(0));
}

void display() //画面初期化
{
	mvprintw(8, 30, "HP:%d/%d", p.HP, p.HP_MAX);
	mvprintw(9, 30, "DP:%d/%d", p.DP, p.DP_MAX);

	mvprintw(8, 80, "HP:%d/%d", monster[number].HP, monster[number].HP_MAX);
	mvprintw(9, 80, "DP:%d/%d", monster[number].DP, monster[number].DP_MAX);

	mvaddstr(6, 20, "You");
	mvprintw(6, 90, "%s", monster[number].monster_name);

	mvprintw(3, 10, "(S)speed ×%d", speed);
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

void Battle(int mnumber) {
	int upLv = 0;
	int myDice = 1;
	int eneDice = 1;
	int key = 0;
	int turn = 0;

	int choose = 1;

	initscr();
	number = mnumber;

	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_RED, COLOR_WHITE);


	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	timeout(0);


	
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

					if (key == 's' && !autoMode) {
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

				if (autoMode) {//Autoモード
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
					while (1) {//技選択
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
							mvprintw(22 + i, 8, "%d:%s", i, p.m[i - 1].move_name);
							attrset(COLOR_PAIR(0));
						}
						refresh();

						key = getch();

						if (key == 's' && !autoMode) {//スピード変更
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

						if (key == 'a') {//モード切替
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

						if (key == 'z') {//技選択終了
							break;
						}


						if (key == KEY_DOWN && choose <= 5 && choose < myDice) {
							for (int i = choose + 1; i <= 6; i++) {
								if (p.m[i - 1].DP_cons <= 0 || p.DP >= p.m[i - 1].DP_cons) {
									choose = i;
									break;
								}
							}
						}
						else if (key == KEY_UP && choose >= 2) {
							for (int i = choose - 1; i >= 1; i--) {
								if (p.m[i - 1].DP_cons <= 0 || p.DP >= p.m[i - 1].DP_cons) {
									choose = i;
									break;
								}
							}
						}
					}

				}
				erase();
				monster[mnumber].HP -= p.m[choose - 1].att_point;
				p.DP -= p.m[choose - 1].DP_cons;
				if (p.DP > p.DP_MAX) {
					p.DP = p.DP_MAX;
				}
				if (monster[mnumber].HP < 0) {
					monster[mnumber].HP = 0;
				}

				mvprintw(7, 40, "%s", p.m[choose - 1].move_name);
				mvprintw(7, 80, "-%d", p.m[choose - 1].att_point);

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
				if (key == 's' && !autoMode) {
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
				if (key == 's' && !autoMode) {
					speedSet();
				}

				while (1) {
					choose = rand() % eneDice + 1;
					if (monster[mnumber].m[choose - 1].DP_cons <= 0 || monster[mnumber].DP >= monster[mnumber].m[choose - 1].DP_cons) {
						break;
					}
				}


				p.HP -= monster[mnumber].m[choose - 1].att_point;
				monster[mnumber].DP -= monster[mnumber].m[choose - 1].DP_cons;
				if (monster[mnumber].DP > monster[mnumber].DP_MAX) {
					monster[mnumber].DP = monster[mnumber].DP_MAX;
				}
				if (p.HP < 0) {
					p.HP = 0;
				}
				erase();

				mvprintw(7, 40, "%s", monster[mnumber].m[choose - 1].move_name);

				mvprintw(7, 30, "-%d", monster[mnumber].m[choose - 1].att_point);



				display();

				Sleep(2000 / speed);

				key = getch();

				if (key == 'a') {
					modeSwitch();
				}
				if (key == 's' && !autoMode) {
					speedSet();
				}

				turn = 0;
			}

			if (p.HP <= 0) {
				erase();
				mvprintw(7, 40, "%s win", monster[mnumber].monster_name);
				display();
				Sleep(2000);
				monster[mnumber].HP = monster[mnumber].HP_MAX;
				if (autoMode) {
					modeSwitch();
				}
				return;
			}
			else if (monster[mnumber].HP <= 0) {
				erase();
				mvaddstr(6, 40, "Player win");
				mvprintw(7, 40, "%dExp, %dgold GET", monster[mnumber].exp, monster[mnumber].gold);
				display();
				Sleep(3000);
				p.exp += monster[mnumber].exp;
				p.gold += monster[mnumber].gold;

				while (1) {
					if (p.exp >= p.max_exp) {
						p.exp -= p.max_exp;
						p.max_exp += p.HP_MAX / 2;
						p.HP_MAX++;
						p.HP++;
						p.DP_MAX++;
						p.DP++;

						erase();
						upLv++;
						mvprintw(7, 40, "%dLevel UP", upLv);
						display();

						Sleep(4000);
					}
					else {
						break;
					}
				}

				erase();
				display();

				mvaddstr(7, 40, "Please push Z");
				refresh();
				timeout(1);

				while (1) {
					key = getch();

					myDice = rand() % 6 + 1;

					if (key == 'z') {
						break;
					}
				}

				Roll(0, myDice);
				choose = 1;
				mvaddstr(7, 40, "Please push Z (選ばないときはN)");
				while (1) {
					attrset(COLOR_PAIR(0));
					for (int i = 1; i <= 6; i++) {
						if (i == choose) {
							attrset(COLOR_PAIR(1));
						}
						if (i > myDice) {
							attrset(COLOR_PAIR(2));
						}
						
						mvprintw(22 + i, 8, "%d:%s", i, monster[mnumber].m[i - 1].move_name);
						attrset(COLOR_PAIR(0));
					}
					refresh();

					key = getch();

					if (key == 'z'||key == 'n') {
						break;
					}


					if (key == KEY_DOWN && choose <= 5 && choose < myDice) {
						choose++;
					}
					else if (key == KEY_UP && choose >= 2) {
								choose--;
					}
				}
				erase();
				display();
				if (key == 'z') {
					p.m[choose - 1] = monster[mnumber].m[choose - 1];
					mvprintw(7, 40, "%s GET", monster[mnumber].m[choose - 1].move_name);
				}
				else {
					mvaddstr(7, 40, "何も選ばなかった");
				}
				refresh();
				monster[mnumber].HP = monster[mnumber].HP_MAX;
				if (autoMode) {
					modeSwitch();
				}
				Sleep(3000);
				
				return;
			}
		}
	return;
}


