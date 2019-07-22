#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>
#include<Windows.h>
#include "battle.h"
#include<time.h>
#include"dangion.h"
#include "monster_data.h"
int x = 120;
int y = 30;
char ab[300][300];
void block1(int a, int b, int c, int d);
void tate(int a, int b, int ichi);
void yoko(int a, int b, int ichi);
void create(int dangion_number);

void dangion(int dangions)
{

	player_data();
	
	// èâä˙âª
	int a = 0;  
	int b = 0;
	int px = 60;
	int py = 15;
	int j;
	int i;
	int key;
	int hantei = 0;
	
	initscr();
	
	noecho();
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_WHITE);
	
	init_pair(7, COLOR_BLACK, COLOR_RED);
	
	cbreak();
	
	keypad(stdscr, TRUE);
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			ab[i][j] = '#';
		}
	}
    if (dangions == 1) {
	    create(1);
	}
	else if (dangions == 2) {
		create(2);
    }
	else if (dangions == 3) {
		create(3);
	}
	int count = 0;
	while (true) {
		start_color();

		init_pair(5, COLOR_YELLOW, COLOR_BLACK);
		init_pair(6, COLOR_GREEN, COLOR_WHITE);

		init_pair(7, COLOR_BLACK, COLOR_RED);


		erase();
		attrset(COLOR_PAIR(4+dangions));
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 120; j++) {
				
				mvaddch(i, j, ab[i - a][j - b]);
				
					
					
				
			}
		}




		mvprintw(15, 60, "@");
		mvprintw(0, 0, "ÉzÅ[ÉÄâÊñ :B");
		key = getch();

		srand((unsigned)time(NULL));

		int random = 0;
		
		int mnumber = 0;
		
		switch (key) {
		case KEY_UP:
			if (dangions == 1) {
				if (py == 230 && (150 < px && 170 > px)) {
					erase();
					Battle(3);
					p.HP = p.HP_MAX;
					player_data_set();
					return;
				}
			}
			else if (dangions == 3) {
				if (hantei == 0 && py == 252 && (180 < px && 220 > px)) {
					erase();
					if(Battle(3)){
					}
					else {
						return;
					}
					
					hantei = 1;
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 11; j++) {
							ab[245 + i][196 + j] = ' ';
						}
					}
				}if (hantei == 1 && py == 222 && (180 < px && 220 > px)) {
					erase();
					if (Battle(3)) {
					}
					else {
						return;
					}
					hantei = 2;
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 9; j++) {
							ab[215 + i][196 + j] = ' ';
						}
					}
				}if (hantei == 2 && py == 192 && (180 < px && 220 > px)) {
					erase();
					if (Battle(3)) {

					}
					else {
						return;
					}
					hantei = 3;
					for (int i = 0; i < 6; i++) {
						for (int j = 0; j < 5; j++) {
							ab[185 + i][197 + j] = ' ';
						}
					}
				}if (hantei == 3 && py == 162 && (180 < px && 220 > px)) {
					erase();
					Battle(3);
					p.HP = p.HP_MAX;
					player_data_set();
					return;
					for (int i = 0; i < 6; i++) {
						for (int j = 0; j < 19; j++) {
							ab[155 + i][194 + j] = ' ';
						}
					}

				}
			}                                                    
			
				if (ab[py - 1][px] != '#') {
					a++;
					py--;
					random = rand() % 8;
					if (random == 7) {
						mnumber = rand() % 2;
						erase();
						if (Battle(mnumber)) {
						}
						else {
							return;
						}
					}
				}
				if (ab[py-1][px] == '+') {
					p.HP = p.HP_MAX;
					ab[py-1][px] = ' ';
					
				}
			
			break;
		case KEY_DOWN:
			if (ab[py + 1][px] != '#') {
				a--;
				py++;
				random = rand() % 8;
				if (random == 7) {
					mnumber = rand() % 2;
					erase();
					if (Battle(mnumber)) {
					}
					else {
						return;
					}
				}
			}
			if (ab[py+1][px] == '+') {
				p.HP = p.HP_MAX;
				ab[py+1][px] = ' ';
				
			}
			break;

		case KEY_RIGHT:
			if (dangions == 2) {
				if (px == 250 && (py > 80 && py < 170)) {
					erase();
					Battle(1);
					p.HP = p.HP_MAX;
					player_data_set();
					return;
				}
			}
	
				if (ab[py][px + 1] != '#') {
					b--;
					px++;
					random = rand() % 8;
					if (random == 7) {
						mnumber = rand() % 3;
						erase();
						if (Battle(mnumber)) {
						}
						else {
							return;
						}
					}
				}
				if (ab[py][px + 1] == '+') {
					p.HP = p.HP_MAX;
					ab[py][px+1] = ' ';
					
				}
			
			break;
		case KEY_LEFT:
			if (ab[py][px - 1] != '#') {
				b++;
				px--;
				random = rand()%8;
				if (random == 7) {
					mnumber = rand() % 3;
					erase();
					if (Battle(mnumber)) {
					}
					else {
						return;
					}
				}
			}
			if (ab[py][px - 1] == '+') {
				p.HP = p.HP_MAX;
				ab[py][px-1] = ' ';
			}
			break;	
		case 'B':
			p.HP = p.HP_MAX;
			p.DP = 0;
			player_data_set();
			return;
		}
	

		refresh();
		
		// 1ïbë“ã@

	}

	   return;
}

void block1(int a, int b, int c, int d) {
	int i, j;
	for (j = a; j < b; j++) {
		for (i = c; i < d; i++) {
			ab[j][i] = ' ';
		}
	}
}
void tate(int a, int b,int ichi) {
	int i;
	for (i = a; i < b; i++) {
		ab[i][ichi] = ' ';
	}
}
void yoko(int a, int b, int ichi) {
	int i;
	for (i = a; i < b; i++) {
		ab[ichi][i] = ' ';
	}
}
void create(int dangion_number) {
	
	if (dangion_number == 1) {
		
		
		block1(15, 30, 60, 140); //1
		block1(110, 140, 100, 150); //2
		block1(160, 200, 50, 100);//4
		block1(170, 220, 145, 180);//5
		block1(130, 150, 160, 200);//6
		block1(15, 100, 170, 220);//7
		block1(140, 180, 250, 270);//8
		block1(230, 260, 220, 270);//9
		tate(30, 110, 120);
		yoko(150, 160, 135);
		tate(150, 160, 170);
		yoko(150, 171, 160);
		tate(160, 170, 150);
		yoko(70, 110, 120);
		tate(120, 160, 70);
		yoko(140, 170, 25);
		yoko(220, 260, 55);
		tate(55, 140, 260);
		tate(180, 200, 260);
		yoko(245, 261, 200);
		tate(200, 231, 245);
		tate(260, 286, 250);
		yoko(160, 251, 285);
		tate(270, 285, 160);
		block1(222, 270, 150, 170);//10
		ab[180][75] = '+';
		ab[250][250] = '+';
		for (int i = 158; i < 163; i++) {
			ab[224][i] = 'X';
		}
		ab[225][158] = 'X'; ab[225][159] = 'o'; ab[225][160] = 'X'; ab[225][161] = 'o'; ab[225][162] = 'X';
		ab[226][158] = 'X'; ab[226][162] = 'X';
		for (int i = 159; i < 162; i++) {
			ab[226][i] = '_';
		}
		for (int i = 158; i < 163; i++) {
			ab[227][i] = 'X';
		}
	  /*XXXXX
		XoXoX
		X___X
		XXXXX*/
	}else if (dangion_number == 2) {
		
		block1(15, 40, 60, 70);//1
		yoko(60, 75, 30);
		block1(20, 80, 75, 90);//2
		tate(80, 100, 75);
		block1(100, 130, 70, 90);//3
		yoko(90, 100, 110);
		block1(100, 180, 35, 45);//4
		tate(130, 150, 80);
		block1(150, 175, 60, 130);//5
		tate(175, 220, 110);
		yoko(110, 130, 220);
		block1(190, 230, 130, 200);//6
		yoko(90, 140, 110);
		block1(100, 130, 140, 210);//7
		tate(50, 150, 175);
		yoko(175, 241, 50);
		yoko(175, 241, 150);
		tate(50, 150, 240);
		yoko(240, 250, 110);
		block1(80, 170, 250, 270);//8
		for (int i = 108; i < 113; i++) {
			if (i != 110) {
				ab[i][261] = '{';
				ab[i][262] = '}';
			}
		}
		for (int i = 261; i < 268; i++) {
			ab[110][i] = '=';
		}
		ab[110][260] = 'O';
		/* {} 
           {}  
          O=======
           {}
           {}*/
	}
	else if (dangion_number == 3) {
		
		block1(15, 40, 60, 70);
		block1(40, 270, 64, 67);
		block1(270, 273, 64, 202);
		block1(260, 270, 199, 202);
		block1(240, 260, 180, 220);
		block1(230, 240, 199, 201);
		block1(210, 230, 180, 220);
		block1(200, 210, 199, 201);
		block1(180, 200, 180, 220);
		block1(170, 180, 199, 201);
		block1(150, 170, 180, 220);
		//ab[215][198]
		char chara[3][10] = {
			{"| (' ')  "},
			{"+ I   I+D"},
			{"   J L   "} };

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 9; j++) {
				ab[215 + i][196 + j] = chara[i][j];
			}
		}
		char chara2[6][6] = {
			{" P q "},
			{" | | "},
			{" ### "},
			{"L###_"},
			{" #T# "},
			{"/#|#-"}
		};

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++) {
				ab[185 + i][197 + j] = chara2[i][j];
			}
		}
		char chara3[6][20] = {
			{"__ / l / l    k, k,"},
			{"Lww'  )  j i / iI  "},
			{"  ,  `/ / i  `     "},
			{" cc   ``~'Y'~~`    "},
			{"	(` () = F         "},
			{"	 (/ U             "}
		};
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 19; j++) {
				ab[155 + i][194 + j] = chara3[i][j];
			}
		}
		char chara4[4][12] = {
			{"   <* *>   "},
			{"Q__ | | __ "},
			{"    | |   D"},
			{"    V V    "}
		};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 11; j++) {
				ab[245 + i][196 + j] = chara4[i][j];
			}
		}
	}
}
