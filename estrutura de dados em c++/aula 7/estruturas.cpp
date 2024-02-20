#include <iostream>
using namespace std;

struct par{double x,y ;};

int main(){
    par p;
    p.x=10.1;
    p.y=20.2;

    cout<<"p.x: "<<p.x<<'\n';
    cout<<"p.y: "<<p.y<<'\n';

    par q;
    cout<<"q.x:"<<q.x<<'\n';
    cout<<"q.y: "<<q.y<<'\n';
    q=p;

    cout<<"q.x: "<<q.x<<'\n';
    cout<<"q.y: "<<q.y<<'\n';

    par r{30,40};
    cout<<"r.x: "<<r.x<<'\n';
    cout<<"r.y: "<<r.y<<'\n';
    
}
