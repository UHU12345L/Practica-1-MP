#ifndef EMPRESA_H
#define EMPRESA_H

//lista contratos array dinamico
//lista clientes 100 max

#include "Cliente.h"
#include "Contrato.h" // definicion de la clase Contrato
#include "ContratoTP.h" // definicion de la clase ContratoTP
#include "ContratoMovil.h" // definicion de la clase ContratoMovil
#include <iostream>

//Empresa polimórfica
class Empresa
{
private:
    // Array ESTÁTICO de clientes (máximo 100)
    static const int MAX_CLIENTES = 100;
    Cliente* clientes[MAX_CLIENTES];  // Array de punteros a Cliente
    int nClientes;                     // Número actual de clientes

    const int nmaxcli;

    // Array DINÁMICO de contratos
    Contrato** contratos;  // Puntero a array de punteros a Contrato
    int nContratosActual;  // Número actual de contratos
    int capacidadContratos; // Capacidad actual del array (10, 20, 40, 80...)

    // buscar un cliente por DNI
    // Devuelve el índice donde está el cliente, o -1 si no existe
    int buscarCliente(long dni) const;

    // buscar un contrato por ID
    // Devuelve el índice donde está el contrato, o -1 si no existe
    int buscarContrato(int idContrato) const;

    // aumentar la capacidad del array de contratos
    // Duplica el tamaño cuando se llena: 10,20,40,80...
    void aumentarCapacidadContratos();

public:
    Empresa();

    ~Empresa();

    // Método para crear un nuevo contrato
    // Pide datos al usuario, verifica si el cliente existe
    // Si no existe, lo crea. Luego crea el contrato solicitado
    void crearContrato();

    // Cancela un contrato dado su ID
    // Devuelve true si se canceló, false si no existe
    bool cancelarContrato(int idContrato);

    // Da de baja un cliente y TODOS sus contratos
    // Devuelve true si se dio de baja, false si no existe
    bool bajaCliente(long dni);

    // Muestra todos los clientes y contratos de la empresa
    void ver() const;

    // Aplica un descuento (en %) a todos los contratos móviles
    // Usa dynamic_cast para identificar ContratoMovil
    void descuento(float porcentaje);

    // Devuelve el número de contratos de Tarifa Plana
    // Usa typeid para identificar el tipo de contrato
    int nContratosTP() const;

    // Método auxiliar para cargar datos de prueba
    // Crea 3 clientes y 7 contratos automáticamente
    void cargarDatos();
};

#endif // EMPRESA_H
