
int get_cert_chain(X509 *param_1,X509_STORE *param_2,stack_st_X509 **param_3)

{
  int iVar1;
  stack_st_X509 *psVar2;
  int in_GS_OFFSET;
  X509_STORE_CTX local_a8;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  X509_STORE_CTX_init(&local_a8,param_2,param_1,(stack_st_X509 *)0x0);
  iVar1 = X509_verify_cert(&local_a8);
  if (iVar1 < 1) {
    psVar2 = (stack_st_X509 *)0x0;
    iVar1 = X509_STORE_CTX_get_error(&local_a8);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = 0;
    psVar2 = X509_STORE_CTX_get1_chain(&local_a8);
  }
  X509_STORE_CTX_cleanup(&local_a8);
  *param_3 = psVar2;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

