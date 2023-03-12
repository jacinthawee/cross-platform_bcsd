
int OCSP_ONEREQ_get_ext_by_critical(OCSP_ONEREQ *x,int crit,int lastpos)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae33c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509v3_get_ext_by_critical_006aa06c)(x->singleRequestExtensions);
  return iVar1;
}

