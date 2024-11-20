/*
    开发日志
    1.创建项目
    2.导入素材
    3.实现最开始的游戏场景



*/

#include <stdio.h>
#include <graphics.h>  

const int G_width = 900;
const int G_height = 600;

IMAGE imgBg; //背景图片
IMAGE imgBar; //工具栏
void gameInit()       //游戏初始化
{
    loadimage(&imgBg, "Res/bg.jpg");   //需要把字符集修改成“多字节字符集”
    loadimage(&imgBar, "Res/bar4.png");

    initgraph(G_width, G_height);//创建游戏窗口
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

