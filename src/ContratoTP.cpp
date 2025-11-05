#include "ContratoTP.h"
#include <iomanip>

/*    static int contadorIds;
    int idContrato;
    long int dniContrato;
    Fecha fechaContrato;

    static int limiteMinutos;
    static double precio;
    int minutosHablados;

    */
int ContratoTP::limiteMinutos = 300;
double ContratoTP::precio = 10.0;

ContratoTP::ContratoTP(long int dniCon, const Fecha& f, int minutos ): Contrato(dniCon, f), minutosHablados(minutos)
{
}

void ContratoTP::ver()const
{
    cout<< getDniContrato()<<" ("<<getIdContrato()<<" - ";
    cout<<getFechaContrato();
    cout<<") "<<minutosHablados<<"m, "<<limiteMinutos<<" ("<<precio<<"€)";
}

double ContratoTP::factura()const
{
    if(minutosHablados>limiteMinutos)
    {
        int exceso=minutosHablados-limiteMinutos;
        return precio + (exceso*0.15);
    }
    else
    {
        return precio;
    }
}


//static_cast: trata lo de() como si fuera de tipo <>
std::ostream& operator<<(std::ostream& os, const ContratoTP& ctp) {
    os << static_cast<const Contrato&>(ctp) << " "
       << ctp.getMinutosHablados() << "m, "
       << ContratoTP::getLimiteMinutos() << "("
       << std::fixed << std::setprecision(2) << ContratoTP::getPrecio() << ") - "  // CAMBIO AQUÍ
       << std::fixed << std::setprecision(2) << ctp.factura() << "€";
    return os;
}
