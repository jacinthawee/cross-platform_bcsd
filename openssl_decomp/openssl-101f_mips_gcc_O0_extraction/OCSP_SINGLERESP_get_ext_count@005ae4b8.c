
int OCSP_SINGLERESP_get_ext_count(OCSP_SINGLERESP *x)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae4c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509v3_get_ext_count_006aa060)(x->singleExtensions);
  return iVar1;
}

