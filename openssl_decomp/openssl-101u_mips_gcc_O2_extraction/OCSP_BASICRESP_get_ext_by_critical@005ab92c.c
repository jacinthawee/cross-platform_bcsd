
int OCSP_BASICRESP_get_ext_by_critical(OCSP_BASICRESP *x,int crit,int lastpos)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab93c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509v3_get_ext_by_critical_006a8f50)(x->tbsResponseData->responseExtensions)
  ;
  return iVar1;
}
