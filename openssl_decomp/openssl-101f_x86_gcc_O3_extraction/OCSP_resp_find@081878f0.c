
int OCSP_resp_find(OCSP_BASICRESP *bs,OCSP_CERTID *id,int last)

{
  _STACK *p_Var1;
  OCSP_CERTID **ppOVar2;
  int iVar3;
  int iVar4;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    iVar4 = last + 1;
    if (last < 0) {
      iVar4 = 0;
    }
    p_Var1 = (_STACK *)bs->tbsResponseData->responses;
    while( true ) {
      iVar3 = sk_num(p_Var1);
      if (iVar3 <= iVar4) break;
      ppOVar2 = (OCSP_CERTID **)sk_value(p_Var1,iVar4);
      iVar3 = OCSP_id_cmp(id,*ppOVar2);
      if (iVar3 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    }
  }
  return -1;
}

