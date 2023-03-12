
int OCSP_REQUEST_get_ext_count(OCSP_REQUEST *x)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509v3_get_ext_count_006a8f44)(x->tbsRequest->requestExtensions);
  return iVar1;
}

