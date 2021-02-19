#ifndef COAGULATIONMODEL_NONE_H
#define COAGULATIONMODEL_NONE_H

#include "sootlib/state/gas/GasState.h"
#include "sootlib/state/soot/MomentSootState.h"
#include "sootlib/coagulation_model/CoagulationModel.h"

namespace soot
{
class CoagulationModel_NONE : public CoagulationModel
{
public:
	[[nodiscard]] double getCoagulationRate(const GasState& gasState, const MomentSootState& sootState, double m1, double m2) const override
	{
		return 0.0;
	}

	~CoagulationModel_NONE() override = default;
};
}

#endif //COAGULATIONMODEL_NONE_H
