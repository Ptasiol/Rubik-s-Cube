#include "Move.h"

Move::Move(int x, int y, int z, Box* box[], int direction)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->direction = direction;
    for(int i = 0; i < 27; i++)
    {
        this->box[i] = box[i];
    }

    angle[0] = 90.f;
    angle[1] = 90.f;
    angle[2] = 90.f;

}

void Move::SetDirection(int x, int y, int z, int direction)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->direction = direction;
}

void Move::TurnX(float angle, float deltaTime)
{
    if(Move::Animate(0) == true )
    {
        angle += 10.f * deltaTime;
        this->angle[0] += angle;
        for(int i = 0; i < 27; i++)
        {
            if(round(box[i]->position.x) == direction)
            {
                glm::mat4 model = glm::mat4(1.f);
                model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.f, 0.f));
                model = glm::translate(model, box[i]->position);
                box[i]->SetLocalTransform(model);

                glm::mat4 rotations;
                for(int j = 0; j < 6; j++)
                {
                    rotations = glm::mat4(1.f);
                    rotations = glm::rotate(rotations, glm::radians(angle), glm::vec3(1.f, 0.f, 0.f));
                    rotations = rotations * box[i]->meshes[j]->GetLocalTransform();
                    box[i]->meshes[j]->SetLocalTransform(rotations);
                }

                box[i]->position = glm::vec3(model[3].x, model[3].y, model[3].z);
            }
        }
    }
}

void Move::TurnY(float angle, float deltaTime)
{
    if(Move::Animate(1) == true )
    {
        angle += 10.f * deltaTime;
        this->angle[1] += angle;
        for(int i = 0; i < 27; i++)
        {
            if(round(box[i]->position.y) == direction)
            {
                glm::mat4 model = glm::mat4(1.f);
                model = glm::rotate(model, glm::radians(angle), glm::vec3(0.f, 1.f, 0.f));
                model = glm::translate(model, box[i]->position);
                box[i]->SetLocalTransform(model);

                glm::mat4 rotations;
                for(int j = 0; j < 6; j++)
                {
                    rotations = glm::mat4(1.f);
                    rotations = glm::rotate(rotations, glm::radians(angle), glm::vec3(0.f, 1.f, 0.f));
                    rotations = rotations * box[i]->meshes[j]->GetLocalTransform();
                    box[i]->meshes[j]->SetLocalTransform(rotations);
                }

                box[i]->position = glm::vec3(model[3].x, model[3].y, model[3].z);
            }
        }
    }
}

void Move::TurnZ(float angle, float deltaTime)
{
    if(Move::Animate(2) == true )
    {
        angle += 10.f * deltaTime;
        this->angle[2] += angle;
        for(int i = 0; i < 27; i++)
        {
            if(round(box[i]->position.z) == direction)
            {
                glm::mat4 model = glm::mat4(1.f);
                model = glm::rotate(model, glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));
                model = glm::translate(model, box[i]->position);
                box[i]->SetLocalTransform(model);

                glm::mat4 rotations;
                for(int j = 0; j < 6; j++)
                {
                    rotations = glm::mat4(1.f);
                    rotations = glm::rotate(rotations, glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));
                    rotations = rotations * box[i]->meshes[j]->GetLocalTransform();
                    box[i]->meshes[j]->SetLocalTransform(rotations);
                }

                box[i]->position = glm::vec3(model[3].x, model[3].y, model[3].z);
            }
        }
    }
}

bool Move::Animate(int axis)
{
    if(abs(this->angle[axis]) >= 90.f) return false;
    else return true;
}

void Move::ResetAngle(int axis)
{
    this->angle[axis] = 0.f;
}
