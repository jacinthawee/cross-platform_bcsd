
void * DSA_get_ex_data(DSA *d,int idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005155ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_CRYPTO_get_ex_data_006a9484)(&d->ex_data);
  return pvVar1;
}

