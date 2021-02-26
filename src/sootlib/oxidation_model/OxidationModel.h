#ifndef OXIDATIONMODEL_H
#define OXIDATIONMODEL_H

#include "sootlib/state/gas/State.h"
#include "sootlib/state/soot/MomentSootState.h"

namespace soot
{
class OxidationModel
{
public:
	[[nodiscard]] virtual double getOxidationRate(const State& gasState, const MomentSootState& sootState) const = 0;

	virtual ~OxidationModel() = default;
};
}

#endif //OXIDATIONMODEL_H
