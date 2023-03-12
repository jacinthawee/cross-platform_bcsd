
undefined4
i2r_PKEY_USAGE_PERIOD(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  (*(code *)PTR_BIO_printf_006a6e38)(param_3,&DAT_0066d674,param_4,"");
  if (*param_2 != 0) {
    (*(code *)PTR_BIO_write_006a6e14)(param_3,"Not Before: ",0xc);
    (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(param_3,*param_2);
    if (param_2[1] == 0) {
      return 1;
    }
    (*(code *)PTR_BIO_write_006a6e14)(param_3,", ",2);
  }
  if (param_2[1] != 0) {
    (*(code *)PTR_BIO_write_006a6e14)(param_3,"Not After: ",0xb);
    (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(param_3,param_2[1]);
  }
  return 1;
}

