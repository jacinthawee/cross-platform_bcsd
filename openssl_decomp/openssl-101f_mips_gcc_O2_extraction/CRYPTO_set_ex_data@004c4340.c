
int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad,int idx,void *val)

{
  int iVar1;
  int iVar2;
  stack_st_void *psVar3;
  
  psVar3 = ad->sk;
  if (psVar3 == (stack_st_void *)0x0) {
    psVar3 = (stack_st_void *)(*(code *)PTR_sk_new_null_006a80a4)();
    ad->sk = psVar3;
    if (psVar3 == (stack_st_void *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xf,0x66,0x41,"ex_data.c",0x25d);
      return 0;
    }
  }
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)(psVar3);
  do {
    if (idx < iVar1) {
      (*(code *)PTR_sk_set_006a9478)(ad->sk,idx,val);
      return 1;
    }
    iVar1 = iVar1 + 1;
    iVar2 = (*(code *)PTR_sk_push_006a80a8)(ad->sk,0);
  } while (iVar2 != 0);
  (*(code *)PTR_ERR_put_error_006a9030)(0xf,0x66,0x41,"ex_data.c",0x267);
  return 0;
}

