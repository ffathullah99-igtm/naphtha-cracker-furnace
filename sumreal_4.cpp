/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: sumreal_4
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2021-03-15/Lenovo -  - 
 *************************************************************************/

#include "sumreal_4.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "sumreal_4_gen.cpp"
#endif


DEFINE_FIRMWARE_FB(FORTE_sumreal_4, g_nStringIdsumreal_4)

const CStringDictionary::TStringId FORTE_sumreal_4::scm_anDataInputNames[] = {g_nStringIdin1, g_nStringIdin2, g_nStringIdin3, g_nStringIdin4};

const CStringDictionary::TStringId FORTE_sumreal_4::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_sumreal_4::scm_anDataOutputNames[] = {g_nStringIdout4};

const CStringDictionary::TStringId FORTE_sumreal_4::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TDataIOID FORTE_sumreal_4::scm_anEIWith[] = {0, 1, 2, 3, 255, 0, 1, 2, 3, 255};
const TForteInt16 FORTE_sumreal_4::scm_anEIWithIndexes[] = {0, 5};
const CStringDictionary::TStringId FORTE_sumreal_4::scm_anEventInputNames[] = {g_nStringIdInit, g_nStringIdREQ};

const TDataIOID FORTE_sumreal_4::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_sumreal_4::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_sumreal_4::scm_anEventOutputNames[] = {g_nStringIdInito, g_nStringIdCNF};


const SFBInterfaceSpec FORTE_sumreal_4::scm_stFBInterfaceSpec = {
  2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes,
  2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  4, scm_anDataInputNames, scm_anDataInputTypeIds,
  1, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_sumreal_4::alg_Initial(void) {
}

void FORTE_sumreal_4::alg_Calculate(void) {
  out4() = (((in1() + in2()) + in3()) + (- in4()));
}


void FORTE_sumreal_4::enterStateSTART(void) {
  m_nECCState = scm_nStateSTART;
}

void FORTE_sumreal_4::enterStateInitialization(void) {
  m_nECCState = scm_nStateInitialization;
  alg_Initial();
  sendOutputEvent(scm_nEventInitoID);
}

void FORTE_sumreal_4::enterStateCalculation(void) {
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent(scm_nEventCNFID);
}


void FORTE_sumreal_4::executeEvent(int pa_nEIID){
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


