#include <nSystem.h>

#DEFINE TRUE 1;
#DEFINE FALSE 2;


typedef struct
{
    nMonitor nom;
    int size;
    int count;

} * buff;

long ganadores[N];

nMonitor mon;
// cola que almacena los precios de las ofertas
precios = PriQueue * MakePriQueue();

nCondition adjudicacion; //son los procesos que son candidatos a adjudicarce una unidad

int punidades;

int contador = 0;

int contadorLlamadas = 0;
int montoRecaudado;
/*s
    nCondition nMakeCondition(nMonitor mon): es como un cola de espera, donde quedan los procesos esperando
    void nWaitCondition (nCondition cond): el proceso se queda en espera pasiva
    void nSignalCondition(nCondition cond): despierta los procesos(grupo de procesos) 


*/
llamadasAOfrecer()
{ //Esto no esta funcionando, pero es una idea
    while (contadorLlamadas <= punidades)
    {
        contadorLlamadas += 1;
    }
    contadorLlamadas;
    // return contadorLlamadas;
}
int largoCola()
{
    return PriLength(precios);
}
int ofrecer(double precio)
{
    /*Se ingresa el monitor solo cuando quiero protejer algo
   // se tiene que guardar los precios

   //extrae el precio cuando sobrepaso las punidades
   //Patron de uso
   Si sobrepaso las punidades debe quitar la menor oferta 
   */

    // • PriQueue *MakePriQueue(): entrega una nueva cola.
    // • void PriPut(PriQueue *q, void *ptr, double pri): agrega el objeto ptr con prioridad pri.
    // • void *PriGet(PriQueue *q): entrega y extrae el objeto cuya prioridad tiene el valor numérico menor.
    // • int PriLength(PriQueue *q): entrega el largo de la cola.

    //buscar maneras de generar ids unicos
    long id = system.date.getCurrentTime();

    //ver si se puede usar un struct en un metodo
    struct oferta
    {
        long id,
        double precio
    };

    oferta -> id = contador;
    oferta -> precio = precio;

    ofre.id = id;
    ofre.precio = precio;

    nEnter(mon);

    if (PriLength(precios) >= punidades)
    {
        //obtengo el menor de la cola
        void *min = PriGet(precios)

            //quedarse con la mayor oferta
            if (min.precio > precio)
        {
            //se usa así?(precios, min, min.precio))
            PriPut(precios, min, min.precio);
        }
        else
        {
            //al menor de la cola le retorno = 2 == false
            return 2;
            //ingreso a la cola al actual
            PriPut(precios, ofre, precio);
        }
    }
    else
    {
        //ingreso a la cola al actual
        PriPut(precios, ofre, precio);
    }
    // Encola a la condition posibles ganardores
    nWaitCondition(posiblesGanadores);
    // despues que se haya adjudicados se sacan de la cola y todos retornan 1 
    
    nWaitCondition(adjudicacion);

    for (int i = 0; i < ganador.length; i++)
    {
        if (ganador[i] == id)
        {

            nNotifyAll(m);
            nExit(mon);
            return true;
        }
    }
    //paso y agrego a la cola
    nNotifyAll(m);
    nExit(mon);
    false;

    /* 
        Esta funcion espera hasta que se llame a la funcion adjudicar en cuyo caso se retornA TRUE
        y el hilos que llama es el ganador con otros que ofrecioron un precio mayor
        Si el precio es menor al que ofrecioron los otros retorna FALSE
    */
}

double adjudicar(int *punidades)
{

    nEnter(mon);
    int i = 0;
    double suma = 0;
    while (/*mientras la pila tenga elementos*/)
    {
        void * p = PriGet(precios)
        ganardores[i]=p.id;
        suma+= p.precio;
        i++;

        //OTRA FORMA
        //HACER LAS RESTA ENTRE: EL TOTAL DE OFERTAS - PUNIDADES = RESULTADO
        //SE RECORRE EL ARREGLO HASTA EL RESULTADO Y TODOS SE RETORNAR FALSE Y SE SACAN
        for (int i = 0; i < precios; i++)
        {
            /* code */
        }
        
    }
    nSignalCondition(adjudicacion);
    nExit(mon);

    return suma;
    /*
        Determina el ganador haciendo que todas las llamada a ofrecer retorne TRUE 
        Retorna el monto recaudado = suma(precios ofrecidos)
        *punidades = unidades vendidas 
    */
}