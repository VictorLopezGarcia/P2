/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: López García, Víctor LOGIN 1: victor.lopezg@udc.es
 * AUTHOR 2: García Iglesias, Iago LOGIN 2: iago.garcia.iglesias@udc.es
 * GROUP: 2.4
 * DATE: 12 / 04 / 2024
 */

#ifndef USER_LIST_H
#define USER_LIST_H
#define NULLU NULL


#include "types.h"
#include "song_list.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node *tPosU;

typedef struct tItemU{
    tUserName userName;
    tPlayTime totalPlayTime;
    tUserCategory userCategory;
    tListS songList;
}tItemU;

typedef struct Node{
    tItemU user;
    tPosU next;
}Node;

typedef tPosU tListU;


void createEmptyListU(tListU *L);
bool isEmptyListU(tListU L);
tPosU firstU(tListU L) ;
tPosU lastU(tListU L);
tPosU nextU(tPosU p, tListU L);
tPosU previousU(tPosU p, tListU L);
bool insertItemU(tItemU d, tListU *L);
void deleteAtPositionU(tPosU p, tListU *L);
tItemU getItemU(tPosU p, tListU L);
void updateItemU(tItemU d , tPosU p, tListU *L);
tPosU findItemU(tUserName d, tListU L);


#endif
