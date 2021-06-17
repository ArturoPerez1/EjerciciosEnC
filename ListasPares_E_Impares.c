#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int valor;
    struct Node * siguiente;
};

void crearNode(struct Node ** nodo)
{
    *nodo = (struct Node*) malloc(sizeof(struct Node));
}


void InsectarNodoFinal(struct Node ** Cabeza, int valor)
{
    struct Node * nodo;
    crearNode(&nodo);
    nodo->valor = valor;
    nodo->siguiente = NULL;
    struct Node * CabezaAux = *Cabeza;
    if(CabezaAux == NULL)
    {
        *Cabeza = nodo;
    }
    else
    {
        while(CabezaAux->siguiente != NULL)
        {
            CabezaAux = CabezaAux->siguiente;
        }
        CabezaAux->siguiente = nodo;

    }
}

void EliminarPares(struct Node ** Pares)
{
    struct Node* ParesAux = *Pares;
    struct Node* ParesAux1;

    if(ParesAux->siguiente == NULL && ParesAux->valor %2 == 0)
    {
        *Pares = ParesAux->siguiente;
        free(ParesAux);
    }
    else
    {

        while(ParesAux != NULL) {
            if (ParesAux->valor % 2 == 0) {
                *Pares = ParesAux->siguiente;
                free(ParesAux);
                ParesAux = *Pares;
            }
           if (ParesAux->siguiente != NULL){
               if ((ParesAux->siguiente->valor % 2 == 0)) {
                ParesAux1 = ParesAux->siguiente->siguiente;
                free(ParesAux->siguiente);
                ParesAux->siguiente = ParesAux1;
                ParesAux = ParesAux->siguiente;
             }
          }
            if(ParesAux != NULL) {
                if (ParesAux->siguiente == NULL)
                {
                    ParesAux = ParesAux->siguiente;
                }
                else
                {
                    if (ParesAux->siguiente != NULL)
                    {
                        ParesAux = ParesAux->siguiente;
                    }
                }

            }
        }
    }
}

void ImprimirLista(struct Node * Imprimir)
{
    int contador = 0;
    if(Imprimir->siguiente == NULL)
    {
        printf("Nodo[0] == valor[%i]", Imprimir->valor);
    }
    else
    {
        while(Imprimir != NULL)
        {

            printf("( Nodo[%i] == Valor[%i] ) -> ", contador, Imprimir->valor );
            contador++;
            Imprimir = Imprimir->siguiente;
        }
        printf(" NULL");
    }

}


int main()
{
    system("cls");
    int exit = 0;
    int data;
    struct Node*Cabeza = NULL;

    do{
        printf("      MENU LISTAS");
        printf("\n    1: InsertarFinal");
        printf("\n    2: Mostrar Lista");
        printf("\n    3: Quitar Pares");
        printf("\n    4:Salir");
        printf("\n    Opcion: ");
        scanf("%i", &exit);


        switch(exit){
            case 1:
                printf("\n\nIntroduzca la data: ");
                scanf("%i", &data);
                InsectarNodoFinal(&Cabeza, data);
                system("cls");
                break;
            case 2:
                if(Cabeza == NULL){
                    printf("\n\nLista Vacia\n");
                    system("pause");
                    system("cls");
                }
                else{
                    system("cls");
                    ImprimirLista(Cabeza);
                    printf("\n\n\n");
                    system("pause");
                    system("cls");
                }

                break;
            case 3:
                if(Cabeza == NULL)
                {
                    printf("Lista Vacia\n");
                }
                else
                {
                    EliminarPares(&Cabeza);
                    system("cls");
                }

                break;
            case 4:
                printf("\nMuchas gracias por usar el programa");
                break;
            default:
                printf("\nOpcion invalida");
                break;
        }
    }while(exit != 4);
}

