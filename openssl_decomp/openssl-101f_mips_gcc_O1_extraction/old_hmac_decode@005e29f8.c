
undefined4 old_hmac_decode(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(iVar1,*param_2,param_3);
    if (iVar2 != 0) {
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x357,iVar1);
      return 1;
    }
  }
  return 0;
}

