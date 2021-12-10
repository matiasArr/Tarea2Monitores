//#include <nSystem.h>
typedef struct{
    nMonitor nom;
    int size;
    int count;
    
}* buff;

int ofrecer (double precio){
    nWait()

    /* 
        Esta funcion espera hasta que se llame a la funcion adjudicar en cuyo caso se retornA TRUE
        y el hilos que llama es el ganador con otros que ofrecioron un precio mayor
        Si el precio es menor al que ofrecioron los otros retorna FALSE
    */
   
}

double adjudicar(int *punidades){
    /*
        Determina el ganador haciendo que todas las llamada a ofrecer retorne TRUE 
        Retorna el monto recaudado = suma(precios ofrecidos)
        *punidades = unidades vendidas 
    */
}