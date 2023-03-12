
int OCSP_SINGLERESP_add1_ext_i2d(OCSP_SINGLERESP *x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509V3_add1_i2d_006aa07c)(&x->singleExtensions);
  return iVar1;
}

