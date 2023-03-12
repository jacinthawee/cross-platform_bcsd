
int SSL_check_private_key(SSL *ctx)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (ctx == (SSL *)0x0) {
    uVar4 = 0x43;
    uVar3 = 0x396;
  }
  else if ((int **)ctx->cert == (int **)0x0) {
    uVar4 = 0xb1;
    uVar3 = 0x39a;
  }
  else {
    piVar1 = *(int **)ctx->cert;
    if (*piVar1 == 0) {
      uVar4 = 0xb1;
      uVar3 = 0x39e;
    }
    else {
      if (piVar1[1] != 0) {
                    /* WARNING: Could not recover jumptable at 0x004a7cec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*(code *)PTR_X509_check_private_key_006a707c)();
        return iVar2;
      }
      uVar4 = 0xbe;
      uVar3 = 0x3a2;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa3,uVar4,"ssl_lib.c",uVar3);
  return 0;
}
