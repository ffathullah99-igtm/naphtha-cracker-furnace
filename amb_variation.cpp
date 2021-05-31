/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: amb_variation
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2021-03-22/Lenovo - null - 
 *************************************************************************/

#include "amb_variation.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "amb_variation_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_amb_variation, g_nStringIdamb_variation)

const CStringDictionary::TStringId FORTE_amb_variation::scm_anDataInputNames[] = {g_nStringIdt};

const CStringDictionary::TStringId FORTE_amb_variation::scm_anDataInputTypeIds[] = {g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_amb_variation::scm_anDataOutputNames[] = {g_nStringIdOut_sinewave};

const CStringDictionary::TStringId FORTE_amb_variation::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_amb_variation::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_amb_variation::scm_anEIWith[] = {0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_amb_variation::scm_anEventInputNames[] = {g_nStringIdInit, g_nStringIdREQ};

const TDataIOID FORTE_amb_variation::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_amb_variation::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_amb_variation::scm_anEventOutputNames[] = {g_nStringIdInito, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_amb_variation::scm_anInternalsNames[] = {g_nStringIdfreq, g_nStringIdstime, g_nStringIdphase, g_nStringIdf_st, g_nStringIdx, g_nStringIdy, g_nStringIdz, g_nStringIdm};

const CStringDictionary::TStringId FORTE_amb_variation::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_amb_variation::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_amb_variation::scm_stInternalVars = {8, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_amb_variation::alg_Initial(void){

}

void FORTE_amb_variation::alg_Calculate(void){
freq() = 0.0043633231299859;
phase() = 0;
f_st() = freq()*t();
x() = f_st()+phase();
y() = sin((x()));
z() = 10*y();;
Out_sinewave() = z();
}


void FORTE_amb_variation::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_amb_variation::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initial();
  sendOutputEvent( scm_nEventInitoID);
}

void FORTE_amb_variation::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_amb_variation::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventInitID == pa_nEIID)
          enterStateInitialization();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateCalculation();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialization:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCalculation:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


