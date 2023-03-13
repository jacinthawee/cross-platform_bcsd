
int EVP_PKEY_verify_recover(EVP_PKEY_CTX *ctx,uchar *rout,size_t *routlen,uchar *sig,size_t siglen)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = *(int *)ctx, iVar2 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x38), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x90,0x96,"pmeth_fn.c",0xad);
    iVar2 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x20) {
    if ((*(byte *)(iVar2 + 4) & 2) == 0) {
LAB_081342db:
                    /* WARNING: Could not recover jumptable at 0x081342f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
      return iVar2;
    }
    uVar1 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (rout == (uchar *)0x0) {
      *routlen = uVar1;
      iVar2 = 1;
    }
    else {
      if (uVar1 < *routlen || uVar1 == *routlen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x38);
        goto LAB_081342db;
      }
      ERR_put_error(6,0x90,0x9b,"pmeth_fn.c",0xb4);
      iVar2 = 0;
    }
  }
  else {
    ERR_put_error(6,0x90,0x97,"pmeth_fn.c",0xb1);
    iVar2 = -1;
  }
  return iVar2;
}

