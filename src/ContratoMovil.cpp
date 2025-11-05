#include "ContratoMovil.h"
#include <cstring>
#include <iomanip>

/* double precioMinuto;
    int minutosHablados;
    char* nacionalidad;*/
ContratoMovil::ContratoMovil(long int dniCon, const Fecha& f, double precioMin, int minutos, const char* nac): Contrato(dniCon, f), precioMinuto(precioMin), minutosHablados(minutos)
{
    nacionalidad=new char[strlen(nac)+1];
    strcpy(nacionalidad, nac);
}
ContratoMovil::ContratoMovil(const ContratoMovil& other): Contrato(other), precioMinuto(other.precioMinuto), minutosHablados(other.minutosHablados)
{
    nacionalidad=new char[strlen(other.nacionalidad)+1];
    strcpy(nacionalidad, other.nacionalidad);
}
ContratoMovil::~ContratoMovil()
{
    delete[] nacionalidad;
}
ContratoMovil& ContratoMovil:: operator=(const ContratoMovil& other)
{
    if(this != &other)
    {
        setDniContrato(other.getDniContrato());
        setFechaContrato(other.getFechaContrato());

        precioMinuto=other.precioMinuto;
        minutosHablados=other.minutosHablados;

        delete[]nacionalidad;
        nacionalidad= new char[strlen(other.nacionalidad)+1];
        strcpy(nacionalidad, other.nacionalidad);

    }
        return *this;
}

void ContratoMovil:: setNacionalidad(const char* nac)
{
    char* nueva =new char[strlen(nac)+1];
    strcpy(nueva, nac);
    delete[] nacionalidad;
    nacionalidad= nueva;

}
void ContratoMovil::ver() const
{
    cout << getDniContrato() << " (" << getIdContrato() << " - ";
    cout << getFechaContrato();
    cout << ") " << minutosHablados << "m, " << nacionalidad << " "
         << std::fixed << std::setprecision(2) << precioMinuto;
}
double ContratoMovil::factura() const
{
    return precioMinuto*minutosHablados;
}

std::ostream& operator<<(std::ostream& os, const ContratoMovil& cm) {
    os << static_cast<const Contrato&>(cm) << " "
       << cm.getMinutosHablados() << "m, "
       << cm.getNacionalidad() << " "
       << std::fixed << std::setprecision(2) << cm.getPrecioMinuto()
       << " - " << std::fixed << std::setprecision(2) << cm.factura() << "€";  // ✅ AÑADIR ESTO
    return os;
}
