
int OCSP_BASICRESP_get_ext_by_OBJ(OCSP_BASICRESP *x,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_OBJ(x->tbsResponseData->responseExtensions,obj,lastpos);
  return iVar1;
}

