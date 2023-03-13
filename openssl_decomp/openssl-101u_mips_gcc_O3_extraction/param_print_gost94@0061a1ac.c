
/* WARNING: Type propagation algorithm not settling */

int * param_print_gost94(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  char *pcVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  code *pcVar16;
  char *pcVar17;
  undefined4 uStack_258;
  int iStack_254;
  undefined4 *puStack_24c;
  undefined *puStack_248;
  int iStack_244;
  int iStack_240;
  undefined4 *puStack_23c;
  undefined4 uStack_238;
  code *pcStack_234;
  int iStack_220;
  undefined4 uStack_21c;
  undefined4 *puStack_218;
  undefined *puStack_210;
  undefined4 uStack_208;
  int iStack_204;
  int iStack_200;
  undefined *puStack_1fc;
  int iStack_1f8;
  undefined4 *puStack_1f4;
  char *pcStack_1f0;
  code *pcStack_1ec;
  undefined4 uStack_1d8;
  int iStack_1d4;
  undefined *puStack_1d0;
  undefined4 uStack_1c8;
  int iStack_1c4;
  undefined *puStack_1bc;
  int *piStack_1b8;
  int *piStack_1b4;
  undefined *puStack_1b0;
  int iStack_1ac;
  undefined4 *puStack_1a8;
  char *pcStack_1a4;
  int *piStack_1a0;
  code *pcStack_19c;
  int **ppiStack_188;
  undefined *puStack_180;
  int *piStack_174;
  int *piStack_170;
  int iStack_16c;
  int iStack_164;
  int *piStack_160;
  int *piStack_15c;
  undefined *puStack_158;
  code *pcStack_154;
  undefined4 uStack_140;
  int iStack_13c;
  undefined *puStack_138;
  int *piStack_130;
  int iStack_12c;
  undefined4 uStack_128;
  int *piStack_124;
  int *piStack_120;
  int *piStack_11c;
  int *piStack_118;
  undefined *puStack_114;
  undefined *puStack_110;
  undefined4 *puStack_10c;
  undefined4 uStack_e0;
  int *piStack_dc;
  undefined4 *puStack_d4;
  int iStack_d0;
  undefined4 *puStack_cc;
  undefined *puStack_c8;
  char *pcStack_c4;
  undefined4 *puStack_c0;
  code *pcStack_bc;
  undefined *puStack_a8;
  undefined4 uStack_a0;
  int *piStack_9c;
  undefined4 uStack_98;
  int iStack_94;
  int iStack_90;
  undefined *puStack_8c;
  undefined4 uStack_88;
  code *pcStack_84;
  undefined *puStack_70;
  undefined4 uStack_68;
  int iStack_64;
  undefined4 uStack_5c;
  int iStack_58;
  undefined *puStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 *puStack_48;
  code *pcStack_44;
  undefined *local_30;
  undefined4 local_28;
  int local_24;
  
  puStack_54 = PTR___stack_chk_guard_006a9ae8;
  local_30 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_58 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  local_28 = (**(code **)(local_30 + -0x7c2c))();
  puStack_48 = &local_28;
  if ((*(undefined4 **)(local_30 + -0x57e4))[3] == 0) {
LAB_0061a27c:
    uStack_5c = 0;
    (**(code **)(local_30 + -0x7dc4))(local_28);
  }
  else {
    pcVar16 = *(code **)(local_30 + -0x6fb0);
    puVar14 = *(undefined4 **)(local_30 + -0x57e4);
    while( true ) {
      (*pcVar16)(puStack_48);
      iVar2 = (**(code **)(local_30 + -0x7480))(local_28,*(undefined4 *)(iStack_58 + 0x10));
      if (iVar2 == 0) break;
      if (puVar14[7] == 0) goto LAB_0061a27c;
      pcVar16 = *(code **)(local_30 + -0x6fb0);
      puVar14 = puVar14 + 4;
    }
    (**(code **)(local_30 + -0x7dc4))(local_28);
    uStack_5c = *puVar14;
  }
  (**(code **)(local_30 + -0x6734))(param_1,param_3,0x80);
  uStack_88 = (**(code **)(local_30 + -0x7cc4))(uStack_5c);
  pcVar13 = "Parameter set: %s\n";
  (**(code **)(local_30 + -0x7fa8))(param_1,"Parameter set: %s\n");
  if (local_24 == *(int *)puStack_54) {
    return (int *)0x1;
  }
  pcStack_44 = pub_print_gost94;
  iStack_90 = local_24;
  (**(code **)(local_30 + -0x5330))();
  puStack_8c = PTR___stack_chk_guard_006a9ae8;
  puStack_70 = &_gp;
  iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_50 = param_1;
  uStack_4c = param_3;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar13);
  uVar15 = *(undefined4 *)(iVar2 + 0x18);
  (**(code **)(puStack_70 + -0x6734))(iStack_90,uStack_88,0x80);
  (**(code **)(puStack_70 + -0x7fa8))(iStack_90,"Public key: ");
  (**(code **)(puStack_70 + -0x7ebc))(iStack_90,uVar15);
  (**(code **)(puStack_70 + -0x7fa8))(iStack_90,"\n");
  iStack_94 = (**(code **)(puStack_70 + -0x5808))(pcVar13);
  uStack_68 = (**(code **)(puStack_70 + -0x7c2c))();
  puStack_10c = &uStack_68;
  if ((*(undefined4 **)(puStack_70 + -0x57e4))[3] == 0) {
LAB_0061a458:
    uStack_98 = 0;
    (**(code **)(puStack_70 + -0x7dc4))(uStack_68);
  }
  else {
    pcVar16 = *(code **)(puStack_70 + -0x6fb0);
    puVar14 = *(undefined4 **)(puStack_70 + -0x57e4);
    while( true ) {
      (*pcVar16)(puStack_10c);
      iVar2 = (**(code **)(puStack_70 + -0x7480))(uStack_68,*(undefined4 *)(iStack_94 + 0x10));
      if (iVar2 == 0) break;
      if (puVar14[7] == 0) goto LAB_0061a458;
      pcVar16 = *(code **)(puStack_70 + -0x6fb0);
      puVar14 = puVar14 + 4;
    }
    (**(code **)(puStack_70 + -0x7dc4))(uStack_68);
    uStack_98 = *puVar14;
  }
  (**(code **)(puStack_70 + -0x6734))(iStack_90,uStack_88,0x80);
  uVar15 = (**(code **)(puStack_70 + -0x7cc4))(uStack_98);
  pcStack_c4 = "Parameter set: %s\n";
  (**(code **)(puStack_70 + -0x7fa8))(iStack_90,"Parameter set: %s\n",uVar15);
  if (iStack_64 == *(int *)puStack_8c) {
    return (int *)0x1;
  }
  pcStack_84 = gost94_param_encode;
  (**(code **)(puStack_70 + -0x5330))();
  puStack_114 = PTR___stack_chk_guard_006a9ae8;
  puStack_a8 = &_gp;
  piStack_9c = *(int **)PTR___stack_chk_guard_006a9ae8;
  iStack_d0 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  uStack_a0 = (**(code **)(puStack_a8 + -0x7c2c))();
  puStack_d4 = *(undefined4 **)(puStack_a8 + -0x57e4);
  puStack_cc = &uStack_a0;
  if (puStack_d4[3] == 0) {
LAB_0061a5b4:
    (**(code **)(puStack_a8 + -0x7dc4))(uStack_a0);
    uVar15 = 0;
  }
  else {
    pcVar16 = *(code **)(puStack_a8 + -0x6fb0);
    puVar14 = puStack_d4;
    while( true ) {
      (*pcVar16)(puStack_cc);
      iVar2 = (**(code **)(puStack_a8 + -0x7480))(uStack_a0,*(undefined4 *)(iStack_d0 + 0x10));
      if (iVar2 == 0) break;
      puStack_d4 = puVar14 + 4;
      if (puVar14[7] == 0) goto LAB_0061a5b4;
      pcVar16 = *(code **)(puStack_a8 + -0x6fb0);
      puVar14 = puStack_d4;
    }
    (**(code **)(puStack_a8 + -0x7dc4))(uStack_a0);
    uVar15 = *puVar14;
    puStack_d4 = puVar14;
  }
  uVar15 = (**(code **)(puStack_a8 + -0x7ca0))(uVar15);
  piVar3 = (int *)(**(code **)(puStack_a8 + -0x5580))(uVar15,pcStack_c4);
  if (piStack_9c == *(int **)puStack_114) {
    return piVar3;
  }
  pcStack_bc = encode_gost_algor_params;
  piStack_120 = piStack_9c;
  (**(code **)(puStack_a8 + -0x5330))();
  puStack_110 = PTR___stack_chk_guard_006a9ae8;
  puStack_c8 = puStack_114;
  piStack_dc = *(int **)PTR___stack_chk_guard_006a9ae8;
  puStack_c0 = puStack_10c;
  piVar3 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
  piStack_15c = (int *)GOST_KEY_PARAMS_new();
  if ((piVar3 == (int *)0x0) || (piStack_15c == (int *)0x0)) {
    uVar15 = 0x2d;
    piVar8 = (int *)&DAT_00000041;
LAB_0061a834:
    ERR_GOST_error(100,piVar8,"gost_ameth.c",uVar15);
    piStack_160 = (int *)0x0;
    (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar3);
  }
  else {
    iVar2 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(piStack_120);
    if (iVar2 == 0x32b) {
      uVar15 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(piStack_120);
      uVar15 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar15);
      iVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar15);
    }
    else {
      if (iVar2 == 0x32c) {
        puStack_114 = (undefined *)(*(code *)PTR_EVP_PKEY_get0_006a95d8)(piStack_120);
        uStack_e0 = (*(code *)PTR_BN_new_006a71b4)();
        puStack_10c = &uStack_e0;
        iVar2 = *(int *)(PTR_R3410_paramset_006a95fc + 0xc);
        piStack_120 = (int *)PTR_R3410_paramset_006a95fc;
        while (iVar2 != 0) {
          (*(code *)PTR_BN_dec2bn_006a7e30)(puStack_10c);
          iVar2 = (*(code *)PTR_BN_cmp_006a7960)(uStack_e0,*(undefined4 *)(puStack_114 + 0x10));
          if (iVar2 == 0) {
            (*(code *)PTR_BN_free_006a701c)(uStack_e0);
            iVar2 = *piStack_120;
            if (iVar2 != 0) goto LAB_0061a6b8;
            goto LAB_0061a824;
          }
          iVar2 = piStack_120[7];
          piStack_120 = piStack_120 + 4;
        }
        (*(code *)PTR_BN_free_006a701c)(uStack_e0);
LAB_0061a824:
        uVar15 = 0x3d;
        piVar8 = (int *)&DAT_0000006d;
        goto LAB_0061a834;
      }
      iVar2 = 0;
    }
LAB_0061a6b8:
    iVar2 = (*(code *)PTR_OBJ_nid2obj_006a7140)(iVar2);
    puVar6 = PTR_OBJ_nid2obj_006a7140;
    *piStack_15c = iVar2;
    iVar2 = (*(code *)puVar6)(0x336);
    piVar8 = piVar3 + 2;
    piStack_15c[1] = iVar2;
    iVar2 = i2d_GOST_KEY_PARAMS(piStack_15c);
    *piVar3 = iVar2;
    if (iVar2 < 1) {
      uVar15 = 0x4b;
      piVar8 = (int *)&DAT_00000041;
      goto LAB_0061a834;
    }
    piVar3[1] = 0x10;
    piStack_160 = piVar3;
  }
  GOST_KEY_PARAMS_free(piStack_15c);
  if (piStack_dc == *(int **)puStack_110) {
    return piStack_160;
  }
  piStack_130 = piStack_dc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1b0 = PTR___stack_chk_guard_006a9ae8;
  puStack_138 = &_gp;
  uStack_128 = 0;
  piStack_124 = *(int **)PTR___stack_chk_guard_006a9ae8;
  piStack_11c = piStack_160;
  piStack_118 = piStack_15c;
  uVar15 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(piVar8);
  uVar4 = (**(code **)(puStack_138 + -0x7ed4))(piVar8);
  puStack_1a8 = (undefined4 *)(**(code **)(puStack_138 + -0x7ca0))(uVar4);
  if (piVar8[6] == 0) {
    pcStack_1a4 = (char *)0xffffffff;
    piStack_1a0 = (int *)0x0;
  }
  else {
    piStack_1a0 = (int *)encode_gost_algor_params(piVar8);
    pcStack_1a4 = (char *)0x10;
  }
  iStack_164 = (**(code **)(puStack_138 + -0x7c2c))();
  uVar4 = (**(code **)(puStack_138 + -0x7750))(uVar15);
  (**(code **)(puStack_138 + -0x7bf4))(uVar4,iStack_164,0);
  iStack_1ac = (**(code **)(puStack_138 + -0x72fc))(uVar15);
  if (iStack_1ac == 0) {
    piStack_1b8 = (int *)0x2e4;
    pcVar13 = "gost_ameth.c";
    puVar14 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    piVar3 = (int *)0x0;
  }
  else {
    piStack_160 = (int *)(**(code **)(puStack_138 + -0x7c2c))();
    piStack_15c = (int *)(**(code **)(puStack_138 + -0x7c2c))();
    if (piStack_160 == (int *)0x0) {
      piStack_1b8 = (int *)0x2ea;
      pcVar13 = "gost_ameth.c";
      puVar14 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      if (piStack_15c != (int *)0x0) {
        (**(code **)(puStack_138 + -0x7dc4))(piStack_15c);
      }
    }
    else {
      if (piStack_15c != (int *)0x0) {
        uVar15 = (**(code **)(puStack_138 + -0x7750))(uVar15);
        uStack_140 = 0;
        piStack_1b8 = piStack_15c;
        piVar3 = (int *)(**(code **)(puStack_138 + -0x6748))(uVar15,iStack_1ac,piStack_160);
        if (piVar3 == (int *)0x0) {
          piStack_1b8 = (int *)0x2f2;
          pcVar13 = "gost_ameth.c";
          puVar14 = (undefined4 *)0x44;
          piStack_130 = piVar3;
          ERR_GOST_error(0x87);
          (**(code **)(puStack_138 + -0x7dc4))(piStack_160);
          (**(code **)(puStack_138 + -0x7dc4))(piStack_15c);
          (**(code **)(puStack_138 + -0x7dc4))(iStack_164);
          piVar3 = piStack_130;
        }
        else {
          iVar5 = (**(code **)(puStack_138 + -0x7bec))(iStack_164);
          iVar2 = iVar5 + 7;
          if (iVar5 + 7 < 0) {
            iVar2 = iVar5 + 0xe;
          }
          iVar2 = iVar2 >> 3;
          (**(code **)(puStack_138 + -0x7dc4))(iStack_164);
          pcVar17 = (char *)(iVar2 << 1);
          iStack_1ac = (**(code **)(puStack_138 + -0x7dd8))(pcVar17,"gost_ameth.c",0x2fa);
          (**(code **)(puStack_138 + -0x53ec))(iStack_1ac,0,pcVar17);
          iStack_12c = iStack_1ac + iVar2;
          (**(code **)(puStack_138 + -0x55cc))(piStack_160,iStack_12c,iVar2);
          (**(code **)(puStack_138 + -0x55cc))(piStack_15c,iStack_1ac,iVar2);
          (**(code **)(puStack_138 + -0x7dc4))(piStack_160);
          (**(code **)(puStack_138 + -0x7dc4))(piStack_15c);
          piStack_160 = (int *)(**(code **)(puStack_138 + -0x6778))();
          pcVar13 = pcVar17;
          (**(code **)(puStack_138 + -0x70c4))(piStack_160,0);
          puVar6 = (undefined *)(**(code **)(puStack_138 + -0x7ab0))(piStack_160);
          iVar2 = iStack_12c + iVar2;
          if (0 < (int)pcVar17) {
            do {
              puVar1 = (undefined *)(iVar2 + -1);
              iVar2 = iVar2 + -1;
              *puVar6 = *puVar1;
              puVar6 = puVar6 + 1;
            } while (iStack_1ac != iVar2);
          }
          (**(code **)(puStack_138 + -0x7f58))(iStack_1ac);
          puVar14 = &uStack_128;
          iStack_164 = (**(code **)(puStack_138 + -0x6a00))(piStack_160);
          (**(code **)(puStack_138 + -0x6770))(piStack_160);
          if (iStack_164 < 0) {
            piVar3 = (int *)0x0;
          }
          else {
            uStack_140 = uStack_128;
            puVar14 = puStack_1a8;
            pcVar13 = pcStack_1a4;
            piStack_1b8 = piStack_1a0;
            iStack_13c = iStack_164;
            piVar3 = (int *)(**(code **)(puStack_138 + -0x6638))(piStack_130);
          }
        }
        goto LAB_0061ab6c;
      }
      piStack_1b8 = (int *)0x2ea;
      pcVar13 = "gost_ameth.c";
      puVar14 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      (**(code **)(puStack_138 + -0x7dc4))(piStack_160);
    }
    (**(code **)(puStack_138 + -0x7dc4))(iStack_164);
    piVar3 = (int *)0x0;
  }
LAB_0061ab6c:
  if (piStack_124 == *(int **)puStack_1b0) {
    return piVar3;
  }
  pcStack_154 = pkey_ctrl_gost;
  piStack_1b4 = piStack_124;
  (**(code **)(puStack_138 + -0x5330))();
  puStack_1bc = PTR___stack_chk_guard_006a9ae8;
  puStack_158 = puStack_1b0;
  puStack_180 = &_gp;
  iStack_16c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuVar7 = &switchD_0061ad28::switchdataD_0067a7d0 + (int)puVar14;
  piVar3 = piStack_1b8;
  switch(puVar14) {
  default:
    piVar8 = (int *)&SUB_fffffffe;
    break;
  case (undefined4 *)0x1:
    piVar8 = (int *)0x1;
    if (pcVar13 == (char *)0x0) {
      piStack_174 = (int *)0x0;
      piStack_170 = (int *)0x0;
      piVar3 = (int *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      (**(code **)(puStack_180 + -0x5728))(piStack_1b8,0,&piStack_174,&piStack_170);
LAB_0061ad7c:
      piStack_1b4 = piStack_174;
      ppuVar7 = (undefined **)(**(code **)(puStack_180 + -0x7ca0))(0x329);
      (**(code **)(puStack_180 + -0x60fc))(piStack_1b4,ppuVar7,5,0);
      piStack_1b8 = piStack_170;
      if (piVar3 == (int *)0x0) goto LAB_0061aef4;
      ppuVar7 = (undefined **)(**(code **)(puStack_180 + -0x7ca0))(piVar3);
      puVar6 = (undefined *)0x0;
      uVar15 = 5;
      pcVar16 = *(code **)(puStack_180 + -0x60fc);
LAB_0061ae24:
      (*pcVar16)(piStack_1b8,ppuVar7,uVar15,puVar6);
      piVar8 = (int *)0x1;
    }
    break;
  case (undefined4 *)0x2:
    piVar8 = (int *)0x1;
    if (pcVar13 == (char *)0x0) {
      puStack_1b0 = (undefined *)encode_gost_algor_params();
      if (puStack_1b0 == (undefined *)0x0) goto LAB_0061aef4;
      (**(code **)(puStack_180 + -0x56bc))(piStack_1b8,&piStack_170);
      puVar6 = puStack_1b0;
LAB_0061ae04:
      piStack_1b8 = piStack_170;
      ppuVar7 = (undefined **)(**(code **)(puStack_180 + -0x7ca0))(*piStack_1b4);
      uVar15 = 0x10;
      pcVar16 = *(code **)(puStack_180 + -0x60fc);
      puStack_1b0 = puVar6;
      goto LAB_0061ae24;
    }
    break;
  case (undefined4 *)0x3:
    piVar8 = (int *)&SUB_00000002;
    *piStack_1b8 = 0x329;
    break;
  case (undefined4 *)0x5:
    piVar8 = (int *)0x1;
    if (pcVar13 == (char *)0x0) {
      piStack_174 = (int *)0x0;
      piStack_170 = (int *)0x0;
      piVar3 = (int *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      ppiStack_188 = &piStack_170;
      (**(code **)(puStack_180 + -0x5acc))(piStack_1b8,0,0,&piStack_174);
      goto LAB_0061ad7c;
    }
    break;
  case (undefined4 *)0x7:
    piVar8 = (int *)0x1;
    if (pcVar13 == (char *)0x0) {
      piStack_170 = (int *)0x0;
      puStack_1b0 = (undefined *)encode_gost_algor_params();
      if (puStack_1b0 != (undefined *)0x0) {
        (**(code **)(puStack_180 + -0x56c0))(piStack_1b8,0,0,&piStack_170);
        puVar6 = puStack_1b0;
        goto LAB_0061ae04;
      }
LAB_0061aef4:
      piStack_1b8 = piVar3;
      piVar8 = (int *)0xffffffff;
    }
  }
  if (iStack_16c == *(int *)puStack_1bc) {
    return piVar8;
  }
  pcStack_19c = pub_encode_gost94;
  iStack_244 = iStack_16c;
  (**(code **)(puStack_180 + -0x5330))();
  puStack_1fc = PTR___stack_chk_guard_006a9ae8;
  puStack_1d0 = &_gp;
  uStack_1c8 = 0;
  iStack_1c4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(ppuVar7);
  uVar15 = (**(code **)(puStack_1d0 + -0x7ed4))(ppuVar7);
  puStack_1f4 = (undefined4 *)(**(code **)(puStack_1d0 + -0x7ca0))(uVar15);
  if (ppuVar7[6] == (undefined *)0x0) {
    pcStack_1f0 = (char *)0xffffffff;
    uStack_238 = 0;
  }
  else {
    uStack_238 = encode_gost_algor_params(ppuVar7);
    pcStack_1f0 = (char *)0x10;
  }
  iVar9 = (**(code **)(puStack_1d0 + -0x7bec))(*(undefined4 *)(iVar2 + 0x18));
  iVar5 = iVar9 + 7;
  if (iVar9 + 7 < 0) {
    iVar5 = iVar9 + 0xe;
  }
  pcVar17 = (char *)(iVar5 >> 3);
  iVar5 = (**(code **)(puStack_1d0 + -0x7dd8))(pcVar17,"gost_ameth.c",0x288);
  (**(code **)(puStack_1d0 + -0x7be0))(*(undefined4 *)(iVar2 + 0x18),iVar5);
  uVar15 = (**(code **)(puStack_1d0 + -0x6778))();
  pcVar13 = pcVar17;
  (**(code **)(puStack_1d0 + -0x70c4))(uVar15,0);
  puVar6 = (undefined *)(**(code **)(puStack_1d0 + -0x7ab0))(uVar15);
  iVar2 = iVar5 + (int)pcVar17;
  if (0 < (int)pcVar17) {
    do {
      puVar1 = (undefined *)(iVar2 + -1);
      iVar2 = iVar2 + -1;
      *puVar6 = *puVar1;
      puVar6 = puVar6 + 1;
    } while (iVar5 != iVar2);
  }
  (**(code **)(puStack_1d0 + -0x7f58))(iVar5);
  puStack_24c = &uStack_1c8;
  iStack_200 = (**(code **)(puStack_1d0 + -0x6a00))(uVar15);
  (**(code **)(puStack_1d0 + -0x6770))(uVar15);
  if (iStack_200 < 0) {
    piVar3 = (int *)0x0;
  }
  else {
    uStack_1d8 = uStack_1c8;
    puStack_24c = puStack_1f4;
    pcVar13 = pcStack_1f0;
    iStack_1d4 = iStack_200;
    piVar3 = (int *)(**(code **)(puStack_1d0 + -0x6638))
                              (iStack_244,puStack_1f4,pcStack_1f0,uStack_238);
  }
  if (iStack_1c4 == *(int *)puStack_1fc) {
    return piVar3;
  }
  pcStack_1ec = priv_encode_gost;
  iStack_240 = iStack_1c4;
  (**(code **)(puStack_1d0 + -0x5330))();
  puStack_248 = PTR___stack_chk_guard_006a9ae8;
  puStack_210 = &_gp;
  iStack_204 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar14 = puStack_24c;
  iStack_1f8 = iStack_244;
  uVar15 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puStack_24c);
  puStack_23c = (undefined4 *)(**(code **)(puStack_210 + -0x7ca0))(uVar15);
  iVar2 = encode_gost_algor_params(puStack_24c);
  uStack_208 = 0;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    iVar5 = (**(code **)(puStack_210 + -0x7ed4))(puStack_24c);
    if (iVar5 == 0x32b) {
      iVar5 = (**(code **)(puStack_210 + -0x5808))(puStack_24c);
      if (iVar5 == 0) goto LAB_0061b1b4;
      uVar15 = (**(code **)(puStack_210 + -0x6e68))(iVar5);
    }
    else if ((iVar5 == 0x32c) &&
            (iVar5 = (**(code **)(puStack_210 + -0x5808))(puStack_24c), iVar5 != 0)) {
      uVar15 = *(undefined4 *)(iVar5 + 0x1c);
    }
    else {
LAB_0061b1b4:
      uVar15 = 0;
    }
    uVar15 = (**(code **)(puStack_210 + -0x7cec))(uVar15,0);
    puStack_24c = (undefined4 *)(**(code **)(puStack_210 + -0x6a04))(uVar15,&uStack_208);
    (**(code **)(puStack_210 + -0x7f4c))(uVar15);
    pcVar13 = (char *)0x0;
    uStack_21c = uStack_208;
    puVar14 = puStack_23c;
    iStack_220 = iVar2;
    puStack_218 = puStack_24c;
    piVar3 = (int *)(**(code **)(puStack_210 + -0x6648))(iStack_240,puStack_23c,0,0x10);
    iStack_244 = iVar2;
  }
  if (iStack_204 == *(int *)puStack_248) {
    return piVar3;
  }
  pcStack_234 = priv_print_gost94;
  iVar2 = iStack_204;
  (**(code **)(puStack_210 + -0x5330))();
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  iVar5 = 0x80;
  iStack_254 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar17 = pcVar13;
  piVar3 = (int *)(*(code *)PTR_BIO_indent_006a86ac)();
  if (piVar3 == (int *)0x0) goto LAB_0061b304;
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"Private key: ");
  iVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puVar14);
  if (iVar5 == 0x32b) {
    iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
    if ((iVar5 != 0) && (iVar5 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar5), iVar5 != 0)
       ) goto LAB_0061b4fc;
LAB_0061b370:
    (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"<undefined>");
  }
  else {
    if ((iVar5 != 0x32c) ||
       ((iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14), iVar5 == 0 ||
        (iVar5 = *(int *)(iVar5 + 0x1c), iVar5 == 0)))) goto LAB_0061b370;
LAB_0061b4fc:
    (*(code *)PTR_BN_print_006a6f24)(iVar2,iVar5);
  }
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
  uVar15 = *(undefined4 *)(iVar5 + 0x18);
  (*(code *)PTR_BIO_indent_006a86ac)(iVar2,pcVar13,0x80);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"Public key: ");
  (*(code *)PTR_BN_print_006a6f24)(iVar2,uVar15);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
  uStack_258 = (*(code *)PTR_BN_new_006a71b4)();
  if (*(int *)(PTR_R3410_paramset_006a95fc + 0xc) != 0) {
    puVar14 = (undefined4 *)PTR_R3410_paramset_006a95fc;
    do {
      (*(code *)PTR_BN_dec2bn_006a7e30)(&uStack_258);
      iVar9 = (*(code *)PTR_BN_cmp_006a7960)(uStack_258,*(undefined4 *)(iVar5 + 0x10));
      if (iVar9 == 0) {
        (*(code *)PTR_BN_free_006a701c)(uStack_258);
        uVar15 = *puVar14;
        goto LAB_0061b494;
      }
      piVar3 = puVar14 + 7;
      puVar14 = puVar14 + 4;
    } while (*piVar3 != 0);
  }
  uVar15 = 0;
  (*(code *)PTR_BN_free_006a701c)(uStack_258);
LAB_0061b494:
  (*(code *)PTR_BIO_indent_006a86ac)(iVar2,pcVar13,0x80);
  iVar5 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar15);
  pcVar17 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"Parameter set: %s\n",iVar5);
  piVar3 = (int *)0x1;
LAB_0061b304:
  if (iStack_254 == *(int *)puVar6) {
    return piVar3;
  }
  iVar2 = iStack_254;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar9 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar9 != 0) {
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar9);
    uVar15 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar9);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar9);
    uVar10 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
    uVar10 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(uVar10);
    uVar11 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
    uVar11 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar11);
    iVar12 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                       (uVar11,uVar10,uVar15,uVar4,iVar9);
    if (iVar12 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1c2);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar9);
      return (int *)0x0;
    }
    iVar12 = (*(code *)PTR_BIO_indent_006a86ac)(iVar2,iVar5,0x80);
    if (iVar12 != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"Public key:\n");
      iVar12 = (*(code *)PTR_BIO_indent_006a86ac)(iVar2,iVar5 + 3,0x80);
      if (iVar12 != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(iVar2,&DAT_0067a7b4);
        (*(code *)PTR_BN_print_006a6f24)(iVar2,uVar15);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"\n");
        (*(code *)PTR_BIO_indent_006a86ac)(iVar2,iVar5 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar2,&DAT_0067a7b8);
        (*(code *)PTR_BN_print_006a6f24)(iVar2,uVar4);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"\n");
        (*(code *)PTR_BN_CTX_end_006a8530)(iVar9);
        (*(code *)PTR_BN_CTX_free_006a7954)(iVar9);
        uVar15 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
        uVar15 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar15);
        uVar15 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar15);
        iVar5 = (*(code *)PTR_BIO_indent_006a86ac)(iVar2,iVar5,0x80);
        if (iVar5 != 0) {
          uVar15 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar15);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"Parameter set: %s\n",uVar15);
          return (int *)0x1;
        }
      }
    }
    return (int *)0x0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1b8);
  return (int *)0x0;
}

