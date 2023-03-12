
int param_print_gost01(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar1);
  uVar1 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar1);
  iVar2 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3,0x80);
  if (iVar2 != 0) {
    uVar1 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar1);
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Parameter set: %s\n",uVar1);
    iVar2 = 1;
  }
  return iVar2;
}

