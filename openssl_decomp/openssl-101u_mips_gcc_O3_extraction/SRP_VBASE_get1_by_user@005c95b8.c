
int * SRP_VBASE_get1_by_user(undefined4 *param_1,int *param_2,int *param_3,int *param_4)

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
  int iVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int *unaff_s0;
  undefined4 *unaff_s1;
  undefined4 uVar14;
  int *unaff_s2;
  int *piVar15;
  undefined *unaff_s5;
  undefined4 uStack_1e4c;
  undefined4 uStack_1e48;
  undefined auStack_1e44 [2500];
  undefined auStack_1480 [2500];
  int iStack_abc;
  int *piStack_ab8;
  int *piStack_ab4;
  undefined *puStack_ab0;
  int iStack_aac;
  int *piStack_aa8;
  int *piStack_aa4;
  undefined *puStack_aa0;
  char *pcStack_a98;
  code *pcStack_a94;
  int iStack_a80;
  undefined4 uStack_a7c;
  undefined *puStack_a78;
  undefined auStack_a70 [2500];
  int iStack_ac;
  int *piStack_a8;
  undefined4 *puStack_a4;
  int *piStack_a0;
  undefined *puStack_9c;
  int *piStack_98;
  undefined *puStack_94;
  int *local_70;
  int *piStack_6c;
  int aiStack_64 [6];
  undefined auStack_4c [20];
  undefined auStack_38 [20];
  int *local_24;
  
  puStack_9c = PTR___stack_chk_guard_006a9ae8;
  local_70 = (int *)&_gp;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  pcStack_a98 = (char *)param_2;
  if (param_1 == (undefined4 *)0x0) goto LAB_005c9930;
  for (unaff_s0 = (int *)0x0; iVar2 = (*(code *)PTR_sk_num_006a6e2c)(*param_1), unaff_s1 = param_1,
      (int)unaff_s0 < iVar2; unaff_s0 = (int *)((int)unaff_s0 + 1)) {
    unaff_s2 = (int *)(*(code *)PTR_sk_value_006a6e24)(*param_1,unaff_s0);
    pcStack_a98 = (char *)param_2;
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(*unaff_s2);
    if (iVar2 == 0) {
      param_3 = (int *)0xc9;
      pcStack_a98 = "srp_vfy.c";
      unaff_s0 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18);
      if (unaff_s0 == (int *)0x0) goto LAB_005c9930;
      unaff_s0[4] = 0;
      unaff_s0[3] = 0;
      *unaff_s0 = 0;
      iVar10 = unaff_s2[3];
      iVar2 = unaff_s2[4];
      unaff_s0[5] = 0;
      unaff_s0[1] = 0;
      unaff_s0[3] = iVar10;
      unaff_s0[4] = iVar2;
      unaff_s0[2] = 0;
      iVar2 = unaff_s2[5];
      if (*unaff_s2 != 0) {
        iVar10 = (*(code *)PTR_BUF_strdup_006a6fdc)();
        *unaff_s0 = iVar10;
        if (iVar10 == 0) goto LAB_005c9938;
      }
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_BUF_strdup_006a6fdc)(iVar2);
        unaff_s0[5] = iVar2;
        if (iVar2 == 0) goto LAB_005c9938;
      }
      param_1 = (undefined4 *)(*(code *)PTR_BN_dup_006a8218)(unaff_s2[1]);
      iVar2 = (*(code *)PTR_BN_dup_006a8218)(unaff_s2[2]);
      unaff_s0[1] = (int)param_1;
      unaff_s0[2] = iVar2;
      piVar3 = unaff_s0;
      goto joined_r0x005c97e0;
    }
  }
  piVar3 = (int *)0x0;
  piStack_a8 = unaff_s0;
  if ((param_1[2] != 0) && (piVar3 = (int *)0x0, param_1[3] != 0)) {
    pcStack_a98 = "encrypt";
    if (param_1[4] != 0) {
      param_3 = (int *)0xc9;
      pcStack_a98 = "srp_vfy.c";
      unaff_s0 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18);
      if (unaff_s0 != (int *)0x0) {
        iVar2 = param_1[3];
        iVar10 = param_1[4];
        unaff_s0[1] = 0;
        unaff_s0[2] = 0;
        *unaff_s0 = 0;
        unaff_s0[5] = 0;
        unaff_s0[4] = iVar10;
        unaff_s0[3] = iVar2;
        if (param_2 == (int *)0x0) {
LAB_005c96d0:
          unaff_s5 = auStack_4c;
          pcStack_a98 = &DAT_00000014;
          iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(unaff_s5);
          if (iVar2 < 1) goto LAB_005c9938;
          unaff_s2 = aiStack_64;
          (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(unaff_s2);
          uVar4 = (*(code *)PTR_EVP_sha1_006a75d0)();
          (*(code *)PTR_EVP_DigestInit_ex_006a757c)(unaff_s2,uVar4,0);
          uVar14 = param_1[2];
          uVar4 = (*(code *)PTR_strlen_006a9a24)(uVar14);
          (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,uVar14,uVar4);
          uVar4 = (*(code *)PTR_strlen_006a9a24)(param_2);
          (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s2,param_2,uVar4);
          (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(unaff_s2,auStack_38,0);
          (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(unaff_s2);
          param_1 = (undefined4 *)(*(code *)PTR_BN_bin2bn_006a7904)(auStack_38,0x14,0);
          param_3 = (int *)0x0;
          pcStack_a98 = &DAT_00000014;
          iVar2 = (*(code *)PTR_BN_bin2bn_006a7904)(unaff_s5);
          unaff_s0[1] = (int)param_1;
          unaff_s0[2] = iVar2;
          piVar3 = unaff_s0;
joined_r0x005c97e0:
          unaff_s0 = piVar3;
          if ((param_1 != (undefined4 *)0x0) && (piStack_a8 = piVar3, iVar2 != 0))
          goto LAB_005c97f4;
        }
        else {
          iVar2 = (*(code *)PTR_BUF_strdup_006a6fdc)(param_2);
          *unaff_s0 = iVar2;
          if (iVar2 != 0) goto LAB_005c96d0;
LAB_005c9938:
          param_1 = (undefined4 *)unaff_s0[1];
        }
        (*(code *)PTR_BN_free_006a701c)(param_1);
        (*(code *)PTR_BN_clear_free_006a7fa8)(unaff_s0[2]);
        (*(code *)PTR_CRYPTO_free_006a6e88)(*unaff_s0);
        (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s0[5]);
        (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s0);
        unaff_s1 = param_1;
      }
    }
LAB_005c9930:
    param_1 = unaff_s1;
    piVar3 = (int *)0x0;
    piStack_a8 = unaff_s0;
  }
LAB_005c97f4:
  if (local_24 == *(int **)puStack_9c) {
    return piVar3;
  }
  piVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_ab0 = PTR___stack_chk_guard_006a9ae8;
  puStack_a78 = &_gp;
  iStack_ac = *(int *)PTR___stack_chk_guard_006a9ae8;
  piVar11 = (int *)pcStack_a98;
  piVar12 = param_3;
  piVar13 = param_4;
  puStack_a4 = param_1;
  piStack_a0 = unaff_s2;
  piStack_98 = param_2;
  puStack_94 = unaff_s5;
  iStack_aac = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (((((piVar3 == (int *)0x0) || ((int *)pcStack_a98 == (int *)0x0)) || (param_3 == (int *)0x0))
      || ((param_4 == (int *)0x0 || (piStack_6c == (int *)0x0)))) || (iStack_aac == 0)) {
LAB_005c9a60:
    iVar2 = 0;
    piStack_aa8 = (int *)0x0;
LAB_005c9a64:
    if (iVar2 == *param_3) {
      piStack_ab8 = (int *)0x0;
    }
    else {
      piStack_ab8 = (int *)0x0;
      (**(code **)(puStack_a78 + -0x6e38))(iVar2);
    }
  }
  else {
    iVar2 = *param_3;
    if (iVar2 == 0) {
      piVar11 = (int *)&DAT_00000014;
      iVar2 = (**(code **)(puStack_a78 + -0x786c))(auStack_a70);
      if (iVar2 < 1) goto LAB_005c9a60;
      iVar2 = (**(code **)(puStack_a78 + -0x74dc))(auStack_a70,0x14,0);
    }
    piVar12 = (int *)pcStack_a98;
    piStack_aa8 = (int *)SRP_Calc_x(iVar2);
    iVar10 = (**(code **)(puStack_a78 + -0x7c2c))();
    *param_4 = iVar10;
    piVar11 = piVar3;
    if (iVar10 == 0) goto LAB_005c9a64;
    piVar12 = piStack_aa8;
    iStack_a80 = iStack_aac;
    iVar10 = (**(code **)(puStack_a78 + -0x7484))(iVar10);
    if (iVar10 == 0) {
      (**(code **)(puStack_a78 + -0x6e38))(*param_4);
      piVar11 = piStack_6c;
      piVar13 = local_70;
      goto LAB_005c9a64;
    }
    *param_3 = iVar2;
    piStack_ab8 = (int *)0x1;
    piVar11 = piStack_6c;
    piVar13 = local_70;
  }
  (**(code **)(puStack_a78 + -0x6e38))(piStack_aa8);
  (**(code **)(puStack_a78 + -0x748c))(iStack_aac);
  if (iStack_ac == *(int *)puStack_ab0) {
    return piStack_ab8;
  }
  pcStack_a94 = SRP_create_verifier;
  iVar10 = iStack_ac;
  (**(code **)(puStack_a78 + -0x5330))();
  iVar2 = iStack_a80;
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_aa0 = &_gp;
  uStack_1e4c = 0;
  uStack_1e48 = 0;
  iStack_abc = *(int *)PTR___stack_chk_guard_006a9ae8;
  piStack_ab4 = param_3;
  piStack_aa4 = param_4;
  if (((iVar10 == 0) || (piVar11 == (int *)0x0)) ||
     ((piVar12 == (int *)0x0 || (piVar13 == (int *)0x0)))) {
    iVar5 = 0;
    piVar6 = (int *)0x0;
    piVar3 = (int *)0x0;
    iVar10 = 0;
    piVar15 = (int *)0x0;
LAB_005c9d34:
    if (iVar2 == 0) goto LAB_005c9d60;
  }
  else {
    if (iStack_a80 == 0) {
      ppiVar8 = (int **)SRP_get_default_gN(uStack_a7c);
      if (ppiVar8 == (int **)0x0) {
        iVar5 = 0;
        iVar10 = 0;
        piVar15 = (int *)0x0;
        goto LAB_005c9d60;
      }
      piVar3 = ppiVar8[2];
      piVar6 = ppiVar8[1];
      piVar15 = *ppiVar8;
LAB_005c9c24:
      if (*piVar12 == 0) {
        iVar5 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_1480,0x14);
        if (0 < iVar5) {
          uStack_1e4c = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_1480,0x14,0);
          goto LAB_005c9c5c;
        }
      }
      else {
        iVar5 = t_fromb64(auStack_1480);
        if (iVar5 != 0) {
          uStack_1e4c = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_1480,iVar5,0);
LAB_005c9c5c:
          iVar10 = SRP_create_verifier_BN(iVar10,piVar11,&uStack_1e4c,&uStack_1e48,piVar3,piVar6);
          if (iVar10 != 0) {
            (*(code *)PTR_BN_bn2bin_006a7200)(uStack_1e48,auStack_1e44);
            iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(uStack_1e48);
            iVar10 = iVar5 + 7;
            if (iVar5 + 7 < 0) {
              iVar10 = iVar5 + 0xe;
            }
            iVar5 = (iVar10 >> 3) << 1;
            iVar10 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar5,"srp_vfy.c",0x267);
            if (iVar10 == 0) {
LAB_005c9ebc:
              piVar15 = (int *)0x0;
            }
            else {
              iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(uStack_1e48);
              iVar9 = iVar7 + 7;
              if (iVar7 + 7 < 0) {
                iVar9 = iVar7 + 0xe;
              }
              t_tob64(iVar10,auStack_1e44,iVar9 >> 3);
              if (*piVar12 == 0) {
                iVar9 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"srp_vfy.c",0x26e);
                if (iVar9 == 0) goto LAB_005c9ebc;
                t_tob64(iVar9,auStack_1480,0x14);
                *piVar12 = iVar9;
              }
              *piVar13 = iVar10;
              iVar10 = 0;
            }
            goto LAB_005c9d34;
          }
        }
      }
      iVar5 = 0;
      iVar10 = 0;
      piVar15 = (int *)0x0;
      goto LAB_005c9d34;
    }
    iVar5 = t_fromb64(auStack_1e44,iStack_a80);
    if (iVar5 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(*(code *)PTR_BN_bin2bn_006a7904)(auStack_1e44,iVar5,0);
      iVar5 = t_fromb64(auStack_1e44,uStack_a7c);
      if (iVar5 != 0) {
        piVar6 = (int *)(*(code *)PTR_BN_bin2bn_006a7904)(auStack_1e44,iVar5,0);
        piVar15 = (int *)&DAT_006731fc;
        goto LAB_005c9c24;
      }
    }
    iVar5 = 0;
    piVar6 = (int *)0x0;
    iVar10 = 0;
    piVar15 = (int *)0x0;
  }
  (*(code *)PTR_BN_free_006a701c)(piVar3);
  (*(code *)PTR_BN_free_006a701c)(piVar6);
LAB_005c9d60:
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar10,iVar5);
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar10);
  (*(code *)PTR_BN_clear_free_006a7fa8)(uStack_1e4c);
  (*(code *)PTR_BN_clear_free_006a7fa8)(uStack_1e48);
  if (iStack_abc == *(int *)puVar1) {
    return piVar15;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return (int *)&DAT_00000020;
}

