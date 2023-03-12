
int eckey_type2param(int param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int unaff_s0;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  int iStack_4c;
  undefined *puStack_48;
  undefined4 *puStack_44;
  undefined4 local_18;
  int local_14;
  
  puStack_48 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_1 == 0x10) {
    local_18 = param_2[2];
    puVar7 = &local_18;
    iVar3 = (*(code *)PTR_d2i_ECParameters_006aa7d8)(0,puVar7,*param_2);
    if (iVar3 == 0) {
      uVar9 = 0x8e;
      goto LAB_005f74ec;
    }
  }
  else {
    if (param_1 == 6) {
      puVar7 = param_2;
      unaff_s0 = (*(code *)PTR_EC_KEY_new_006a82a8)();
      if (unaff_s0 != 0) {
        uVar9 = (*(code *)PTR_OBJ_obj2nid_006a822c)(param_2);
        param_2 = (undefined4 *)(*(code *)PTR_EC_GROUP_new_by_curve_name_006a8284)(uVar9);
        if (param_2 != (undefined4 *)0x0) {
          (*(code *)PTR_EC_GROUP_set_asn1_flag_006a8288)(param_2,1);
          puVar7 = param_2;
          iVar3 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(unaff_s0);
          if (iVar3 != 0) {
            (*(code *)PTR_EC_GROUP_free_006a829c)(param_2);
            iVar3 = unaff_s0;
            goto LAB_005f7504;
          }
        }
        (*(code *)PTR_EC_KEY_free_006a82d8)(unaff_s0);
        iVar3 = 0;
        goto LAB_005f7504;
      }
      uVar9 = 0x41;
    }
    else {
      uVar9 = 0x8e;
    }
LAB_005f74ec:
    puVar7 = (undefined4 *)&DAT_000000dc;
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdc,uVar9,"ec_ameth.c");
    iVar3 = 0;
  }
LAB_005f7504:
  if (local_14 == *(int *)puStack_48) {
    return iVar3;
  }
  iVar3 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uStack_6c = 0;
  iStack_5c = 0;
  iStack_54 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar8 = &uStack_6c;
  iStack_4c = unaff_s0;
  puStack_44 = param_2;
  iVar2 = (*(code *)PTR_PKCS8_pkey_get0_006a98c0)(0,&uStack_6c,&uStack_60,&uStack_58,puVar7);
  if (iVar2 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a98c4)(0,&uStack_64,&uStack_68,uStack_58);
    iStack_5c = eckey_type2param(uStack_64,uStack_68);
    if (iStack_5c == 0) {
LAB_005f7804:
      puVar8 = (undefined4 *)0xd5;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd5,0x10,"ec_ameth.c",0x131);
    }
    else {
      iVar2 = (*(code *)PTR_d2i_ECPrivateKey_006a9f38)(&iStack_5c,&uStack_6c,uStack_60);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iStack_5c);
        if (iVar2 != 0) {
LAB_005f7718:
          puVar8 = (undefined4 *)0x198;
          (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar3,0x198,iStack_5c);
          iVar3 = 1;
          goto LAB_005f7690;
        }
        uVar9 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(iStack_5c);
        iVar2 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar9);
        if (iVar2 == 0) {
          uVar9 = 0x114;
        }
        else {
          uVar5 = (*(code *)PTR_EC_GROUP_get0_generator_006a82e0)(uVar9);
          iVar4 = (*(code *)PTR_EC_POINT_copy_006a9144)(iVar2,uVar5);
          if (iVar4 == 0) {
            (*(code *)PTR_EC_POINT_free_006a9134)(iVar2);
            uVar9 = 0x11a;
          }
          else {
            uVar5 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iStack_5c);
            iVar4 = (*(code *)PTR_EC_POINT_mul_006a976c)(uVar9,iVar2,uVar5,0,0,0);
            if (iVar4 == 0) {
              (*(code *)PTR_EC_POINT_free_006a9134)(iVar2);
              uVar9 = 0x121;
            }
            else {
              iVar4 = (*(code *)PTR_EC_KEY_set_public_key_006a91b0)(iStack_5c,iVar2);
              if (iVar4 != 0) {
                (*(code *)PTR_EC_POINT_free_006a9134)(iVar2);
                goto LAB_005f7718;
              }
              (*(code *)PTR_EC_POINT_free_006a9134)();
              uVar9 = 0x127;
            }
          }
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd5,0x10,"ec_ameth.c",uVar9);
        goto LAB_005f7804;
      }
      puVar8 = (undefined4 *)0xd5;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd5,0x8e,"ec_ameth.c",0x104);
    }
    if (iStack_5c != 0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)();
      iVar3 = 0;
      goto LAB_005f7690;
    }
  }
  iVar3 = 0;
LAB_005f7690:
  if (iStack_54 == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = iStack_54;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar9 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(puVar8[5]);
  uVar5 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(*(undefined4 *)(iVar3 + 0x14));
  uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(puVar8[5]);
  iVar3 = (*(code *)PTR_EC_POINT_cmp_006a9730)(uVar9,uVar5,uVar6,0);
  iVar2 = -2;
  if (iVar3 == 0) {
    return 1;
  }
  if (iVar3 == 1) {
    iVar2 = 0;
  }
  return iVar2;
}

