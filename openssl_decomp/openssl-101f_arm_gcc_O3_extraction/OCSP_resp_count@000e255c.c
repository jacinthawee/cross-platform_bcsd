
int OCSP_resp_count(OCSP_BASICRESP *bs)

{
  int iVar1;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
    iVar1 = sk_num((_STACK *)bs->tbsResponseData->responses);
    return iVar1;
  }
  return -1;
}

