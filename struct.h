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
    char race[20];
}ENTITY;
 

typedef struct BATTLE_DATA{
    int battle_duration;
    int battle_result;
}B_DATA;
