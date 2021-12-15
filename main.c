#include <nSystem.h>

typedef struct{
    nMonitor nom;
    int size;
    int count;
    
}* buff;


nMonitor mon;
// cola que almacena los precios de las ofertas
precios = PriQueue *MakePriQueue();

nCondition adjudicacion;//son los procesos que son candidatos a adjudicarce una unidad 

int punidades;
int contador;
int contadorLlamadas = 0;
int montoRecaudado;
/*s
    nCondition nMakeCondition(nMonitor mon): es como un cola de espera, donde quedan los procesos esperando
    void nWaitCondition (nCondition cond): el proceso se queda en espera pasiva
    void nSignalCondition(nCondition cond): despierta los procesos(grupo de procesos) 


*/
llamadasAOfrecer(){  //Esto no esta funcionando, pero es una idea
    while(contadorLlamadas <= punidades){
        contadorLlamadas+=1;
    }
    contadorLlamadas;
   // return contadorLlamadas; 
}
int largoCola(){
    return PriLength(precios);
}
int ofrecer (double precio){
   /*Se ingresa el monitor solo cuando quiero protejer algo
   // se tiene que guardar los precios

   //extrae el precio cuando sobrepaso las punidades
   //Patron de uso
   Si sobrepaso las punidades debe quitar la menor oferta 
   */

   llamadasAOfrecer();
    nEnter(mon);
    while(largoCola > punidades){
        nWaitCondition(adjudicacion);
    }
    //paso y agrego a la cola
    PriPut(precios, agrego un puntero al threads, precio);//la prioridad es numero pero no sé a que se refiere
    nNotifyAll(m);

    nExit(mon);    

   
    /* 
        Esta funcion espera hasta que se llame a la funcion adjudicar en cuyo caso se retornA TRUE
        y el hilos que llama es el ganador con otros que ofrecioron un precio mayor
        Si el precio es menor al que ofrecioron los otros retorna FALSE
    */
   
}

double adjudicar(int *punidades){
    
    nEnter(mon);
        while(/*mientras no*/){

        }
        nSignalCondition(adjudicacion);
    nExit(mon);
    /*
        Determina el ganador haciendo que todas las llamada a ofrecer retorne TRUE 
        Retorna el monto recaudado = suma(precios ofrecidos)
        *punidades = unidades vendidas 
    */
}