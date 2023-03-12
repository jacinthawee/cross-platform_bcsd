
ASN1_TYPE * PKCS7_get_attribute(PKCS7_SIGNER_INFO *si,int nid)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  ASN1_TYPE *pAVar4;
  int iVar5;
  stack_st_X509_ATTRIBUTE *psVar6;
  
  psVar6 = si->unauth_attr;
  iVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(nid);
  if ((iVar1 != 0) && (psVar6 != (stack_st_X509_ATTRIBUTE *)0x0)) {
    iVar5 = 0;
    do {
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar6);
      if (iVar3 <= iVar5) {
        return (ASN1_TYPE *)0x0;
      }
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(psVar6,iVar5);
      iVar3 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar2,iVar1);
      iVar5 = iVar5 + 1;
    } while (iVar3 != 0);
    if ((puVar2[1] == 0) && (iVar1 = (*(code *)PTR_sk_num_006a7f2c)(puVar2[2]), iVar1 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x005a6d2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pAVar4 = (ASN1_TYPE *)(*(code *)PTR_sk_value_006a7f24)(puVar2[2],0);
      return pAVar4;
    }
  }
  return (ASN1_TYPE *)0x0;
}

