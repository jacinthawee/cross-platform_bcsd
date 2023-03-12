
void * UI_get_ex_data(UI *r,int idx)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b4dc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_CRYPTO_get_ex_data_006a9484)(r + 0xc);
  return pvVar1;
}

