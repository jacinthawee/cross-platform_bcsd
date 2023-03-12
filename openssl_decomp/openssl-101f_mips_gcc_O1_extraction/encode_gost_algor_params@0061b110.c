
/* WARNING: Type propagation algorithm not settling */

int * encode_gost_algor_params(int *param_1)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined *puVar8;
  undefined **ppuVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  int *piVar15;
  undefined *puVar16;
  char *pcVar17;
  char *pcVar18;
  int unaff_s3;
  undefined4 *unaff_s5;
  code *pcVar19;
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
  undefined4 *puStack_100;
  undefined4 *puStack_fc;
  undefined *puStack_f8;
  undefined *puStack_f4;
  undefined4 *puStack_f0;
  char *pcStack_ec;
  undefined4 *puStack_e8;
  code *pcStack_e4;
  undefined4 **ppuStack_d0;
  undefined *puStack_c8;
  undefined4 *puStack_bc;
  undefined4 *puStack_b8;
  int iStack_b4;
  int iStack_ac;
  undefined4 uStack_a8;
  char *pcStack_a4;
  undefined *puStack_a0;
  code *pcStack_9c;
  undefined4 uStack_88;
  int iStack_84;
  undefined *puStack_80;
  undefined4 *puStack_78;
  int iStack_74;
  undefined4 uStack_70;
  undefined4 *puStack_6c;
  int *piStack_68;
  int *piStack_64;
  undefined4 *puStack_60;
  int iStack_5c;
  undefined *puStack_58;
  undefined4 *puStack_54;
  undefined4 local_28;
  int local_24;
  
  puStack_f4 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar2 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
  puStack_60 = (undefined4 *)GOST_KEY_PARAMS_new();
  if ((piVar2 == (int *)0x0) || (puStack_60 == (undefined4 *)0x0)) {
    uVar4 = 0x31;
    piVar15 = (int *)&DAT_00000041;
LAB_0061b320:
    ERR_GOST_error(100,piVar15,"gost_ameth.c",uVar4);
    piStack_64 = (int *)0x0;
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(piVar2);
  }
  else {
    iVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_1);
    if (iVar3 == 0x32b) {
      uVar4 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
      uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar4);
      iVar3 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar4);
    }
    else {
      if (iVar3 == 0x32c) {
        unaff_s3 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
        local_28 = (*(code *)PTR_BN_new_006a82b4)();
        unaff_s5 = &local_28;
        iVar3 = *(int *)(PTR_R3410_paramset_006aa708 + 0xc);
        param_1 = (int *)PTR_R3410_paramset_006aa708;
        while (iVar3 != 0) {
          (*(code *)PTR_BN_dec2bn_006a8f20)(unaff_s5);
          iVar3 = (*(code *)PTR_BN_cmp_006a8a4c)(local_28,*(undefined4 *)(unaff_s3 + 0x10));
          if (iVar3 == 0) {
            (*(code *)PTR_BN_free_006a811c)(local_28);
            iVar3 = *param_1;
            if (iVar3 != 0) goto LAB_0061b1a4;
            goto LAB_0061b310;
          }
          iVar3 = param_1[7];
          param_1 = param_1 + 4;
        }
        (*(code *)PTR_BN_free_006a811c)(local_28);
LAB_0061b310:
        uVar4 = 0x40;
        piVar15 = (int *)&DAT_0000006d;
        goto LAB_0061b320;
      }
      iVar3 = 0;
    }
LAB_0061b1a4:
    uVar4 = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar3);
    puVar8 = PTR_OBJ_nid2obj_006a8240;
    *puStack_60 = uVar4;
    uVar4 = (*(code *)puVar8)(0x336);
    piVar15 = piVar2 + 2;
    puStack_60[1] = uVar4;
    iVar3 = i2d_GOST_KEY_PARAMS(puStack_60);
    *piVar2 = iVar3;
    if (iVar3 < 1) {
      uVar4 = 0x4e;
      piVar15 = (int *)&DAT_00000041;
      goto LAB_0061b320;
    }
    piVar2[1] = 0x10;
    piStack_64 = piVar2;
  }
  GOST_KEY_PARAMS_free(puStack_60);
  if (local_24 == *(int *)puStack_f4) {
    return piStack_64;
  }
  iStack_74 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_f8 = PTR___stack_chk_guard_006aabf0;
  puStack_80 = &_gp;
  puStack_58 = puStack_f4;
  uStack_70 = 0;
  puStack_6c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  piStack_68 = param_1;
  iStack_5c = unaff_s3;
  puStack_54 = unaff_s5;
  uStack_a8 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piVar15);
  uVar4 = (**(code **)(puStack_80 + -0x7ed4))(piVar15);
  puStack_78 = (undefined4 *)(**(code **)(puStack_80 + -0x7ca0))(uVar4);
  if (piVar15[6] == 0) {
    pcStack_ec = (char *)0xffffffff;
    puStack_e8 = (undefined4 *)0x0;
  }
  else {
    puStack_e8 = (undefined4 *)encode_gost_algor_params(piVar15);
    pcStack_ec = &SUB_00000010;
  }
  iStack_ac = (**(code **)(puStack_80 + -0x7c2c))();
  uVar4 = (**(code **)(puStack_80 + -0x7760))(uStack_a8);
  (**(code **)(puStack_80 + -0x7bf4))(uVar4,iStack_ac,0);
  pcStack_a4 = (char *)(**(code **)(puStack_80 + -0x7310))(uStack_a8);
  if (pcStack_a4 == (char *)0x0) {
    puStack_100 = (undefined4 *)0x2f6;
    pcVar17 = "gost_ameth.c";
    puVar5 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    piVar2 = (int *)0x0;
  }
  else {
    uVar4 = (**(code **)(puStack_80 + -0x7c2c))();
    puVar5 = (undefined4 *)(**(code **)(puStack_80 + -0x7c2c))();
    uVar6 = (**(code **)(puStack_80 + -0x7760))(uStack_a8);
    uStack_88 = 0;
    puStack_100 = puVar5;
    (**(code **)(puStack_80 + -0x6724))(uVar6,pcStack_a4,uVar4);
    iVar7 = (**(code **)(puStack_80 + -0x7bec))(iStack_ac);
    iVar3 = iVar7 + 7;
    if (iVar7 + 7 < 0) {
      iVar3 = iVar7 + 0xe;
    }
    iVar3 = iVar3 >> 3;
    (**(code **)(puStack_80 + -0x7dc4))(iStack_ac);
    pcStack_a4 = (char *)(iVar3 << 1);
    puStack_f4 = (undefined *)(**(code **)(puStack_80 + -0x7dd8))(pcStack_a4,"gost_ameth.c",0x2ff);
    unaff_s5 = (undefined4 *)(puStack_f4 + iVar3);
    (**(code **)(puStack_80 + -0x53e0))(puStack_f4,0,pcStack_a4);
    (**(code **)(puStack_80 + -0x55bc))(uVar4,unaff_s5,iVar3);
    (**(code **)(puStack_80 + -0x55bc))(puVar5,puStack_f4,iVar3);
    (**(code **)(puStack_80 + -0x7dc4))(uVar4);
    (**(code **)(puStack_80 + -0x7dc4))(puVar5);
    uStack_a8 = (**(code **)(puStack_80 + -0x6754))();
    pcVar17 = pcStack_a4;
    (**(code **)(puStack_80 + -0x70d4))(uStack_a8,0);
    puVar8 = (undefined *)(**(code **)(puStack_80 + -0x7ab0))(uStack_a8);
    puVar16 = (undefined *)((int)unaff_s5 + iVar3);
    if (0 < (int)pcStack_a4) {
      do {
        puVar1 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        *puVar8 = *puVar1;
        puVar8 = puVar8 + 1;
      } while (puStack_f4 != puVar16);
    }
    (**(code **)(puStack_80 + -0x7f58))(puStack_f4);
    puVar5 = &uStack_70;
    iStack_ac = (**(code **)(puStack_80 + -0x69e8))(uStack_a8);
    (**(code **)(puStack_80 + -0x674c))(uStack_a8);
    if (iStack_ac < 0) {
      piVar2 = (int *)0x0;
    }
    else {
      uStack_88 = uStack_70;
      puVar5 = puStack_78;
      pcVar17 = pcStack_ec;
      puStack_100 = puStack_e8;
      iStack_84 = iStack_ac;
      piVar2 = (int *)(**(code **)(puStack_80 + -0x6618))(iStack_74);
    }
  }
  if (puStack_6c == *(undefined4 **)puStack_f8) {
    return piVar2;
  }
  pcStack_9c = pkey_ctrl_gost;
  puStack_fc = puStack_6c;
  (**(code **)(puStack_80 + -0x5328))();
  puStack_104 = PTR___stack_chk_guard_006aabf0;
  puStack_a0 = puStack_f8;
  puStack_c8 = &_gp;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar9 = &switchD_0061b724::switchdataD_0067b080 + (int)puVar5;
  puVar10 = puStack_100;
  switch(puVar5) {
  default:
    piVar2 = (int *)&SUB_fffffffe;
    break;
  case (undefined4 *)0x1:
    piVar2 = (int *)0x1;
    if (pcVar17 == (char *)0x0) {
      puStack_bc = (undefined4 *)0x0;
      puStack_b8 = (undefined4 *)0x0;
      puVar10 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      (**(code **)(puStack_c8 + -0x5720))(puStack_100,0,&puStack_bc,&puStack_b8);
LAB_0061b778:
      puStack_fc = puStack_bc;
      ppuVar9 = (undefined **)(**(code **)(puStack_c8 + -0x7ca0))(0x329);
      (**(code **)(puStack_c8 + -0x60dc))(puStack_fc,ppuVar9,5,0);
      puStack_100 = puStack_b8;
      if (puVar10 == (undefined4 *)0x0) goto LAB_0061b8f0;
      ppuVar9 = (undefined **)(**(code **)(puStack_c8 + -0x7ca0))(puVar10);
      puVar8 = (undefined *)0x0;
      uVar4 = 5;
      pcVar19 = *(code **)(puStack_c8 + -0x60dc);
LAB_0061b820:
      (*pcVar19)(puStack_100,ppuVar9,uVar4,puVar8);
      piVar2 = (int *)0x1;
    }
    break;
  case (undefined4 *)0x2:
    piVar2 = (int *)0x1;
    if (pcVar17 == (char *)0x0) {
      puStack_f8 = (undefined *)encode_gost_algor_params();
      if (puStack_f8 == (undefined *)0x0) goto LAB_0061b8f0;
      (**(code **)(puStack_c8 + -0x56b4))(puStack_100,&puStack_b8);
      puVar8 = puStack_f8;
LAB_0061b800:
      puStack_100 = puStack_b8;
      ppuVar9 = (undefined **)(**(code **)(puStack_c8 + -0x7ca0))(*puStack_fc);
      uVar4 = 0x10;
      pcVar19 = *(code **)(puStack_c8 + -0x60dc);
      puStack_f8 = puVar8;
      goto LAB_0061b820;
    }
    break;
  case (undefined4 *)0x3:
    piVar2 = (int *)&SUB_00000002;
    *puStack_100 = 0x329;
    break;
  case (undefined4 *)0x5:
    piVar2 = (int *)0x1;
    if (pcVar17 == (char *)0x0) {
      puStack_bc = (undefined4 *)0x0;
      puStack_b8 = (undefined4 *)0x0;
      puVar10 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      ppuStack_d0 = &puStack_b8;
      (**(code **)(puStack_c8 + -0x5ac0))(puStack_100,0,0,&puStack_bc);
      goto LAB_0061b778;
    }
    break;
  case (undefined4 *)0x7:
    piVar2 = (int *)0x1;
    if (pcVar17 == (char *)0x0) {
      puStack_f8 = (undefined *)encode_gost_algor_params();
      if (puStack_f8 != (undefined *)0x0) {
        (**(code **)(puStack_c8 + -0x56b8))(puStack_100,0,0,&puStack_b8);
        puVar8 = puStack_f8;
        goto LAB_0061b800;
      }
LAB_0061b8f0:
      puStack_100 = puVar10;
      piVar2 = (int *)0xffffffff;
    }
  }
  if (iStack_b4 == *(int *)puStack_104) {
    return piVar2;
  }
  pcStack_e4 = pub_encode_gost94;
  iStack_18c = iStack_b4;
  (**(code **)(puStack_c8 + -0x5328))();
  puStack_144 = PTR___stack_chk_guard_006aabf0;
  puStack_118 = &_gp;
  uStack_110 = 0;
  iStack_10c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_f0 = unaff_s5;
  iVar3 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(ppuVar9);
  uVar4 = (**(code **)(puStack_118 + -0x7ed4))(ppuVar9);
  puStack_13c = (undefined4 *)(**(code **)(puStack_118 + -0x7ca0))(uVar4);
  if (ppuVar9[6] == (undefined *)0x0) {
    pcStack_138 = (char *)0xffffffff;
    uStack_180 = 0;
  }
  else {
    uStack_180 = encode_gost_algor_params(ppuVar9);
    pcStack_138 = (char *)0x10;
  }
  iVar11 = (**(code **)(puStack_118 + -0x7bec))(*(undefined4 *)(iVar3 + 0x18));
  iVar7 = iVar11 + 7;
  if (iVar11 + 7 < 0) {
    iVar7 = iVar11 + 0xe;
  }
  pcVar18 = (char *)(iVar7 >> 3);
  iVar7 = (**(code **)(puStack_118 + -0x7dd8))(pcVar18,"gost_ameth.c",0x291);
  (**(code **)(puStack_118 + -0x7be0))(*(undefined4 *)(iVar3 + 0x18),iVar7);
  uVar4 = (**(code **)(puStack_118 + -0x6754))();
  pcVar17 = pcVar18;
  (**(code **)(puStack_118 + -0x70d4))(uVar4,0);
  puVar8 = (undefined *)(**(code **)(puStack_118 + -0x7ab0))(uVar4);
  iVar3 = iVar7 + (int)pcVar18;
  if (0 < (int)pcVar18) {
    do {
      puVar16 = (undefined *)(iVar3 + -1);
      iVar3 = iVar3 + -1;
      *puVar8 = *puVar16;
      puVar8 = puVar8 + 1;
    } while (iVar7 != iVar3);
  }
  (**(code **)(puStack_118 + -0x7f58))(iVar7);
  puStack_194 = &uStack_110;
  iStack_148 = (**(code **)(puStack_118 + -0x69e8))(uVar4);
  (**(code **)(puStack_118 + -0x674c))(uVar4);
  if (iStack_148 < 0) {
    piVar2 = (int *)0x0;
  }
  else {
    uStack_120 = uStack_110;
    puStack_194 = puStack_13c;
    pcVar17 = pcStack_138;
    iStack_11c = iStack_148;
    piVar2 = (int *)(**(code **)(puStack_118 + -0x6618))
                              (iStack_18c,puStack_13c,pcStack_138,uStack_180);
  }
  if (iStack_10c == *(int *)puStack_144) {
    return piVar2;
  }
  pcStack_134 = priv_encode_gost;
  iStack_188 = iStack_10c;
  (**(code **)(puStack_118 + -0x5328))();
  puStack_190 = PTR___stack_chk_guard_006aabf0;
  puStack_158 = &_gp;
  iStack_14c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar5 = puStack_194;
  iStack_140 = iStack_18c;
  uVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puStack_194);
  puStack_184 = (undefined4 *)(**(code **)(puStack_158 + -0x7ca0))(uVar4);
  iVar3 = encode_gost_algor_params(puStack_194);
  uStack_150 = 0;
  if (iVar3 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar7 = (**(code **)(puStack_158 + -0x7ed4))(puStack_194);
    if (iVar7 == 0x32b) {
      iVar7 = (**(code **)(puStack_158 + -0x57fc))(puStack_194);
      if (iVar7 == 0) goto LAB_0061bbb0;
      uVar4 = (**(code **)(puStack_158 + -0x6dd4))(iVar7);
    }
    else if ((iVar7 == 0x32c) &&
            (iVar7 = (**(code **)(puStack_158 + -0x57fc))(puStack_194), iVar7 != 0)) {
      uVar4 = *(undefined4 *)(iVar7 + 0x1c);
    }
    else {
LAB_0061bbb0:
      uVar4 = 0;
    }
    uVar4 = (**(code **)(puStack_158 + -0x7cec))(uVar4,0);
    puStack_194 = (undefined4 *)(**(code **)(puStack_158 + -0x69ec))(uVar4,&uStack_150);
    (**(code **)(puStack_158 + -0x7f4c))(uVar4);
    pcVar17 = (char *)0x0;
    uStack_164 = uStack_150;
    puVar5 = puStack_184;
    iStack_168 = iVar3;
    puStack_160 = puStack_194;
    piVar2 = (int *)(**(code **)(puStack_158 + -0x6628))(iStack_188,puStack_184,0,0x10);
    iStack_18c = iVar3;
  }
  if (iStack_14c == *(int *)puStack_190) {
    return piVar2;
  }
  pcStack_17c = priv_print_gost94;
  iVar3 = iStack_14c;
  (**(code **)(puStack_158 + -0x5328))();
  puVar8 = PTR___stack_chk_guard_006aabf0;
  iVar7 = 0x80;
  iStack_19c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar18 = pcVar17;
  piVar2 = (int *)(*(code *)PTR_BIO_indent_006a97d0)();
  if (piVar2 == (int *)0x0) goto LAB_0061bd00;
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Private key: ");
  iVar7 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar5);
  if (iVar7 == 0x32b) {
    iVar7 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar5);
    if ((iVar7 != 0) && (iVar7 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar7), iVar7 != 0)
       ) goto LAB_0061bef8;
LAB_0061bd6c:
    (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"<undefined>");
  }
  else {
    if ((iVar7 != 0x32c) ||
       ((iVar7 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar5), iVar7 == 0 ||
        (iVar7 = *(int *)(iVar7 + 0x1c), iVar7 == 0)))) goto LAB_0061bd6c;
LAB_0061bef8:
    (*(code *)PTR_BN_print_006a8024)(iVar3,iVar7);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
  iVar7 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar5);
  uVar4 = *(undefined4 *)(iVar7 + 0x18);
  (*(code *)PTR_BIO_indent_006a97d0)(iVar3,pcVar17,0x80);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Public key: ");
  (*(code *)PTR_BN_print_006a8024)(iVar3,uVar4);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
  iVar7 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar5);
  uStack_1a0 = (*(code *)PTR_BN_new_006a82b4)();
  if (*(int *)(PTR_R3410_paramset_006aa708 + 0xc) != 0) {
    puVar5 = (undefined4 *)PTR_R3410_paramset_006aa708;
    do {
      (*(code *)PTR_BN_dec2bn_006a8f20)(&uStack_1a0);
      iVar11 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_1a0,*(undefined4 *)(iVar7 + 0x10));
      if (iVar11 == 0) {
        (*(code *)PTR_BN_free_006a811c)(uStack_1a0);
        uVar4 = *puVar5;
        goto LAB_0061be90;
      }
      piVar2 = puVar5 + 7;
      puVar5 = puVar5 + 4;
    } while (*piVar2 != 0);
  }
  uVar4 = 0;
  (*(code *)PTR_BN_free_006a811c)(uStack_1a0);
LAB_0061be90:
  (*(code *)PTR_BIO_indent_006a97d0)(iVar3,pcVar17,0x80);
  iVar7 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar4);
  pcVar18 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Parameter set: %s\n",iVar7);
  piVar2 = (int *)0x1;
LAB_0061bd00:
  if (iStack_19c == *(int *)puVar8) {
    return piVar2;
  }
  iVar3 = iStack_19c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar11 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar11 != 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar11);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar11);
    uVar6 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar11);
    uVar12 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar18);
    uVar12 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(uVar12);
    uVar13 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar18);
    uVar13 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar13);
    iVar14 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                       (uVar13,uVar12,uVar4,uVar6,iVar11);
    if (iVar14 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1d8);
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar11);
      return (int *)0x0;
    }
    iVar14 = (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar7,0x80);
    if (iVar14 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Public key:\n");
      iVar14 = (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar7 + 3,0x80);
      if (iVar14 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,&DAT_0067b064);
        (*(code *)PTR_BN_print_006a8024)(iVar3,uVar4);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
        (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar7 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,&DAT_0067b068);
        (*(code *)PTR_BN_print_006a8024)(iVar3,uVar6);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
        (*(code *)PTR_BN_CTX_end_006a9654)(iVar11);
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar11);
        uVar4 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar18);
        uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar4);
        uVar4 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar4);
        iVar7 = (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar7,0x80);
        if (iVar7 != 0) {
          uVar4 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar4);
          (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Parameter set: %s\n",uVar4);
          return (int *)0x1;
        }
      }
    }
    return (int *)0x0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1ce);
  return (int *)0x0;
}

