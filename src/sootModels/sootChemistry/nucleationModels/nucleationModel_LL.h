#pragma once

#include "nucleationModel.h"

namespace soot {

////////////////////////////////////////////////////////////////////////////////
/*! Nucleation by Leung_Lindstedt (1991)
 *
 *      Rate from Leung & Lindstedt (1991), Comb. & Flame 87:289-305.
 *      Returns chemical nucleation rate in #/m3*s.
 *
 *      C2H2 --> C(s) + H2
 */
class nucleationModel_LL : public nucleationModel {

//////////////// DATA MEMBERS /////////////////////

public:

//////////////// MEMBER FUNCTIONS /////////////////

public:

    double getNucleationSootRate(state &state) override;

//////////////// CONSTRUCTOR FUNCTIONS ////////////

public:

    nucleationModel_LL();
    ~nucleationModel_LL() override = default;

};
} // namespace soot
