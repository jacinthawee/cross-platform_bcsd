
undefined4 gost2001_do_verify(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  
  uVar1 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  uVar2 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(param_4);
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar1);
  uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar1);
  iVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar1);
  uVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar1);
  uVar6 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar1);
  uVar7 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar1);
  uVar8 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar1);
  uVar9 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar1);
  uVar10 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar1);
  (*(code *)PTR_EC_GROUP_get_order_006a82ec)(uVar2,uVar3,uVar1);
  uVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(param_4);
  if ((*(int *)(param_3[1] + 4) != 0) && (*(int *)(*param_3 + 4) != 0)) {
    iVar12 = (*(code *)PTR_BN_cmp_006a8a4c)(param_3[1],uVar3);
    if (iVar12 < 1) {
      iVar12 = (*(code *)PTR_BN_cmp_006a8a4c)(*param_3,uVar3);
      if (iVar12 < 1) {
        uVar13 = (*(code *)PTR_hashsum2bn_006aa960)(param_1);
        (*(code *)PTR_BN_div_006a967c)(0,iVar4,uVar13,uVar3,uVar1);
        if (*(int *)(iVar4 + 4) == 0) {
          (*(code *)PTR_BN_set_word_006a8820)(iVar4,1);
        }
        uVar10 = (*(code *)PTR_BN_mod_inverse_006a9714)(uVar10,iVar4,uVar3,uVar1);
        (*(code *)PTR_BN_mod_mul_006a9698)(uVar5,param_3[1],uVar10,uVar3,uVar1);
        (*(code *)PTR_BN_sub_006a96cc)(uVar7,uVar3,*param_3);
        (*(code *)PTR_BN_mod_mul_006a9698)(uVar6,uVar7,uVar10,uVar3,uVar1);
        uVar7 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar2);
        iVar4 = (*(code *)PTR_EC_POINT_mul_006a976c)(uVar2,uVar7,uVar5,uVar11,uVar6,uVar1);
        if (iVar4 == 0) {
          uVar2 = 0xf0;
        }
        else {
          iVar4 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                            (uVar2,uVar7,uVar8,0,uVar1);
          if (iVar4 != 0) {
            (*(code *)PTR_BN_div_006a967c)(0,uVar9,uVar8,uVar3,uVar1);
            iVar4 = (*(code *)PTR_BN_cmp_006a8a4c)(uVar9,*param_3);
            if (iVar4 == 0) {
              uVar3 = 1;
            }
            else {
              uVar3 = 0;
              ERR_GOST_error(0x6a,0x7e,"gost2001.c",0x102);
            }
            goto LAB_0061435c;
          }
          uVar2 = 0xf5;
        }
        uVar3 = 0;
        ERR_GOST_error(0x6a,0x10,"gost2001.c",uVar2);
        goto LAB_0061435c;
      }
    }
  }
  uVar3 = 0;
  ERR_GOST_error(0x6a,0x7f,"gost2001.c",0xd3);
  uVar7 = 0;
  uVar13 = 0;
LAB_0061435c:
  (*(code *)PTR_EC_POINT_free_006a9134)(uVar7);
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar1);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar1);
  (*(code *)PTR_BN_free_006a811c)(uVar13);
  return uVar3;
}

