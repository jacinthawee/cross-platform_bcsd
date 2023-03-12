
DSA_SIG * gost2001_do_sign(undefined4 param_1,int param_2,EC_KEY *param_3)

{
  BIGNUM *m;
  BN_CTX *ctx;
  EC_GROUP *group;
  BIGNUM *pBVar1;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *rnd;
  DSA_SIG *r;
  DSA_SIG *pDVar2;
  BIGNUM *x;
  BIGNUM *r_00;
  undefined4 uVar3;
  BIGNUM *r_01;
  undefined4 uVar4;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  DSA_SIG *local_30;
  
  m = (BIGNUM *)hashsum2bn();
  ctx = BN_CTX_new();
  BN_CTX_start(ctx);
  if (param_2 != 0x20) {
    OpenSSLDie("gost2001.c",0x69,"dlen==32");
  }
  local_30 = DSA_SIG_new();
  if (local_30 == (DSA_SIG *)0x0) {
    ERR_GOST_error(0x69,0x76,"gost2001.c",0x6d);
    r = local_30;
  }
  else {
    group = EC_KEY_get0_group(param_3);
    pBVar1 = BN_CTX_get(ctx);
    EC_GROUP_get_order(group,pBVar1,ctx);
    a = EC_KEY_get0_private_key(param_3);
    rem = BN_CTX_get(ctx);
    BN_div((BIGNUM *)0x0,rem,m,pBVar1,ctx);
    if (rem->top == 0) {
      BN_set_word(rem,1);
    }
    local_40 = (BIGNUM *)0x0;
    rnd = BN_CTX_get(ctx);
    r = (DSA_SIG *)EC_POINT_new(group);
    r_01 = (BIGNUM *)0x0;
    local_3c = (BIGNUM *)0x0;
    x = r_01;
    r_00 = r_01;
    do {
      do {
        pDVar2 = (DSA_SIG *)BN_rand_range(rnd,pBVar1);
        if (pDVar2 == (DSA_SIG *)0x0) {
          uVar3 = 0x7d;
          uVar4 = 0x89;
LAB_0011380a:
          ERR_GOST_error(0x69,uVar3,"gost2001.c",uVar4);
          DSA_SIG_free(local_30);
          local_30 = pDVar2;
          goto LAB_00113820;
        }
        pDVar2 = (DSA_SIG *)EC_POINT_mul(group,(EC_POINT *)r,rnd,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
        if (pDVar2 == (DSA_SIG *)0x0) {
          uVar3 = 0x10;
          uVar4 = 0x90;
          goto LAB_0011380a;
        }
        if (x == (BIGNUM *)0x0) {
          x = BN_CTX_get(ctx);
        }
        pDVar2 = (DSA_SIG *)
                 EC_POINT_get_affine_coordinates_GFp(group,(EC_POINT *)r,x,(BIGNUM *)0x0,ctx);
        if (pDVar2 == (DSA_SIG *)0x0) {
          uVar3 = 0x10;
          uVar4 = 0x98;
          goto LAB_0011380a;
        }
        if (r_01 == (BIGNUM *)0x0) {
          r_01 = BN_CTX_get(ctx);
        }
        BN_nnmod(r_01,x,pBVar1,ctx);
      } while (r_01->top == 0);
      if (local_3c == (BIGNUM *)0x0) {
        local_3c = BN_CTX_get(ctx);
      }
      BN_mod_mul(local_3c,a,r_01,pBVar1,ctx);
      if (local_40 == (BIGNUM *)0x0) {
        local_40 = BN_CTX_get(ctx);
      }
      BN_mod_mul(local_40,rnd,rem,pBVar1,ctx);
      if (r_00 == (BIGNUM *)0x0) {
        r_00 = BN_CTX_get(ctx);
      }
      BN_mod_add(r_00,local_3c,local_40,pBVar1,ctx);
    } while (r_00->top == 0);
    pBVar1 = BN_dup(r_00);
    local_30->s = pBVar1;
    pBVar1 = BN_dup(r_01);
    local_30->r = pBVar1;
  }
LAB_00113820:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  EC_POINT_free((EC_POINT *)r);
  BN_free(m);
  return local_30;
}

