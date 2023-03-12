
void * OCSP_REQUEST_get1_ext_d2i(OCSP_REQUEST *x,int nid,int *crit,int *idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_X509V3_get_d2i_006a8f5c)(x->tbsRequest->requestExtensions);
  return pvVar1;
}

