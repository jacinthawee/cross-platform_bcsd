
int OCSP_single_get0_status
              (OCSP_SINGLERESP *single,int *reason,ASN1_GENERALIZEDTIME **revtime,
              ASN1_GENERALIZEDTIME **thisupd,ASN1_GENERALIZEDTIME **nextupd)

{
  OCSP_REVOKEDINFO *pOVar1;
  int iVar2;
  int iVar3;
  
  if (single == (OCSP_SINGLERESP *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = single->certStatus->type;
    if (iVar3 == 1) {
      pOVar1 = (single->certStatus->value).revoked;
      if (revtime != (ASN1_GENERALIZEDTIME **)0x0) {
        *revtime = pOVar1->revocationTime;
      }
      if (reason != (int *)0x0) {
        if (pOVar1->revocationReason == (ASN1_ENUMERATED *)0x0) {
          *reason = -1;
        }
        else {
          iVar2 = (*(code *)PTR_ASN1_ENUMERATED_get_006a8d2c)();
          *reason = iVar2;
        }
      }
    }
    if (thisupd != (ASN1_GENERALIZEDTIME **)0x0) {
      *thisupd = single->thisUpdate;
    }
    if (nextupd == (ASN1_GENERALIZEDTIME **)0x0) {
      return iVar3;
    }
    *nextupd = single->nextUpdate;
  }
  return iVar3;
}

