
int OCSP_REQUEST_get_ext_by_OBJ(OCSP_REQUEST *x,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509v3_get_ext_by_OBJ_006aa068)(x->tbsRequest->requestExtensions);
  return iVar1;
}

