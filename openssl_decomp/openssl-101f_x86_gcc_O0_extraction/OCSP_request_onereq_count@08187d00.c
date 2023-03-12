
int OCSP_request_onereq_count(OCSP_REQUEST *req)

{
  int iVar1;
  
  iVar1 = sk_num((_STACK *)req->tbsRequest->requestList);
  return iVar1;
}

