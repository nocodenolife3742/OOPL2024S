#ifndef BOMB_HPP
#define BOMB_HPP

#include "Component/Collider.hpp"
#include "Component/TileBox.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/SFX.hpp"
#include <string>

class Bomb : public Util::GameObject {
public:
    enum class State { FALLING, EXPLODING };

    Bomb(const std::string &imagePath, glm::vec2 startPosition,
         glm::vec2 expectedEndPosition, float expectedHeight,
         unsigned int collisionDamage, unsigned int explosionDamage);
    ~Bomb() override = default;

    void Update(std::shared_ptr<std::vector<std::shared_ptr<TileBox>>> tiles);

    [[nodiscard]] Collider GetCollider() const { return *m_Collider; }

    void MarkForRemoval() { m_MarkedForRemoval = true; }

    [[nodiscard]] bool IsAlive() const { return !m_MarkedForRemoval; }

    [[nodiscard]] glm::vec2 GetPosition() const { return *m_Position; }

    [[nodiscard]] State GetState() const { return m_State; }

    [[nodiscard]] int GetDamage() const {
        if (m_State == State::FALLING) {
            return m_CollisionDamage;
        }
        else {
            return m_ExplosionDamage;
        }
    }

    void SetToExplode();

private:
    const float GRAVITY = 200.0f;
    unsigned int m_CollisionDamage;
    unsigned int m_ExplosionDamage;
    float m_XVelocity;
    float m_YVelocity;
    std::shared_ptr<Collider> m_Collider;
    std::shared_ptr<glm::vec2> m_Position;
    bool m_MarkedForRemoval = false;
    State m_State = State::FALLING;

    std::shared_ptr<Util::SFX> m_BGM = std::make_shared<Util::SFX>(RESOURCE_DIR"/Sound/Explosion.mp3");
};

#endif // BOMB_HPP
