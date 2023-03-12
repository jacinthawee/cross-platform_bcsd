
uint decode_gost_algor_params(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined *puVar12;
  undefined *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *unaff_s2;
  undefined4 *unaff_s3;
  code *pcVar16;
  undefined4 *puStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  int iStack_6c;
  undefined *puStack_68;
  undefined4 uStack_64;
  undefined4 *puStack_60;
  undefined4 *puStack_5c;
  undefined4 local_2c;
  int local_28;
  undefined4 *local_24;
  undefined4 local_20;
  int local_1c;
  
  puStack_68 = PTR___stack_chk_guard_006aabf0;
  local_28 = -1;
  local_2c = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_X509_ALGOR_get0_006a98c4)(&local_2c,&local_28,&local_24,param_2);
  if (local_28 == 0x10) {
    local_20 = local_24[2];
    unaff_s3 = (undefined4 *)(*(code *)PTR_OBJ_obj2nid_006a822c)(local_2c);
    puStack_60 = (undefined4 *)d2i_GOST_KEY_PARAMS(0,&local_20,*local_24);
    if (puStack_60 == (undefined4 *)0x0) {
      puVar14 = (undefined4 *)&DAT_00000064;
      ERR_GOST_error(99,100,"gost_ameth.c",0x75);
      uVar2 = 0;
    }
    else {
      puVar15 = (undefined4 *)(*(code *)PTR_OBJ_obj2nid_006a822c)(*puStack_60);
      GOST_KEY_PARAMS_free(puStack_60);
      puVar14 = unaff_s3;
      (*(code *)PTR_EVP_PKEY_set_type_006a9d60)(param_1);
      puStack_60 = puVar15;
      if (unaff_s3 == (undefined4 *)0x32b) {
        unaff_s3 = (undefined4 *)(*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
        pcVar16 = (code *)PTR_fill_GOST2001_params_006aa714;
        if (unaff_s3 == (undefined4 *)0x0) {
          unaff_s3 = (undefined4 *)(*(code *)PTR_EC_KEY_new_006a82a8)();
          puVar14 = (undefined4 *)0x32b;
          iVar11 = (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x32b,unaff_s3);
          pcVar16 = (code *)PTR_fill_GOST2001_params_006aa714;
          if (iVar11 == 0) {
            uVar2 = 0;
            goto LAB_00619b3c;
          }
        }
      }
      else {
        uVar2 = 1;
        if (unaff_s3 != (undefined4 *)0x32c) goto LAB_00619b3c;
        unaff_s3 = (undefined4 *)(*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
        pcVar16 = (code *)PTR_fill_GOST94_params_006aa718;
        if (unaff_s3 == (undefined4 *)0x0) {
          unaff_s3 = (undefined4 *)(*(code *)PTR_DSA_new_006a8624)();
          puVar14 = (undefined4 *)0x32c;
          iVar11 = (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x32c,unaff_s3);
          pcVar16 = (code *)PTR_fill_GOST94_params_006aa718;
          if (iVar11 == 0) {
            uVar2 = 0;
            goto LAB_00619b3c;
          }
        }
      }
      puVar14 = puVar15;
      iVar11 = (*pcVar16)(unaff_s3);
      uVar2 = (uint)(iVar11 != 0);
    }
  }
  else {
    puVar14 = (undefined4 *)0x63;
    ERR_GOST_error(99,99,"gost_ameth.c",0x6b);
    uVar2 = 0;
    puStack_60 = unaff_s2;
  }
LAB_00619b3c:
  if (local_1c == *(int *)puStack_68) {
    return uVar2;
  }
  iVar11 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puStack_7c = (undefined4 *)0x0;
  uStack_78 = 0;
  uStack_74 = 0;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar15 = &uStack_78;
  uStack_64 = param_1;
  puStack_5c = unaff_s3;
  iVar3 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)
                    (&uStack_74,&uStack_78,&uStack_70,&puStack_7c,puVar14);
  if (iVar3 != 0) {
    uVar10 = (*(code *)PTR_OBJ_obj2nid_006a822c)(uStack_74);
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar11,uVar10,0);
    puVar15 = puStack_7c;
    iVar3 = decode_gost_algor_params(iVar11,puStack_7c);
    if (iVar3 != 0) {
      uVar10 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(iVar11);
      uVar10 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar10);
      piVar4 = (int *)(*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(0,&uStack_78,uStack_70);
      if (piVar4 != (int *)0x0) {
        iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(*piVar4,"gost_ameth.c",0x2b9);
        iVar7 = *piVar4;
        if (0 < iVar7) {
          puVar13 = (undefined *)(iVar3 + iVar7);
          iVar8 = 0;
          do {
            puVar13 = puVar13 + -1;
            puVar12 = (undefined *)(piVar4[2] + iVar8);
            iVar8 = iVar8 + 1;
            *puVar13 = *puVar12;
            iVar7 = *piVar4;
          } while (iVar8 < iVar7);
        }
        (*(code *)PTR_ASN1_OCTET_STRING_free_006a9e1c)(piVar4);
        iVar7 = iVar7 / 2;
        uVar5 = (*(code *)PTR_getbnfrombuf_006aa920)(iVar3,iVar7);
        uVar6 = (*(code *)PTR_getbnfrombuf_006aa920)(iVar3 + iVar7,iVar7);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
        puVar14 = (undefined4 *)(*(code *)PTR_EC_POINT_new_006a9140)(uVar10);
        uVar2 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a9758)
                          (uVar10,puVar14,uVar6,uVar5,0);
        if (uVar2 == 0) {
          puVar15 = (undefined4 *)&SUB_00000010;
          ERR_GOST_error(0x85,0x10,"gost_ameth.c",0x2c9);
          (*(code *)PTR_EC_POINT_free_006a9134)(puVar14);
          (*(code *)PTR_BN_free_006a811c)(uVar6);
          (*(code *)PTR_BN_free_006a811c)(uVar5);
        }
        else {
          (*(code *)PTR_BN_free_006a811c)(uVar6);
          (*(code *)PTR_BN_free_006a811c)(uVar5);
          uVar10 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(iVar11);
          puVar15 = puVar14;
          uVar2 = (*(code *)PTR_EC_KEY_set_public_key_006a91b0)(uVar10,puVar14);
          if (uVar2 == 0) {
            puVar15 = (undefined4 *)&SUB_00000010;
            ERR_GOST_error(0x85,0x10,"gost_ameth.c",0x2d4);
            (*(code *)PTR_EC_POINT_free_006a9134)(puVar14);
          }
          else {
            (*(code *)PTR_EC_POINT_free_006a9134)(puVar14);
            uVar2 = 1;
          }
        }
        goto LAB_00619d64;
      }
      puVar15 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x85,0x41,"gost_ameth.c",0x2b6);
    }
  }
  uVar2 = 0;
LAB_00619d64:
  if (iStack_6c == *(int *)puVar1) {
    return uVar2;
  }
  iVar11 = iStack_6c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  iVar7 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar15);
  iVar8 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar15);
  iVar9 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(iVar11);
  if (iVar8 != iVar9) {
    ERR_GOST_error(0x74,0x69,"gost_ameth.c",0x234);
    return 0;
  }
  if (iVar7 == 0) {
    ERR_GOST_error(0x74,0x73,"gost_ameth.c",0x23a);
    uVar2 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = (*(code *)PTR_EC_KEY_new_006a82a8)();
      uVar10 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar15);
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar11,uVar10,iVar3);
    }
    uVar10 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(iVar7);
    (*(code *)PTR_EC_KEY_set_group_006a82d0)(iVar3,uVar10);
    iVar11 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar3);
    if (iVar11 == 0) {
      return 1;
    }
    gost2001_compute_public(iVar3);
    uVar2 = 1;
  }
  return uVar2;
}

