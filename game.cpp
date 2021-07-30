#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "player.h"
#include "Enemy.h"

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�

static int mSoundBGM;

//������
void Game_Initialize() {
	mImageHandle = LoadGraph("images/haikeigazo.png"); //�摜�̃��[�h

	Player_Initialize();	//
	Enemy_Initialize();

	PlayMusic("sounds/NES-Action-C02-1(Stage_Select).mp3", DX_PLAYTYPE_LOOP);

}

//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��

	Player_Finalize();	//�v���C���[�̊J��
	Enemy_Finalize();

	StopMusic();
}

//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
	DrawGraph(0, 0, mImageHandle, FALSE);

	Player_Update();
	Enemy_Update();

}
//�`��
void Game_Draw() {
	Player_Draw();
	Enemy_Draw();

}