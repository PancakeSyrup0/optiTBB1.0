#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include "struct.h"
#include "tools.h"
#include "tbb.h"

void room1();

ENTITY player;
ENTITY mob[10];
//---------MAIN GAME------------
void initPlayerClass()
{
    int c;
    scanf("%d",&c);
    switch(c){
        case 1: {
            strcpy(player.race,"Human");
            break;
        }
        default:{
            printf("invalid choice\n");
            initPlayerClass();
        }
    }

}
void initPlayerInfo()
{
    int choice;
    printf("Enter your name.\n");
    scanf("%[^\n]%*c", player.name);
    printf("What race are you?\n");
    printf("(1)Human\n");
    initPlayerClass();
    player.lvl=5;
    player.hp=player.lvl*10;

    if((strcmp(player.race,"Human")==0)){
        player.MOVELIST[0]=0;player.MOVELIST[1]=1;player.MOVELIST[2]=0;player.MOVELIST[3]=0;
    }


    printf("%s is your name and you are a %s\n Accept?\n(1)Yes (2)No",player.name,player.race);
    scanf("%d",&choice);
    if(choice==1){
        //hi
    }else if(choice==2){
        initPlayerInfo();
    }
}
void initMobInfo()
{
    //Slime
    strcpy(mob[0].name, "Slime");
    mob[0].lvl=1;
    mob[0].hp=10;
    mob[0].MOVELIST[0]=0;mob[0].MOVELIST[1]=0;mob[0].MOVELIST[2]=0;mob[0].MOVELIST[3]=0;
}



extern B_DATA Battle(ENTITY p, ENTITY e);
int main()
{
    printf("You find yourself lost in a dark cave with no sense of your surroundings\n");
    initPlayerInfo();
    initMobInfo();
    room1();
    return 0;
}
void room1(){

    B_DATA b_data;
    printf("you encounter a slime\n");
    printf("Starting battle with slime!\n\n");
    b_data=Battle(player,mob[0]);
    if(b_data.battle_result==1){
        player.lvl+=lvlCALC(b_data.battle_duration);
        printf("%s leveled up to LVL%d",player.name,player.lvl);
    }else if(b_data.battle_result==0){
        printf("You died!\n");
        Sleep(5);
        exit(1);
    }
    
}

