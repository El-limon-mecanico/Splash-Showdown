#include "AgentBehaviour.h"
#include "QuackEntity.h"
#include "Agent.h"

AgentBehaviour::AgentBehaviour()
{
}

AgentBehaviour::~AgentBehaviour()
{
}

void AgentBehaviour::onEnable()
{
	agent = entity_->getComponent<Agent>();
}

bool AgentBehaviour::init(luabridge::LuaRef parameterTable)
{
	return true;
}

void AgentBehaviour::update()
{
    if (agent->combineByWeight)
        agent->setSteering(getSteering(), weight);
    else if (agent->combineByPrio)
        agent->setSteering(getSteering(), priority);
    else
        agent->setSteering(getSteering());
}

void AgentBehaviour::setTarget(QuackEntity* newtarget) {
    target = newtarget;
}
