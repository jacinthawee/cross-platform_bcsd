
stack_st_X509 * get_cert_chain(X509 *param_1,X509_STORE *param_2,stack_st_X509 **param_3)

{
  int iVar1;
  stack_st_X509 *psVar2;
  stack_st_X509 *psVar3;
  X509_STORE_CTX XStack_98;
  
  X509_STORE_CTX_init(&XStack_98,param_2,param_1,(stack_st_X509 *)0x0);
  iVar1 = X509_verify_cert(&XStack_98);
  if (iVar1 < 1) {
    psVar2 = (stack_st_X509 *)X509_STORE_CTX_get_error(&XStack_98);
    if (psVar2 == (stack_st_X509 *)0x0) {
      psVar3 = (stack_st_X509 *)0xffffffff;
    }
    else {
      psVar3 = psVar2;
      psVar2 = (stack_st_X509 *)0x0;
    }
  }
  else {
    psVar2 = X509_STORE_CTX_get1_chain(&XStack_98);
    psVar3 = (stack_st_X509 *)0x0;
  }
  X509_STORE_CTX_cleanup(&XStack_98);
  *param_3 = psVar2;
  return psVar3;
}

