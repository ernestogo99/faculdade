#include <cmath>
#include <iostream>

double f(double x){
    return(
        -(std::exp(x)/2)
        + 2* std::cos(x)
    );
}


double bissecao(double a, double b,double epsilon){
    double fa=f(a);
    double fb=f(b);

    if(fa * fb >=0){
        throw  std::runtime_error("Intervalo inválido");
    }


    
    double intervalo = std::abs(b-a);
    while(intervalo > epsilon){
        double meio = (b+a)/2;
        double fmeio= f(meio);

        if(fa * fmeio <0){
            b= meio;
            fb=f(b);
        }else if(fb* meio <0){
            a=meio;
            fa=f(a);
        }else{
            return meio;
        }

        intervalo =std::abs(b-a);
    }

    return (a+b)/2;
}




int main(){

    double a,b;
    std::cout<<"Digite o invervalo inicial:";
    std::cin>>a;
    std::cin>>b;
    




    return 0;
}