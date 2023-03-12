
/* WARNING: Type propagation algorithm not settling */

int pub_encode_gost94(int param_1,int param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  char *pcVar13;
  char *pcVar14;
  undefined4 uStack_c0;
  int iStack_bc;
  undefined4 *puStack_b4;
  undefined *puStack_b0;
  int iStack_ac;
  int iStack_a8;
  undefined4 *puStack_a4;
  undefined4 uStack_a0;
  code *pcStack_9c;
  int iStack_88;
  undefined4 uStack_84;
  undefined4 *puStack_80;
  undefined *puStack_78;
  undefined4 uStack_70;
  int iStack_6c;
  int iStack_68;
  undefined *puStack_64;
  int iStack_60;
  undefined4 *puStack_5c;
  char *pcStack_58;
  code *pcStack_54;
  undefined4 local_40;
  int local_3c;
  undefined *local_38;
  undefined4 local_30;
  int local_2c;
  
  puStack_64 = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  uVar4 = (**(code **)(local_38 + -0x7ed4))(param_2);
  puStack_5c = (undefined4 *)(**(code **)(local_38 + -0x7ca0))(uVar4);
  if (*(int *)(param_2 + 0x18) == 0) {
    pcStack_58 = (char *)0xffffffff;
    uStack_a0 = 0;
  }
  else {
    uStack_a0 = encode_gost_algor_params(param_2);
    pcStack_58 = (char *)0x10;
  }
  iVar5 = (**(code **)(local_38 + -0x7bec))(*(undefined4 *)(iVar3 + 0x18));
  iVar6 = iVar5 + 7;
  if (iVar5 + 7 < 0) {
    iVar6 = iVar5 + 0xe;
  }
  pcVar14 = (char *)(iVar6 >> 3);
  iVar6 = (**(code **)(local_38 + -0x7dd8))(pcVar14,"gost_ameth.c",0x291);
  (**(code **)(local_38 + -0x7be0))(*(undefined4 *)(iVar3 + 0x18),iVar6);
  uVar4 = (**(code **)(local_38 + -0x6754))();
  pcVar13 = pcVar14;
  (**(code **)(local_38 + -0x70d4))(uVar4,0);
  puVar7 = (undefined *)(**(code **)(local_38 + -0x7ab0))(uVar4);
  iVar3 = iVar6 + (int)pcVar14;
  if (0 < (int)pcVar14) {
    do {
      puVar1 = (undefined *)(iVar3 + -1);
      iVar3 = iVar3 + -1;
      *puVar7 = *puVar1;
      puVar7 = puVar7 + 1;
    } while (iVar6 != iVar3);
  }
  (**(code **)(local_38 + -0x7f58))(iVar6);
  puStack_b4 = &local_30;
  iStack_68 = (**(code **)(local_38 + -0x69e8))(uVar4);
  (**(code **)(local_38 + -0x674c))(uVar4);
  if (iStack_68 < 0) {
    iVar3 = 0;
  }
  else {
    local_40 = local_30;
    puStack_b4 = puStack_5c;
    pcVar13 = pcStack_58;
    local_3c = iStack_68;
    iVar3 = (**(code **)(local_38 + -0x6618))(param_1,puStack_5c,pcStack_58,uStack_a0);
  }
  if (local_2c == *(int *)puStack_64) {
    return iVar3;
  }
  pcStack_54 = priv_encode_gost;
  iStack_a8 = local_2c;
  (**(code **)(local_38 + -0x5328))();
  puStack_b0 = PTR___stack_chk_guard_006aabf0;
  puStack_78 = &_gp;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar12 = puStack_b4;
  iStack_60 = param_1;
  uVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puStack_b4);
  puStack_a4 = (undefined4 *)(**(code **)(puStack_78 + -0x7ca0))(uVar4);
  iVar3 = encode_gost_algor_params(puStack_b4);
  uStack_70 = 0;
  if (iVar3 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (**(code **)(puStack_78 + -0x7ed4))(puStack_b4);
    if (iVar6 == 0x32b) {
      iVar6 = (**(code **)(puStack_78 + -0x57fc))(puStack_b4);
      if (iVar6 == 0) goto LAB_0061bbb0;
      uVar4 = (**(code **)(puStack_78 + -0x6dd4))(iVar6);
    }
    else if ((iVar6 == 0x32c) &&
            (iVar6 = (**(code **)(puStack_78 + -0x57fc))(puStack_b4), iVar6 != 0)) {
      uVar4 = *(undefined4 *)(iVar6 + 0x1c);
    }
    else {
LAB_0061bbb0:
      uVar4 = 0;
    }
    uVar4 = (**(code **)(puStack_78 + -0x7cec))(uVar4,0);
    puStack_b4 = (undefined4 *)(**(code **)(puStack_78 + -0x69ec))(uVar4,&uStack_70);
    (**(code **)(puStack_78 + -0x7f4c))(uVar4);
    pcVar13 = (char *)0x0;
    uStack_84 = uStack_70;
    puVar12 = puStack_a4;
    iStack_88 = iVar3;
    puStack_80 = puStack_b4;
    iVar6 = (**(code **)(puStack_78 + -0x6628))(iStack_a8,puStack_a4,0,0x10);
    param_1 = iVar3;
  }
  if (iStack_6c == *(int *)puStack_b0) {
    return iVar6;
  }
  pcStack_9c = priv_print_gost94;
  iVar3 = iStack_6c;
  (**(code **)(puStack_78 + -0x5328))();
  puVar7 = PTR___stack_chk_guard_006aabf0;
  iVar5 = 0x80;
  iStack_bc = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar14 = pcVar13;
  iStack_ac = param_1;
  iVar6 = (*(code *)PTR_BIO_indent_006a97d0)();
  if (iVar6 == 0) goto LAB_0061bd00;
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Private key: ");
  iVar6 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(puVar12);
  if (iVar6 == 0x32b) {
    iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar12);
    if ((iVar6 != 0) && (iVar6 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar6), iVar6 != 0)
       ) goto LAB_0061bef8;
LAB_0061bd6c:
    (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"<undefined>");
  }
  else {
    if ((iVar6 != 0x32c) ||
       ((iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar12), iVar6 == 0 ||
        (iVar6 = *(int *)(iVar6 + 0x1c), iVar6 == 0)))) goto LAB_0061bd6c;
LAB_0061bef8:
    (*(code *)PTR_BN_print_006a8024)(iVar3,iVar6);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar12);
  uVar4 = *(undefined4 *)(iVar6 + 0x18);
  (*(code *)PTR_BIO_indent_006a97d0)(iVar3,pcVar13,0x80);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Public key: ");
  (*(code *)PTR_BN_print_006a8024)(iVar3,uVar4);
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
  iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(puVar12);
  uStack_c0 = (*(code *)PTR_BN_new_006a82b4)();
  if (*(int *)(PTR_R3410_paramset_006aa708 + 0xc) != 0) {
    puVar12 = (undefined4 *)PTR_R3410_paramset_006aa708;
    do {
      (*(code *)PTR_BN_dec2bn_006a8f20)(&uStack_c0);
      iVar5 = (*(code *)PTR_BN_cmp_006a8a4c)(uStack_c0,*(undefined4 *)(iVar6 + 0x10));
      if (iVar5 == 0) {
        (*(code *)PTR_BN_free_006a811c)(uStack_c0);
        uVar4 = *puVar12;
        goto LAB_0061be90;
      }
      piVar2 = puVar12 + 7;
      puVar12 = puVar12 + 4;
    } while (*piVar2 != 0);
  }
  uVar4 = 0;
  (*(code *)PTR_BN_free_006a811c)(uStack_c0);
LAB_0061be90:
  (*(code *)PTR_BIO_indent_006a97d0)(iVar3,pcVar13,0x80);
  iVar5 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar4);
  pcVar14 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Parameter set: %s\n",iVar5);
  iVar6 = 1;
LAB_0061bd00:
  if (iStack_bc == *(int *)puVar7) {
    return iVar6;
  }
  iVar3 = iStack_bc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar6 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar6 != 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar6);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar6);
    uVar8 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar6);
    uVar9 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar14);
    uVar9 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(uVar9);
    uVar10 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar14);
    uVar10 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar10);
    iVar11 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                       (uVar10,uVar9,uVar4,uVar8,iVar6);
    if (iVar11 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1d8);
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar6);
      return 0;
    }
    iVar11 = (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar5,0x80);
    if (iVar11 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Public key:\n");
      iVar11 = (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar5 + 3,0x80);
      if (iVar11 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,&DAT_0067b064);
        (*(code *)PTR_BN_print_006a8024)(iVar3,uVar4);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
        (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar5 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,&DAT_0067b068);
        (*(code *)PTR_BN_print_006a8024)(iVar3,uVar8);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
        (*(code *)PTR_BN_CTX_end_006a9654)(iVar6);
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar6);
        uVar4 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar14);
        uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar4);
        uVar4 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar4);
        iVar6 = (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar5,0x80);
        if (iVar6 != 0) {
          uVar4 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar4);
          (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Parameter set: %s\n",uVar4);
          return 1;
        }
      }
    }
    return 0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1ce);
  return 0;
}

