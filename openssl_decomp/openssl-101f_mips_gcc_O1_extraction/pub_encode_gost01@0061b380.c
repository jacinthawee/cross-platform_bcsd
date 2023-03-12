
/* WARNING: Type propagation algorithm not settling */

int pub_encode_gost01(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 uVar3;
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
  int iVar15;
  char *pcVar16;
  int unaff_s4;
  int unaff_s5;
  code *pcVar17;
  undefined4 uStack_160;
  int iStack_15c;
  undefined4 *puStack_154;
  undefined *puStack_150;
  int iStack_14c;
  int iStack_148;
  undefined4 *puStack_144;
  undefined4 uStack_140;
  code *pcStack_13c;
  int iStack_128;
  undefined4 uStack_124;
  undefined4 *puStack_120;
  undefined *puStack_118;
  undefined4 uStack_110;
  int iStack_10c;
  int iStack_108;
  undefined *puStack_104;
  int iStack_100;
  undefined4 *puStack_fc;
  char *pcStack_f8;
  code *pcStack_f4;
  undefined4 uStack_e0;
  int iStack_dc;
  undefined *puStack_d8;
  undefined4 uStack_d0;
  int iStack_cc;
  undefined *puStack_c4;
  undefined4 *puStack_c0;
  undefined4 *puStack_bc;
  undefined *puStack_b8;
  int iStack_b4;
  int iStack_b0;
  char *pcStack_ac;
  undefined4 *puStack_a8;
  code *pcStack_a4;
  undefined4 **ppuStack_90;
  undefined *puStack_88;
  undefined4 *puStack_7c;
  undefined4 *puStack_78;
  int iStack_74;
  int iStack_6c;
  undefined4 uStack_68;
  char *pcStack_64;
  undefined *puStack_60;
  code *pcStack_5c;
  undefined4 local_48;
  int local_44;
  undefined *local_40;
  undefined4 *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  
  puStack_b8 = PTR___stack_chk_guard_006aabf0;
  local_40 = &_gp;
  local_30 = 0;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  local_34 = param_1;
  uStack_68 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  uVar3 = (**(code **)(local_40 + -0x7ed4))(param_2);
  local_38 = (undefined4 *)(**(code **)(local_40 + -0x7ca0))(uVar3);
  if (*(int *)(param_2 + 0x18) == 0) {
    pcStack_ac = (char *)0xffffffff;
    puStack_a8 = (undefined4 *)0x0;
  }
  else {
    puStack_a8 = (undefined4 *)encode_gost_algor_params(param_2);
    pcStack_ac = &SUB_00000010;
  }
  iStack_6c = (**(code **)(local_40 + -0x7c2c))();
  uVar3 = (**(code **)(local_40 + -0x7760))(uStack_68);
  (**(code **)(local_40 + -0x7bf4))(uVar3,iStack_6c,0);
  pcStack_64 = (char *)(**(code **)(local_40 + -0x7310))(uStack_68);
  if (pcStack_64 == (char *)0x0) {
    puStack_c0 = (undefined4 *)0x2f6;
    pcVar14 = "gost_ameth.c";
    puVar4 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    iVar15 = 0;
  }
  else {
    uVar3 = (**(code **)(local_40 + -0x7c2c))();
    puVar4 = (undefined4 *)(**(code **)(local_40 + -0x7c2c))();
    uVar5 = (**(code **)(local_40 + -0x7760))(uStack_68);
    local_48 = 0;
    puStack_c0 = puVar4;
    (**(code **)(local_40 + -0x6724))(uVar5,pcStack_64,uVar3);
    iVar6 = (**(code **)(local_40 + -0x7bec))(iStack_6c);
    iVar15 = iVar6 + 7;
    if (iVar6 + 7 < 0) {
      iVar15 = iVar6 + 0xe;
    }
    iVar15 = iVar15 >> 3;
    (**(code **)(local_40 + -0x7dc4))(iStack_6c);
    pcStack_64 = (char *)(iVar15 << 1);
    unaff_s4 = (**(code **)(local_40 + -0x7dd8))(pcStack_64,"gost_ameth.c",0x2ff);
    unaff_s5 = unaff_s4 + iVar15;
    (**(code **)(local_40 + -0x53e0))(unaff_s4,0,pcStack_64);
    (**(code **)(local_40 + -0x55bc))(uVar3,unaff_s5,iVar15);
    (**(code **)(local_40 + -0x55bc))(puVar4,unaff_s4,iVar15);
    (**(code **)(local_40 + -0x7dc4))(uVar3);
    (**(code **)(local_40 + -0x7dc4))(puVar4);
    uStack_68 = (**(code **)(local_40 + -0x6754))();
    pcVar14 = pcStack_64;
    (**(code **)(local_40 + -0x70d4))(uStack_68,0);
    puVar7 = (undefined *)(**(code **)(local_40 + -0x7ab0))(uStack_68);
    iVar15 = unaff_s5 + iVar15;
    if (0 < (int)pcStack_64) {
      do {
        puVar1 = (undefined *)(iVar15 + -1);
        iVar15 = iVar15 + -1;
        *puVar7 = *puVar1;
        puVar7 = puVar7 + 1;
      } while (unaff_s4 != iVar15);
    }
    (**(code **)(local_40 + -0x7f58))(unaff_s4);
    puVar4 = &local_30;
    iStack_6c = (**(code **)(local_40 + -0x69e8))(uStack_68);
    (**(code **)(local_40 + -0x674c))(uStack_68);
    if (iStack_6c < 0) {
      iVar15 = 0;
    }
    else {
      local_48 = local_30;
      puVar4 = local_38;
      pcVar14 = pcStack_ac;
      puStack_c0 = puStack_a8;
      local_44 = iStack_6c;
      iVar15 = (**(code **)(local_40 + -0x6618))(local_34);
    }
  }
  if (local_2c == *(undefined4 **)puStack_b8) {
    return iVar15;
  }
  pcStack_5c = pkey_ctrl_gost;
  puStack_bc = local_2c;
  (**(code **)(local_40 + -0x5328))();
  puStack_c4 = PTR___stack_chk_guard_006aabf0;
  puStack_60 = puStack_b8;
  puStack_88 = &_gp;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar8 = &switchD_0061b724::switchdataD_0067b080 + (int)puVar4;
  puVar9 = puStack_c0;
  switch(puVar4) {
  default:
    iVar15 = -2;
    break;
  case (undefined4 *)0x1:
    iVar15 = 1;
    if (pcVar14 == (char *)0x0) {
      puStack_7c = (undefined4 *)0x0;
      puStack_78 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      (**(code **)(puStack_88 + -0x5720))(puStack_c0,0,&puStack_7c,&puStack_78);
LAB_0061b778:
      puStack_bc = puStack_7c;
      ppuVar8 = (undefined **)(**(code **)(puStack_88 + -0x7ca0))(0x329);
      (**(code **)(puStack_88 + -0x60dc))(puStack_bc,ppuVar8,5,0);
      puStack_c0 = puStack_78;
      if (puVar9 == (undefined4 *)0x0) goto LAB_0061b8f0;
      ppuVar8 = (undefined **)(**(code **)(puStack_88 + -0x7ca0))(puVar9);
      puVar7 = (undefined *)0x0;
      uVar3 = 5;
      pcVar17 = *(code **)(puStack_88 + -0x60dc);
LAB_0061b820:
      (*pcVar17)(puStack_c0,ppuVar8,uVar3,puVar7);
      iVar15 = 1;
    }
    break;
  case (undefined4 *)0x2:
    iVar15 = 1;
    if (pcVar14 == (char *)0x0) {
      puStack_b8 = (undefined *)encode_gost_algor_params();
      if (puStack_b8 == (undefined *)0x0) goto LAB_0061b8f0;
      (**(code **)(puStack_88 + -0x56b4))(puStack_c0,&puStack_78);
      puVar7 = puStack_b8;
LAB_0061b800:
      puStack_c0 = puStack_78;
      ppuVar8 = (undefined **)(**(code **)(puStack_88 + -0x7ca0))(*puStack_bc);
      uVar3 = 0x10;
      pcVar17 = *(code **)(puStack_88 + -0x60dc);
      puStack_b8 = puVar7;
      goto LAB_0061b820;
    }
    break;
  case (undefined4 *)0x3:
    iVar15 = 2;
    *puStack_c0 = 0x329;
    break;
  case (undefined4 *)0x5:
    iVar15 = 1;
    if (pcVar14 == (char *)0x0) {
      puStack_7c = (undefined4 *)0x0;
      puStack_78 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a800c)();
      ppuStack_90 = &puStack_78;
      (**(code **)(puStack_88 + -0x5ac0))(puStack_c0,0,0,&puStack_7c);
      goto LAB_0061b778;
    }
    break;
  case (undefined4 *)0x7:
    iVar15 = 1;
    if (pcVar14 == (char *)0x0) {
      puStack_b8 = (undefined *)encode_gost_algor_params();
      if (puStack_b8 != (undefined *)0x0) {
        (**(code **)(puStack_88 + -0x56b8))(puStack_c0,0,0,&puStack_78);
        puVar7 = puStack_b8;
        goto LAB_0061b800;
      }
LAB_0061b8f0:
      puStack_c0 = puVar9;
      iVar15 = -1;
    }
  }
  if (iStack_74 == *(int *)puStack_c4) {
    return iVar15;
  }
  pcStack_a4 = pub_encode_gost94;
  iStack_14c = iStack_74;
  (**(code **)(puStack_88 + -0x5328))();
  puStack_104 = PTR___stack_chk_guard_006aabf0;
  puStack_d8 = &_gp;
  uStack_d0 = 0;
  iStack_cc = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_b4 = unaff_s4;
  iStack_b0 = unaff_s5;
  iVar15 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(ppuVar8);
  uVar3 = (**(code **)(puStack_d8 + -0x7ed4))(ppuVar8);
  puStack_fc = (undefined4 *)(**(code **)(puStack_d8 + -0x7ca0))(uVar3);
  if (ppuVar8[6] == (undefined *)0x0) {
    pcStack_f8 = (char *)0xffffffff;
    uStack_140 = 0;
  }
  else {
    uStack_140 = encode_gost_algor_params(ppuVar8);
    pcStack_f8 = (char *)0x10;
  }
  iVar10 = (**(code **)(puStack_d8 + -0x7bec))(*(undefined4 *)(iVar15 + 0x18));
  iVar6 = iVar10 + 7;
  if (iVar10 + 7 < 0) {
    iVar6 = iVar10 + 0xe;
  }
  pcVar16 = (char *)(iVar6 >> 3);
  iVar6 = (**(code **)(puStack_d8 + -0x7dd8))(pcVar16,"gost_ameth.c",0x291);
  (**(code **)(puStack_d8 + -0x7be0))(*(undefined4 *)(iVar15 + 0x18),iVar6);
  uVar3 = (**(code **)(puStack_d8 + -0x6754))();
  pcVar14 = pcVar16;
  (**(code **)(puStack_d8 + -0x70d4))(uVar3,0);
  puVar7 = (undefined *)(**(code **)(puStack_d8 + -0x7ab0))(uVar3);
  iVar15 = iVar6 + (int)pcVar16;
  if (0 < (int)pcVar16) {
    do {
      puVar1 = (undefined *)(iVar15 + -1);
      iVar15 = iVar15 + -1;
      *puVar7 = *puVar1;
      puVar7 = puVar7 + 1;
    } while (iVar6 != iVar15);
  }
  (**(code **)(puStack_d8 + -0x7f58))(iVar6);
  puStack_154 = &uStack_d0;
  iStack_108 = (**(code **)(puStack_d8 + -0x69e8))(uVar3);
  (**(code **)(puStack_d8 + -0x674c))(uVar3);
  if (iStack_108 < 0) {
    iVar15 = 0;
  }
  else {
    uStack_e0 = uStack_d0;
    puStack_154 = puStack_fc;
    pcVar14 = pcStack_f8;
    iStack_dc = iStack_108;
    iVar15 = (**(code **)(puStack_d8 + -0x6618))(iStack_14c,puStack_fc,pcStack_f8,uStack_140);
  }
  if (iStack_cc == *(int *)puStack_104) {
    return iVar15;
  }
  pcStack_f4 = priv_encode_gost;
  iStack_148 = iStack_cc;
  (**(code **)(puStack_d8 + -0x5328))();
  puStack_150 = PTR___stack_chk_guard_006aabf0;
  puStack_118 = &_gp;
  iStack_10c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar4 = puStack_154;
  iStack_100 = iStack_14c;
  uVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puStack_154);
  puStack_144 = (undefined4 *)(**(code **)(puStack_118 + -0x7ca0))(uVar3);
  iVar15 = encode_gost_algor_params(puStack_154);
  uStack_110 = 0;
  if (iVar15 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (**(code **)(puStack_118 + -0x7ed4))(puStack_154);
    if (iVar6 == 0x32b) {
      iVar6 = (**(code **)(puStack_118 + -0x57fc))(puStack_154);
      if (iVar6 == 0) goto LAB_0061bbb0;
      uVar3 = (**(code **)(puStack_118 + -0x6dd4))(iVar6);
    }
    else if ((iVar6 == 0x32c) &&
            (iVar6 = (**(code **)(puStack_118 + -0x57fc))(puStack_154), iVar6 != 0)) {
      uVar3 = *(undefined4 *)(iVar6 + 0x1c);
    }
    else {
LAB_0061bbb0:
      uVar3 = 0;
    }
    uVar3 = (**(code **)(puStack_118 + -0x7cec))(uVar3,0);
    puStack_154 = (undefined4 *)(**(code **)(puStack_118 + -0x69ec))(uVar3,&uStack_110);
    (**(code **)(puStack_118 + -0x7f4c))(uVar3);
    pcVar14 = (char *)0x0;
    uStack_124 = uStack_110;
    puVar4 = puStack_144;
    iStack_128 = iVar15;
    puStack_120 = puStack_154;
    iVar6 = (**(code **)(puStack_118 + -0x6628))(iStack_148,puStack_144,0,0x10);
    iStack_14c = iVar15;
  }
  if (iStack_10c == *(int *)puStack_150) {
    return iVar6;
  }
  pcStack_13c = priv_print_gost94;
  iVar15 = iStack_10c;
  (**(code **)(puStack_118 + -0x5328))();
  puVar7 = PTR___stack_chk_guard_006aabf0;
  iVar10 = 0x80;
  iStack_15c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar16 = pcVar14;
  iVar6 = (*(code *)PTR_BIO_indent_006a97d0)();
  if (iVar6 == 0) goto LAB_0061bd00;
  (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"Private key: ");
  iVar6 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar4);
  if (iVar6 == 0x32b) {
    iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar4);
    if ((iVar6 == 0) || (iVar6 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar6), iVar6 == 0)
       ) goto LAB_0061bd6c;
LAB_0061bef8:
    (*(code *)PTR_BN_print_006a8024)(iVar15,iVar6);
  }
  else {
    if ((iVar6 == 0x32c) &&
       ((iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar4), iVar6 != 0 &&
        (iVar6 = *(int *)(iVar6 + 0x1c), iVar6 != 0)))) goto LAB_0061bef8;
LAB_0061bd6c:
    (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"<undefined>");
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar4);
  uVar3 = *(undefined4 *)(iVar6 + 0x18);
  (*(code *)PTR_BIO_indent_006a97d0)(iVar15,pcVar14,0x80);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"Public key: ");
  (*(code *)PTR_BN_print_006a8024)(iVar15,uVar3);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar4);
  uStack_160 = (*(code *)PTR_BN_new_006a82b4)();
  if (*(int *)(PTR_R3410_paramset_006aa708 + 0xc) != 0) {
    puVar4 = (undefined4 *)PTR_R3410_paramset_006aa708;
    do {
      (*(code *)PTR_BN_dec2bn_006a8f20)(&uStack_160);
      iVar10 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_160,*(undefined4 *)(iVar6 + 0x10));
      if (iVar10 == 0) {
        (*(code *)PTR_BN_free_006a811c)(uStack_160);
        uVar3 = *puVar4;
        goto LAB_0061be90;
      }
      piVar2 = puVar4 + 7;
      puVar4 = puVar4 + 4;
    } while (*piVar2 != 0);
  }
  uVar3 = 0;
  (*(code *)PTR_BN_free_006a811c)(uStack_160);
LAB_0061be90:
  (*(code *)PTR_BIO_indent_006a97d0)(iVar15,pcVar14,0x80);
  iVar10 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar3);
  pcVar16 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"Parameter set: %s\n",iVar10);
  iVar6 = 1;
LAB_0061bd00:
  if (iStack_15c == *(int *)puVar7) {
    return iVar6;
  }
  iVar15 = iStack_15c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar6 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar6 != 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar6);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar6);
    uVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar6);
    uVar11 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar16);
    uVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(uVar11);
    uVar12 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar16);
    uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar12);
    iVar13 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                       (uVar12,uVar11,uVar3,uVar5,iVar6);
    if (iVar13 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1d8);
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar6);
      return 0;
    }
    iVar13 = (*(code *)PTR_BIO_indent_006a97d0)(iVar15,iVar10,0x80);
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"Public key:\n");
      iVar13 = (*(code *)PTR_BIO_indent_006a97d0)(iVar15,iVar10 + 3,0x80);
      if (iVar13 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar15,&DAT_0067b064);
        (*(code *)PTR_BN_print_006a8024)(iVar15,uVar3);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"\n");
        (*(code *)PTR_BIO_indent_006a97d0)(iVar15,iVar10 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar15,&DAT_0067b068);
        (*(code *)PTR_BN_print_006a8024)(iVar15,uVar5);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"\n");
        (*(code *)PTR_BN_CTX_end_006a9654)(iVar6);
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar6);
        uVar3 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar16);
        uVar3 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar3);
        uVar3 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar3);
        iVar6 = (*(code *)PTR_BIO_indent_006a97d0)(iVar15,iVar10,0x80);
        if (iVar6 != 0) {
          uVar3 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar3);
          (*(code *)PTR_BIO_printf_006a7f38)(iVar15,"Parameter set: %s\n",uVar3);
          return 1;
        }
      }
    }
    return 0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1ce);
  return 0;
}

