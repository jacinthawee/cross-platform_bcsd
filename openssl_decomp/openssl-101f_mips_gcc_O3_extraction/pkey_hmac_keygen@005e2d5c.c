
undefined4 pkey_hmac_keygen(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x14) + 0xc) == 0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_dup_006aa774)(*(int *)(param_1 + 0x14) + 4);
  if (iVar1 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_2,0x357,iVar1);
    return 1;
  }
  return 0;
}

