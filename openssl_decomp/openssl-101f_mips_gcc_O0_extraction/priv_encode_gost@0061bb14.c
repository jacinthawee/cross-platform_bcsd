
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
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar9 = param_2;
  uVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_2);
  uStack_54 = (*(code *)PTR_OBJ_nid2obj_006a8240)(uVar3);
  iVar4 = encode_gost_algor_params(param_2);
  local_20 = 0;
  if (iVar4 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_2);
    if (iVar5 == 0x32b) {
      iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
      if (iVar5 == 0) goto LAB_0061bbb0;
      uVar9 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar5);
    }
    else if ((iVar5 == 0x32c) &&
            (iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2), iVar5 != 0)) {
      uVar9 = *(undefined4 *)(iVar5 + 0x1c);
    }
    else {
LAB_0061bbb0:
      uVar9 = 0;
    }
    uVar9 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(uVar9,0);
    param_2 = (*(code *)PTR_i2d_ASN1_INTEGER_006a94f4)(uVar9,&local_20);
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(uVar9);
    param_3 = (char *)0x0;
    uVar9 = uStack_54;
    iVar5 = (*(code *)PTR_PKCS8_pkey_set0_006a98b8)(param_1,uStack_54,0,0x10);
    unaff_s2 = iVar4;
  }
  if (local_1c == *(int *)puStack_60) {
    return iVar5;
  }
  iVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar11 = 0x80;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar10 = param_3;
  uStack_64 = param_2;
  iStack_5c = unaff_s2;
  uStack_58 = param_1;
  iVar5 = (*(code *)PTR_BIO_indent_006a97d0)();
  if (iVar5 == 0) goto LAB_0061bd00;
  (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"Private key: ");
  iVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(uVar9);
  if (iVar5 == 0x32b) {
    iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(uVar9);
    if ((iVar5 != 0) && (iVar5 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar5), iVar5 != 0)
       ) goto LAB_0061bef8;
LAB_0061bd6c:
    (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"<undefined>");
  }
  else {
    if ((iVar5 != 0x32c) ||
       ((iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(uVar9), iVar5 == 0 ||
        (iVar5 = *(int *)(iVar5 + 0x1c), iVar5 == 0)))) goto LAB_0061bd6c;
LAB_0061bef8:
    (*(code *)PTR_BN_print_006a8024)(iVar4,iVar5);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(uVar9);
  uVar3 = *(undefined4 *)(iVar5 + 0x18);
  (*(code *)PTR_BIO_indent_006a97d0)(iVar4,param_3,0x80);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"Public key: ");
  (*(code *)PTR_BN_print_006a8024)(iVar4,uVar3);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"\n");
  iVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(uVar9);
  uStack_70 = (*(code *)PTR_BN_new_006a82b4)();
  if (*(int *)(PTR_R3410_paramset_006aa708 + 0xc) != 0) {
    puVar12 = (undefined4 *)PTR_R3410_paramset_006aa708;
    do {
      (*(code *)PTR_BN_dec2bn_006a8f20)(&uStack_70);
      iVar11 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_70,*(undefined4 *)(iVar5 + 0x10));
      if (iVar11 == 0) {
        (*(code *)PTR_BN_free_006a811c)(uStack_70);
        uVar9 = *puVar12;
        goto LAB_0061be90;
      }
      piVar1 = puVar12 + 7;
      puVar12 = puVar12 + 4;
    } while (*piVar1 != 0);
  }
  uVar9 = 0;
  (*(code *)PTR_BN_free_006a811c)(uStack_70);
LAB_0061be90:
  (*(code *)PTR_BIO_indent_006a97d0)(iVar4,param_3,0x80);
  iVar11 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar9);
  pcVar10 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"Parameter set: %s\n",iVar11);
  iVar5 = 1;
LAB_0061bd00:
  if (iStack_6c == *(int *)puVar2) {
    return iVar5;
  }
  iVar4 = iStack_6c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar5 != 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar5);
    uVar9 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar5);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar5);
    uVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar10);
    uVar6 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(uVar6);
    uVar7 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar10);
    uVar7 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar7);
    iVar8 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                      (uVar7,uVar6,uVar9,uVar3,iVar5);
    if (iVar8 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1d8);
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar5);
      return 0;
    }
    iVar8 = (*(code *)PTR_BIO_indent_006a97d0)(iVar4,iVar11,0x80);
    if (iVar8 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"Public key:\n");
      iVar8 = (*(code *)PTR_BIO_indent_006a97d0)(iVar4,iVar11 + 3,0x80);
      if (iVar8 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar4,&DAT_0067b044);
        (*(code *)PTR_BN_print_006a8024)(iVar4,uVar9);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"\n");
        (*(code *)PTR_BIO_indent_006a97d0)(iVar4,iVar11 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar4,&DAT_0067b048);
        (*(code *)PTR_BN_print_006a8024)(iVar4,uVar3);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"\n");
        (*(code *)PTR_BN_CTX_end_006a9654)(iVar5);
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar5);
        uVar9 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar10);
        uVar9 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar9);
        uVar9 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar9);
        iVar5 = (*(code *)PTR_BIO_indent_006a97d0)(iVar4,iVar11,0x80);
        if (iVar5 != 0) {
          uVar9 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar9);
          (*(code *)PTR_BIO_printf_006a7f38)(iVar4,"Parameter set: %s\n",uVar9);
          return 1;
        }
      }
    }
    return 0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1ce);
  return 0;
}

