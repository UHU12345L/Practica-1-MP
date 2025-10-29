#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H

#include "Contrato.h"
#include <cstring>

//CONTRATOTP
//getLimiteMinutos
//getPrecio
//constructor
//destructor
//ver
//getIdContrato
//setTarifaPlana
//setFechaCOntrato
//setMinutosHablados


//CONTRATO MOVIL
//constructor
//destructor
//ver
//getIdContrato
//setNacionalidad
//setPrecioMinuto
//setMinutosHablados
//factura
//NACIONALIDAD

class ContratoMovil:public Contrato
{
    double precioMinuto;
    int minutosHablados;
    char* nacionalidad;

    public:
        ContratoMovil(long int dniCon, const Fecha& f, double precioMin, int minutos, const char* nac);
        ContratoMovil(const ContratoMovil& other);
        ~ContratoMovil() override;
        ContratoMovil& operator=(const ContratoMovil& other);

        double getPrecioMinuto() const {return precioMinuto;}
        int getMinutosHablados() const {return minutosHablados;}
        const char* getNacionalidad() const {return nacionalidad;}

        void setNacionalidad(const char* nac);
        void setPrecioMinuto(double precio){precioMinuto=precio;}
        void setMinutosHablados(int minutos){minutosHablados=minutos;}

        void ver() const;
        double factura() const override;

        friend std::ostream& operator<<(std::ostream& os, const ContratoMovil& cm);

};

#endif // CONTRATOMOVIL_H
