
undefined4 * gost2001_do_sign(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int local_3c;
  undefined4 *local_30;
  
  uVar2 = (*(code *)PTR_hashsum2bn_006aa960)();
  uVar3 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar3);
  if (param_2 != 0x20) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("gost2001.c",0x69,"dlen==32");
  }
  local_30 = (undefined4 *)(*(code *)PTR_DSA_SIG_new_006a9880)();
  if (local_30 == (undefined4 *)0x0) {
    uVar9 = 0;
    ERR_GOST_error(0x69,0x76,"gost2001.c",0x6d);
  }
  else {
    uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(param_3);
    uVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar3);
    (*(code *)PTR_EC_GROUP_get_order_006a82ec)(uVar4,uVar5,uVar3);
    uVar6 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(param_3);
    iVar7 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar3);
    (*(code *)PTR_BN_div_006a967c)(0,iVar7,uVar2,uVar5,uVar3);
    if (*(int *)(iVar7 + 4) == 0) {
      (*(code *)PTR_BN_set_word_006a8820)(iVar7,1);
    }
    iVar14 = 0;
    iVar12 = 0;
    uVar8 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar3);
    iVar13 = 0;
    iVar11 = 0;
    uVar9 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar4);
    local_3c = 0;
    do {
      do {
        iVar10 = (*(code *)PTR_BN_rand_range_006a97b0)(uVar8,uVar5);
        if (iVar10 == 0) {
          uVar5 = 0x89;
          uVar4 = 0x7d;
LAB_006140dc:
          ERR_GOST_error(0x69,uVar4,"gost2001.c",uVar5);
          (*(code *)PTR_DSA_SIG_free_006a987c)(local_30);
          local_30 = (undefined4 *)0x0;
          goto LAB_006140fc;
        }
        iVar10 = (*(code *)PTR_EC_POINT_mul_006a976c)(uVar4,uVar9,uVar8,0,0,uVar3);
        if (iVar10 == 0) {
          uVar5 = 0x90;
LAB_0061418c:
          uVar4 = 0x10;
          goto LAB_006140dc;
        }
        if (iVar12 == 0) {
          iVar12 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar3);
        }
        iVar10 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                           (uVar4,uVar9,iVar12,0,uVar3);
        if (iVar10 == 0) {
          uVar5 = 0x98;
          goto LAB_0061418c;
        }
        if (iVar11 == 0) {
          iVar11 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar3);
        }
        (*(code *)PTR_BN_nnmod_006a9664)(iVar11,iVar12,uVar5,uVar3);
      } while (*(int *)(iVar11 + 4) == 0);
      if (local_3c == 0) {
        local_3c = (*(code *)PTR_BN_CTX_get_006a9648)(uVar3);
      }
      (*(code *)PTR_BN_mod_mul_006a9698)(local_3c,uVar6,iVar11,uVar5,uVar3);
      if (iVar14 == 0) {
        iVar14 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar3);
      }
      (*(code *)PTR_BN_mod_mul_006a9698)(iVar14,uVar8,iVar7,uVar5,uVar3);
      if (iVar13 == 0) {
        iVar13 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar3);
      }
      (*(code *)PTR_BN_mod_add_006aa61c)(iVar13,local_3c,iVar14,uVar5,uVar3);
    } while (*(int *)(iVar13 + 4) == 0);
    uVar4 = (*(code *)PTR_BN_dup_006a9100)(iVar13);
    puVar1 = PTR_BN_dup_006a9100;
    local_30[1] = uVar4;
    uVar4 = (*(code *)puVar1)(iVar11);
    *local_30 = uVar4;
  }
LAB_006140fc:
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar3);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar3);
  (*(code *)PTR_EC_POINT_free_006a9134)(uVar9);
  (*(code *)PTR_BN_free_006a811c)(uVar2);
  return local_30;
}

