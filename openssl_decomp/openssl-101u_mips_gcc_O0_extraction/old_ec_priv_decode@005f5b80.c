
undefined4 old_ec_priv_decode(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_d2i_ECPrivateKey_006a8e1c)(0);
  if (iVar1 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x198,iVar1);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xde,0x8e,"ec_ameth.c",0x219);
  return 0;
}

