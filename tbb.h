#include <stdio.h>
#include <string.h>
#include <math.h>
#include "struct.h"
#include "tools.h"

extern M_DATA REF_MOVELIST(int MOVE_ID);
M_DATA EnemyTurn(ENTITY e);
M_DATA PlayerTurn(ENTITY p);
B_DATA Battle(ENTITY p, ENTITY e);