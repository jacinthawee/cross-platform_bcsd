
DSA_SIG * gost_do_sign(uchar *param_1,undefined4 param_2,int param_3)

{
  uchar uVar1;
  DSA_SIG *pDVar2;
  uchar *puVar3;
  int len;
  BN_CTX *ctx;
  BIGNUM *rem;
  BIGNUM *rnd;
  BIGNUM *r;
  BIGNUM *pBVar4;
  uchar *puVar5;
  int in_GS_OFFSET;
  BIGNUM *local_50;
  uchar local_41;
  uchar local_40 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pDVar2 = DSA_SIG_new();
  puVar5 = local_40 + 0x1f;
  do {
    uVar1 = *param_1;
    puVar3 = puVar5 + -1;
    param_1 = param_1 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar3;
  } while (puVar3 != &local_41);
  len = 0x20;
  puVar5 = local_40;
  if (local_40[0] == '\0') {
    do {
      puVar5 = puVar5 + 1;
      len = len + -1;
      if (*puVar5 != '\0') {
        if (len != 0) goto LAB_081ab69b;
        break;
      }
    } while (len != 0);
    local_50 = BN_new();
    BN_set_word(local_50,0);
  }
  else {
LAB_081ab69b:
    local_50 = BN_bin2bn(puVar5,len,(BIGNUM *)0x0);
  }
  ctx = BN_CTX_new();
  BN_CTX_start(ctx);
  if (pDVar2 == (DSA_SIG *)0x0) {
    ERR_GOST_error(0x70,0x76,"gost_sign.c",0x3d);
  }
  else {
    rem = BN_CTX_get(ctx);
    rnd = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    BN_div((BIGNUM *)0x0,rem,local_50,*(BIGNUM **)(param_3 + 0x10),ctx);
    if (rem->top == 0) {
      BN_set_word(local_50,1);
    }
    do {
      do {
        BN_rand_range(rnd,*(BIGNUM **)(param_3 + 0x10));
        BN_mod_exp(rem,*(BIGNUM **)(param_3 + 0x14),rnd,*(BIGNUM **)(param_3 + 0xc),ctx);
        pBVar4 = pDVar2->r;
        if (pBVar4 == (BIGNUM *)0x0) {
          pBVar4 = BN_new();
          pDVar2->r = pBVar4;
        }
        BN_div((BIGNUM *)0x0,pBVar4,rem,*(BIGNUM **)(param_3 + 0x10),ctx);
      } while (pDVar2->r->top == 0);
      BN_mod_mul(rem,*(BIGNUM **)(param_3 + 0x1c),pDVar2->r,*(BIGNUM **)(param_3 + 0x10),ctx);
      BN_mod_mul(r,rnd,local_50,*(BIGNUM **)(param_3 + 0x10),ctx);
      pBVar4 = pDVar2->s;
      if (pBVar4 == (BIGNUM *)0x0) {
        pBVar4 = BN_new();
        pDVar2->s = pBVar4;
      }
      BN_mod_add(pBVar4,rem,r,*(BIGNUM **)(param_3 + 0x10),ctx);
    } while (pDVar2->s->top == 0);
  }
  BN_free(local_50);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pDVar2;
}

