
int EVP_PKEY_verify_recover_init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  code *pcVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (*(int *)(iVar1 + 0x38) == 0)) {
    ERR_put_error(6,0x91,0x96,"pmeth_fn.c",0x9b);
    iVar1 = -2;
  }
  else {
    pcVar2 = *(code **)(iVar1 + 0x34);
    *(undefined4 *)(ctx + 0x10) = 0x20;
    if (pcVar2 == (code *)0x0) {
      return 1;
    }
    iVar1 = (*pcVar2)();
    if (iVar1 < 1) {
      *(undefined4 *)(ctx + 0x10) = 0;
      return iVar1;
    }
  }
  return iVar1;
}
