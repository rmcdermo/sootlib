////////////////////////////////////////////////////////////////////////////////
/*! Nucleation by Lindstedt (2005)
 *
 *      Rate from Lindstedt (2005), Proc. Comb. Inst. 30:775
 *      Returns chemical nucleation rate in #/m3*s.
 *
 */

#include "NucleationModel_LIN.h"

using namespace std;
using namespace soot;

double NucleationModel_LIN::getNucleationRate(State& state,
                                              const vector<double>& particleSizes,
                                              const vector<double>& particleWeights,
                                              MassRateRatios& ratio) const {
    ratio.nucCond().gasSpeciesRatio(GasSpecies::C2H2) = -MW_C2H2 / (2 * MW_C);
    ratio.nucCond().gasSpeciesRatio(GasSpecies::H2) = MW_H2 / (2 * MW_C);

    const double Rnuc = 0.63E4 * exp(-21100 / state.getT()) * state.getGasSpeciesC(GasSpecies::C2H2);
    return Rnuc * 2 * Na / state.getCMin();
}
