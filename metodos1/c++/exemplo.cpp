#include <iostream>


int main(){
    int n;
    float notas[n];
    for(int i=0; i<n; i++){
        std::cout << "Digite a dona da prova" << i + 1 << ": ";
        std::cin >>notas[i];
    }

    float soma=0;
    for(int nota:notas){
        soma+=nota;
    }

    float media =soma/n;

    std::cout << "Média das notas: "  << media << std::endl;

    if(media >7){
        std::cout <<"Aprovado" << std::endl;
    }else if(media >=4){
        std:: cout <<"AF" << std::endl;
    }else{
        std::cout <<"Reprovado"<<std::endl;
    }
    return 0;
}

