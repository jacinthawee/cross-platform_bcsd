
undefined4 old_rsa_priv_decode(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_d2i_RSAPrivateKey_006a8ad4)(0);
  if (iVar1 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,6,iVar1);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(4,0x93,4,"rsa_ameth.c",0x73);
  return 0;
}

