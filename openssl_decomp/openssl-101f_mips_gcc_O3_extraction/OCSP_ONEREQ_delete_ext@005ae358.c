
X509_EXTENSION * OCSP_ONEREQ_delete_ext(OCSP_ONEREQ *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae364. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_EXTENSION *)(*(code *)PTR_X509v3_delete_ext_006aa074)(x->singleRequestExtensions);
  return pXVar1;
}
