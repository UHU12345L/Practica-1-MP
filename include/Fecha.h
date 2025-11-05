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

    //Fecha debe ser programada de forma que se ejecute lo más rápida y eficientemente posible
    //Una función amiga es más rápida que una no amiga ya que la amiga puede acceder directamente a los atributos del objeto de la clase mientras que la no amiga debe hacerlo indirectamente llamando a los métodos públicos.
    //2. Pasar un parámetro por referencia es más rápido que pasarlo por valor ya que se evita tener que hacer una copia
class Fecha {
  int dia;
  int mes, anio;
public:
  Fecha(int dia, int m, int anio); //const y & menos rapido
  int getDia() const { return dia; }
  int getMes() const { return this->mes; }
  int getAnio() const { return this->anio; }
  void setFecha(int dia, int mes, int a);
  void ver() const;
  bool bisiesto() const;
  Fecha operator++();   //++f
  Fecha operator++(int i); //f++
  Fecha operator+( int i) const; //f+5

  friend Fecha operator+(int i, const Fecha &f); //const por seguridad y & por velocidad
  friend ostream& operator<<(std::ostream &os, const Fecha &f);
};

Fecha operator+( int i, const Fecha &f); //const por seguridad y & por velocidad
ostream& operator<<(ostream &os, const Fecha &f);
#endif // FECHA_H
