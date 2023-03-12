
undefined4 pub_print_gost01(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar1 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar1 == 0) {
    ERR_GOST_error(0x83,0x41,"gost_ameth.c",0x1ce);
    return 0;
  }
  (*(code *)PTR_BN_CTX_start_006a9644)(iVar1);
  uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar1);
  uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(iVar1);
  uVar4 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  uVar4 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(uVar4);
  uVar5 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  uVar5 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar5);
  iVar6 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)(uVar5,uVar4,uVar2,uVar3,iVar1)
  ;
  if (iVar6 != 0) {
    iVar6 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
    if (iVar6 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Public key:\n");
      iVar6 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3 + 3,0x80);
      if (iVar6 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_0067b044);
        (*(code *)PTR_BN_print_006a8024)(param_1,uVar2);
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n");
        (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3 + 3,0x80);
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_0067b048);
        (*(code *)PTR_BN_print_006a8024)(param_1,uVar3);
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n");
        (*(code *)PTR_BN_CTX_end_006a9654)(iVar1);
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar1);
        uVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
        uVar2 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar2);
        uVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar2);
        iVar1 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
        if (iVar1 != 0) {
          uVar2 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar2);
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Parameter set: %s\n",uVar2);
          return 1;
        }
      }
    }
    return 0;
  }
  ERR_GOST_error(0x83,0x10,"gost_ameth.c",0x1d8);
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar1);
  return 0;
}

