
int OCSP_resp_find_status
              (OCSP_BASICRESP *bs,OCSP_CERTID *id,int *status,int *reason,
              ASN1_GENERALIZEDTIME **revtime,ASN1_GENERALIZEDTIME **thisupd,
              ASN1_GENERALIZEDTIME **nextupd)

{
  OCSP_CERTID **ppOVar1;
  int iVar2;
  ASN1_GENERALIZEDTIME **ppAVar3;
  int iVar4;
  int iVar5;
  stack_st_OCSP_SINGLERESP *psVar6;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    psVar6 = bs->tbsResponseData->responses;
    for (iVar5 = 0; iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar6), iVar5 < iVar2; iVar5 = iVar5 + 1
        ) {
      ppOVar1 = (OCSP_CERTID **)(*(code *)PTR_sk_value_006a6e24)(psVar6,iVar5);
      iVar2 = OCSP_id_cmp(id,*ppOVar1);
      if (iVar2 == 0) {
        if (iVar5 < 0) {
          return 0;
        }
        iVar5 = (*(code *)PTR_sk_value_006a6e24)(bs->tbsResponseData->responses,iVar5);
        if (iVar5 == 0) {
          iVar2 = -1;
        }
        else {
          iVar2 = **(int **)(iVar5 + 4);
          if (iVar2 == 1) {
            ppAVar3 = (ASN1_GENERALIZEDTIME **)(*(int **)(iVar5 + 4))[1];
            if (revtime != (ASN1_GENERALIZEDTIME **)0x0) {
              *revtime = *ppAVar3;
            }
            if (reason != (int *)0x0) {
              if (ppAVar3[1] == (ASN1_GENERALIZEDTIME *)0x0) {
                *reason = -1;
              }
              else {
                iVar4 = (*(code *)PTR_ASN1_ENUMERATED_get_006a8d2c)();
                *reason = iVar4;
              }
            }
          }
          if (thisupd != (ASN1_GENERALIZEDTIME **)0x0) {
            *thisupd = *(ASN1_GENERALIZEDTIME **)(iVar5 + 8);
          }
          if (nextupd != (ASN1_GENERALIZEDTIME **)0x0) {
            *nextupd = *(ASN1_GENERALIZEDTIME **)(iVar5 + 0xc);
          }
        }
        if (status == (int *)0x0) {
          return 1;
        }
        *status = iVar2;
        return 1;
      }
    }
  }
  return 0;
}

