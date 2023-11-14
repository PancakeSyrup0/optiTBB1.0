#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//-----------structs--------------
//testing commits
//testing second commit
typedef struct MOVE_DATA{
    int dmg;
    int status;
    char name[20];
}M_DATA;


typedef struct ENTITY_INFO{
    char name[20];
    int lvl,hp;
    int MOVELIST[4];
}ENTITY;
 

typedef struct BATTLE_DATA{
    int battle_duration;
    int battle_result;
}B_DATA;
 

ENTITY player;
ENTITY mob[10];
//--------tools needed for the game----------


/*
MOVE LIST
---------------
Do Nothing-00
Punch-01
Kick-02
Dodge-03
Counter-04
Poison Breath-05
*/

// random number generator
int random_number()
{
    int num;
    num = rand() % 100 + 1;
    return num;
}

// MOVE LIST REFERENCE
M_DATA REF_MOVELIST(int MOVE_ID)
{
    M_DATA m;
    switch (MOVE_ID)
    {
        case 0:{
            //do nothing
            m.dmg=0;
            m.status=0;
            strcpy(m.name,"Do nothing");
            return m;
        }
        case 1:{
            //punch
            m.dmg=5;
            m.status=0;
            strcpy(m.name,"Punch");
            return m;
        }
        case 2:{
            //kick
            m.dmg=8;
            m.status=0;
            strcpy(m.name,"Kick");
            return m;
        }
        case 3:{
            //dodge
            m.dmg=0;
            m.status=-1;
            strcpy(m.name,"Dodge");
            return m;
        }
        case 4:{
            //counter
            m.dmg=0;
            m.status=-2;
            strcpy(m.name,"Counter");
            return m;
        }
        case 5:{
            //poison breath
            m.dmg=10;
            if(random_number()<=25){m.status=1;}
            else{m.status=0;}
            strcpy(m.name,"Poison Breath");
            return m;
        }
        case 6:{
            //water blade
            m.dmg=5;
            m.status=0;
            strcpy(m.name,"Water Blade");
            return m;
        }
    }
    return m;

}





//---------MAIN GAME------------

void initPlayerInfo()
{
    printf("Enter your name\n");
    scanf("%[^\n]%*c", player.name);
    player.MOVELIST[0]=0;player.MOVELIST[1]=1;player.MOVELIST[2]=2;player.MOVELIST[3]=3;
    player.hp=100;
}
void initMobInfo()
{
    //Slime
    strcpy(mob[0].name, "Slime");
    mob[0].lvl=1;
    mob[0].hp=10;
    mob[0].MOVELIST[0]=0;mob[0].MOVELIST[1]=0;mob[0].MOVELIST[2]=0;mob[0].MOVELIST[3]=0;
}
M_DATA EnemyTurn(ENTITY e)
{
    M_DATA m;
    m=REF_MOVELIST(e.MOVELIST[1]);
    return m;

}
M_DATA PlayerTurn()
{
    M_DATA m;
    int i,choice;
    printf("Your moves are:\n");
    for(i=0;i<4;i++){
        m=REF_MOVELIST(player.MOVELIST[i]);
        printf("(%d)%s\n",i,m.name);// goes through every move in the players movelist
    }
    printf("Choose your move:\n");
    scanf("%d",&choice);
    m=REF_MOVELIST(player.MOVELIST[choice]);//player chooses move and returns data of that move

    return m;
}
B_DATA Battle(ENTITY p, ENTITY e)
{
    B_DATA b_data;
    M_DATA p_turn,e_turn;
    b_data.battle_duration=0;
    int battle_loop=1;
    while(battle_loop!=0){

        

        p_turn=PlayerTurn();
        e_turn=EnemyTurn(e);

        
        //battle loop
        if(p_turn.status>=0)
        {
            printf("%s used %s, dealing %d damage!\n",p.name,p_turn.name,p_turn.dmg);
            e.hp-=p_turn.dmg;
            printf("%s used %s, dealing %d damage!\n",e.name,e_turn.name,e_turn.dmg);
            p.hp-=e_turn.dmg;
        }
        printf("Player hp: %d\n",p.hp);
        printf("Enemy hp: %d\n",e.hp);

        b_data.battle_duration++;






        //battle end cases
        if(p.hp<=0){
            b_data.battle_result=0;
            battle_loop=0;
        }else if(e.hp<=0){
            b_data.battle_result=1;
            battle_loop=0;
        }
    }
    return b_data;

}
int main()
{
    initPlayerInfo();
    initMobInfo();
    B_DATA bdat;
    bdat = Battle(player,mob[0]);
    if(bdat.battle_result==1){
        printf("\nPlayer wins!\n");
    }else if(bdat.battle_result==0){
        printf("\nPlayer lost!\n");
    }
    return 0;
}

