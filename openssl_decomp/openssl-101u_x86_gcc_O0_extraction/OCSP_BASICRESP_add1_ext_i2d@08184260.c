
int OCSP_BASICRESP_add1_ext_i2d(OCSP_BASICRESP *x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  
  iVar1 = X509V3_add1_i2d(&x->tbsResponseData->responseExtensions,nid,value,crit,flags);
  return iVar1;
}

