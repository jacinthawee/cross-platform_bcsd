
int EVP_PKEY_verify_init(EVP_PKEY_CTX *ctx)

{
  code *pcVar1;
  int iVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = *(int *)ctx, iVar2 == 0)) ||
     (*(int *)(iVar2 + 0x30) == 0)) {
    ERR_put_error(6,0x8f,0x96,"pmeth_fn.c",0x7d);
    iVar2 = -2;
  }
  else {
    pcVar1 = *(code **)(iVar2 + 0x2c);
    *(undefined4 *)(ctx + 0x10) = 0x10;
    iVar2 = 1;
    if (pcVar1 != (code *)0x0) {
      iVar2 = (*pcVar1)(ctx);
      if (iVar2 < 1) {
        *(undefined4 *)(ctx + 0x10) = 0;
        return iVar2;
      }
    }
  }
  return iVar2;
}
