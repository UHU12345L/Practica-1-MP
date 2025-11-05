#include "Fecha.h"

Fecha::Fecha( int dia,  int m,  int anio) {
    this->setFecha(dia, m, anio);
}

void Fecha::setFecha( int dia,  int mes, int a) {
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    this->anio=a; //debo asignar año para que al llamar a bisiesto() tenga el año bien
    if (this->bisiesto())
        diaMes[2]=29;

    //si el mes es incorrecto pongo el mas cercano
    if (mes<1) {
       this->mes=1;
    }else if (mes>12){
        this->mes=12;
    }else{
        this->mes=mes;
    }
    dmax=diaMes[this->mes]; //una vez fijado el mes veo cuantos dias tiene ese mes como maximo

    if (dia>dmax) {//si dia es superior al numero de dias de dicho mes
      this->dia=dmax;
    }else if (dia<1){ //si dia es inferior a 1
      this->dia=1;
    }else{
      this->dia=dia;
    }
}

bool Fecha::bisiesto() const {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
        return true;
    } else {
        return false;
    }

}

void Fecha::ver() const {
  if (this->dia < 10){
    cout << "0";
  }
  cout << this->dia << "/";
  if (this->mes < 10){
    cout << "0";
  }
  cout << this->mes << "/" << this->anio;
}

Fecha Fecha::operator++() {   //++f
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (this->bisiesto()) {//si el año es bisiesto febrero tiene 29 dias
      diaMes[2]=29;
    }
    dmax=diaMes[this->mes];
    this->dia++;
    if (this->dia>dmax) { //si al incrementar dia superamos el numero de dias de dicho mes
        this->dia=1;      //pasamos a 1
        this->mes++;      //del mes siguiente
        if (this->mes>12) { //si al incrementar mes pasamos de 12 meses
            this->mes=1;    //pasamos al mes 1
            this->anio++;   //del año siguiente
        }
    }
    return *this; //devolvemos el objeto fecha ya incrementado
}

Fecha Fecha::operator++(int i){ //f++
    Fecha copia(*this);
    ++(*this);
    return copia;
}

Fecha Fecha::operator+( int i) const { // f + 5
    if (i <= 0) return *this;

    int diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (this->bisiesto()){ //si el año es bisiesto febrero tiene 29 dias
      diaMes[2]=29;
    }
    int diaCopia  = this->getDia();
    int mesCopia  = this->getMes();
    int anioCopia = this->getAnio();

    int restante = i;

    while (restante > 0) {
        int dmax = diaMes[mesCopia]; //dias del mes segun en que mes estoy
        int libres = dmax - diaCopia; // días que quedan en el mes contando desde hoy

        if (restante <= libres) {
            diaCopia += restante;
            restante = 0; //he sumado lo que me faltaba por sumar
        } else {
            // saltar al día 1 del mes siguiente porque no quedan mas dias en el mes
            restante -= (libres + 1);
            diaCopia = 1;
            mesCopia++;
            if (mesCopia > 12) {
                mesCopia = 1;
                anioCopia++;
            }
        }
    }
    Fecha suma(diaCopia, mesCopia, anioCopia);
    return suma;
}

Fecha operator+( int i, const Fecha &f){
    return f+i;
  }

ostream& operator<<(ostream &os, const Fecha &f) {
  static const char* mesES[13] ={"", "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"};
  if (f.getDia() < 10) os << '0';
  os << f.getDia() << ' ' << mesES[f.getMes()] << ' ' << f.getAnio();
  return os;
}

