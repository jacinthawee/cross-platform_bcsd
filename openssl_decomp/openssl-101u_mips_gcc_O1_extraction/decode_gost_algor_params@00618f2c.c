
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
  uint uStackY_cc;
  undefined4 *puStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  undefined *puStack_70;
  undefined4 uStack_6c;
  undefined4 *puStack_68;
  undefined4 *puStack_64;
  undefined4 local_2c;
  int local_28;
  undefined4 *local_24;
  undefined4 local_20;
  int local_1c;
  
  puStack_70 = PTR___stack_chk_guard_006a9ae8;
  local_28 = -1;
  local_2c = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_X509_ALGOR_get0_006a87a4)(&local_2c,&local_28,&local_24,param_2);
  if (local_28 == 0x10) {
    local_20 = local_24[2];
    unaff_s3 = (undefined4 *)(*(code *)PTR_OBJ_obj2nid_006a712c)(local_2c);
    puStack_68 = (undefined4 *)d2i_GOST_KEY_PARAMS(0,&local_20,*local_24);
    if (puStack_68 == (undefined4 *)0x0) {
      puVar14 = (undefined4 *)&DAT_00000064;
      ERR_GOST_error(99,100,"gost_ameth.c",0x71);
      uVar2 = 0;
    }
    else {
      puVar15 = (undefined4 *)(*(code *)PTR_OBJ_obj2nid_006a712c)(*puStack_68);
      GOST_KEY_PARAMS_free(puStack_68);
      puVar14 = unaff_s3;
      uVar2 = (*(code *)PTR_EVP_PKEY_set_type_006a8c44)(param_1);
      puStack_68 = puVar15;
      if (uVar2 == 0) {
        puVar14 = (undefined4 *)0x44;
        ERR_GOST_error(99,0x44,"gost_ameth.c",0x77);
      }
      else {
        if (unaff_s3 == (undefined4 *)0x32b) {
          unaff_s3 = (undefined4 *)(*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_1);
          pcVar16 = (code *)PTR_fill_GOST2001_params_006a9608;
          if (unaff_s3 == (undefined4 *)0x0) {
            unaff_s3 = (undefined4 *)(*(code *)PTR_EC_KEY_new_006a71a8)();
            puVar14 = (undefined4 *)0x32b;
            iVar11 = (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x32b,unaff_s3);
            pcVar16 = (code *)PTR_fill_GOST2001_params_006a9608;
joined_r0x0061911c:
            if (iVar11 == 0) {
              uVar2 = 0;
              goto LAB_00618fbc;
            }
          }
        }
        else {
          uVar2 = 1;
          if (unaff_s3 != (undefined4 *)0x32c) goto LAB_00618fbc;
          unaff_s3 = (undefined4 *)(*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_1);
          pcVar16 = (code *)PTR_fill_GOST94_params_006a960c;
          if (unaff_s3 == (undefined4 *)0x0) {
            unaff_s3 = (undefined4 *)(*(code *)PTR_DSA_new_006a7528)();
            puVar14 = (undefined4 *)0x32c;
            iVar11 = (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x32c,unaff_s3);
            pcVar16 = (code *)PTR_fill_GOST94_params_006a960c;
            goto joined_r0x0061911c;
          }
        }
        puVar14 = puVar15;
        iVar11 = (*pcVar16)(unaff_s3);
        uVar2 = (uint)(iVar11 != 0);
      }
    }
  }
  else {
    puVar14 = (undefined4 *)&DAT_00000063;
    ERR_GOST_error(99,99,"gost_ameth.c",0x68);
    uVar2 = 0;
    puStack_68 = unaff_s2;
  }
LAB_00618fbc:
  if (local_1c == *(int *)puStack_70) {
    return uVar2;
  }
  iVar11 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_84 = (undefined4 *)0x0;
  uStack_80 = 0;
  uStack_7c = 0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar15 = &uStack_80;
  uStack_6c = param_1;
  puStack_64 = unaff_s3;
  iVar3 = (*(code *)PTR_X509_PUBKEY_get0_param_006a87ac)
                    (&uStack_7c,&uStack_80,&uStack_78,&puStack_84,puVar14);
  if (iVar3 == 0) {
LAB_00619210:
    uVar2 = 0;
  }
  else {
    uVar10 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uStack_7c);
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar11,uVar10,0);
    puVar15 = puStack_84;
    iVar3 = decode_gost_algor_params(iVar11,puStack_84);
    if (iVar3 == 0) goto LAB_00619210;
    uVar10 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar11);
    uVar10 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar10);
    piVar4 = (int *)(*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(0,&uStack_80,uStack_78);
    if (piVar4 == (int *)0x0) {
      puVar15 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x85,0x41,"gost_ameth.c",0x2ad);
      goto LAB_00619210;
    }
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(*piVar4,"gost_ameth.c",0x2b0);
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
    (*(code *)PTR_ASN1_OCTET_STRING_free_006a8cfc)(piVar4);
    iVar7 = iVar7 / 2;
    uVar5 = (*(code *)PTR_getbnfrombuf_006a9810)(iVar3,iVar7);
    uVar6 = (*(code *)PTR_getbnfrombuf_006a9810)(iVar3 + iVar7,iVar7);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
    puVar14 = (undefined4 *)(*(code *)PTR_EC_POINT_new_006a7fc0)(uVar10);
    uVar2 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a8634)
                      (uVar10,puVar14,uVar6,uVar5,0);
    if (uVar2 == 0) {
      puVar15 = (undefined4 *)&SUB_00000010;
      ERR_GOST_error(0x85,0x10,"gost_ameth.c",700);
      (*(code *)PTR_EC_POINT_free_006a7fac)(puVar14);
      (*(code *)PTR_BN_free_006a701c)(uVar6);
      (*(code *)PTR_BN_free_006a701c)(uVar5);
    }
    else {
      (*(code *)PTR_BN_free_006a701c)(uVar6);
      (*(code *)PTR_BN_free_006a701c)(uVar5);
      uVar10 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar11);
      puVar15 = puVar14;
      uVar2 = (*(code *)PTR_EC_KEY_set_public_key_006a8068)(uVar10,puVar14);
      if (uVar2 == 0) {
        puVar15 = (undefined4 *)&SUB_00000010;
        ERR_GOST_error(0x85,0x10,"gost_ameth.c",0x2c5);
        (*(code *)PTR_EC_POINT_free_006a7fac)(puVar14);
      }
      else {
        (*(code *)PTR_EC_POINT_free_006a7fac)(puVar14);
        uVar2 = 1;
      }
    }
  }
  if (iStack_74 == *(int *)puVar1) {
    return uVar2;
  }
  iVar11 = iStack_74;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  iVar7 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar15);
  iVar8 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puVar15);
  iVar9 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(iVar11);
  if (iVar8 != iVar9) {
    ERR_GOST_error(0x74,0x69,"gost_ameth.c",0x225);
    return 0;
  }
  if (iVar7 == 0) {
    ERR_GOST_error(0x74,0x73,"gost_ameth.c",0x229);
    uVar2 = 0;
  }
  else {
    if (iVar3 == 0) {
      iVar3 = (*(code *)PTR_EC_KEY_new_006a71a8)();
      if (iVar3 == 0) {
        ERR_GOST_error(0x74,0x41,"gost_ameth.c",0x22f);
        return 0;
      }
      uVar10 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puVar15);
      uStackY_cc = (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar11,uVar10,iVar3);
      if (uStackY_cc == 0) {
        uVar10 = 0x233;
        goto LAB_006195d4;
      }
    }
    uVar10 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar7);
    uStackY_cc = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar3,uVar10);
    if (uStackY_cc == 0) {
      uVar10 = 0x238;
LAB_006195d4:
      ERR_GOST_error(0x74,0x44,"gost_ameth.c",uVar10);
      return uStackY_cc;
    }
    iVar11 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar3);
    if (iVar11 == 0) {
      uVar2 = 1;
    }
    else {
      gost2001_compute_public(iVar3);
      uVar2 = 1;
    }
  }
  return uVar2;
}

