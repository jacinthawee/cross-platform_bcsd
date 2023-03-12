
int PKCS7_add_attribute(PKCS7_SIGNER_INFO *p7si,int nid,int atrtype,void *value)

{
  undefined4 *puVar1;
  int iVar2;
  stack_st_X509_ATTRIBUTE *psVar3;
  stack_st_X509_ATTRIBUTE **ppsVar4;
  int iVar5;
  
  ppsVar4 = &p7si->unauth_attr;
  psVar3 = *ppsVar4;
  if (psVar3 == (stack_st_X509_ATTRIBUTE *)0x0) {
    psVar3 = (stack_st_X509_ATTRIBUTE *)(*(code *)PTR_sk_new_null_006a6fa4)();
    *ppsVar4 = psVar3;
    if (psVar3 == (stack_st_X509_ATTRIBUTE *)0x0) {
      return 0;
    }
  }
  else {
    for (iVar5 = 0; iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar3), iVar5 < iVar2; iVar5 = iVar5 + 1
        ) {
      puVar1 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(*ppsVar4,iVar5);
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar1);
      if (iVar2 == nid) {
        (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(puVar1);
        iVar2 = (*(code *)PTR_X509_ATTRIBUTE_create_006a913c)(nid,atrtype,value);
        if (iVar2 == 0) {
          return 0;
        }
        iVar5 = (*(code *)PTR_sk_set_006a8358)(*ppsVar4,iVar5,iVar2);
        if (iVar5 != 0) {
          return 1;
        }
        (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(iVar2);
        return 0;
      }
      psVar3 = *ppsVar4;
    }
  }
  iVar5 = (*(code *)PTR_X509_ATTRIBUTE_create_006a913c)(nid,atrtype,value);
  if (iVar5 == 0) {
    return 0;
  }
  iVar2 = (*(code *)PTR_sk_push_006a6fa8)(*ppsVar4,iVar5);
  if (iVar2 != 0) {
    return 1;
  }
  (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(iVar5);
  return 0;
}

