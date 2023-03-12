
undefined4 pub_decode_gost94(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined4 *puVar11;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = (undefined4 *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar11 = &local_28;
  iVar2 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)
                    (&local_24,&local_28,&local_20,&local_2c,param_2);
  if (iVar2 != 0) {
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(local_24);
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,uVar3,0);
    puVar11 = local_2c;
    iVar2 = decode_gost_algor_params(param_1,local_2c);
    if (iVar2 != 0) {
      piVar4 = (int *)(*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(0,&local_28,local_20);
      if (piVar4 != (int *)0x0) {
        iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(*piVar4,"gost_ameth.c",0x272);
        if (0 < *piVar4) {
          puVar10 = (undefined *)(iVar2 + *piVar4);
          iVar5 = 0;
          do {
            puVar10 = puVar10 + -1;
            puVar9 = (undefined *)(piVar4[2] + iVar5);
            iVar5 = iVar5 + 1;
            *puVar10 = *puVar9;
          } while (iVar5 < *piVar4);
        }
        iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
        puVar11 = (undefined4 *)*piVar4;
        uVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(iVar2,puVar11,0);
        puVar10 = PTR_ASN1_OCTET_STRING_free_006a9e1c;
        *(undefined4 *)(iVar5 + 0x18) = uVar3;
        (*(code *)puVar10)(piVar4);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
        uVar3 = 1;
        goto LAB_0061a510;
      }
      puVar11 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x86,0x41,"gost_ameth.c",0x26f);
    }
  }
  uVar3 = 0;
LAB_0061a510:
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar11);
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(iVar2);
  iVar7 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar11);
  iVar8 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(iVar2);
  if (iVar7 == iVar8) {
    if (iVar5 == 0) {
      ERR_GOST_error(0x75,0x73,"gost_ameth.c",0x21c);
      uVar3 = 0;
    }
    else {
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_DSA_new_006a8624)();
        uVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar11);
        (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2,uVar3,iVar6);
      }
      if (*(int *)(iVar6 + 0xc) != 0) {
        (*(code *)PTR_BN_free_006a811c)();
      }
      uVar3 = (*(code *)PTR_BN_dup_006a9100)(*(undefined4 *)(iVar5 + 0xc));
      *(undefined4 *)(iVar6 + 0xc) = uVar3;
      if (*(int *)(iVar6 + 0x10) != 0) {
        (*(code *)PTR_BN_free_006a811c)();
      }
      uVar3 = (*(code *)PTR_BN_dup_006a9100)(*(undefined4 *)(iVar5 + 0x10));
      *(undefined4 *)(iVar6 + 0x10) = uVar3;
      if (*(int *)(iVar6 + 0x14) != 0) {
        (*(code *)PTR_BN_free_006a811c)();
      }
      uVar3 = (*(code *)PTR_BN_dup_006a9100)(*(undefined4 *)(iVar5 + 0x14));
      *(undefined4 *)(iVar6 + 0x14) = uVar3;
      if (*(int *)(iVar6 + 0x1c) == 0) {
        return 1;
      }
      (*(code *)PTR_gost94_compute_public_006aa974)(iVar6);
      uVar3 = 1;
    }
    return uVar3;
  }
  ERR_GOST_error(0x75,0x69,"gost_ameth.c",0x216);
  return 0;
}

