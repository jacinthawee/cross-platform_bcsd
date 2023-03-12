
void gost_do_sign(int param_1,undefined4 param_2,int param_3)

{
  DSA_SIG *pDVar1;
  uchar *s;
  BIGNUM *a;
  BN_CTX *ctx;
  BIGNUM *rem;
  BIGNUM *rnd;
  BIGNUM *r;
  int len;
  BIGNUM *pBVar2;
  uchar *puVar3;
  uchar local_50 [32];
  uchar auStack_30 [4];
  int local_2c;
  
  local_2c = __TMC_END__;
  pDVar1 = DSA_SIG_new();
  puVar3 = (uchar *)(param_1 + -1);
  s = auStack_30;
  do {
    puVar3 = puVar3 + 1;
    s = s + -1;
    *s = *puVar3;
  } while (s != local_50);
  if (local_50[0] == '\0') {
    s = local_50;
    len = 0x20;
    do {
      s = s + 1;
      len = len + -1;
      if (*s != '\0') {
        if (len != 0) goto LAB_000f8daa;
        break;
      }
    } while (len != 0);
    a = BN_new();
    BN_set_word(a,0);
    ctx = BN_CTX_new();
    BN_CTX_start(ctx);
  }
  else {
    len = 0x20;
LAB_000f8daa:
    a = BN_bin2bn(s,len,(BIGNUM *)0x0);
    ctx = BN_CTX_new();
    BN_CTX_start(ctx);
  }
  if (pDVar1 == (DSA_SIG *)0x0) {
    ERR_GOST_error(0x70,0x76,"gost_sign.c",0x3d);
  }
  else {
    rem = BN_CTX_get(ctx);
    rnd = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    BN_div((BIGNUM *)0x0,rem,a,*(BIGNUM **)(param_3 + 0x10),ctx);
    if (rem->top == 0) {
      BN_set_word(a,1);
    }
    do {
      do {
        BN_rand_range(rnd,*(BIGNUM **)(param_3 + 0x10));
        BN_mod_exp(rem,*(BIGNUM **)(param_3 + 0x14),rnd,*(BIGNUM **)(param_3 + 0xc),ctx);
        pBVar2 = pDVar1->r;
        if (pBVar2 == (BIGNUM *)0x0) {
          pBVar2 = BN_new();
          pDVar1->r = pBVar2;
        }
        BN_div((BIGNUM *)0x0,pBVar2,rem,*(BIGNUM **)(param_3 + 0x10),ctx);
      } while (pDVar1->r->top == 0);
      BN_mod_mul(rem,*(BIGNUM **)(param_3 + 0x1c),pDVar1->r,*(BIGNUM **)(param_3 + 0x10),ctx);
      BN_mod_mul(r,rnd,a,*(BIGNUM **)(param_3 + 0x10),ctx);
      pBVar2 = pDVar1->s;
      if (pBVar2 == (BIGNUM *)0x0) {
        pBVar2 = BN_new();
        pDVar1->s = pBVar2;
      }
      BN_mod_add(pBVar2,rem,r,*(BIGNUM **)(param_3 + 0x10),ctx);
    } while (pDVar1->s->top == 0);
  }
  BN_free(a);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pDVar1);
}

