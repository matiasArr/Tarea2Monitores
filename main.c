#include <nSystem.h>

#DEFINE TRUE 1;
#DEFINE FALSE 2;

typedef enum {
    GANADOR,
    SINRESPUESTA
} Resol;

//ver si se puede usar un struct en un metodo
struct oferta{
    double precio,
    Resol estado
};

nMonitor mon;
// cola que almacena los precios de las ofertas
precios = PriQueue * MakePriQueue();

nCondition adjudicacion; //son los procesos que son candidatos a adjudicarce una unidad

int punidades;


int ofrecer(double precio){

    //crear oferta
    oferta o = {
        precio, 
        SINRESPUESTA
    }

    nEnter(mon);

    if (PriLength(precios) >= punidades){
        //obtengo el menor de la cola
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

    if(o.estado==GANADOR){

        nSignalCondition(adjudicacion);
        nExit(mon);
        return TRUE;
    }

    // despues que se haya adjudicados se sacan de la cola y todos retornan 1
    nSignalCondition(adjudicacion);
    nExit(mon);
    return FALSE;
    

}

double adjudicar(int *punidades){

    nEnter(mon);
    double suma = 0;

    while (PriLength(p)>0){
        oferta *p = PriGet(precios);
        
        p->estado=GANADOR;
        suma+=p->precio;

    }
    nSignalCondition(adjudicacion);
    nExit(mon);

    return suma;
}