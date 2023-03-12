
undefined *
SRP_create_verifier(int param_1,int param_2,int *param_3,int *param_4,int param_5,undefined4 param_6
                   )

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 local_13bc;
  undefined4 local_13b8;
  undefined auStack_13b4 [2500];
  undefined auStack_9f0 [2500];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_13bc = 0;
  local_13b8 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (int *)0x0)) || (param_4 == (int *)0x0)) {
    iVar5 = 0;
    uVar4 = 0;
    uVar3 = 0;
    iVar2 = 0;
    puVar9 = (undefined *)0x0;
LAB_005c9d34:
    if (param_5 == 0) goto LAB_005c9d60;
  }
  else {
    if (param_5 == 0) {
      puVar7 = (undefined4 *)SRP_get_default_gN(param_6);
      if (puVar7 == (undefined4 *)0x0) {
        iVar5 = 0;
        iVar2 = 0;
        puVar9 = (undefined *)0x0;
        goto LAB_005c9d60;
      }
      uVar3 = puVar7[2];
      uVar4 = puVar7[1];
      puVar9 = (undefined *)*puVar7;
LAB_005c9c24:
      if (*param_3 == 0) {
        iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_9f0,0x14);
        if (0 < iVar2) {
          local_13bc = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_9f0,0x14,0);
          goto LAB_005c9c5c;
        }
      }
      else {
        iVar2 = t_fromb64(auStack_9f0);
        if (iVar2 != 0) {
          local_13bc = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_9f0,iVar2,0);
LAB_005c9c5c:
          iVar2 = SRP_create_verifier_BN(param_1,param_2,&local_13bc,&local_13b8,uVar3,uVar4);
          if (iVar2 != 0) {
            (*(code *)PTR_BN_bn2bin_006a7200)(local_13b8,auStack_13b4);
            iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(local_13b8);
            iVar2 = iVar5 + 7;
            if (iVar5 + 7 < 0) {
              iVar2 = iVar5 + 0xe;
            }
            iVar5 = (iVar2 >> 3) << 1;
            iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar5,"srp_vfy.c",0x267);
            if (iVar2 == 0) {
LAB_005c9ebc:
              puVar9 = (undefined *)0x0;
            }
            else {
              iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(local_13b8);
              iVar8 = iVar6 + 7;
              if (iVar6 + 7 < 0) {
                iVar8 = iVar6 + 0xe;
              }
              t_tob64(iVar2,auStack_13b4,iVar8 >> 3);
              if (*param_3 == 0) {
                iVar8 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"srp_vfy.c",0x26e);
                if (iVar8 == 0) goto LAB_005c9ebc;
                t_tob64(iVar8,auStack_9f0,0x14);
                *param_3 = iVar8;
              }
              *param_4 = iVar2;
              iVar2 = 0;
            }
            goto LAB_005c9d34;
          }
        }
      }
      iVar5 = 0;
      iVar2 = 0;
      puVar9 = (undefined *)0x0;
      goto LAB_005c9d34;
    }
    iVar2 = t_fromb64(auStack_13b4,param_5);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_13b4,iVar2,0);
      iVar2 = t_fromb64(auStack_13b4,param_6);
      if (iVar2 != 0) {
        uVar4 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_13b4,iVar2,0);
        puVar9 = &DAT_006731fc;
        goto LAB_005c9c24;
      }
    }
    iVar5 = 0;
    uVar4 = 0;
    iVar2 = 0;
    puVar9 = (undefined *)0x0;
  }
  (*(code *)PTR_BN_free_006a701c)(uVar3);
  (*(code *)PTR_BN_free_006a701c)(uVar4);
LAB_005c9d60:
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar2,iVar5);
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
  (*(code *)PTR_BN_clear_free_006a7fa8)(local_13bc);
  (*(code *)PTR_BN_clear_free_006a7fa8)(local_13b8);
  if (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return (undefined *)0x20;
  }
  return puVar9;
}

