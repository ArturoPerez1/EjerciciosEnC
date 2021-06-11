#include <stdio.h>
#include <stdlib.h>

struct Node{
    int valor;
    struct Node * next;
};


void crearNode(struct Node** new_node)
{
   *new_node = (struct Node*) malloc(sizeof(struct Node)); 
}



void apilar(struct Node** head_ref,int new_data)
{
        struct Node* new_node;
        crearNode(&new_node);
        new_node->valor  = new_data;
        new_node->next = (*head_ref);
        (*head_ref)    = new_node;
        system("cls");
}


void deleteNode(struct Node**head_ref)
{
     struct Node*eliminado = *head_ref;
     *head_ref = eliminado->next;
     free(eliminado); // Free memory
}

void printList(struct Node* aux)
{
    if(aux->next == NULL){
        printf(" %d ", aux->valor);
    }else {
        printf("El tope: ");
        while (aux != NULL) {
            printf(" |%d| ->", aux->valor);
            aux = aux ->next;
        }
        printf(" Null");
    }
}







int main(){
    system("cls");
    struct Node* head = NULL;
    int new_data;
    int menu = 0;
    while(menu != 4)
    {
        printf("           Menu interactivo de pilas\n");
        printf("                    1:Apilar \n");
        printf("                    2:Desapilar\n");
        printf("                    3:Mostrar pila\n");
        printf("                    4:salir\n");
        printf("                    opcion: ");
        scanf("%i", &menu);
        system("cls");

        switch (menu) {
            case 1:
                    printf("Introduzca la data: ");
                    scanf("%i", &new_data);
                    apilar(&head, new_data);
            break;
            case 2:
                if(head->next == NULL){
                        printf("Este es el tope, no hay mas datos\n");
                        system("pause");
                        system("cls"); 
                    }
                else{
                        printf("El tope es: |%i|\n", head->valor);
                        system("pause");
                        system("cls");
                        deleteNode(&head);
                        printf("La Nuevo tope es: |%i|\n", head->valor);
                        system("pause");
                        system("cls");
                    }

            break;
            case 3:
                    printf("\n Los valores de nodo son: ");
                    printList(head);
                    printf("\n");
                    system("pause");
                    system("cls");
            break;
            case 4:
                    printf("Gracias por usar el programa");
            break;
            default:
                    printf("\n             La opcion es invalida\n\n\n\n");
        }
    }
    return 0;
}