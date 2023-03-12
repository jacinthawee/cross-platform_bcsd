
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
  undefined *puVar8;
  undefined4 local_13bc;
  undefined4 local_13b8;
  undefined auStack_13b4 [2500];
  undefined auStack_9f0 [2500];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_13bc = 0;
  local_13b8 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (int *)0x0)) || (param_4 == (int *)0x0)) {
    uVar4 = 0;
    uVar3 = 0;
    puVar8 = (undefined *)0x0;
LAB_005cc384:
    if (param_5 == 0) goto LAB_005cc3ac;
  }
  else {
    if (param_5 == 0) {
      puVar7 = (undefined4 *)SRP_get_default_gN(param_6);
      if (puVar7 == (undefined4 *)0x0) {
        puVar8 = (undefined *)0x0;
        goto LAB_005cc3ac;
      }
      uVar3 = puVar7[2];
      uVar4 = puVar7[1];
      puVar8 = (undefined *)*puVar7;
LAB_005cc284:
      if (*param_3 == 0) {
        (*(code *)PTR_RAND_pseudo_bytes_006a8664)(auStack_9f0,0x14);
        local_13bc = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_9f0,0x14,0);
LAB_005cc2bc:
        iVar2 = SRP_create_verifier_BN(param_1,param_2,&local_13bc,&local_13b8,uVar3,uVar4);
        if (iVar2 != 0) {
          (*(code *)PTR_BN_bn2bin_006a8300)(local_13b8,auStack_13b4);
          iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(local_13b8);
          iVar2 = iVar5 + 7;
          if (iVar5 + 7 < 0) {
            iVar2 = iVar5 + 0xe;
          }
          iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)((iVar2 >> 3) << 1,"srp_vfy.c",0x240);
          if (iVar2 != 0) {
            iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(local_13b8);
            iVar5 = iVar6 + 7;
            if (iVar6 + 7 < 0) {
              iVar5 = iVar6 + 0xe;
            }
            t_tob64(iVar2,auStack_13b4,iVar5 >> 3);
            *param_4 = iVar2;
            if (*param_3 == 0) {
              iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"srp_vfy.c",0x249);
              if (iVar5 == 0) {
                puVar8 = (undefined *)0x0;
                (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
              }
              else {
                t_tob64(iVar5,auStack_9f0,0x14);
                *param_3 = iVar5;
              }
            }
            goto LAB_005cc384;
          }
        }
      }
      else {
        iVar2 = t_fromb64(auStack_9f0);
        if (iVar2 != 0) {
          local_13bc = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_9f0,iVar2,0);
          goto LAB_005cc2bc;
        }
      }
      puVar8 = (undefined *)0x0;
      goto LAB_005cc384;
    }
    iVar2 = t_fromb64(auStack_13b4,param_5);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_13b4,iVar2,0);
      iVar2 = t_fromb64(auStack_13b4,param_6);
      if (iVar2 != 0) {
        uVar4 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_13b4,iVar2,0);
        puVar8 = &DAT_00673aec;
        goto LAB_005cc284;
      }
    }
    uVar4 = 0;
    puVar8 = (undefined *)0x0;
  }
  (*(code *)PTR_BN_free_006a811c)(uVar3);
  (*(code *)PTR_BN_free_006a811c)(uVar4);
LAB_005cc3ac:
  if (local_2c == *(int *)puVar1) {
    return puVar8;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return (undefined *)0x20;
}

