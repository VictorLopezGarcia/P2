/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255


char* catToString(tUserCategory category){
    if(category == 0) return "basic";
    else return "pro";
}


void new(char *param1, char *param2, tListU *userList){
    tItemU item;
    strcpy(item.userName, param1);
    if(strcmp(param2, "basic")==0) item.userCategory=basic; else item.userCategory=pro;
    item.totalPlayTime = 0;
    if(findItemU(item.userName, *userList) == NULLU)
    {
        if(insertItemU(item, userList)){
            printf("* New: user %s category %s\n", item.userName, catToString(item.userCategory));
        }
    }
    else printf("+ Error: New not possible\n");
}

void delete(char *param1, tListU *userList){
    tPosU pos = findItemU(param1, *userList);
    if(pos != NULLU){
        tItemU item = getItemU(pos, *userList);
        deleteAtPositionU(pos, userList);
        printf("* Delete: user %s category %s totalplaytime %d\n", param1, catToString(item.userCategory), item.totalPlayTime);
    }
    else printf("+ Error: Delete not possible\n");
}

void add(char *param1, char *param2, tListU *userList){
    tPosU pos = findItemU(param1, *userList);
    if(pos != NULLU){
        tItemU item = getItemU(pos, *userList);
        if(findItemS(param2, *item.songList) == NULLS){
            tSong cancion;
            strcpy(cancion.songTitle, param2);
            cancion.playTime = 0;
            insertItemS(cancion, NULLS, item.songList);
            printf("* Add: user %s adds song %s\n", param1, cancion.songTitle);
        }else printf("+ Error: Add not possible\n");
    }
    else printf("+ Error: Add not possible\n");
}

void upgrade(char *param1, tListU *list){
    tPosU pos = findItemU(param1, *list);
    tItemU item = getItemU(pos, *list);
    if(pos == NULLU || isEmptyListU(*list) || item.userCategory == pro)
    {
        printf("+ Error: Upgrade not possible\n");
    }else{
        item.userCategory = pro;
        updateItemU(item, pos, list);
        printf("* Upgrade: user %s category %s\n", item.userName, catToString(item.userCategory));
    }
}

void play (char *param1, char *param2, char *param3, tListU *list){
    tPosU pos = findItemU(param1, *list);
    if(pos == NULLU || isEmptyListU(*list))
    {
        printf("+ Error: Play not possible\n");
    }
    else{
        tItemU item = getItemU(pos, *list);
        tPosS songPos = findItemS(param2, *item.songList);
        if(songPos != NULLS){
            tSong cancion = getItemS(songPos, *item.songList);
            cancion.playTime+= (int)strtol(param3, NULL, 10);
            item.totalPlayTime += (int)strtol(param3, NULL, 10);
            updateItemS(cancion, songPos, item.songList);
            updateItemU(item, pos, list);
            printf("* Play: user %s plays song %s playtime %d totalplaytime %d\n", item.userName, cancion.songTitle, cancion.playTime, item.totalPlayTime);
        }
        else printf("+ Error: Play not possible\n");

    }
}

void stats (tListU *list){
    if(isEmptyListU(*list))
    {
        printf("+ Error: Stats not possible");
    }
    else{
        tPosU pos = firstU(*list);
        int basicCont = 0;
        int proCont = 0;
        int basicPlaysCont = 0;
        int proPlaysCont = 0;
        while (pos != NULLU){
            tItemU item = getItemU(pos, *list);
            if(item.userCategory == basic){
                basicCont ++;
                basicPlaysCont += item.totalPlayTime;
            }
            else{
                proCont ++;
                proPlaysCont += item.totalPlayTime;
            }
            printf("\nUser %s category %s totalplaytime %d\n", item.userName, catToString(item.userCategory), item.totalPlayTime);

            if(isEmptyListS(*item.songList)) printf("No songs\n");
            else{
                for (int i = 0; i <= item.songList->ultPos; ++i) {
                    tSong cancion = getItemS(i, *item.songList);
                    printf("Song %s playtime %d\n", cancion.songTitle, cancion.playTime);
                }
            }
            pos = nextU(pos, *list);
        }

        float basicAvg;
        float proAvg;

        if (basicCont != 0) basicAvg = (float)basicPlaysCont/(float)basicCont;
        else basicAvg = 0;

        if(proCont != 0) proAvg = (float)proPlaysCont/(float)proCont;
        else proAvg = 0;

        printf("\nCategory  Users  TimePlay  Average\n");
        printf("Basic     %5d    %6d  %8.2f\n", basicCont, basicPlaysCont, basicAvg);
        printf("Pro       %5d    %6d  %8.2f\n", proCont, proPlaysCont, proAvg);
    }
}

void removeU(char *param1, tListU *list){
    bool delete;
    tPosU pos = firstU(*list);
    tPosU next_pos;
    while (pos != NULLU){
        next_pos = nextU(pos, *list);
        tItemU item = getItemU(pos, *list);
        if(item.userCategory == basic){
            if(item.totalPlayTime > (int)strtol(param1, NULL, 10)){
                printf("Removing user %s totalplaytime %d\n", item.userName, item.totalPlayTime);
                deleteAtPositionU(pos, list);
                delete = true;
            }
        }
        pos = next_pos;
    }
    if(!delete)printf("+ Error: Remove not possible");
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListU *userList) {

    printf("********************\n");
    switch (command) {
        case 'N':
            printf("%s N: user %s category %s\n", commandNumber, param1, param2);
            new(param1, param2, userList);
            break;
        case 'D':
            printf("%s D: user %s\n", commandNumber, param1);
            delete(param1, userList);
            break;
        case 'A':
            printf("%s A: user %s song %s\n", commandNumber, param1, param2);
            add(param1, param2, userList);
            break;
        case 'U':
            printf("%s U: user %s\n", commandNumber, param1);
            upgrade(param1, userList);
            break;
        case 'P':
            printf("%s P: user %s song %s minutes %s\n", commandNumber, param1, param2, param3);
            play(param1, param2, param3, userList);
            break;
        case 'S':
            printf("%s S:", commandNumber);
            stats(userList);
            break;
        case 'R':
            printf("%s R: maxtime %s\n", commandNumber, param1);
            removeU(param1, userList);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];
    tListU userList;
    createEmptyListU(&userList);

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, &userList);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}
