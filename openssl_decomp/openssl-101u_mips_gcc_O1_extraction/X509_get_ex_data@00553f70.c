
void * X509_get_ex_data(X509 *r,int idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00553f7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_CRYPTO_get_ex_data_006a8364)(&r->ex_data);
  return pvVar1;
}

