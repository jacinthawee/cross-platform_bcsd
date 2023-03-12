
int EVP_PKEY_verify_recover(EVP_PKEY_CTX *ctx,uchar *rout,size_t *routlen,uchar *sig,size_t siglen)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x38), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x90,0x96,"pmeth_fn.c",0xb4);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x20) {
    if ((*(uint *)(iVar1 + 4) & 2) == 0) {
LAB_0054904c:
                    /* WARNING: Could not recover jumptable at 0x0054905c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,rout,routlen,sig);
      return iVar1;
    }
    uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (rout == (uchar *)0x0) {
      *routlen = uVar2;
      iVar1 = 1;
    }
    else {
      if (uVar2 <= *routlen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x38);
        goto LAB_0054904c;
      }
      ERR_put_error(6,0x90,0x9b,"pmeth_fn.c",0xbc);
      iVar1 = 0;
    }
  }
  else {
    ERR_put_error(6,0x90,0x97,"pmeth_fn.c",0xb9);
    iVar1 = -1;
  }
  return iVar1;
}

