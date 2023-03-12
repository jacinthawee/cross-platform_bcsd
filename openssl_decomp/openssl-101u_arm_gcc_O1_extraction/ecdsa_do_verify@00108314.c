
uint ecdsa_do_verify(uchar *param_1,int param_2,BIGNUM **param_3,EC_KEY *param_4)

{
  EC_GROUP *group;
  EC_POINT *q;
  BN_CTX *ctx;
  BIGNUM *order;
  BIGNUM *r;
  BIGNUM *ret;
  BIGNUM *ret_00;
  BIGNUM *x;
  BIGNUM *pBVar1;
  EC_POINT *r_00;
  EC_METHOD *meth;
  int iVar2;
  uint uVar3;
  
  if ((((param_4 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_4), group == (EC_GROUP *)0x0)
       ) || (q = EC_KEY_get0_public_key(param_4), q == (EC_POINT *)0x0)) ||
     (param_3 == (BIGNUM **)0x0)) {
    ERR_put_error(0x2a,0x66,0x67,"ecs_ossl.c",0x156);
    return 0xffffffff;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_put_error(0x2a,0x66,0x41,"ecs_ossl.c",0x15c);
    return 0xffffffff;
  }
  BN_CTX_start(ctx);
  order = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  ret = BN_CTX_get(ctx);
  ret_00 = BN_CTX_get(ctx);
  x = BN_CTX_get(ctx);
  iVar2 = 0x166;
  if (x == (BIGNUM *)0x0) goto LAB_00108484;
  iVar2 = EC_GROUP_get_order(group,order,ctx);
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
    ERR_put_error(0x2a,0x66,0x10,"ecs_ossl.c",0x16b);
    goto LAB_001083be;
  }
  pBVar1 = *param_3;
  if ((((pBVar1->top == 0) || (pBVar1->neg != 0)) ||
      ((iVar2 = BN_ucmp(pBVar1,order), -1 < iVar2 ||
       ((pBVar1 = param_3[1], pBVar1->top == 0 || (pBVar1->neg != 0)))))) ||
     (iVar2 = BN_ucmp(pBVar1,order), -1 < iVar2)) {
    uVar3 = 0;
    ERR_put_error(0x2a,0x66,100,"ecs_ossl.c",0x172);
    goto LAB_001083be;
  }
  pBVar1 = BN_mod_inverse(ret,param_3[1],order,ctx);
  if (pBVar1 == (BIGNUM *)0x0) {
    iVar2 = 0x178;
  }
  else {
    uVar3 = BN_num_bits(order);
    if ((int)(uVar3 + param_2 * -8) < 0 != SBORROW4(uVar3,param_2 * 8)) {
      param_2 = uVar3 + 7;
      if (param_2 < 0) {
        param_2 = uVar3 + 0xe;
      }
      param_2 = param_2 >> 3;
    }
    pBVar1 = BN_bin2bn(param_1,param_2,ret_00);
    if (pBVar1 == (BIGNUM *)0x0) {
      iVar2 = 0x183;
    }
    else if (((int)(uVar3 + param_2 * -8) < 0 == SBORROW4(uVar3,param_2 * 8)) ||
            (iVar2 = BN_rshift(ret_00,ret_00,8 - (uVar3 & 7)), iVar2 != 0)) {
      iVar2 = BN_mod_mul(r,ret_00,ret,order,ctx);
      if (iVar2 == 0) {
        iVar2 = 0x18d;
      }
      else {
        iVar2 = BN_mod_mul(ret,*param_3,ret,order,ctx);
        if (iVar2 != 0) {
          r_00 = EC_POINT_new(group);
          if (r_00 == (EC_POINT *)0x0) {
            uVar3 = 0xffffffff;
            ERR_put_error(0x2a,0x66,0x41,"ecs_ossl.c",0x197);
            goto LAB_001083be;
          }
          iVar2 = EC_POINT_mul(group,r_00,r,q,ret,ctx);
          if (iVar2 == 0) {
            iVar2 = 0x19b;
          }
          else {
            meth = EC_GROUP_method_of(group);
            iVar2 = EC_METHOD_get_field_type(meth);
            if (iVar2 == 0x196) {
              iVar2 = EC_POINT_get_affine_coordinates_GFp(group,r_00,x,(BIGNUM *)0x0,ctx);
              if (iVar2 != 0) goto LAB_00108580;
              iVar2 = 0x1a1;
            }
            else {
              iVar2 = EC_POINT_get_affine_coordinates_GF2m();
              if (iVar2 != 0) {
LAB_00108580:
                iVar2 = BN_nnmod(r,x,order,ctx);
                if (iVar2 == 0) {
                  uVar3 = 0xffffffff;
                  ERR_put_error(0x2a,0x66,3,"ecs_ossl.c",0x1af);
                }
                else {
                  iVar2 = BN_ucmp(r,*param_3);
                  uVar3 = count_leading_zeroes(iVar2);
                  uVar3 = uVar3 >> 5;
                }
                goto LAB_00108540;
              }
              iVar2 = 0x1a9;
            }
          }
          uVar3 = 0xffffffff;
          ERR_put_error(0x2a,0x66,0x10,"ecs_ossl.c",iVar2);
LAB_00108540:
          BN_CTX_end(ctx);
          BN_CTX_free(ctx);
          EC_POINT_free(r_00);
          return uVar3;
        }
        iVar2 = 0x192;
      }
    }
    else {
      iVar2 = 0x188;
    }
  }
LAB_00108484:
  uVar3 = 0xffffffff;
  ERR_put_error(0x2a,0x66,3,"ecs_ossl.c",iVar2);
LAB_001083be:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return uVar3;
}

