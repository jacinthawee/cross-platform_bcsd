
OCSP_SINGLERESP *
OCSP_basic_add1_status
          (OCSP_BASICRESP *rsp,OCSP_CERTID *cid,int status,int reason,ASN1_TIME *revtime,
          ASN1_TIME *thisupd,ASN1_TIME *nextupd)

{
  OCSP_RESPDATA *pOVar1;
  OCSP_CERTSTATUS *pOVar2;
  OCSP_SINGLERESP *a;
  ASN1_GENERALIZEDTIME *pAVar3;
  OCSP_CERTID *pOVar4;
  ASN1_NULL *pAVar5;
  int iVar6;
  OCSP_REVOKEDINFO *out;
  ASN1_ENUMERATED *a_00;
  _STACK *p_Var7;
  
  pOVar1 = rsp->tbsResponseData;
  if (pOVar1->responses == (stack_st_OCSP_SINGLERESP *)0x0) {
    p_Var7 = sk_new_null();
    pOVar1->responses = (stack_st_OCSP_SINGLERESP *)p_Var7;
    if (p_Var7 != (_STACK *)0x0) goto LAB_08187e80;
  }
  else {
LAB_08187e80:
    a = OCSP_SINGLERESP_new();
    if (a != (OCSP_SINGLERESP *)0x0) {
      pAVar3 = ASN1_TIME_to_generalizedtime(thisupd,&a->thisUpdate);
      if ((pAVar3 != (ASN1_GENERALIZEDTIME *)0x0) &&
         ((nextupd == (ASN1_TIME *)0x0 ||
          (pAVar3 = ASN1_TIME_to_generalizedtime(nextupd,&a->nextUpdate),
          pAVar3 != (ASN1_GENERALIZEDTIME *)0x0)))) {
        OCSP_CERTID_free(a->certId);
        pOVar4 = OCSP_CERTID_dup(cid);
        a->certId = pOVar4;
        if (pOVar4 != (OCSP_CERTID *)0x0) {
          pOVar2 = a->certStatus;
          pOVar2->type = status;
          if (status == 1) {
            if (revtime == (ASN1_TIME *)0x0) {
              ERR_put_error(0x27,0x67,0x6d,"ocsp_srv.c",0xa0);
              goto LAB_08187eef;
            }
            out = OCSP_REVOKEDINFO_new();
            (pOVar2->value).revoked = out;
            if ((out == (OCSP_REVOKEDINFO *)0x0) ||
               (pAVar3 = ASN1_TIME_to_generalizedtime(revtime,&out->revocationTime),
               pAVar3 == (ASN1_GENERALIZEDTIME *)0x0)) goto LAB_08187eef;
            if (reason != -1) {
              a_00 = ASN1_ENUMERATED_new();
              out->revocationReason = a_00;
              if ((a_00 == (ASN1_ENUMERATED *)0x0) ||
                 (iVar6 = ASN1_ENUMERATED_set(a_00,reason), iVar6 == 0)) goto LAB_08187eef;
            }
          }
          else {
            if ((status != 2) && (status != 0)) goto LAB_08187eef;
            pAVar5 = ASN1_NULL_new();
            (pOVar2->value).good = pAVar5;
          }
          iVar6 = sk_push((_STACK *)rsp->tbsResponseData->responses,a);
          if (iVar6 != 0) {
            return a;
          }
        }
      }
      goto LAB_08187eef;
    }
  }
  a = (OCSP_SINGLERESP *)0x0;
LAB_08187eef:
  OCSP_SINGLERESP_free(a);
  return (OCSP_SINGLERESP *)0x0;
}
