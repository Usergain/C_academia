#ifndef ARITMETICA_H
#define ARITMETICA_H

class Aritmetica
{
private:
    int numero1;
    int numero2;

public:
    Aritmetica(int num1, int num2);

    int getnumero1();
    int getnumero2();
    void setnumero1(int numero1);
    void setnumero2(int numero2);
    int sumar();
    int restar();
    int producto();
    float division();
};

#endif