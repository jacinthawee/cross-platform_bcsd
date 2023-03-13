
void * BIO_get_ex_data(BIO *bio,int idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00520134. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_CRYPTO_get_ex_data_006a8364)(&bio->ex_data);
  return pvVar1;
}

