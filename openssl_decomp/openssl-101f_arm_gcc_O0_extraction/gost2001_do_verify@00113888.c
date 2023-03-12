
int gost2001_do_verify(undefined4 param_1,undefined4 param_2,BIGNUM **param_3,EC_KEY *param_4)

{
  BN_CTX *ctx;
  EC_GROUP *group;
  BIGNUM *order;
  BIGNUM *pBVar1;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *x;
  BIGNUM *rem;
  BIGNUM *ret;
  EC_POINT *q;
  int iVar2;
  BIGNUM *m;
  int iVar3;
  EC_POINT *r_02;
  
  ctx = BN_CTX_new();
  group = EC_KEY_get0_group(param_4);
  BN_CTX_start(ctx);
  order = BN_CTX_get(ctx);
  pBVar1 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  r_01 = BN_CTX_get(ctx);
  x = BN_CTX_get(ctx);
  rem = BN_CTX_get(ctx);
  ret = BN_CTX_get(ctx);
  EC_GROUP_get_order(group,order,ctx);
  q = EC_KEY_get0_public_key(param_4);
  if ((param_3[1]->top != 0) && ((*param_3)->top != 0)) {
    iVar3 = BN_cmp(param_3[1],order);
    if ((iVar3 < 1) && (iVar3 = BN_cmp(*param_3,order), iVar3 < 1)) {
      m = (BIGNUM *)hashsum2bn(param_1);
      BN_div((BIGNUM *)0x0,pBVar1,m,order,ctx);
      if (pBVar1->top == 0) {
        BN_set_word(pBVar1,1);
      }
      pBVar1 = BN_mod_inverse(ret,pBVar1,order,ctx);
      BN_mod_mul(r,param_3[1],pBVar1,order,ctx);
      BN_sub(r_01,order,*param_3);
      BN_mod_mul(r_00,r_01,pBVar1,order,ctx);
      r_02 = EC_POINT_new(group);
      iVar3 = EC_POINT_mul(group,r_02,r,q,r_00,ctx);
      if (iVar3 == 0) {
        ERR_GOST_error(0x6a,0x10,"gost2001.c",0xf0);
      }
      else {
        iVar3 = EC_POINT_get_affine_coordinates_GFp(group,r_02,x,(BIGNUM *)0x0,ctx);
        if (iVar3 == 0) {
          ERR_GOST_error(0x6a,0x10,"gost2001.c",0xf5);
        }
        else {
          BN_div((BIGNUM *)0x0,rem,x,order,ctx);
          iVar3 = 1;
          iVar2 = BN_cmp(rem,*param_3);
          if (iVar2 != 0) {
            iVar3 = 0;
            ERR_GOST_error(0x6a,0x7e,"gost2001.c",0x102);
          }
        }
      }
      goto LAB_0011391e;
    }
  }
  iVar3 = 0;
  ERR_GOST_error(0x6a,0x7f,"gost2001.c",0xd3);
  r_02 = (EC_POINT *)0x0;
  m = (BIGNUM *)0x0;
LAB_0011391e:
  EC_POINT_free(r_02);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  BN_free(m);
  return iVar3;
}

