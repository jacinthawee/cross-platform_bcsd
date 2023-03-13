
int OCSP_check_nonce(OCSP_REQUEST *req,OCSP_BASICRESP *bs)

{
  int iVar1;
  int loc;
  uint uVar2;
  X509_EXTENSION *pXVar3;
  X509_EXTENSION *pXVar4;
  
  iVar1 = X509v3_get_ext_by_NID(req->tbsRequest->requestExtensions,0x16e,-1);
  loc = X509v3_get_ext_by_NID(bs->tbsResponseData->responseExtensions,0x16e,-1);
  if ((-1 < iVar1) || (uVar2 = 2, -1 < loc)) {
    if ((iVar1 < 0) || (-1 < loc)) {
      if ((loc < 0) || (uVar2 = 3, -1 < iVar1)) {
        pXVar3 = X509v3_get_ext(req->tbsRequest->requestExtensions,iVar1);
        pXVar4 = X509v3_get_ext(bs->tbsResponseData->responseExtensions,loc);
        iVar1 = ASN1_OCTET_STRING_cmp(pXVar3->value,pXVar4->value);
        uVar2 = (uint)(iVar1 == 0);
      }
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

