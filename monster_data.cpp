
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
	{ "�Ђ�����", "�����5�_���[�W�ADP+3", 5, 0, -3},
	{ "���肳��", "�����7�_���[�W�ADP+5", 7, 0, -5 },
	{ "�O���O�j��", "�����12�_���[�W", 12, 0, 6 },
	{ "�L���L��", "���g��HP��30�񕜂���", 0, -30, 5 },
	{ "�x�M���S��", "�����25�_���[�W�^���A�����ɂ�25�_���[�W", 25, 25, 10 },
	{ "�W�E�A�[�X", "�����30�_���[�W", 30, 30, 15 },
	};

	int s[6]{
		500, 1500, 2000, 4000, 9999, 9999
	};

	//�v���C���[�̏����Z
	Move move0[6] = {
		{ "�₷��", "�x��ŁADP��3���߂�", 0, 0, -3 },
		{ "�p���`", "�����2�_���[�W", 1, 0, 0 },
		{ "�₷��", "�x��ŁADP��3���߂�", 0, 0, -3 },
		{ "�p���`", "�����2�_���[�W", 1, 0, 0  },
		{ "�₷��", "�x��ŁADP��3���߂�", 0, 0, -3 },
		{ "�t���p���`", "����ɏo����+3�̃_���[�W", num + 3, 0, 9  }
	};

	//�S�[�����ُ̊o�������X�^�[�̋Z���X�g
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
		{ "���ǂ�", "���ǂ��āADP��4���߂�", 0, 0, -4 },
		{ "���ǂ�", "���ǂ��āADP��4���߂�", 0, 0, -4 },,
		{ "���ǂ肭�邤", "����ɏo����+3�̃_���[�W", num + 3, 0, 4 },
		{ "���ǂ�", "���ǂ��āADP��4���߂�", 0, 0, -4 },,
		{ "���ǂ�", "���ǂ��āADP��4���߂�", 0, 0, -4 },,
		{ "���ǂ肭�邤", "����ɏo����+3�̃_���[�W", num + 3, 0, 4 }
	};

	extern Move move6[6] = {
		{ "�ł̂�����", "�ł��܂Ƃ��ADP���T���߂�", 0, 0, -5 },
		{ "�؂肩����", "����ɏo����+2�̃_���[�W", num + 2, 0, 3 },
		{ "�؂肩����", "����ɏo����+2�̃_���[�W", num + 2, 0, 3 },
		{ "�ł̂�����", "�ł��܂Ƃ��ADP���T���߂�", 0, 0, -5 },
		{ "�ł̂͂ǂ�", "����ɏo���ځ~2�̃_���[�W", num * 2, 0, 12 },
		{ "�ł̂�����", "�ł��܂Ƃ��ADP���T���߂�", 0, 0, -5 }
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
		{ "�������Ȃ�", "�������Ȃ�ADP���T���߂�", 0, 0, -5},
		{ "�S�[�����p���`", "����ɏo����+2�_���[�W�ADP+1", num + 2, 0, -1 },
		{ "�S�[�����p���`", "����ɏo����+2�_���[�W�ADP+1", num + 2, 0, -1 },
		{ "�������Ȃ�", "�������Ȃ�ADP���T���߂�", 0, 0, -5},
		{ "�������Ȃ�", "�������Ȃ�ADP���T���߂�", 0, 0, -5},
		{ "�������Ȃ�", "�������Ȃ�ADP���T���߂�", 0, 0, -5}
	};

	//�g���{�̑��o�������X�^�[�̋Z���X�g
	extern Move move9[6] = {
		{ "�͂���", "�����1�_���[�W", 1, 0, 0 },
		{ "�͂���", "�����1�_���[�W", 1, 0, 0 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "���傫���傫", "����ɏo���ڂ̃_���[�W��^����ADP+2", num , 0, -2 },
		{ "���傫���傫", "����ɏo���ڂ̃_���[�W��^����ADP+2", num , 0, -2 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
	};

	extern Move move10[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "��", "�����2�_���[�W", 2, 0, 0 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "��", "�����2�_���[�W", 2, 0, 0 },
		{ "�̂ł�", "�����5�_���[�W", 5, 0, 3 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 }
	};

	extern Move move11[6] = {
		{ "���炪����", "���炪����ADP��3���߂�", 0, 0, -3 },
		{ "���炪����", "���炪����ADP��3���߂�", 0, 0, -3 },
		{ "�Ђ����肩����", "�����3�̃_���[�W��^����", 3, 0, 1 },
		{ "�Ђ����肩����", "�����3�̃_���[�W��^����", 3, 0, 1 },
		{ "�͂˂�", "�����5�̃_���[�W��^����", 5, 0, 3 },
		{ "���炪����", "���炪����ADP��3���߂�", 0, 0, -3 },
	};

	extern Move move12[6] = {
		{ "������", "�E�炵�āADP��3���߂�", 0, 0, -3 },
		{ "�܂���", "����ɏo���ڂ̃_���[�W", num, 0, 1 },
		{ "������", "�E�炵�āADP��3���߂�", 0, 0, -3 },
		{ "�܂���", "����ɏo���ڂ̃_���[�W", num, 0, 1 },
		{ "�܂���", "����ɏo���ڂ̃_���[�W", num, 0, 1 },
		{ "����������", "�����5�_���[�W", num * 2, 0, 3 }
	};

	extern Move move13[6] = {
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 },
		{ "�Ō�", "����ɏo���ڂ̃_���[�W�ADP+1", num, 0, -1 }
	};

	extern Move move14[6] = {
		{ "�Ƃ���", "����ɏo���ڂ̃_���[�W", num, 0, 0 },
		{ "�Ƃ���", "����ɏo���ڂ̃_���[�W", num, 0, 0 },
		{ "�Ƃ���", "����ɏo���ڂ̃_���[�W", num, 0, 0 },
		{ "�Ƃ���", "����ɏo���ڂ̃_���[�W", num, 0, 0 },
		{ "�Ƃ���", "����ɏo���ڂ̃_���[�W", num, 0, 0 },
		{ "�Ƃ���", "����ɏo���ڂ̃_���[�W", num, 0, 0 }
	};

	extern Move move15[6] = {
		{ "���_����", "���_�𓝈ꂳ���ADP��7���߂�", 0, 0, -7 },
		{ "�؂肩����", "����ɏo����+2�̃_���[�W", num + 2, 0, 3 },
		{ "�؂肩����", "����ɏo����+2�̃_���[�W", num + 2, 0, 3 },
		{ "�̓�����", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W�ADP+2", num + 1, 2, -2 },
		{ "���_����", "���_�𓝈ꂳ���ADP��7���߂�", 0, 0, -7 },
		{ "�Ȃɂ����Ȃ�", "�Ȃɂ������ADP���T���߂�", 0, 0, -5 }
	};

	extern Move move16[6] = {
		{ "�w���L�b�N", "����ɏo����+2�_���[�W�ADP+1", num + 2, 0, -1 },
		{ "�w���L�b�N", "����ɏo����+2�_���[�W�ADP+1", num + 2, 0, -1 },
		{ "�w���L�b�N", "����ɏo����+2�_���[�W�ADP+1", num + 2, 0, -1 },
		{ "�݂�����", "HP���o���ځ~2�񕜂���", 0, -(num * 2), 5},
		{ "�������Ȃ�", "�������Ȃ�ADP��5���߂�", 0, 0, -5},
		{ "�݂�����", "HP���o���ځ~2�񕜂���", 0, -(num * 2), 5}
	};

	//�{�X�Z
	extern Move boss_move1[6] = {
		{ "�S�[�����p���`", "����ɏo����+2�_���[�W�ADP+1", num + 2, 0, -1 },
		{ "�S�[�����p���`", "����ɏo����+2�_���[�W�ADP+1", num + 2, 0, -1 },
		{ "�������Ȃ�", "�������Ȃ�ADP��2���߂�", 0, 0, -2},
		{ "�������Ȃ�", "�������Ȃ�ADP��2���߂�", 0, 0, -2},
		{ "�̂�������", "�����6�̃_���[�W", 6, 0, 5 },
		{ "�̂�������", "�����6�̃_���[�W", 6, 0, 5 },
	};

	extern Move boss_move2[6] = {
		{ "�ނ��̂��点", "�����1�_���[�W�ADP���T���߂�", 1, 0, -5 },
		{ "�ނ��̂����߂�", "�����4�_���[�W", 1, 0, 3 },
		{ "�ނ��̂��点", "�����1�_���[�W�ADP���T���߂�", 1, 0, -5 },
		{ "�ނ��̂����߂�", "�����4�_���[�W", 1, 0, 3 },
		{ "�V�O�i���r�[��", "�����8�_���[�W", 8, 0, 8 }
		{ "�V�O�i���r�[��", "�����8�_���[�W", 8, 0, 8 }
	};

	extern Move boss_move3[6] = {
		{ "�܂���", "�݂��܂���ADP��3���߂�", 0, 0, -3 },
		{ "�₭����", "HP��10�񕜂���", 0, -10, 0 },
		{ "�E�҂̂邬", "�����7�_���[�W�ADP+5", 7, 0, -5 },
		{ "�E�҂̂邬", "�����7�_���[�W�ADP+5", 7, 0, -5 },
		{ "�₭����", "HP��10�񕜂���", 0, -10, 0 }
		{ "��݂̂����ق�", "�����20�_���[�W", 20, 0, 40 }
	};

	extern Move boss_move4[6] = {
		{ "���傫���傫", "����ɏo���ڂ̃_���[�W��^����ADP+2", num , 0, -2 },
		{ "���肫����", "����ɏo����+2�_���[�W", num + 1, 0, 1 },
		{ "���肫����", "����ɏo����+2�_���[�W", num + 1, 0, 1 },
		{ "���傫���傫", "����ɏo���ڂ̃_���[�W��^����ADP+2", num , 0, -2 },
		{ "�d��", "DP��10���߂�", 0, 0, -6 },
		{ "�n�T�~�M���`��", "�����25�_���[�W", 25, 0, 35 }
	};

	extern Move boss_move5[6] = {
		{ "�l�̘B��", "HP��5�񕜂���", 0, -5, 5},
		{ "���傤������", "����ɏo����+3�̃_���[�W", num + 3, 0, 3},
		{ "�l�̘B��", "HP��5�񕜂���", 0, -5, 5},
		{ "�[�ċz", "�������ADP��9���߂�", 0, 0, -9 },
		{ "�l�̘B��", "HP��5�񕜂���", 0, -5, 5},
		{ "������̂����ق�", "�����50�̃_���[�W", 50, 0, 45 },
	};

	extern Move boss_move6[6] = {
		{ "���̃I�[��", "DP��10���߂�", 0, 0, -10 },
		{ "�h���S���u���X", "����ɏo���ځ~2�̃_���[�W", num * 2, 0, 1 },
		{ "���̈Ј�", "HP��10�񕜁ADP���T���߂�", 0, -10, -5 },
		{ "�h���S���u���X", "����ɏo���ځ~2�̃_���[�W", num * 2, 0, 1 },
		{ "�o�[�j���O�u���X", "�����15�_���[�W", 15, 0, 5 }
		{ "�o�[�j���O�u���X", "�����15�_���[�W", 15, 0, 5 }
	};

	//�v���C���[�ݒ�
	extern struct Player p = { 15, 15, 15, 15, move0[1], move0[1], move0[2], move0[3], move0[4], move0[5], 10000, 0 };

	
	extern struct Monster monster[22] = {
		//�S�[�����ُ̊o�������X�^�[
		{ "�X���C��", 6, 6, 10, 10, move1[0], move1[1], move1[2], move1[3], move1[4], move1[5], 10, 10 },
		{ "�h���L�[", 7, 7, 15, 15, move2[0], move2[1], move2[2], move2[3], move2[4], move2[5], 12, 12 },
		{ "���܂���", 9, 9, 10, 10, move3[0], move3[1], move3[2], move3[3], move3[4], move3[5], 15, 8 },
		{ "����������", 10, 10, 5, 5, move4[0], move4[1], move4[2], move4[3], move4[4], move4[5], 10, 15 },
		{ "���ǂ�ق�����", 8, 8, 27, 27, move5[0], move5[1], move5[2], move5[3], move5[4], move5[5], 200, 1 },
		{ "�_�[�N�G���t", 10, 10, 20, 20, move6[0], move6[1], move6[2], move6[3], move6[4], move6[5], 10, 16 },
		{ "�X���C���i�C�g", 11, 11, 10, 10, move7[0], move7[1], move7[2], move7[3], move7[4], move7[5], 18, 20 },
		{ "�v�`�S�[����", 20, 20, 8, 8, move8[0], move8[1], move8[2], move8[3], move8[4], move8[5], 30, 30 },

		//�g���{�̑��o�������X�^�[
		{ "�N���K�^��", 15, 15, 10, 10, move9[0], move9[1], move9[2], move9[3], move9[4], move9[5], 20, 20 },
		{ "�J�u�g��", 17, 17, 15, 15, move10[0], move10[1], move10[2], move10[3], move10[4], move10[5], 22, 18 },
		{ "�E���K�G��", 15, 15, 10, 10, move11[0], move11[1], move11[2], move11[3], move11[4], move11[5], 24, 20 },
		{ "���[��", 20, 20, 10, 10, move12[0], move12[1], move12[2], move12[3], move12[4], move12[5], 15, 26 },
		{ "�ނ��X���C��", 13, 13, 17, 17, move13[0], move13[1], move13[2], move13[3], move13[4], move13[5], 22, 22 },
		{ "�t���C���[", 20, 20, 20, 20, move14[0], move14[1], move14[2], move14[3], move14[4], move14[5], 23, 26 },
		{ "�C�s�~", 16, 16, 21, 21, move15[0], move15[1], move15[2], move15[3], move15[4], move15[5], 1, 200},
		{ "�w���N����", 30, 30, 20, 20, move16[0], move16[1], move16[2], move16[3], move16[4], move16[5], 30, 30 },

		//�S�[�����̊�boss�����X�^�[
		{ "�L���O�S�[����", 35, 35, 10, 10, boss_move1[0], boss_move1[1], boss_move1[2], boss_move1[3], boss_move1[4], boss_move1[5], 500, 500 },

		//�g���{�̑�boss�����X�^�[
		{ "���K�����}", 50, 50, 32, 32, boss_move2[0], boss_move2[1], boss_move2[2], boss_move2[3], boss_move2[4], boss_move2[5], 800, 800 },

		//�l�V��
		{ "��݂̂䂤����", 50, 50, 40, 40, boss_move3[0], boss_move3[1], boss_move3[2], boss_move3[3], boss_move3[4], boss_move3[5], 1000, 1000 },
		{ "�M���t�@��", 55, 55, 35, 35, boss_move4[0], boss_move4[1], boss_move4[2], boss_move4[3], boss_move4[4], boss_move4[5], 1000, 1000 },
		{ "No.2", 60, 60, 45, 45, boss_move5[0], boss_move5[1], boss_move5[2], boss_move5[3], boss_move5[4], boss_move5[5], 1000, 1000 },
		{ "�h���S��", 75, 75, 50, 50, boss_move6[0], boss_move6[1], boss_move6[2], boss_move6[3], boss_move6[4], boss_move6[5], 1500, 1500 }
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