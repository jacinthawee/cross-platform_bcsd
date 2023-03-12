
DSA_SIG * gost2001_do_sign(undefined4 param_1,int param_2,EC_KEY *param_3)

{
  BIGNUM *m;
  BN_CTX *ctx;
  EC_GROUP *group;
  BIGNUM *pBVar1;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *rnd;
  int iVar2;
  BIGNUM *x;
  BIGNUM *r;
  undefined4 uVar3;
  undefined4 uVar4;
  EC_POINT *local_40;
  BIGNUM *local_38;
  BIGNUM *local_34;
  BIGNUM *local_30;
  DSA_SIG *local_24;
  
  m = (BIGNUM *)hashsum2bn(param_1);
  ctx = BN_CTX_new();
  BN_CTX_start(ctx);
  if (param_2 != 0x20) {
    OpenSSLDie("gost2001.c",0x69,"dlen==32");
  }
  local_24 = DSA_SIG_new();
  if (local_24 == (DSA_SIG *)0x0) {
    ERR_GOST_error(0x69,0x76,"gost2001.c",0x6d);
    local_40 = (EC_POINT *)0x0;
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
    x = (BIGNUM *)0x0;
    r = (BIGNUM *)0x0;
    rnd = BN_CTX_get(ctx);
    local_40 = EC_POINT_new(group);
    local_30 = (BIGNUM *)0x0;
    local_34 = (BIGNUM *)0x0;
    local_38 = (BIGNUM *)0x0;
    do {
      do {
        iVar2 = BN_rand_range(rnd,pBVar1);
        if (iVar2 == 0) {
          uVar4 = 0x89;
          uVar3 = 0x7d;
LAB_081d3c54:
          ERR_GOST_error(0x69,uVar3,"gost2001.c",uVar4);
          DSA_SIG_free(local_24);
          local_24 = (DSA_SIG *)0x0;
          goto LAB_081d3c70;
        }
        iVar2 = EC_POINT_mul(group,local_40,rnd,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
        if (iVar2 == 0) {
          uVar4 = 0x90;
LAB_081d3cc5:
          uVar3 = 0x10;
          goto LAB_081d3c54;
        }
        if (x == (BIGNUM *)0x0) {
          x = BN_CTX_get(ctx);
        }
        iVar2 = EC_POINT_get_affine_coordinates_GFp(group,local_40,x,(BIGNUM *)0x0,ctx);
        if (iVar2 == 0) {
          uVar4 = 0x98;
          goto LAB_081d3cc5;
        }
        if (r == (BIGNUM *)0x0) {
          r = BN_CTX_get(ctx);
        }
        BN_nnmod(r,x,pBVar1,ctx);
      } while (r->top == 0);
      if (local_34 == (BIGNUM *)0x0) {
        local_34 = BN_CTX_get(ctx);
      }
      BN_mod_mul(local_34,a,r,pBVar1,ctx);
      if (local_30 == (BIGNUM *)0x0) {
        local_30 = BN_CTX_get(ctx);
      }
      BN_mod_mul(local_30,rnd,rem,pBVar1,ctx);
      if (local_38 == (BIGNUM *)0x0) {
        local_38 = BN_CTX_get(ctx);
      }
      BN_mod_add(local_38,local_34,local_30,pBVar1,ctx);
    } while (local_38->top == 0);
    pBVar1 = BN_dup(local_38);
    local_24->s = pBVar1;
    pBVar1 = BN_dup(r);
    local_24->r = pBVar1;
  }
LAB_081d3c70:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  EC_POINT_free(local_40);
  BN_free(m);
  return local_24;
}

