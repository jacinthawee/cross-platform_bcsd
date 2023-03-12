
int param_print_gost01(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar1);
  uVar1 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar1);
  iVar2 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
  if (iVar2 != 0) {
    uVar1 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar1);
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Parameter set: %s\n",uVar1);
    iVar2 = 1;
  }
  return iVar2;
}

