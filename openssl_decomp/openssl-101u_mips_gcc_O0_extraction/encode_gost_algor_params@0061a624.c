
/* WARNING: Type propagation algorithm not settling */

int * encode_gost_algor_params(int *param_1)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  undefined **ppuVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 *puVar14;
  char *pcVar15;
  int unaff_s3;
  undefined4 *unaff_s5;
  code *pcVar16;
  char *pcVar17;
  undefined4 uStack_1a0;
  int iStack_19c;
  undefined4 *puStack_194;
  undefined *puStack_190;
  int iStack_18c;
  int iStack_188;
  undefined4 *puStack_184;
  undefined4 uStack_180;
  code *pcStack_17c;
  int iStack_168;
  undefined4 uStack_164;
  undefined4 *puStack_160;
  undefined *puStack_158;
  undefined4 uStack_150;
  int iStack_14c;
  int iStack_148;
  undefined *puStack_144;
  int iStack_140;
  undefined4 *puStack_13c;
  char *pcStack_138;
  code *pcStack_134;
  undefined4 uStack_120;
  int iStack_11c;
  undefined *puStack_118;
  undefined4 uStack_110;
  int iStack_10c;
  undefined *puStack_104;
  int *piStack_100;
  int *piStack_fc;
  undefined *puStack_f8;
  int iStack_f4;
  undefined4 *puStack_f0;
  char *pcStack_ec;
  int *piStack_e8;
  code *pcStack_e4;
  int **ppiStack_d0;
  undefined *puStack_c8;
  int *piStack_bc;
  int *piStack_b8;
  int iStack_b4;
  int iStack_ac;
  int *piStack_a8;
  int *piStack_a4;
  undefined *puStack_a0;
  code *pcStack_9c;
  undefined4 uStack_88;
  int iStack_84;
  undefined *puStack_80;
  int *piStack_78;
  int iStack_74;
  undefined4 uStack_70;
  int *piStack_6c;
  int *piStack_68;
  int *piStack_64;
  int *piStack_60;
  int iStack_5c;
  undefined *puStack_58;
  undefined4 *puStack_54;
  undefined4 local_28;
  int *local_24;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  piVar2 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
  piStack_a4 = (int *)GOST_KEY_PARAMS_new();
  if ((piVar2 == (int *)0x0) || (piStack_a4 == (int *)0x0)) {
    uVar4 = 0x2d;
    piVar9 = (int *)&DAT_00000041;
LAB_0061a834:
    ERR_GOST_error(100,piVar9,"gost_ameth.c",uVar4);
    piStack_a8 = (int *)0x0;
    (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar2);
  }
  else {
    iVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_1);
    if (iVar3 == 0x32b) {
      uVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_1);
      uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar4);
      iVar3 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar4);
    }
    else {
      if (iVar3 == 0x32c) {
        unaff_s3 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_1);
        local_28 = (*(code *)PTR_BN_new_006a71b4)();
        unaff_s5 = &local_28;
        iVar3 = *(int *)(PTR_R3410_paramset_006a95fc + 0xc);
        param_1 = (int *)PTR_R3410_paramset_006a95fc;
        while (iVar3 != 0) {
          (*(code *)PTR_BN_dec2bn_006a7e30)(unaff_s5);
          iVar3 = (*(code *)PTR_BN_cmp_006a7960)(local_28,*(undefined4 *)(unaff_s3 + 0x10));
          if (iVar3 == 0) {
            (*(code *)PTR_BN_free_006a701c)(local_28);
            iVar3 = *param_1;
            if (iVar3 != 0) goto LAB_0061a6b8;
            goto LAB_0061a824;
          }
          iVar3 = param_1[7];
          param_1 = param_1 + 4;
        }
        (*(code *)PTR_BN_free_006a701c)(local_28);
LAB_0061a824:
        uVar4 = 0x3d;
        piVar9 = (int *)&DAT_0000006d;
        goto LAB_0061a834;
      }
      iVar3 = 0;
    }
LAB_0061a6b8:
    iVar3 = (*(code *)PTR_OBJ_nid2obj_006a7140)(iVar3);
    puVar7 = PTR_OBJ_nid2obj_006a7140;
    *piStack_a4 = iVar3;
    iVar3 = (*(code *)puVar7)(0x336);
    piVar9 = piVar2 + 2;
    piStack_a4[1] = iVar3;
    iVar3 = i2d_GOST_KEY_PARAMS(piStack_a4);
    *piVar2 = iVar3;
    if (iVar3 < 1) {
      uVar4 = 0x4b;
      piVar9 = (int *)&DAT_00000041;
      goto LAB_0061a834;
    }
    piVar2[1] = 0x10;
    piStack_a8 = piVar2;
  }
  GOST_KEY_PARAMS_free(piStack_a4);
  if (local_24 == *(int **)puStack_58) {
    return piStack_a8;
  }
  piStack_78 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_f8 = PTR___stack_chk_guard_006a9ae8;
  puStack_80 = &_gp;
  uStack_70 = 0;
  piStack_6c = *(int **)PTR___stack_chk_guard_006a9ae8;
  piStack_68 = param_1;
  piStack_64 = piStack_a8;
  piStack_60 = piStack_a4;
  iStack_5c = unaff_s3;
  puStack_54 = unaff_s5;
  uVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(piVar9);
  uVar5 = (**(code **)(puStack_80 + -0x7ed4))(piVar9);
  puStack_f0 = (undefined4 *)(**(code **)(puStack_80 + -0x7ca0))(uVar5);
  if (piVar9[6] == 0) {
    pcStack_ec = (char *)0xffffffff;
    piStack_e8 = (int *)0x0;
  }
  else {
    piStack_e8 = (int *)encode_gost_algor_params(piVar9);
    pcStack_ec = (char *)0x10;
  }
  iStack_ac = (**(code **)(puStack_80 + -0x7c2c))();
  uVar5 = (**(code **)(puStack_80 + -0x7750))(uVar4);
  (**(code **)(puStack_80 + -0x7bf4))(uVar5,iStack_ac,0);
  iStack_f4 = (**(code **)(puStack_80 + -0x72fc))(uVar4);
  if (iStack_f4 == 0) {
    piStack_100 = (int *)0x2e4;
    pcVar15 = "gost_ameth.c";
    puVar14 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    piVar2 = (int *)0x0;
  }
  else {
    piStack_a8 = (int *)(**(code **)(puStack_80 + -0x7c2c))();
    piStack_a4 = (int *)(**(code **)(puStack_80 + -0x7c2c))();
    if (piStack_a8 == (int *)0x0) {
      piStack_100 = (int *)0x2ea;
      pcVar15 = "gost_ameth.c";
      puVar14 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      if (piStack_a4 != (int *)0x0) {
        (**(code **)(puStack_80 + -0x7dc4))(piStack_a4);
      }
    }
    else {
      if (piStack_a4 != (int *)0x0) {
        uVar4 = (**(code **)(puStack_80 + -0x7750))(uVar4);
        uStack_88 = 0;
        piStack_100 = piStack_a4;
        piVar2 = (int *)(**(code **)(puStack_80 + -0x6748))(uVar4,iStack_f4,piStack_a8);
        if (piVar2 == (int *)0x0) {
          piStack_100 = (int *)0x2f2;
          pcVar15 = "gost_ameth.c";
          puVar14 = (undefined4 *)0x44;
          piStack_78 = piVar2;
          ERR_GOST_error(0x87);
          (**(code **)(puStack_80 + -0x7dc4))(piStack_a8);
          (**(code **)(puStack_80 + -0x7dc4))(piStack_a4);
          (**(code **)(puStack_80 + -0x7dc4))(iStack_ac);
          piVar2 = piStack_78;
        }
        else {
          iVar6 = (**(code **)(puStack_80 + -0x7bec))(iStack_ac);
          iVar3 = iVar6 + 7;
          if (iVar6 + 7 < 0) {
            iVar3 = iVar6 + 0xe;
          }
          iVar3 = iVar3 >> 3;
          (**(code **)(puStack_80 + -0x7dc4))(iStack_ac);
          pcVar17 = (char *)(iVar3 << 1);
          iStack_f4 = (**(code **)(puStack_80 + -0x7dd8))(pcVar17,"gost_ameth.c",0x2fa);
          (**(code **)(puStack_80 + -0x53ec))(iStack_f4,0,pcVar17);
          iStack_74 = iStack_f4 + iVar3;
          (**(code **)(puStack_80 + -0x55cc))(piStack_a8,iStack_74,iVar3);
          (**(code **)(puStack_80 + -0x55cc))(piStack_a4,iStack_f4,iVar3);
          (**(code **)(puStack_80 + -0x7dc4))(piStack_a8);
          (**(code **)(puStack_80 + -0x7dc4))(piStack_a4);
          piStack_a8 = (int *)(**(code **)(puStack_80 + -0x6778))();
          pcVar15 = pcVar17;
          (**(code **)(puStack_80 + -0x70c4))(piStack_a8,0);
          puVar7 = (undefined *)(**(code **)(puStack_80 + -0x7ab0))(piStack_a8);
          iVar3 = iStack_74 + iVar3;
          if (0 < (int)pcVar17) {
            do {
              puVar1 = (undefined *)(iVar3 + -1);
              iVar3 = iVar3 + -1;
              *puVar7 = *puVar1;
              puVar7 = puVar7 + 1;
            } while (iStack_f4 != iVar3);
          }
          (**(code **)(puStack_80 + -0x7f58))(iStack_f4);
          puVar14 = &uStack_70;
          iStack_ac = (**(code **)(puStack_80 + -0x6a00))(piStack_a8);
          (**(code **)(puStack_80 + -0x6770))(piStack_a8);
          if (iStack_ac < 0) {
            piVar2 = (int *)0x0;
          }
          else {
            uStack_88 = uStack_70;
            puVar14 = puStack_f0;
            pcVar15 = pcStack_ec;
            piStack_100 = piStack_e8;
            iStack_84 = iStack_ac;
            piVar2 = (int *)(**(code **)(puStack_80 + -0x6638))(piStack_78);
          }
        }
        goto LAB_0061ab6c;
      }
      piStack_100 = (int *)0x2ea;
      pcVar15 = "gost_ameth.c";
      puVar14 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      (**(code **)(puStack_80 + -0x7dc4))(piStack_a8);
    }
    (**(code **)(puStack_80 + -0x7dc4))(iStack_ac);
    piVar2 = (int *)0x0;
  }
LAB_0061ab6c:
  if (piStack_6c == *(int **)puStack_f8) {
    return piVar2;
  }
  pcStack_9c = pkey_ctrl_gost;
  piStack_fc = piStack_6c;
  (**(code **)(puStack_80 + -0x5330))();
  puStack_104 = PTR___stack_chk_guard_006a9ae8;
  puStack_a0 = puStack_f8;
  puStack_c8 = &_gp;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuVar8 = &switchD_0061ad28::switchdataD_0067a7d0 + (int)puVar14;
  piVar2 = piStack_100;
  switch(puVar14) {
  default:
    piVar9 = (int *)&SUB_fffffffe;
    break;
  case (undefined4 *)0x1:
    piVar9 = (int *)0x1;
    if (pcVar15 == (char *)0x0) {
      piStack_bc = (int *)0x0;
      piStack_b8 = (int *)0x0;
      piVar2 = (int *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      (**(code **)(puStack_c8 + -0x5728))(piStack_100,0,&piStack_bc,&piStack_b8);
LAB_0061ad7c:
      piStack_fc = piStack_bc;
      ppuVar8 = (undefined **)(**(code **)(puStack_c8 + -0x7ca0))(0x329);
      (**(code **)(puStack_c8 + -0x60fc))(piStack_fc,ppuVar8,5,0);
      piStack_100 = piStack_b8;
      if (piVar2 == (int *)0x0) goto LAB_0061aef4;
      ppuVar8 = (undefined **)(**(code **)(puStack_c8 + -0x7ca0))(piVar2);
      puVar7 = (undefined *)0x0;
      uVar4 = 5;
      pcVar16 = *(code **)(puStack_c8 + -0x60fc);
LAB_0061ae24:
      (*pcVar16)(piStack_100,ppuVar8,uVar4,puVar7);
      piVar9 = (int *)0x1;
    }
    break;
  case (undefined4 *)0x2:
    piVar9 = (int *)0x1;
    if (pcVar15 == (char *)0x0) {
      puStack_f8 = (undefined *)encode_gost_algor_params();
      if (puStack_f8 == (undefined *)0x0) goto LAB_0061aef4;
      (**(code **)(puStack_c8 + -0x56bc))(piStack_100,&piStack_b8);
      puVar7 = puStack_f8;
LAB_0061ae04:
      piStack_100 = piStack_b8;
      ppuVar8 = (undefined **)(**(code **)(puStack_c8 + -0x7ca0))(*piStack_fc);
      uVar4 = 0x10;
      pcVar16 = *(code **)(puStack_c8 + -0x60fc);
      puStack_f8 = puVar7;
      goto LAB_0061ae24;
    }
    break;
  case (undefined4 *)0x3:
    piVar9 = (int *)&SUB_00000002;
    *piStack_100 = 0x329;
    break;
  case (undefined4 *)0x5:
    piVar9 = (int *)0x1;
    if (pcVar15 == (char *)0x0) {
      piStack_bc = (int *)0x0;
      piStack_b8 = (int *)0x0;
      piVar2 = (int *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      ppiStack_d0 = &piStack_b8;
      (**(code **)(puStack_c8 + -0x5acc))(piStack_100,0,0,&piStack_bc);
      goto LAB_0061ad7c;
    }
    break;
  case (undefined4 *)0x7:
    piVar9 = (int *)0x1;
    if (pcVar15 == (char *)0x0) {
      piStack_b8 = (int *)0x0;
      puStack_f8 = (undefined *)encode_gost_algor_params();
      if (puStack_f8 != (undefined *)0x0) {
        (**(code **)(puStack_c8 + -0x56c0))(piStack_100,0,0,&piStack_b8);
        puVar7 = puStack_f8;
        goto LAB_0061ae04;
      }
LAB_0061aef4:
      piStack_100 = piVar2;
      piVar9 = (int *)0xffffffff;
    }
  }
  if (iStack_b4 == *(int *)puStack_104) {
    return piVar9;
  }
  pcStack_e4 = pub_encode_gost94;
  iStack_18c = iStack_b4;
  (**(code **)(puStack_c8 + -0x5330))();
  puStack_144 = PTR___stack_chk_guard_006a9ae8;
  puStack_118 = &_gp;
  uStack_110 = 0;
  iStack_10c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(ppuVar8);
  uVar4 = (**(code **)(puStack_118 + -0x7ed4))(ppuVar8);
  puStack_13c = (undefined4 *)(**(code **)(puStack_118 + -0x7ca0))(uVar4);
  if (ppuVar8[6] == (undefined *)0x0) {
    pcStack_138 = (char *)0xffffffff;
    uStack_180 = 0;
  }
  else {
    uStack_180 = encode_gost_algor_params(ppuVar8);
    pcStack_138 = (char *)0x10;
  }
  iVar10 = (**(code **)(puStack_118 + -0x7bec))(*(undefined4 *)(iVar3 + 0x18));
  iVar6 = iVar10 + 7;
  if (iVar10 + 7 < 0) {
    iVar6 = iVar10 + 0xe;
  }
  pcVar17 = (char *)(iVar6 >> 3);
  iVar6 = (**(code **)(puStack_118 + -0x7dd8))(pcVar17,"gost_ameth.c",0x288);
  (**(code **)(puStack_118 + -0x7be0))(*(undefined4 *)(iVar3 + 0x18),iVar6);
  uVar4 = (**(code **)(puStack_118 + -0x6778))();
  pcVar15 = pcVar17;
  (**(code **)(puStack_118 + -0x70c4))(uVar4,0);
  puVar7 = (undefined *)(**(code **)(puStack_118 + -0x7ab0))(uVar4);
  iVar3 = iVar6 + (int)pcVar17;
  if (0 < (int)pcVar17) {
    do {
      puVar1 = (undefined *)(iVar3 + -1);
      iVar3 = iVar3 + -1;
      *puVar7 = *puVar1;
      puVar7 = puVar7 + 1;
    } while (iVar6 != iVar3);
  }
  (**(code **)(puStack_118 + -0x7f58))(iVar6);
  puStack_194 = &uStack_110;
  iStack_148 = (**(code **)(puStack_118 + -0x6a00))(uVar4);
  (**(code **)(puStack_118 + -0x6770))(uVar4);
  if (iStack_148 < 0) {
    piVar2 = (int *)0x0;
  }
  else {
    uStack_120 = uStack_110;
    puStack_194 = puStack_13c;
    pcVar15 = pcStack_138;
    iStack_11c = iStack_148;
    piVar2 = (int *)(**(code **)(puStack_118 + -0x6638))
                              (iStack_18c,puStack_13c,pcStack_138,uStack_180);
  }
  if (iStack_10c == *(int *)puStack_144) {
    return piVar2;
  }
  pcStack_134 = priv_encode_gost;
  iStack_188 = iStack_10c;
  (**(code **)(puStack_118 + -0x5330))();
  puStack_190 = PTR___stack_chk_guard_006a9ae8;
  puStack_158 = &_gp;
  iStack_14c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar14 = puStack_194;
  iStack_140 = iStack_18c;
  uVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puStack_194);
  puStack_184 = (undefined4 *)(**(code **)(puStack_158 + -0x7ca0))(uVar4);
  iVar3 = encode_gost_algor_params(puStack_194);
  uStack_150 = 0;
  if (iVar3 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar6 = (**(code **)(puStack_158 + -0x7ed4))(puStack_194);
    if (iVar6 == 0x32b) {
      iVar6 = (**(code **)(puStack_158 + -0x5808))(puStack_194);
      if (iVar6 == 0) goto LAB_0061b1b4;
      uVar4 = (**(code **)(puStack_158 + -0x6e68))(iVar6);
    }
    else if ((iVar6 == 0x32c) &&
            (iVar6 = (**(code **)(puStack_158 + -0x5808))(puStack_194), iVar6 != 0)) {
      uVar4 = *(undefined4 *)(iVar6 + 0x1c);
    }
    else {
LAB_0061b1b4:
      uVar4 = 0;
    }
    uVar4 = (**(code **)(puStack_158 + -0x7cec))(uVar4,0);
    puStack_194 = (undefined4 *)(**(code **)(puStack_158 + -0x6a04))(uVar4,&uStack_150);
    (**(code **)(puStack_158 + -0x7f4c))(uVar4);
    pcVar15 = (char *)0x0;
    uStack_164 = uStack_150;
    puVar14 = puStack_184;
    iStack_168 = iVar3;
    puStack_160 = puStack_194;
    piVar2 = (int *)(**(code **)(puStack_158 + -0x6648))(iStack_188,puStack_184,0,0x10);
    iStack_18c = iVar3;
  }
  if (iStack_14c == *(int *)puStack_190) {
    return piVar2;
  }
  pcStack_17c = priv_print_gost94;
  iVar3 = iStack_14c;
  (**(code **)(puStack_158 + -0x5330))();
  puVar7 = PTR___stack_chk_guard_006a9ae8;
  iVar6 = 0x80;
  iStack_19c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar17 = pcVar15;
  piVar2 = (int *)(*(code *)PTR_BIO_indent_006a86ac)();
  if (piVar2 == (int *)0x0) goto LAB_0061b304;
  (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"Private key: ");
  iVar6 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puVar14);
  if (iVar6 == 0x32b) {
    iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
    if ((iVar6 != 0) && (iVar6 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar6), iVar6 != 0)
       ) goto LAB_0061b4fc;
LAB_0061b370:
    (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"<undefined>");
  }
  else {
    if ((iVar6 != 0x32c) ||
       ((iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14), iVar6 == 0 ||
        (iVar6 = *(int *)(iVar6 + 0x1c), iVar6 == 0)))) goto LAB_0061b370;
LAB_0061b4fc:
    (*(code *)PTR_BN_print_006a6f24)(iVar3,iVar6);
  }
  (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
  uVar4 = *(undefined4 *)(iVar6 + 0x18);
  (*(code *)PTR_BIO_indent_006a86ac)(iVar3,pcVar15,0x80);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"Public key: ");
  (*(code *)PTR_BN_print_006a6f24)(iVar3,uVar4);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
  uStack_1a0 = (*(code *)PTR_BN_new_006a71b4)();
  if (*(int *)(PTR_R3410_paramset_006a95fc + 0xc) != 0) {
    puVar14 = (undefined4 *)PTR_R3410_paramset_006a95fc;
    do {
      (*(code *)PTR_BN_dec2bn_006a7e30)(&uStack_1a0);
      iVar10 = (*(code *)PTR_BN_cmp_006a7960)(uStack_1a0,*(undefined4 *)(iVar6 + 0x10));
      if (iVar10 == 0) {
        (*(code *)PTR_BN_free_006a701c)(uStack_1a0);
        uVar4 = *puVar14;
        goto LAB_0061b494;
      }
      piVar2 = puVar14 + 7;
      puVar14 = puVar14 + 4;
    } while (*piVar2 != 0);
  }
  uVar4 = 0;
  (*(code *)PTR_BN_free_006a701c)(uStack_1a0);
LAB_0061b494:
  (*(code *)PTR_BIO_indent_006a86ac)(iVar3,pcVar15,0x80);
  iVar6 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar4);
  pcVar17 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"Parameter set: %s\n",iVar6);
  piVar2 = (int *)0x1;
LAB_0061b304:
  if (iStack_19c == *(int *)puVar7) {
    return piVar2;
  }
  iVar3 = iStack_19c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar10 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar10 != 0) {
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar10);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar10);
    uVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar10);
    uVar11 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
    uVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(uVar11);
    uVar12 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
    uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar12);
    iVar13 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                       (uVar12,uVar11,uVar4,uVar5,iVar10);
    if (iVar13 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1c2);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar10);
      return (int *)0x0;
    }
    iVar13 = (*(code *)PTR_BIO_indent_006a86ac)(iVar3,iVar6,0x80);
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"Public key:\n");
      iVar13 = (*(code *)PTR_BIO_indent_006a86ac)(iVar3,iVar6 + 3,0x80);
      if (iVar13 != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(iVar3,&DAT_0067a7b4);
        (*(code *)PTR_BN_print_006a6f24)(iVar3,uVar4);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"\n");
        (*(code *)PTR_BIO_indent_006a86ac)(iVar3,iVar6 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar3,&DAT_0067a7b8);
        (*(code *)PTR_BN_print_006a6f24)(iVar3,uVar5);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"\n");
        (*(code *)PTR_BN_CTX_end_006a8530)(iVar10);
        (*(code *)PTR_BN_CTX_free_006a7954)(iVar10);
        uVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
        uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar4);
        uVar4 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar4);
        iVar6 = (*(code *)PTR_BIO_indent_006a86ac)(iVar3,iVar6,0x80);
        if (iVar6 != 0) {
          uVar4 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar4);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"Parameter set: %s\n",uVar4);
          return (int *)0x1;
        }
      }
    }
    return (int *)0x0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1b8);
  return (int *)0x0;
}

