#include "Contrato.h"

/*    static int contadorIds;
    int idContrato;
    long int dniContrato;
    Fecha fechaContrato;*/
    int Contrato::contadorIds = 1;

Contrato::Contrato(long dniCon, const Fecha& f): idContrato(contadorIds++), dniContrato(dniCon), fechaContrato(f){}

Contrato::Contrato(const Contrato& other): idContrato(contadorIds++), dniContrato(other.dniContrato), fechaContrato(other.fechaContrato){}

 void Contrato::ver()const{
    cout<<dniContrato<< " (" << idContrato<<" - ";
    fechaContrato.ver();
    cout<<")";
}

 std::ostream& operator<<(std::ostream& os, const Contrato& c){
    os<<c.dniContrato<<" ("<<c.idContrato<<" - " << c.fechaContrato<<")";
    return os;
}
