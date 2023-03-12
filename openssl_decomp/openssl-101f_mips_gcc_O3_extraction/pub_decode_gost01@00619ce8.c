
int pub_decode_gost01(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined *puVar12;
  undefined *puVar13;
  undefined4 *puVar14;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_34 = (undefined4 *)0x0;
  local_30 = 0;
  local_2c = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar14 = &local_30;
  iVar2 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)
                    (&local_2c,&local_30,&local_28,&local_34,param_2);
  if (iVar2 != 0) {
    uVar11 = (*(code *)PTR_OBJ_obj2nid_006a822c)(local_2c);
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,uVar11,0);
    puVar14 = local_34;
    iVar2 = decode_gost_algor_params(param_1,local_34);
    if (iVar2 != 0) {
      uVar11 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
      uVar11 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar11);
      piVar3 = (int *)(*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(0,&local_30,local_28);
      if (piVar3 != (int *)0x0) {
        iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(*piVar3,"gost_ameth.c",0x2b9);
        iVar7 = *piVar3;
        if (0 < iVar7) {
          puVar13 = (undefined *)(iVar2 + iVar7);
          iVar8 = 0;
          do {
            puVar13 = puVar13 + -1;
            puVar12 = (undefined *)(piVar3[2] + iVar8);
            iVar8 = iVar8 + 1;
            *puVar13 = *puVar12;
            iVar7 = *piVar3;
          } while (iVar8 < iVar7);
        }
        (*(code *)PTR_ASN1_OCTET_STRING_free_006a9e1c)(piVar3);
        iVar7 = iVar7 / 2;
        uVar4 = (*(code *)PTR_getbnfrombuf_006aa920)(iVar2,iVar7);
        uVar5 = (*(code *)PTR_getbnfrombuf_006aa920)(iVar2 + iVar7,iVar7);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
        puVar6 = (undefined4 *)(*(code *)PTR_EC_POINT_new_006a9140)(uVar11);
        iVar2 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a9758)
                          (uVar11,puVar6,uVar5,uVar4,0);
        if (iVar2 == 0) {
          puVar14 = (undefined4 *)&SUB_00000010;
          ERR_GOST_error(0x85,0x10,"gost_ameth.c",0x2c9);
          (*(code *)PTR_EC_POINT_free_006a9134)(puVar6);
          (*(code *)PTR_BN_free_006a811c)(uVar5);
          (*(code *)PTR_BN_free_006a811c)(uVar4);
        }
        else {
          (*(code *)PTR_BN_free_006a811c)(uVar5);
          (*(code *)PTR_BN_free_006a811c)(uVar4);
          uVar11 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
          puVar14 = puVar6;
          iVar2 = (*(code *)PTR_EC_KEY_set_public_key_006a91b0)(uVar11,puVar6);
          if (iVar2 == 0) {
            puVar14 = (undefined4 *)&SUB_00000010;
            ERR_GOST_error(0x85,0x10,"gost_ameth.c",0x2d4);
            (*(code *)PTR_EC_POINT_free_006a9134)(puVar6);
          }
          else {
            (*(code *)PTR_EC_POINT_free_006a9134)(puVar6);
            iVar2 = 1;
          }
        }
        goto LAB_00619d64;
      }
      puVar14 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x85,0x41,"gost_ameth.c",0x2b6);
    }
  }
  iVar2 = 0;
LAB_00619d64:
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar7 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  iVar8 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar14);
  iVar9 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar14);
  iVar10 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(iVar2);
  if (iVar9 == iVar10) {
    if (iVar8 == 0) {
      ERR_GOST_error(0x74,0x73,"gost_ameth.c",0x23a);
      iVar2 = 0;
    }
    else {
      if (iVar7 == 0) {
        iVar7 = (*(code *)PTR_EC_KEY_new_006a82a8)();
        uVar11 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar14);
        (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2,uVar11,iVar7);
      }
      uVar11 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(iVar8);
      (*(code *)PTR_EC_KEY_set_group_006a82d0)(iVar7,uVar11);
      iVar2 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar7);
      if (iVar2 == 0) {
        return 1;
      }
      gost2001_compute_public(iVar7);
      iVar2 = 1;
    }
    return iVar2;
  }
  ERR_GOST_error(0x74,0x69,"gost_ameth.c",0x234);
  return 0;
}

