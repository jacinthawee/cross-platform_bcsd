
/* WARNING: Type propagation algorithm not settling */

int * gost94_param_encode(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined **ppuVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 *puVar14;
  char *pcVar15;
  undefined4 *unaff_s5;
  code *pcVar16;
  char *pcVar17;
  undefined4 uStack_1d8;
  int iStack_1d4;
  undefined4 *puStack_1cc;
  undefined *puStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  undefined4 *puStack_1bc;
  undefined4 uStack_1b8;
  code *pcStack_1b4;
  int iStack_1a0;
  undefined4 uStack_19c;
  undefined4 *puStack_198;
  undefined *puStack_190;
  undefined4 uStack_188;
  int iStack_184;
  int iStack_180;
  undefined *puStack_17c;
  int iStack_178;
  undefined4 *puStack_174;
  char *pcStack_170;
  code *pcStack_16c;
  undefined4 uStack_158;
  int iStack_154;
  undefined *puStack_150;
  undefined4 uStack_148;
  int iStack_144;
  undefined *puStack_13c;
  int *piStack_138;
  int *piStack_134;
  undefined *puStack_130;
  int iStack_12c;
  undefined4 *puStack_128;
  char *pcStack_124;
  int *piStack_120;
  code *pcStack_11c;
  int **ppiStack_108;
  undefined *puStack_100;
  int *piStack_f4;
  int *piStack_f0;
  int iStack_ec;
  int iStack_e4;
  int *piStack_e0;
  int *piStack_dc;
  undefined *puStack_d8;
  code *pcStack_d4;
  undefined4 uStack_c0;
  int iStack_bc;
  undefined *puStack_b8;
  int *piStack_b0;
  int iStack_ac;
  undefined4 uStack_a8;
  int *piStack_a4;
  int *piStack_a0;
  int *piStack_9c;
  int *piStack_98;
  undefined *puStack_94;
  undefined *puStack_90;
  undefined4 *puStack_8c;
  undefined4 uStack_60;
  int *piStack_5c;
  undefined4 *puStack_54;
  int iStack_50;
  undefined4 *puStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined4 local_20;
  int *local_1c;
  
  puStack_94 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int **)PTR___stack_chk_guard_006a9ae8;
  iStack_50 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  local_20 = (*(code *)PTR_BN_new_006a71b4)();
  puStack_4c = &local_20;
  iVar13 = *(int *)(PTR_R3410_paramset_006a95fc + 0xc);
  puStack_54 = (undefined4 *)PTR_R3410_paramset_006a95fc;
  while (iVar13 != 0) {
    (*(code *)PTR_BN_dec2bn_006a7e30)(puStack_4c);
    iVar13 = (*(code *)PTR_BN_cmp_006a7960)(local_20,*(undefined4 *)(iStack_50 + 0x10));
    if (iVar13 == 0) {
      (*(code *)PTR_BN_free_006a701c)(local_20);
      uVar12 = *puStack_54;
      goto LAB_0061a5c8;
    }
    iVar13 = puStack_54[7];
    puStack_54 = puStack_54 + 4;
  }
  (*(code *)PTR_BN_free_006a701c)(local_20);
  uVar12 = 0;
LAB_0061a5c8:
  uVar12 = (*(code *)PTR_OBJ_nid2obj_006a7140)(uVar12);
  piVar2 = (int *)(*(code *)PTR_i2d_ASN1_OBJECT_006a9860)(uVar12,param_2);
  if (local_1c == *(int **)puStack_94) {
    return piVar2;
  }
  piStack_a0 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_90 = PTR___stack_chk_guard_006a9ae8;
  puStack_48 = puStack_94;
  piStack_5c = *(int **)PTR___stack_chk_guard_006a9ae8;
  uStack_44 = param_2;
  piVar2 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
  piStack_dc = (int *)GOST_KEY_PARAMS_new();
  if ((piVar2 == (int *)0x0) || (piStack_dc == (int *)0x0)) {
    uVar12 = 0x2d;
    piVar7 = (int *)&DAT_00000041;
LAB_0061a834:
    ERR_GOST_error(100,piVar7,"gost_ameth.c",uVar12);
    piStack_e0 = (int *)0x0;
    (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar2);
  }
  else {
    iVar13 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(piStack_a0);
    if (iVar13 == 0x32b) {
      uVar12 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(piStack_a0);
      uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar12);
      iVar13 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar12);
    }
    else {
      if (iVar13 == 0x32c) {
        puStack_94 = (undefined *)(*(code *)PTR_EVP_PKEY_get0_006a95d8)(piStack_a0);
        uStack_60 = (*(code *)PTR_BN_new_006a71b4)();
        unaff_s5 = &uStack_60;
        iVar13 = *(int *)(PTR_R3410_paramset_006a95fc + 0xc);
        piStack_a0 = (int *)PTR_R3410_paramset_006a95fc;
        while (iVar13 != 0) {
          (*(code *)PTR_BN_dec2bn_006a7e30)(unaff_s5);
          iVar13 = (*(code *)PTR_BN_cmp_006a7960)(uStack_60,*(undefined4 *)(puStack_94 + 0x10));
          if (iVar13 == 0) {
            (*(code *)PTR_BN_free_006a701c)(uStack_60);
            iVar13 = *piStack_a0;
            if (iVar13 != 0) goto LAB_0061a6b8;
            goto LAB_0061a824;
          }
          iVar13 = piStack_a0[7];
          piStack_a0 = piStack_a0 + 4;
        }
        (*(code *)PTR_BN_free_006a701c)(uStack_60);
LAB_0061a824:
        uVar12 = 0x3d;
        piVar7 = (int *)&DAT_0000006d;
        goto LAB_0061a834;
      }
      iVar13 = 0;
    }
LAB_0061a6b8:
    iVar13 = (*(code *)PTR_OBJ_nid2obj_006a7140)(iVar13);
    puVar5 = PTR_OBJ_nid2obj_006a7140;
    *piStack_dc = iVar13;
    iVar13 = (*(code *)puVar5)(0x336);
    piVar7 = piVar2 + 2;
    piStack_dc[1] = iVar13;
    iVar13 = i2d_GOST_KEY_PARAMS(piStack_dc);
    *piVar2 = iVar13;
    if (iVar13 < 1) {
      uVar12 = 0x4b;
      piVar7 = (int *)&DAT_00000041;
      goto LAB_0061a834;
    }
    piVar2[1] = 0x10;
    piStack_e0 = piVar2;
  }
  GOST_KEY_PARAMS_free(piStack_dc);
  if (piStack_5c == *(int **)puStack_90) {
    return piStack_e0;
  }
  piStack_b0 = piStack_5c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_130 = PTR___stack_chk_guard_006a9ae8;
  puStack_b8 = &_gp;
  uStack_a8 = 0;
  piStack_a4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  piStack_9c = piStack_e0;
  piStack_98 = piStack_dc;
  puStack_8c = unaff_s5;
  uVar12 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(piVar7);
  uVar3 = (**(code **)(puStack_b8 + -0x7ed4))(piVar7);
  puStack_128 = (undefined4 *)(**(code **)(puStack_b8 + -0x7ca0))(uVar3);
  if (piVar7[6] == 0) {
    pcStack_124 = (char *)0xffffffff;
    piStack_120 = (int *)0x0;
  }
  else {
    piStack_120 = (int *)encode_gost_algor_params(piVar7);
    pcStack_124 = (char *)0x10;
  }
  iStack_e4 = (**(code **)(puStack_b8 + -0x7c2c))();
  uVar3 = (**(code **)(puStack_b8 + -0x7750))(uVar12);
  (**(code **)(puStack_b8 + -0x7bf4))(uVar3,iStack_e4,0);
  iStack_12c = (**(code **)(puStack_b8 + -0x72fc))(uVar12);
  if (iStack_12c == 0) {
    piStack_138 = (int *)0x2e4;
    pcVar15 = "gost_ameth.c";
    puVar14 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    piVar2 = (int *)0x0;
  }
  else {
    piStack_e0 = (int *)(**(code **)(puStack_b8 + -0x7c2c))();
    piStack_dc = (int *)(**(code **)(puStack_b8 + -0x7c2c))();
    if (piStack_e0 == (int *)0x0) {
      piStack_138 = (int *)0x2ea;
      pcVar15 = "gost_ameth.c";
      puVar14 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      if (piStack_dc != (int *)0x0) {
        (**(code **)(puStack_b8 + -0x7dc4))(piStack_dc);
      }
    }
    else {
      if (piStack_dc != (int *)0x0) {
        uVar12 = (**(code **)(puStack_b8 + -0x7750))(uVar12);
        uStack_c0 = 0;
        piStack_138 = piStack_dc;
        piVar2 = (int *)(**(code **)(puStack_b8 + -0x6748))(uVar12,iStack_12c,piStack_e0);
        if (piVar2 == (int *)0x0) {
          piStack_138 = (int *)0x2f2;
          pcVar15 = "gost_ameth.c";
          puVar14 = (undefined4 *)0x44;
          piStack_b0 = piVar2;
          ERR_GOST_error(0x87);
          (**(code **)(puStack_b8 + -0x7dc4))(piStack_e0);
          (**(code **)(puStack_b8 + -0x7dc4))(piStack_dc);
          (**(code **)(puStack_b8 + -0x7dc4))(iStack_e4);
          piVar2 = piStack_b0;
        }
        else {
          iVar4 = (**(code **)(puStack_b8 + -0x7bec))(iStack_e4);
          iVar13 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar13 = iVar4 + 0xe;
          }
          iVar13 = iVar13 >> 3;
          (**(code **)(puStack_b8 + -0x7dc4))(iStack_e4);
          pcVar17 = (char *)(iVar13 << 1);
          iStack_12c = (**(code **)(puStack_b8 + -0x7dd8))(pcVar17,"gost_ameth.c",0x2fa);
          (**(code **)(puStack_b8 + -0x53ec))(iStack_12c,0,pcVar17);
          iStack_ac = iStack_12c + iVar13;
          (**(code **)(puStack_b8 + -0x55cc))(piStack_e0,iStack_ac,iVar13);
          (**(code **)(puStack_b8 + -0x55cc))(piStack_dc,iStack_12c,iVar13);
          (**(code **)(puStack_b8 + -0x7dc4))(piStack_e0);
          (**(code **)(puStack_b8 + -0x7dc4))(piStack_dc);
          piStack_e0 = (int *)(**(code **)(puStack_b8 + -0x6778))();
          pcVar15 = pcVar17;
          (**(code **)(puStack_b8 + -0x70c4))(piStack_e0,0);
          puVar5 = (undefined *)(**(code **)(puStack_b8 + -0x7ab0))(piStack_e0);
          iVar13 = iStack_ac + iVar13;
          if (0 < (int)pcVar17) {
            do {
              puVar1 = (undefined *)(iVar13 + -1);
              iVar13 = iVar13 + -1;
              *puVar5 = *puVar1;
              puVar5 = puVar5 + 1;
            } while (iStack_12c != iVar13);
          }
          (**(code **)(puStack_b8 + -0x7f58))(iStack_12c);
          puVar14 = &uStack_a8;
          iStack_e4 = (**(code **)(puStack_b8 + -0x6a00))(piStack_e0);
          (**(code **)(puStack_b8 + -0x6770))(piStack_e0);
          if (iStack_e4 < 0) {
            piVar2 = (int *)0x0;
          }
          else {
            uStack_c0 = uStack_a8;
            puVar14 = puStack_128;
            pcVar15 = pcStack_124;
            piStack_138 = piStack_120;
            iStack_bc = iStack_e4;
            piVar2 = (int *)(**(code **)(puStack_b8 + -0x6638))(piStack_b0);
          }
        }
        goto LAB_0061ab6c;
      }
      piStack_138 = (int *)0x2ea;
      pcVar15 = "gost_ameth.c";
      puVar14 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      (**(code **)(puStack_b8 + -0x7dc4))(piStack_e0);
    }
    (**(code **)(puStack_b8 + -0x7dc4))(iStack_e4);
    piVar2 = (int *)0x0;
  }
LAB_0061ab6c:
  if (piStack_a4 == *(int **)puStack_130) {
    return piVar2;
  }
  pcStack_d4 = pkey_ctrl_gost;
  piStack_134 = piStack_a4;
  (**(code **)(puStack_b8 + -0x5330))();
  puStack_13c = PTR___stack_chk_guard_006a9ae8;
  puStack_d8 = puStack_130;
  puStack_100 = &_gp;
  iStack_ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuVar6 = &switchD_0061ad28::switchdataD_0067a7d0 + (int)puVar14;
  piVar2 = piStack_138;
  switch(puVar14) {
  default:
    piVar7 = (int *)&SUB_fffffffe;
    break;
  case (undefined4 *)0x1:
    piVar7 = (int *)0x1;
    if (pcVar15 == (char *)0x0) {
      piStack_f4 = (int *)0x0;
      piStack_f0 = (int *)0x0;
      piVar2 = (int *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      (**(code **)(puStack_100 + -0x5728))(piStack_138,0,&piStack_f4,&piStack_f0);
LAB_0061ad7c:
      piStack_134 = piStack_f4;
      ppuVar6 = (undefined **)(**(code **)(puStack_100 + -0x7ca0))(0x329);
      (**(code **)(puStack_100 + -0x60fc))(piStack_134,ppuVar6,5,0);
      piStack_138 = piStack_f0;
      if (piVar2 == (int *)0x0) goto LAB_0061aef4;
      ppuVar6 = (undefined **)(**(code **)(puStack_100 + -0x7ca0))(piVar2);
      puVar5 = (undefined *)0x0;
      uVar12 = 5;
      pcVar16 = *(code **)(puStack_100 + -0x60fc);
LAB_0061ae24:
      (*pcVar16)(piStack_138,ppuVar6,uVar12,puVar5);
      piVar7 = (int *)0x1;
    }
    break;
  case (undefined4 *)0x2:
    piVar7 = (int *)0x1;
    if (pcVar15 == (char *)0x0) {
      puStack_130 = (undefined *)encode_gost_algor_params();
      if (puStack_130 == (undefined *)0x0) goto LAB_0061aef4;
      (**(code **)(puStack_100 + -0x56bc))(piStack_138,&piStack_f0);
      puVar5 = puStack_130;
LAB_0061ae04:
      piStack_138 = piStack_f0;
      ppuVar6 = (undefined **)(**(code **)(puStack_100 + -0x7ca0))(*piStack_134);
      uVar12 = 0x10;
      pcVar16 = *(code **)(puStack_100 + -0x60fc);
      puStack_130 = puVar5;
      goto LAB_0061ae24;
    }
    break;
  case (undefined4 *)0x3:
    piVar7 = (int *)&SUB_00000002;
    *piStack_138 = 0x329;
    break;
  case (undefined4 *)0x5:
    piVar7 = (int *)0x1;
    if (pcVar15 == (char *)0x0) {
      piStack_f4 = (int *)0x0;
      piStack_f0 = (int *)0x0;
      piVar2 = (int *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      ppiStack_108 = &piStack_f0;
      (**(code **)(puStack_100 + -0x5acc))(piStack_138,0,0,&piStack_f4);
      goto LAB_0061ad7c;
    }
    break;
  case (undefined4 *)0x7:
    piVar7 = (int *)0x1;
    if (pcVar15 == (char *)0x0) {
      piStack_f0 = (int *)0x0;
      puStack_130 = (undefined *)encode_gost_algor_params();
      if (puStack_130 != (undefined *)0x0) {
        (**(code **)(puStack_100 + -0x56c0))(piStack_138,0,0,&piStack_f0);
        puVar5 = puStack_130;
        goto LAB_0061ae04;
      }
LAB_0061aef4:
      piStack_138 = piVar2;
      piVar7 = (int *)0xffffffff;
    }
  }
  if (iStack_ec == *(int *)puStack_13c) {
    return piVar7;
  }
  pcStack_11c = pub_encode_gost94;
  iStack_1c4 = iStack_ec;
  (**(code **)(puStack_100 + -0x5330))();
  puStack_17c = PTR___stack_chk_guard_006a9ae8;
  puStack_150 = &_gp;
  uStack_148 = 0;
  iStack_144 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar13 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(ppuVar6);
  uVar12 = (**(code **)(puStack_150 + -0x7ed4))(ppuVar6);
  puStack_174 = (undefined4 *)(**(code **)(puStack_150 + -0x7ca0))(uVar12);
  if (ppuVar6[6] == (undefined *)0x0) {
    pcStack_170 = (char *)0xffffffff;
    uStack_1b8 = 0;
  }
  else {
    uStack_1b8 = encode_gost_algor_params(ppuVar6);
    pcStack_170 = (char *)0x10;
  }
  iVar8 = (**(code **)(puStack_150 + -0x7bec))(*(undefined4 *)(iVar13 + 0x18));
  iVar4 = iVar8 + 7;
  if (iVar8 + 7 < 0) {
    iVar4 = iVar8 + 0xe;
  }
  pcVar17 = (char *)(iVar4 >> 3);
  iVar4 = (**(code **)(puStack_150 + -0x7dd8))(pcVar17,"gost_ameth.c",0x288);
  (**(code **)(puStack_150 + -0x7be0))(*(undefined4 *)(iVar13 + 0x18),iVar4);
  uVar12 = (**(code **)(puStack_150 + -0x6778))();
  pcVar15 = pcVar17;
  (**(code **)(puStack_150 + -0x70c4))(uVar12,0);
  puVar5 = (undefined *)(**(code **)(puStack_150 + -0x7ab0))(uVar12);
  iVar13 = iVar4 + (int)pcVar17;
  if (0 < (int)pcVar17) {
    do {
      puVar1 = (undefined *)(iVar13 + -1);
      iVar13 = iVar13 + -1;
      *puVar5 = *puVar1;
      puVar5 = puVar5 + 1;
    } while (iVar4 != iVar13);
  }
  (**(code **)(puStack_150 + -0x7f58))(iVar4);
  puStack_1cc = &uStack_148;
  iStack_180 = (**(code **)(puStack_150 + -0x6a00))(uVar12);
  (**(code **)(puStack_150 + -0x6770))(uVar12);
  if (iStack_180 < 0) {
    piVar2 = (int *)0x0;
  }
  else {
    uStack_158 = uStack_148;
    puStack_1cc = puStack_174;
    pcVar15 = pcStack_170;
    iStack_154 = iStack_180;
    piVar2 = (int *)(**(code **)(puStack_150 + -0x6638))
                              (iStack_1c4,puStack_174,pcStack_170,uStack_1b8);
  }
  if (iStack_144 == *(int *)puStack_17c) {
    return piVar2;
  }
  pcStack_16c = priv_encode_gost;
  iStack_1c0 = iStack_144;
  (**(code **)(puStack_150 + -0x5330))();
  puStack_1c8 = PTR___stack_chk_guard_006a9ae8;
  puStack_190 = &_gp;
  iStack_184 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar14 = puStack_1cc;
  iStack_178 = iStack_1c4;
  uVar12 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puStack_1cc);
  puStack_1bc = (undefined4 *)(**(code **)(puStack_190 + -0x7ca0))(uVar12);
  iVar13 = encode_gost_algor_params(puStack_1cc);
  uStack_188 = 0;
  if (iVar13 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar4 = (**(code **)(puStack_190 + -0x7ed4))(puStack_1cc);
    if (iVar4 == 0x32b) {
      iVar4 = (**(code **)(puStack_190 + -0x5808))(puStack_1cc);
      if (iVar4 == 0) goto LAB_0061b1b4;
      uVar12 = (**(code **)(puStack_190 + -0x6e68))(iVar4);
    }
    else if ((iVar4 == 0x32c) &&
            (iVar4 = (**(code **)(puStack_190 + -0x5808))(puStack_1cc), iVar4 != 0)) {
      uVar12 = *(undefined4 *)(iVar4 + 0x1c);
    }
    else {
LAB_0061b1b4:
      uVar12 = 0;
    }
    uVar12 = (**(code **)(puStack_190 + -0x7cec))(uVar12,0);
    puStack_1cc = (undefined4 *)(**(code **)(puStack_190 + -0x6a04))(uVar12,&uStack_188);
    (**(code **)(puStack_190 + -0x7f4c))(uVar12);
    pcVar15 = (char *)0x0;
    uStack_19c = uStack_188;
    puVar14 = puStack_1bc;
    iStack_1a0 = iVar13;
    puStack_198 = puStack_1cc;
    piVar2 = (int *)(**(code **)(puStack_190 + -0x6648))(iStack_1c0,puStack_1bc,0,0x10);
    iStack_1c4 = iVar13;
  }
  if (iStack_184 == *(int *)puStack_1c8) {
    return piVar2;
  }
  pcStack_1b4 = priv_print_gost94;
  iVar13 = iStack_184;
  (**(code **)(puStack_190 + -0x5330))();
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  iVar4 = 0x80;
  iStack_1d4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar17 = pcVar15;
  piVar2 = (int *)(*(code *)PTR_BIO_indent_006a86ac)();
  if (piVar2 == (int *)0x0) goto LAB_0061b304;
  (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"Private key: ");
  iVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puVar14);
  if (iVar4 == 0x32b) {
    iVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
    if ((iVar4 != 0) && (iVar4 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar4), iVar4 != 0)
       ) goto LAB_0061b4fc;
LAB_0061b370:
    (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"<undefined>");
  }
  else {
    if ((iVar4 != 0x32c) ||
       ((iVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14), iVar4 == 0 ||
        (iVar4 = *(int *)(iVar4 + 0x1c), iVar4 == 0)))) goto LAB_0061b370;
LAB_0061b4fc:
    (*(code *)PTR_BN_print_006a6f24)(iVar13,iVar4);
  }
  (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"\n");
  iVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
  uVar12 = *(undefined4 *)(iVar4 + 0x18);
  (*(code *)PTR_BIO_indent_006a86ac)(iVar13,pcVar15,0x80);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"Public key: ");
  (*(code *)PTR_BN_print_006a6f24)(iVar13,uVar12);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"\n");
  iVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
  uStack_1d8 = (*(code *)PTR_BN_new_006a71b4)();
  if (*(int *)(PTR_R3410_paramset_006a95fc + 0xc) != 0) {
    puVar14 = (undefined4 *)PTR_R3410_paramset_006a95fc;
    do {
      (*(code *)PTR_BN_dec2bn_006a7e30)(&uStack_1d8);
      iVar8 = (*(code *)PTR_BN_cmp_006a7960)(uStack_1d8,*(undefined4 *)(iVar4 + 0x10));
      if (iVar8 == 0) {
        (*(code *)PTR_BN_free_006a701c)(uStack_1d8);
        uVar12 = *puVar14;
        goto LAB_0061b494;
      }
      piVar2 = puVar14 + 7;
      puVar14 = puVar14 + 4;
    } while (*piVar2 != 0);
  }
  uVar12 = 0;
  (*(code *)PTR_BN_free_006a701c)(uStack_1d8);
LAB_0061b494:
  (*(code *)PTR_BIO_indent_006a86ac)(iVar13,pcVar15,0x80);
  iVar4 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar12);
  pcVar17 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"Parameter set: %s\n",iVar4);
  piVar2 = (int *)0x1;
LAB_0061b304:
  if (iStack_1d4 == *(int *)puVar5) {
    return piVar2;
  }
  iVar13 = iStack_1d4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar8 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar8 != 0) {
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar8);
    uVar12 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar8);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar8);
    uVar9 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
    uVar9 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(uVar9);
    uVar10 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
    uVar10 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar10);
    iVar11 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                       (uVar10,uVar9,uVar12,uVar3,iVar8);
    if (iVar11 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1c2);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
      return (int *)0x0;
    }
    iVar11 = (*(code *)PTR_BIO_indent_006a86ac)(iVar13,iVar4,0x80);
    if (iVar11 != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"Public key:\n");
      iVar11 = (*(code *)PTR_BIO_indent_006a86ac)(iVar13,iVar4 + 3,0x80);
      if (iVar11 != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(iVar13,&DAT_0067a7b4);
        (*(code *)PTR_BN_print_006a6f24)(iVar13,uVar12);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"\n");
        (*(code *)PTR_BIO_indent_006a86ac)(iVar13,iVar4 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar13,&DAT_0067a7b8);
        (*(code *)PTR_BN_print_006a6f24)(iVar13,uVar3);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"\n");
        (*(code *)PTR_BN_CTX_end_006a8530)(iVar8);
        (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
        uVar12 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
        uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar12);
        uVar12 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar12);
        iVar4 = (*(code *)PTR_BIO_indent_006a86ac)(iVar13,iVar4,0x80);
        if (iVar4 != 0) {
          uVar12 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar12);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar13,"Parameter set: %s\n",uVar12);
          return (int *)0x1;
        }
      }
    }
    return (int *)0x0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1b8);
  return (int *)0x0;
}

