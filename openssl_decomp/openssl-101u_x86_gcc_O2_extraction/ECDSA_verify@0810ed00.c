
int ECDSA_verify(int type,uchar *dgst,int dgstlen,uchar *sig,int siglen,EC_KEY *eckey)

{
  ECDSA_SIG *pEVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  ECDSA_SIG *local_2c;
  uchar *local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (uchar *)0x0;
  local_28 = sig;
  local_2c = ECDSA_SIG_new();
  if (local_2c == (ECDSA_SIG *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = -1;
    pEVar1 = d2i_ECDSA_SIG(&local_2c,&local_28,siglen);
    if (pEVar1 != (ECDSA_SIG *)0x0) {
      __n = i2d_ECDSA_SIG(local_2c,&local_24);
      if (siglen == __n) {
        iVar2 = memcmp(sig,local_24,__n);
        pEVar1 = local_2c;
        if (iVar2 == 0) {
          iVar3 = 0;
          iVar2 = ecdsa_check(eckey);
          if (iVar2 != 0) {
            iVar3 = (**(code **)(*(int *)(iVar2 + 0xc) + 0xc))(dgst,dgstlen,pEVar1,eckey);
          }
        }
      }
      if (0 < (int)__n) {
        OPENSSL_cleanse(local_24,__n);
        CRYPTO_free(local_24);
      }
    }
    ECDSA_SIG_free(local_2c);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

