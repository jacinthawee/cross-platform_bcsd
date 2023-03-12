
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_34 = 0;
  local_24 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar7 = &local_34;
  iVar2 = (*(code *)PTR_PKCS8_pkey_get0_006a87a0)(0,&local_34,&local_28,&local_20,param_2);
  if (iVar2 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&local_2c,&local_30,local_20);
    local_24 = eckey_type2param(local_2c,local_30);
    if (local_24 == 0) {
LAB_005f5848:
      puVar7 = (undefined4 *)0xd5;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd5,0x10,"ec_ameth.c",0x121);
    }
    else {
      iVar2 = (*(code *)PTR_d2i_ECPrivateKey_006a8e1c)(&local_24,&local_34,local_28);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(local_24);
        if (iVar2 != 0) {
LAB_005f575c:
          puVar7 = (undefined4 *)0x198;
          (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x198,local_24);
          uVar3 = 1;
          goto LAB_005f56d4;
        }
        uVar3 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(local_24);
        iVar2 = (*(code *)PTR_EC_POINT_new_006a7fc0)(uVar3);
        if (iVar2 == 0) {
          uVar3 = 0x107;
        }
        else {
          uVar5 = (*(code *)PTR_EC_GROUP_get0_generator_006a71e0)(uVar3);
          iVar4 = (*(code *)PTR_EC_POINT_copy_006a7fc4)(iVar2,uVar5);
          if (iVar4 == 0) {
            (*(code *)PTR_EC_POINT_free_006a7fac)(iVar2);
            uVar3 = 0x10c;
          }
          else {
            uVar5 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(local_24);
            iVar4 = (*(code *)PTR_EC_POINT_mul_006a8648)(uVar3,iVar2,uVar5,0,0,0);
            if (iVar4 == 0) {
              (*(code *)PTR_EC_POINT_free_006a7fac)(iVar2);
              uVar3 = 0x112;
            }
            else {
              iVar4 = (*(code *)PTR_EC_KEY_set_public_key_006a8068)(local_24,iVar2);
              if (iVar4 != 0) {
                (*(code *)PTR_EC_POINT_free_006a7fac)(iVar2);
                goto LAB_005f575c;
              }
              (*(code *)PTR_EC_POINT_free_006a7fac)();
              uVar3 = 0x117;
            }
          }
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd5,0x10,"ec_ameth.c",uVar3);
        goto LAB_005f5848;
      }
      puVar7 = (undefined4 *)0xd5;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd5,0x8e,"ec_ameth.c",0xf7);
    }
    if (local_24 != 0) {
      (*(code *)PTR_EC_KEY_free_006a71d4)();
      uVar3 = 0;
      goto LAB_005f56d4;
    }
  }
  uVar3 = 0;
LAB_005f56d4:
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar3 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(puVar7[5]);
  uVar5 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(*(undefined4 *)(iVar2 + 0x14));
  uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(puVar7[5]);
  iVar2 = (*(code *)PTR_EC_POINT_cmp_006a8610)(uVar3,uVar5,uVar6,0);
  uVar3 = 0xfffffffe;
  if (iVar2 == 0) {
    return 1;
  }
  if (iVar2 == 1) {
    uVar3 = 0;
  }
  return uVar3;
}

