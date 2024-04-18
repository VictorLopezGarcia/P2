/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: López García, Víctor LOGIN 1: victor.lopezg@udc.es
 * AUTHOR 2: García Iglesias, Iago LOGIN 2: iago.garcia.iglesias@udc.es
 * GROUP: 2.4
 * DATE: 12 / 04 / 2024
 */

#ifndef SONG_LIST_H
#define SONG_LIST_H
#define MAX_ELEMENTOS 25
#define NULLS -1


#include "types.h"
#include <string.h>

    typedef int tPosS;
    typedef tSong tItemS;

    typedef struct tListS{
        tItemS canciones[MAX_ELEMENTOS];
        tPosS ultPos;
    }tListS;

    void createEmptyListS(tListS *L);
    bool isEmptyListS(tListS L);
    tPosS firstS(tListS L) ;
    tPosS lastS(tListS L);
    tPosS nextS(tPosS p, tListS L);
    tPosS previousS(tPosS p, tListS L);
    bool insertItemS(tItemS d, tPosS p, tListS *L);
    void deleteAtPositionS(tPosS p, tListS *L);
    tItemS getItemS(tPosS p, tListS L);
    void updateItemS(tItemS d , tPosS p, tListS *L);
    tPosS findItemS(tSongTitle d, tListS L);


#endif