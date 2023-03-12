
int EVP_PKEY_sign(EVP_PKEY_CTX *ctx,uchar *sig,size_t *siglen,uchar *tbs,size_t tbslen)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = *(int *)ctx, iVar2 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x28), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x8c,0x96,"pmeth_fn.c",0x6b);
    iVar2 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 8) {
    if ((*(byte *)(iVar2 + 4) & 2) == 0) {
LAB_081367fb:
                    /* WARNING: Could not recover jumptable at 0x08136816. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
      return iVar2;
    }
    uVar1 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (sig == (uchar *)0x0) {
      *siglen = uVar1;
      iVar2 = 1;
    }
    else {
      if (uVar1 < *siglen || uVar1 == *siglen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x28);
        goto LAB_081367fb;
      }
      ERR_put_error(6,0x8c,0x9b,"pmeth_fn.c",0x73);
      iVar2 = 0;
    }
  }
  else {
    ERR_put_error(6,0x8c,0x97,"pmeth_fn.c",0x70);
    iVar2 = -1;
  }
  return iVar2;
}

