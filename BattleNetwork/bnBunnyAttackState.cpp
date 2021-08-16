#include "bnBunnyIdleState.h"
#include "bnBunnyAttackState.h"
#include "bnBunny.h"
#include "bnAudioResourceManager.h"
#include "bnTile.h"
#include "bnField.h"
#include "bnZapring.h"
#include <iostream>

BunnyAttackState::BunnyAttackState() : AIState<Bunny>() { ; }
BunnyAttackState::~BunnyAttackState() { ; }

void BunnyAttackState::OnEnter(Bunny& can) {
    auto onFinish = [&can]() {
        can.ChangeState<BunnyIdleState>();
    };

    auto onAttack = [&can]() {
        if (can.GetField()->GetAt(can.tile->GetX() - 1, can.tile->GetY())) {
            Spell* spell;
            switch (can.GetRank())
            {
            case(Bunny::Rank::_2):
                spell = new Zapring(can.team, 50);
                break;
            case(Bunny::Rank::_3):
                spell = new Zapring(can.team, 80);
                break;
            default:
                spell = new Zapring(can.team, 20);
                break;
            }
            spell->SetDirection(Direction::left);
            auto props = spell->GetHitboxProperties();
            props.aggressor = can.GetID();
            spell->SetHitboxProperties(props);

            can.field->AddEntity(*spell, can.tile->GetX() - 1, can.tile->GetY());

            can.Audio().Play(AudioType::TOSS_ITEM_LITE);
        }
    };

    auto animation = can.GetFirstComponent<AnimationComponent>();

    switch (can.GetRank()) {
    case Bunny::Rank::_1:
        animation->SetAnimation("ATTACK_1", onFinish);
        break;
    case Bunny::Rank::_2:
        animation->SetAnimation("ATTACK_2", onFinish);
        break;
    case Bunny::Rank::_3:
        animation->SetAnimation("ATTACK_3", onFinish);
        break;
    }

    animation->SetCounterFrameRange(1, 4);
    animation->AddCallback(3, onAttack, true);
}

void BunnyAttackState::OnUpdate(double _elapsed, Bunny& can) {
}

void BunnyAttackState::OnLeave(Bunny& can) {
}

