#ifndef MOVE_H
#define MOVE_H

#include "Box.h"

class Move
{
public:
    int x;
    int y;
    int z;
    int direction;
    Box* box[27];

    float angle[3];

    Move(int x, int y, int z, Box* box[], int direction = 1);
    void SetDirection(int x, int y, int z, int direction);
    void TurnX(float angle, float deltaTime);
    void TurnY(float angle, float deltaTime);
    void TurnZ(float angle, float deltaTime);

    bool Animate(int axis);
    void ResetAngle(int axis);
};

#endif
