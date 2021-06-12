#include <stdio.h>
#include <stdlib.h>

struct Node {
    int valor;
    struct Node *next;
};


void crearNode(struct Node **new_node) {
    *new_node = (struct Node *) malloc(sizeof(struct Node));
}


void apilar(struct Node **head_ref, int new_data) {
    struct Node *new_node;
    crearNode(&new_node);
    new_node->valor = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


void deleteNode(struct Node **head_ref) {
    struct Node *eliminado = *head_ref;
    *head_ref = eliminado->next;
    free(eliminado); // Free memory
}

void printList(struct Node *aux) {
    if (aux->next == NULL) {
        printf(" %d ", aux->valor);
    } else {
        printf("El tope: ");
        while (aux != NULL) {
            printf(" |%d| ->", aux->valor);
            aux = aux->next;
        }
        printf(" Null");
    }
}

int sumarizarPila(struct Node *aux) {
    if (aux->next == NULL) {
        return aux->valor;
    } else {
        return aux->valor + sumarizarPila(aux->next);
    }
}

int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    struct Node *head = NULL;
    int new_data;
    int option = 0;

    do {
        system("clear");
        printf("\n     Menu interactivo de pilas");
        printf("\n       1:Apilar ");
        printf("\n       2:Desapilar");
        printf("\n       3:Mostrar pila");
        printf("\n       4:Factorial");
        printf("\n       5:Sumarizar Pila Recursiva");
        printf("\n       6:Salir");
        printf("\n\n   Introduzca opcion (1-6): ");

        scanf("%i", &option);

        switch (option) {
            case 1:
                printf("Introduzca la data: ");
                scanf("%i", &new_data);

                apilar(&head, new_data);
                break;
            case 2:
                if (head == NULL) {
                    printf("Por favor proceda a apilar datos\n");
                    getchar();
                    system("clear");
                } else {
                    printf("El tope es: |%i|\n", head->valor);
                    getchar();
                    system("clear");
                    deleteNode(&head);
                    if (head) {
                        printf("La Nuevo tope es: |%i|\n", head->valor);
                        getchar();
                        system("clear");
                    } else {
                        printf("Pila Vacia!!\n");
                    }
                }

                break;
            case 3:
                printf("\n Los valores de la pila son: ");
                printList(head);
                printf("\n");
                getchar();
                system("clear");
                break;
            case 4:
                printf("Introduzca el factorial a calcular: ");
                scanf("%i", &new_data);

                printf("El resultado es: %i", factorial(new_data));
                break;
            case 5:
                printf("El resultado es: %i", sumarizarPila(head));
                break;
            case 6:
                printf("Gracias por usar el programa");
                break;

            default:
                printf("\nLa opcion es invalida\n\n\n\n");
        }

    } while (option != 6);

    return 0;
}