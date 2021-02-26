#include "GrowthModel_HACA.h"
double soot::GrowthModel_HACA::getGrowthRate(const soot::State& gasState, const soot::MomentSootState& sootState) const
{
	/**
	 * Growth by HACA
	 *
	 * See Appel, Bockhorn, & Frenklach (2000), Comb. & Flame 121:122-136.
	 * For details, see Franklach and Wang (1990), 23rd Symposium, pp. 1559-1566.
	 *
	 * Parameters for steric factor alpha updated to those given in Balthasar
	 * and Franklach (2005) Comb. & Flame 140:130-145.
	 *
	 * Returns the chemical soot growth rate in kg/m2*s.
	 *
	 * @param M0       /input  local soot number density (#/m3)
	 * @param M1       /input  local soot mass density (kg/m3)
	 */

	const double M0 = sootState.getMoment(0);
	const double M1 = sootState.getMoment(1);

	const double cC2H2 = gasState.getC_C2H2();      // kmol/m3
	const double cO2   = gasState.getC_O2();        // kmol/m3
	const double cH    = gasState.getC_H();         // kmol/m3
	const double cH2   = gasState.getC_H2();        // kmol/m3
	const double cOH   = gasState.getC_OH();        // kmol/m3
	const double cH2O  = gasState.getC_H2O();       // kmol/m3

	//---------- calculate alpha, other constants
	const double RT       = 1.9872036E-3 * gasState.getT();         // R (=) kcal/mol
	const double chi_soot = 2.3E15;                   // (=) sites/cm^2
	const double a_param  = 33.167 - 0.0154 * gasState.getT();      // a parameter for calculating alpha
	const double b_param  = -2.5786 + 0.00112 * gasState.getT();    // b parameter for calculating alpha

	//---------- calculate raw HACA reaction rates
	const double fR1 = 4.2E13 * exp(-13.0 / RT) * cH / 1000;
	const double rR1 = 3.9E12 * exp(-11.0 / RT) * cH2 / 1000;
	const double fR2 = 1.0E10 * pow(gasState.getT(), 0.734) * exp(-1.43 / RT) * cOH / 1000;
	const double rR2 = 3.68E8 * pow(gasState.getT(), 1.139) * exp(-17.1 / RT) * cH2O /1000;
	const double fR3 = 2.0E13 * cH / 1000;
	const double fR4 = 8.00E7 * pow(gasState.getT(), 1.56) * exp(-3.8 / RT) * cC2H2 / 1000;
	const double fR5 = 2.2E12 * exp(-7.5 / RT) * cO2 / 1000;
	const double fR6 = 1290.0 * 0.13 * gasState.getP() * (cOH / gasState.getGasRho() * MW_OH) / sqrt(gasState.getT());    // gamma = 0.13 from Neoh et al.

	//---------- Steady state calculation of chi for soot radical; see Frenklach 1990 pg. 1561
	const double denom = rR1 + rR2 + fR3 + fR4 + fR5;
	double chi_rad = 0.0;
	if (denom != 0.0)
		chi_rad = 2 * chi_soot * (fR1 + fR2 + fR6) / denom;        // sites/cm^2

	double alpha = 1.0;                                            // alpha = fraction of available surface sites
	if (M0 > 0.0)
		alpha = tanh(a_param / log10(M1 / M0) + b_param);
	if (alpha < 0.0)
		alpha = 1.0;

	const double c_soot_H   = alpha * chi_soot * 1E4;                    // sites/m2-mixture
	const double c_soot_rad = alpha * chi_rad  * 1E4;                    // sites/m2-mixture

	return (fR5 * c_soot_rad + fR6 * c_soot_H) / Na * 2 * MW_c;        // kg/m2*s
}
