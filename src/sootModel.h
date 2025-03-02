#pragma once

#include "sootDefs.h"
#include "state.h"

#include "nucleationModels/nucleationModel.h"
#include "growthModels/growthModel.h"
#include "oxidationModels/oxidationModel.h"
#include "coagulationModels/coagulationModel.h"

#include <vector>

namespace soot {

///////////////////////////////////////////////////////////////////////////////
///
/// Abstract base class for soot models.
/// sootModel_MONO, etc. inherit from this.
///
///////////////////////////////////////////////////////////////////////////////

class sootModel {

    //////////////// DATA MEMBERS /////////////////////

public:

    size_t            nsoot;    ///< \# of soot variables: moments or sections

    nucleationModel  *nucl;     ///< pointer to nucleation mechanism
    growthModel      *grow;     ///< pointer to growth mechanism
    oxidationModel   *oxid;     ///< pointer to oxidation mechanism
    coagulationModel *coag;     ///< pointer to coagulation mechanism

    bool    mechsNewedHere;     ///< flag to delete "new" objects

    psdMech psdMechType;        ///< one of MONO, LOGN, QMOM, MOMIC, SECT, etc.

    //----------- for the SECT model interface

    std::vector<double> mBins;  ///< mass in sections for the sectional model
    sourceTerms sources;        ///< struct containing soot, gas, and pah source terms vectors

    //////////////// MEMBER FUNCTIONS /////////////////

    virtual void setSourceTerms(state &state) = 0;

    void checkSpec();

    //----------- for the LOGN model interface

    virtual double pahSootCollisionRatePerDimer(const double mDimer) const {return 0;}

    //----------- for the SECT model interface

    virtual double get_M0_sectional(const state &state) {
        throw std::runtime_error("ERROR: sootModel::get_M0_sectional should not be called, but child sootModel_SECT::get_M0_sectional is fine");
        return 0;
    }
    virtual double get_M1_sectional(const state &state) {
        throw std::runtime_error("ERROR: sootModel::get_M1_sectional should not be called, but child sootModel_SECT::get_M1_sectional is fine");
        return 0;
    }

    //////////////// CONSTRUCTOR //////////////////////

    sootModel(size_t            nsoot_,
              nucleationModel  *nucl_,
              growthModel      *grow_,
              oxidationModel   *oxid_,
              coagulationModel *coag_);

    sootModel(size_t          nsoot_,
              nucleationMech  Nmech,
              growthMech      Gmech,
              oxidationMech   Omech,
              coagulationMech Cmech);

    virtual ~sootModel() {
        if(mechsNewedHere){
            delete(nucl);
            delete(grow);
            delete(oxid);
            delete(coag);
        }
    }

};
} // namespace soot
