
void * OCSP_REQUEST_get1_ext_d2i(OCSP_REQUEST *x,int nid,int *crit,int *idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae2a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_X509V3_get_d2i_006aa078)(x->tbsRequest->requestExtensions);
  return pvVar1;
}

