
void * ENGINE_get_ex_data(ENGINE *e,int idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0051a400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_CRYPTO_get_ex_data_006a9484)(e + 0x60);
  return pvVar1;
}

