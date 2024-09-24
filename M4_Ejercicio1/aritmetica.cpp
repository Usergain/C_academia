#include "aritmetica.h"

Aritmetica::Aritmetica(int num1, int num2){
    this->numero1=num1;
    this->numero2=num2;

}

int Aritmetica::getnumero1(){
    return numero1;
}

int Aritmetica::getnumero2 (){
    return numero2;
}

void Aritmetica::setnumero1(int num){
    this->numero1=num;
}

void Aritmetica::setnumero2(int num){
    this->numero2=num;
}

int Aritmetica:: sumar(){
    return numero1 + numero2;
}

int Aritmetica:: restar(){
    return numero1 - numero2;
}

int Aritmetica:: producto(){
    return numero1 * numero2;
}

float Aritmetica:: division(){
    return static_cast<float>(numero1 / static_cast<float>(numero2)); //static_cast<float> para que no se trunque el resultado y el del numero 2 para que resultado sea float
}
