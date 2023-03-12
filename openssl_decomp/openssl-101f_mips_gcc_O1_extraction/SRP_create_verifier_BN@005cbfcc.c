
undefined *
SRP_create_verifier_BN
          (int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  undefined *puVar12;
  undefined *unaff_s8;
  undefined4 uStack_1dcc;
  undefined4 uStack_1dc8;
  undefined auStack_1dc4 [2500];
  undefined auStack_1400 [2500];
  int iStack_a3c;
  undefined *puStack_a38;
  int iStack_a34;
  int *piStack_a30;
  undefined *puStack_a2c;
  int *piStack_a28;
  int *piStack_a24;
  int *piStack_a20;
  int *piStack_a1c;
  undefined *puStack_a18;
  code *pcStack_a14;
  int local_a00;
  undefined4 uStack_9fc;
  undefined *local_9f8;
  undefined auStack_9f0 [2500];
  int local_2c;
  
  puStack_a38 = PTR___stack_chk_guard_006aabf0;
  local_9f8 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar9 = param_2;
  piVar10 = param_3;
  piVar11 = param_4;
  iStack_a34 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (((((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
      ((param_4 == (int *)0x0 || (param_5 == (int *)0x0)))) ||
     ((param_6 == (int *)0x0 || (iStack_a34 == 0)))) {
    piStack_a30 = (int *)0x0;
    puStack_a2c = (undefined *)0x0;
  }
  else {
    iVar8 = *param_3;
    if (iVar8 == 0) {
      unaff_s8 = auStack_9f0;
      (**(code **)(local_9f8 + -0x787c))(unaff_s8,0x14);
      iVar8 = (**(code **)(local_9f8 + -0x74f0))(unaff_s8,0x14,0);
      *param_3 = iVar8;
    }
    piStack_a30 = (int *)SRP_Calc_x(iVar8);
    iVar8 = (**(code **)(local_9f8 + -0x7c2c))();
    *param_4 = iVar8;
    if (iVar8 == 0) {
      puStack_a2c = (undefined *)0x0;
      piVar9 = param_1;
      piVar10 = param_2;
    }
    else {
      piVar9 = param_6;
      piVar10 = piStack_a30;
      piVar11 = param_5;
      local_a00 = iStack_a34;
      iVar8 = (**(code **)(local_9f8 + -0x7498))(iVar8);
      if (iVar8 == 0) {
        puStack_a2c = (undefined *)0x0;
        (**(code **)(local_9f8 + -0x6db0))(*param_4);
      }
      else {
        puStack_a2c = (undefined *)0x1;
      }
    }
  }
  (**(code **)(local_9f8 + -0x6db0))(piStack_a30);
  (**(code **)(local_9f8 + -0x74a0))(iStack_a34);
  if (local_2c == *(int *)puStack_a38) {
    return puStack_a2c;
  }
  pcStack_a14 = SRP_create_verifier;
  iVar5 = local_2c;
  (**(code **)(local_9f8 + -0x5328))();
  iVar8 = local_a00;
  puVar1 = PTR___stack_chk_guard_006aabf0;
  piStack_a1c = param_6;
  piStack_a20 = param_5;
  uStack_1dcc = 0;
  uStack_1dc8 = 0;
  iStack_a3c = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_a28 = param_4;
  piStack_a24 = param_3;
  puStack_a18 = unaff_s8;
  if (((iVar5 == 0) || (piVar9 == (int *)0x0)) ||
     ((piVar10 == (int *)0x0 || (piVar11 == (int *)0x0)))) {
    uVar4 = 0;
    uVar3 = 0;
    puVar12 = (undefined *)0x0;
LAB_005cc384:
    if (iVar8 == 0) goto LAB_005cc3ac;
  }
  else {
    if (local_a00 == 0) {
      puVar7 = (undefined4 *)SRP_get_default_gN(uStack_9fc);
      if (puVar7 == (undefined4 *)0x0) {
        puVar12 = (undefined *)0x0;
        goto LAB_005cc3ac;
      }
      uVar3 = puVar7[2];
      uVar4 = puVar7[1];
      puVar12 = (undefined *)*puVar7;
LAB_005cc284:
      if (*piVar10 == 0) {
        (*(code *)PTR_RAND_pseudo_bytes_006a8664)(auStack_1400,0x14);
        uStack_1dcc = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_1400,0x14,0);
LAB_005cc2bc:
        iVar5 = SRP_create_verifier_BN(iVar5,piVar9,&uStack_1dcc,&uStack_1dc8,uVar3,uVar4);
        if (iVar5 != 0) {
          (*(code *)PTR_BN_bn2bin_006a8300)(uStack_1dc8,auStack_1dc4);
          iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(uStack_1dc8);
          iVar5 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            iVar5 = iVar2 + 0xe;
          }
          iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)((iVar5 >> 3) << 1,"srp_vfy.c",0x240);
          if (iVar5 != 0) {
            iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(uStack_1dc8);
            iVar2 = iVar6 + 7;
            if (iVar6 + 7 < 0) {
              iVar2 = iVar6 + 0xe;
            }
            t_tob64(iVar5,auStack_1dc4,iVar2 >> 3);
            *piVar11 = iVar5;
            if (*piVar10 == 0) {
              iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"srp_vfy.c",0x249);
              if (iVar2 == 0) {
                puVar12 = (undefined *)0x0;
                (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
              }
              else {
                t_tob64(iVar2,auStack_1400,0x14);
                *piVar10 = iVar2;
              }
            }
            goto LAB_005cc384;
          }
        }
      }
      else {
        iVar2 = t_fromb64(auStack_1400);
        if (iVar2 != 0) {
          uStack_1dcc = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_1400,iVar2,0);
          goto LAB_005cc2bc;
        }
      }
      puVar12 = (undefined *)0x0;
      goto LAB_005cc384;
    }
    iVar2 = t_fromb64(auStack_1dc4,local_a00);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_1dc4,iVar2,0);
      iVar2 = t_fromb64(auStack_1dc4,uStack_9fc);
      if (iVar2 != 0) {
        uVar4 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_1dc4,iVar2,0);
        puVar12 = &DAT_00673b0c;
        goto LAB_005cc284;
      }
    }
    uVar4 = 0;
    puVar12 = (undefined *)0x0;
  }
  (*(code *)PTR_BN_free_006a811c)(uVar3);
  (*(code *)PTR_BN_free_006a811c)(uVar4);
LAB_005cc3ac:
  if (iStack_a3c == *(int *)puVar1) {
    return puVar12;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return (undefined *)0x20;
}

