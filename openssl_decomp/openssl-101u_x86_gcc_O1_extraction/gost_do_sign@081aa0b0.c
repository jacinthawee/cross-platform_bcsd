
DSA_SIG * gost_do_sign(uchar *param_1,undefined4 param_2,int param_3)

{
  uchar uVar1;
  uchar *puVar2;
  int len;
  BN_CTX *ctx;
  DSA_SIG *a;
  BIGNUM *rem;
  BIGNUM *rnd;
  BIGNUM *r;
  BIGNUM *pBVar3;
  uchar *puVar4;
  int in_GS_OFFSET;
  undefined4 uVar5;
  BIGNUM *local_50;
  uchar local_41;
  uchar local_40 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  puVar4 = local_40 + 0x1f;
  do {
    uVar1 = *param_1;
    puVar2 = puVar4 + -1;
    param_1 = param_1 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar2;
  } while (puVar2 != &local_41);
  len = 0x20;
  puVar4 = local_40;
  if (local_40[0] == '\0') {
    do {
      puVar4 = puVar4 + 1;
      len = len + -1;
      if (*puVar4 != '\0') {
        if (len != 0) goto LAB_081aa113;
        break;
      }
    } while (len != 0);
    local_50 = BN_new();
    BN_set_word(local_50,0);
  }
  else {
LAB_081aa113:
    local_50 = BN_bin2bn(puVar4,len,(BIGNUM *)0x0);
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    a = (DSA_SIG *)0x0;
    ERR_GOST_error(0x70,0x41,"gost_sign.c",0x3d);
    BN_free(local_50);
  }
  else {
    BN_CTX_start(ctx);
    a = DSA_SIG_new();
    if (a == (DSA_SIG *)0x0) {
      ERR_GOST_error(0x70,0x76,"gost_sign.c",0x43);
    }
    else {
      rem = BN_CTX_get(ctx);
      rnd = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      if ((rem == (BIGNUM *)0x0 || rnd == (BIGNUM *)0x0) || (r == (BIGNUM *)0x0)) {
        uVar5 = 0x4a;
LAB_081aa230:
        ERR_GOST_error(0x70,0x41,"gost_sign.c",uVar5);
        BN_free(local_50);
        BN_CTX_end(ctx);
        BN_CTX_free(ctx);
        DSA_SIG_free(a);
        a = (DSA_SIG *)0x0;
        goto LAB_081aa26a;
      }
      BN_div((BIGNUM *)0x0,rem,local_50,*(BIGNUM **)(param_3 + 0x10),ctx);
      if (rem->top == 0) {
        BN_set_word(local_50,1);
      }
      do {
        do {
          BN_rand_range(rnd,*(BIGNUM **)(param_3 + 0x10));
          BN_mod_exp(rem,*(BIGNUM **)(param_3 + 0x14),rnd,*(BIGNUM **)(param_3 + 0xc),ctx);
          pBVar3 = a->r;
          if (pBVar3 == (BIGNUM *)0x0) {
            pBVar3 = BN_new();
            a->r = pBVar3;
            if (pBVar3 == (BIGNUM *)0x0) {
              uVar5 = 0x5c;
              goto LAB_081aa230;
            }
          }
          BN_div((BIGNUM *)0x0,pBVar3,rem,*(BIGNUM **)(param_3 + 0x10),ctx);
        } while (a->r->top == 0);
        BN_mod_mul(rem,*(BIGNUM **)(param_3 + 0x1c),a->r,*(BIGNUM **)(param_3 + 0x10),ctx);
        BN_mod_mul(r,rnd,local_50,*(BIGNUM **)(param_3 + 0x10),ctx);
        pBVar3 = a->s;
        if (pBVar3 == (BIGNUM *)0x0) {
          pBVar3 = BN_new();
          a->s = pBVar3;
          if (pBVar3 == (BIGNUM *)0x0) {
            uVar5 = 0x69;
            goto LAB_081aa230;
          }
        }
        BN_mod_add(pBVar3,rem,r,*(BIGNUM **)(param_3 + 0x10),ctx);
      } while (a->s->top == 0);
    }
    BN_free(local_50);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
LAB_081aa26a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a;
}

