
BN_BLINDING *
BN_BLINDING_create_param
          (BN_BLINDING *b,BIGNUM *e,BIGNUM *m,BN_CTX *ctx,bn_mod_exp *bn_mod_exp,BN_MONT_CTX *m_ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  ulong uVar3;
  BIGNUM **ptr;
  int iVar4;
  
  ptr = (BIGNUM **)b;
  if ((b == (BN_BLINDING *)0x0) &&
     (ptr = (BIGNUM **)BN_BLINDING_new((BIGNUM *)0x0,(BIGNUM *)0x0,m), ptr == (BIGNUM **)0x0)) {
    return (BN_BLINDING *)0x0;
  }
  if (*ptr == (BIGNUM *)0x0) {
    pBVar1 = BN_new();
    *ptr = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) {
      if (b != (BN_BLINDING *)0x0) {
        return (BN_BLINDING *)ptr;
      }
      goto LAB_081b94ba;
    }
  }
  if (ptr[1] == (BIGNUM *)0x0) {
    pBVar1 = BN_new();
    ptr[1] = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) goto LAB_081b9352;
  }
  else {
LAB_081b9352:
    if (e == (BIGNUM *)0x0) {
      pBVar1 = ptr[2];
    }
    else {
      if (ptr[2] != (BIGNUM *)0x0) {
        BN_free(ptr[2]);
      }
      pBVar1 = BN_dup(e);
      ptr[2] = pBVar1;
    }
    if (pBVar1 != (BIGNUM *)0x0) {
      if (bn_mod_exp != (bn_mod_exp *)0x0) {
        ptr[10] = (BIGNUM *)bn_mod_exp;
      }
      if (m_ctx != (BN_MONT_CTX *)0x0) {
        ptr[9] = (BIGNUM *)m_ctx;
      }
      iVar4 = 0x21;
      while (iVar2 = BN_rand_range(*ptr,ptr[3]), iVar2 != 0) {
        pBVar1 = BN_mod_inverse(ptr[1],*ptr,ptr[3],ctx);
        if (pBVar1 != (BIGNUM *)0x0) {
          if ((ptr[10] == (BIGNUM *)0x0) || (ptr[9] == (BIGNUM *)0x0)) {
            iVar4 = BN_mod_exp(*ptr,*ptr,ptr[2],ptr[3],ctx);
          }
          else {
            iVar4 = (*(code *)ptr[10])(*ptr,*ptr,ptr[2],ptr[3],ctx,ptr[9]);
          }
          if (iVar4 != 0) {
            return (BN_BLINDING *)ptr;
          }
          break;
        }
        uVar3 = ERR_peek_last_error();
        if ((uVar3 & 0xfff) != 0x6c) break;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          ERR_put_error(3,0x80,0x71,"bn_blind.c",0x161);
          break;
        }
        ERR_clear_error();
      }
    }
  }
  if (b != (BN_BLINDING *)0x0) {
    return (BN_BLINDING *)ptr;
  }
  if (*ptr != (BIGNUM *)0x0) {
    BN_free(*ptr);
  }
LAB_081b94ba:
  if (ptr[1] != (BIGNUM *)0x0) {
    BN_free(ptr[1]);
  }
  if (ptr[2] != (BIGNUM *)0x0) {
    BN_free(ptr[2]);
  }
  if (ptr[3] != (BIGNUM *)0x0) {
    BN_free(ptr[3]);
  }
  CRYPTO_free(ptr);
  return (BN_BLINDING *)0x0;
}

