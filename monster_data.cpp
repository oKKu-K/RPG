
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
	{ "ひっかく", "相手に5ダメージ、DP+3", 5, 0, -3},
	{ "きりさく", "相手に7ダメージ、DP+5", 7, 0, -5 },
	{ "グングニル", "相手に12ダメージ", 12, 0, 6 },
	{ "キラキラ", "自身のHPを30回復する", 0, -30, 5 },
	{ "ベギラゴン", "相手に25ダメージ与え、自分にも25ダメージ", 25, 25, 10 },
	{ "ジ・アース", "相手に30ダメージ", 30, 30, 15 },
	};

	int s[6]{
		500, 1500, 2000, 4000, 9999, 9999
	};

	//プレイヤーの初期技
	Move move0[6] = {
		{ "やすむ", "休んで、DPを3ためる", 0, 0, -3 },
		{ "パンチ", "相手に2ダメージ", 1, 0, 0 },
		{ "やすむ", "休んで、DPを3ためる", 0, 0, -3 },
		{ "パンチ", "相手に2ダメージ", 1, 0, 0  },
		{ "やすむ", "休んで、DPを3ためる", 0, 0, -3 },
		{ "フルパンチ", "相手に出た目+3のダメージ", num + 3, 0, 9  }
	};

	//ゴーレムの館出現モンスターの技リスト
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
		{ "おどる", "おどって、DPを4ためる", 0, 0, -4 },
		{ "おどる", "おどって、DPを4ためる", 0, 0, -4 },,
		{ "おどりくるう", "相手に出た目+3のダメージ", num + 3, 0, 4 },
		{ "おどる", "おどって、DPを4ためる", 0, 0, -4 },,
		{ "おどる", "おどって、DPを4ためる", 0, 0, -4 },,
		{ "おどりくるう", "相手に出た目+3のダメージ", num + 3, 0, 4 }
	};

	extern Move move6[6] = {
		{ "闇のちから", "闇をまとい、DPを５ためる", 0, 0, -5 },
		{ "切りかかる", "相手に出た目+2のダメージ", num + 2, 0, 3 },
		{ "切りかかる", "相手に出た目+2のダメージ", num + 2, 0, 3 },
		{ "闇のちから", "闇をまとい、DPを５ためる", 0, 0, -5 },
		{ "闇のはどう", "相手に出た目×2のダメージ", num * 2, 0, 12 },
		{ "闇のちから", "闇をまとい、DPを５ためる", 0, 0, -5 }
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
		{ "かたくなる", "かたくなり、DPを５ためる", 0, 0, -5},
		{ "ゴーレムパンチ", "相手に出た目+2ダメージ、DP+1", num + 2, 0, -1 },
		{ "ゴーレムパンチ", "相手に出た目+2ダメージ、DP+1", num + 2, 0, -1 },
		{ "かたくなる", "かたくなり、DPを５ためる", 0, 0, -5},
		{ "かたくなる", "かたくなり、DPを５ためる", 0, 0, -5},
		{ "かたくなる", "かたくなり、DPを５ためる", 0, 0, -5}
	};

	//トンボの巣出現モンスターの技リスト
	extern Move move9[6] = {
		{ "はさむ", "相手に1ダメージ", 1, 0, 0 },
		{ "はさむ", "相手に1ダメージ", 1, 0, 0 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "ちょきちょき", "相手に出た目のダメージを与える、DP+2", num , 0, -2 },
		{ "ちょきちょき", "相手に出た目のダメージを与える、DP+2", num , 0, -2 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
	};

	extern Move move10[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "つつく", "相手に2ダメージ", 2, 0, 0 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "つつく", "相手に2ダメージ", 2, 0, 0 },
		{ "つのでつく", "相手に5ダメージ", 5, 0, 3 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 }
	};

	extern Move move11[6] = {
		{ "うらがえる", "うらがえり、DPを3ためる", 0, 0, -3 },
		{ "うらがえる", "うらがえり、DPを3ためる", 0, 0, -3 },
		{ "ひっくりかえる", "相手に3のダメージを与える", 3, 0, 1 },
		{ "ひっくりかえる", "相手に3のダメージを与える", 3, 0, 1 },
		{ "はねる", "相手に5のダメージを与える", 5, 0, 3 },
		{ "うらがえる", "うらがえり、DPを3ためる", 0, 0, -3 },
	};

	extern Move move12[6] = {
		{ "だっぴ", "脱皮して、DPを3ためる", 0, 0, -3 },
		{ "まきつく", "相手に出た目のダメージ", num, 0, 1 },
		{ "だっぴ", "脱皮して、DPを3ためる", 0, 0, -3 },
		{ "まきつく", "相手に出た目のダメージ", num, 0, 1 },
		{ "まきつく", "相手に出た目のダメージ", num, 0, 1 },
		{ "たたきつける", "相手に5ダメージ", num * 2, 0, 3 }
	};

	extern Move move13[6] = {
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 },
		{ "打撃", "相手に出た目のダメージ、DP+1", num, 0, -1 }
	};

	extern Move move14[6] = {
		{ "とつげき", "相手に出た目のダメージ", num, 0, 0 },
		{ "とつげき", "相手に出た目のダメージ", num, 0, 0 },
		{ "とつげき", "相手に出た目のダメージ", num, 0, 0 },
		{ "とつげき", "相手に出た目のダメージ", num, 0, 0 },
		{ "とつげき", "相手に出た目のダメージ", num, 0, 0 },
		{ "とつげき", "相手に出た目のダメージ", num, 0, 0 }
	};

	extern Move move15[6] = {
		{ "精神統一", "精神を統一させ、DPを7ためる", 0, 0, -7 },
		{ "切りかかる", "相手に出た目+2のダメージ", num + 2, 0, 3 },
		{ "切りかかる", "相手に出た目+2のダメージ", num + 2, 0, 3 },
		{ "体当たり", "相手に出た目+1のダメージを与え、自分にも2ダメージ、DP+2", num + 1, 2, -2 },
		{ "精神統一", "精神を統一させ、DPを7ためる", 0, 0, -7 },
		{ "なにもしない", "なにもせず、DPを５ためる", 0, 0, -5 }
	};

	extern Move move16[6] = {
		{ "ヘラキック", "相手に出た目+2ダメージ、DP+1", num + 2, 0, -1 },
		{ "ヘラキック", "相手に出た目+2ダメージ、DP+1", num + 2, 0, -1 },
		{ "ヘラキック", "相手に出た目+2ダメージ、DP+1", num + 2, 0, -1 },
		{ "みつをすう", "HPを出た目×2回復する", 0, -(num * 2), 5},
		{ "かたくなる", "かたくなり、DPを5ためる", 0, 0, -5},
		{ "みつをすう", "HPを出た目×2回復する", 0, -(num * 2), 5}
	};

	//ボス技
	extern Move boss_move1[6] = {
		{ "ゴーレムパンチ", "相手に出た目+2ダメージ、DP+1", num + 2, 0, -1 },
		{ "ゴーレムパンチ", "相手に出た目+2ダメージ、DP+1", num + 2, 0, -1 },
		{ "かたくなる", "かたくなり、DPを2ためる", 0, 0, -2},
		{ "かたくなる", "かたくなり、DPを2ためる", 0, 0, -2},
		{ "のしかかる", "相手に6のダメージ", 6, 0, 5 },
		{ "のしかかる", "相手に6のダメージ", 6, 0, 5 },
	};

	extern Move boss_move2[6] = {
		{ "むしのしらせ", "相手に1ダメージ、DPを５ためる", 1, 0, -5 },
		{ "むしのさざめき", "相手に4ダメージ", 1, 0, 3 },
		{ "むしのしらせ", "相手に1ダメージ、DPを５ためる", 1, 0, -5 },
		{ "むしのさざめき", "相手に4ダメージ", 1, 0, 3 },
		{ "シグナルビーム", "相手に8ダメージ", 8, 0, 8 }
		{ "シグナルビーム", "相手に8ダメージ", 8, 0, 8 }
	};

	extern Move boss_move3[6] = {
		{ "まもる", "みをまもり、DPを3ためる", 0, 0, -3 },
		{ "やくそう", "HPを10回復する", 0, -10, 0 },
		{ "勇者のつるぎ", "相手に7ダメージ、DP+5", 7, 0, -5 },
		{ "勇者のつるぎ", "相手に7ダメージ、DP+5", 7, 0, -5 },
		{ "やくそう", "HPを10回復する", 0, -10, 0 }
		{ "やみのかいほう", "相手に20ダメージ", 20, 0, 40 }
	};

	extern Move boss_move4[6] = {
		{ "ちょきちょき", "相手に出た目のダメージを与える、DP+2", num , 0, -2 },
		{ "きりきざむ", "相手に出た目+2ダメージ", num + 1, 0, 1 },
		{ "きりきざむ", "相手に出た目+2ダメージ", num + 1, 0, 1 },
		{ "ちょきちょき", "相手に出た目のダメージを与える、DP+2", num , 0, -2 },
		{ "硬化", "DPを10ためる", 0, 0, -6 },
		{ "ハサミギロチン", "相手に25ダメージ", 25, 0, 35 }
	};

	extern Move boss_move5[6] = {
		{ "人体錬成", "HPを5回復する", 0, -5, 5},
		{ "しょうげきは", "相手に出た目+3のダメージ", num + 3, 0, 3},
		{ "人体錬成", "HPを5回復する", 0, -5, 5},
		{ "深呼吸", "落着き、DPを9ためる", 0, 0, -9 },
		{ "人体錬成", "HPを5回復する", 0, -5, 5},
		{ "ちからのかいほう", "相手に50のダメージ", 50, 0, 45 },
	};

	extern Move boss_move6[6] = {
		{ "竜のオーラ", "DPを10ためる", 0, 0, -10 },
		{ "ドラゴンブレス", "相手に出た目×2のダメージ", num * 2, 0, 1 },
		{ "竜の威圧", "HPを10回復、DPを５ためる", 0, -10, -5 },
		{ "ドラゴンブレス", "相手に出た目×2のダメージ", num * 2, 0, 1 },
		{ "バーニングブレス", "相手に15ダメージ", 15, 0, 5 }
		{ "バーニングブレス", "相手に15ダメージ", 15, 0, 5 }
	};

	//プレイヤー設定
	extern struct Player p = { 15, 15, 15, 15, move0[1], move0[1], move0[2], move0[3], move0[4], move0[5], 10000, 0 };

	
	extern struct Monster monster[22] = {
		//ゴーレムの館出現モンスター
		{ "スライム", 6, 6, 10, 10, move1[0], move1[1], move1[2], move1[3], move1[4], move1[5], 10, 10 },
		{ "ドラキー", 7, 7, 15, 15, move2[0], move2[1], move2[2], move2[3], move2[4], move2[5], 12, 12 },
		{ "たまたま", 9, 9, 10, 10, move3[0], move3[1], move3[2], move3[3], move3[4], move3[5], 15, 8 },
		{ "おおもぐら", 10, 10, 5, 5, move4[0], move4[1], move4[2], move4[3], move4[4], move4[5], 10, 15 },
		{ "おどるほうせき", 8, 8, 27, 27, move5[0], move5[1], move5[2], move5[3], move5[4], move5[5], 200, 1 },
		{ "ダークエルフ", 10, 10, 20, 20, move6[0], move6[1], move6[2], move6[3], move6[4], move6[5], 10, 16 },
		{ "スライムナイト", 11, 11, 10, 10, move7[0], move7[1], move7[2], move7[3], move7[4], move7[5], 18, 20 },
		{ "プチゴーレム", 20, 20, 8, 8, move8[0], move8[1], move8[2], move8[3], move8[4], move8[5], 30, 30 },

		//トンボの巣出現モンスター
		{ "クワガタン", 15, 15, 10, 10, move9[0], move9[1], move9[2], move9[3], move9[4], move9[5], 20, 20 },
		{ "カブトン", 17, 17, 15, 15, move10[0], move10[1], move10[2], move10[3], move10[4], move10[5], 22, 18 },
		{ "ウラガエル", 15, 15, 10, 10, move11[0], move11[1], move11[2], move11[3], move11[4], move11[5], 24, 20 },
		{ "ワーム", 20, 20, 10, 10, move12[0], move12[1], move12[2], move12[3], move12[4], move12[5], 15, 26 },
		{ "むしスライム", 13, 13, 17, 17, move13[0], move13[1], move13[2], move13[3], move13[4], move13[5], 22, 22 },
		{ "フライヤー", 20, 20, 20, 20, move14[0], move14[1], move14[2], move14[3], move14[4], move14[5], 23, 26 },
		{ "修行厨", 16, 16, 21, 21, move15[0], move15[1], move15[2], move15[3], move15[4], move15[5], 1, 200},
		{ "ヘラクレン", 30, 30, 20, 20, move16[0], move16[1], move16[2], move16[3], move16[4], move16[5], 30, 30 },

		//ゴーレムの館bossモンスター
		{ "キングゴーレム", 35, 35, 10, 10, boss_move1[0], boss_move1[1], boss_move1[2], boss_move1[3], boss_move1[4], boss_move1[5], 500, 500 },

		//トンボの巣bossモンスター
		{ "メガヤンマ", 50, 50, 32, 32, boss_move2[0], boss_move2[1], boss_move2[2], boss_move2[3], boss_move2[4], boss_move2[5], 800, 800 },

		//四天王
		{ "やみのゆうしゃ", 50, 50, 40, 40, boss_move3[0], boss_move3[1], boss_move3[2], boss_move3[3], boss_move3[4], boss_move3[5], 1000, 1000 },
		{ "ギラファン", 55, 55, 35, 35, boss_move4[0], boss_move4[1], boss_move4[2], boss_move4[3], boss_move4[4], boss_move4[5], 1000, 1000 },
		{ "No.2", 60, 60, 45, 45, boss_move5[0], boss_move5[1], boss_move5[2], boss_move5[3], boss_move5[4], boss_move5[5], 1000, 1000 },
		{ "ドラゴン", 75, 75, 50, 50, boss_move6[0], boss_move6[1], boss_move6[2], boss_move6[3], boss_move6[4], boss_move6[5], 1500, 1500 }
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