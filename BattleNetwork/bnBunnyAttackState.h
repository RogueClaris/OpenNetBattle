#pragma once
#include "bnAIState.h"
#include "bnBunny.h"

/**
 * @class CanodumbAttackState
 * @author mav
 * @date 05/05/19
 * @brief Spawns a cannon and smoke effect
 */
class BunnyAttackState final : public AIState<Bunny>
{
public:
	BunnyAttackState();
	~BunnyAttackState();

	void OnEnter(Bunny& can) override;
	void OnUpdate(double _elapsed, Bunny& can) override;
	void OnLeave(Bunny& can) override;
};

