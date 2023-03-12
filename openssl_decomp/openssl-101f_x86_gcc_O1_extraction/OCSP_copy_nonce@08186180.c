
int OCSP_copy_nonce(OCSP_BASICRESP *resp,OCSP_REQUEST *req)

{
  int loc;
  X509_EXTENSION *ex;
  stack_st_X509_EXTENSION *psVar1;
  uint uVar2;
  
  loc = X509v3_get_ext_by_NID(req->tbsRequest->requestExtensions,0x16e,-1);
  uVar2 = 2;
  if (-1 < loc) {
    ex = X509v3_get_ext(req->tbsRequest->requestExtensions,loc);
    psVar1 = X509v3_add_ext(&resp->tbsResponseData->responseExtensions,ex,-1);
    uVar2 = (uint)(psVar1 != (stack_st_X509_EXTENSION *)0x0);
  }
  return uVar2;
}

