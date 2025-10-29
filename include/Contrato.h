#ifndef CONTRATO_H
#define CONTRATO_H

#include <iostream>
#include "Fecha.h"

class Contrato
{
    static int contadorIds;
    int idContrato;
    long int dniContrato;
    Fecha fechaContrato;

    public:
        Contrato(long dniCon, const Fecha& f);
        Contrato(const Contrato& other); //constructor de copia para ids unicos
        virtual ~Contrato()=default;
        int getIdContrato() const {return idContrato;}
        long int getDniContrato() const {return dniContrato;}
        Fecha getFechaContrato()const {return fechaContrato;}

        void setDniContrato(long dni){dniContrato=dni;}
        void setFechaContrato(const Fecha& f){fechaContrato=f;}

        virtual void ver()const; //virtual para hacerlo polimorfico?? yo pensaba que se hacia en Fecha.h
        virtual double factura() const=0; //metodo virtual puro:
                //para clase abstracta, obliga a derivadas a implementarlo
                //no se puede crear objeto Contrato

        friend std::ostream& operator<<(std::ostream& os, const Contrato& c);

};

#endif // CONTRATO_H
