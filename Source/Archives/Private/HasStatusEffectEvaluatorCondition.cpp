#include "HasStatusEffectEvaluatorCondition.h"

UHasStatusEffectEvaluatorCondition::UHasStatusEffectEvaluatorCondition()
{
	this->_statusEffectList = TArray<TSubclassOf<UStatusEffect>>();
}
