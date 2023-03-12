
undefined4 eckey_param_decode(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_d2i_ECParameters_006aa7d8)(0);
  if (iVar1 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x198,iVar1);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd4,0x10,"ec_ameth.c",0x210);
  return 0;
}

