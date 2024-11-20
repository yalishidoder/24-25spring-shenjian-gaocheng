/* 2351131 信04 韦世贸 */
#include <iostream>
#include <string>
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int daxie(int num,  int flag_of_zero)
{
    if (num == 0) {
        if (!flag_of_zero)
        {
            result += chnstr[0];
            result += chnstr[1];
        }
        flag_of_zero++;
    }
    else
    {
        result += chnstr[2 * num];
        result += chnstr[2 * num + 1];
    }
    return flag_of_zero;
}
int main()
{
    /* --允许添加需要的内容 --*/

    double money;
    int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;/* 定义人民币各位的数值 */
    int flag_of_zero[4] = { 0 };
    
    cout<<"请输入[0-100亿)之间的数字:"<<endl;
    cin >> money;

    while (money < 0 || money >= 10000000000) {
        cout<<"请输入[0-100亿)之间的数字:"<<endl;
        cin >> money;
        if (money >= 0 && money < 10000000000)
            break;
    }
  
    shiyi = (int)(money / 1000000000) % 10;
    yi = (int)(money / 100000000) % 10;
    qianwan = (int)(money / 10000000) % 10;
    baiwan = (int)(money / 1000000) % 10;
    shiwan = (int)(money / 100000) % 10;
    wan = (int)(money / 10000) % 10;
    qian = (int)(money / 1000) % 10;
    bai = (int)(money / 100) % 10;
    shi = (int)(money / 10) % 10;
    yuan = (int)((money / 10 - (int)(money / 10)) * 10 + 0.001) % 10;
    jiao = (int)((money / 10 - (int)(money / 10)) * 100 + 0.001) % 10;
    fen = (int)((money / 10 - (int)(money / 10)) * 1000 + 0.001) % 10;
   
    //十亿和亿位
    flag_of_zero[0] = 1;
    flag_of_zero[0] = daxie(shiyi, flag_of_zero[0]);

    if (shiyi)
    {
        result+= "拾";      
    }
    flag_of_zero[0] = daxie(yi, flag_of_zero[0]);

    if (flag_of_zero[0] != 3)
    {
        result += "亿";
    }

    //万
    if (flag_of_zero[0] != 1)
        flag_of_zero[1] = 1;
    if (qianwan && (shiwan || baiwan || wan))
        flag_of_zero[1] = 0;
    flag_of_zero[1] = daxie(qianwan, flag_of_zero[1]);
    
    if (qianwan)
    {
        result += "仟";
    }

    flag_of_zero[1] = daxie(baiwan, flag_of_zero[1]);
    if (baiwan)
    {
        result += "佰";
    }

    flag_of_zero[1] = daxie(shiwan, flag_of_zero[1]);

    if (shiwan)
    {
        result += "拾";
    }

    flag_of_zero[1] = daxie(wan, 1);
    if (qianwan || shiwan || baiwan || wan)
        result += "万";

    //千到个位
    if (flag_of_zero[1] > 1)
        flag_of_zero[2] = 1;
    if (qian && (shi || bai || yuan))
        flag_of_zero[2] = 0;
    flag_of_zero[2] = daxie(qian, flag_of_zero[2]);
    if (qian)
    {
        result+= "仟";
    }

    flag_of_zero[2] = daxie(bai, flag_of_zero[2]);
 
    if (bai)
    {
        result += "佰";
    }

    flag_of_zero[2] = daxie(shi, flag_of_zero[2]);
    if (shi)
    {
        result += "拾";
    }
    if(money<1)
        flag_of_zero[2] = daxie(yuan, flag_of_zero[2]);
    else
        flag_of_zero[2] = daxie(yuan, 1);
    if(money == 0){
        result += chnstr[0];
        result += chnstr[1];
    }
    if (yuan  || (shiyi || yi || qianwan || baiwan || shiwan || wan || qian || bai || shi))
    {
        result+= "圆";
    }
    else if(yuan >= 0 && !jiao && !fen)
        result += "圆";
    if(!jiao && yuan>=0 && !fen)
        flag_of_zero[3] = 1;
    flag_of_zero[3] = daxie(jiao, flag_of_zero[3]);
    if (jiao)
    {
        result += "角";
    }
    if (fen)
    {
        flag_of_zero[3] = daxie(fen, flag_of_zero[3]);
        result += "分";
    }
    else
        result += "整";
    cout << "大写结果是:" << endl;
    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}