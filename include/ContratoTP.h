#ifndef CONTRATOTP_H
#define CONTRATOTP_H

#include "Contrato.h"
//CONTRATOTP
//getLimiteMinutos si
//getPrecio si
//constructor
//destructor si
//ver
//getIdContrato
//setTarifaPlana si
//setFechaContrato
//setMinutosHablados
//getMinutosHablados


//CONTRATO MOVIL
//constructor
//destructor
//ver
//getIdContrato
//setNacionalidad
//setPrecioMinuto
//setMinutosHablados
//factura
class ContratoTP: public Contrato
{
    static int limiteMinutos;
    static double precio;
    int minutosHablados;
    public:
        ContratoTP(long int dniCon, const Fecha& f, int minutos );
        ~ContratoTP() override = default;
        static int getLimiteMinutos(){return limiteMinutos;}
        static double getPrecio(){return precio;}
        static void setTarifaPlana(int lim, double p){
            limiteMinutos=lim;
            precio=p;}
        int getMinutosHablados() const {return minutosHablados;}
        void setMinutosHablados(int m){minutosHablados=m;}
        void ver()const;
        double factura()const override;

        friend std::ostream& operator<<(std::ostream& os, const ContratoTP& ctp);

};


#endif // CONTRATOTP_H

