
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_NID(stack_st_X509_ATTRIBUTE **x,int nid,int type,uchar *bytes,int len)

{
  int iVar1;
  X509_ATTRIBUTE *attr;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  stack_st_X509_ATTRIBUTE *psVar6;
  code *pcVar7;
  
  iVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(nid);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x88,0x6d,"x509_att.c",0xdc);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  attr = (X509_ATTRIBUTE *)(*(code *)PTR_X509_ATTRIBUTE_new_006a9fe0)();
  if (attr == (X509_ATTRIBUTE *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x89,0x41,"x509_att.c",0xed);
LAB_0058282c:
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(attr->object);
  pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(iVar1);
  attr->object = pAVar2;
  iVar3 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
  if (iVar3 == 0) {
    (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(attr);
    goto LAB_0058282c;
  }
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    uVar5 = 0x43;
    uVar4 = 0x81;
LAB_005828b0:
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x87,uVar5,"x509_att.c",uVar4);
  }
  else {
    psVar6 = *x;
    if ((psVar6 == (stack_st_X509_ATTRIBUTE *)0x0) &&
       (psVar6 = (stack_st_X509_ATTRIBUTE *)(*(code *)PTR_sk_new_null_006a80a4)(),
       psVar6 == (stack_st_X509_ATTRIBUTE *)0x0)) {
      uVar5 = 0x41;
      uVar4 = 0x95;
      goto LAB_005828b0;
    }
    iVar1 = (*(code *)PTR_X509_ATTRIBUTE_dup_006aa084)(attr);
    if (iVar1 != 0) {
      iVar3 = (*(code *)PTR_sk_push_006a80a8)(psVar6,iVar1);
      pcVar7 = (code *)PTR_X509_ATTRIBUTE_free_006a9c00;
      if (iVar3 != 0) {
        if (*x == (stack_st_X509_ATTRIBUTE *)0x0) {
          *x = psVar6;
        }
        goto LAB_005827f0;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x87,0x41,"x509_att.c",0x95);
      (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(iVar1);
    }
    (*(code *)PTR_sk_free_006a7f80)(psVar6);
  }
  psVar6 = (stack_st_X509_ATTRIBUTE *)0x0;
  pcVar7 = (code *)PTR_X509_ATTRIBUTE_free_006a9c00;
LAB_005827f0:
  (*pcVar7)(attr);
  return psVar6;
}

