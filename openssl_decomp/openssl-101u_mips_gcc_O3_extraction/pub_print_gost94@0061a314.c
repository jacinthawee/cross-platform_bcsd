
/* WARNING: Type propagation algorithm not settling */

int * pub_print_gost94(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  undefined4 *puVar13;
  char *pcVar14;
  undefined4 uVar15;
  code *pcVar16;
  char *pcVar17;
  undefined4 uStack_218;
  int iStack_214;
  undefined4 *puStack_20c;
  undefined *puStack_208;
  int iStack_204;
  int iStack_200;
  undefined4 *puStack_1fc;
  undefined4 uStack_1f8;
  code *pcStack_1f4;
  int iStack_1e0;
  undefined4 uStack_1dc;
  undefined4 *puStack_1d8;
  undefined *puStack_1d0;
  undefined4 uStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  undefined *puStack_1bc;
  int iStack_1b8;
  undefined4 *puStack_1b4;
  char *pcStack_1b0;
  code *pcStack_1ac;
  undefined4 uStack_198;
  int iStack_194;
  undefined *puStack_190;
  undefined4 uStack_188;
  int iStack_184;
  undefined *puStack_17c;
  int *piStack_178;
  int *piStack_174;
  undefined *puStack_170;
  int iStack_16c;
  undefined4 *puStack_168;
  char *pcStack_164;
  int *piStack_160;
  code *pcStack_15c;
  int **ppiStack_148;
  undefined *puStack_140;
  int *piStack_134;
  int *piStack_130;
  int iStack_12c;
  int iStack_124;
  int *piStack_120;
  int *piStack_11c;
  undefined *puStack_118;
  code *pcStack_114;
  undefined4 uStack_100;
  int iStack_fc;
  undefined *puStack_f8;
  int *piStack_f0;
  int iStack_ec;
  undefined4 uStack_e8;
  int *piStack_e4;
  int *piStack_e0;
  int *piStack_dc;
  int *piStack_d8;
  undefined *puStack_d4;
  undefined *puStack_d0;
  undefined4 *puStack_cc;
  undefined4 uStack_a0;
  int *piStack_9c;
  undefined4 *puStack_94;
  int iStack_90;
  undefined4 *puStack_8c;
  undefined *puStack_88;
  char *pcStack_84;
  undefined4 *puStack_80;
  code *pcStack_7c;
  undefined *puStack_68;
  undefined4 uStack_60;
  int *piStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined *puStack_4c;
  undefined4 uStack_48;
  code *pcStack_44;
  undefined *local_30;
  undefined4 local_28;
  int local_24;
  
  puStack_4c = PTR___stack_chk_guard_006a9ae8;
  local_30 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  uVar15 = *(undefined4 *)(iVar2 + 0x18);
  (**(code **)(local_30 + -0x6734))(param_1,param_3,0x80);
  (**(code **)(local_30 + -0x7fa8))(param_1,"Public key: ");
  (**(code **)(local_30 + -0x7ebc))(param_1,uVar15);
  (**(code **)(local_30 + -0x7fa8))(param_1,"\n");
  iStack_54 = (**(code **)(local_30 + -0x5808))(param_2);
  local_28 = (**(code **)(local_30 + -0x7c2c))();
  puStack_cc = &local_28;
  if ((*(undefined4 **)(local_30 + -0x57e4))[3] == 0) {
LAB_0061a458:
    uStack_58 = 0;
    (**(code **)(local_30 + -0x7dc4))(local_28);
  }
  else {
    pcVar16 = *(code **)(local_30 + -0x6fb0);
    puVar13 = *(undefined4 **)(local_30 + -0x57e4);
    while( true ) {
      (*pcVar16)(puStack_cc);
      iVar2 = (**(code **)(local_30 + -0x7480))(local_28,*(undefined4 *)(iStack_54 + 0x10));
      if (iVar2 == 0) break;
      if (puVar13[7] == 0) goto LAB_0061a458;
      pcVar16 = *(code **)(local_30 + -0x6fb0);
      puVar13 = puVar13 + 4;
    }
    (**(code **)(local_30 + -0x7dc4))(local_28);
    uStack_58 = *puVar13;
  }
  (**(code **)(local_30 + -0x6734))(param_1,param_3,0x80);
  uVar15 = (**(code **)(local_30 + -0x7cc4))(uStack_58);
  pcStack_84 = "Parameter set: %s\n";
  (**(code **)(local_30 + -0x7fa8))(param_1,"Parameter set: %s\n",uVar15);
  if (local_24 == *(int *)puStack_4c) {
    return (int *)0x1;
  }
  pcStack_44 = gost94_param_encode;
  (**(code **)(local_30 + -0x5330))();
  puStack_d4 = PTR___stack_chk_guard_006a9ae8;
  puStack_68 = &_gp;
  piStack_5c = *(int **)PTR___stack_chk_guard_006a9ae8;
  uStack_50 = param_1;
  uStack_48 = param_3;
  iStack_90 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  uStack_60 = (**(code **)(puStack_68 + -0x7c2c))();
  puStack_94 = *(undefined4 **)(puStack_68 + -0x57e4);
  puStack_8c = &uStack_60;
  if (puStack_94[3] == 0) {
LAB_0061a5b4:
    (**(code **)(puStack_68 + -0x7dc4))(uStack_60);
    uVar15 = 0;
  }
  else {
    pcVar16 = *(code **)(puStack_68 + -0x6fb0);
    puVar13 = puStack_94;
    while( true ) {
      (*pcVar16)(puStack_8c);
      iVar2 = (**(code **)(puStack_68 + -0x7480))(uStack_60,*(undefined4 *)(iStack_90 + 0x10));
      if (iVar2 == 0) break;
      puStack_94 = puVar13 + 4;
      if (puVar13[7] == 0) goto LAB_0061a5b4;
      pcVar16 = *(code **)(puStack_68 + -0x6fb0);
      puVar13 = puStack_94;
    }
    (**(code **)(puStack_68 + -0x7dc4))(uStack_60);
    uVar15 = *puVar13;
    puStack_94 = puVar13;
  }
  uVar15 = (**(code **)(puStack_68 + -0x7ca0))(uVar15);
  piVar3 = (int *)(**(code **)(puStack_68 + -0x5580))(uVar15,pcStack_84);
  if (piStack_5c == *(int **)puStack_d4) {
    return piVar3;
  }
  pcStack_7c = encode_gost_algor_params;
  piStack_e0 = piStack_5c;
  (**(code **)(puStack_68 + -0x5330))();
  puStack_d0 = PTR___stack_chk_guard_006a9ae8;
  puStack_88 = puStack_d4;
  piStack_9c = *(int **)PTR___stack_chk_guard_006a9ae8;
  puStack_80 = puStack_cc;
  piVar3 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
  piStack_11c = (int *)GOST_KEY_PARAMS_new();
  if ((piVar3 == (int *)0x0) || (piStack_11c == (int *)0x0)) {
    uVar15 = 0x2d;
    piVar8 = (int *)&DAT_00000041;
LAB_0061a834:
    ERR_GOST_error(100,piVar8,"gost_ameth.c",uVar15);
    piStack_120 = (int *)0x0;
    (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar3);
  }
  else {
    iVar2 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(piStack_e0);
    if (iVar2 == 0x32b) {
      uVar15 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(piStack_e0);
      uVar15 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar15);
      iVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar15);
    }
    else {
      if (iVar2 == 0x32c) {
        puStack_d4 = (undefined *)(*(code *)PTR_EVP_PKEY_get0_006a95d8)(piStack_e0);
        uStack_a0 = (*(code *)PTR_BN_new_006a71b4)();
        puStack_cc = &uStack_a0;
        iVar2 = *(int *)(PTR_R3410_paramset_006a95fc + 0xc);
        piStack_e0 = (int *)PTR_R3410_paramset_006a95fc;
        while (iVar2 != 0) {
          (*(code *)PTR_BN_dec2bn_006a7e30)(puStack_cc);
          iVar2 = (*(code *)PTR_BN_cmp_006a7960)(uStack_a0,*(undefined4 *)(puStack_d4 + 0x10));
          if (iVar2 == 0) {
            (*(code *)PTR_BN_free_006a701c)(uStack_a0);
            iVar2 = *piStack_e0;
            if (iVar2 != 0) goto LAB_0061a6b8;
            goto LAB_0061a824;
          }
          iVar2 = piStack_e0[7];
          piStack_e0 = piStack_e0 + 4;
        }
        (*(code *)PTR_BN_free_006a701c)(uStack_a0);
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
    *piStack_11c = iVar2;
    iVar2 = (*(code *)puVar6)(0x336);
    piVar8 = piVar3 + 2;
    piStack_11c[1] = iVar2;
    iVar2 = i2d_GOST_KEY_PARAMS(piStack_11c);
    *piVar3 = iVar2;
    if (iVar2 < 1) {
      uVar15 = 0x4b;
      piVar8 = (int *)&DAT_00000041;
      goto LAB_0061a834;
    }
    piVar3[1] = 0x10;
    piStack_120 = piVar3;
  }
  GOST_KEY_PARAMS_free(piStack_11c);
  if (piStack_9c == *(int **)puStack_d0) {
    return piStack_120;
  }
  piStack_f0 = piStack_9c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_170 = PTR___stack_chk_guard_006a9ae8;
  puStack_f8 = &_gp;
  uStack_e8 = 0;
  piStack_e4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  piStack_dc = piStack_120;
  piStack_d8 = piStack_11c;
  uVar15 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(piVar8);
  uVar4 = (**(code **)(puStack_f8 + -0x7ed4))(piVar8);
  puStack_168 = (undefined4 *)(**(code **)(puStack_f8 + -0x7ca0))(uVar4);
  if (piVar8[6] == 0) {
    pcStack_164 = (char *)0xffffffff;
    piStack_160 = (int *)0x0;
  }
  else {
    piStack_160 = (int *)encode_gost_algor_params(piVar8);
    pcStack_164 = (char *)0x10;
  }
  iStack_124 = (**(code **)(puStack_f8 + -0x7c2c))();
  uVar4 = (**(code **)(puStack_f8 + -0x7750))(uVar15);
  (**(code **)(puStack_f8 + -0x7bf4))(uVar4,iStack_124,0);
  iStack_16c = (**(code **)(puStack_f8 + -0x72fc))(uVar15);
  if (iStack_16c == 0) {
    piStack_178 = (int *)0x2e4;
    pcVar14 = "gost_ameth.c";
    puVar13 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    piVar3 = (int *)0x0;
  }
  else {
    piStack_120 = (int *)(**(code **)(puStack_f8 + -0x7c2c))();
    piStack_11c = (int *)(**(code **)(puStack_f8 + -0x7c2c))();
    if (piStack_120 == (int *)0x0) {
      piStack_178 = (int *)0x2ea;
      pcVar14 = "gost_ameth.c";
      puVar13 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      if (piStack_11c != (int *)0x0) {
        (**(code **)(puStack_f8 + -0x7dc4))(piStack_11c);
      }
    }
    else {
      if (piStack_11c != (int *)0x0) {
        uVar15 = (**(code **)(puStack_f8 + -0x7750))(uVar15);
        uStack_100 = 0;
        piStack_178 = piStack_11c;
        piVar3 = (int *)(**(code **)(puStack_f8 + -0x6748))(uVar15,iStack_16c,piStack_120);
        if (piVar3 == (int *)0x0) {
          piStack_178 = (int *)0x2f2;
          pcVar14 = "gost_ameth.c";
          puVar13 = (undefined4 *)0x44;
          piStack_f0 = piVar3;
          ERR_GOST_error(0x87);
          (**(code **)(puStack_f8 + -0x7dc4))(piStack_120);
          (**(code **)(puStack_f8 + -0x7dc4))(piStack_11c);
          (**(code **)(puStack_f8 + -0x7dc4))(iStack_124);
          piVar3 = piStack_f0;
        }
        else {
          iVar5 = (**(code **)(puStack_f8 + -0x7bec))(iStack_124);
          iVar2 = iVar5 + 7;
          if (iVar5 + 7 < 0) {
            iVar2 = iVar5 + 0xe;
          }
          iVar2 = iVar2 >> 3;
          (**(code **)(puStack_f8 + -0x7dc4))(iStack_124);
          pcVar17 = (char *)(iVar2 << 1);
          iStack_16c = (**(code **)(puStack_f8 + -0x7dd8))(pcVar17,"gost_ameth.c",0x2fa);
          (**(code **)(puStack_f8 + -0x53ec))(iStack_16c,0,pcVar17);
          iStack_ec = iStack_16c + iVar2;
          (**(code **)(puStack_f8 + -0x55cc))(piStack_120,iStack_ec,iVar2);
          (**(code **)(puStack_f8 + -0x55cc))(piStack_11c,iStack_16c,iVar2);
          (**(code **)(puStack_f8 + -0x7dc4))(piStack_120);
          (**(code **)(puStack_f8 + -0x7dc4))(piStack_11c);
          piStack_120 = (int *)(**(code **)(puStack_f8 + -0x6778))();
          pcVar14 = pcVar17;
          (**(code **)(puStack_f8 + -0x70c4))(piStack_120,0);
          puVar6 = (undefined *)(**(code **)(puStack_f8 + -0x7ab0))(piStack_120);
          iVar2 = iStack_ec + iVar2;
          if (0 < (int)pcVar17) {
            do {
              puVar1 = (undefined *)(iVar2 + -1);
              iVar2 = iVar2 + -1;
              *puVar6 = *puVar1;
              puVar6 = puVar6 + 1;
            } while (iStack_16c != iVar2);
          }
          (**(code **)(puStack_f8 + -0x7f58))(iStack_16c);
          puVar13 = &uStack_e8;
          iStack_124 = (**(code **)(puStack_f8 + -0x6a00))(piStack_120);
          (**(code **)(puStack_f8 + -0x6770))(piStack_120);
          if (iStack_124 < 0) {
            piVar3 = (int *)0x0;
          }
          else {
            uStack_100 = uStack_e8;
            puVar13 = puStack_168;
            pcVar14 = pcStack_164;
            piStack_178 = piStack_160;
            iStack_fc = iStack_124;
            piVar3 = (int *)(**(code **)(puStack_f8 + -0x6638))(piStack_f0);
          }
        }
        goto LAB_0061ab6c;
      }
      piStack_178 = (int *)0x2ea;
      pcVar14 = "gost_ameth.c";
      puVar13 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      (**(code **)(puStack_f8 + -0x7dc4))(piStack_120);
    }
    (**(code **)(puStack_f8 + -0x7dc4))(iStack_124);
    piVar3 = (int *)0x0;
  }
LAB_0061ab6c:
  if (piStack_e4 == *(int **)puStack_170) {
    return piVar3;
  }
  pcStack_114 = pkey_ctrl_gost;
  piStack_174 = piStack_e4;
  (**(code **)(puStack_f8 + -0x5330))();
  puStack_17c = PTR___stack_chk_guard_006a9ae8;
  puStack_118 = puStack_170;
  puStack_140 = &_gp;
  iStack_12c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuVar7 = &switchD_0061ad28::switchdataD_0067a7d0 + (int)puVar13;
  piVar3 = piStack_178;
  switch(puVar13) {
  default:
    piVar8 = (int *)&SUB_fffffffe;
    break;
  case (undefined4 *)0x1:
    piVar8 = (int *)0x1;
    if (pcVar14 == (char *)0x0) {
      piStack_134 = (int *)0x0;
      piStack_130 = (int *)0x0;
      piVar3 = (int *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      (**(code **)(puStack_140 + -0x5728))(piStack_178,0,&piStack_134,&piStack_130);
LAB_0061ad7c:
      piStack_174 = piStack_134;
      ppuVar7 = (undefined **)(**(code **)(puStack_140 + -0x7ca0))(0x329);
      (**(code **)(puStack_140 + -0x60fc))(piStack_174,ppuVar7,5,0);
      piStack_178 = piStack_130;
      if (piVar3 == (int *)0x0) goto LAB_0061aef4;
      ppuVar7 = (undefined **)(**(code **)(puStack_140 + -0x7ca0))(piVar3);
      puVar6 = (undefined *)0x0;
      uVar15 = 5;
      pcVar16 = *(code **)(puStack_140 + -0x60fc);
LAB_0061ae24:
      (*pcVar16)(piStack_178,ppuVar7,uVar15,puVar6);
      piVar8 = (int *)0x1;
    }
    break;
  case (undefined4 *)0x2:
    piVar8 = (int *)0x1;
    if (pcVar14 == (char *)0x0) {
      puStack_170 = (undefined *)encode_gost_algor_params();
      if (puStack_170 == (undefined *)0x0) goto LAB_0061aef4;
      (**(code **)(puStack_140 + -0x56bc))(piStack_178,&piStack_130);
      puVar6 = puStack_170;
LAB_0061ae04:
      piStack_178 = piStack_130;
      ppuVar7 = (undefined **)(**(code **)(puStack_140 + -0x7ca0))(*piStack_174);
      uVar15 = 0x10;
      pcVar16 = *(code **)(puStack_140 + -0x60fc);
      puStack_170 = puVar6;
      goto LAB_0061ae24;
    }
    break;
  case (undefined4 *)0x3:
    piVar8 = (int *)&SUB_00000002;
    *piStack_178 = 0x329;
    break;
  case (undefined4 *)0x5:
    piVar8 = (int *)0x1;
    if (pcVar14 == (char *)0x0) {
      piStack_134 = (int *)0x0;
      piStack_130 = (int *)0x0;
      piVar3 = (int *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      ppiStack_148 = &piStack_130;
      (**(code **)(puStack_140 + -0x5acc))(piStack_178,0,0,&piStack_134);
      goto LAB_0061ad7c;
    }
    break;
  case (undefined4 *)0x7:
    piVar8 = (int *)0x1;
    if (pcVar14 == (char *)0x0) {
      piStack_130 = (int *)0x0;
      puStack_170 = (undefined *)encode_gost_algor_params();
      if (puStack_170 != (undefined *)0x0) {
        (**(code **)(puStack_140 + -0x56c0))(piStack_178,0,0,&piStack_130);
        puVar6 = puStack_170;
        goto LAB_0061ae04;
      }
LAB_0061aef4:
      piStack_178 = piVar3;
      piVar8 = (int *)0xffffffff;
    }
  }
  if (iStack_12c == *(int *)puStack_17c) {
    return piVar8;
  }
  pcStack_15c = pub_encode_gost94;
  iStack_204 = iStack_12c;
  (**(code **)(puStack_140 + -0x5330))();
  puStack_1bc = PTR___stack_chk_guard_006a9ae8;
  puStack_190 = &_gp;
  uStack_188 = 0;
  iStack_184 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(ppuVar7);
  uVar15 = (**(code **)(puStack_190 + -0x7ed4))(ppuVar7);
  puStack_1b4 = (undefined4 *)(**(code **)(puStack_190 + -0x7ca0))(uVar15);
  if (ppuVar7[6] == (undefined *)0x0) {
    pcStack_1b0 = (char *)0xffffffff;
    uStack_1f8 = 0;
  }
  else {
    uStack_1f8 = encode_gost_algor_params(ppuVar7);
    pcStack_1b0 = (char *)0x10;
  }
  iVar9 = (**(code **)(puStack_190 + -0x7bec))(*(undefined4 *)(iVar2 + 0x18));
  iVar5 = iVar9 + 7;
  if (iVar9 + 7 < 0) {
    iVar5 = iVar9 + 0xe;
  }
  pcVar17 = (char *)(iVar5 >> 3);
  iVar5 = (**(code **)(puStack_190 + -0x7dd8))(pcVar17,"gost_ameth.c",0x288);
  (**(code **)(puStack_190 + -0x7be0))(*(undefined4 *)(iVar2 + 0x18),iVar5);
  uVar15 = (**(code **)(puStack_190 + -0x6778))();
  pcVar14 = pcVar17;
  (**(code **)(puStack_190 + -0x70c4))(uVar15,0);
  puVar6 = (undefined *)(**(code **)(puStack_190 + -0x7ab0))(uVar15);
  iVar2 = iVar5 + (int)pcVar17;
  if (0 < (int)pcVar17) {
    do {
      puVar1 = (undefined *)(iVar2 + -1);
      iVar2 = iVar2 + -1;
      *puVar6 = *puVar1;
      puVar6 = puVar6 + 1;
    } while (iVar5 != iVar2);
  }
  (**(code **)(puStack_190 + -0x7f58))(iVar5);
  puStack_20c = &uStack_188;
  iStack_1c0 = (**(code **)(puStack_190 + -0x6a00))(uVar15);
  (**(code **)(puStack_190 + -0x6770))(uVar15);
  if (iStack_1c0 < 0) {
    piVar3 = (int *)0x0;
  }
  else {
    uStack_198 = uStack_188;
    puStack_20c = puStack_1b4;
    pcVar14 = pcStack_1b0;
    iStack_194 = iStack_1c0;
    piVar3 = (int *)(**(code **)(puStack_190 + -0x6638))
                              (iStack_204,puStack_1b4,pcStack_1b0,uStack_1f8);
  }
  if (iStack_184 == *(int *)puStack_1bc) {
    return piVar3;
  }
  pcStack_1ac = priv_encode_gost;
  iStack_200 = iStack_184;
  (**(code **)(puStack_190 + -0x5330))();
  puStack_208 = PTR___stack_chk_guard_006a9ae8;
  puStack_1d0 = &_gp;
  iStack_1c4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar13 = puStack_20c;
  iStack_1b8 = iStack_204;
  uVar15 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puStack_20c);
  puStack_1fc = (undefined4 *)(**(code **)(puStack_1d0 + -0x7ca0))(uVar15);
  iVar2 = encode_gost_algor_params(puStack_20c);
  uStack_1c8 = 0;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    iVar5 = (**(code **)(puStack_1d0 + -0x7ed4))(puStack_20c);
    if (iVar5 == 0x32b) {
      iVar5 = (**(code **)(puStack_1d0 + -0x5808))(puStack_20c);
      if (iVar5 == 0) goto LAB_0061b1b4;
      uVar15 = (**(code **)(puStack_1d0 + -0x6e68))(iVar5);
    }
    else if ((iVar5 == 0x32c) &&
            (iVar5 = (**(code **)(puStack_1d0 + -0x5808))(puStack_20c), iVar5 != 0)) {
      uVar15 = *(undefined4 *)(iVar5 + 0x1c);
    }
    else {
LAB_0061b1b4:
      uVar15 = 0;
    }
    uVar15 = (**(code **)(puStack_1d0 + -0x7cec))(uVar15,0);
    puStack_20c = (undefined4 *)(**(code **)(puStack_1d0 + -0x6a04))(uVar15,&uStack_1c8);
    (**(code **)(puStack_1d0 + -0x7f4c))(uVar15);
    pcVar14 = (char *)0x0;
    uStack_1dc = uStack_1c8;
    puVar13 = puStack_1fc;
    iStack_1e0 = iVar2;
    puStack_1d8 = puStack_20c;
    piVar3 = (int *)(**(code **)(puStack_1d0 + -0x6648))(iStack_200,puStack_1fc,0,0x10);
    iStack_204 = iVar2;
  }
  if (iStack_1c4 == *(int *)puStack_208) {
    return piVar3;
  }
  pcStack_1f4 = priv_print_gost94;
  iVar2 = iStack_1c4;
  (**(code **)(puStack_1d0 + -0x5330))();
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  iVar5 = 0x80;
  iStack_214 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar17 = pcVar14;
  piVar3 = (int *)(*(code *)PTR_BIO_indent_006a86ac)();
  if (piVar3 == (int *)0x0) goto LAB_0061b304;
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"Private key: ");
  iVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puVar13);
  if (iVar5 == 0x32b) {
    iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar13);
    if ((iVar5 != 0) && (iVar5 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar5), iVar5 != 0)
       ) goto LAB_0061b4fc;
LAB_0061b370:
    (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"<undefined>");
  }
  else {
    if ((iVar5 != 0x32c) ||
       ((iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar13), iVar5 == 0 ||
        (iVar5 = *(int *)(iVar5 + 0x1c), iVar5 == 0)))) goto LAB_0061b370;
LAB_0061b4fc:
    (*(code *)PTR_BN_print_006a6f24)(iVar2,iVar5);
  }
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar13);
  uVar15 = *(undefined4 *)(iVar5 + 0x18);
  (*(code *)PTR_BIO_indent_006a86ac)(iVar2,pcVar14,0x80);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"Public key: ");
  (*(code *)PTR_BN_print_006a6f24)(iVar2,uVar15);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar13);
  uStack_218 = (*(code *)PTR_BN_new_006a71b4)();
  if (*(int *)(PTR_R3410_paramset_006a95fc + 0xc) != 0) {
    puVar13 = (undefined4 *)PTR_R3410_paramset_006a95fc;
    do {
      (*(code *)PTR_BN_dec2bn_006a7e30)(&uStack_218);
      iVar9 = (*(code *)PTR_BN_cmp_006a7960)(uStack_218,*(undefined4 *)(iVar5 + 0x10));
      if (iVar9 == 0) {
        (*(code *)PTR_BN_free_006a701c)(uStack_218);
        uVar15 = *puVar13;
        goto LAB_0061b494;
      }
      piVar3 = puVar13 + 7;
      puVar13 = puVar13 + 4;
    } while (*piVar3 != 0);
  }
  uVar15 = 0;
  (*(code *)PTR_BN_free_006a701c)(uStack_218);
LAB_0061b494:
  (*(code *)PTR_BIO_indent_006a86ac)(iVar2,pcVar14,0x80);
  iVar5 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar15);
  pcVar17 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a6e38)(iVar2,"Parameter set: %s\n",iVar5);
  piVar3 = (int *)0x1;
LAB_0061b304:
  if (iStack_214 == *(int *)puVar6) {
    return piVar3;
  }
  iVar2 = iStack_214;
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

