
int OCSP_check_nonce(OCSP_REQUEST *req,OCSP_BASICRESP *bs)

{
  uint loc;
  uint loc_00;
  X509_EXTENSION *pXVar1;
  X509_EXTENSION *pXVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  loc = X509v3_get_ext_by_NID(req->tbsRequest->requestExtensions,0x16e,-1);
  loc_00 = X509v3_get_ext_by_NID(bs->tbsResponseData->responseExtensions,0x16e,-1);
  uVar4 = loc >> 0x1f;
  uVar5 = loc_00 >> 0x1f;
  if ((int)(loc_00 & loc) < 0) {
    return 2;
  }
  if ((int)loc < 0) {
    uVar5 = 0;
  }
  if (uVar5 == 0) {
    if ((int)loc_00 < 0) {
      uVar4 = 0;
    }
    if (uVar4 != 0) {
      return 3;
    }
    pXVar1 = X509v3_get_ext(req->tbsRequest->requestExtensions,loc);
    pXVar2 = X509v3_get_ext(bs->tbsResponseData->responseExtensions,loc_00);
    iVar3 = ASN1_OCTET_STRING_cmp(pXVar1->value,pXVar2->value);
    uVar5 = count_leading_zeroes(iVar3);
    return uVar5 >> 5;
  }
  return -1;
}

