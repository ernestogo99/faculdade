#include <iostream>
using namespace std;

int main(){
    char v[100];
    v[0]='u';
    v[1]='m';
    v[2]=' ';
    v[3]='t';
    v[4]='e';
    v[5]='x'; v[6]='t'; v[7]='0'; v[8]=0;

    cout<<"["<<v<<"]\n";

    v[0]='48';// 0
    v[1]='49';// 1
    v[2]=' '; // ""
    v[3]='50';// 2
    v[4]='51';//3
    v[5]='52' ;//4
    v[6]=' ';// ""
    v[7]='48';//0
    v[8]=0;

    cout<<"["<<v<<"]\n";

}