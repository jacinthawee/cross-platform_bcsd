
int priv_print_gost94(undefined4 param_1,undefined4 param_2,char *param_3)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 local_28;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar11 = 0x80;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar10 = param_3;
  iVar3 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
  if (iVar3 == 0) goto LAB_0061bd00;
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Private key: ");
  iVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_2);
  if (iVar3 == 0x32b) {
    iVar3 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
    if ((iVar3 != 0) && (iVar3 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar3), iVar3 != 0)
       ) goto LAB_0061bef8;
LAB_0061bd6c:
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"<undefined>");
  }
  else {
    if ((iVar3 != 0x32c) ||
       ((iVar3 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2), iVar3 == 0 ||
        (iVar3 = *(int *)(iVar3 + 0x1c), iVar3 == 0)))) goto LAB_0061bd6c;
LAB_0061bef8:
    (*(code *)PTR_BN_print_006a8024)(param_1,iVar3);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n");
  iVar3 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  uVar5 = *(undefined4 *)(iVar3 + 0x18);
  (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Public key: ");
  (*(code *)PTR_BN_print_006a8024)(param_1,uVar5);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n");
  iVar3 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  local_28 = (*(code *)PTR_BN_new_006a82b4)();
  if (*(int *)(PTR_R3410_paramset_006aa708 + 0xc) != 0) {
    puVar12 = (undefined4 *)PTR_R3410_paramset_006aa708;
    do {
      (*(code *)PTR_BN_dec2bn_006a8f20)(&local_28);
      iVar11 = (*(code *)PTR_BN_cmp_006a8a4c)(local_28,*(undefined4 *)(iVar3 + 0x10));
      if (iVar11 == 0) {
        (*(code *)PTR_BN_free_006a811c)(local_28);
        uVar5 = *puVar12;
        goto LAB_0061be90;
      }
      piVar1 = puVar12 + 7;
      puVar12 = puVar12 + 4;
    } while (*piVar1 != 0);
  }
  uVar5 = 0;
  (*(code *)PTR_BN_free_006a811c)(local_28);
LAB_0061be90:
  (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
  iVar11 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar5);
  pcVar10 = "Parameter set: %s\n";
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Parameter set: %s\n",iVar11);
  iVar3 = 1;
LAB_0061bd00:
  if (local_24 == *(int *)puVar2) {
    return iVar3;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar4 != 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar4);
    uVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar4);
    uVar6 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar4);
    uVar7 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar10);
    uVar7 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(uVar7);
    uVar8 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar10);
    uVar8 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar8);
    iVar9 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                      (uVar8,uVar7,uVar5,uVar6,iVar4);
    if (iVar9 == 0) {
      ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1d8);
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
      return 0;
    }
    iVar9 = (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar11,0x80);
    if (iVar9 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Public key:\n");
      iVar9 = (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar11 + 3,0x80);
      if (iVar9 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,&DAT_0067b044);
        (*(code *)PTR_BN_print_006a8024)(iVar3,uVar5);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
        (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar11 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,&DAT_0067b048);
        (*(code *)PTR_BN_print_006a8024)(iVar3,uVar6);
        (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"\n");
        (*(code *)PTR_BN_CTX_end_006a9654)(iVar4);
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
        uVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(pcVar10);
        uVar5 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar5);
        uVar5 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar5);
        iVar11 = (*(code *)PTR_BIO_indent_006a97d0)(iVar3,iVar11,0x80);
        if (iVar11 != 0) {
          uVar5 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar5);
          (*(code *)PTR_BIO_printf_006a7f38)(iVar3,"Parameter set: %s\n",uVar5);
          return 1;
        }
      }
    }
    return 0;
  }
  ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1ce);
  return 0;
}

