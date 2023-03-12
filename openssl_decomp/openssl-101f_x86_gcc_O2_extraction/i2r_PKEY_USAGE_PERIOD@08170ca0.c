
undefined4
i2r_PKEY_USAGE_PERIOD
          (undefined4 param_1,ASN1_GENERALIZEDTIME **param_2,BIO *param_3,undefined4 param_4)

{
  BIO_printf(param_3,"%*s",param_4,&DAT_081ec74a);
  if (*param_2 != (ASN1_GENERALIZEDTIME *)0x0) {
    BIO_write(param_3,"Not Before: ",0xc);
    ASN1_GENERALIZEDTIME_print(param_3,*param_2);
    if (param_2[1] == (ASN1_GENERALIZEDTIME *)0x0) {
      return 1;
    }
    BIO_write(param_3,", ",2);
  }
  if (param_2[1] != (ASN1_GENERALIZEDTIME *)0x0) {
    BIO_write(param_3,"Not After: ",0xb);
    ASN1_GENERALIZEDTIME_print(param_3,param_2[1]);
  }
  return 1;
}

