
int DSA_verify(int type,uchar *dgst,int dgst_len,uchar *sigbuf,int siglen,DSA *dsa)

{
  ASN1_VALUE *pAVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  DSA_SIG *local_2c;
  uchar *local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (uchar *)0x0;
  local_28 = sigbuf;
  local_2c = DSA_SIG_new();
  if (local_2c == (DSA_SIG *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = -1;
    pAVar1 = ASN1_item_d2i((ASN1_VALUE **)&local_2c,&local_28,siglen,(ASN1_ITEM *)DSA_SIG_it);
    if (pAVar1 != (ASN1_VALUE *)0x0) {
      __n = ASN1_item_i2d((ASN1_VALUE *)local_2c,&local_24,(ASN1_ITEM *)DSA_SIG_it);
      if (siglen == __n) {
        iVar2 = memcmp(sigbuf,local_24,__n);
        if (iVar2 == 0) {
          iVar3 = DSA_do_verify(dgst,dgst_len,local_2c,dsa);
        }
      }
      if (0 < (int)__n) {
        OPENSSL_cleanse(local_24,__n);
        CRYPTO_free(local_24);
      }
    }
    DSA_SIG_free(local_2c);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

