
undefined4 ecdsa_sign_setup(int param_1,BN_CTX *param_2,BIGNUM **param_3,int *param_4)

{
  int iVar1;
  BIGNUM *r;
  int iVar2;
  BIGNUM *b;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  BIGNUM *pBVar7;
  BN_CTX *ctx;
  undefined4 uVar8;
  undefined4 uVar9;
  
  if ((param_1 == 0) || (iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(), iVar1 == 0)) {
    uVar9 = 0x43;
    uVar8 = 100;
LAB_005ff918:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x67,uVar9,"ecs_ossl.c",uVar8);
    return 0;
  }
  ctx = param_2;
  if ((param_2 == (BN_CTX *)0x0) &&
     (ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a794c)(), ctx == (BN_CTX *)0x0)) {
    uVar9 = 0x41;
    uVar8 = 0x6a;
    goto LAB_005ff918;
  }
  r = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
  iVar2 = (*(code *)PTR_BN_new_006a71b4)();
  b = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
  iVar3 = (*(code *)PTR_BN_new_006a71b4)();
  if (r == (BIGNUM *)0x0) {
    iVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x67,0x41,"ecs_ossl.c",0x75);
LAB_005ff6c8:
    if (iVar2 != 0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)(iVar2);
    }
    uVar8 = 0;
    if (param_2 == (BN_CTX *)0x0) {
LAB_005ff8f0:
      (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
    }
    if (b == (BIGNUM *)0x0) goto LAB_005ff6fc;
  }
  else {
    if (((iVar2 == 0) || (b == (BIGNUM *)0x0)) || (iVar3 == 0)) {
      iVar4 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x67,0x41,"ecs_ossl.c",0x75);
LAB_005ff6b8:
      (*(code *)PTR_BN_clear_free_006a7fa8)(r);
      goto LAB_005ff6c8;
    }
    iVar4 = (*(code *)PTR_EC_POINT_new_006a7fc0)(iVar1);
    if (iVar4 == 0) {
      uVar9 = 0x10;
      uVar8 = 0x79;
LAB_005ff6a4:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2a,0x67,uVar9,"ecs_ossl.c",uVar8);
      goto LAB_005ff6b8;
    }
    iVar5 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar1,b,ctx);
    if (iVar5 == 0) {
      uVar9 = 0x10;
      uVar8 = 0x7d;
      goto LAB_005ff6a4;
    }
    do {
      do {
        iVar5 = (*(code *)PTR_BN_rand_range_006a868c)(r,b);
        if (iVar5 == 0) {
          uVar9 = 0x68;
          uVar8 = 0x86;
          goto LAB_005ff6a4;
        }
      } while (r->top == 0);
      iVar5 = BN_add(r,r,b);
      if (iVar5 == 0) goto LAB_005ff6b8;
      iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(r);
      iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(b);
      if ((iVar5 <= iVar6) && (iVar5 = BN_add(r,r,b), iVar5 == 0)) goto LAB_005ff6b8;
      iVar5 = (*(code *)PTR_EC_POINT_mul_006a8648)(iVar1,iVar4,r,0,0,ctx);
      if (iVar5 == 0) {
        uVar9 = 0x10;
        uVar8 = 0x98;
        goto LAB_005ff6a4;
      }
      uVar8 = (*(code *)PTR_EC_GROUP_method_of_006a71b0)(iVar1);
      iVar5 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)(uVar8);
      if (iVar5 == 0x196) {
        iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)(iVar1,iVar4,iVar3,0,ctx)
        ;
        if (iVar5 == 0) {
          uVar9 = 0x10;
          uVar8 = 0x9f;
          goto LAB_005ff6a4;
        }
      }
      else {
        iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a8694)
                          (iVar1,iVar4,iVar3,0,ctx);
        if (iVar5 == 0) {
          uVar9 = 0x10;
          uVar8 = 0xa9;
          goto LAB_005ff6a4;
        }
      }
      iVar5 = (*(code *)PTR_BN_nnmod_006a8548)(iVar2,iVar3,b,ctx);
      if (iVar5 == 0) {
        uVar9 = 3;
        uVar8 = 0xaf;
        goto LAB_005ff6a4;
      }
    } while (*(int *)(iVar2 + 4) == 0);
    pBVar7 = BN_mod_inverse(r,r,b,ctx);
    if (pBVar7 == (BIGNUM *)0x0) {
      uVar9 = 3;
      uVar8 = 0xb7;
      goto LAB_005ff6a4;
    }
    if (*param_4 != 0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
    }
    if (*param_3 != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
    }
    *param_4 = iVar2;
    uVar8 = 1;
    *param_3 = r;
    if (param_2 == (BN_CTX *)0x0) goto LAB_005ff8f0;
  }
  (*(code *)PTR_BN_free_006a701c)(b);
LAB_005ff6fc:
  if (iVar4 != 0) {
    (*(code *)PTR_EC_POINT_free_006a7fac)(iVar4);
  }
  if (iVar3 == 0) {
    return uVar8;
  }
  (*(code *)PTR_BN_clear_free_006a7fa8)(iVar3);
  return uVar8;
}

