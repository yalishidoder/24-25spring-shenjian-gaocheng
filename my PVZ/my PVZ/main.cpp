/*
    ������־
    1.������Ŀ
    2.�����ز�
    3.ʵ���ʼ����Ϸ����



*/

#include <stdio.h>
#include <graphics.h>  

const int G_width = 900;
const int G_height = 600;

IMAGE imgBg; //����ͼƬ
IMAGE imgBar; //������
void gameInit()       //��Ϸ��ʼ��
{
    loadimage(&imgBg, "Res/bg.jpg");   //��Ҫ���ַ����޸ĳɡ����ֽ��ַ�����
    loadimage(&imgBar, "Res/bar4.png");

    initgraph(G_width, G_height);//������Ϸ����
}


void updateWindow()
{
    putimage(0, 0, &imgBg);
    putimage(215, 0, &imgBar);
}

int main()
{
    gameInit();

    updateWindow();

    system("pause");
    return 0;
}

