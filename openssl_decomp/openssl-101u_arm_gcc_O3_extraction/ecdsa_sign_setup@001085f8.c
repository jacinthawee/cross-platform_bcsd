
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
    ERR_put_error(0x2a,0x67,0x41,"ecs_ossl.c",0x6a);
    return (BIGNUM *)0x0;
  }
  pBVar1 = BN_new();
  r = BN_new();
  order = BN_new();
  x = BN_new();
  if ((r == (BIGNUM *)0x0 || pBVar1 == (BIGNUM *)0x0) ||
     (x == (BIGNUM *)0x0 || order == (BIGNUM *)0x0)) {
    ERR_put_error(0x2a,0x67,0x41,"ecs_ossl.c",0x75);
    r_00 = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) {
      r_00 = (BIGNUM *)0x0;
      goto LAB_00108668;
    }
  }
  else {
    r_00 = (BIGNUM *)EC_POINT_new(group);
    if (r_00 == (BIGNUM *)0x0) {
      iVar4 = 0x79;
    }
    else {
      iVar2 = EC_GROUP_get_order(group,order,ctx);
      iVar4 = 0x7d;
      if (iVar2 != 0) {
        do {
          do {
            iVar4 = BN_rand_range(pBVar1,order);
            if (iVar4 == 0) {
              ERR_put_error(0x2a,0x67,0x68,"ecs_ossl.c",0x86);
              goto LAB_00108668;
            }
          } while (pBVar1->top == 0);
          iVar4 = BN_add(pBVar1,pBVar1,order);
          if (iVar4 == 0) goto LAB_00108668;
          iVar4 = BN_num_bits(pBVar1);
          iVar2 = BN_num_bits(order);
          if ((iVar4 <= iVar2) && (iVar4 = BN_add(pBVar1,pBVar1,order), iVar4 == 0))
          goto LAB_00108668;
          iVar4 = EC_POINT_mul(group,(EC_POINT *)r_00,pBVar1,(EC_POINT *)0x0,(BIGNUM *)0x0,ctx);
          if (iVar4 == 0) {
            iVar4 = 0x98;
            goto LAB_00108802;
          }
          meth = EC_GROUP_method_of(group);
          iVar4 = EC_METHOD_get_field_type(meth);
          if (iVar4 == 0x196) {
            iVar4 = EC_POINT_get_affine_coordinates_GFp(group,(EC_POINT *)r_00,x,(BIGNUM *)0x0,ctx);
            if (iVar4 == 0) {
              iVar4 = 0x9f;
              goto LAB_00108802;
            }
          }
          else {
            iVar4 = EC_POINT_get_affine_coordinates_GF2m();
            if (iVar4 == 0) {
              iVar4 = 0xa9;
              goto LAB_00108802;
            }
          }
          iVar4 = BN_nnmod(r,x,order,ctx);
          if (iVar4 == 0) {
            iVar4 = 0xaf;
            goto LAB_0010883a;
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
          goto joined_r0x00108680;
        }
        iVar4 = 0xb7;
LAB_0010883a:
        ERR_put_error(0x2a,0x67,3,"ecs_ossl.c",iVar4);
        goto LAB_00108668;
      }
    }
LAB_00108802:
    ERR_put_error(0x2a,0x67,0x10,"ecs_ossl.c",iVar4);
LAB_00108668:
    BN_clear_free(pBVar1);
  }
  pBVar1 = r;
  if (r != (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)0x0;
    BN_clear_free(r);
  }
joined_r0x00108680:
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

