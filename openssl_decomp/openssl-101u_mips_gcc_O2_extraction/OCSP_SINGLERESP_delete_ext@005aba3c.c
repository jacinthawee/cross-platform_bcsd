
X509_EXTENSION * OCSP_SINGLERESP_delete_ext(OCSP_SINGLERESP *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005aba48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_EXTENSION *)(*(code *)PTR_X509v3_delete_ext_006a8f58)(x->singleExtensions);
  return pXVar1;
}

