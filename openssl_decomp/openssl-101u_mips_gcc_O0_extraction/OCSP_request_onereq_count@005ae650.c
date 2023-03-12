
int OCSP_request_onereq_count(OCSP_REQUEST *req)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(req->tbsRequest->requestList);
  return iVar1;
}

