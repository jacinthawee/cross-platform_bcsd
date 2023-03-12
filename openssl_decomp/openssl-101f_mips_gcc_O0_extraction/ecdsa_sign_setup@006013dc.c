
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
  
  if ((param_1 == 0) || (iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(), iVar1 == 0)) {
    uVar9 = 0x43;
    uVar8 = 100;
LAB_00601788:
    (*(code *)PTR_ERR_put_error_006a9030)(0x2a,0x67,uVar9,"ecs_ossl.c",uVar8);
    return 0;
  }
  ctx = param_2;
  if ((param_2 == (BN_CTX *)0x0) &&
     (ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a8a38)(), ctx == (BN_CTX *)0x0)) {
    uVar9 = 0x41;
    uVar8 = 0x6c;
    goto LAB_00601788;
  }
  r = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
  iVar2 = (*(code *)PTR_BN_new_006a82b4)();
  b = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
  iVar3 = (*(code *)PTR_BN_new_006a82b4)();
  if (r == (BIGNUM *)0x0) {
    iVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2a,0x67,0x41,"ecs_ossl.c",0x79);
LAB_00601538:
    if (iVar2 != 0) {
      (*(code *)PTR_BN_clear_free_006a9130)(iVar2);
    }
    uVar8 = 0;
    if (param_2 == (BN_CTX *)0x0) {
LAB_00601760:
      (*(code *)PTR_BN_CTX_free_006a8a40)(ctx);
    }
    if (b == (BIGNUM *)0x0) goto LAB_0060156c;
  }
  else {
    if (((iVar2 == 0) || (b == (BIGNUM *)0x0)) || (iVar3 == 0)) {
      iVar4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2a,0x67,0x41,"ecs_ossl.c",0x79);
LAB_00601528:
      (*(code *)PTR_BN_clear_free_006a9130)(r);
      goto LAB_00601538;
    }
    iVar4 = (*(code *)PTR_EC_POINT_new_006a9140)(iVar1);
    if (iVar4 == 0) {
      uVar9 = 0x10;
      uVar8 = 0x7e;
LAB_00601514:
      (*(code *)PTR_ERR_put_error_006a9030)(0x2a,0x67,uVar9,"ecs_ossl.c",uVar8);
      goto LAB_00601528;
    }
    iVar5 = (*(code *)PTR_EC_GROUP_get_order_006a82ec)(iVar1,b,ctx);
    if (iVar5 == 0) {
      uVar9 = 0x10;
      uVar8 = 0x83;
      goto LAB_00601514;
    }
    do {
      do {
        iVar5 = (*(code *)PTR_BN_rand_range_006a97b0)(r,b);
        if (iVar5 == 0) {
          uVar9 = 0x68;
          uVar8 = 0x8e;
          goto LAB_00601514;
        }
      } while (r->top == 0);
      iVar5 = BN_add(r,r,b);
      if (iVar5 == 0) goto LAB_00601528;
      iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(r);
      iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(b);
      if ((iVar5 <= iVar6) && (iVar5 = BN_add(r,r,b), iVar5 == 0)) goto LAB_00601528;
      iVar5 = (*(code *)PTR_EC_POINT_mul_006a976c)(iVar1,iVar4,r,0,0,ctx);
      if (iVar5 == 0) {
        uVar9 = 0x10;
        uVar8 = 0x9e;
        goto LAB_00601514;
      }
      uVar8 = (*(code *)PTR_EC_GROUP_method_of_006a82b0)(iVar1);
      iVar5 = (*(code *)PTR_EC_METHOD_get_field_type_006a82b8)(uVar8);
      if (iVar5 == 0x196) {
        iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)(iVar1,iVar4,iVar3,0,ctx)
        ;
        if (iVar5 == 0) {
          uVar9 = 0x10;
          uVar8 = 0xa6;
          goto LAB_00601514;
        }
      }
      else {
        iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a97b8)
                          (iVar1,iVar4,iVar3,0,ctx);
        if (iVar5 == 0) {
          uVar9 = 0x10;
          uVar8 = 0xb0;
          goto LAB_00601514;
        }
      }
      iVar5 = (*(code *)PTR_BN_nnmod_006a9664)(iVar2,iVar3,b,ctx);
      if (iVar5 == 0) {
        uVar9 = 3;
        uVar8 = 0xb7;
        goto LAB_00601514;
      }
    } while (*(int *)(iVar2 + 4) == 0);
    pBVar7 = BN_mod_inverse(r,r,b,ctx);
    if (pBVar7 == (BIGNUM *)0x0) {
      uVar9 = 3;
      uVar8 = 0xc0;
      goto LAB_00601514;
    }
    if (*param_4 != 0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
    }
    if (*param_3 != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_clear_free_006a9130)();
    }
    *param_4 = iVar2;
    uVar8 = 1;
    *param_3 = r;
    if (param_2 == (BN_CTX *)0x0) goto LAB_00601760;
  }
  (*(code *)PTR_BN_free_006a811c)(b);
LAB_0060156c:
  if (iVar4 != 0) {
    (*(code *)PTR_EC_POINT_free_006a9134)(iVar4);
  }
  if (iVar3 == 0) {
    return uVar8;
  }
  (*(code *)PTR_BN_clear_free_006a9130)(iVar3);
  return uVar8;
}

