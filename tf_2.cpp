/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: tf_2
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2021-03-12/Lenovo - null - 
 *************************************************************************/

#include "tf_2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "tf_2_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_tf_2, g_nStringIdtf_2)

const CStringDictionary::TStringId FORTE_tf_2::scm_anDataInputNames[] = {g_nStringIdtin};

const CStringDictionary::TStringId FORTE_tf_2::scm_anDataInputTypeIds[] = {g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_tf_2::scm_anDataOutputNames[] = {g_nStringIdyout};

const CStringDictionary::TStringId FORTE_tf_2::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_tf_2::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_tf_2::scm_anEIWith[] = {0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_tf_2::scm_anEventInputNames[] = {g_nStringIdInit, g_nStringIdREQ};

const TDataIOID FORTE_tf_2::scm_anEOWith[] = {0, 255, 0, 255};
const TForteInt16 FORTE_tf_2::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_tf_2::scm_anEventOutputNames[] = {g_nStringIdInito, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_tf_2::scm_anInternalsNames[] = {g_nStringIdx, g_nStringIdn};

const CStringDictionary::TStringId FORTE_tf_2::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_tf_2::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_tf_2::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_tf_2::alg_Initial(void){

}

void FORTE_tf_2::alg_Calculate(void){
x() = -tin()/10;
n() = EXP((x()));
yout() = ((0.1))*n();
}


void FORTE_tf_2::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_tf_2::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initial();
  sendOutputEvent( scm_nEventInitoID);
}

void FORTE_tf_2::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_tf_2::executeEvent(int pa_nEIID){
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


