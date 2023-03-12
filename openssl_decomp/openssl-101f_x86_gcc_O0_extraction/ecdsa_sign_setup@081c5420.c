
undefined4 ecdsa_sign_setup(EC_KEY *param_1,BN_CTX *param_2,BIGNUM **param_3,BIGNUM **param_4)

{
  EC_GROUP *group;
  BIGNUM *rnd;
  BIGNUM *r;
  BIGNUM *order;
  BIGNUM *x;
  int iVar1;
  int iVar2;
  EC_METHOD *meth;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  EC_POINT *r_00;
  BN_CTX *local_28;
  
  if ((param_1 == (EC_KEY *)0x0) || (group = EC_KEY_get0_group(param_1), group == (EC_GROUP *)0x0))
  {
    iVar2 = 100;
    iVar1 = 0x43;
LAB_081c559c:
    ERR_put_error(0x2a,0x67,iVar1,"ecs_ossl.c",iVar2);
    return 0;
  }
  local_28 = param_2;
  if ((param_2 == (BN_CTX *)0x0) && (local_28 = BN_CTX_new(), local_28 == (BN_CTX *)0x0)) {
    iVar2 = 0x6c;
    iVar1 = 0x41;
    goto LAB_081c559c;
  }
  rnd = BN_new();
  r = BN_new();
  order = BN_new();
  x = BN_new();
  if ((((rnd == (BIGNUM *)0x0) || (r == (BIGNUM *)0x0)) || (order == (BIGNUM *)0x0)) ||
     (x == (BIGNUM *)0x0)) {
    r_00 = (EC_POINT *)0x0;
    ERR_put_error(0x2a,0x67,0x41,"ecs_ossl.c",0x79);
    if (rnd != (BIGNUM *)0x0) goto LAB_081c54ad;
  }
  else {
    r_00 = EC_POINT_new(group);
    if (r_00 == (EC_POINT *)0x0) {
      iVar1 = 0x7e;
    }
    else {
      iVar1 = EC_GROUP_get_order(group,order,local_28);
      if (iVar1 != 0) {
        do {
          do {
            iVar1 = BN_rand_range(rnd,order);
            if (iVar1 == 0) {
              ERR_put_error(0x2a,0x67,0x68,"ecs_ossl.c",0x8e);
              goto LAB_081c54ad;
            }
          } while (rnd->top == 0);
          iVar1 = BN_add(rnd,rnd,order);
          if (iVar1 == 0) goto LAB_081c54ad;
          iVar1 = BN_num_bits(rnd);
          iVar2 = BN_num_bits(order);
          if ((iVar1 <= iVar2) && (iVar1 = BN_add(rnd,rnd,order), iVar1 == 0)) goto LAB_081c54ad;
          iVar1 = EC_POINT_mul(group,r_00,rnd,(EC_POINT *)0x0,(BIGNUM *)0x0,local_28);
          if (iVar1 == 0) {
            iVar1 = 0x9e;
            goto LAB_081c5740;
          }
          meth = EC_GROUP_method_of(group);
          iVar1 = EC_METHOD_get_field_type(meth);
          if (iVar1 == 0x196) {
            iVar1 = EC_POINT_get_affine_coordinates_GFp(group,r_00,x,(BIGNUM *)0x0,local_28);
            if (iVar1 == 0) {
              iVar1 = 0xa6;
              goto LAB_081c5740;
            }
          }
          else {
            iVar1 = EC_POINT_get_affine_coordinates_GF2m(group,r_00,x,0,local_28);
            if (iVar1 == 0) {
              iVar1 = 0xb0;
              goto LAB_081c5740;
            }
          }
          iVar1 = BN_nnmod(r,x,order,local_28);
          if (iVar1 == 0) {
            iVar1 = 0xb7;
            goto LAB_081c57ab;
          }
        } while (r->top == 0);
        pBVar3 = BN_mod_inverse(rnd,rnd,order,local_28);
        if (pBVar3 != (BIGNUM *)0x0) {
          if (*param_4 != (BIGNUM *)0x0) {
            BN_clear_free(*param_4);
          }
          if (*param_3 != (BIGNUM *)0x0) {
            BN_clear_free(*param_3);
          }
          *param_4 = r;
          *param_3 = rnd;
          uVar4 = 1;
          goto LAB_081c54cf;
        }
        iVar1 = 0xc0;
LAB_081c57ab:
        ERR_put_error(0x2a,0x67,3,"ecs_ossl.c",iVar1);
        goto LAB_081c54ad;
      }
      iVar1 = 0x83;
    }
LAB_081c5740:
    ERR_put_error(0x2a,0x67,0x10,"ecs_ossl.c",iVar1);
LAB_081c54ad:
    BN_clear_free(rnd);
  }
  uVar4 = 0;
  if (r != (BIGNUM *)0x0) {
    BN_clear_free(r);
  }
LAB_081c54cf:
  if (param_2 == (BN_CTX *)0x0) {
    BN_CTX_free(local_28);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (r_00 != (EC_POINT *)0x0) {
    EC_POINT_free(r_00);
  }
  if (x != (BIGNUM *)0x0) {
    BN_clear_free(x);
  }
  return uVar4;
}

