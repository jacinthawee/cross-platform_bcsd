
bool i2r_ocsp_crlid(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (((*param_2 == 0) ||
      (((iVar1 = (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*scrlUrl: ",param_4,""), 0 < iVar1 &&
        (iVar1 = (*(code *)PTR_ASN1_STRING_print_006a8d54)(param_3,*param_2), iVar1 != 0)) &&
       (iVar1 = (*(code *)PTR_BIO_write_006a6e14)(param_3,"\n",1), 0 < iVar1)))) &&
     ((param_2[1] == 0 ||
      (((iVar1 = (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*scrlNum: ",param_4,""), 0 < iVar1 &&
        (iVar1 = (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(param_3,param_2[1]), 0 < iVar1)) &&
       (iVar1 = (*(code *)PTR_BIO_write_006a6e14)(param_3,"\n",1), 0 < iVar1)))))) {
    if (param_2[2] == 0) {
      return true;
    }
    iVar1 = (*(code *)PTR_BIO_printf_006a6e38)(param_3,"%*scrlTime: ",param_4,"");
    if ((0 < iVar1) &&
       (iVar1 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(param_3,param_2[2]), iVar1 != 0))
    {
      iVar1 = (*(code *)PTR_BIO_write_006a6e14)(param_3,"\n",1);
      return 0 < iVar1;
    }
  }
  return false;
}

