
int OCSP_BASICRESP_get_ext_by_critical(OCSP_BASICRESP *x,int crit,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_critical(x->tbsResponseData->responseExtensions,crit,lastpos);
  return iVar1;
}

