
int OCSP_SINGLERESP_get_ext_by_OBJ(OCSP_SINGLERESP *x,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005aba0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509v3_get_ext_by_OBJ_006a8f4c)(x->singleExtensions);
  return iVar1;
}

