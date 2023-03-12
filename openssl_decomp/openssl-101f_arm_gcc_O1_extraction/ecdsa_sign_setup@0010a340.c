
BIGNUM * ecdsa_sign_setup(EC_KEY *param_1,BN_CTX *param_2,BIGNUM **param_3,BIGNUM **param_4)

{
  EC_GROUP *group;
  BIGNUM *pBVar1;
  BIGNUM *r;
  BIGNUM *order;
  BIGNUM *x;
  int iVar2;
  BN_CTX *ctx;
  EC_METHOD *meth;
  BIGNUM *pBVar3;
  int iVar4;
  BIGNUM *r_00;
  
  if ((param_1 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_1), group == (EC_GROUP *)0x0))
  {
    ERR_put_error(0x2a,0x67,0x43,"ecs_ossl.c",100);
    return (BIGNUM *)0x0;
  }
  ctx = param_2;
  if ((param_2 == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
    ERR_put_error(0x2a,0x67,0x41,"ecs_ossl.c",0x6c);
    return (BIGNUM *)0x0;
  }
  pBVar1 = BN_new();
  r = BN_new();
  order = BN_new();
  x = BN_new();
  if ((r == (BIGNUM *)0x0 || pBVar1 == (BIGNUM *)0x0) ||
     (x == (BIGNUM *)0x0 || order == (BIGNUM *)0x0)) {
    ERR_put_error(0x2a,0x67,0x41,"ecs_ossl.c",0x79);
    r_00 = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) {
      r_00 = (BIGNUM *)0x0;
      goto LAB_0010a3b0;
    }
  }
  else {
    r_00 = (BIGNUM *)EC_POINT_new(group);
    if (r_00 == (BIGNUM *)0x0) {
      iVar4 = 0x7e;
    }
    else {
      iVar2 = EC_GROUP_get_order(group,order,ctx);
      iVar4 = 0x83;
      if (iVar2 != 0) {
        do {
          do {
            iVar4 = BN_rand_range(pBVar1,order);
            if (iVar4 == 0) {
              ERR_put_error(0x2a,0x67,0x68,"ecs_ossl.c",0x8e);
              goto LAB_0010a3b0;
            }
          } while (pBVar1->top == 0);
          iVar4 = BN_add(pBVar1,pBVar1,order);
          if (iVar4 == 0) goto LAB_0010a3b0;
          iVar4 = BN_num_bits(pBVar1);
          iVar2 = BN_num_bits(order);
          if ((iVar4 <= iVar2) && (iVar4 = BN_add(pBVar1,pBVar1,order), iVar4 == 0))
          goto LAB_0010a3b0;
          iVar4 = EC_POINT_mul(group,(EC_POINT *)r_00,pBVar1,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
          if (iVar4 == 0) {
            iVar4 = 0x9e;
            goto LAB_0010a54a;
          }
          meth = EC_GROUP_method_of(group);
          iVar4 = EC_METHOD_get_field_type(meth);
          if (iVar4 == 0x196) {
            iVar4 = EC_POINT_get_affine_coordinates_GFp(group,(EC_POINT *)r_00,x,(BIGNUM *)0x0,ctx);
            if (iVar4 == 0) {
              iVar4 = 0xa6;
              goto LAB_0010a54a;
            }
          }
          else {
            iVar4 = EC_POINT_get_affine_coordinates_GF2m();
            if (iVar4 == 0) {
              iVar4 = 0xb0;
              goto LAB_0010a54a;
            }
          }
          iVar4 = BN_nnmod(r,x,order,ctx);
          if (iVar4 == 0) {
            iVar4 = 0xb7;
            goto LAB_0010a582;
          }
        } while (r->top == 0);
        pBVar3 = BN_mod_inverse(pBVar1,pBVar1,order,ctx);
        if (pBVar3 != (BIGNUM *)0x0) {
          if (*param_4 != (BIGNUM *)0x0) {
            BN_clear_free(*param_4);
          }
          if (*param_3 != (BIGNUM *)0x0) {
            BN_clear_free(*param_3);
          }
          *param_4 = r;
          *param_3 = pBVar1;
          pBVar1 = (BIGNUM *)0x1;
          goto joined_r0x0010a3c8;
        }
        iVar4 = 0xc0;
LAB_0010a582:
        ERR_put_error(0x2a,0x67,3,"ecs_ossl.c",iVar4);
        goto LAB_0010a3b0;
      }
    }
LAB_0010a54a:
    ERR_put_error(0x2a,0x67,0x10,"ecs_ossl.c",iVar4);
LAB_0010a3b0:
    BN_clear_free(pBVar1);
  }
  pBVar1 = r;
  if (r != (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)0x0;
    BN_clear_free(r);
  }
joined_r0x0010a3c8:
  if (param_2 == (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (r_00 != (BIGNUM *)0x0) {
    EC_POINT_free((EC_POINT *)r_00);
  }
  if (x != (BIGNUM *)0x0) {
    BN_clear_free(x);
  }
  return pBVar1;
}

