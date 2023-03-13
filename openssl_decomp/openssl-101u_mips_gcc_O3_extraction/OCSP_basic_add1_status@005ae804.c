
OCSP_SINGLERESP *
OCSP_basic_add1_status
          (OCSP_BASICRESP *rsp,OCSP_CERTID *cid,int status,int reason,ASN1_TIME *revtime,
          ASN1_TIME *thisupd,ASN1_TIME *nextupd)

{
  OCSP_SINGLERESP *a;
  int iVar1;
  OCSP_CERTID *pOVar2;
  ASN1_NULL *pAVar3;
  OCSP_REVOKEDINFO *pOVar4;
  ASN1_ENUMERATED *pAVar5;
  stack_st_OCSP_SINGLERESP *psVar6;
  OCSP_RESPDATA *pOVar7;
  OCSP_CERTSTATUS *pOVar8;
  
  pOVar7 = rsp->tbsResponseData;
  if (pOVar7->responses == (stack_st_OCSP_SINGLERESP *)0x0) {
    psVar6 = (stack_st_OCSP_SINGLERESP *)(*(code *)PTR_sk_new_null_006a6fa4)();
    pOVar7->responses = psVar6;
    if (psVar6 != (stack_st_OCSP_SINGLERESP *)0x0) goto LAB_005ae850;
  }
  else {
LAB_005ae850:
    a = OCSP_SINGLERESP_new();
    if (a != (OCSP_SINGLERESP *)0x0) {
      iVar1 = (*(code *)PTR_ASN1_TIME_to_generalizedtime_006a929c)(thisupd,&a->thisUpdate);
      if ((iVar1 != 0) &&
         ((nextupd == (ASN1_TIME *)0x0 ||
          (iVar1 = (*(code *)PTR_ASN1_TIME_to_generalizedtime_006a929c)(nextupd,&a->nextUpdate),
          iVar1 != 0)))) {
        OCSP_CERTID_free(a->certId);
        pOVar2 = OCSP_CERTID_dup(cid);
        a->certId = pOVar2;
        if (pOVar2 != (OCSP_CERTID *)0x0) {
          pOVar8 = a->certStatus;
          pOVar8->type = status;
          if (status == 1) {
            if (revtime == (ASN1_TIME *)0x0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x67,0x6d,"ocsp_srv.c",0xaa);
              goto LAB_005ae8ec;
            }
            pOVar4 = OCSP_REVOKEDINFO_new();
            (pOVar8->value).revoked = pOVar4;
            if ((pOVar4 == (OCSP_REVOKEDINFO *)0x0) ||
               (iVar1 = (*(code *)PTR_ASN1_TIME_to_generalizedtime_006a929c)(revtime,pOVar4),
               iVar1 == 0)) goto LAB_005ae8ec;
            if (reason != -1) {
              pAVar5 = (ASN1_ENUMERATED *)(*(code *)PTR_ASN1_ENUMERATED_new_006a7044)();
              pOVar4->revocationReason = pAVar5;
              if ((pAVar5 == (ASN1_ENUMERATED *)0x0) ||
                 (iVar1 = (*(code *)PTR_ASN1_ENUMERATED_set_006a7048)(pAVar5,reason), iVar1 == 0))
              goto LAB_005ae8ec;
            }
          }
          else {
            if ((status != 2) && (status != 0)) goto LAB_005ae8ec;
            pAVar3 = (ASN1_NULL *)(*(code *)PTR_ASN1_NULL_new_006a9084)();
            (pOVar8->value).good = pAVar3;
          }
          iVar1 = (*(code *)PTR_sk_push_006a6fa8)(rsp->tbsResponseData->responses,a);
          if (iVar1 != 0) {
            return a;
          }
        }
      }
      goto LAB_005ae8ec;
    }
  }
  a = (OCSP_SINGLERESP *)0x0;
LAB_005ae8ec:
  OCSP_SINGLERESP_free(a);
  return (OCSP_SINGLERESP *)0x0;
}

