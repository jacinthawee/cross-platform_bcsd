
undefined *
SRP_create_verifier_BN
          (int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  undefined *puVar13;
  undefined4 uStack_1dcc;
  undefined4 uStack_1dc8;
  undefined auStack_1dc4 [2500];
  undefined auStack_1400 [2500];
  int iStack_a3c;
  undefined *puStack_a38;
  int *piStack_a34;
  undefined *puStack_a30;
  int iStack_a2c;
  int *piStack_a28;
  int *piStack_a24;
  int *piStack_a20;
  int *piStack_a1c;
  int *piStack_a18;
  code *pcStack_a14;
  int local_a00;
  undefined4 uStack_9fc;
  undefined *local_9f8;
  undefined auStack_9f0 [2500];
  int local_2c;
  
  puStack_a30 = PTR___stack_chk_guard_006a9ae8;
  local_9f8 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  piVar9 = param_2;
  piVar10 = param_3;
  piVar11 = param_4;
  iStack_a2c = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (((((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
      ((param_4 == (int *)0x0 || (param_5 == (int *)0x0)))) ||
     ((param_6 == (int *)0x0 || (iStack_a2c == 0)))) {
LAB_005c9a60:
    param_1 = piVar9;
    iVar12 = 0;
    piStack_a28 = (int *)0x0;
LAB_005c9a64:
    if (iVar12 == *param_3) {
      puStack_a38 = (undefined *)0x0;
    }
    else {
      puStack_a38 = (undefined *)0x0;
      (**(code **)(local_9f8 + -0x6e38))(iVar12);
    }
  }
  else {
    iVar12 = *param_3;
    if (iVar12 == 0) {
      piVar9 = (int *)&DAT_00000014;
      iVar12 = (**(code **)(local_9f8 + -0x786c))(auStack_9f0);
      if (iVar12 < 1) goto LAB_005c9a60;
      iVar12 = (**(code **)(local_9f8 + -0x74dc))(auStack_9f0,0x14,0);
    }
    piVar10 = param_2;
    piStack_a28 = (int *)SRP_Calc_x(iVar12);
    iVar2 = (**(code **)(local_9f8 + -0x7c2c))();
    *param_4 = iVar2;
    if (iVar2 == 0) goto LAB_005c9a64;
    param_1 = param_6;
    piVar10 = piStack_a28;
    piVar11 = param_5;
    local_a00 = iStack_a2c;
    iVar2 = (**(code **)(local_9f8 + -0x7484))(iVar2);
    if (iVar2 == 0) {
      (**(code **)(local_9f8 + -0x6e38))(*param_4);
      goto LAB_005c9a64;
    }
    *param_3 = iVar12;
    puStack_a38 = (undefined *)0x1;
  }
  (**(code **)(local_9f8 + -0x6e38))(piStack_a28);
  (**(code **)(local_9f8 + -0x748c))(iStack_a2c);
  if (local_2c == *(int *)puStack_a30) {
    return puStack_a38;
  }
  pcStack_a14 = SRP_create_verifier;
  iVar2 = local_2c;
  (**(code **)(local_9f8 + -0x5330))();
  iVar12 = local_a00;
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  piStack_a20 = param_5;
  piStack_a1c = param_6;
  uStack_1dcc = 0;
  uStack_1dc8 = 0;
  iStack_a3c = *(int *)PTR___stack_chk_guard_006a9ae8;
  piStack_a34 = param_3;
  piStack_a24 = param_4;
  piStack_a18 = param_2;
  if (((iVar2 == 0) || (param_1 == (int *)0x0)) ||
     ((piVar10 == (int *)0x0 || (piVar11 == (int *)0x0)))) {
    iVar3 = 0;
    uVar5 = 0;
    uVar4 = 0;
    iVar2 = 0;
    puVar13 = (undefined *)0x0;
LAB_005c9d34:
    if (iVar12 == 0) goto LAB_005c9d60;
  }
  else {
    if (local_a00 == 0) {
      puVar7 = (undefined4 *)SRP_get_default_gN(uStack_9fc);
      if (puVar7 == (undefined4 *)0x0) {
        iVar3 = 0;
        iVar2 = 0;
        puVar13 = (undefined *)0x0;
        goto LAB_005c9d60;
      }
      uVar4 = puVar7[2];
      uVar5 = puVar7[1];
      puVar13 = (undefined *)*puVar7;
LAB_005c9c24:
      if (*piVar10 == 0) {
        iVar3 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_1400,0x14);
        if (0 < iVar3) {
          uStack_1dcc = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_1400,0x14,0);
          goto LAB_005c9c5c;
        }
      }
      else {
        iVar3 = t_fromb64(auStack_1400);
        if (iVar3 != 0) {
          uStack_1dcc = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_1400,iVar3,0);
LAB_005c9c5c:
          iVar2 = SRP_create_verifier_BN(iVar2,param_1,&uStack_1dcc,&uStack_1dc8,uVar4,uVar5);
          if (iVar2 != 0) {
            (*(code *)PTR_BN_bn2bin_006a7200)(uStack_1dc8,auStack_1dc4);
            iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(uStack_1dc8);
            iVar2 = iVar3 + 7;
            if (iVar3 + 7 < 0) {
              iVar2 = iVar3 + 0xe;
            }
            iVar3 = (iVar2 >> 3) << 1;
            iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"srp_vfy.c",0x267);
            if (iVar2 == 0) {
LAB_005c9ebc:
              puVar13 = (undefined *)0x0;
            }
            else {
              iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(uStack_1dc8);
              iVar8 = iVar6 + 7;
              if (iVar6 + 7 < 0) {
                iVar8 = iVar6 + 0xe;
              }
              t_tob64(iVar2,auStack_1dc4,iVar8 >> 3);
              if (*piVar10 == 0) {
                iVar8 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"srp_vfy.c",0x26e);
                if (iVar8 == 0) goto LAB_005c9ebc;
                t_tob64(iVar8,auStack_1400,0x14);
                *piVar10 = iVar8;
              }
              *piVar11 = iVar2;
              iVar2 = 0;
            }
            goto LAB_005c9d34;
          }
        }
      }
      iVar3 = 0;
      iVar2 = 0;
      puVar13 = (undefined *)0x0;
      goto LAB_005c9d34;
    }
    iVar3 = t_fromb64(auStack_1dc4,local_a00);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_1dc4,iVar3,0);
      iVar3 = t_fromb64(auStack_1dc4,uStack_9fc);
      if (iVar3 != 0) {
        uVar5 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_1dc4,iVar3,0);
        puVar13 = &DAT_006731fc;
        goto LAB_005c9c24;
      }
    }
    iVar3 = 0;
    uVar5 = 0;
    iVar2 = 0;
    puVar13 = (undefined *)0x0;
  }
  (*(code *)PTR_BN_free_006a701c)(uVar4);
  (*(code *)PTR_BN_free_006a701c)(uVar5);
LAB_005c9d60:
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar2,iVar3);
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
  (*(code *)PTR_BN_clear_free_006a7fa8)(uStack_1dcc);
  (*(code *)PTR_BN_clear_free_006a7fa8)(uStack_1dc8);
  if (iStack_a3c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return (undefined *)0x20;
  }
  return puVar13;
}

