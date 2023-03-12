
undefined4 old_hmac_decode(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a8668)();
  if (((iVar1 != 0) &&
      (iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)(iVar1,*param_2,param_3), iVar2 != 0))
     && (iVar2 = (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x357,iVar1), iVar2 != 0)) {
    return 1;
  }
  (*(code *)PTR_ASN1_OCTET_STRING_free_006a8cfc)(iVar1);
  return 0;
}

