#include <nSystem.h>

typedef struct{
    nMonitor nom;
    int size;
    int count;
    
}* buff;


nMonitor mon;
cola = PriQueue *MakePriQueue();

nCondition adjudicacion;//son los procesos que son candidatos a adjudicarce una unidad 

int punidades;
int contador;
/*s
    nCondition nMakeCondition(nMonitor mon): es como un cola de espera, donde quedan los procesos esperando
    void nWaitCondition (nCondition cond): el proceso se queda en espera pasiva
    void nSignalCondition(nCondition cond): despierta los procesos(grupo de procesos) 


*/
int ofrecer (double precio){
   //Se ingresa el monitor solo cuando quiero protejer algo
   // se tiene que guardar los precios
   //Patron de uso
   
    nEnter(mon);
    while(contador > punidades){
        nWaitCondition(adjudicacion);
    }
    if (PriLength(cola) == 0 ){
        PriPut(cola, agrego un puntero al objeto, precio);//la prioridad es numero pero no sé a que se refiere
    }else{
        //debo 
    }
    
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
        while(){

        }
        nSignalCondition(adjudicacion);
    nExit(mon);
    /*
        Determina el ganador haciendo que todas las llamada a ofrecer retorne TRUE 
        Retorna el monto recaudado = suma(precios ofrecidos)
        *punidades = unidades vendidas 
    */
}