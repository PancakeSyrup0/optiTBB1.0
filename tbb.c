#include <stdio.h>
#include <string.h>
#include <math.h>
#include "struct.h"
#include "tools.h"






extern M_DATA REF_MOVELIST(int MOVE_ID);
M_DATA EnemyTurn(ENTITY e)
{
    M_DATA m;
    m=REF_MOVELIST(e.MOVELIST[1]);
    return m;

}
M_DATA PlayerTurn(ENTITY p)
{
    M_DATA m;
    int i,choice;
    printf("Your moves are:\n");
    for(i=0;i<4;i++){
        m=REF_MOVELIST(p.MOVELIST[i]);
        printf("(%d)%s\n",i,m.name);// goes through every move in the players movelist
    }
    printf("Choose your move:\n");
    scanf("%d",&choice);
    m=REF_MOVELIST(p.MOVELIST[choice]);//player chooses move and returns data of that move

    return m;
}
B_DATA Battle(ENTITY p, ENTITY e)
{
    B_DATA b_data;
    M_DATA p_turn,e_turn;
    b_data.battle_duration=0;
    int battle_loop=1;
    while(battle_loop!=0){

        

        p_turn=PlayerTurn(p);
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