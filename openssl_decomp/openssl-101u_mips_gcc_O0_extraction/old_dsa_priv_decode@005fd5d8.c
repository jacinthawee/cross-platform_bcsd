
undefined4 old_dsa_priv_decode(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_d2i_DSAPrivateKey_006a8e20)(0);
  if (iVar1 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x74,iVar1);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(10,0x7a,10,"dsa_ameth.c",0x205);
  return 0;
}

