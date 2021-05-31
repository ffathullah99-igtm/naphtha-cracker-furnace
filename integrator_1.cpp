/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: integrator_1
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2021-05-19/Lenovo -  - 
 *************************************************************************/

#include "integrator_1.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "integrator_1_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_integrator_1, g_nStringIdintegrator_1)

const CStringDictionary::TStringId FORTE_integrator_1::scm_anDataInputNames[] = {g_nStringIdinputx, g_nStringIdinteg};

const CStringDictionary::TStringId FORTE_integrator_1::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_integrator_1::scm_anDataOutputNames[] = {g_nStringIdoutputx};

const CStringDictionary::TStringId FORTE_integrator_1::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TDataIOID FORTE_integrator_1::scm_anEIWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_integrator_1::scm_anEIWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_integrator_1::scm_anEventInputNames[] = {g_nStringIdInit, g_nStringIdREQ};

const TDataIOID FORTE_integrator_1::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_integrator_1::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_integrator_1::scm_anEventOutputNames[] = {g_nStringIdInito, g_nStringIdCNF};


const SFBInterfaceSpec FORTE_integrator_1::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  2, scm_anDataInputNames, scm_anDataInputTypeIds,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_integrator_1::alg_Initial(void) {
}

void FORTE_integrator_1::alg_Calculate(void) {
  outputx() = ((inputx() * 5) + integ());
}


void FORTE_integrator_1::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_integrator_1::enterStateInitialization(void) {
  m_nECCState = scm_nStateInitialization;
  alg_Initial();
  sendOutputEvent(scm_nEventInitoID);
}

void FORTE_integrator_1::enterStateCalculation(void) {
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent(scm_nEventCNFID);
}


void FORTE_integrator_1::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do {
    bTransitionCleared = true;
    switch(m_nECCState) {
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
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCalculation:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; // 0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(bTransitionCleared);
}


