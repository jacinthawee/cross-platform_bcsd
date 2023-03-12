
undefined4 eckey_priv_decode(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_34 = 0;
  local_24 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar7 = &local_34;
  iVar2 = (*(code *)PTR_PKCS8_pkey_get0_006a98c0)(0,&local_34,&local_28,&local_20,param_2);
  if (iVar2 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a98c4)(0,&local_2c,&local_30,local_20);
    local_24 = eckey_type2param(local_2c,local_30);
    if (local_24 == 0) {
LAB_005f7804:
      puVar7 = (undefined4 *)0xd5;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd5,0x10,"ec_ameth.c",0x131);
    }
    else {
      iVar2 = (*(code *)PTR_d2i_ECPrivateKey_006a9f38)(&local_24,&local_34,local_28);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(local_24);
        if (iVar2 != 0) {
LAB_005f7718:
          puVar7 = (undefined4 *)0x198;
          (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x198,local_24);
          uVar3 = 1;
          goto LAB_005f7690;
        }
        uVar3 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(local_24);
        iVar2 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar3);
        if (iVar2 == 0) {
          uVar3 = 0x114;
        }
        else {
          uVar5 = (*(code *)PTR_EC_GROUP_get0_generator_006a82e0)(uVar3);
          iVar4 = (*(code *)PTR_EC_POINT_copy_006a9144)(iVar2,uVar5);
          if (iVar4 == 0) {
            (*(code *)PTR_EC_POINT_free_006a9134)(iVar2);
            uVar3 = 0x11a;
          }
          else {
            uVar5 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(local_24);
            iVar4 = (*(code *)PTR_EC_POINT_mul_006a976c)(uVar3,iVar2,uVar5,0,0,0);
            if (iVar4 == 0) {
              (*(code *)PTR_EC_POINT_free_006a9134)(iVar2);
              uVar3 = 0x121;
            }
            else {
              iVar4 = (*(code *)PTR_EC_KEY_set_public_key_006a91b0)(local_24,iVar2);
              if (iVar4 != 0) {
                (*(code *)PTR_EC_POINT_free_006a9134)(iVar2);
                goto LAB_005f7718;
              }
              (*(code *)PTR_EC_POINT_free_006a9134)();
              uVar3 = 0x127;
            }
          }
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd5,0x10,"ec_ameth.c",uVar3);
        goto LAB_005f7804;
      }
      puVar7 = (undefined4 *)0xd5;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd5,0x8e,"ec_ameth.c",0x104);
    }
    if (local_24 != 0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)();
      uVar3 = 0;
      goto LAB_005f7690;
    }
  }
  uVar3 = 0;
LAB_005f7690:
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar3 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(puVar7[5]);
  uVar5 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(*(undefined4 *)(iVar2 + 0x14));
  uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(puVar7[5]);
  iVar2 = (*(code *)PTR_EC_POINT_cmp_006a9730)(uVar3,uVar5,uVar6,0);
  uVar3 = 0xfffffffe;
  if (iVar2 == 0) {
    return 1;
  }
  if (iVar2 == 1) {
    uVar3 = 0;
  }
  return uVar3;
}

