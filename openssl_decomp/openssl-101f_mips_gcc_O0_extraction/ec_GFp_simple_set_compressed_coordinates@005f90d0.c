
bool ec_GFp_simple_set_compressed_coordinates
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  undefined4 uVar2;
  BIGNUM *r;
  int iVar3;
  int iVar4;
  bool bVar6;
  uint uVar5;
  undefined4 uVar7;
  bool bVar8;
  code *pcVar9;
  BIGNUM *a;
  undefined4 local_2c;
  
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_5 == 0) {
      return false;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    local_2c = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    piVar1 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    r = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if ((r == (BIGNUM *)0x0) ||
       (iVar4 = (*(code *)PTR_BN_nnmod_006a9664)(uVar2,param_3,param_1 + 0x12,param_5),
       iVar3 = param_5, iVar4 == 0)) {
      bVar8 = false;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      goto LAB_005f9200;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    local_2c = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    piVar1 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    r = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if ((r == (BIGNUM *)0x0) ||
       (iVar3 = (*(code *)PTR_BN_nnmod_006a9664)(uVar2,param_3,param_1 + 0x12,param_5), iVar3 == 0))
    {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      return false;
    }
    iVar3 = 0;
  }
  bVar8 = param_4 != 0;
  a = (BIGNUM *)(param_1 + 0x12);
  if (*(int *)(*param_1 + 0x94) == 0) {
    iVar4 = (**(code **)(*param_1 + 0x88))(param_1,piVar1,param_3,param_5);
    if ((iVar4 != 0) &&
       (iVar4 = (**(code **)(*param_1 + 0x84))(param_1,local_2c,piVar1,param_3,param_5), iVar4 != 0)
       ) {
      iVar4 = param_1[0x27];
      goto LAB_005f92a8;
    }
LAB_005f91e8:
    bVar8 = false;
  }
  else {
    iVar4 = (*(code *)PTR_BN_mod_sqr_006aa7f0)(piVar1,param_3,a,param_5);
    if ((iVar4 == 0) ||
       (iVar4 = (*(code *)PTR_BN_mod_mul_006a9698)(local_2c,piVar1,param_3,a,param_5), iVar4 == 0))
    goto LAB_005f91e8;
    iVar4 = param_1[0x27];
LAB_005f92a8:
    if (iVar4 != 0) {
      iVar4 = (*(code *)PTR_BN_mod_lshift1_quick_006aa7f4)(piVar1,uVar2,a);
      if (iVar4 != 0) {
        iVar4 = (*(code *)PTR_BN_mod_add_quick_006aa7f8)(piVar1,piVar1,uVar2,a);
        pcVar9 = (code *)PTR_BN_mod_sub_quick_006aa800;
joined_r0x005f9538:
        if (iVar4 != 0) goto LAB_005f9300;
      }
      goto LAB_005f91e8;
    }
    pcVar9 = *(code **)(*param_1 + 0x94);
    if (pcVar9 != (code *)0x0) {
      iVar4 = (*pcVar9)(param_1,piVar1,param_1 + 0x1d,param_5);
      if (iVar4 != 0) {
        iVar4 = (*(code *)PTR_BN_mod_mul_006a9698)(piVar1,piVar1,uVar2,a,param_5);
        pcVar9 = (code *)PTR_BN_mod_add_quick_006aa7f8;
        goto joined_r0x005f9538;
      }
      goto LAB_005f91e8;
    }
    iVar4 = (**(code **)(*param_1 + 0x84))(param_1,piVar1,param_1 + 0x1d,uVar2,param_5);
    pcVar9 = (code *)PTR_BN_mod_add_quick_006aa7f8;
    if (iVar4 == 0) goto LAB_005f91e8;
LAB_005f9300:
    iVar4 = (*pcVar9)(local_2c,local_2c,piVar1,a);
    if (iVar4 == 0) goto LAB_005f91e8;
    if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
      piVar1 = param_1 + 0x22;
    }
    else {
      iVar4 = (**(code **)(*param_1 + 0x94))(param_1,piVar1,param_1 + 0x22,param_5);
      if (iVar4 == 0) goto LAB_005f91e8;
    }
    iVar4 = (*(code *)PTR_BN_mod_add_quick_006aa7f8)(local_2c,local_2c,piVar1,a);
    if (iVar4 == 0) goto LAB_005f91e8;
    iVar4 = (*(code *)PTR_BN_mod_sqrt_006aa7fc)(r,local_2c,a,param_5);
    if (iVar4 == 0) {
      uVar5 = (*(code *)PTR_ERR_peek_last_error_006a8508)();
      if ((uVar5 >> 0x18 == 3) && ((uVar5 & 0xfff) == 0x6f)) {
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
        uVar7 = 0x6e;
        uVar2 = 0x9c;
      }
      else {
        uVar7 = 3;
        uVar2 = 0x9f;
      }
LAB_005f93f0:
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa9,uVar7,"ecp_oct.c",uVar2);
      goto LAB_005f91e8;
    }
    if (r->top < 1) {
      if (bVar8) {
        if (r->top != 0) goto LAB_005f93b0;
        iVar4 = (*(code *)PTR_BN_kronecker_006aa804)(uVar2,a,param_5);
        if (iVar4 == -2) goto LAB_005f91e8;
        if (iVar4 == 1) {
          uVar7 = 0x6d;
          uVar2 = 0xad;
        }
        else {
          uVar7 = 0x6e;
          uVar2 = 0xb0;
        }
        goto LAB_005f93f0;
      }
LAB_005f93d4:
      bVar6 = false;
LAB_005f93d8:
      if (bVar6 != bVar8) {
        uVar7 = 0x44;
        uVar2 = 0xb7;
        goto LAB_005f93f0;
      }
    }
    else {
      if ((*r->d & 1) == 0) {
        if (bVar8) goto LAB_005f93b0;
        uVar5 = *r->d;
LAB_005f94f4:
        bVar6 = true;
        if ((uVar5 & 1) == 0) goto LAB_005f93d4;
        goto LAB_005f93d8;
      }
      if (!bVar8) {
LAB_005f93b0:
        iVar4 = BN_usub(r,a,r);
        if (iVar4 == 0) goto LAB_005f91e8;
        if (r->top < 1) goto LAB_005f93d4;
        uVar5 = *r->d;
        goto LAB_005f94f4;
      }
    }
    iVar4 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a9758)
                      (param_1,param_2,uVar2,r,param_5);
    bVar8 = iVar4 != 0;
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  param_5 = iVar3;
  if (iVar3 == 0) {
    return bVar8;
  }
LAB_005f9200:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_5);
  return bVar8;
}

