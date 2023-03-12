
void * OCSP_BASICRESP_get1_ext_d2i(OCSP_BASICRESP *x,int nid,int *crit,int *idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab984. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_X509V3_get_d2i_006a8f5c)(x->tbsResponseData->responseExtensions);
  return pvVar1;
}

