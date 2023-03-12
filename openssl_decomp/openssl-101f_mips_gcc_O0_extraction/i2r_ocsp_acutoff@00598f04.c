
bool i2r_ocsp_acutoff(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BIO_printf_006a7f38)(param_3,&DAT_0066df84,param_4,"");
  if (0 < iVar1) {
    iVar1 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(param_3,param_2);
    return iVar1 != 0;
  }
  return false;
}

