
int OCSP_REQUEST_add1_ext_i2d(OCSP_REQUEST *x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae2b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509V3_add1_i2d_006aa07c)(&x->tbsRequest->requestExtensions);
  return iVar1;
}

