#ifndef NUCLEATIONMODEL_PAH_H
#define NUCLEATIONMODEL_PAH_H

#include <memory>

#include "sootlib/state/gas/State.h"
#include "sootlib/state/soot/MomentSootState.h"
#include "sootlib/nucleation_model/NucleationModel.h"
#include "sootlib/coagulation_model/CoagulationModel_FRENK.h"

namespace soot
{
class NucleationModel_PAH : public NucleationModel
{
public:
	// TODO implement
	[[nodiscard]] double getNucleationRate(const State& gasState, const MomentSootState& sootState, const std::vector<double>& particleSizes, const std::vector<double>& particleWeights) const override;

	~NucleationModel_PAH() override = default;
};
}

#endif //NUCLEATIONMODEL_PAH_H
