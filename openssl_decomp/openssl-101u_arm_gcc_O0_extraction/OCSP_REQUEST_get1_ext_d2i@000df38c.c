
void * OCSP_REQUEST_get1_ext_d2i(OCSP_REQUEST *x,int nid,int *crit,int *idx)

{
  void *pvVar1;
  
  pvVar1 = X509V3_get_d2i(x->tbsRequest->requestExtensions,nid,crit,idx);
  return pvVar1;
}

