
undefined4 * fill_GOST2001_params(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  int *piVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int iStack_9c;
  undefined4 *puStack_90;
  undefined4 local_3c;
  char *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_3c = 0;
  local_38 = (char *)0x0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar2);
  local_3c = (*(code *)PTR_BN_CTX_get_006a9648)(uVar2);
  local_34 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar2);
  local_30 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar2);
  local_2c = (*(code *)PTR_BN_CTX_get_006a9648)(uVar2);
  local_28 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar2);
  local_38 = (char *)(*(code *)PTR_BN_CTX_get_006a9648)(uVar2);
  iVar3 = *(int *)PTR_R3410_2001_paramset_006aa704;
  piVar11 = (int *)PTR_R3410_2001_paramset_006aa704;
  while (iVar3 != 0) {
    if (param_2 == iVar3) {
      (*(code *)PTR_BN_hex2bn_006a81f0)(&local_3c,piVar11[3]);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&local_34,piVar11[1]);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&local_30,piVar11[2]);
      iVar13 = (*(code *)PTR_EC_GROUP_new_curve_GFp_006a975c)(local_3c,local_34,local_30,uVar2);
      uVar15 = (*(code *)PTR_EC_POINT_new_006a9140)(iVar13);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&local_2c,piVar11[5]);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&local_28,piVar11[6]);
      (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a9758)
                (iVar13,uVar15,local_2c,local_28,uVar2);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&local_38,piVar11[4]);
      pcVar10 = local_38;
      (*(code *)PTR_EC_GROUP_set_generator_006a9760)(iVar13,uVar15,local_38,0);
      puVar12 = (undefined4 *)0x1;
      (*(code *)PTR_EC_GROUP_set_curve_name_006a9750)(iVar13,*piVar11);
      iVar3 = iVar13;
      (*(code *)PTR_EC_KEY_set_group_006a82d0)(param_1);
      goto LAB_00613c04;
    }
    piVar11 = piVar11 + 7;
    iVar3 = *piVar11;
  }
  pcVar10 = "gost2001.c";
  iVar3 = 0x82;
  puVar12 = (undefined4 *)0x0;
  ERR_GOST_error(0x65,0x82,"gost2001.c",0x35);
  uVar15 = 0;
  iVar13 = 0;
LAB_00613c04:
  (*(code *)PTR_EC_POINT_free_006a9134)(uVar15);
  (*(code *)PTR_EC_GROUP_free_006a829c)(iVar13);
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar2);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar2);
  if (local_24 == *(int *)puVar1) {
    return puVar12;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar2 = (*(code *)PTR_hashsum2bn_006aa960)();
  uVar15 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar15);
  if (iVar3 != 0x20) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("gost2001.c",0x69,"dlen==32");
  }
  puStack_90 = (undefined4 *)(*(code *)PTR_DSA_SIG_new_006a9880)();
  if (puStack_90 == (undefined4 *)0x0) {
    uVar8 = 0;
    ERR_GOST_error(0x69,0x76,"gost2001.c",0x6d);
  }
  else {
    uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(pcVar10);
    uVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
    (*(code *)PTR_EC_GROUP_get_order_006a82ec)(uVar4,uVar5,uVar15);
    uVar6 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(pcVar10);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
    (*(code *)PTR_BN_div_006a967c)(0,iVar3,uVar2,uVar5,uVar15);
    if (*(int *)(iVar3 + 4) == 0) {
      (*(code *)PTR_BN_set_word_006a8820)(iVar3,1);
    }
    iVar17 = 0;
    iVar13 = 0;
    uVar7 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
    iVar16 = 0;
    iVar14 = 0;
    uVar8 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar4);
    iStack_9c = 0;
    do {
      do {
        iVar9 = (*(code *)PTR_BN_rand_range_006a97b0)(uVar7,uVar5);
        if (iVar9 == 0) {
          uVar5 = 0x89;
          uVar4 = 0x7d;
LAB_006140dc:
          ERR_GOST_error(0x69,uVar4,"gost2001.c",uVar5);
          (*(code *)PTR_DSA_SIG_free_006a987c)(puStack_90);
          puStack_90 = (undefined4 *)0x0;
          goto LAB_006140fc;
        }
        iVar9 = (*(code *)PTR_EC_POINT_mul_006a976c)(uVar4,uVar8,uVar7,0,0,uVar15);
        if (iVar9 == 0) {
          uVar5 = 0x90;
LAB_0061418c:
          uVar4 = 0x10;
          goto LAB_006140dc;
        }
        if (iVar13 == 0) {
          iVar13 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
        }
        iVar9 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                          (uVar4,uVar8,iVar13,0,uVar15);
        if (iVar9 == 0) {
          uVar5 = 0x98;
          goto LAB_0061418c;
        }
        if (iVar14 == 0) {
          iVar14 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
        }
        (*(code *)PTR_BN_nnmod_006a9664)(iVar14,iVar13,uVar5,uVar15);
      } while (*(int *)(iVar14 + 4) == 0);
      if (iStack_9c == 0) {
        iStack_9c = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
      }
      (*(code *)PTR_BN_mod_mul_006a9698)(iStack_9c,uVar6,iVar14,uVar5,uVar15);
      if (iVar17 == 0) {
        iVar17 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
      }
      (*(code *)PTR_BN_mod_mul_006a9698)(iVar17,uVar7,iVar3,uVar5,uVar15);
      if (iVar16 == 0) {
        iVar16 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
      }
      (*(code *)PTR_BN_mod_add_006aa61c)(iVar16,iStack_9c,iVar17,uVar5,uVar15);
    } while (*(int *)(iVar16 + 4) == 0);
    uVar4 = (*(code *)PTR_BN_dup_006a9100)(iVar16);
    puVar1 = PTR_BN_dup_006a9100;
    puStack_90[1] = uVar4;
    uVar4 = (*(code *)puVar1)(iVar14);
    *puStack_90 = uVar4;
  }
LAB_006140fc:
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar15);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar15);
  (*(code *)PTR_EC_POINT_free_006a9134)(uVar8);
  (*(code *)PTR_BN_free_006a811c)(uVar2);
  return puStack_90;
}

