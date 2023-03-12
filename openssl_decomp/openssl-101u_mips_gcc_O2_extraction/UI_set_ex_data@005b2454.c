
int UI_set_ex_data(UI *r,int idx,void *arg)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b2460. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_CRYPTO_set_ex_data_006a8360)(r + 0xc);
  return iVar1;
}

