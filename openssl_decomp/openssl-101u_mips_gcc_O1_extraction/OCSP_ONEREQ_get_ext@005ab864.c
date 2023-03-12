
X509_EXTENSION * OCSP_ONEREQ_get_ext(OCSP_ONEREQ *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_EXTENSION *)(*(code *)PTR_X509v3_get_ext_006a8f54)(x->singleRequestExtensions);
  return pXVar1;
}

