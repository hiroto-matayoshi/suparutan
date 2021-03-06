#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "player.h"
#include "Enemy.h"

static int mImageHandle; //画像ハンドル格納用変数

static int mSoundBGM;

//初期化
void Game_Initialize() {
	mImageHandle = LoadGraph("images/haikeigazo.png"); //画像のロード

	Player_Initialize();	//
	Enemy_Initialize();

	PlayMusic("sounds/NES-Action-C02-1(Stage_Select).mp3", DX_PLAYTYPE_LOOP);

}

//終了処理
void Game_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放

	Player_Finalize();	//プレイヤーの開放
	Enemy_Finalize();

	StopMusic();
}

//更新
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
	DrawGraph(0, 0, mImageHandle, FALSE);

	Player_Update();
	Enemy_Update();

}
//描画
void Game_Draw() {
	Player_Draw();
	Enemy_Draw();

}