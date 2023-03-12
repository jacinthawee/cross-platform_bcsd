
ASN1_OCTET_STRING * PKCS7_digest_from_attributes(stack_st_X509_ATTRIBUTE *sk)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x33);
  if ((iVar1 != 0) && (sk != (stack_st_X509_ATTRIBUTE *)0x0)) {
    iVar4 = 0;
    do {
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(sk);
      if (iVar3 <= iVar4) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(sk,iVar4);
      iVar3 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar2,iVar1);
      iVar4 = iVar4 + 1;
    } while (iVar3 != 0);
    if (((puVar2[1] == 0) && (iVar1 = (*(code *)PTR_sk_num_006a7f2c)(puVar2[2]), iVar1 != 0)) &&
       (iVar1 = (*(code *)PTR_sk_value_006a7f24)(puVar2[2],0), iVar1 != 0)) {
      return *(ASN1_OCTET_STRING **)(iVar1 + 4);
    }
  }
  return (ASN1_OCTET_STRING *)0x0;
}

