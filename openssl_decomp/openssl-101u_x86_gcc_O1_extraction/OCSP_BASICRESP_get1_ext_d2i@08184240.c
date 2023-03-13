
void * OCSP_BASICRESP_get1_ext_d2i(OCSP_BASICRESP *x,int nid,int *crit,int *idx)

{
  void *pvVar1;
  
  pvVar1 = X509V3_get_d2i(x->tbsResponseData->responseExtensions,nid,crit,idx);
  return pvVar1;
}

