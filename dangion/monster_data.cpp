
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "Setting.h"
#include "monster_data.h"

Player p;


int num = 0;
	Move shop_move[6] = {
	{ "ひっかく", "相手に5ダメージ、DP+5", 5, 0, 2 },
	{ "きりさく", "相手に7ダメージ、DP+5", 7, 0, 4 },
	{ "グングニル", "相手に12ダメージ", 12, 0, 6 },
	{ "キラキラ", "自身のHPを30回復する", 0, -30, 5 },
	{ "ベギラゴン", "相手に50ダメージ与え、自分にも10ダメージ", 50, 10, 10 },
	{ "ジ・アース", "相手に100ダメージ", 100, 0, 15 },
	};

	int s[6]{
		200, 500, 1000, 2500, 5000, 9999
	};

	//プレイヤーの初期技
	Move move0[6] = {
		{ "やすむ", "休んで、DPを3ためる", 0, 0, -3 },
		{ "パンチ", "相手に1ダメージ", 1, 0, 0 },
		{ "やすむ", "休んで、DPを3ためる", 0, 0, -3 },
		{ "パンチ", "相手に1ダメージ", 1, 0, 0  },
		{ "やすむ", "休んで、DPを3ためる", 0, 0, -3 },
		{ "フルパンチ", "相手に出た目+3のダメージ", num + 3, 0, 9  }
	};

	//モンスター1の技リスト
	extern Move move1[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 }
	};

	extern Move move2[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "息を吐く", "相手に２ダメージ", 2, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 }
	};

	extern Move move3[6] = {
		{ "まるくなる", "まるくなり、DPを3ためる", 0, 0, -3 },
		{ "まるくなる", "まるくなり、DPを3ためる", 0, 0, -3 },
		{ "ころがる", "相手に3のダメージを与え、自分にも1ダメージ", 3, 1, 3 },
		{ "大車輪", "相手に出た目×3のダメージを与え、自分にも出た目×2のダメージ", num * 3, num * 2, 5 },
		{ "ころがる", "相手に3のダメージを与え、自分にも1ダメージ", 3, 1, 3 },
		{ "まるくなる", "まるくなり、DPを3ためる", 0, 0, -3 }
	};

	extern Move move4[6] = {
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたきつける", "相手に5ダメージ", num * 2, 0, 3 }
	};

	extern Move move5[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 }
	};

	extern Move move6[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "息を吐く", "相手に２ダメージ", 2, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 }
	};

	extern Move move7[6] = {
		{ "精神統一", "精神を統一させ、DPを7ためる", 0, 0, -7 },
		{ "切りかかる", "相手に出た目+2のダメージ", num + 2, 0, 3 },
		{ "切りかかる", "相手に出た目+2のダメージ", num + 2, 0, 3 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "精神統一", "精神を統一させ、DPを7ためる", 0, 0, -7 },
		{ "魔人切り", "相手に出た目×2のダメージ", num * 2, 0, 15 }
	};

	extern Move move8[6] = {
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたきつける", "相手に5ダメージ", num * 2, 0, 3 }
	};

	//ボス技
	extern Move boss_move1[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 }
	};

	extern Move boss_move2[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "息を吐く", "相手に２ダメージ", 2, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 }
	};

	extern Move boss_move3[6] = {
		{ "まるくなる", "まるくなり、DPを3ためる", 0, 0, -3 },
		{ "まるくなる", "まるくなり、DPを3ためる", 0, 0, -3 },
		{ "ころがる", "相手に3のダメージを与え、自分にも1ダメージ", 3, 1, 3 },
		{ "大車輪", "相手に出た目×3のダメージを与え、自分にも出た目×2のダメージ", num * 3, num * 2, 5 },
		{ "ころがる", "相手に3のダメージを与え、自分にも1ダメージ", 3, 1, 3 },
		{ "まるくなる", "まるくなり、DPを3ためる", 0, 0, -3 }
	};

	extern Move boss_move4[6] = {
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたく", "相手に2ダメージ、DP+1", 0, 0, -1 },
		{ "たたきつける", "相手に5ダメージ", num * 2, 0, 3 }
	};

	extern Move boss_move5[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 }
	};

	extern Move boss_move6[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "息を吐く", "相手に２ダメージ", 2, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 }
	};

	//プレイヤー設定
	extern struct Player p = { 15, 15, 15, 15, move0[1], move0[1], move0[2], move0[3], move0[4], move0[5], 10000, 0 };

	
	extern struct Monster monster[22] = {
		//ゴーレムの館出現モンスター
		{ "スライム", 10, 10, 10, 10, move1[0], move1[1], move1[2], move1[3], move1[4], move1[5], 10, 10 },
		{ "ドラキー", 12, 12, 15, 15, move2[0], move2[1], move2[2], move2[3], move2[4], move2[5], 12, 12 },
		{ "たまたま", 13, 13, 10, 10, move3[0], move3[1], move3[2], move3[3], move3[4], move3[5], 15, 8 },
		{ "おおもぐら", 15, 15, 5, 5, move4[0], move4[1], move4[2], move4[3], move4[4], move4[5], 10, 15 },
		{ "おどるほうせき", 20, 20, 27, 27, move5[0], move5[1], move5[2], move5[3], move5[4], move5[5], 360, 1 },
		{ "ダークエルフ", 10, 10, 20, 20, move6[0], move6[1], move6[2], move6[3], move6[4], move6[5], 10, 16 },
		{ "スライムナイト", 15, 15, 10, 10, move7[0], move7[1], move7[2], move7[3], move7[4], move7[5], 18, 20 },
		{ "プチゴーレム", 30, 30, 8, 8, move8[0], move8[1], move8[2], move8[3], move8[4], move8[5], 30, 30 },

		//トンボの巣出現モンスター
		{ "クワガタン", 10, 10, 10, 10, move1[0], move1[1], move1[2], move1[3], move1[4], move1[5], 10, 10 },
		{ "カブトン", 12, 12, 15, 15, move2[0], move2[1], move2[2], move2[3], move2[4], move2[5], 10, 10 },
		{ "ウラガエル", 15, 15, 10, 10, move3[0], move3[1], move3[2], move3[3], move3[4], move3[5], 10, 10 },
		{ "おおもぐら", 20, 20, 5, 5, move4[0], move4[1], move4[2], move4[3], move4[4], move4[5], 10, 10 },
		{ "スライム", 10, 10, 10, 10, move5[0], move5[1], move5[2], move5[3], move5[4], move5[5], 10, 10 },
		{ "ダークエルフ", 10, 10, 20, 20, move6[0], move6[1], move6[2], move6[3], move6[4], move6[5], 10, 10 },
		{ "修行厨", 37, 37, 10, 10, move7[0], move7[1], move7[2], move7[3], move7[4], move7[5], 10, 10 },
		{ "ヘラクレン", 40, 40, 5, 5, move8[0], move8[1], move8[2], move8[3], move8[4], move8[5], 10, 10 },

		//ゴーレムの館bossモンスター
		{ "キングゴーレム", 75, 75, 10, 10, boss_move1[0], boss_move1[1], boss_move1[2], boss_move1[3], boss_move1[4], boss_move1[5], 500, 500 },

		//トンボの巣bossモンスター
		{ "ゴッドオブTONBO", 100, 100, 10, 10, boss_move2[0], boss_move2[1], boss_move2[2], boss_move2[3], boss_move2[4], boss_move2[5], 800, 800 },

		//四天王
		{ "ハデス", 100, 100, 10, 10, boss_move3[0], boss_move3[1], boss_move3[2], boss_move3[3], boss_move3[4], boss_move3[5], 1000, 1000 },
		{ "ウラノス", 120, 120, 15, 15, boss_move4[0], boss_move4[1], boss_move4[2], boss_move4[3], boss_move4[4], boss_move4[5], 1000, 1000 },
		{ "サンダー", 150, 150, 10, 10, boss_move5[0], boss_move5[1], boss_move5[2], boss_move5[3], boss_move5[4], boss_move5[5], 1000, 1000 },
		{ "ダイスマン", 200, 200, 5, 5, boss_move6[0], boss_move6[1], boss_move6[2], boss_move6[3], boss_move6[4], boss_move6[5], 1500, 1500 }
	};

void player_data() {
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);

	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\RPG_data.ini", currentDirectory);

	char section[CHARBUFF];
	sprintf_s(section, "player");

	char keyWord[CHARBUFF];
	sprintf_s(keyWord, "HP");
	if (getIntFromINI(section, keyWord, settingFile, -1) == -1) {
		player_data_ini();
	}
	else {
		sprintf_s(keyWord, "HP");
		p.HP = getIntFromINI(section, keyWord, settingFile, -1);
		sprintf_s(keyWord, "HP_MAX");
		p.HP_MAX = getIntFromINI(section, keyWord, settingFile, -1);
		sprintf_s(keyWord, "DP");
		p.DP = getIntFromINI(section, keyWord, settingFile, -1);
		sprintf_s(keyWord, "DP_MAX");
		p.DP_MAX = getIntFromINI(section, keyWord, settingFile, -1);
		sprintf_s(keyWord, "gold");
		p.gold = getIntFromINI(section, keyWord, settingFile, -1);
		sprintf_s(keyWord, "exp");
		p.exp = getIntFromINI(section, keyWord, settingFile, -1);
		sprintf_s(keyWord, "max_exp");
		p.max_exp = getIntFromINI(section, keyWord, settingFile, -1);

		for (int i = 0; i < 6; i++) {
			sprintf_s(section, "m%d", i);
			sprintf_s(keyWord, "move_name");
			getCharFromINI(section, keyWord, settingFile, p.m[i].move_name,"none");
			sprintf_s(keyWord, "move_exp");
			getCharFromINI(section, keyWord, settingFile, p.m[i].move_exp,"move_exp");
			sprintf_s(keyWord, "att_point");
			p.m[i].att_point=getIntFromINI(section, keyWord, settingFile, -1);
			sprintf_s(keyWord, "myself_att");
			p.m[i].myself_att = getIntFromINI(section, keyWord, settingFile, -1);
			sprintf_s(keyWord, "DP_cons");
			p.m[i].DP_cons = getIntFromINI(section, keyWord, settingFile, -1);
		}
	}
}

void player_data_set() {
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);

	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\RPG_data.ini", currentDirectory);

	char section[CHARBUFF];
	sprintf_s(section, "player");

	char keyWord[CHARBUFF];

	sprintf_s(keyWord, "HP");
	setIntFromINI(section, keyWord, settingFile, p.HP);
	sprintf_s(keyWord, "HP_MAX");
	setIntFromINI(section, keyWord, settingFile, p.HP_MAX);
	sprintf_s(keyWord, "DP");
	setIntFromINI(section, keyWord, settingFile, p.DP);
	sprintf_s(keyWord, "DP_MAX");
	setIntFromINI(section, keyWord, settingFile, p.DP_MAX);
	sprintf_s(keyWord, "gold");
	setIntFromINI(section, keyWord, settingFile, p.gold);
	sprintf_s(keyWord, "exp");
	setIntFromINI(section, keyWord, settingFile, p.exp);
	sprintf_s(keyWord, "max_exp");
	setIntFromINI(section, keyWord, settingFile, p.max_exp);

	for (int i = 0; i < 6; i++) {
		sprintf_s(section, "m%d", i);
		sprintf_s(keyWord, "move_name");
		setCharFromINI(section, keyWord, settingFile, p.m[i].move_name);
		sprintf_s(keyWord, "move_exp");
		setCharFromINI(section, keyWord, settingFile, p.m[i].move_exp);
		sprintf_s(keyWord, "att_point");
		setIntFromINI(section, keyWord, settingFile, p.m[i].att_point);
		sprintf_s(keyWord, "myself_att");
		setIntFromINI(section, keyWord, settingFile, p.m[i].myself_att);
		sprintf_s(keyWord, "DP_cons");
		setIntFromINI(section, keyWord, settingFile, p.m[i].DP_cons);
	}
}

void player_data_ini() {
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);

	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\RPG_data.ini", currentDirectory);

	char section[CHARBUFF];
	sprintf_s(section, "player");

	char keyWord[CHARBUFF];

	p = { 15, 15, 0, 15, move0[0], move0[1], move0[2], move0[3], move0[4], move0[5], 10000, 0 ,10 };

	sprintf_s(keyWord, "HP");
	setIntFromINI(section, keyWord, settingFile, p.HP);
	sprintf_s(keyWord, "HP_MAX");
	setIntFromINI(section, keyWord, settingFile, p.HP_MAX);
	sprintf_s(keyWord, "DP");
	setIntFromINI(section, keyWord, settingFile, p.DP);
	sprintf_s(keyWord, "DP_MAX");
	setIntFromINI(section, keyWord, settingFile, p.DP_MAX);
	sprintf_s(keyWord, "gold");
	setIntFromINI(section, keyWord, settingFile, p.gold);
	sprintf_s(keyWord, "exp");
	setIntFromINI(section, keyWord, settingFile, p.exp);
	sprintf_s(keyWord, "max_exp");
	setIntFromINI(section, keyWord, settingFile, p.max_exp);

	for (int i = 0; i < 6; i++) {
		sprintf_s(section, "m%d",i);
		sprintf_s(keyWord, "move_name");
		setCharFromINI(section, keyWord, settingFile, p.m[i].move_name);
		sprintf_s(keyWord, "move_exp");
		setCharFromINI(section, keyWord, settingFile, p.m[i].move_exp);
		sprintf_s(keyWord, "att_point");
		setIntFromINI(section, keyWord, settingFile, p.m[i].att_point);
		sprintf_s(keyWord, "myself_att");
		setIntFromINI(section, keyWord, settingFile, p.m[i].myself_att);
		sprintf_s(keyWord, "DP_cons");
		setIntFromINI(section, keyWord, settingFile, p.m[i].DP_cons);
	}
}