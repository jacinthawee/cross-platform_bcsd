
stack_st_X509 * X509_STORE_CTX_get1_chain(X509_STORE_CTX *ctx)

{
  stack_st_X509 *psVar1;
  int iVar2;
  int iVar3;
  
  if (ctx->chain == (stack_st_X509 *)0x0) {
    return (stack_st_X509 *)0x0;
  }
  psVar1 = (stack_st_X509 *)(*(code *)PTR_sk_dup_006a9074)();
  if (psVar1 == (stack_st_X509 *)0x0) {
    psVar1 = (stack_st_X509 *)0x0;
  }
  else {
    iVar3 = 0;
    while( true ) {
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar1);
      if (iVar2 <= iVar3) break;
      iVar2 = (*(code *)PTR_sk_value_006a7f24)(psVar1,iVar3);
      (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar2 + 0x10,1,3,"x509_vfy.c",0x75d);
      iVar3 = iVar3 + 1;
    }
  }
  return psVar1;
}

