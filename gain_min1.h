/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: gain_min1
 *** Description: Basic FB with empty ECC
 *** Version:
***     1.0: 2021-03-30/Lenovo -  - 
 *************************************************************************/

#ifndef _GAIN_MIN1_H_
#define _GAIN_MIN1_H_

#include "basicfb.h"
#include "forte_real.h"


#include "forte_array_at.h"

class FORTE_gain_min1: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_gain_min1)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventInitID = 0;
  static const TEventID scm_nEventREQID = 1;
  
  static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventInitoID = 0;
  static const TEventID scm_nEventCNFID = 1;
  
  static const TDataIOID scm_anEOWith[];
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  CIEC_REAL &in_min1() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  }
  
  CIEC_REAL &out_min1() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  }
  

  void alg_Initial(void);
  void alg_Calculate(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInitialization = 1;
  static const TForteInt16 scm_nStateCalculation = 2;
  
  void enterStateSTART(void);
  void enterStateInitialization(void);
  void enterStateCalculation(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(2, 1, 1, 0, 0);

public:
  FORTE_gain_min1(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_gain_min1() = default;
};

#endif // _GAIN_MIN1_H_


