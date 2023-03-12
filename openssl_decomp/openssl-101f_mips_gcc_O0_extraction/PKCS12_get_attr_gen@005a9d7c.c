
ASN1_TYPE * PKCS12_get_attr_gen(stack_st_X509_ATTRIBUTE *attrs,int attr_nid)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  ASN1_TYPE *pAVar4;
  
  if (attrs == (stack_st_X509_ATTRIBUTE *)0x0) {
    return (ASN1_TYPE *)0x0;
  }
  iVar3 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(attrs);
    if (iVar2 <= iVar3) {
      return (ASN1_TYPE *)0x0;
    }
    puVar1 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(attrs,iVar3);
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar1);
    iVar3 = iVar3 + 1;
  } while (iVar2 != attr_nid);
  iVar3 = (*(code *)PTR_sk_num_006a7f2c)(puVar1[2]);
  if (iVar3 == 0) {
    return (ASN1_TYPE *)0x0;
  }
                    /* WARNING: Could not recover jumptable at 0x005a9e54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pAVar4 = (ASN1_TYPE *)(*(code *)PTR_sk_value_006a7f24)(puVar1[2],0);
  return pAVar4;
}

