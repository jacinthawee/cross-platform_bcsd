
int OCSP_BASICRESP_add1_ext_i2d(OCSP_BASICRESP *x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab99c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509V3_add1_i2d_006a8f60)(&x->tbsResponseData->responseExtensions);
  return iVar1;
}

