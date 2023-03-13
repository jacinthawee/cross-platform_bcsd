
/* WARNING: Type propagation algorithm not settling */

int pkey_ctrl_gost(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined *puVar1;
  int *piVar2;
  undefined **ppuVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  int unaff_s3;
  undefined4 uStack_108;
  int iStack_104;
  undefined4 *puStack_fc;
  undefined *puStack_f8;
  int iStack_f4;
  int iStack_f0;
  undefined4 *puStack_ec;
  undefined4 uStack_e8;
  code *pcStack_e4;
  int iStack_d0;
  undefined4 uStack_cc;
  undefined4 *puStack_c8;
  undefined *puStack_c0;
  undefined4 uStack_b8;
  int iStack_b4;
  int iStack_b0;
  undefined *puStack_ac;
  int iStack_a8;
  undefined4 *puStack_a4;
  char *pcStack_a0;
  code *pcStack_9c;
  undefined4 uStack_88;
  int iStack_84;
  undefined *puStack_80;
  undefined4 uStack_78;
  int iStack_74;
  undefined *puStack_6c;
  undefined4 *puStack_68;
  undefined4 *puStack_64;
  int iStack_60;
  undefined4 *local_24;
  undefined4 *local_20;
  int local_1c;
  
  puStack_6c = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuVar3 = &switchD_0061ad28::switchdataD_0067a7d0 + param_2;
  puVar4 = param_4;
  switch(param_2) {
  default:
    iVar5 = -2;
    break;
  case 1:
    iVar5 = 1;
    if (param_3 == 0) {
      local_24 = (undefined4 *)0x0;
      local_20 = (undefined4 *)0x0;
      puVar4 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      (*(code *)PTR_PKCS7_SIGNER_INFO_get0_algs_006a96b8)(param_4,0,&local_24,&local_20);
LAB_0061ad7c:
      param_1 = local_24;
      ppuVar3 = (undefined **)(*(code *)PTR_OBJ_nid2obj_006a7140)(0x329);
      (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(param_1,ppuVar3,5,0);
      param_4 = local_20;
      if (puVar4 == (undefined4 *)0x0) goto LAB_0061aef4;
      ppuVar3 = (undefined **)(*(code *)PTR_OBJ_nid2obj_006a7140)(puVar4);
      iVar5 = 0;
      uVar6 = 5;
LAB_0061ae24:
      (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(param_4,ppuVar3,uVar6,iVar5);
      iVar5 = 1;
    }
    break;
  case 2:
    iVar5 = 1;
    if (param_3 == 0) {
      unaff_s3 = encode_gost_algor_params();
      if (unaff_s3 == 0) goto LAB_0061aef4;
      (*(code *)PTR_PKCS7_RECIP_INFO_get0_alg_006a9724)(param_4,&local_20);
      iVar5 = unaff_s3;
LAB_0061ae04:
      param_4 = local_20;
      ppuVar3 = (undefined **)(*(code *)PTR_OBJ_nid2obj_006a7140)(*param_1);
      uVar6 = 0x10;
      unaff_s3 = iVar5;
      goto LAB_0061ae24;
    }
    break;
  case 3:
    iVar5 = 2;
    *param_4 = 0x329;
    break;
  case 5:
    iVar5 = 1;
    if (param_3 == 0) {
      local_24 = (undefined4 *)0x0;
      local_20 = (undefined4 *)0x0;
      puVar4 = (undefined4 *)(*(code *)PTR_EVP_PKEY_base_id_006a6f0c)();
      (*(code *)PTR_CMS_SignerInfo_get0_algs_006a9314)(param_4,0,0,&local_24);
      goto LAB_0061ad7c;
    }
    break;
  case 7:
    iVar5 = 1;
    if (param_3 == 0) {
      local_20 = (undefined4 *)0x0;
      unaff_s3 = encode_gost_algor_params();
      if (unaff_s3 != 0) {
        (*(code *)PTR_CMS_RecipientInfo_ktri_get0_algs_006a9720)(param_4,0,0,&local_20);
        iVar5 = unaff_s3;
        goto LAB_0061ae04;
      }
LAB_0061aef4:
      param_4 = puVar4;
      iVar5 = -1;
    }
  }
  if (local_1c == *(int *)puStack_6c) {
    return iVar5;
  }
  iStack_f4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_ac = PTR___stack_chk_guard_006a9ae8;
  puStack_80 = &_gp;
  uStack_78 = 0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_68 = param_4;
  puStack_64 = param_1;
  iStack_60 = unaff_s3;
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(ppuVar3);
  uVar6 = (**(code **)(puStack_80 + -0x7ed4))(ppuVar3);
  puStack_a4 = (undefined4 *)(**(code **)(puStack_80 + -0x7ca0))(uVar6);
  if (ppuVar3[6] == (undefined *)0x0) {
    pcStack_a0 = (char *)0xffffffff;
    uStack_e8 = 0;
  }
  else {
    uStack_e8 = encode_gost_algor_params(ppuVar3);
    pcStack_a0 = (char *)0x10;
  }
  iVar7 = (**(code **)(puStack_80 + -0x7bec))(*(undefined4 *)(iVar5 + 0x18));
  iVar8 = iVar7 + 7;
  if (iVar7 + 7 < 0) {
    iVar8 = iVar7 + 0xe;
  }
  pcVar15 = (char *)(iVar8 >> 3);
  iVar8 = (**(code **)(puStack_80 + -0x7dd8))(pcVar15,"gost_ameth.c",0x288);
  (**(code **)(puStack_80 + -0x7be0))(*(undefined4 *)(iVar5 + 0x18),iVar8);
  uVar6 = (**(code **)(puStack_80 + -0x6778))();
  pcVar14 = pcVar15;
  (**(code **)(puStack_80 + -0x70c4))(uVar6,0);
  puVar9 = (undefined *)(**(code **)(puStack_80 + -0x7ab0))(uVar6);
  iVar5 = iVar8 + (int)pcVar15;
  if (0 < (int)pcVar15) {
    do {
      puVar1 = (undefined *)(iVar5 + -1);
      iVar5 = iVar5 + -1;
      *puVar9 = *puVar1;
      puVar9 = puVar9 + 1;
    } while (iVar8 != iVar5);
  }
  (**(code **)(puStack_80 + -0x7f58))(iVar8);
  puStack_fc = &uStack_78;
  iStack_b0 = (**(code **)(puStack_80 + -0x6a00))(uVar6);
  (**(code **)(puStack_80 + -0x6770))(uVar6);
  if (iStack_b0 < 0) {
    iVar5 = 0;
  }
  else {
    uStack_88 = uStack_78;
    puStack_fc = puStack_a4;
    pcVar14 = pcStack_a0;
    iStack_84 = iStack_b0;
    iVar5 = (**(code **)(puStack_80 + -0x6638))(iStack_f4,puStack_a4,pcStack_a0,uStack_e8);
  }
  if (iStack_74 == *(int *)puStack_ac) {
    return iVar5;
  }
  pcStack_9c = priv_encode_gost;
  iStack_f0 = iStack_74;
  (**(code **)(puStack_80 + -0x5330))();
  puStack_f8 = PTR___stack_chk_guard_006a9ae8;
  puStack_c0 = &_gp;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar4 = puStack_fc;
  iStack_a8 = iStack_f4;
  uVar6 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puStack_fc);
  puStack_ec = (undefined4 *)(**(code **)(puStack_c0 + -0x7ca0))(uVar6);
  iVar5 = encode_gost_algor_params(puStack_fc);
  uStack_b8 = 0;
  if (iVar5 == 0) {
    iVar8 = 0;
  }
  else {
    iVar8 = (**(code **)(puStack_c0 + -0x7ed4))(puStack_fc);
    if (iVar8 == 0x32b) {
      iVar8 = (**(code **)(puStack_c0 + -0x5808))(puStack_fc);
      if (iVar8 == 0) goto LAB_0061b1b4;
      uVar6 = (**(code **)(puStack_c0 + -0x6e68))(iVar8);
    }
    else if ((iVar8 == 0x32c) &&
            (iVar8 = (**(code **)(puStack_c0 + -0x5808))(puStack_fc), iVar8 != 0)) {
      uVar6 = *(undefined4 *)(iVar8 + 0x1c);
    }
    else {
LAB_0061b1b4:
      uVar6 = 0;
    }
    uVar6 = (**(code **)(puStack_c0 + -0x7cec))(uVar6,0);
    puStack_fc = (undefined4 *)(**(code **)(puStack_c0 + -0x6a04))(uVar6,&uStack_b8);
    (**(code **)(puStack_c0 + -0x7f4c))(uVar6);
    pcVar14 = (char *)0x0;
    uStack_cc = uStack_b8;
    puVar4 = puStack_ec;
    iStack_d0 = iVar5;
    puStack_c8 = puStack_fc;
    iVar8 = (**(code **)(puStack_c0 + -0x6648))(iStack_f0,puStack_ec,0,0x10);
    iStack_f4 = iVar5;
  }
  if (iStack_b4 == *(int *)puStack_f8) {
    return iVar8;
  }
  pcStack_e4 = priv_print_gost94;
  iVar5 = iStack_b4;
  (**(code **)(puStack_c0 + -0x5330))();
  puVar9 = PTR___stack_chk_guard_006a9ae8;
  iVar7 = 0x80;
  iStack_104 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar15 = pcVar14;
  iVar8 = (*(code *)PTR_BIO_indent_006a86ac)();
  if (iVar8 == 0) goto LAB_0061b304;
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Private key: ");
  iVar8 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(puVar4);
  if (iVar8 == 0x32b) {
    iVar8 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar4);
    if ((iVar8 == 0) || (iVar8 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar8), iVar8 == 0)
       ) goto LAB_0061b370;
LAB_0061b4fc:
    (*(code *)PTR_BN_print_006a6f24)(iVar5,iVar8);
  }
  else {
    if ((iVar8 == 0x32c) &&
       ((iVar8 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar4), iVar8 != 0 &&
        (iVar8 = *(int *)(iVar8 + 0x1c), iVar8 != 0)))) goto LAB_0061b4fc;
LAB_0061b370:
    (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"<undefined>");
  }
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"\n");
  iVar8 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar4);
  uVar6 = *(undefined4 *)(iVar8 + 0x18);
  (*(code *)PTR_BIO_indent_006a86ac)(iVar5,pcVar14,0x80);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Public key: ");
  (*(code *)PTR_BN_print_006a6f24)(iVar5,uVar6);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"\n");
  iVar8 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(puVar4);
  uStack_108 = (*(code *)PTR_BN_new_006a71b4)();
  if (*(int *)(PTR_R3410_paramset_006a95fc + 0xc) != 0) {
    puVar4 = (undefined4 *)PTR_R3410_paramset_006a95fc;
    do {
      (*(code *)PTR_BN_dec2bn_006a7e30)(&uStack_108);
      iVar7 = (*(code *)PTR_BN_cmp_006a7960)(uStack_108,*(undefined4 *)(iVar8 + 0x10));
      if (iVar7 == 0) {
        (*(code *)PTR_BN_free_006a701c)(uStack_108);
        uVar6 = *puVar4;
        goto LAB_0061b494;
      }
      piVar2 = puVar4 + 7;
      puVar4 = puVar4 + 4;
    } while (*piVar2 != 0);
  }
  uVar6 = 0;
  (*(code *)PTR_BN_free_006a701c)(uStack_108);
LAB_0061b494:
  (*(code *)PTR_BIO_indent_006a86ac)(iVar5,pcVar14,0x80);
  iVar7 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar6);
  pcVar15 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Parameter set: %s\n",iVar7);
  iVar8 = 1;
LAB_0061b304:
  if (iStack_104 == *(int *)puVar9) {
    return iVar8;
  }
  iVar5 = iStack_104;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar8 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar8 != 0) {
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar8);
    uVar6 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar8);
    uVar10 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar8);
    uVar11 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar15);
    uVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(uVar11);
    uVar12 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar15);
    uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar12);
    iVar13 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                       (uVar12,uVar11,uVar6,uVar10,iVar8);
    if (iVar13 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1c2);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
      return 0;
    }
    iVar13 = (*(code *)PTR_BIO_indent_006a86ac)(iVar5,iVar7,0x80);
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Public key:\n");
      iVar13 = (*(code *)PTR_BIO_indent_006a86ac)(iVar5,iVar7 + 3,0x80);
      if (iVar13 != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(iVar5,&DAT_0067a7b4);
        (*(code *)PTR_BN_print_006a6f24)(iVar5,uVar6);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"\n");
        (*(code *)PTR_BIO_indent_006a86ac)(iVar5,iVar7 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar5,&DAT_0067a7b8);
        (*(code *)PTR_BN_print_006a6f24)(iVar5,uVar10);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"\n");
        (*(code *)PTR_BN_CTX_end_006a8530)(iVar8);
        (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
        uVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar15);
        uVar6 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar6);
        uVar6 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar6);
        iVar8 = (*(code *)PTR_BIO_indent_006a86ac)(iVar5,iVar7,0x80);
        if (iVar8 != 0) {
          uVar6 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar6);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Parameter set: %s\n",uVar6);
          return 1;
        }
      }
    }
    return 0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1b8);
  return 0;
}

