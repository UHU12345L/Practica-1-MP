#ifndef FECHA_H
#define FECHA_H

#include <iostream> //cin, cout

using namespace std;
//METODOS QUE NECESITO PORQUE APARECEN EN EL MAIN:
    //Constructor fecha con dia, mes, anio
    //getDia
    //getMes
    //getAnio
    //setFecha
    //ver
    //bool bisiesto
    //operator++ por la derecha
    //operator ++ por la izquierda
    //operator +
    //friend operator +
    //operator <<

class Fecha {
  int dia;
  int mes, anio;
public:
  Fecha(const int &dia, const int &m, const int &anio);
  int getDia() const { return dia; }
  int getMes() const { return this->mes; }
  int getAnio() const { return this->anio; }
  void setFecha(const int &dia, const int &mes, const int &a);
  void ver() const;
  bool bisiesto() const;
  Fecha operator++();   //++f
  Fecha operator++(int i); //f++
  Fecha operator+(const int &i) const; //f+5

  friend Fecha operator+(const int &i, const Fecha &f); //const por seguridad y & por velocidad
};

Fecha operator+(const int &i, const Fecha &f); //const por seguridad y & por velocidad
std::ostream& operator<<(std::ostream &os, const Fecha &f);
#endif // FECHA_H
