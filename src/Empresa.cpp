#include "Empresa.h"
#include <typeinfo>
#include <cstring>
#include <iomanip>

/*static const int MAX_CLIENTES = 100;
    Cliente* clientes[MAX_CLIENTES];
    int nClientes;
    Contrato** contratos;
    int nContratosActual;
    int capacidadContratos;*/

Empresa::Empresa()
{
    nClientes=0;
    for(int i=0; i<MAX_CLIENTES; i++){
        clientes[i]=nullptr; //porque clientes es array puntero
    }

    capacidadContratos=10;
    contratos=new Contrato*[capacidadContratos];
    nContratosActual=0;

    for(int i=0; i<capacidadContratos; i++){
        contratos[i]=nullptr; //porque clientes es array puntero
    }
}

Empresa::~Empresa()
{
    for(int i=0; i<nClientes; i++) {
        delete clientes[i];
        clientes[i]=nullptr;
    }

    for (int i=0; i<nContratosActual; i++){
        delete contratos[i];
        contratos[i]=nullptr;
    }

    delete[] contratos;
    contratos=nullptr;
}

// buscar un cliente por DNI
    // Devuelve el índice donde está el cliente, o -1 si no existe
int Empresa::buscarCliente(long dni) const
{
    for(int i=0; i<nClientes;i++){
        if(clientes[i]->getDni()==dni){
            return i;
        }
    }
    return-1;
}

    // buscar un contrato por ID
    // Devuelve el índice donde está el contrato, o -1 si no existe
    int Empresa::buscarContrato(int idContrato) const
    {
        for(int i=0; i<nContratosActual; i++){
            if(contratos[i]->getIdContrato()==idContrato){
                return i;
            }
        }
        return -1;
    }

    // aumentar la capacidad del array de contratos
    // Duplica el tamaño cuando se llena: 10,20,40,80...
    void Empresa::aumentarCapacidadContratos()
    {
        int nuevaCapacidad=capacidadContratos*2;
        //puntero que apunta a un array de punteros, array de nuevaCapacidad(nº) punteros,
         Contrato** nuevoArray = new Contrato*[nuevaCapacidad];
         for(int i=0; i<nContratosActual; i++){
            nuevoArray[i]=contratos[i];
         }
         //los creados nuevos los pongo a nullptr
         for(int i=nContratosActual; i<nuevaCapacidad;i++){
            nuevoArray[i]=nullptr;
         }

         delete[] contratos;
         contratos=nuevoArray;
         capacidadContratos=nuevaCapacidad;
    }

    // Método para crear un nuevo contrato
    // Pide datos al usuario, verifica si el cliente existe
    // Si no existe, lo crea. Luego crea el contrato solicitado
    /*    static int contadorIds;
    int idContrato;
    long int dniContrato;
    Fecha fechaContrato;

    long int dni;
    char *nombre;
    Fecha fechaAlta;
    */
    void Empresa::crearContrato()
    {
        long dni;
        cout<<"Introduzca dni: ";
        cin>>dni;

        int posCliente=buscarCliente(dni);
        //crear nuevo: Contrato(long dniCon, const Fecha& f), setFecha(Fecha f);
        if(posCliente==-1){
            if(nClientes>=MAX_CLIENTES){
                cout<<"No se pueden agregar más clientes, ya hay 100"<<endl;
                return;
            }
            else{
                cout<<"nombre del cliente: ";
                cin.ignore(); //limpiar buffer
                char nombre[100];
                cin.getline(nombre, 100);

                int dia, mes, anio;
                cout<<"Introduce la fecha de alta"<<endl;
                cout<<"Dia: ";
                cin>>dia;
                cout<<"mes: ";
                cin>>mes;
                cout<<"anio: ";
                cin>>anio;

                Fecha fechaAlta(dia, mes, anio);

                clientes[nClientes]=new Cliente(dni, nombre, fechaAlta);
                posCliente=nClientes;
                nClientes++;
            }
        }
        int tipoContrato;
        cout<<"Introduzca tipo de contrato que quiere abrir (1 tarifa plana, 2 movil): ";
        cin>>tipoContrato;

        cout<<"Fecha del contrato: "<<endl;
        int dia, mes, anio;
        cout<<"Dia: ";
        cin>>dia;
        cout<<"mes: ";
        cin>>mes;
        cout<<"anio: ";
        cin>>anio;
        Fecha fechaContrato(dia, mes, anio);

        int minutos;
        cout<<"Introduce los minutos hablados: ";
        cin>>minutos;

        if(nContratosActual>=capacidadContratos){
            aumentarCapacidadContratos();
        }

        if(tipoContrato==1){
            contratos[nContratosActual]=new ContratoTP(dni, fechaContrato, minutos);
            nContratosActual++;
        }else if(tipoContrato==2){
            double precioMinuto;
        std::cout << "Precio minuto: ";
        std::cin >> precioMinuto;

        std::cout << "Nacionalidad: ";
        char nacionalidad[50];
        std::cin >> nacionalidad;

        contratos[nContratosActual] = new ContratoMovil(dni, fechaContrato, precioMinuto, minutos, nacionalidad);
        nContratosActual++;
        }

    }

    // Cancela un contrato dado su ID
    // Devuelve true si se canceló, false si no existe
    bool Empresa::cancelarContrato(int idContrato)
    {
        int pos= buscarContrato(idContrato);

        if(pos==-1){
            return false;
        }

        delete contratos[pos];
        //desplazar contratos posteriores hacia atras para no dejar hueco
        for(int i=pos; i<nContratosActual-1;i++){
            contratos[i]=contratos[i+1];
        }

        nContratosActual--;
        contratos[nContratosActual]=nullptr;

        return true;

    }

    // Da de baja un cliente y TODOS sus contratos
    // Devuelve true si se dio de baja, false si no existe
    bool Empresa::bajaCliente(long dni)
    {
        int posCliente=buscarCliente(dni);
        if(posCliente==-1){
            return false; //no existe cliente
        }
        for(int i=nContratosActual-1;i>=0;i--){
            if(contratos[i]->getDniContrato()==dni){
                delete contratos[i];
                //Desplazar contratos detras
                for(int j=i;j<nContratosActual-1;j++){
                    contratos[j]=contratos[j+1];
                }
                nContratosActual--;
                contratos[nContratosActual]=nullptr;
            }
        }
        delete clientes[posCliente];
        for(int i=posCliente;i<nClientes-1;i++){
            clientes[i]=clientes[i+1];
        }
        nClientes--;
        clientes[nClientes]=nullptr;

        return true;
    }

    // Muestra todos los clientes y contratos de la empresa
    void Empresa::ver() const
    {
        cout<<"La empresa tiene "<<nClientes<<" clientes y "
        <<nContratosActual<<" contratos"<<endl;

        cout<<"Clientes: "<<endl;
        for(int i=0; i<nClientes;i++){
            cout<<*clientes[i]<<endl;
        }
        cout<<"Contratos: "<<endl;
        for(int i=0;i<nContratosActual;i++){
            contratos[i]->ver();
            cout << " - " << std::fixed << std::setprecision(2)
                  << contratos[i]->factura() << "€\n";
        }
    }

    void Empresa::descuento(float porcentaje)
    {
        //  dynamic_cast convertir Contrato* a *ContratoMovil, sino devuelve nullptr y no hay que hacer nada
        for(int i=0; i<nContratosActual;i++){
            ContratoMovil* cm=dynamic_cast<ContratoMovil*>(contratos[i]);
            if(cm!=nullptr){
                double precioActual=cm->getPrecioMinuto();
                double nuevoPrecio=precioActual*(1-porcentaje/100.0);
                cm->setPrecioMinuto(nuevoPrecio);
            }
        }

    }

    // Devuelve el número de contratos de Tarifa Plana
    // Usa typeid para identificar el tipo de contrato
    int Empresa::nContratosTP() const{
        int contador=0;
        for(int i=0; i<nContratosActual;i++){
            if(typeid(*contratos[i])==typeid(ContratoTP)){
                contador++;
            }
        }
        return contador;
    }

    // Método auxiliar para cargar datos de prueba
    // Crea 3 clientes y 7 contratos automáticamente
    void Empresa::cargarDatos()
    {

    Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002);
 this->clientes[0] = new Cliente(75547001, "Peter Lee", f1);
 this->clientes[1] = new Cliente(45999000, "Juan Perez", Fecha(29,2,2000));
 this->clientes[2] = new Cliente(37000017, "Luis Bono", f2);
 this->nClientes=3;
 this->contratos[0] = new ContratoMovil(75547001, f1, 0.12, 110, "DANES"); //habla 110m a 0.12€/m
 this->contratos[1] = new ContratoMovil(75547001, f2, 0.09, 170, "DANES"); //habla 170m a 0.09€/m
 this->contratos[2] = new ContratoTP(37000017, f3, 250); //habla 250m (300m a 10€, exceso 0.15€/m)
 this->contratos[3] = new ContratoTP(75547001, f1, 312); //habla 312m (300m a 10€, exceso 0.15€/m)
 this->contratos[4] = new ContratoMovil(45999000, f2, 0.10, 202, "ESPAÑOL"); //habla 202m a 0.10/m
 this->contratos[5] = new ContratoMovil(75547001, f2, 0.15, 80, "DANES"); //habla 80m a 0.15€/m
 this->contratos[6] = new ContratoTP(45999000, f3, 400); //habla 400m (300m a 10€, exceso 0.15€/m)
 this->nContratosActual=7; }
