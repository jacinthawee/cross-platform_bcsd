
bool i2r_ocsp_nonce(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BIO_printf_006a7f38)(param_3,&DAT_0066dfa4,param_4,"");
  if (0 < iVar1) {
    iVar1 = (*(code *)PTR_i2a_ASN1_STRING_006aa1a4)(param_3,param_2,4);
    return 0 < iVar1;
  }
  return false;
}

