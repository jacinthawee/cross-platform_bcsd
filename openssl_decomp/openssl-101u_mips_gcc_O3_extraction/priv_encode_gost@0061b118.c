
int priv_encode_gost(undefined4 param_1,undefined4 param_2,char *param_3)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  int iVar11;
  undefined4 *puVar12;
  int unaff_s2;
  undefined4 uStack_70;
  int iStack_6c;
  undefined4 uStack_64;
  undefined *puStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_20;
  int local_1c;
  
  puStack_60 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar9 = param_2;
  uVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_2);
  uStack_54 = (*(code *)PTR_OBJ_nid2obj_006a7140)(uVar3);
  iVar4 = encode_gost_algor_params(param_2);
  local_20 = 0;
  if (iVar4 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_2);
    if (iVar5 == 0x32b) {
      iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
      if (iVar5 == 0) goto LAB_0061b1b4;
      uVar9 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar5);
    }
    else if ((iVar5 == 0x32c) &&
            (iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2), iVar5 != 0)) {
      uVar9 = *(undefined4 *)(iVar5 + 0x1c);
    }
    else {
LAB_0061b1b4:
      uVar9 = 0;
    }
    uVar9 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(uVar9,0);
    param_2 = (*(code *)PTR_i2d_ASN1_INTEGER_006a83dc)(uVar9,&local_20);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(uVar9);
    param_3 = (char *)0x0;
    uVar9 = uStack_54;
    iVar5 = (*(code *)PTR_PKCS8_pkey_set0_006a8798)(param_1,uStack_54,0,0x10);
    unaff_s2 = iVar4;
  }
  if (local_1c == *(int *)puStack_60) {
    return iVar5;
  }
  iVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iVar11 = 0x80;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar10 = param_3;
  uStack_64 = param_2;
  iStack_5c = unaff_s2;
  uStack_58 = param_1;
  iVar5 = (*(code *)PTR_BIO_indent_006a86ac)();
  if (iVar5 == 0) goto LAB_0061b304;
  (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"Private key: ");
  iVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(uVar9);
  if (iVar5 == 0x32b) {
    iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(uVar9);
    if ((iVar5 != 0) && (iVar5 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar5), iVar5 != 0)
       ) goto LAB_0061b4fc;
LAB_0061b370:
    (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"<undefined>");
  }
  else {
    if ((iVar5 != 0x32c) ||
       ((iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(uVar9), iVar5 == 0 ||
        (iVar5 = *(int *)(iVar5 + 0x1c), iVar5 == 0)))) goto LAB_0061b370;
LAB_0061b4fc:
    (*(code *)PTR_BN_print_006a6f24)(iVar4,iVar5);
  }
  (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(uVar9);
  uVar3 = *(undefined4 *)(iVar5 + 0x18);
  (*(code *)PTR_BIO_indent_006a86ac)(iVar4,param_3,0x80);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"Public key: ");
  (*(code *)PTR_BN_print_006a6f24)(iVar4,uVar3);
  (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(uVar9);
  uStack_70 = (*(code *)PTR_BN_new_006a71b4)();
  if (*(int *)(PTR_R3410_paramset_006a95fc + 0xc) != 0) {
    puVar12 = (undefined4 *)PTR_R3410_paramset_006a95fc;
    do {
      (*(code *)PTR_BN_dec2bn_006a7e30)(&uStack_70);
      iVar11 = (*(code *)PTR_BN_cmp_006a7960)(uStack_70,*(undefined4 *)(iVar5 + 0x10));
      if (iVar11 == 0) {
        (*(code *)PTR_BN_free_006a701c)(uStack_70);
        uVar9 = *puVar12;
        goto LAB_0061b494;
      }
      piVar1 = puVar12 + 7;
      puVar12 = puVar12 + 4;
    } while (*piVar1 != 0);
  }
  uVar9 = 0;
  (*(code *)PTR_BN_free_006a701c)(uStack_70);
LAB_0061b494:
  (*(code *)PTR_BIO_indent_006a86ac)(iVar4,param_3,0x80);
  iVar11 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar9);
  pcVar10 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"Parameter set: %s\n",iVar11);
  iVar5 = 1;
LAB_0061b304:
  if (iStack_6c == *(int *)puVar2) {
    return iVar5;
  }
  iVar4 = iStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar5 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar5 != 0) {
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar5);
    uVar9 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar5);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar5);
    uVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar10);
    uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(uVar6);
    uVar7 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar10);
    uVar7 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar7);
    iVar8 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                      (uVar7,uVar6,uVar9,uVar3,iVar5);
    if (iVar8 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1c2);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar5);
      return 0;
    }
    iVar8 = (*(code *)PTR_BIO_indent_006a86ac)(iVar4,iVar11,0x80);
    if (iVar8 != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"Public key:\n");
      iVar8 = (*(code *)PTR_BIO_indent_006a86ac)(iVar4,iVar11 + 3,0x80);
      if (iVar8 != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(iVar4,&DAT_0067a7b4);
        (*(code *)PTR_BN_print_006a6f24)(iVar4,uVar9);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"\n");
        (*(code *)PTR_BIO_indent_006a86ac)(iVar4,iVar11 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar4,&DAT_0067a7b8);
        (*(code *)PTR_BN_print_006a6f24)(iVar4,uVar3);
        (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"\n");
        (*(code *)PTR_BN_CTX_end_006a8530)(iVar5);
        (*(code *)PTR_BN_CTX_free_006a7954)(iVar5);
        uVar9 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(pcVar10);
        uVar9 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar9);
        uVar9 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar9);
        iVar5 = (*(code *)PTR_BIO_indent_006a86ac)(iVar4,iVar11,0x80);
        if (iVar5 != 0) {
          uVar9 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar9);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"Parameter set: %s\n",uVar9);
          return 1;
        }
      }
    }
    return 0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1b8);
  return 0;
}

