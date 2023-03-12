
int OCSP_resp_find(OCSP_BASICRESP *bs,OCSP_CERTID *id,int last)

{
  OCSP_CERTID **ppOVar1;
  int iVar2;
  int iVar3;
  stack_st_OCSP_SINGLERESP *psVar4;
  
  if (bs == (OCSP_BASICRESP *)0x0) {
    return -1;
  }
  if (last < 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = last + 1;
  }
  psVar4 = bs->tbsResponseData->responses;
  while( true ) {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar4);
    if (iVar2 <= iVar3) {
      return -1;
    }
    ppOVar1 = (OCSP_CERTID **)(*(code *)PTR_sk_value_006a6e24)(psVar4,iVar3);
    iVar2 = OCSP_id_cmp(id,*ppOVar1);
    if (iVar2 == 0) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

