
/* WARNING: Type propagation algorithm not settling */

int * param_print_gost94(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  char *pcVar14;
  int *piVar15;
  undefined *puVar16;
  char *pcVar17;
  undefined4 uVar18;
  code *pcVar19;
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
  undefined4 *puStack_1b8;
  undefined4 *puStack_1b4;
  undefined *puStack_1b0;
  undefined *puStack_1ac;
  undefined4 *puStack_1a8;
  char *pcStack_1a4;
  undefined4 *puStack_1a0;
  code *pcStack_19c;
  undefined4 **ppuStack_188;
  undefined *puStack_180;
  undefined4 *puStack_174;
  undefined4 *puStack_170;
  int iStack_16c;
  int iStack_164;
  undefined4 uStack_160;
  char *pcStack_15c;
  undefined *puStack_158;
  code *pcStack_154;
  undefined4 uStack_140;
  int iStack_13c;
  undefined *puStack_138;
  undefined4 *puStack_130;
  int iStack_12c;
  undefined4 uStack_128;
  undefined4 *puStack_124;
  int *piStack_120;
  int *piStack_11c;
  undefined4 *puStack_118;
  undefined *puStack_114;
  undefined *puStack_110;
  undefined4 *puStack_10c;
  undefined4 uStack_e0;
  int iStack_dc;
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
  
  puStack_54 = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_58 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  local_28 = (**(code **)(local_30 + -0x7c2c))();
  puStack_48 = &local_28;
  if ((*(undefined4 **)(local_30 + -0x57d8))[3] == 0) {
LAB_0061ad68:
    uStack_5c = 0;
    (**(code **)(local_30 + -0x7dc4))(local_28);
  }
  else {
    pcVar19 = *(code **)(local_30 + -0x6fc0);
    puVar4 = *(undefined4 **)(local_30 + -0x57d8);
    while( true ) {
      (*pcVar19)(puStack_48);
      iVar2 = (**(code **)(local_30 + -0x7494))(local_28,*(undefined4 *)(iStack_58 + 0x10));
      if (iVar2 == 0) break;
      if (puVar4[7] == 0) goto LAB_0061ad68;
      pcVar19 = *(code **)(local_30 + -0x6fc0);
      puVar4 = puVar4 + 4;
    }
    (**(code **)(local_30 + -0x7dc4))(local_28);
    uStack_5c = *puVar4;
  }
  (**(code **)(local_30 + -0x6710))(param_1,param_3,0x80);
  uStack_88 = (**(code **)(local_30 + -0x7cc4))(uStack_5c);
  pcVar14 = "Parameter set: %s\n";
  (**(code **)(local_30 + -0x7fa8))(param_1,"Parameter set: %s\n");
  if (local_24 == *(int *)puStack_54) {
    return (int *)0x1;
  }
  pcStack_44 = pub_print_gost94;
  iStack_90 = local_24;
  (**(code **)(local_30 + -0x5328))();
  puStack_8c = PTR___stack_chk_guard_006aabf0;
  puStack_70 = &_gp;
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_50 = param_1;
  uStack_4c = param_3;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar14);
  uVar18 = *(undefined4 *)(iVar2 + 0x18);
  (**(code **)(puStack_70 + -0x6710))(iStack_90,uStack_88,0x80);
  (**(code **)(puStack_70 + -0x7fa8))(iStack_90,"Public key: ");
  (**(code **)(puStack_70 + -0x7ebc))(iStack_90,uVar18);
  (**(code **)(puStack_70 + -0x7fa8))(iStack_90,"\n");
  iStack_94 = (**(code **)(puStack_70 + -0x57fc))(pcVar14);
  uStack_68 = (**(code **)(puStack_70 + -0x7c2c))();
  puStack_1a8 = &uStack_68;
  if ((*(undefined4 **)(puStack_70 + -0x57d8))[3] == 0) {
LAB_0061af44:
    uStack_98 = 0;
    (**(code **)(puStack_70 + -0x7dc4))(uStack_68);
  }
  else {
    pcVar19 = *(code **)(puStack_70 + -0x6fc0);
    puVar4 = *(undefined4 **)(puStack_70 + -0x57d8);
    while( true ) {
      (*pcVar19)(puStack_1a8);
      iVar2 = (**(code **)(puStack_70 + -0x7494))(uStack_68,*(undefined4 *)(iStack_94 + 0x10));
      if (iVar2 == 0) break;
      if (puVar4[7] == 0) goto LAB_0061af44;
      pcVar19 = *(code **)(puStack_70 + -0x6fc0);
      puVar4 = puVar4 + 4;
    }
    (**(code **)(puStack_70 + -0x7dc4))(uStack_68);
    uStack_98 = *puVar4;
  }
  (**(code **)(puStack_70 + -0x6710))(iStack_90,uStack_88,0x80);
  uVar18 = (**(code **)(puStack_70 + -0x7cc4))(uStack_98);
  pcStack_c4 = "Parameter set: %s\n";
  (**(code **)(puStack_70 + -0x7fa8))(iStack_90,"Parameter set: %s\n",uVar18);
  if (iStack_64 == *(int *)puStack_8c) {
    return (int *)0x1;
  }
  pcStack_84 = gost94_param_encode;
  (**(code **)(puStack_70 + -0x5328))();
  puStack_114 = PTR___stack_chk_guard_006aabf0;
  puStack_a8 = &_gp;
  piStack_9c = *(int **)PTR___stack_chk_guard_006aabf0;
  iStack_d0 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  uStack_a0 = (**(code **)(puStack_a8 + -0x7c2c))();
  puStack_d4 = *(undefined4 **)(puStack_a8 + -0x57d8);
  puStack_cc = &uStack_a0;
  if (puStack_d4[3] == 0) {
LAB_0061b0a0:
    (**(code **)(puStack_a8 + -0x7dc4))(uStack_a0);
    uVar18 = 0;
  }
  else {
    pcVar19 = *(code **)(puStack_a8 + -0x6fc0);
    puVar4 = puStack_d4;
    while( true ) {
      (*pcVar19)(puStack_cc);
      iVar2 = (**(code **)(puStack_a8 + -0x7494))(uStack_a0,*(undefined4 *)(iStack_d0 + 0x10));
      if (iVar2 == 0) break;
      puStack_d4 = puVar4 + 4;
      if (puVar4[7] == 0) goto LAB_0061b0a0;
      pcVar19 = *(code **)(puStack_a8 + -0x6fc0);
      puVar4 = puStack_d4;
    }
    (**(code **)(puStack_a8 + -0x7dc4))(uStack_a0);
    uVar18 = *puVar4;
    puStack_d4 = puVar4;
  }
  uVar18 = (**(code **)(puStack_a8 + -0x7ca0))(uVar18);
  piVar3 = (int *)(**(code **)(puStack_a8 + -0x5570))(uVar18,pcStack_c4);
  if (piStack_9c == *(int **)puStack_114) {
    return piVar3;
  }
  pcStack_bc = encode_gost_algor_params;
  piStack_120 = piStack_9c;
  (**(code **)(puStack_a8 + -0x5328))();
  puStack_1ac = PTR___stack_chk_guard_006aabf0;
  puStack_c8 = puStack_114;
  iStack_dc = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_c0 = puStack_1a8;
  piVar3 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
  puStack_118 = (undefined4 *)GOST_KEY_PARAMS_new();
  if ((piVar3 == (int *)0x0) || (puStack_118 == (undefined4 *)0x0)) {
    uVar18 = 0x31;
    piVar15 = (int *)&DAT_00000041;
LAB_0061b320:
    ERR_GOST_error(100,piVar15,"gost_ameth.c",uVar18);
    piStack_11c = (int *)0x0;
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(piVar3);
  }
  else {
    iVar2 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(piStack_120);
    if (iVar2 == 0x32b) {
      uVar18 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piStack_120);
      uVar18 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar18);
      iVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar18);
    }
    else {
      if (iVar2 == 0x32c) {
        puStack_114 = (undefined *)(*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piStack_120);
        uStack_e0 = (*(code *)PTR_BN_new_006a82b4)();
        puStack_1a8 = &uStack_e0;
        iVar2 = *(int *)(PTR_R3410_paramset_006aa708 + 0xc);
        piStack_120 = (int *)PTR_R3410_paramset_006aa708;
        while (iVar2 != 0) {
          (*(code *)PTR_BN_dec2bn_006a8f20)(puStack_1a8);
          iVar2 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_e0,*(undefined4 *)(puStack_114 + 0x10));
          if (iVar2 == 0) {
            (*(code *)PTR_BN_free_006a811c)(uStack_e0);
            iVar2 = *piStack_120;
            if (iVar2 != 0) goto LAB_0061b1a4;
            goto LAB_0061b310;
          }
          iVar2 = piStack_120[7];
          piStack_120 = piStack_120 + 4;
        }
        (*(code *)PTR_BN_free_006a811c)(uStack_e0);
LAB_0061b310:
        uVar18 = 0x40;
        piVar15 = (int *)&DAT_0000006d;
        goto LAB_0061b320;
      }
      iVar2 = 0;
    }
LAB_0061b1a4:
    uVar18 = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar2);
    puVar7 = PTR_OBJ_nid2obj_006a8240;
    *puStack_118 = uVar18;
    uVar18 = (*(code *)puVar7)(0x336);
    piVar15 = piVar3 + 2;
    puStack_118[1] = uVar18;
    iVar2 = i2d_GOST_KEY_PARAMS(puStack_118);
    *piVar3 = iVar2;
    if (iVar2 < 1) {
      uVar18 = 0x4e;
      piVar15 = (int *)&DAT_00000041;
      goto LAB_0061b320;
    }
    piVar3[1] = 0x10;
    piStack_11c = piVar3;
  }
  GOST_KEY_PARAMS_free(puStack_118);
  if (iStack_dc == *(int *)puStack_1ac) {
    return piStack_11c;
  }
  iStack_12c = iStack_dc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1b0 = PTR___stack_chk_guard_006aabf0;
  puStack_138 = &_gp;
  puStack_110 = puStack_1ac;
  uStack_128 = 0;
  puStack_124 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  puStack_10c = puStack_1a8;
  uStack_160 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(piVar15);
  uVar18 = (**(code **)(puStack_138 + -0x7ed4))(piVar15);
  puStack_130 = (undefined4 *)(**(code **)(puStack_138 + -0x7ca0))(uVar18);
  if (piVar15[6] == 0) {
    pcStack_1a4 = (char *)0xffffffff;
    puStack_1a0 = (undefined4 *)0x0;
  }
  else {
    puStack_1a0 = (undefined4 *)encode_gost_algor_params(piVar15);
    pcStack_1a4 = &SUB_00000010;
  }
  iStack_164 = (**(code **)(puStack_138 + -0x7c2c))();
  uVar18 = (**(code **)(puStack_138 + -0x7760))(uStack_160);
  (**(code **)(puStack_138 + -0x7bf4))(uVar18,iStack_164,0);
  pcStack_15c = (char *)(**(code **)(puStack_138 + -0x7310))(uStack_160);
  if (pcStack_15c == (char *)0x0) {
    puStack_1b8 = (undefined4 *)0x2f6;
    pcVar14 = "gost_ameth.c";
    puVar4 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    piVar3 = (int *)0x0;
  }
  else {
    uVar18 = (**(code **)(puStack_138 + -0x7c2c))();
    puVar4 = (undefined4 *)(**(code **)(puStack_138 + -0x7c2c))();
    uVar5 = (**(code **)(puStack_138 + -0x7760))(uStack_160);
    uStack_140 = 0;
    puStack_1b8 = puVar4;
    (**(code **)(puStack_138 + -0x6724))(uVar5,pcStack_15c,uVar18);
    iVar6 = (**(code **)(puStack_138 + -0x7bec))(iStack_164);
    iVar2 = iVar6 + 7;
    if (iVar6 + 7 < 0) {
      iVar2 = iVar6 + 0xe;
    }
    iVar2 = iVar2 >> 3;
    (**(code **)(puStack_138 + -0x7dc4))(iStack_164);
    pcStack_15c = (char *)(iVar2 << 1);
    puStack_1ac = (undefined *)
                  (**(code **)(puStack_138 + -0x7dd8))(pcStack_15c,"gost_ameth.c",0x2ff);
    puStack_1a8 = (undefined4 *)(puStack_1ac + iVar2);
    (**(code **)(puStack_138 + -0x53e0))(puStack_1ac,0,pcStack_15c);
    (**(code **)(puStack_138 + -0x55bc))(uVar18,puStack_1a8,iVar2);
    (**(code **)(puStack_138 + -0x55bc))(puVar4,puStack_1ac,iVar2);
    (**(code **)(puStack_138 + -0x7dc4))(uVar18);
    (**(code **)(puStack_138 + -0x7dc4))(puVar4);
    uStack_160 = (**(code **)(puStack_138 + -0x6754))();
    pcVar14 = pcStack_15c;
    (**(code **)(puStack_138 + -0x70d4))(uStack_160,0);
    puVar7 = (undefined *)(**(code **)(puStack_138 + -0x7ab0))(uStack_160);
    puVar16 = (undefined *)((int)puStack_1a8 + iVar2);
    if (0 < (int)pcStack_15c) {
      do {
        puVar1 = puVar16 + -1;
        puVar16 = puVar16 + -1;
        *puVar7 = *puVar1;
        puVar7 = puVar7 + 1;
      } while (puStack_1ac != puVar16);
    }
    (**(code **)(puStack_138 + -0x7f58))(puStack_1ac);
    puVar4 = &uStack_128;
    iStack_164 = (**(code **)(puStack_138 + -0x69e8))(uStack_160);
    (**(code **)(puStack_138 + -0x674c))(uStack_160);
    if (iStack_164 < 0) {
      piVar3 = (int *)0x0;
    }
    else {
      uStack_140 = uStack_128;
      puVar4 = puStack_130;
      pcVar14 = pcStack_1a4;
      puStack_1b8 = puStack_1a0;
      iStack_13c = iStack_164;
      piVar3 = (int *)(**(code **)(puStack_138 + -0x6618))(iStack_12c);
    }
  }
  if (puStack_124 == *(undefined4 **)puStack_1b0) {
    return piVar3;
  }
  pcStack_154 = pkey_ctrl_gost;
  puStack_1b4 = puStack_124;
  (**(code **)(puStack_138 + -0x5328))();
  puStack_1bc = PTR___stack_chk_guard_006aabf0;
  puStack_158 = puStack_1b0;
  puStack_180 = &_gp;
  iStack_16c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar8 = &switchD_0061b724::switchdataD_0067b060 + (int)puVar4;
  puVar9 = puStack_1b8;
  switch(puVar4) {
  default:
    piVar3 = (int *)&SUB_fffffffe;
    break;
  case (undefined4 *)0x1:
    piVar3 = (int *)0x1;
    if (pcVar14 == (char *)0x0) {
      puStack_174 = (undefined4 *)0x0;
      puStack_170 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      (**(code **)(puStack_180 + -0x5720))(puStack_1b8,0,&puStack_174,&puStack_170);
LAB_0061b778:
      puStack_1b4 = puStack_174;
      ppuVar8 = (undefined **)(**(code **)(puStack_180 + -0x7ca0))(0x329);
      (**(code **)(puStack_180 + -0x60dc))(puStack_1b4,ppuVar8,5,0);
      puStack_1b8 = puStack_170;
      if (puVar9 == (undefined4 *)0x0) goto LAB_0061b8f0;
      ppuVar8 = (undefined **)(**(code **)(puStack_180 + -0x7ca0))(puVar9);
      puVar7 = (undefined *)0x0;
      uVar18 = 5;
      pcVar19 = *(code **)(puStack_180 + -0x60dc);
LAB_0061b820:
      (*pcVar19)(puStack_1b8,ppuVar8,uVar18,puVar7);
      piVar3 = (int *)0x1;
    }
    break;
  case (undefined4 *)0x2:
    piVar3 = (int *)0x1;
    if (pcVar14 == (char *)0x0) {
      puStack_1b0 = (undefined *)encode_gost_algor_params();
      if (puStack_1b0 == (undefined *)0x0) goto LAB_0061b8f0;
      (**(code **)(puStack_180 + -0x56b4))(puStack_1b8,&puStack_170);
      puVar7 = puStack_1b0;
LAB_0061b800:
      puStack_1b8 = puStack_170;
      ppuVar8 = (undefined **)(**(code **)(puStack_180 + -0x7ca0))(*puStack_1b4);
      uVar18 = 0x10;
      pcVar19 = *(code **)(puStack_180 + -0x60dc);
      puStack_1b0 = puVar7;
      goto LAB_0061b820;
    }
    break;
  case (undefined4 *)0x3:
    piVar3 = (int *)&SUB_00000002;
    *puStack_1b8 = 0x329;
    break;
  case (undefined4 *)0x5:
    piVar3 = (int *)0x1;
    if (pcVar14 == (char *)0x0) {
      puStack_174 = (undefined4 *)0x0;
      puStack_170 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      ppuStack_188 = &puStack_170;
      (**(code **)(puStack_180 + -0x5ac0))(puStack_1b8,0,0,&puStack_174);
      goto LAB_0061b778;
    }
    break;
  case (undefined4 *)0x7:
    piVar3 = (int *)0x1;
    if (pcVar14 == (char *)0x0) {
      puStack_1b0 = (undefined *)encode_gost_algor_params();
      if (puStack_1b0 != (undefined *)0x0) {
        (**(code **)(puStack_180 + -0x56b8))(puStack_1b8,0,0,&puStack_170);
        puVar7 = puStack_1b0;
        goto LAB_0061b800;
      }
LAB_0061b8f0:
      puStack_1b8 = puVar9;
      piVar3 = (int *)0xffffffff;
    }
  }
  if (iStack_16c == *(int *)puStack_1bc) {
    return piVar3;
  }
  pcStack_19c = pub_encode_gost94;
  iStack_244 = iStack_16c;
  (**(code **)(puStack_180 + -0x5328))();
  puStack_1fc = PTR___stack_chk_guard_006aabf0;
  puStack_1d0 = &_gp;
  uStack_1c8 = 0;
  iStack_1c4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(ppuVar8);
  uVar18 = (**(code **)(puStack_1d0 + -0x7ed4))(ppuVar8);
  puStack_1f4 = (undefined4 *)(**(code **)(puStack_1d0 + -0x7ca0))(uVar18);
  if (ppuVar8[6] == (undefined *)0x0) {
    pcStack_1f0 = (char *)0xffffffff;
    uStack_238 = 0;
  }
  else {
    uStack_238 = encode_gost_algor_params(ppuVar8);
    pcStack_1f0 = (char *)0x10;
  }
  iVar10 = (**(code **)(puStack_1d0 + -0x7bec))(*(undefined4 *)(iVar2 + 0x18));
  iVar6 = iVar10 + 7;
  if (iVar10 + 7 < 0) {
    iVar6 = iVar10 + 0xe;
  }
  pcVar17 = (char *)(iVar6 >> 3);
  iVar6 = (**(code **)(puStack_1d0 + -0x7dd8))(pcVar17,"gost_ameth.c",0x291);
  (**(code **)(puStack_1d0 + -0x7be0))(*(undefined4 *)(iVar2 + 0x18),iVar6);
  uVar18 = (**(code **)(puStack_1d0 + -0x6754))();
  pcVar14 = pcVar17;
  (**(code **)(puStack_1d0 + -0x70d4))(uVar18,0);
  puVar7 = (undefined *)(**(code **)(puStack_1d0 + -0x7ab0))(uVar18);
  iVar2 = iVar6 + (int)pcVar17;
  if (0 < (int)pcVar17) {
    do {
      puVar16 = (undefined *)(iVar2 + -1);
      iVar2 = iVar2 + -1;
      *puVar7 = *puVar16;
      puVar7 = puVar7 + 1;
    } while (iVar6 != iVar2);
  }
  (**(code **)(puStack_1d0 + -0x7f58))(iVar6);
  puStack_24c = &uStack_1c8;
  iStack_200 = (**(code **)(puStack_1d0 + -0x69e8))(uVar18);
  (**(code **)(puStack_1d0 + -0x674c))(uVar18);
  if (iStack_200 < 0) {
    piVar3 = (int *)0x0;
  }
  else {
    uStack_1d8 = uStack_1c8;
    puStack_24c = puStack_1f4;
    pcVar14 = pcStack_1f0;
    iStack_1d4 = iStack_200;
    piVar3 = (int *)(**(code **)(puStack_1d0 + -0x6618))
                              (iStack_244,puStack_1f4,pcStack_1f0,uStack_238);
  }
  if (iStack_1c4 == *(int *)puStack_1fc) {
    return piVar3;
  }
  pcStack_1ec = priv_encode_gost;
  iStack_240 = iStack_1c4;
  (**(code **)(puStack_1d0 + -0x5328))();
  puStack_248 = PTR___stack_chk_guard_006aabf0;
  puStack_210 = &_gp;
  iStack_204 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar4 = puStack_24c;
  iStack_1f8 = iStack_244;
  uVar18 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puStack_24c);
  puStack_23c = (undefined4 *)(**(code **)(puStack_210 + -0x7ca0))(uVar18);
  iVar2 = encode_gost_algor_params(puStack_24c);
  uStack_208 = 0;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    iVar6 = (**(code **)(puStack_210 + -0x7ed4))(puStack_24c);
    if (iVar6 == 0x32b) {
      iVar6 = (**(code **)(puStack_210 + -0x57fc))(puStack_24c);
      if (iVar6 == 0) goto LAB_0061bbb0;
      uVar18 = (**(code **)(puStack_210 + -0x6dd4))(iVar6);
    }
    else if ((iVar6 == 0x32c) &&
            (iVar6 = (**(code **)(puStack_210 + -0x57fc))(puStack_24c), iVar6 != 0)) {
      uVar18 = *(undefined4 *)(iVar6 + 0x1c);
    }
    else {
LAB_0061bbb0:
      uVar18 = 0;
    }
    uVar18 = (**(code **)(puStack_210 + -0x7cec))(uVar18,0);
    puStack_24c = (undefined4 *)(**(code **)(puStack_210 + -0x69ec))(uVar18,&uStack_208);
    (**(code **)(puStack_210 + -0x7f4c))(uVar18);
    pcVar14 = (char *)0x0;
    uStack_21c = uStack_208;
    puVar4 = puStack_23c;
    iStack_220 = iVar2;
    puStack_218 = puStack_24c;
    piVar3 = (int *)(**(code **)(puStack_210 + -0x6628))(iStack_240,puStack_23c,0,0x10);
    iStack_244 = iVar2;
  }
  if (iStack_204 == *(int *)puStack_248) {
    return piVar3;
  }
  pcStack_234 = priv_print_gost94;
  iVar2 = iStack_204;
  (**(code **)(puStack_210 + -0x5328))();
  puVar7 = PTR___stack_chk_guard_006aabf0;
  iVar6 = 0x80;
  iStack_254 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar17 = pcVar14;
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
  (*(code *)PTR_BIO_indent_006a97d0)(iVar2,pcVar14,0x80);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"Public key: ");
  (*(code *)PTR_BN_print_006a8024)(iVar2,uVar18);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar4);
  uStack_258 = (*(code *)PTR_BN_new_006a82b4)();
  if (*(int *)(PTR_R3410_paramset_006aa708 + 0xc) != 0) {
    puVar4 = (undefined4 *)PTR_R3410_paramset_006aa708;
    do {
      (*(code *)PTR_BN_dec2bn_006a8f20)(&uStack_258);
      iVar10 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_258,*(undefined4 *)(iVar6 + 0x10));
      if (iVar10 == 0) {
        (*(code *)PTR_BN_free_006a811c)(uStack_258);
        uVar18 = *puVar4;
        goto LAB_0061be90;
      }
      piVar3 = puVar4 + 7;
      puVar4 = puVar4 + 4;
    } while (*piVar3 != 0);
  }
  uVar18 = 0;
  (*(code *)PTR_BN_free_006a811c)(uStack_258);
LAB_0061be90:
  (*(code *)PTR_BIO_indent_006a97d0)(iVar2,pcVar14,0x80);
  iVar6 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar18);
  pcVar17 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a7f38)(iVar2,"Parameter set: %s\n",iVar6);
  piVar3 = (int *)0x1;
LAB_0061bd00:
  if (iStack_254 == *(int *)puVar7) {
    return piVar3;
  }
  iVar2 = iStack_254;
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

