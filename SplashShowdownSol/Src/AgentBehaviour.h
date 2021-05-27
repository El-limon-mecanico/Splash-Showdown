#include "Component.h"

class QuackEntity;
class Agent;

class AgentBehaviour : public Component
{
private:
	float weight = 1.0f;
	int priority = 1;

	QuackEntity* target;
	Agent* agent;

public:
	AgentBehaviour();
	virtual ~AgentBehaviour();

	virtual void onEnable() override;
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	virtual void update() override;
	virtual Steering getSteering() = 0;

	void setTarget(QuackEntity* newtarget);
};