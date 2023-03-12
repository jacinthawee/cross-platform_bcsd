
int SSL_CTX_check_private_key(SSL_CTX *ctx)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (((ctx == (SSL_CTX *)0x0) || ((int **)ctx->cert == (int **)0x0)) ||
     (piVar1 = *(int **)ctx->cert, *piVar1 == 0)) {
    uVar4 = 0xb1;
    uVar3 = 0x380;
  }
  else {
    if (piVar1[1] != 0) {
                    /* WARNING: Could not recover jumptable at 0x004aadfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*(code *)PTR_X509_check_private_key_006a817c)();
      return iVar2;
    }
    uVar4 = 0xbe;
    uVar3 = 0x385;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xa8,uVar4,"ssl_lib.c",uVar3);
  return 0;
}

