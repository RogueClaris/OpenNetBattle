#include "bnZapring.h"
#include "bnTile.h"
#include "bnField.h"
#include "bnExplosion.h"
#include "bnHitbox.h"
#include "bnTextureResourceManager.h"
#include "bnAudioResourceManager.h"

Zapring::Zapring(Team _team, int damage, double speed, Direction facing) : Spell(_team) {
    // Zapring flies over tiles
    SetFloatShoe(true);
    SetLayer(0);

    setTexture(Textures().GetTexture(TextureType::SPELL_ZAPRING));
    setScale(2.f, 2.f);

    this->speed = speed;
    SetDirection(facing);
    hit = false;
    
    animation = CreateComponent<AnimationComponent>(this);
    animation->SetPath("resources/spells/spell_zapring.animation");
    animation->Load();
    animation->SetAnimation("DEFAULT", Animator::Mode::Loop);

    auto props = Hit::DefaultProperties;
    props.damage = damage;
    props.flags = Hit::flinch | Hit::impact | Hit::stun;
    SetHitboxProperties(props);
}

Zapring::~Zapring() {
}

void Zapring::OnDelete() {
}

void Zapring::OnSpawn(Battle::Tile& start) {
}

void Zapring::OnUpdate(double _elapsed) {
    if (hit) {
        Remove();
    }
    if (tile->IsEdgeTile()) {
        Remove();
    }

    if (!IsSliding()) {
        Slide(GetTile() + GetDirection(), frames(7), frames(0));
    }
    if (!hit) {
        tile->AffectEntities(this);
    }
}

void Zapring::OnCollision(const Character*) {
    Delete();
}

bool Zapring::CanMoveTo(Battle::Tile* tile) {
    return true;
}

void Zapring::Attack(Character* _entity) {
    if (_entity->Hit(GetHitboxProperties())) {
        Audio().Play(AudioType::HURT, AudioPriority::highest);
        this->hit = true;
    }
}
