
OCSP_SINGLERESP *
OCSP_basic_add1_status
          (OCSP_BASICRESP *rsp,OCSP_CERTID *cid,int status,int reason,ASN1_TIME *revtime,
          ASN1_TIME *thisupd,ASN1_TIME *nextupd)

{
  OCSP_SINGLERESP *a;
  ASN1_GENERALIZEDTIME *pAVar1;
  OCSP_CERTID *pOVar2;
  ASN1_NULL *pAVar3;
  int iVar4;
  OCSP_REVOKEDINFO *out;
  ASN1_ENUMERATED *a_00;
  _STACK *p_Var5;
  OCSP_RESPDATA *pOVar6;
  OCSP_CERTSTATUS *pOVar7;
  
  pOVar6 = rsp->tbsResponseData;
  if (pOVar6->responses == (stack_st_OCSP_SINGLERESP *)0x0) {
    p_Var5 = sk_new_null();
    pOVar6->responses = (stack_st_OCSP_SINGLERESP *)p_Var5;
    if (p_Var5 != (_STACK *)0x0) goto LAB_000e07ec;
  }
  else {
LAB_000e07ec:
    a = OCSP_SINGLERESP_new();
    if (a != (OCSP_SINGLERESP *)0x0) {
      pAVar1 = ASN1_TIME_to_generalizedtime(thisupd,&a->thisUpdate);
      if ((pAVar1 != (ASN1_GENERALIZEDTIME *)0x0) &&
         ((nextupd == (ASN1_TIME *)0x0 ||
          (pAVar1 = ASN1_TIME_to_generalizedtime(nextupd,&a->nextUpdate),
          pAVar1 != (ASN1_GENERALIZEDTIME *)0x0)))) {
        OCSP_CERTID_free(a->certId);
        pOVar2 = OCSP_CERTID_dup(cid);
        a->certId = pOVar2;
        if (pOVar2 != (OCSP_CERTID *)0x0) {
          pOVar7 = a->certStatus;
          pOVar7->type = status;
          if (status == 1) {
            if (revtime == (ASN1_TIME *)0x0) {
              ERR_put_error(0x27,0x67,0x6d,"ocsp_srv.c",0xaa);
              goto LAB_000e082e;
            }
            out = OCSP_REVOKEDINFO_new();
            (pOVar7->value).revoked = out;
            if ((out == (OCSP_REVOKEDINFO *)0x0) ||
               (pAVar1 = ASN1_TIME_to_generalizedtime(revtime,&out->revocationTime),
               pAVar1 == (ASN1_GENERALIZEDTIME *)0x0)) goto LAB_000e082e;
            if (reason != -1) {
              a_00 = ASN1_ENUMERATED_new();
              out->revocationReason = a_00;
              if ((a_00 == (ASN1_ENUMERATED *)0x0) ||
                 (iVar4 = ASN1_ENUMERATED_set(a_00,reason), iVar4 == 0)) goto LAB_000e082e;
            }
          }
          else {
            if ((status != 2) && (status != 0)) goto LAB_000e082e;
            pAVar3 = ASN1_NULL_new();
            (pOVar7->value).good = pAVar3;
          }
          iVar4 = sk_push((_STACK *)rsp->tbsResponseData->responses,a);
          if (iVar4 != 0) {
            return a;
          }
        }
      }
      goto LAB_000e082e;
    }
  }
  a = (OCSP_SINGLERESP *)0x0;
LAB_000e082e:
  OCSP_SINGLERESP_free(a);
  return (OCSP_SINGLERESP *)0x0;
}

