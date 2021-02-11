#ifndef STATIC_H
#define STATIC_H

#include <vector>
#include <cmath>

namespace soot
{
static constexpr double Na    = 6.02214086E26;  ///< Avogadro's constant: #/kmol
static constexpr double kb    = 1.38064852E-23; ///< Boltzmann constant = Rg/Na: J/#*K
static constexpr double Rg    = 8314.46;        ///< Universal gas constant
static constexpr double eps_c = 2.2;            ///< coagulation constant
static constexpr double Df    = 1.8;            ///< soot fractal dimension
static constexpr double MW_c  = 12.011;         ///< mw of carbon
static constexpr double MW_h  = 1.00794;        ///< mw of hydrogen

enum class MomentModel {MONO, LOGN, MOMIC, QMOM};
enum class BinModel {SECT};
enum class NucleationMechanism {NONE, LL, LIN, PAH};
enum class GrowthMechanism {NONE, LL, LIN, HACA};
enum class OxidationMechanism {NONE, LL, LEE_NEOH, NSC_NEOH, HACA};
enum class CoagulationMechanism {NONE, LL, FUCHS, FRENK};

static constexpr double MW_C2H2 = 26.038;
static constexpr double MW_O2 = 31.998;
static constexpr double MW_H = 1.008;
static constexpr double MW_H2 = 2.016;
static constexpr double MW_OH = 17.007;
static constexpr double MW_H2O = 18.015;
static constexpr double MW_CO = 28.010;
static constexpr double MW_C = 12.011;
}

#endif //STATIC_H
