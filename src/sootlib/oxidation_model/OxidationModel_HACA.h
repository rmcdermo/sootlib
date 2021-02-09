#ifndef OXIDATIONMODEL_HACA_H
#define OXIDATIONMODEL_HACA_H

#include "sootlib/state/GasState.h"
#include "sootlib/state/SootState.h"
#include "sootlib/oxidation_model/OxidationModel.h"

namespace soot
{
class OxidationModel_HACA : public OxidationModel
{
public:
	// TODO implement
	[[nodiscard]] double getOxidationRate(const GasState& gasState, const SootState& sootState) const override;

	~OxidationModel_HACA() override = default;
};
}

#endif //OXIDATIONMODEL_HACA_H
