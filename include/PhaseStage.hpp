#ifndef PHASE_STAGE_HPP
#define PHASE_STAGE_HPP

#include "Component/Blaster.hpp"
#include "Component/Bomb.hpp"
#include "Component/Bombombomb.hpp"
#include "Component/Backgroundmap.hpp"
#include "Component/CollideEventManager.hpp"
#include "Component/HealthBar.hpp"
#include "Component/OctopusBattery.hpp"
#include "Component/Phase.hpp"
#include "Component/SceneManager.hpp"
#include "Component/ScrewDriver.hpp"
#include "Component/TileMap.hpp"
#include "Component/PersonLife.hpp"
#include "Component/OctopusBattery.hpp"
#include "Component/KillerBomb.hpp"
#include "Component/Mambu.hpp"
#include "Component/Gabyoll.hpp"
#include "Component/SniperJoe.hpp"
#include "Component/Kamadoma.hpp"
#include "Component/EnemyManager.hpp"
#include "IncludeComponent.hpp"

class PhaseStage final : public Phase {
public:
    void Init(App *app) override;

    void Update(App *app) override;

    void Leave(App *app) override;

    explicit PhaseStage(App::State lastState)
        : Phase(lastState){};

private:
    std::shared_ptr<Backgroundmap> m_BackgroundObjects;
    std::shared_ptr<Backgroundmap> m_ForegroundObjects;
    std::shared_ptr<Rockman> m_Rockman;
    std::shared_ptr<KillerBomb> m_KillerBomb;
    std::shared_ptr<TestBox> m_Testbox;
    std::shared_ptr<Mambu> m_Mambu;
    std::shared_ptr<SniperJoe> m_SniperJoe;
    std::shared_ptr<Scorebar> m_Scorebar;
    std::shared_ptr<HealthBar> m_RockmanHealthBar;
    std::shared_ptr<std::queue<std::shared_ptr<Ammo>>> m_Magazine; // Store Rockman's Ammo.

    std::vector<std::shared_ptr<Blaster>> m_Blaster;
    std::vector<std::shared_ptr<Kamadoma>> m_Kamadoma;
    std::vector<std::shared_ptr<Gabyoll>> m_Gabyoll;
    std::vector<std::shared_ptr<Screwdriver>> m_Screwdriver;
    std::vector<std::shared_ptr<OctopusBattery>> m_OctopusBattery;
    std::vector<std::shared_ptr<Bombombomb>> m_Bombombomb;
    std::shared_ptr<std::queue<std::shared_ptr<Item>>> m_Items;
    SceneManager m_SceneManager;
    EnemyManager m_EnemyManager;
    CollideEventManager m_CollideEventManager;
    std::shared_ptr<std::vector<std::shared_ptr<TileBox>>> m_ForeObjectTileBox;
    std::shared_ptr<std::queue<std::shared_ptr<Bomb>>> m_Bombs;
    std::shared_ptr<PersonLife> m_PersonLife;


    std::vector<std::shared_ptr<Enemy>> m_Enemies;
    void ReloadMagazine(App *app); // Update Every Ammo In The Stage.
    void UpdateItems(App *app);
    void UpdateBombs(App *app);
    bool CheckIfRockmanInMap(glm::vec2 cameraposition,glm::vec2 position,glm::vec2 offset);
};

#endif // PHASE_STAGE_HPP
