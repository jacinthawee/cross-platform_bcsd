
void * CRYPTO_get_ex_data(CRYPTO_EX_DATA *ad,int idx)

{
  int iVar1;
  void *pvVar2;
  
  if (ad->sk == (stack_st_void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(ad->sk);
  if (idx < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x004c12d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pvVar2 = (void *)(*(code *)PTR_sk_value_006a6e24)(ad->sk,idx);
    return pvVar2;
  }
  return (void *)0x0;
}

