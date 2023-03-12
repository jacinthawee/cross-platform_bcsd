
/* WARNING: Type propagation algorithm not settling */

int * gost94_param_encode(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int *piVar15;
  undefined *puVar16;
  char *pcVar17;
  char *pcVar18;
  undefined4 *unaff_s5;
  code *pcVar19;
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
  undefined4 *puStack_138;
  undefined4 *puStack_134;
  undefined *puStack_130;
  undefined *puStack_12c;
  undefined4 *puStack_128;
  char *pcStack_124;
  undefined4 *puStack_120;
  code *pcStack_11c;
  undefined4 **ppuStack_108;
  undefined *puStack_100;
  undefined4 *puStack_f4;
  undefined4 *puStack_f0;
  int iStack_ec;
  int iStack_e4;
  undefined4 uStack_e0;
  char *pcStack_dc;
  undefined *puStack_d8;
  code *pcStack_d4;
  undefined4 uStack_c0;
  int iStack_bc;
  undefined *puStack_b8;
  undefined4 *puStack_b0;
  int iStack_ac;
  undefined4 uStack_a8;
  undefined4 *puStack_a4;
  int *piStack_a0;
  int *piStack_9c;
  undefined4 *puStack_98;
  undefined *puStack_94;
  undefined *puStack_90;
  undefined4 *puStack_8c;
  undefined4 uStack_60;
  int iStack_5c;
  undefined4 *puStack_54;
  int iStack_50;
  undefined4 *puStack_4c;
  undefined *puStack_48;
  undefined4 uStack_44;
  undefined4 local_20;
  int *local_1c;
  
  puStack_94 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int **)PTR___stack_chk_guard_006aabf0;
  iStack_50 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  local_20 = (*(code *)PTR_BN_new_006a82b4)();
  puStack_4c = &local_20;
  iVar14 = *(int *)(PTR_R3410_paramset_006aa708 + 0xc);
  puStack_54 = (undefined4 *)PTR_R3410_paramset_006aa708;
  while (iVar14 != 0) {
    (*(code *)PTR_BN_dec2bn_006a8f20)(puStack_4c);
    iVar14 = (*(code *)PTR_BN_cmp_006a8a4c)(local_20,*(undefined4 *)(iStack_50 + 0x10));
    if (iVar14 == 0) {
      (*(code *)PTR_BN_free_006a811c)(local_20);
      uVar13 = *puStack_54;
      goto LAB_0061b0b4;
    }
    iVar14 = puStack_54[7];
    puStack_54 = puStack_54 + 4;
  }
  (*(code *)PTR_BN_free_006a811c)(local_20);
  uVar13 = 0;
LAB_0061b0b4:
  uVar13 = (*(code *)PTR_OBJ_nid2obj_006a8240)(uVar13);
  piVar2 = (int *)(*(code *)PTR_i2d_ASN1_OBJECT_006aa970)(uVar13,param_2);
  if (local_1c == *(int **)puStack_94) {
    return piVar2;
  }
  piStack_a0 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_12c = PTR___stack_chk_guard_006aabf0;
  puStack_48 = puStack_94;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_44 = param_2;
  piVar2 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
  puStack_98 = (undefined4 *)GOST_KEY_PARAMS_new();
  if ((piVar2 == (int *)0x0) || (puStack_98 == (undefined4 *)0x0)) {
    uVar13 = 0x31;
    piVar15 = (int *)&DAT_00000041;
LAB_0061b320:
    ERR_GOST_error(100,piVar15,"gost_ameth.c",uVar13);
    piStack_9c = (int *)0x0;
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(piVar2);
  }
  else {
    iVar14 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(piStack_a0);
    if (iVar14 == 0x32b) {
      uVar13 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piStack_a0);
      uVar13 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar13);
      iVar14 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar13);
    }
    else {
      if (iVar14 == 0x32c) {
        puStack_94 = (undefined *)(*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piStack_a0);
        uStack_60 = (*(code *)PTR_BN_new_006a82b4)();
        unaff_s5 = &uStack_60;
        iVar14 = *(int *)(PTR_R3410_paramset_006aa708 + 0xc);
        piStack_a0 = (int *)PTR_R3410_paramset_006aa708;
        while (iVar14 != 0) {
          (*(code *)PTR_BN_dec2bn_006a8f20)(unaff_s5);
          iVar14 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_60,*(undefined4 *)(puStack_94 + 0x10));
          if (iVar14 == 0) {
            (*(code *)PTR_BN_free_006a811c)(uStack_60);
            iVar14 = *piStack_a0;
            if (iVar14 != 0) goto LAB_0061b1a4;
            goto LAB_0061b310;
          }
          iVar14 = piStack_a0[7];
          piStack_a0 = piStack_a0 + 4;
        }
        (*(code *)PTR_BN_free_006a811c)(uStack_60);
LAB_0061b310:
        uVar13 = 0x40;
        piVar15 = (int *)&DAT_0000006d;
        goto LAB_0061b320;
      }
      iVar14 = 0;
    }
LAB_0061b1a4:
    uVar13 = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar14);
    puVar6 = PTR_OBJ_nid2obj_006a8240;
    *puStack_98 = uVar13;
    uVar13 = (*(code *)puVar6)(0x336);
    piVar15 = piVar2 + 2;
    puStack_98[1] = uVar13;
    iVar14 = i2d_GOST_KEY_PARAMS(puStack_98);
    *piVar2 = iVar14;
    if (iVar14 < 1) {
      uVar13 = 0x4e;
      piVar15 = (int *)&DAT_00000041;
      goto LAB_0061b320;
    }
    piVar2[1] = 0x10;
    piStack_9c = piVar2;
  }
  GOST_KEY_PARAMS_free(puStack_98);
  if (iStack_5c == *(int *)puStack_12c) {
    return piStack_9c;
  }
  iStack_ac = iStack_5c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_130 = PTR___stack_chk_guard_006aabf0;
  puStack_b8 = &_gp;
  puStack_90 = puStack_12c;
  uStack_a8 = 0;
  puStack_a4 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  puStack_8c = unaff_s5;
  uStack_e0 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piVar15);
  uVar13 = (**(code **)(puStack_b8 + -0x7ed4))(piVar15);
  puStack_b0 = (undefined4 *)(**(code **)(puStack_b8 + -0x7ca0))(uVar13);
  if (piVar15[6] == 0) {
    pcStack_124 = (char *)0xffffffff;
    puStack_120 = (undefined4 *)0x0;
  }
  else {
    puStack_120 = (undefined4 *)encode_gost_algor_params(piVar15);
    pcStack_124 = &SUB_00000010;
  }
  iStack_e4 = (**(code **)(puStack_b8 + -0x7c2c))();
  uVar13 = (**(code **)(puStack_b8 + -0x7760))(uStack_e0);
  (**(code **)(puStack_b8 + -0x7bf4))(uVar13,iStack_e4,0);
  pcStack_dc = (char *)(**(code **)(puStack_b8 + -0x7310))(uStack_e0);
  if (pcStack_dc == (char *)0x0) {
    puStack_138 = (undefined4 *)0x2f6;
    pcVar17 = "gost_ameth.c";
    puVar3 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    piVar2 = (int *)0x0;
  }
  else {
    uVar13 = (**(code **)(puStack_b8 + -0x7c2c))();
    puVar3 = (undefined4 *)(**(code **)(puStack_b8 + -0x7c2c))();
    uVar4 = (**(code **)(puStack_b8 + -0x7760))(uStack_e0);
    uStack_c0 = 0;
    puStack_138 = puVar3;
    (**(code **)(puStack_b8 + -0x6724))(uVar4,pcStack_dc,uVar13);
    iVar5 = (**(code **)(puStack_b8 + -0x7bec))(iStack_e4);
    iVar14 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar14 = iVar5 + 0xe;
    }
    iVar14 = iVar14 >> 3;
    (**(code **)(puStack_b8 + -0x7dc4))(iStack_e4);
    pcStack_dc = (char *)(iVar14 << 1);
    puStack_12c = (undefined *)(**(code **)(puStack_b8 + -0x7dd8))(pcStack_dc,"gost_ameth.c",0x2ff);
    unaff_s5 = (undefined4 *)(puStack_12c + iVar14);
    (**(code **)(puStack_b8 + -0x53e0))(puStack_12c,0,pcStack_dc);
    (**(code **)(puStack_b8 + -0x55bc))(uVar13,unaff_s5,iVar14);
    (**(code **)(puStack_b8 + -0x55bc))(puVar3,puStack_12c,iVar14);
    (**(code **)(puStack_b8 + -0x7dc4))(uVar13);
    (**(code **)(puStack_b8 + -0x7dc4))(puVar3);
    uStack_e0 = (**(code **)(puStack_b8 + -0x6754))();
    pcVar17 = pcStack_dc;
    (**(code **)(puStack_b8 + -0x70d4))(uStack_e0,0);
    puVar6 = (undefined *)(**(code **)(puStack_b8 + -0x7ab0))(uStack_e0);
    puVar16 = (undefined *)((int)unaff_s5 + iVar14);
    if (0 < (int)pcStack_dc) {
      do {
        puVar1 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        *puVar6 = *puVar1;
        puVar6 = puVar6 + 1;
      } while (puStack_12c != puVar16);
    }
    (**(code **)(puStack_b8 + -0x7f58))(puStack_12c);
    puVar3 = &uStack_a8;
    iStack_e4 = (**(code **)(puStack_b8 + -0x69e8))(uStack_e0);
    (**(code **)(puStack_b8 + -0x674c))(uStack_e0);
    if (iStack_e4 < 0) {
      piVar2 = (int *)0x0;
    }
    else {
      uStack_c0 = uStack_a8;
      puVar3 = puStack_b0;
      pcVar17 = pcStack_124;
      puStack_138 = puStack_120;
      iStack_bc = iStack_e4;
      piVar2 = (int *)(**(code **)(puStack_b8 + -0x6618))(iStack_ac);
    }
  }
  if (puStack_a4 == *(undefined4 **)puStack_130) {
    return piVar2;
  }
  pcStack_d4 = pkey_ctrl_gost;
  puStack_134 = puStack_a4;
  (**(code **)(puStack_b8 + -0x5328))();
  puStack_13c = PTR___stack_chk_guard_006aabf0;
  puStack_d8 = puStack_130;
  puStack_100 = &_gp;
  iStack_ec = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar7 = &switchD_0061b724::switchdataD_0067b080 + (int)puVar3;
  puVar8 = puStack_138;
  switch(puVar3) {
  default:
    piVar2 = (int *)&SUB_fffffffe;
    break;
  case (undefined4 *)0x1:
    piVar2 = (int *)0x1;
    if (pcVar17 == (char *)0x0) {
      puStack_f4 = (undefined4 *)0x0;
      puStack_f0 = (undefined4 *)0x0;
      puVar8 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      (**(code **)(puStack_100 + -0x5720))(puStack_138,0,&puStack_f4,&puStack_f0);
LAB_0061b778:
      puStack_134 = puStack_f4;
      ppuVar7 = (undefined **)(**(code **)(puStack_100 + -0x7ca0))(0x329);
      (**(code **)(puStack_100 + -0x60dc))(puStack_134,ppuVar7,5,0);
      puStack_138 = puStack_f0;
      if (puVar8 == (undefined4 *)0x0) goto LAB_0061b8f0;
      ppuVar7 = (undefined **)(**(code **)(puStack_100 + -0x7ca0))(puVar8);
      puVar6 = (undefined *)0x0;
      uVar13 = 5;
      pcVar19 = *(code **)(puStack_100 + -0x60dc);
LAB_0061b820:
      (*pcVar19)(puStack_138,ppuVar7,uVar13,puVar6);
      piVar2 = (int *)0x1;
    }
    break;
  case (undefined4 *)0x2:
    piVar2 = (int *)0x1;
    if (pcVar17 == (char *)0x0) {
      puStack_130 = (undefined *)encode_gost_algor_params();
      if (puStack_130 == (undefined *)0x0) goto LAB_0061b8f0;
      (**(code **)(puStack_100 + -0x56b4))(puStack_138,&puStack_f0);
      puVar6 = puStack_130;
LAB_0061b800:
      puStack_138 = puStack_f0;
      ppuVar7 = (undefined **)(**(code **)(puStack_100 + -0x7ca0))(*puStack_134);
      uVar13 = 0x10;
      pcVar19 = *(code **)(puStack_100 + -0x60dc);
      puStack_130 = puVar6;
      goto LAB_0061b820;
    }
    break;
  case (undefined4 *)0x3:
    piVar2 = (int *)&SUB_00000002;
    *puStack_138 = 0x329;
    break;
  case (undefined4 *)0x5:
    piVar2 = (int *)0x1;
    if (pcVar17 == (char *)0x0) {
      puStack_f4 = (undefined4 *)0x0;
      puStack_f0 = (undefined4 *)0x0;
      puVar8 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      ppuStack_108 = &puStack_f0;
      (**(code **)(puStack_100 + -0x5ac0))(puStack_138,0,0,&puStack_f4);
      goto LAB_0061b778;
    }
    break;
  case (undefined4 *)0x7:
    piVar2 = (int *)0x1;
    if (pcVar17 == (char *)0x0) {
      puStack_130 = (undefined *)encode_gost_algor_params();
      if (puStack_130 != (undefined *)0x0) {
        (**(code **)(puStack_100 + -0x56b8))(puStack_138,0,0,&puStack_f0);
        puVar6 = puStack_130;
        goto LAB_0061b800;
      }
LAB_0061b8f0:
      puStack_138 = puVar8;
      piVar2 = (int *)0xffffffff;
    }
  }
  if (iStack_ec == *(int *)puStack_13c) {
    return piVar2;
  }
  pcStack_11c = pub_encode_gost94;
  iStack_1c4 = iStack_ec;
  (**(code **)(puStack_100 + -0x5328))();
  puStack_17c = PTR___stack_chk_guard_006aabf0;
  puStack_150 = &_gp;
  uStack_148 = 0;
  iStack_144 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_128 = unaff_s5;
  iVar14 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(ppuVar7);
  uVar13 = (**(code **)(puStack_150 + -0x7ed4))(ppuVar7);
  puStack_174 = (undefined4 *)(**(code **)(puStack_150 + -0x7ca0))(uVar13);
  if (ppuVar7[6] == (undefined *)0x0) {
    pcStack_170 = (char *)0xffffffff;
    uStack_1b8 = 0;
  }
  else {
    uStack_1b8 = encode_gost_algor_params(ppuVar7);
    pcStack_170 = (char *)0x10;
  }
  iVar9 = (**(code **)(puStack_150 + -0x7bec))(*(undefined4 *)(iVar14 + 0x18));
  iVar5 = iVar9 + 7;
  if (iVar9 + 7 < 0) {
    iVar5 = iVar9 + 0xe;
  }
  pcVar18 = (char *)(iVar5 >> 3);
  iVar5 = (**(code **)(puStack_150 + -0x7dd8))(pcVar18,"gost_ameth.c",0x291);
  (**(code **)(puStack_150 + -0x7be0))(*(undefined4 *)(iVar14 + 0x18),iVar5);
  uVar13 = (**(code **)(puStack_150 + -0x6754))();
  pcVar17 = pcVar18;
  (**(code **)(puStack_150 + -0x70d4))(uVar13,0);
  puVar6 = (undefined *)(**(code **)(puStack_150 + -0x7ab0))(uVar13);
  iVar14 = iVar5 + (int)pcVar18;
  if (0 < (int)pcVar18) {
    do {
      puVar16 = (undefined *)(iVar14 + -1);
      iVar14 = iVar14 + -1;
      *puVar6 = *puVar16;
      puVar6 = puVar6 + 1;
    } while (iVar5 != iVar14);
  }
  (**(code **)(puStack_150 + -0x7f58))(iVar5);
  puStack_1cc = &uStack_148;
  iStack_180 = (**(code **)(puStack_150 + -0x69e8))(uVar13);
  (**(code **)(puStack_150 + -0x674c))(uVar13);
  if (iStack_180 < 0) {
    piVar2 = (int *)0x0;
  }
  else {
    uStack_158 = uStack_148;
    puStack_1cc = puStack_174;
    pcVar17 = pcStack_170;
    iStack_154 = iStack_180;
    piVar2 = (int *)(**(code **)(puStack_150 + -0x6618))
                              (iStack_1c4,puStack_174,pcStack_170,uStack_1b8);
  }
  if (iStack_144 == *(int *)puStack_17c) {
    return piVar2;
  }
  pcStack_16c = priv_encode_gost;
  iStack_1c0 = iStack_144;
  (**(code **)(puStack_150 + -0x5328))();
  puStack_1c8 = PTR___stack_chk_guard_006aabf0;
  puStack_190 = &_gp;
  iStack_184 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar3 = puStack_1cc;
  iStack_178 = iStack_1c4;
  uVar13 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puStack_1cc);
  puStack_1bc = (undefined4 *)(**(code **)(puStack_190 + -0x7ca0))(uVar13);
  iVar14 = encode_gost_algor_params(puStack_1cc);
  uStack_188 = 0;
  if (iVar14 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar5 = (**(code **)(puStack_190 + -0x7ed4))(puStack_1cc);
    if (iVar5 == 0x32b) {
      iVar5 = (**(code **)(puStack_190 + -0x57fc))(puStack_1cc);
      if (iVar5 == 0) goto LAB_0061bbb0;
      uVar13 = (**(code **)(puStack_190 + -0x6dd4))(iVar5);
    }
    else if ((iVar5 == 0x32c) &&
            (iVar5 = (**(code **)(puStack_190 + -0x57fc))(puStack_1cc), iVar5 != 0)) {
      uVar13 = *(undefined4 *)(iVar5 + 0x1c);
    }
    else {
LAB_0061bbb0:
      uVar13 = 0;
    }
    uVar13 = (**(code **)(puStack_190 + -0x7cec))(uVar13,0);
    puStack_1cc = (undefined4 *)(**(code **)(puStack_190 + -0x69ec))(uVar13,&uStack_188);
    (**(code **)(puStack_190 + -0x7f4c))(uVar13);
    pcVar17 = (char *)0x0;
    uStack_19c = uStack_188;
    puVar3 = puStack_1bc;
    iStack_1a0 = iVar14;
    puStack_198 = puStack_1cc;
    piVar2 = (int *)(**(code **)(puStack_190 + -0x6628))(iStack_1c0,puStack_1bc,0,0x10);
    iStack_1c4 = iVar14;
  }
  if (iStack_184 == *(int *)puStack_1c8) {
    return piVar2;
  }
  pcStack_1b4 = priv_print_gost94;
  iVar14 = iStack_184;
  (**(code **)(puStack_190 + -0x5328))();
  puVar6 = PTR___stack_chk_guard_006aabf0;
  iVar5 = 0x80;
  iStack_1d4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar18 = pcVar17;
  piVar2 = (int *)(*(code *)PTR_BIO_indent_006a97d0)();
  if (piVar2 == (int *)0x0) goto LAB_0061bd00;
  (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"Private key: ");
  iVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar3);
  if (iVar5 == 0x32b) {
    iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar3);
    if ((iVar5 != 0) && (iVar5 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar5), iVar5 != 0)
       ) goto LAB_0061bef8;
LAB_0061bd6c:
    (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"<undefined>");
  }
  else {
    if ((iVar5 != 0x32c) ||
       ((iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar3), iVar5 == 0 ||
        (iVar5 = *(int *)(iVar5 + 0x1c), iVar5 == 0)))) goto LAB_0061bd6c;
LAB_0061bef8:
    (*(code *)PTR_BN_print_006a8024)(iVar14,iVar5);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar3);
  uVar13 = *(undefined4 *)(iVar5 + 0x18);
  (*(code *)PTR_BIO_indent_006a97d0)(iVar14,pcVar17,0x80);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"Public key: ");
  (*(code *)PTR_BN_print_006a8024)(iVar14,uVar13);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar3);
  uStack_1d8 = (*(code *)PTR_BN_new_006a82b4)();
  if (*(int *)(PTR_R3410_paramset_006aa708 + 0xc) != 0) {
    puVar3 = (undefined4 *)PTR_R3410_paramset_006aa708;
    do {
      (*(code *)PTR_BN_dec2bn_006a8f20)(&uStack_1d8);
      iVar9 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_1d8,*(undefined4 *)(iVar5 + 0x10));
      if (iVar9 == 0) {
        (*(code *)PTR_BN_free_006a811c)(uStack_1d8);
        uVar13 = *puVar3;
        goto LAB_0061be90;
      }
      piVar2 = puVar3 + 7;
      puVar3 = puVar3 + 4;
    } while (*piVar2 != 0);
  }
  uVar13 = 0;
  (*(code *)PTR_BN_free_006a811c)(uStack_1d8);
LAB_0061be90:
  (*(code *)PTR_BIO_indent_006a97d0)(iVar14,pcVar17,0x80);
  iVar5 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar13);
  pcVar18 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"Parameter set: %s\n",iVar5);
  piVar2 = (int *)0x1;
LAB_0061bd00:
  if (iStack_1d4 == *(int *)puVar6) {
    return piVar2;
  }
  iVar14 = iStack_1d4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar9 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar9 != 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar9);
    uVar13 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar9);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar9);
    uVar10 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar18);
    uVar10 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(uVar10);
    uVar11 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar18);
    uVar11 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar11);
    iVar12 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                       (uVar11,uVar10,uVar13,uVar4,iVar9);
    if (iVar12 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1d8);
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar9);
      return (int *)0x0;
    }
    iVar12 = (*(code *)PTR_BIO_indent_006a97d0)(iVar14,iVar5,0x80);
    if (iVar12 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"Public key:\n");
      iVar12 = (*(code *)PTR_BIO_indent_006a97d0)(iVar14,iVar5 + 3,0x80);
      if (iVar12 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar14,&DAT_0067b064);
        (*(code *)PTR_BN_print_006a8024)(iVar14,uVar13);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"\n");
        (*(code *)PTR_BIO_indent_006a97d0)(iVar14,iVar5 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar14,&DAT_0067b068);
        (*(code *)PTR_BN_print_006a8024)(iVar14,uVar4);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"\n");
        (*(code *)PTR_BN_CTX_end_006a9654)(iVar9);
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar9);
        uVar13 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar18);
        uVar13 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar13);
        uVar13 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar13);
        iVar5 = (*(code *)PTR_BIO_indent_006a97d0)(iVar14,iVar5,0x80);
        if (iVar5 != 0) {
          uVar13 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar13);
          (*(code *)PTR_BIO_printf_006a7f38)(iVar14,"Parameter set: %s\n",uVar13);
          return (int *)0x1;
        }
      }
    }
    return (int *)0x0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1ce);
  return (int *)0x0;
}

