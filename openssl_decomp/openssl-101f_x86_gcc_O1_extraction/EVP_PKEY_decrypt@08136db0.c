
int EVP_PKEY_decrypt(EVP_PKEY_CTX *ctx,uchar *out,size_t *outlen,uchar *in,size_t inlen)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = *(int *)ctx, iVar2 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x58), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x68,0x96,"pmeth_fn.c",0xfe);
    iVar2 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x200) {
    if ((*(byte *)(iVar2 + 4) & 2) == 0) {
LAB_08136e1e:
                    /* WARNING: Could not recover jumptable at 0x08136e39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)();
      return iVar2;
    }
    uVar1 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (out == (uchar *)0x0) {
      *outlen = uVar1;
      iVar2 = 1;
    }
    else {
      if (uVar1 < *outlen || uVar1 == *outlen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x58);
        goto LAB_08136e1e;
      }
      ERR_put_error(6,0x68,0x9b,"pmeth_fn.c",0x106);
      iVar2 = 0;
    }
  }
  else {
    ERR_put_error(6,0x68,0x97,"pmeth_fn.c",0x103);
    iVar2 = -1;
  }
  return iVar2;
}

