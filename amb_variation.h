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

#ifndef _AMB_VARIATION_H_
#define _AMB_VARIATION_H_

#include <basicfb.h>
#include <forte_real.h>

class FORTE_amb_variation: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_amb_variation)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &t() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &Out_sinewave() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  static const TEventID scm_nEventInitID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventInitoID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_REAL &freq() {
    return *static_cast<CIEC_REAL*>(getVarInternal(0));
  };

  CIEC_REAL &stime() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  CIEC_REAL &phase() {
    return *static_cast<CIEC_REAL*>(getVarInternal(2));
  };

  CIEC_REAL &f_st() {
    return *static_cast<CIEC_REAL*>(getVarInternal(3));
  };

  CIEC_REAL &x() {
    return *static_cast<CIEC_REAL*>(getVarInternal(4));
  };

  CIEC_REAL &y() {
    return *static_cast<CIEC_REAL*>(getVarInternal(5));
  };

  CIEC_REAL &z() {
    return *static_cast<CIEC_REAL*>(getVarInternal(6));
  };

  CIEC_REAL &m() {
    return *static_cast<CIEC_REAL*>(getVarInternal(7));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 1, 1, 8, 0);
  void alg_Initial(void);
  void alg_Calculate(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInitialization = 1;
  static const TForteInt16 scm_nStateCalculation = 2;

  void enterStateSTART(void);
  void enterStateInitialization(void);
  void enterStateCalculation(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_amb_variation(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_amb_variation(){};

};

#endif //close the ifdef sequence from the beginning of the file

