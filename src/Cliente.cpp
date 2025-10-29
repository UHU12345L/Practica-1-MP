#include <cstdlib>
#include <cstring> //strlen, strcpy
#include <iomanip> //std::setprecision
#include <sstream> //stringstream
#include "Cliente.h"

Cliente::Cliente(long int d, const char *nom, Fecha f):fechaAlta(f) {
  this->dni=d;

  this->nombre=new char[strlen(nom)+1];
  strcpy(this->nombre, nom);
}

Cliente::Cliente(const Cliente& c) : dni(c.dni), fechaAlta(c.fechaAlta) {
    nombre = new char[strlen(c.nombre) + 1];
    strcpy(nombre, c.nombre);
}

Cliente::~Cliente() {
  delete [] nombre; //si en el constructor uso new [] en el destructor uso delete []
}

Cliente& Cliente::operator=(const Cliente& c) {
  if (this != &c) {
    dni=c.dni;
    delete [] nombre;
    this->nombre=new char[strlen(c.nombre)+1];
    strcpy(nombre, c.nombre);
    this->fechaAlta=c.fechaAlta;
  }
  return *this;
}

void Cliente::setNombre(const char *nom){
    char* nuevo=new char[strlen(nom)+1];
    strcpy(nuevo,nom);
    delete [] nombre;
    nombre=nuevo;
}
void Cliente::setFecha(Fecha f){
    fechaAlta=f;
}

bool Cliente::operator==(const Cliente& c) const {
  if (dni!=c.dni) return false;
  if (strcmp(this->nombre, c.nombre)!=0) return false;
  if (fechaAlta.getDia()!=c.fechaAlta.getDia() ||
      fechaAlta.getMes()!=c.fechaAlta.getMes() ||
      fechaAlta.getAnio()!=c.fechaAlta.getAnio()) return false;
  return true;
}

std::ostream& operator<<(std::ostream &os, const Cliente &c) {
    os << c.getNombre() << " (" << c.getDni() << " - " << c.getFecha() << ")";
    return os;
}


