
undefined4 old_dsa_priv_decode(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_d2i_DSAPrivateKey_006a9f3c)(0);
  if (iVar1 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x74,iVar1);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(10,0x7a,10,"dsa_ameth.c",0x215);
  return 0;
}
