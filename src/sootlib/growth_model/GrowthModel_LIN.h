#ifndef GROWTHMODEL_LIN_H
#define GROWTHMODEL_LIN_H

#include <cmath>

#include <sootlib/static.h>
#include <sootlib/growth_model/GrowthModel.h>
#include <sootlib/state/gas/State.h>
#include <sootlib/state/soot/MomentSootState.h>

namespace soot
{
class GrowthModel_LIN : public GrowthModel
{
public:
	[[nodiscard]] double getGrowthRate(const State& gasState, const MomentSootState& sootState) const override;

	~GrowthModel_LIN() override = default;
};
}

#endif //GROWTHMODEL_LIN_H
