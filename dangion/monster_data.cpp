
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
	{ "�Ђ�����", "�����5�_���[�W�ADP+5", 5, 0, 2 },
	{ "���肳��", "�����7�_���[�W�ADP+5", 7, 0, 4 },
	{ "�O���O�j��", "�����12�_���[�W", 12, 0, 6 },
	{ "�L���L��", "���g��HP��30�񕜂���", 0, -30, 5 },
	{ "�x�M���S��", "�����50�_���[�W�^���A�����ɂ�10�_���[�W", 50, 10, 10 },
	{ "�W�E�A�[�X", "�����100�_���[�W", 100, 0, 15 },
	};

	int s[6]{
		200, 500, 1000, 2500, 5000, 9999
	};

	//�v���C���[�̏����Z
	Move move0[6] = {
		{ "�₷��", "�x��ŁADP��3���߂�", 0, 0, -3 },
		{ "�p���`", "�����1�_���[�W", 1, 0, 0 },
		{ "�₷��", "�x��ŁADP��3���߂�", 0, 0, -3 },
		{ "�p���`", "�����1�_���[�W", 1, 0, 0  },
		{ "�₷��", "�x��ŁADP��3���߂�", 0, 0, -3 },
		{ "�t���p���`", "����ɏo����+3�̃_���[�W", num + 3, 0, 9  }
	};

	//�����X�^�[1�̋Z���X�g
	extern Move move1[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 }
	};

	extern Move move2[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "����f��", "����ɂQ�_���[�W", 2, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 }
	};

	extern Move move3[6] = {
		{ "�܂邭�Ȃ�", "�܂邭�Ȃ�ADP��3���߂�", 0, 0, -3 },
		{ "�܂邭�Ȃ�", "�܂邭�Ȃ�ADP��3���߂�", 0, 0, -3 },
		{ "���낪��", "�����3�̃_���[�W��^���A�����ɂ�1�_���[�W", 3, 1, 3 },
		{ "��ԗ�", "����ɏo���ځ~3�̃_���[�W��^���A�����ɂ��o���ځ~2�̃_���[�W", num * 3, num * 2, 5 },
		{ "���낪��", "�����3�̃_���[�W��^���A�����ɂ�1�_���[�W", 3, 1, 3 },
		{ "�܂邭�Ȃ�", "�܂邭�Ȃ�ADP��3���߂�", 0, 0, -3 }
	};

	extern Move move4[6] = {
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "����������", "�����5�_���[�W", num * 2, 0, 3 }
	};

	extern Move move5[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 }
	};

	extern Move move6[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "����f��", "����ɂQ�_���[�W", 2, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 }
	};

	extern Move move7[6] = {
		{ "���_����", "���_�𓝈ꂳ���ADP��7���߂�", 0, 0, -7 },
		{ "�؂肩����", "����ɏo����+2�̃_���[�W", num + 2, 0, 3 },
		{ "�؂肩����", "����ɏo����+2�̃_���[�W", num + 2, 0, 3 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "���_����", "���_�𓝈ꂳ���ADP��7���߂�", 0, 0, -7 },
		{ "���l�؂�", "����ɏo���ځ~2�̃_���[�W", num * 2, 0, 15 }
	};

	extern Move move8[6] = {
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "����������", "�����5�_���[�W", num * 2, 0, 3 }
	};

	//�{�X�Z
	extern Move boss_move1[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 }
	};

	extern Move boss_move2[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "����f��", "����ɂQ�_���[�W", 2, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 }
	};

	extern Move boss_move3[6] = {
		{ "�܂邭�Ȃ�", "�܂邭�Ȃ�ADP��3���߂�", 0, 0, -3 },
		{ "�܂邭�Ȃ�", "�܂邭�Ȃ�ADP��3���߂�", 0, 0, -3 },
		{ "���낪��", "�����3�̃_���[�W��^���A�����ɂ�1�_���[�W", 3, 1, 3 },
		{ "��ԗ�", "����ɏo���ځ~3�̃_���[�W��^���A�����ɂ��o���ځ~2�̃_���[�W", num * 3, num * 2, 5 },
		{ "���낪��", "�����3�̃_���[�W��^���A�����ɂ�1�_���[�W", 3, 1, 3 },
		{ "�܂邭�Ȃ�", "�܂邭�Ȃ�ADP��3���߂�", 0, 0, -3 }
	};

	extern Move boss_move4[6] = {
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "������", "�����2�_���[�W�ADP+1", 0, 0, -1 },
		{ "����������", "�����5�_���[�W", num * 2, 0, 3 }
	};

	extern Move boss_move5[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 }
	};

	extern Move boss_move6[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "����f��", "����ɂQ�_���[�W", 2, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 }
	};

	//�v���C���[�ݒ�
	extern struct Player p = { 15, 15, 15, 15, move0[1], move0[1], move0[2], move0[3], move0[4], move0[5], 10000, 0 };

	
	extern struct Monster monster[22] = {
		//�S�[�����ُ̊o�������X�^�[
		{ "�X���C��", 10, 10, 10, 10, move1[0], move1[1], move1[2], move1[3], move1[4], move1[5], 10, 10 },
		{ "�h���L�[", 12, 12, 15, 15, move2[0], move2[1], move2[2], move2[3], move2[4], move2[5], 12, 12 },
		{ "���܂���", 13, 13, 10, 10, move3[0], move3[1], move3[2], move3[3], move3[4], move3[5], 15, 8 },
		{ "����������", 15, 15, 5, 5, move4[0], move4[1], move4[2], move4[3], move4[4], move4[5], 10, 15 },
		{ "���ǂ�ق�����", 20, 20, 27, 27, move5[0], move5[1], move5[2], move5[3], move5[4], move5[5], 360, 1 },
		{ "�_�[�N�G���t", 10, 10, 20, 20, move6[0], move6[1], move6[2], move6[3], move6[4], move6[5], 10, 16 },
		{ "�X���C���i�C�g", 15, 15, 10, 10, move7[0], move7[1], move7[2], move7[3], move7[4], move7[5], 18, 20 },
		{ "�v�`�S�[����", 30, 30, 8, 8, move8[0], move8[1], move8[2], move8[3], move8[4], move8[5], 30, 30 },

		//�g���{�̑��o�������X�^�[
		{ "�N���K�^��", 10, 10, 10, 10, move1[0], move1[1], move1[2], move1[3], move1[4], move1[5], 10, 10 },
		{ "�J�u�g��", 12, 12, 15, 15, move2[0], move2[1], move2[2], move2[3], move2[4], move2[5], 10, 10 },
		{ "�E���K�G��", 15, 15, 10, 10, move3[0], move3[1], move3[2], move3[3], move3[4], move3[5], 10, 10 },
		{ "����������", 20, 20, 5, 5, move4[0], move4[1], move4[2], move4[3], move4[4], move4[5], 10, 10 },
		{ "�X���C��", 10, 10, 10, 10, move5[0], move5[1], move5[2], move5[3], move5[4], move5[5], 10, 10 },
		{ "�_�[�N�G���t", 10, 10, 20, 20, move6[0], move6[1], move6[2], move6[3], move6[4], move6[5], 10, 10 },
		{ "�C�s�~", 37, 37, 10, 10, move7[0], move7[1], move7[2], move7[3], move7[4], move7[5], 10, 10 },
		{ "�w���N����", 40, 40, 5, 5, move8[0], move8[1], move8[2], move8[3], move8[4], move8[5], 10, 10 },

		//�S�[�����̊�boss�����X�^�[
		{ "�L���O�S�[����", 75, 75, 10, 10, boss_move1[0], boss_move1[1], boss_move1[2], boss_move1[3], boss_move1[4], boss_move1[5], 500, 500 },

		//�g���{�̑�boss�����X�^�[
		{ "�S�b�h�I�uTONBO", 100, 100, 10, 10, boss_move2[0], boss_move2[1], boss_move2[2], boss_move2[3], boss_move2[4], boss_move2[5], 800, 800 },

		//�l�V��
		{ "�n�f�X", 100, 100, 10, 10, boss_move3[0], boss_move3[1], boss_move3[2], boss_move3[3], boss_move3[4], boss_move3[5], 1000, 1000 },
		{ "�E���m�X", 120, 120, 15, 15, boss_move4[0], boss_move4[1], boss_move4[2], boss_move4[3], boss_move4[4], boss_move4[5], 1000, 1000 },
		{ "�T���_�[", 150, 150, 10, 10, boss_move5[0], boss_move5[1], boss_move5[2], boss_move5[3], boss_move5[4], boss_move5[5], 1000, 1000 },
		{ "�_�C�X�}��", 200, 200, 5, 5, boss_move6[0], boss_move6[1], boss_move6[2], boss_move6[3], boss_move6[4], boss_move6[5], 1500, 1500 }
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