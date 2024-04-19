/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: López García, Víctor LOGIN 1: victor.lopezg@udc.es
 * AUTHOR 2: García Iglesias, Iago LOGIN 2: iago.garcia.iglesias@udc.es
 * GROUP: 2.4
 * DATE: 12 / 04 / 2024
 */

#include "user_list.h"
#include "song_list.h"


void createEmptyListU(tListU *L){ //Inicializa lista con primer nodo nulo
    *L = NULLU;
}

bool isEmptyListU(tListU L){ //Devuelve true si el primer nodo está vacio (lista vacía)
    return L == NULLU;
}

tPosU firstU(tListU L){ //Devuelve el primer nodo
    return L;
}

tPosU lastU(tListU L){ //recorre todos los nodos hasta encontrar el primero que no tenga hijo
    tPosU temp = L;
    while (temp->next != NULLU){
        temp = temp->next;
    }
    return temp;
}

tPosU nextU(tPosU p, tListU L){ //Devuelve el hijo del nodo pasado
    if (isEmptyListU(L)) return  NULLU;
    else{
        tPosU temp = L;
        while(temp != p && temp!=NULLU){
            temp = temp->next;
        }
        return temp->next;
    }
}

tPosU previousU(tPosU p, tListU L){ //Recorre desde el nodo inicial hasta encontrar el nodo cuyo hijo concuerde con el posterior
    tPosU temp = L;
    while(temp->next !=p && temp!=NULLU){
        temp = temp->next;
    }
    return temp;
}

bool insertItemU(tItemU d, tListU *L){
    tPosU node = malloc(sizeof(struct Node));//Asigna espacio de memoria para el nuevo item
    if(node == NULLU) return false;
    else{                                         // Añade el item en la posicion que le corresponde dependiendo de la pasada por parametro
        node -> user = d;
        node -> next = NULLU;
        if(isEmptyListU(*L) ){
            *L = node;
        }

        else{
           tPosU temp = *L;
            if(strcmp(temp->user.userName, d.userName)>0){
                *L = node;
                node->next = temp;
            }else{
                while(temp->next != NULLU && strcmp(temp->next->user.userName, d.userName)<0){
                    temp = temp->next;
                }
                node->next = temp->next;
                temp->next = node;
            }
        }
        node->user.songList = malloc(sizeof(tListS));
        createEmptyListS(node->user.songList);
        return true;
    }
}

void deleteAtPositionU(tPosU p, tListU *L){  //asigna al hijo del padre su propio hijo para no romper la cadena
    if(!isEmptyListU(*L)) {
        if(p==*L){
            *L = p->next;
        }
        else{
            previousU(p, *L)->next = p->next;
        }
        free(p->user.songList);
        free(p); //Posteriormente libera la memoria asignada a este item
    }
}

tItemU getItemU(tPosU p, tListU L){
    return p->user; //Devuelve los datos del nodo pasado por parametro
}

void updateItemU(tItemU d , tPosU p, tListU *L){
    if(!isEmptyListU(*L))p->user = d;  //Actualiza los datos del nodo pasado por parametro
}

tPosU findItemU(tUserName d, tListU L) { //Recorre todos los items hasta encontrar el que coincida con el username pasado por parametro
    tPosU temp = L;
    while (temp != NULLU) {
        if (strcmp(temp->user.userName, d) == 0) {
            return temp;
        }
        else if(strcmp(temp->user.userName, d)>0) return NULLU;
        temp = temp->next;
    }
    return NULLU;
}