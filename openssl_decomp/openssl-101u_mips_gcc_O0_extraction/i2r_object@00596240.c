
bool i2r_object(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BIO_printf_006a6e38)(param_3,&DAT_0066d674,param_4,"");
  if (0 < iVar1) {
    iVar1 = (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(param_3,param_2);
    return 0 < iVar1;
  }
  return false;
}

