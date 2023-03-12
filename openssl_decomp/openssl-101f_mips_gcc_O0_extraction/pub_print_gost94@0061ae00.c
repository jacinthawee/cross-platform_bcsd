
/* WARNING: Type propagation algorithm not settling */

int * pub_print_gost94(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int *piVar14;
  undefined *puVar15;
  char *pcVar16;
  char *pcVar17;
  undefined4 uVar18;
  code *pcVar19;
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
  undefined4 *puStack_178;
  undefined4 *puStack_174;
  undefined *puStack_170;
  undefined *puStack_16c;
  undefined4 *puStack_168;
  char *pcStack_164;
  undefined4 *puStack_160;
  code *pcStack_15c;
  undefined4 **ppuStack_148;
  undefined *puStack_140;
  undefined4 *puStack_134;
  undefined4 *puStack_130;
  int iStack_12c;
  int iStack_124;
  undefined4 uStack_120;
  char *pcStack_11c;
  undefined *puStack_118;
  code *pcStack_114;
  undefined4 uStack_100;
  int iStack_fc;
  undefined *puStack_f8;
  undefined4 *puStack_f0;
  int iStack_ec;
  undefined4 uStack_e8;
  undefined4 *puStack_e4;
  int *piStack_e0;
  int *piStack_dc;
  undefined4 *puStack_d8;
  undefined *puStack_d4;
  undefined *puStack_d0;
  undefined4 *puStack_cc;
  undefined4 uStack_a0;
  int iStack_9c;
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
  
  puStack_4c = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  uVar18 = *(undefined4 *)(iVar2 + 0x18);
  (**(code **)(local_30 + -0x6710))(param_1,param_3,0x80);
  (**(code **)(local_30 + -0x7fa8))(param_1,"Public key: ");
  (**(code **)(local_30 + -0x7ebc))(param_1,uVar18);
  (**(code **)(local_30 + -0x7fa8))(param_1,"\n");
  iStack_54 = (**(code **)(local_30 + -0x57fc))(param_2);
  local_28 = (**(code **)(local_30 + -0x7c2c))();
  puStack_168 = &local_28;
  if ((*(undefined4 **)(local_30 + -0x57d8))[3] == 0) {
LAB_0061af44:
    uStack_58 = 0;
    (**(code **)(local_30 + -0x7dc4))(local_28);
  }
  else {
    pcVar19 = *(code **)(local_30 + -0x6fc0);
    puVar4 = *(undefined4 **)(local_30 + -0x57d8);
    while( true ) {
      (*pcVar19)(puStack_168);
      iVar2 = (**(code **)(local_30 + -0x7494))(local_28,*(undefined4 *)(iStack_54 + 0x10));
      if (iVar2 == 0) break;
      if (puVar4[7] == 0) goto LAB_0061af44;
      pcVar19 = *(code **)(local_30 + -0x6fc0);
      puVar4 = puVar4 + 4;
    }
    (**(code **)(local_30 + -0x7dc4))(local_28);
    uStack_58 = *puVar4;
  }
  (**(code **)(local_30 + -0x6710))(param_1,param_3,0x80);
  uVar18 = (**(code **)(local_30 + -0x7cc4))(uStack_58);
  pcStack_84 = "Parameter set: %s\n";
  (**(code **)(local_30 + -0x7fa8))(param_1,"Parameter set: %s\n",uVar18);
  if (local_24 == *(int *)puStack_4c) {
    return (int *)0x1;
  }
  pcStack_44 = gost94_param_encode;
  (**(code **)(local_30 + -0x5328))();
  puStack_d4 = PTR___stack_chk_guard_006aabf0;
  puStack_68 = &_gp;
  piStack_5c = *(int **)PTR___stack_chk_guard_006aabf0;
  uStack_50 = param_1;
  uStack_48 = param_3;
  iStack_90 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  uStack_60 = (**(code **)(puStack_68 + -0x7c2c))();
  puStack_94 = *(undefined4 **)(puStack_68 + -0x57d8);
  puStack_8c = &uStack_60;
  if (puStack_94[3] == 0) {
LAB_0061b0a0:
    (**(code **)(puStack_68 + -0x7dc4))(uStack_60);
    uVar18 = 0;
  }
  else {
    pcVar19 = *(code **)(puStack_68 + -0x6fc0);
    puVar4 = puStack_94;
    while( true ) {
      (*pcVar19)(puStack_8c);
      iVar2 = (**(code **)(puStack_68 + -0x7494))(uStack_60,*(undefined4 *)(iStack_90 + 0x10));
      if (iVar2 == 0) break;
      puStack_94 = puVar4 + 4;
      if (puVar4[7] == 0) goto LAB_0061b0a0;
      pcVar19 = *(code **)(puStack_68 + -0x6fc0);
      puVar4 = puStack_94;
    }
    (**(code **)(puStack_68 + -0x7dc4))(uStack_60);
    uVar18 = *puVar4;
    puStack_94 = puVar4;
  }
  uVar18 = (**(code **)(puStack_68 + -0x7ca0))(uVar18);
  piVar3 = (int *)(**(code **)(puStack_68 + -0x5570))(uVar18,pcStack_84);
  if (piStack_5c == *(int **)puStack_d4) {
    return piVar3;
  }
  pcStack_7c = encode_gost_algor_params;
  piStack_e0 = piStack_5c;
  (**(code **)(puStack_68 + -0x5328))();
  puStack_16c = PTR___stack_chk_guard_006aabf0;
  puStack_88 = puStack_d4;
  iStack_9c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_80 = puStack_168;
  piVar3 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
  puStack_d8 = (undefined4 *)GOST_KEY_PARAMS_new();
  if ((piVar3 == (int *)0x0) || (puStack_d8 == (undefined4 *)0x0)) {
    uVar18 = 0x31;
    piVar14 = (int *)&DAT_00000041;
LAB_0061b320:
    ERR_GOST_error(100,piVar14,"gost_ameth.c",uVar18);
    piStack_dc = (int *)0x0;
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(piVar3);
  }
  else {
    iVar2 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(piStack_e0);
    if (iVar2 == 0x32b) {
      uVar18 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piStack_e0);
      uVar18 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar18);
      iVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar18);
    }
    else {
      if (iVar2 == 0x32c) {
        puStack_d4 = (undefined *)(*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piStack_e0);
        uStack_a0 = (*(code *)PTR_BN_new_006a82b4)();
        puStack_168 = &uStack_a0;
        iVar2 = *(int *)(PTR_R3410_paramset_006aa708 + 0xc);
        piStack_e0 = (int *)PTR_R3410_paramset_006aa708;
        while (iVar2 != 0) {
          (*(code *)PTR_BN_dec2bn_006a8f20)(puStack_168);
          iVar2 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_a0,*(undefined4 *)(puStack_d4 + 0x10));
          if (iVar2 == 0) {
            (*(code *)PTR_BN_free_006a811c)(uStack_a0);
            iVar2 = *piStack_e0;
            if (iVar2 != 0) goto LAB_0061b1a4;
            goto LAB_0061b310;
          }
          iVar2 = piStack_e0[7];
          piStack_e0 = piStack_e0 + 4;
        }
        (*(code *)PTR_BN_free_006a811c)(uStack_a0);
LAB_0061b310:
        uVar18 = 0x40;
        piVar14 = (int *)&DAT_0000006d;
        goto LAB_0061b320;
      }
      iVar2 = 0;
    }
LAB_0061b1a4:
    uVar18 = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar2);
    puVar7 = PTR_OBJ_nid2obj_006a8240;
    *puStack_d8 = uVar18;
    uVar18 = (*(code *)puVar7)(0x336);
    piVar14 = piVar3 + 2;
    puStack_d8[1] = uVar18;
    iVar2 = i2d_GOST_KEY_PARAMS(puStack_d8);
    *piVar3 = iVar2;
    if (iVar2 < 1) {
      uVar18 = 0x4e;
      piVar14 = (int *)&DAT_00000041;
      goto LAB_0061b320;
    }
    piVar3[1] = 0x10;
    piStack_dc = piVar3;
  }
  GOST_KEY_PARAMS_free(puStack_d8);
  if (iStack_9c == *(int *)puStack_16c) {
    return piStack_dc;
  }
  iStack_ec = iStack_9c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_170 = PTR___stack_chk_guard_006aabf0;
  puStack_f8 = &_gp;
  puStack_d0 = puStack_16c;
  uStack_e8 = 0;
  puStack_e4 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  puStack_cc = puStack_168;
  uStack_120 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piVar14);
  uVar18 = (**(code **)(puStack_f8 + -0x7ed4))(piVar14);
  puStack_f0 = (undefined4 *)(**(code **)(puStack_f8 + -0x7ca0))(uVar18);
  if (piVar14[6] == 0) {
    pcStack_164 = (char *)0xffffffff;
    puStack_160 = (undefined4 *)0x0;
  }
  else {
    puStack_160 = (undefined4 *)encode_gost_algor_params(piVar14);
    pcStack_164 = &SUB_00000010;
  }
  iStack_124 = (**(code **)(puStack_f8 + -0x7c2c))();
  uVar18 = (**(code **)(puStack_f8 + -0x7760))(uStack_120);
  (**(code **)(puStack_f8 + -0x7bf4))(uVar18,iStack_124,0);
  pcStack_11c = (char *)(**(code **)(puStack_f8 + -0x7310))(uStack_120);
  if (pcStack_11c == (char *)0x0) {
    puStack_178 = (undefined4 *)0x2f6;
    pcVar16 = "gost_ameth.c";
    puVar4 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    piVar3 = (int *)0x0;
  }
  else {
    uVar18 = (**(code **)(puStack_f8 + -0x7c2c))();
    puVar4 = (undefined4 *)(**(code **)(puStack_f8 + -0x7c2c))();
    uVar5 = (**(code **)(puStack_f8 + -0x7760))(uStack_120);
    uStack_100 = 0;
    puStack_178 = puVar4;
    (**(code **)(puStack_f8 + -0x6724))(uVar5,pcStack_11c,uVar18);
    iVar6 = (**(code **)(puStack_f8 + -0x7bec))(iStack_124);
    iVar2 = iVar6 + 7;
    if (iVar6 + 7 < 0) {
      iVar2 = iVar6 + 0xe;
    }
    iVar2 = iVar2 >> 3;
    (**(code **)(puStack_f8 + -0x7dc4))(iStack_124);
    pcStack_11c = (char *)(iVar2 << 1);
    puStack_16c = (undefined *)(**(code **)(puStack_f8 + -0x7dd8))(pcStack_11c,"gost_ameth.c",0x2ff)
    ;
    puStack_168 = (undefined4 *)(puStack_16c + iVar2);
    (**(code **)(puStack_f8 + -0x53e0))(puStack_16c,0,pcStack_11c);
    (**(code **)(puStack_f8 + -0x55bc))(uVar18,puStack_168,iVar2);
    (**(code **)(puStack_f8 + -0x55bc))(puVar4,puStack_16c,iVar2);
    (**(code **)(puStack_f8 + -0x7dc4))(uVar18);
    (**(code **)(puStack_f8 + -0x7dc4))(puVar4);
    uStack_120 = (**(code **)(puStack_f8 + -0x6754))();
    pcVar16 = pcStack_11c;
    (**(code **)(puStack_f8 + -0x70d4))(uStack_120,0);
    puVar7 = (undefined *)(**(code **)(puStack_f8 + -0x7ab0))(uStack_120);
    puVar15 = (undefined *)((int)puStack_168 + iVar2);
    if (0 < (int)pcStack_11c) {
      do {
        puVar1 = puVar15 + -1;
        puVar15 = puVar15 + -1;
        *puVar7 = *puVar1;
        puVar7 = puVar7 + 1;
      } while (puStack_16c != puVar15);
    }
    (**(code **)(puStack_f8 + -0x7f58))(puStack_16c);
    puVar4 = &uStack_e8;
    iStack_124 = (**(code **)(puStack_f8 + -0x69e8))(uStack_120);
    (**(code **)(puStack_f8 + -0x674c))(uStack_120);
    if (iStack_124 < 0) {
      piVar3 = (int *)0x0;
    }
    else {
      uStack_100 = uStack_e8;
      puVar4 = puStack_f0;
      pcVar16 = pcStack_164;
      puStack_178 = puStack_160;
      iStack_fc = iStack_124;
      piVar3 = (int *)(**(code **)(puStack_f8 + -0x6618))(iStack_ec);
    }
  }
  if (puStack_e4 == *(undefined4 **)puStack_170) {
    return piVar3;
  }
  pcStack_114 = pkey_ctrl_gost;
  puStack_174 = puStack_e4;
  (**(code **)(puStack_f8 + -0x5328))();
  puStack_17c = PTR___stack_chk_guard_006aabf0;
  puStack_118 = puStack_170;
  puStack_140 = &_gp;
  iStack_12c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar8 = &switchD_0061b724::switchdataD_0067b060 + (int)puVar4;
  puVar9 = puStack_178;
  switch(puVar4) {
  default:
    piVar3 = (int *)&SUB_fffffffe;
    break;
  case (undefined4 *)0x1:
    piVar3 = (int *)0x1;
    if (pcVar16 == (char *)0x0) {
      puStack_134 = (undefined4 *)0x0;
      puStack_130 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      (**(code **)(puStack_140 + -0x5720))(puStack_178,0,&puStack_134,&puStack_130);
LAB_0061b778:
      puStack_174 = puStack_134;
      ppuVar8 = (undefined **)(**(code **)(puStack_140 + -0x7ca0))(0x329);
      (**(code **)(puStack_140 + -0x60dc))(puStack_174,ppuVar8,5,0);
      puStack_178 = puStack_130;
      if (puVar9 == (undefined4 *)0x0) goto LAB_0061b8f0;
      ppuVar8 = (undefined **)(**(code **)(puStack_140 + -0x7ca0))(puVar9);
      puVar7 = (undefined *)0x0;
      uVar18 = 5;
      pcVar19 = *(code **)(puStack_140 + -0x60dc);
LAB_0061b820:
      (*pcVar19)(puStack_178,ppuVar8,uVar18,puVar7);
      piVar3 = (int *)0x1;
    }
    break;
  case (undefined4 *)0x2:
    piVar3 = (int *)0x1;
    if (pcVar16 == (char *)0x0) {
      puStack_170 = (undefined *)encode_gost_algor_params();
      if (puStack_170 == (undefined *)0x0) goto LAB_0061b8f0;
      (**(code **)(puStack_140 + -0x56b4))(puStack_178,&puStack_130);
      puVar7 = puStack_170;
LAB_0061b800:
      puStack_178 = puStack_130;
      ppuVar8 = (undefined **)(**(code **)(puStack_140 + -0x7ca0))(*puStack_174);
      uVar18 = 0x10;
      pcVar19 = *(code **)(puStack_140 + -0x60dc);
      puStack_170 = puVar7;
      goto LAB_0061b820;
    }
    break;
  case (undefined4 *)0x3:
    piVar3 = (int *)&SUB_00000002;
    *puStack_178 = 0x329;
    break;
  case (undefined4 *)0x5:
    piVar3 = (int *)0x1;
    if (pcVar16 == (char *)0x0) {
      puStack_134 = (undefined4 *)0x0;
      puStack_130 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      ppuStack_148 = &puStack_130;
      (**(code **)(puStack_140 + -0x5ac0))(puStack_178,0,0,&puStack_134);
      goto LAB_0061b778;
    }
    break;
  case (undefined4 *)0x7:
    piVar3 = (int *)0x1;
    if (pcVar16 == (char *)0x0) {
      puStack_170 = (undefined *)encode_gost_algor_params();
      if (puStack_170 != (undefined *)0x0) {
        (**(code **)(puStack_140 + -0x56b8))(puStack_178,0,0,&puStack_130);
        puVar7 = puStack_170;
        goto LAB_0061b800;
      }
LAB_0061b8f0:
      puStack_178 = puVar9;
      piVar3 = (int *)0xffffffff;
    }
  }
  if (iStack_12c == *(int *)puStack_17c) {
    return piVar3;
  }
  pcStack_15c = pub_encode_gost94;
  iStack_204 = iStack_12c;
  (**(code **)(puStack_140 + -0x5328))();
  puStack_1bc = PTR___stack_chk_guard_006aabf0;
  puStack_190 = &_gp;
  uStack_188 = 0;
  iStack_184 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(ppuVar8);
  uVar18 = (**(code **)(puStack_190 + -0x7ed4))(ppuVar8);
  puStack_1b4 = (undefined4 *)(**(code **)(puStack_190 + -0x7ca0))(uVar18);
  if (ppuVar8[6] == (undefined *)0x0) {
    pcStack_1b0 = (char *)0xffffffff;
    uStack_1f8 = 0;
  }
  else {
    uStack_1f8 = encode_gost_algor_params(ppuVar8);
    pcStack_1b0 = (char *)0x10;
  }
  iVar10 = (**(code **)(puStack_190 + -0x7bec))(*(undefined4 *)(iVar2 + 0x18));
  iVar6 = iVar10 + 7;
  if (iVar10 + 7 < 0) {
    iVar6 = iVar10 + 0xe;
  }
  pcVar17 = (char *)(iVar6 >> 3);
  iVar6 = (**(code **)(puStack_190 + -0x7dd8))(pcVar17,"gost_ameth.c",0x291);
  (**(code **)(puStack_190 + -0x7be0))(*(undefined4 *)(iVar2 + 0x18),iVar6);
  uVar18 = (**(code **)(puStack_190 + -0x6754))();
  pcVar16 = pcVar17;
  (**(code **)(puStack_190 + -0x70d4))(uVar18,0);
  puVar7 = (undefined *)(**(code **)(puStack_190 + -0x7ab0))(uVar18);
  iVar2 = iVar6 + (int)pcVar17;
  if (0 < (int)pcVar17) {
    do {
      puVar15 = (undefined *)(iVar2 + -1);
      iVar2 = iVar2 + -1;
      *puVar7 = *puVar15;
      puVar7 = puVar7 + 1;
    } while (iVar6 != iVar2);
  }
  (**(code **)(puStack_190 + -0x7f58))(iVar6);
  puStack_20c = &uStack_188;
  iStack_1c0 = (**(code **)(puStack_190 + -0x69e8))(uVar18);
  (**(code **)(puStack_190 + -0x674c))(uVar18);
  if (iStack_1c0 < 0) {
    piVar3 = (int *)0x0;
  }
  else {
    uStack_198 = uStack_188;
    puStack_20c = puStack_1b4;
    pcVar16 = pcStack_1b0;
    iStack_194 = iStack_1c0;
    piVar3 = (int *)(**(code **)(puStack_190 + -0x6618))
                              (iStack_204,puStack_1b4,pcStack_1b0,uStack_1f8);
  }
  if (iStack_184 == *(int *)puStack_1bc) {
    return piVar3;
  }
  pcStack_1ac = priv_encode_gost;
  iStack_200 = iStack_184;
  (**(code **)(puStack_190 + -0x5328))();
  puStack_208 = PTR___stack_chk_guard_006aabf0;
  puStack_1d0 = &_gp;
  iStack_1c4 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar4 = puStack_20c;
  iStack_1b8 = iStack_204;
  uVar18 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puStack_20c);
  puStack_1fc = (undefined4 *)(**(code **)(puStack_1d0 + -0x7ca0))(uVar18);
  iVar2 = encode_gost_algor_params(puStack_20c);
  uStack_1c8 = 0;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    iVar6 = (**(code **)(puStack_1d0 + -0x7ed4))(puStack_20c);
    if (iVar6 == 0x32b) {
      iVar6 = (**(code **)(puStack_1d0 + -0x57fc))(puStack_20c);
      if (iVar6 == 0) goto LAB_0061bbb0;
      uVar18 = (**(code **)(puStack_1d0 + -0x6dd4))(iVar6);
    }
    else if ((iVar6 == 0x32c) &&
            (iVar6 = (**(code **)(puStack_1d0 + -0x57fc))(puStack_20c), iVar6 != 0)) {
      uVar18 = *(undefined4 *)(iVar6 + 0x1c);
    }
    else {
LAB_0061bbb0:
      uVar18 = 0;
    }
    uVar18 = (**(code **)(puStack_1d0 + -0x7cec))(uVar18,0);
    puStack_20c = (undefined4 *)(**(code **)(puStack_1d0 + -0x69ec))(uVar18,&uStack_1c8);
    (**(code **)(puStack_1d0 + -0x7f4c))(uVar18);
    pcVar16 = (char *)0x0;
    uStack_1dc = uStack_1c8;
    puVar4 = puStack_1fc;
    iStack_1e0 = iVar2;
    puStack_1d8 = puStack_20c;
    piVar3 = (int *)(**(code **)(puStack_1d0 + -0x6628))(iStack_200,puStack_1fc,0,0x10);
    iStack_204 = iVar2;
  }
  if (iStack_1c4 == *(int *)puStack_208) {
    return piVar3;
  }
  pcStack_1f4 = priv_print_gost94;
  iVar2 = iStack_1c4;
  (**(code **)(puStack_1d0 + -0x5328))();
  puVar7 = PTR___stack_chk_guard_006aabf0;
  iVar6 = 0x80;
  iStack_214 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar17 = pcVar16;
  piVar3 = (int *)(*(code *)PTR_BIO_indent_006a97d0)();
  if (piVar3 == (int *)0x0) goto LAB_0061bd00;
  (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"Private key: ");
  iVar6 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar4);
  if (iVar6 == 0x32b) {
    iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar4);
    if ((iVar6 != 0) && (iVar6 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar6), iVar6 != 0)
       ) goto LAB_0061bef8;
LAB_0061bd6c:
    (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"<undefined>");
  }
  else {
    if ((iVar6 != 0x32c) ||
       ((iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar4), iVar6 == 0 ||
        (iVar6 = *(int *)(iVar6 + 0x1c), iVar6 == 0)))) goto LAB_0061bd6c;
LAB_0061bef8:
    (*(code *)PTR_BN_print_006a8024)(iVar2,iVar6);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar4);
  uVar18 = *(undefined4 *)(iVar6 + 0x18);
  (*(code *)PTR_BIO_indent_006a97d0)(iVar2,pcVar16,0x80);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"Public key: ");
  (*(code *)PTR_BN_print_006a8024)(iVar2,uVar18);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar4);
  uStack_218 = (*(code *)PTR_BN_new_006a82b4)();
  if (*(int *)(PTR_R3410_paramset_006aa708 + 0xc) != 0) {
    puVar4 = (undefined4 *)PTR_R3410_paramset_006aa708;
    do {
      (*(code *)PTR_BN_dec2bn_006a8f20)(&uStack_218);
      iVar10 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_218,*(undefined4 *)(iVar6 + 0x10));
      if (iVar10 == 0) {
        (*(code *)PTR_BN_free_006a811c)(uStack_218);
        uVar18 = *puVar4;
        goto LAB_0061be90;
      }
      piVar3 = puVar4 + 7;
      puVar4 = puVar4 + 4;
    } while (*piVar3 != 0);
  }
  uVar18 = 0;
  (*(code *)PTR_BN_free_006a811c)(uStack_218);
LAB_0061be90:
  (*(code *)PTR_BIO_indent_006a97d0)(iVar2,pcVar16,0x80);
  iVar6 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar18);
  pcVar17 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"Parameter set: %s\n",iVar6);
  piVar3 = (int *)0x1;
LAB_0061bd00:
  if (iStack_214 == *(int *)puVar7) {
    return piVar3;
  }
  iVar2 = iStack_214;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar10 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar10 != 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar10);
    uVar18 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar10);
    uVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar10);
    uVar11 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar17);
    uVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(uVar11);
    uVar12 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar17);
    uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar12);
    iVar13 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                       (uVar12,uVar11,uVar18,uVar5,iVar10);
    if (iVar13 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1d8);
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar10);
      return (int *)0x0;
    }
    iVar13 = (*(code *)PTR_BIO_indent_006a97d0)(iVar2,iVar6,0x80);
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"Public key:\n");
      iVar13 = (*(code *)PTR_BIO_indent_006a97d0)(iVar2,iVar6 + 3,0x80);
      if (iVar13 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar2,&DAT_0067b044);
        (*(code *)PTR_BN_print_006a8024)(iVar2,uVar18);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"\n");
        (*(code *)PTR_BIO_indent_006a97d0)(iVar2,iVar6 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar2,&DAT_0067b048);
        (*(code *)PTR_BN_print_006a8024)(iVar2,uVar5);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"\n");
        (*(code *)PTR_BN_CTX_end_006a9654)(iVar10);
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar10);
        uVar18 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar17);
        uVar18 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar18);
        uVar18 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar18);
        iVar6 = (*(code *)PTR_BIO_indent_006a97d0)(iVar2,iVar6,0x80);
        if (iVar6 != 0) {
          uVar18 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar18);
          (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"Parameter set: %s\n",uVar18);
          return (int *)0x1;
        }
      }
    }
    return (int *)0x0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1ce);
  return (int *)0x0;
}

