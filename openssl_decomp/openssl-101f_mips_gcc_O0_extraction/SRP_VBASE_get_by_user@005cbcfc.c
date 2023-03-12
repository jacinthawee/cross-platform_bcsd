
int * SRP_VBASE_get_by_user(undefined4 *param_1,int *param_2,int *param_3,int *param_4)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int **ppiVar8;
  int iVar9;
  char *pcVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int unaff_s0;
  int *unaff_s1;
  int *piVar14;
  undefined4 *unaff_s2;
  undefined4 uVar15;
  undefined *unaff_s5;
  undefined *unaff_s8;
  undefined4 uStack_1e4c;
  undefined4 uStack_1e48;
  undefined auStack_1e44 [2500];
  undefined auStack_1480 [2500];
  int iStack_abc;
  undefined *puStack_ab8;
  int iStack_ab4;
  int *piStack_ab0;
  int *piStack_aac;
  int *piStack_aa8;
  int *piStack_aa4;
  undefined *puStack_aa0;
  undefined *puStack_a98;
  code *pcStack_a94;
  int iStack_a80;
  undefined4 uStack_a7c;
  undefined *puStack_a78;
  undefined auStack_a70 [2500];
  int iStack_ac;
  int iStack_a8;
  int *piStack_a4;
  undefined4 *puStack_a0;
  undefined *puStack_9c;
  int *piStack_98;
  undefined *puStack_94;
  int *local_70;
  int *piStack_6c;
  undefined auStack_64 [24];
  undefined auStack_4c [20];
  undefined4 auStack_38 [5];
  int *local_24;
  
  puStack_9c = PTR___stack_chk_guard_006aabf0;
  local_70 = (int *)&_gp;
  local_24 = *(int **)PTR___stack_chk_guard_006aabf0;
  pcVar10 = (char *)param_2;
  if (param_1 == (undefined4 *)0x0) goto LAB_005cbfb8;
  for (unaff_s0 = 0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*param_1), unaff_s0 < iVar2;
      unaff_s0 = unaff_s0 + 1) {
    piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(*param_1,unaff_s0);
    pcVar10 = (char *)param_2;
    iVar2 = (*(code *)PTR_strcmp_006aac20)(*piVar3);
    piStack_a4 = piVar3;
    if (iVar2 == 0) goto LAB_005cbf34;
    unaff_s1 = piVar3;
  }
  piVar3 = (int *)0x0;
  piStack_a4 = unaff_s1;
  if ((param_1[2] != 0) && (piVar3 = (int *)0x0, param_1[3] != 0)) {
    pcVar10 = "r";
    unaff_s2 = param_1;
    if (param_1[4] != 0) {
      param_3 = (int *)&DAT_000000c3;
      pcVar10 = "srp_vfy.c";
      piVar3 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18);
      unaff_s1 = piVar3;
      if (piVar3 != (int *)0x0) {
        iVar2 = param_1[3];
        iVar9 = param_1[4];
        piVar3[1] = 0;
        piVar3[2] = 0;
        *piVar3 = 0;
        piVar3[5] = 0;
        piVar3[4] = iVar9;
        piVar3[3] = iVar2;
        if (param_2 == (int *)0x0) {
LAB_005cbe14:
          unaff_s5 = auStack_4c;
          (*(code *)PTR_RAND_pseudo_bytes_006a8664)(unaff_s5,0x14);
          (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_64);
          uVar4 = (*(code *)PTR_EVP_sha1_006a86c4)();
          (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_64,uVar4,0);
          uVar15 = param_1[2];
          uVar4 = (*(code *)PTR_strlen_006aab30)(uVar15);
          param_1 = auStack_38;
          (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_64,uVar15,uVar4);
          uVar4 = (*(code *)PTR_strlen_006aab30)(param_2);
          (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_64,param_2,uVar4);
          (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_64,param_1,0);
          (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_64);
          unaff_s0 = (*(code *)PTR_BN_bin2bn_006a89f0)(param_1,0x14,0);
          param_3 = (int *)0x0;
          pcVar10 = &DAT_00000014;
          iVar2 = (*(code *)PTR_BN_bin2bn_006a89f0)(unaff_s5);
          piVar3[1] = unaff_s0;
          piVar3[2] = iVar2;
          if ((unaff_s0 != 0) && (piStack_a4 = piVar3, iVar2 != 0)) goto LAB_005cbf34;
        }
        else {
          iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(param_2);
          *piVar3 = iVar2;
          if (iVar2 != 0) goto LAB_005cbe14;
          unaff_s0 = piVar3[1];
        }
        (*(code *)PTR_BN_free_006a811c)(unaff_s0);
        (*(code *)PTR_BN_clear_free_006a9130)(piVar3[2]);
        (*(code *)PTR_CRYPTO_free_006a7f88)(*piVar3);
        (*(code *)PTR_CRYPTO_free_006a7f88)(piVar3[5]);
        (*(code *)PTR_CRYPTO_free_006a7f88)(piVar3);
        unaff_s2 = param_1;
      }
    }
LAB_005cbfb8:
    piVar3 = (int *)0x0;
    piStack_a4 = unaff_s1;
    param_1 = unaff_s2;
  }
LAB_005cbf34:
  if (local_24 == *(int **)puStack_9c) {
    return piVar3;
  }
  piVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_ab8 = PTR___stack_chk_guard_006aabf0;
  puStack_a78 = &_gp;
  iStack_ac = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar11 = (int *)pcVar10;
  piVar12 = param_3;
  piVar13 = param_4;
  iStack_a8 = unaff_s0;
  puStack_a0 = param_1;
  piStack_98 = param_2;
  puStack_94 = unaff_s5;
  iStack_ab4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (((((piVar3 == (int *)0x0) || ((int *)pcVar10 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
      ((param_4 == (int *)0x0 || (piStack_6c == (int *)0x0)))) || (iStack_ab4 == 0)) {
    piStack_ab0 = (int *)0x0;
    piStack_aac = (int *)0x0;
  }
  else {
    iVar2 = *param_3;
    if (iVar2 == 0) {
      unaff_s8 = auStack_a70;
      (**(code **)(puStack_a78 + -0x787c))(unaff_s8,0x14);
      iVar2 = (**(code **)(puStack_a78 + -0x74f0))(unaff_s8,0x14,0);
      *param_3 = iVar2;
    }
    piStack_ab0 = (int *)SRP_Calc_x(iVar2);
    iVar2 = (**(code **)(puStack_a78 + -0x7c2c))();
    *param_4 = iVar2;
    if (iVar2 == 0) {
      piStack_aac = (int *)0x0;
      piVar11 = piVar3;
      piVar12 = (int *)pcVar10;
    }
    else {
      piVar12 = piStack_ab0;
      iStack_a80 = iStack_ab4;
      iVar2 = (**(code **)(puStack_a78 + -0x7498))(iVar2);
      if (iVar2 == 0) {
        piStack_aac = (int *)0x0;
        (**(code **)(puStack_a78 + -0x6db0))(*param_4);
        piVar11 = piStack_6c;
        piVar13 = local_70;
      }
      else {
        piStack_aac = (int *)0x1;
        piVar11 = piStack_6c;
        piVar13 = local_70;
      }
    }
  }
  (**(code **)(puStack_a78 + -0x6db0))(piStack_ab0);
  (**(code **)(puStack_a78 + -0x74a0))(iStack_ab4);
  if (iStack_ac == *(int *)puStack_ab8) {
    return piStack_aac;
  }
  pcStack_a94 = SRP_create_verifier;
  iVar9 = iStack_ac;
  (**(code **)(puStack_a78 + -0x5328))();
  iVar2 = iStack_a80;
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puStack_aa0 = &_gp;
  uStack_1e4c = 0;
  uStack_1e48 = 0;
  iStack_abc = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_aa8 = param_4;
  piStack_aa4 = param_3;
  puStack_a98 = unaff_s8;
  if (((iVar9 == 0) || (piVar11 == (int *)0x0)) ||
     ((piVar12 == (int *)0x0 || (piVar13 == (int *)0x0)))) {
    piVar6 = (int *)0x0;
    piVar3 = (int *)0x0;
    piVar14 = (int *)0x0;
LAB_005cc384:
    if (iVar2 == 0) goto LAB_005cc3ac;
  }
  else {
    if (iStack_a80 == 0) {
      ppiVar8 = (int **)SRP_get_default_gN(uStack_a7c);
      if (ppiVar8 == (int **)0x0) {
        piVar14 = (int *)0x0;
        goto LAB_005cc3ac;
      }
      piVar3 = ppiVar8[2];
      piVar6 = ppiVar8[1];
      piVar14 = *ppiVar8;
LAB_005cc284:
      if (*piVar12 == 0) {
        (*(code *)PTR_RAND_pseudo_bytes_006a8664)(auStack_1480,0x14);
        uStack_1e4c = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_1480,0x14,0);
LAB_005cc2bc:
        iVar9 = SRP_create_verifier_BN(iVar9,piVar11,&uStack_1e4c,&uStack_1e48,piVar3,piVar6);
        if (iVar9 != 0) {
          (*(code *)PTR_BN_bn2bin_006a8300)(uStack_1e48,auStack_1e44);
          iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(uStack_1e48);
          iVar9 = iVar5 + 7;
          if (iVar5 + 7 < 0) {
            iVar9 = iVar5 + 0xe;
          }
          iVar9 = (*(code *)PTR_CRYPTO_malloc_006a8108)((iVar9 >> 3) << 1,"srp_vfy.c",0x240);
          if (iVar9 != 0) {
            iVar7 = (*(code *)PTR_BN_num_bits_006a82f4)(uStack_1e48);
            iVar5 = iVar7 + 7;
            if (iVar7 + 7 < 0) {
              iVar5 = iVar7 + 0xe;
            }
            t_tob64(iVar9,auStack_1e44,iVar5 >> 3);
            *piVar13 = iVar9;
            if (*piVar12 == 0) {
              iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"srp_vfy.c",0x249);
              if (iVar5 == 0) {
                piVar14 = (int *)0x0;
                (*(code *)PTR_CRYPTO_free_006a7f88)(iVar9);
              }
              else {
                t_tob64(iVar5,auStack_1480,0x14);
                *piVar12 = iVar5;
              }
            }
            goto LAB_005cc384;
          }
        }
      }
      else {
        iVar5 = t_fromb64(auStack_1480);
        if (iVar5 != 0) {
          uStack_1e4c = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_1480,iVar5,0);
          goto LAB_005cc2bc;
        }
      }
      piVar14 = (int *)0x0;
      goto LAB_005cc384;
    }
    iVar5 = t_fromb64(auStack_1e44,iStack_a80);
    if (iVar5 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(*(code *)PTR_BN_bin2bn_006a89f0)(auStack_1e44,iVar5,0);
      iVar5 = t_fromb64(auStack_1e44,uStack_a7c);
      if (iVar5 != 0) {
        piVar6 = (int *)(*(code *)PTR_BN_bin2bn_006a89f0)(auStack_1e44,iVar5,0);
        piVar14 = (int *)&DAT_00673aec;
        goto LAB_005cc284;
      }
    }
    piVar6 = (int *)0x0;
    piVar14 = (int *)0x0;
  }
  (*(code *)PTR_BN_free_006a811c)(piVar3);
  (*(code *)PTR_BN_free_006a811c)(piVar6);
LAB_005cc3ac:
  if (iStack_abc == *(int *)puVar1) {
    return piVar14;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return (int *)&DAT_00000020;
}

