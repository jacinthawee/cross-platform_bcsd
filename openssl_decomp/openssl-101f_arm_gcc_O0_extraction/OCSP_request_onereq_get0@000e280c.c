
OCSP_ONEREQ * OCSP_request_onereq_get0(OCSP_REQUEST *req,int i)

{
  OCSP_ONEREQ *pOVar1;
  
  pOVar1 = (OCSP_ONEREQ *)sk_value((_STACK *)req->tbsRequest->requestList,i);
  return pOVar1;
}

