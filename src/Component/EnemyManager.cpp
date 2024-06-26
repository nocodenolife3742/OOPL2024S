//
// Created by User on 2024/5/31.
//

#include "Component/EnemyManager.hpp"

EnemyManager::EnemyManager(){}

void EnemyManager::Update(glm::vec2 CameraPos, glm::vec2 RockmanPos, int SceneStage) {
    int N = m_Enemies.size();
    for(int i=0;i<N;i++){
        auto Stages = m_EnemyStage[m_Enemies[i]->GetEnemyId()];
        for(int j=0;j<Stages.size();j++){
            if(SceneStage == Stages[j]){
                if(m_Enemies[i]->GetLifeState() == Enemy::LifeState::LIFE){
                    m_Enemies[i]->DoBehavior(CameraPos,RockmanPos,SceneStage);
                }
                else{
                    if(m_Enemies[i]->GetEnemyId() != "KillerBomb") {
                        m_Enemies[i]->SetPosition(glm::vec2{-20000, -20000});
                    }
                    else{
                        m_Enemies[i]->DoBehavior(CameraPos,RockmanPos,SceneStage);;
                    }
                }
            }
        }
    }
}
void EnemyManager::Reset(){
    int N = m_Enemies.size();
    for(int i=0;i<N;i++){
        m_Enemies[i]->Reset();
    }
}
void EnemyManager::SetEnemies(std::vector<std::shared_ptr<Enemy>> enemy){
    this->m_Enemies = enemy;
}
std::vector<std::shared_ptr<Enemy>> EnemyManager::GetEnemies(){
    return m_Enemies;
}
void EnemyManager::SetEnemyStage(std::unordered_map<std::string,std::vector<int> > enemystage){
    m_EnemyStage = enemystage;
}