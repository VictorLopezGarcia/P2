/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: López García, Víctor LOGIN 1: victor.lopezg@udc.es
 * AUTHOR 2: García Iglesias, Iago LOGIN 2: iago.garcia.iglesias@udc.es
 * GROUP: 2.4
 * DATE: 12 / 04 / 2024
 */

#ifndef PRO2_2023_P2_TYPES_H
#define PRO2_2023_P2_TYPES_H

#define NAME_LENGTH_LIMIT 25
#include <stdbool.h>

typedef char tUserName[NAME_LENGTH_LIMIT];
typedef enum {basic, pro} tUserCategory;
typedef int tPlayTime;
typedef char tSongTitle[NAME_LENGTH_LIMIT];

typedef struct Song{
    tSongTitle songTitle;
    tPlayTime playTime;
} tSong;

#endif //PRO2_2023_P2_TYPES_H
