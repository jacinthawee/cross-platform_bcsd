
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_OBJ(stack_st_X509_ATTRIBUTE **x,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  X509_ATTRIBUTE *attr;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  stack_st_X509_ATTRIBUTE *psVar6;
  code *pcVar7;
  
  attr = (X509_ATTRIBUTE *)(*(code *)PTR_X509_ATTRIBUTE_new_006a8ec4)();
  if (attr == (X509_ATTRIBUTE *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x89,0x41,"x509_att.c",0xf7);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  if (obj == (ASN1_OBJECT *)0x0) {
LAB_0057f578:
    (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(attr);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(attr->object);
  pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a8494)(obj);
  attr->object = pAVar1;
  iVar2 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
  if (iVar2 == 0) goto LAB_0057f578;
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    uVar5 = 0x43;
    uVar4 = 0x81;
LAB_0057f5fc:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x87,uVar5,"x509_att.c",uVar4);
  }
  else {
    psVar6 = *x;
    if ((psVar6 == (stack_st_X509_ATTRIBUTE *)0x0) &&
       (psVar6 = (stack_st_X509_ATTRIBUTE *)(*(code *)PTR_sk_new_null_006a6fa4)(),
       psVar6 == (stack_st_X509_ATTRIBUTE *)0x0)) {
      uVar5 = 0x41;
      uVar4 = 0x93;
      goto LAB_0057f5fc;
    }
    iVar2 = (*(code *)PTR_X509_ATTRIBUTE_dup_006a8f68)(attr);
    if (iVar2 != 0) {
      iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar6,iVar2);
      pcVar7 = (code *)PTR_X509_ATTRIBUTE_free_006a8ae4;
      if (iVar3 != 0) {
        if (*x == (stack_st_X509_ATTRIBUTE *)0x0) {
          *x = psVar6;
        }
        goto LAB_0057f54c;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x87,0x41,"x509_att.c",0x93);
      (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(iVar2);
    }
    (*(code *)PTR_sk_free_006a6e80)(psVar6);
  }
  psVar6 = (stack_st_X509_ATTRIBUTE *)0x0;
  pcVar7 = (code *)PTR_X509_ATTRIBUTE_free_006a8ae4;
LAB_0057f54c:
  (*pcVar7)(attr);
  return psVar6;
}

