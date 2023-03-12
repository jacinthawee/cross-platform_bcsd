
int OCSP_REQUEST_get_ext_by_NID(OCSP_REQUEST *x,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_NID(x->tbsRequest->requestExtensions,nid,lastpos);
  return iVar1;
}

