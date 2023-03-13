
int OCSP_REQUEST_get_ext_by_critical(OCSP_REQUEST *x,int crit,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_critical(x->tbsRequest->requestExtensions,crit,lastpos);
  return iVar1;
}

