
void * RSA_get_ex_data(RSA *r,int idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0050e318. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_CRYPTO_get_ex_data_006a8364)(&r->ex_data);
  return pvVar1;
}

