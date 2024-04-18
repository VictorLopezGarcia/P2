/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: López García, Víctor LOGIN 1: victor.lopezg@udc.es
 * AUTHOR 2: García Iglesias, Iago LOGIN 2: iago.garcia.iglesias@udc.es
 * GROUP: 2.4
 * DATE: 12 / 04 / 2024
 */

#include "song_list.h"


void createEmptyListS(tListS *L){
    L->ultPos = NULLS;
}

bool isEmptyListS(tListS L){
    if(L.ultPos == NULLS) return true;
    else return false;
}

tPosS firstS(tListS L){
    if (!isEmptyListS(L)){
        return 0;
    }
    return NULLS;
}

tPosS lastS(tListS L){
    return L.ultPos;
}
tPosS nextS(tPosS p, tListS L){
    if(p > NULLS && p < L.ultPos){
        return p+1;
    }
    return NULLS;
}


tPosS previousS(tPosS p, tListS L){
    if(p > 0 && p <= L.ultPos){
        return p-1;
    }
    return NULLS;
}

bool insertItemS(tItemS d, tPosS p, tListS *L){
    if(p >= NULLS && p < MAX_ELEMENTOS && L -> ultPos < MAX_ELEMENTOS-1)
    {
        if(p == NULLS || p > L -> ultPos)
        {
            L -> canciones[L -> ultPos+1] = d;
            L -> ultPos++;
            return true;
        }
        else {
            for (int i = L -> ultPos; i >= p ; --i) {
                L -> canciones[i+1] = L -> canciones[i];
            }
            L -> canciones[p] = d;
            L -> ultPos++;
            return true;
        }
    }
    else return false;


}
void deleteAtPositionS(tPosS p, tListS *L){
    if (p <= L -> ultPos && p > NULLS){
        for (int i = p; i < L -> ultPos; ++i) {
            L -> canciones[i]=L -> canciones[i+1];
        }
        L -> ultPos--;
    }
}

tItemS getItemS(tPosS p, tListS L){
    if (p <= L.ultPos && p > NULLS){
        return L.canciones[p];
    }
}

void updateItemS(tItemS d , tPosS p, tListS *L){
    if (p <= L -> ultPos && p > NULLS){
        L -> canciones[p] = d;
    }
}
tPosS findItemS(tSongTitle d, tListS L){
    tPosS i;
    if(!isEmptyListS(L)){
        for (i = 0; i <= L.ultPos; ++i) {
            if(strcmp(d,L.canciones[i].songTitle)==0)
            {
                return i;
            }
        }
    }
    return NULLS;
}

/* Write your code here... */