#include <math.h>
#include <string.h>
#include "struct.h"

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
//XP CALCULATOR
int balance=0;
int calcXP(int xp,int lvlgain){
    if(xp>=100){
        balance=xp-100;
        lvlgain++;

        if(balance>=100){
            calcXP(balance,lvlgain);
        }
    }
    return lvlgain;
}
int lvlCALC(int dur)
{
    int xpgain;
    xpgain = dur*10;
    return calcXP(xpgain,0);
}