
OCSP_ONEREQ * OCSP_request_onereq_get0(OCSP_REQUEST *req,int i)

{
  OCSP_ONEREQ *pOVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b10b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pOVar1 = (OCSP_ONEREQ *)(*(code *)PTR_sk_value_006a7f24)(req->tbsRequest->requestList);
  return pOVar1;
}

