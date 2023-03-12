
/* WARNING: Type propagation algorithm not settling */

int pub_encode_gost01(int param_1,int param_2)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 *puVar14;
  char *pcVar15;
  int unaff_s1;
  undefined4 *unaff_s2;
  code *pcVar16;
  char *pcVar17;
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
  undefined4 *puStack_b0;
  char *pcStack_ac;
  undefined4 *puStack_a8;
  code *pcStack_a4;
  undefined4 **ppuStack_90;
  undefined *puStack_88;
  undefined4 *puStack_7c;
  undefined4 *puStack_78;
  int iStack_74;
  int iStack_6c;
  int iStack_68;
  undefined4 *puStack_64;
  undefined *puStack_60;
  code *pcStack_5c;
  undefined4 local_48;
  int local_44;
  undefined *local_40;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  
  puStack_b8 = PTR___stack_chk_guard_006a9ae8;
  local_40 = &_gp;
  local_30 = 0;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  local_38 = param_1;
  uVar3 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  uVar4 = (**(code **)(local_40 + -0x7ed4))(param_2);
  puStack_b0 = (undefined4 *)(**(code **)(local_40 + -0x7ca0))(uVar4);
  if (*(int *)(param_2 + 0x18) == 0) {
    pcStack_ac = (char *)0xffffffff;
    puStack_a8 = (undefined4 *)0x0;
  }
  else {
    puStack_a8 = (undefined4 *)encode_gost_algor_params(param_2);
    pcStack_ac = (char *)0x10;
  }
  iStack_6c = (**(code **)(local_40 + -0x7c2c))();
  uVar4 = (**(code **)(local_40 + -0x7750))(uVar3);
  (**(code **)(local_40 + -0x7bf4))(uVar4,iStack_6c,0);
  iStack_b4 = (**(code **)(local_40 + -0x72fc))(uVar3);
  if (iStack_b4 == 0) {
    puStack_c0 = (undefined4 *)0x2e4;
    pcVar15 = "gost_ameth.c";
    puVar14 = (undefined4 *)0x7a;
    ERR_GOST_error(0x87);
    iVar5 = 0;
  }
  else {
    unaff_s1 = (**(code **)(local_40 + -0x7c2c))();
    unaff_s2 = (undefined4 *)(**(code **)(local_40 + -0x7c2c))();
    if (unaff_s1 == 0) {
      puStack_c0 = (undefined4 *)0x2ea;
      pcVar15 = "gost_ameth.c";
      puVar14 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      if (unaff_s2 != (undefined4 *)0x0) {
        (**(code **)(local_40 + -0x7dc4))(unaff_s2);
      }
    }
    else {
      if (unaff_s2 != (undefined4 *)0x0) {
        uVar3 = (**(code **)(local_40 + -0x7750))(uVar3);
        local_48 = 0;
        puStack_c0 = unaff_s2;
        iVar5 = (**(code **)(local_40 + -0x6748))(uVar3,iStack_b4,unaff_s1);
        if (iVar5 == 0) {
          puStack_c0 = (undefined4 *)0x2f2;
          pcVar15 = "gost_ameth.c";
          puVar14 = (undefined4 *)0x44;
          local_38 = iVar5;
          ERR_GOST_error(0x87);
          (**(code **)(local_40 + -0x7dc4))(unaff_s1);
          (**(code **)(local_40 + -0x7dc4))(unaff_s2);
          (**(code **)(local_40 + -0x7dc4))(iStack_6c);
          iVar5 = local_38;
        }
        else {
          iVar6 = (**(code **)(local_40 + -0x7bec))(iStack_6c);
          iVar5 = iVar6 + 7;
          if (iVar6 + 7 < 0) {
            iVar5 = iVar6 + 0xe;
          }
          iVar5 = iVar5 >> 3;
          (**(code **)(local_40 + -0x7dc4))(iStack_6c);
          pcVar17 = (char *)(iVar5 << 1);
          iStack_b4 = (**(code **)(local_40 + -0x7dd8))(pcVar17,"gost_ameth.c",0x2fa);
          (**(code **)(local_40 + -0x53ec))(iStack_b4,0,pcVar17);
          local_34 = iStack_b4 + iVar5;
          (**(code **)(local_40 + -0x55cc))(unaff_s1,local_34,iVar5);
          (**(code **)(local_40 + -0x55cc))(unaff_s2,iStack_b4,iVar5);
          (**(code **)(local_40 + -0x7dc4))(unaff_s1);
          (**(code **)(local_40 + -0x7dc4))(unaff_s2);
          unaff_s1 = (**(code **)(local_40 + -0x6778))();
          pcVar15 = pcVar17;
          (**(code **)(local_40 + -0x70c4))(unaff_s1,0);
          puVar7 = (undefined *)(**(code **)(local_40 + -0x7ab0))(unaff_s1);
          iVar5 = local_34 + iVar5;
          if (0 < (int)pcVar17) {
            do {
              puVar1 = (undefined *)(iVar5 + -1);
              iVar5 = iVar5 + -1;
              *puVar7 = *puVar1;
              puVar7 = puVar7 + 1;
            } while (iStack_b4 != iVar5);
          }
          (**(code **)(local_40 + -0x7f58))(iStack_b4);
          puVar14 = &local_30;
          iStack_6c = (**(code **)(local_40 + -0x6a00))(unaff_s1);
          (**(code **)(local_40 + -0x6770))(unaff_s1);
          if (iStack_6c < 0) {
            iVar5 = 0;
          }
          else {
            local_48 = local_30;
            puVar14 = puStack_b0;
            pcVar15 = pcStack_ac;
            puStack_c0 = puStack_a8;
            local_44 = iStack_6c;
            iVar5 = (**(code **)(local_40 + -0x6638))(local_38);
          }
        }
        goto LAB_0061ab6c;
      }
      puStack_c0 = (undefined4 *)0x2ea;
      pcVar15 = "gost_ameth.c";
      puVar14 = (undefined4 *)&DAT_00000041;
      ERR_GOST_error(0x87);
      (**(code **)(local_40 + -0x7dc4))(unaff_s1);
    }
    (**(code **)(local_40 + -0x7dc4))(iStack_6c);
    iVar5 = 0;
  }
LAB_0061ab6c:
  if (local_2c == *(undefined4 **)puStack_b8) {
    return iVar5;
  }
  pcStack_5c = pkey_ctrl_gost;
  puStack_bc = local_2c;
  (**(code **)(local_40 + -0x5330))();
  puStack_c4 = PTR___stack_chk_guard_006a9ae8;
  puStack_60 = puStack_b8;
  puStack_88 = &_gp;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuVar8 = &switchD_0061ad28::switchdataD_0067a7d0 + (int)puVar14;
  puVar9 = puStack_c0;
  iStack_68 = unaff_s1;
  puStack_64 = unaff_s2;
  switch(puVar14) {
  default:
    iVar5 = -2;
    break;
  case (undefined4 *)0x1:
    iVar5 = 1;
    if (pcVar15 == (char *)0x0) {
      puStack_7c = (undefined4 *)0x0;
      puStack_78 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      (**(code **)(puStack_88 + -0x5728))(puStack_c0,0,&puStack_7c,&puStack_78);
LAB_0061ad7c:
      puStack_bc = puStack_7c;
      ppuVar8 = (undefined **)(**(code **)(puStack_88 + -0x7ca0))(0x329);
      (**(code **)(puStack_88 + -0x60fc))(puStack_bc,ppuVar8,5,0);
      puStack_c0 = puStack_78;
      if (puVar9 == (undefined4 *)0x0) goto LAB_0061aef4;
      ppuVar8 = (undefined **)(**(code **)(puStack_88 + -0x7ca0))(puVar9);
      puVar7 = (undefined *)0x0;
      uVar3 = 5;
      pcVar16 = *(code **)(puStack_88 + -0x60fc);
LAB_0061ae24:
      (*pcVar16)(puStack_c0,ppuVar8,uVar3,puVar7);
      iVar5 = 1;
    }
    break;
  case (undefined4 *)0x2:
    iVar5 = 1;
    if (pcVar15 == (char *)0x0) {
      puStack_b8 = (undefined *)encode_gost_algor_params();
      if (puStack_b8 == (undefined *)0x0) goto LAB_0061aef4;
      (**(code **)(puStack_88 + -0x56bc))(puStack_c0,&puStack_78);
      puVar7 = puStack_b8;
LAB_0061ae04:
      puStack_c0 = puStack_78;
      ppuVar8 = (undefined **)(**(code **)(puStack_88 + -0x7ca0))(*puStack_bc);
      uVar3 = 0x10;
      pcVar16 = *(code **)(puStack_88 + -0x60fc);
      puStack_b8 = puVar7;
      goto LAB_0061ae24;
    }
    break;
  case (undefined4 *)0x3:
    iVar5 = 2;
    *puStack_c0 = 0x329;
    break;
  case (undefined4 *)0x5:
    iVar5 = 1;
    if (pcVar15 == (char *)0x0) {
      puStack_7c = (undefined4 *)0x0;
      puStack_78 = (undefined4 *)0x0;
      puVar9 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      ppuStack_90 = &puStack_78;
      (**(code **)(puStack_88 + -0x5acc))(puStack_c0,0,0,&puStack_7c);
      goto LAB_0061ad7c;
    }
    break;
  case (undefined4 *)0x7:
    iVar5 = 1;
    if (pcVar15 == (char *)0x0) {
      puStack_78 = (undefined4 *)0x0;
      puStack_b8 = (undefined *)encode_gost_algor_params();
      if (puStack_b8 != (undefined *)0x0) {
        (**(code **)(puStack_88 + -0x56c0))(puStack_c0,0,0,&puStack_78);
        puVar7 = puStack_b8;
        goto LAB_0061ae04;
      }
LAB_0061aef4:
      puStack_c0 = puVar9;
      iVar5 = -1;
    }
  }
  if (iStack_74 == *(int *)puStack_c4) {
    return iVar5;
  }
  pcStack_a4 = pub_encode_gost94;
  iStack_14c = iStack_74;
  (**(code **)(puStack_88 + -0x5330))();
  puStack_104 = PTR___stack_chk_guard_006a9ae8;
  puStack_d8 = &_gp;
  uStack_d0 = 0;
  iStack_cc = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(ppuVar8);
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
  iVar10 = (**(code **)(puStack_d8 + -0x7bec))(*(undefined4 *)(iVar5 + 0x18));
  iVar6 = iVar10 + 7;
  if (iVar10 + 7 < 0) {
    iVar6 = iVar10 + 0xe;
  }
  pcVar17 = (char *)(iVar6 >> 3);
  iVar6 = (**(code **)(puStack_d8 + -0x7dd8))(pcVar17,"gost_ameth.c",0x288);
  (**(code **)(puStack_d8 + -0x7be0))(*(undefined4 *)(iVar5 + 0x18),iVar6);
  uVar3 = (**(code **)(puStack_d8 + -0x6778))();
  pcVar15 = pcVar17;
  (**(code **)(puStack_d8 + -0x70c4))(uVar3,0);
  puVar7 = (undefined *)(**(code **)(puStack_d8 + -0x7ab0))(uVar3);
  iVar5 = iVar6 + (int)pcVar17;
  if (0 < (int)pcVar17) {
    do {
      puVar1 = (undefined *)(iVar5 + -1);
      iVar5 = iVar5 + -1;
      *puVar7 = *puVar1;
      puVar7 = puVar7 + 1;
    } while (iVar6 != iVar5);
  }
  (**(code **)(puStack_d8 + -0x7f58))(iVar6);
  puStack_154 = &uStack_d0;
  iStack_108 = (**(code **)(puStack_d8 + -0x6a00))(uVar3);
  (**(code **)(puStack_d8 + -0x6770))(uVar3);
  if (iStack_108 < 0) {
    iVar5 = 0;
  }
  else {
    uStack_e0 = uStack_d0;
    puStack_154 = puStack_fc;
    pcVar15 = pcStack_f8;
    iStack_dc = iStack_108;
    iVar5 = (**(code **)(puStack_d8 + -0x6638))(iStack_14c,puStack_fc,pcStack_f8,uStack_140);
  }
  if (iStack_cc == *(int *)puStack_104) {
    return iVar5;
  }
  pcStack_f4 = priv_encode_gost;
  iStack_148 = iStack_cc;
  (**(code **)(puStack_d8 + -0x5330))();
  puStack_150 = PTR___stack_chk_guard_006a9ae8;
  puStack_118 = &_gp;
  iStack_10c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar14 = puStack_154;
  iStack_100 = iStack_14c;
  uVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puStack_154);
  puStack_144 = (undefined4 *)(**(code **)(puStack_118 + -0x7ca0))(uVar3);
  iVar5 = encode_gost_algor_params(puStack_154);
  uStack_110 = 0;
  if (iVar5 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (**(code **)(puStack_118 + -0x7ed4))(puStack_154);
    if (iVar6 == 0x32b) {
      iVar6 = (**(code **)(puStack_118 + -0x5808))(puStack_154);
      if (iVar6 == 0) goto LAB_0061b1b4;
      uVar3 = (**(code **)(puStack_118 + -0x6e68))(iVar6);
    }
    else if ((iVar6 == 0x32c) &&
            (iVar6 = (**(code **)(puStack_118 + -0x5808))(puStack_154), iVar6 != 0)) {
      uVar3 = *(undefined4 *)(iVar6 + 0x1c);
    }
    else {
LAB_0061b1b4:
      uVar3 = 0;
    }
    uVar3 = (**(code **)(puStack_118 + -0x7cec))(uVar3,0);
    puStack_154 = (undefined4 *)(**(code **)(puStack_118 + -0x6a04))(uVar3,&uStack_110);
    (**(code **)(puStack_118 + -0x7f4c))(uVar3);
    pcVar15 = (char *)0x0;
    uStack_124 = uStack_110;
    puVar14 = puStack_144;
    iStack_128 = iVar5;
    puStack_120 = puStack_154;
    iVar6 = (**(code **)(puStack_118 + -0x6648))(iStack_148,puStack_144,0,0x10);
    iStack_14c = iVar5;
  }
  if (iStack_10c == *(int *)puStack_150) {
    return iVar6;
  }
  pcStack_13c = priv_print_gost94;
  iVar5 = iStack_10c;
  (**(code **)(puStack_118 + -0x5330))();
  puVar7 = PTR___stack_chk_guard_006a9ae8;
  iVar10 = 0x80;
  iStack_15c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar17 = pcVar15;
  iVar6 = (*(code *)PTR_BIO_indent_006a86ac)();
  if (iVar6 == 0) goto LAB_0061b304;
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Private key: ");
  iVar6 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puVar14);
  if (iVar6 == 0x32b) {
    iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
    if ((iVar6 == 0) || (iVar6 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar6), iVar6 == 0)
       ) goto LAB_0061b370;
LAB_0061b4fc:
    (*(code *)PTR_BN_print_006a6f24)(iVar5,iVar6);
  }
  else {
    if ((iVar6 == 0x32c) &&
       ((iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14), iVar6 != 0 &&
        (iVar6 = *(int *)(iVar6 + 0x1c), iVar6 != 0)))) goto LAB_0061b4fc;
LAB_0061b370:
    (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"<undefined>");
  }
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
  uVar3 = *(undefined4 *)(iVar6 + 0x18);
  (*(code *)PTR_BIO_indent_006a86ac)(iVar5,pcVar15,0x80);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Public key: ");
  (*(code *)PTR_BN_print_006a6f24)(iVar5,uVar3);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar14);
  uStack_160 = (*(code *)PTR_BN_new_006a71b4)();
  if (*(int *)(PTR_R3410_paramset_006a95fc + 0xc) != 0) {
    puVar14 = (undefined4 *)PTR_R3410_paramset_006a95fc;
    do {
      (*(code *)PTR_BN_dec2bn_006a7e30)(&uStack_160);
      iVar10 = (*(code *)PTR_BN_cmp_006a7960)(uStack_160,*(undefined4 *)(iVar6 + 0x10));
      if (iVar10 == 0) {
        (*(code *)PTR_BN_free_006a701c)(uStack_160);
        uVar3 = *puVar14;
        goto LAB_0061b494;
      }
      piVar2 = puVar14 + 7;
      puVar14 = puVar14 + 4;
    } while (*piVar2 != 0);
  }
  uVar3 = 0;
  (*(code *)PTR_BN_free_006a701c)(uStack_160);
LAB_0061b494:
  (*(code *)PTR_BIO_indent_006a86ac)(iVar5,pcVar15,0x80);
  iVar10 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar3);
  pcVar17 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Parameter set: %s\n",iVar10);
  iVar6 = 1;
LAB_0061b304:
  if (iStack_15c == *(int *)puVar7) {
    return iVar6;
  }
  iVar5 = iStack_15c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar6 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar6 != 0) {
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar6);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar6);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar6);
    uVar11 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
    uVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(uVar11);
    uVar12 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
    uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar12);
    iVar13 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                       (uVar12,uVar11,uVar3,uVar4,iVar6);
    if (iVar13 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1c2);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar6);
      return 0;
    }
    iVar13 = (*(code *)PTR_BIO_indent_006a86ac)(iVar5,iVar10,0x80);
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Public key:\n");
      iVar13 = (*(code *)PTR_BIO_indent_006a86ac)(iVar5,iVar10 + 3,0x80);
      if (iVar13 != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(iVar5,&DAT_0067a7b4);
        (*(code *)PTR_BN_print_006a6f24)(iVar5,uVar3);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"\n");
        (*(code *)PTR_BIO_indent_006a86ac)(iVar5,iVar10 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar5,&DAT_0067a7b8);
        (*(code *)PTR_BN_print_006a6f24)(iVar5,uVar4);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"\n");
        (*(code *)PTR_BN_CTX_end_006a8530)(iVar6);
        (*(code *)PTR_BN_CTX_free_006a7954)(iVar6);
        uVar3 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar17);
        uVar3 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar3);
        uVar3 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar3);
        iVar6 = (*(code *)PTR_BIO_indent_006a86ac)(iVar5,iVar10,0x80);
        if (iVar6 != 0) {
          uVar3 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar3);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Parameter set: %s\n",uVar3);
          return 1;
        }
      }
    }
    return 0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1b8);
  return 0;
}

