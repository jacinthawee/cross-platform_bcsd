
int OCSP_REQUEST_get_ext_count(OCSP_REQUEST *x)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_count(x->tbsRequest->requestExtensions);
  return iVar1;
}

