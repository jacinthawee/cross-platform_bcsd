
undefined4 priv_print_gost01(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar1 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3,0x80);
  if (iVar1 == 0) {
    return 0;
  }
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Private key: ");
  iVar1 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_2);
  if (iVar1 == 0x32b) {
    iVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar1);
      goto joined_r0x0061bc9c;
    }
  }
  else if ((iVar1 == 0x32c) && (iVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2), iVar1 != 0))
  {
    iVar1 = *(int *)(iVar1 + 0x1c);
joined_r0x0061bc9c:
    if (iVar1 != 0) {
      (*(code *)PTR_BN_print_006a6f24)(param_1,iVar1);
      goto LAB_0061b990;
    }
  }
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"<undefined)");
LAB_0061b990:
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"\n");
  iVar1 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar1 == 0) {
    ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1b8);
    return 0;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(iVar1);
  uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
  uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
  uVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  uVar4 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(uVar4);
  uVar5 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  uVar5 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar5);
  iVar6 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)(uVar5,uVar4,uVar2,uVar3,iVar1)
  ;
  if (iVar6 == 0) {
    ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1c2);
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
    return 0;
  }
  iVar6 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3,0x80);
  if (iVar6 != 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Public key:\n");
    iVar6 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3 + 3,0x80);
    if (iVar6 != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,&DAT_0067a7b4);
      (*(code *)PTR_BN_print_006a6f24)(param_1,uVar2);
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"\n");
      (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3 + 3,0x80);
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,&DAT_0067a7b8);
      (*(code *)PTR_BN_print_006a6f24)(param_1,uVar3);
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"\n");
      (*(code *)PTR_BN_CTX_end_006a8530)(iVar1);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
      uVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
      uVar2 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar2);
      uVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar2);
      iVar1 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3,0x80);
      if (iVar1 != 0) {
        uVar2 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar2);
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Parameter set: %s\n",uVar2);
        return 1;
      }
    }
  }
  return 0;
}

