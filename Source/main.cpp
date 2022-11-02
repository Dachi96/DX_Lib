#include "DxLib.h"
#include "SceneMgr.h"
#include "Keyboard.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    SceneMgr sceneMgr;
    sceneMgr.Initialize();

    while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

        Keyboard_Update();    //�L�[�{�[�h�̍X�V

        sceneMgr.Update();  //�X�V
        sceneMgr.Draw();    //�`��

    }

    sceneMgr.Finalize();

    DxLib_End(); // DX���C�u�����I������
    return 0;
}