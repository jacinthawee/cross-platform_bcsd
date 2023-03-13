
int OCSP_resp_find_status
              (OCSP_BASICRESP *bs,OCSP_CERTID *id,int *status,int *reason,
              ASN1_GENERALIZEDTIME **revtime,ASN1_GENERALIZEDTIME **thisupd,
              ASN1_GENERALIZEDTIME **nextupd)

{
  _STACK *p_Var1;
  ASN1_GENERALIZEDTIME **ppAVar2;
  ASN1_ENUMERATED *a;
  OCSP_CERTID **ppOVar3;
  int iVar4;
  void *pvVar5;
  long lVar6;
  int iVar7;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    p_Var1 = (_STACK *)bs->tbsResponseData->responses;
    for (iVar7 = 0; iVar4 = sk_num(p_Var1), iVar7 < iVar4; iVar7 = iVar7 + 1) {
      ppOVar3 = (OCSP_CERTID **)sk_value(p_Var1,iVar7);
      iVar4 = OCSP_id_cmp(id,*ppOVar3);
      if (iVar4 == 0) {
        if (iVar7 < 0) {
          return 0;
        }
        pvVar5 = sk_value((_STACK *)bs->tbsResponseData->responses,iVar7);
        if (pvVar5 == (void *)0x0) {
          iVar7 = -1;
        }
        else {
          iVar7 = **(int **)((int)pvVar5 + 4);
          if (iVar7 == 1) {
            ppAVar2 = (ASN1_GENERALIZEDTIME **)(*(int **)((int)pvVar5 + 4))[1];
            if (revtime != (ASN1_GENERALIZEDTIME **)0x0) {
              *revtime = *ppAVar2;
            }
            if (reason != (int *)0x0) {
              a = ppAVar2[1];
              if (a == (ASN1_ENUMERATED *)0x0) {
                *reason = -1;
              }
              else {
                lVar6 = ASN1_ENUMERATED_get(a);
                *reason = lVar6;
              }
            }
          }
          if (thisupd != (ASN1_GENERALIZEDTIME **)0x0) {
            *thisupd = *(ASN1_GENERALIZEDTIME **)((int)pvVar5 + 8);
          }
          if (nextupd != (ASN1_GENERALIZEDTIME **)0x0) {
            *nextupd = *(ASN1_GENERALIZEDTIME **)((int)pvVar5 + 0xc);
          }
        }
        if (status != (int *)0x0) {
          *status = iVar7;
          return 1;
        }
        return 1;
      }
    }
  }
  return 0;
}

