
undefined4
gost2001_do_verify(undefined4 param_1,undefined4 param_2,BIGNUM **param_3,EC_KEY *param_4)

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
  int iVar3;
  BIGNUM *pBVar4;
  EC_POINT *r_02;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
  ctx = BN_CTX_new();
  group = EC_KEY_get0_group(param_4);
  if ((ctx == (BN_CTX *)0x0) || (group == (EC_GROUP *)0x0)) {
    pBVar4 = (BIGNUM *)0x0;
    uVar5 = 0;
    ERR_GOST_error(0x6a,0x44,"gost2001.c",0x112);
    if (ctx == (BN_CTX *)0x0) {
      return 0;
    }
    goto LAB_081d3cc2;
  }
  BN_CTX_start(ctx);
  order = BN_CTX_get(ctx);
  pBVar1 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  r_01 = BN_CTX_get(ctx);
  x = BN_CTX_get(ctx);
  rem = BN_CTX_get(ctx);
  ret = BN_CTX_get(ctx);
  if (((((order == (BIGNUM *)0x0) || (pBVar1 == (BIGNUM *)0x0)) || (r == (BIGNUM *)0x0)) ||
      ((r_00 == (BIGNUM *)0x0 || (r_01 == (BIGNUM *)0x0)))) ||
     ((x == (BIGNUM *)0x0 || ((rem == (BIGNUM *)0x0 || (ret == (BIGNUM *)0x0)))))) {
    ERR_GOST_error(0x6a,0x41,"gost2001.c",0x120);
  }
  else {
    q = EC_KEY_get0_public_key(param_4);
    if ((q == (EC_POINT *)0x0) || (iVar2 = EC_GROUP_get_order(group,order,ctx), iVar2 == 0)) {
      ERR_GOST_error(0x6a,0x44,"gost2001.c",0x126);
    }
    else {
      if ((((param_3[1]->top != 0) && ((*param_3)->top != 0)) &&
          (iVar2 = BN_cmp(param_3[1],order), iVar2 < 1)) &&
         (pBVar4 = order, iVar6 = iVar2, iVar3 = BN_cmp(*param_3,order), iVar3 < 1)) {
        pBVar4 = (BIGNUM *)hashsum2bn(param_1,pBVar4,iVar2,iVar6);
        if ((pBVar4 == (BIGNUM *)0x0) ||
           (iVar2 = BN_div((BIGNUM *)0x0,pBVar1,pBVar4,order,ctx), iVar2 == 0)) {
          uVar5 = 0;
          ERR_GOST_error(0x6a,0x44,"gost2001.c",0x134);
          goto LAB_081d3cc2;
        }
        if ((pBVar1->top == 0) && (iVar2 = BN_set_word(pBVar1,1), iVar2 == 0)) {
          uVar7 = 0x13e;
        }
        else {
          pBVar1 = BN_mod_inverse(ret,pBVar1,order,ctx);
          if ((((pBVar1 != (BIGNUM *)0x0) &&
               (iVar2 = BN_mod_mul(r,param_3[1],pBVar1,order,ctx), iVar2 != 0)) &&
              (iVar2 = BN_sub(r_01,order,*param_3), iVar2 != 0)) &&
             (iVar2 = BN_mod_mul(r_00,r_01,pBVar1,order,ctx), iVar2 != 0)) {
            r_02 = EC_POINT_new(group);
            if (r_02 == (EC_POINT *)0x0) {
              uVar5 = 0;
              ERR_GOST_error(0x6a,0x41,"gost2001.c",0x153);
              goto LAB_081d3cc2;
            }
            iVar2 = EC_POINT_mul(group,r_02,r,q,r_00,ctx);
            if (iVar2 == 0) {
              uVar7 = 0x157;
LAB_081d3f07:
              uVar5 = 0;
              ERR_GOST_error(0x6a,0x10,"gost2001.c",uVar7);
            }
            else {
              iVar2 = EC_POINT_get_affine_coordinates_GFp(group,r_02,x,(BIGNUM *)0x0,ctx);
              if (iVar2 == 0) {
                uVar7 = 0x15b;
                goto LAB_081d3f07;
              }
              iVar2 = BN_div((BIGNUM *)0x0,rem,x,order,ctx);
              if (iVar2 == 0) {
                uVar5 = 0;
                ERR_GOST_error(0x6a,0x44,"gost2001.c",0x15f);
              }
              else {
                uVar5 = 1;
                iVar2 = BN_cmp(rem,*param_3);
                if (iVar2 != 0) {
                  uVar5 = 0;
                  ERR_GOST_error(0x6a,0x7e,"gost2001.c",0x16a);
                }
              }
            }
            EC_POINT_free(r_02);
            goto LAB_081d3cc2;
          }
          uVar7 = 0x146;
        }
        uVar5 = 0;
        ERR_GOST_error(0x6a,0x44,"gost2001.c",uVar7);
        goto LAB_081d3cc2;
      }
      ERR_GOST_error(0x6a,0x7f,"gost2001.c",0x12d);
    }
  }
  pBVar4 = (BIGNUM *)0x0;
  uVar5 = 0;
LAB_081d3cc2:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  if (pBVar4 != (BIGNUM *)0x0) {
    BN_free(pBVar4);
  }
  return uVar5;
}

