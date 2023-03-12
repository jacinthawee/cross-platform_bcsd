
void gost_do_sign(int param_1,undefined4 param_2,int param_3)

{
  uchar *puVar1;
  uchar *s;
  BIGNUM *a;
  DSA_SIG *ctx;
  DSA_SIG *a_00;
  BIGNUM *rem;
  BIGNUM *rnd;
  BIGNUM *r;
  int len;
  BIGNUM *pBVar2;
  uchar local_50 [32];
  uchar auStack_30 [4];
  int local_2c;
  
  puVar1 = (uchar *)(param_1 + -1);
  s = auStack_30;
  local_2c = __stack_chk_guard;
  do {
    puVar1 = puVar1 + 1;
    s = s + -1;
    *s = *puVar1;
  } while (s != local_50);
  if (local_50[0] == '\0') {
    s = local_50;
    len = 0x20;
    do {
      s = s + 1;
      len = len + -1;
      if (*s != '\0') {
        if (len != 0) goto LAB_000f6f12;
        break;
      }
    } while (len != 0);
    a = BN_new();
    BN_set_word(a,0);
  }
  else {
    len = 0x20;
LAB_000f6f12:
    a = BN_bin2bn(s,len,(BIGNUM *)0x0);
  }
  ctx = (DSA_SIG *)BN_CTX_new();
  if (ctx == (DSA_SIG *)0x0) {
    ERR_GOST_error(0x70,0x41,"gost_sign.c",0x3d);
    BN_free(a);
  }
  else {
    BN_CTX_start((BN_CTX *)ctx);
    a_00 = DSA_SIG_new();
    if (a_00 == (DSA_SIG *)0x0) {
      ERR_GOST_error(0x70,0x76,"gost_sign.c",0x43);
    }
    else {
      rem = BN_CTX_get((BN_CTX *)ctx);
      rnd = BN_CTX_get((BN_CTX *)ctx);
      r = BN_CTX_get((BN_CTX *)ctx);
      if ((rnd == (BIGNUM *)0x0 || rem == (BIGNUM *)0x0) || (r == (BIGNUM *)0x0)) {
        ERR_GOST_error(0x70,0x41,"gost_sign.c",0x4a);
LAB_000f6fd0:
        BN_free(a);
        BN_CTX_end((BN_CTX *)ctx);
        BN_CTX_free((BN_CTX *)ctx);
        DSA_SIG_free(a_00);
        ctx = (DSA_SIG *)0x0;
        goto LAB_000f6fea;
      }
      BN_div((BIGNUM *)0x0,rem,a,*(BIGNUM **)(param_3 + 0x10),(BN_CTX *)ctx);
      if (rem->top == 0) {
        BN_set_word(a,1);
      }
      do {
        do {
          BN_rand_range(rnd,*(BIGNUM **)(param_3 + 0x10));
          BN_mod_exp(rem,*(BIGNUM **)(param_3 + 0x14),rnd,*(BIGNUM **)(param_3 + 0xc),(BN_CTX *)ctx)
          ;
          pBVar2 = a_00->r;
          if (pBVar2 == (BIGNUM *)0x0) {
            pBVar2 = BN_new();
            a_00->r = pBVar2;
            if (pBVar2 == (BIGNUM *)0x0) {
              ERR_GOST_error(0x70,0x41,"gost_sign.c",0x5c);
              goto LAB_000f6fd0;
            }
          }
          BN_div((BIGNUM *)0x0,pBVar2,rem,*(BIGNUM **)(param_3 + 0x10),(BN_CTX *)ctx);
        } while (a_00->r->top == 0);
        BN_mod_mul(rem,*(BIGNUM **)(param_3 + 0x1c),a_00->r,*(BIGNUM **)(param_3 + 0x10),
                   (BN_CTX *)ctx);
        BN_mod_mul(r,rnd,a,*(BIGNUM **)(param_3 + 0x10),(BN_CTX *)ctx);
        pBVar2 = a_00->s;
        if (pBVar2 == (BIGNUM *)0x0) {
          pBVar2 = BN_new();
          a_00->s = pBVar2;
          if (pBVar2 == (BIGNUM *)0x0) {
            ERR_GOST_error(0x70,0x41,"gost_sign.c",0x69);
            goto LAB_000f6fd0;
          }
        }
        BN_mod_add(pBVar2,rem,r,*(BIGNUM **)(param_3 + 0x10),(BN_CTX *)ctx);
      } while (a_00->s->top == 0);
    }
    BN_free(a);
    BN_CTX_end((BN_CTX *)ctx);
    BN_CTX_free((BN_CTX *)ctx);
    ctx = a_00;
  }
LAB_000f6fea:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(ctx);
  }
  return;
}

