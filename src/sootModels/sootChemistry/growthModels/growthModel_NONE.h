#pragma once

#include "growthModel.h"

namespace soot {

class growthModel_NONE : public growthModel {

//////////////// DATA MEMBERS /////////////////////

private:

//////////////// MEMBER FUNCTIONS /////////////////

public:

     double getGrowthSootRate(const state &state) const override { return 0; }

//////////////// CONSTRUCTOR FUNCTIONS ////////////

public:

     growthModel_NONE() : growthModel() {};
    ~growthModel_NONE() override = default;

};
} // namespace soot
