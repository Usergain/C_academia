#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
public:
    Tiempo(int _h, int _m, float _s);
    Tiempo(const Tiempo &);
    float total() const;
    void mostrar() const;
    virtual ~Tiempo();

private:
    int h;
    int m;
    float s;
};
#endif /* TIEMPO_H */