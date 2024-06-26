#ifndef OCTOPUS_BATTERY_HPP
#define OCTOPUS_BATTERY_HPP

#include "Component/Collider.hpp"
#include "Component/EnemyAttribute.hpp"
#include "Component/ImageObject.hpp"
#include "pch.hpp"

class OctopusBattery : public Enemy, Physic {
public:
    enum class OctopusState {
        SLEEP,
        BLEAZY,
        AWAKE,
    };
    OctopusBattery(glm::vec2 inipos, glm::vec2 finpos, glm::vec2 collidersize,
                   glm::vec2 speed, glm::vec2 scale,
                   std::vector<std::string> path, int health, bool visable,
                   OctopusState state, Enemy::HurtState hurtstate);
    void DoBehavior(glm::vec2 CameraPos,glm::vec2 RockmanPos,int SceneStage) override;
    void Reset() override;
    void PhysicEngine() override;

private:
    std::vector<std::string> Path;
    glm::vec2 InitialPosition, FinalPosition;
    glm::vec2 Speed;
    OctopusBattery::OctopusState State;
    float SleepCounter, BleazyCounter;

    //When Reset, Use This.
    glm::vec2 InitialInitialPos,InitialFinalPos;
    OctopusBattery::OctopusState InitialState;
};
#endif
