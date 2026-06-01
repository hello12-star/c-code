#include<stdio.h>
using namespace std;
int main(){

cin >> angle;     // 输入角度
if (angle % 90 == 0)
{
    // if-else嵌套
    if (angle % 180 == 0)
        cout << "线段在X轴上" << endl;
    else
        cout << "线段在Y轴上" << endl;
}
else
    cout << "线段在象限" << angle / 90 + 1 << endl;
}
