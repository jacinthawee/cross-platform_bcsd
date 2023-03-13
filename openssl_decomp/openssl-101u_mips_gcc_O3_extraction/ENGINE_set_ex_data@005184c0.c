
int ENGINE_set_ex_data(ENGINE *e,int idx,void *arg)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005184cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_CRYPTO_set_ex_data_006a8360)(e + 0x60);
  return iVar1;
}

