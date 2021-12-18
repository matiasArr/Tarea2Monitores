#include <nSystem.h>

#DEFINE TRUE 1;
#DEFINE FALSE 2;

//estructura para los posibles estados de cada oferta
typedef enum {
    GANADOR,
    SINRESPUESTA
} Resol;

//estructura de cada oferta realizada
struct oferta{
    double precio,
    Resol estado
};

//monitor
nMonitor mon;

// cola que almacena los precios de las ofertas
precios = PriQueue * MakePriQueue();

//son los procesos que son candidatos a adjudicarce una unidad
nCondition adjudicacion; 

int punidades;


int ofrecer(double precio){

    //crear oferta
    oferta o = {
        precio, 
        SINRESPUESTA
    }

    //entrar al monitor
    nEnter(mon);

    //si la cola está llena, entonces se debe comparar el ultima oferta con la oferta actual
    if (PriLength(precios) >= punidades){

        //obtengo la menor oferta de la cola
        void *min = PriGet(precios);

        //quedarse con la mayor oferta
        if (min.precio > precio){
            
            PriPut(precios, min, min.precio);
            
            nExit(mon);
            return FALSE;
        }
        else{
            //ingreso a la cola la oferta actual
            PriPut(precios, o, precio);
        }
    }
    else{
        //ingreso a la cola la oferta actual
        PriPut(precios, o, precio);
    }
    // Encola a la condition posibles ganardores
    nWaitCondition(adjudicacion);

    //validad si el proceso es ganador
    if(o.estado==GANADOR){

        nExit(mon);
        return TRUE;
    }

    nExit(mon);
    return FALSE;
}

double adjudicar(int *punidades){

    //entrar al monitor
    nEnter(mon);
    double suma = 0;

    //iterar por todos los ganadores que están en la cola
    while (PriLength(p)>0){
        oferta *p = PriGet(precios);
        
        //cambiar estado de la oferta ganadora
        p->estado=GANADOR;
        suma+=p->precio;

    }
    //enviar la señal a todas las ofertas que están esperando
    nSignalCondition(adjudicacion);
    nExit(mon);

    //retornar el monto total recaudado
    return suma;
}