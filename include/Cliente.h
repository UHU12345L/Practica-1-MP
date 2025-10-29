#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream> //cin, cout
#include "Fecha.h"

using namespace std;
//METODOS QUE NECESITO PORQUE APARECEN EN EL MAIN:
    //Constructor cliente con dni,nombre,fecha
    //Destructor cliente
    //operator =
    //getDni
    //getNombre
    //getFecha
    //setNombre
    //setFecha
    //operator==
    //operator <<

class Cliente {
  long int dni;
  char *nombre;
  Fecha fechaAlta;
public:
  Cliente(long int d, const char *nom, Fecha f);
  Cliente(const Cliente& c);
  virtual ~Cliente();
  Cliente& operator=(const Cliente& c);

  long int getDni() const { return this->dni; }
  const char* getNombre() const { return nombre; } //VIP devolver un puntero constante para evitar que desde el main() se puede modificar el nombre
  Fecha getFecha() const { return fechaAlta; }

  void setNombre(const char *nom);
  void setFecha(Fecha f);

  bool operator==(const Cliente& c) const; // if (c1 ===c2)

};

std::ostream& operator<<(std::ostream &os, const Cliente &c); //funcion no amiga de la clase

#endif // CLIENTE_H
