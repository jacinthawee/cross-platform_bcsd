
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
  int iVar1;
  BIGNUM *pBVar2;
  EC_POINT *r_00;
  EC_METHOD *meth;
  uint uVar3;
  int iVar4;
  BN_CTX *pBVar5;
  EC_POINT *pEVar6;
  EC_POINT *pEVar7;
  
  if ((((param_4 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_4), group == (EC_GROUP *)0x0)
       ) || (q = EC_KEY_get0_public_key(param_4), q == (EC_POINT *)0x0)) ||
     (param_3 == (BIGNUM **)0x0)) {
    iVar4 = 0x16f;
    iVar1 = 0x67;
LAB_081c51ef:
    ERR_put_error(0x2a,0x66,iVar1,"ecs_ossl.c",iVar4);
    return 0xffffffff;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    iVar4 = 0x176;
    iVar1 = 0x41;
    goto LAB_081c51ef;
  }
  BN_CTX_start(ctx);
  order = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  ret = BN_CTX_get(ctx);
  ret_00 = BN_CTX_get(ctx);
  x = BN_CTX_get(ctx);
  if (x == (BIGNUM *)0x0) {
    iVar4 = 0x181;
    iVar1 = 3;
  }
  else {
    iVar1 = EC_GROUP_get_order(group,order,ctx);
    if (iVar1 == 0) {
      iVar4 = 0x187;
      iVar1 = 0x10;
    }
    else {
      pBVar2 = *param_3;
      if ((((pBVar2->top == 0) || (pBVar2->neg != 0)) ||
          ((iVar1 = BN_ucmp(pBVar2,order), -1 < iVar1 ||
           ((pBVar2 = param_3[1], pBVar2->top == 0 || (pBVar2->neg != 0)))))) ||
         (iVar1 = BN_ucmp(pBVar2,order), -1 < iVar1)) {
        uVar3 = 0;
        ERR_put_error(0x2a,0x66,100,"ecs_ossl.c",399);
        goto LAB_081c503f;
      }
      pBVar2 = BN_mod_inverse(ret,param_3[1],order,ctx);
      if (pBVar2 == (BIGNUM *)0x0) {
        iVar4 = 0x196;
        iVar1 = 3;
      }
      else {
        uVar3 = BN_num_bits(order);
        if ((int)uVar3 < param_2 * 8) {
          iVar1 = (int)(uVar3 + 7) / 8;
          pBVar2 = BN_bin2bn(param_1,iVar1,ret_00);
          if (pBVar2 == (BIGNUM *)0x0) {
LAB_081c523b:
            iVar4 = 0x1a2;
            iVar1 = 3;
          }
          else {
            if ((iVar1 * 8 <= (int)uVar3) ||
               (iVar1 = BN_rshift(ret_00,ret_00,8 - (uVar3 & 7)), iVar1 != 0)) goto LAB_081c5185;
            iVar4 = 0x1a8;
            iVar1 = 3;
          }
        }
        else {
          pBVar2 = BN_bin2bn(param_1,param_2,ret_00);
          if (pBVar2 == (BIGNUM *)0x0) goto LAB_081c523b;
LAB_081c5185:
          iVar1 = BN_mod_mul(r,ret_00,ret,order,ctx);
          if (iVar1 == 0) {
            iVar4 = 0x1ae;
            iVar1 = 3;
          }
          else {
            iVar1 = BN_mod_mul(ret,*param_3,ret,order,ctx);
            if (iVar1 == 0) {
              iVar4 = 0x1b4;
              iVar1 = 3;
            }
            else {
              r_00 = EC_POINT_new(group);
              if (r_00 != (EC_POINT *)0x0) {
                pBVar5 = ctx;
                pEVar6 = r_00;
                pEVar7 = r_00;
                iVar1 = EC_POINT_mul(group,r_00,r,q,ret,ctx);
                if (iVar1 == 0) {
                  iVar4 = 0x1bf;
                  iVar1 = 0x10;
                }
                else {
                  meth = EC_GROUP_method_of(group);
                  iVar1 = EC_METHOD_get_field_type(meth);
                  if (iVar1 == 0x196) {
                    iVar1 = EC_POINT_get_affine_coordinates_GFp(group,r_00,x,(BIGNUM *)0x0,ctx);
                    if (iVar1 != 0) goto LAB_081c538e;
                    iVar4 = 0x1c7;
                    iVar1 = 0x10;
                  }
                  else {
                    iVar1 = EC_POINT_get_affine_coordinates_GF2m
                                      (group,r_00,x,0,ctx,pBVar5,pEVar6,pEVar7);
                    if (iVar1 == 0) {
                      iVar4 = 0x1d1;
                      iVar1 = 0x10;
                    }
                    else {
LAB_081c538e:
                      iVar1 = BN_nnmod(r,x,order,ctx);
                      if (iVar1 != 0) {
                        iVar1 = BN_ucmp(r,*param_3);
                        uVar3 = (uint)(iVar1 == 0);
                        goto LAB_081c530f;
                      }
                      iVar4 = 0x1d8;
                      iVar1 = 3;
                    }
                  }
                }
                uVar3 = 0xffffffff;
                ERR_put_error(0x2a,0x66,iVar1,"ecs_ossl.c",iVar4);
LAB_081c530f:
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
                EC_POINT_free(r_00);
                return uVar3;
              }
              iVar4 = 0x1ba;
              iVar1 = 0x41;
            }
          }
        }
      }
    }
  }
  uVar3 = 0xffffffff;
  ERR_put_error(0x2a,0x66,iVar1,"ecs_ossl.c",iVar4);
LAB_081c503f:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return uVar3;
}

