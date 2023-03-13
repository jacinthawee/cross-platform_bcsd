
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_txt(stack_st_X509_ATTRIBUTE **x,char *attrname,int type,uchar *bytes,int len)

{
  int iVar1;
  X509_ATTRIBUTE *attr;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  stack_st_X509_ATTRIBUTE *psVar6;
  code *pcVar7;
  
  iVar1 = (*(code *)PTR_OBJ_txt2obj_006a7000)(attrname,0);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x8c,0x77,"x509_att.c",0x116);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"name=",attrname);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  attr = (X509_ATTRIBUTE *)(*(code *)PTR_X509_ATTRIBUTE_new_006a8ec4)();
  if (attr == (X509_ATTRIBUTE *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x89,0x41,"x509_att.c",0xf7);
LAB_0057f7c8:
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar1);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(attr->object);
  pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a8494)(iVar1);
  attr->object = pAVar2;
  iVar3 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
  if (iVar3 == 0) {
    (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(attr);
    goto LAB_0057f7c8;
  }
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar1);
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    uVar5 = 0x43;
    uVar4 = 0x81;
LAB_0057f850:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x87,uVar5,"x509_att.c",uVar4);
  }
  else {
    psVar6 = *x;
    if ((psVar6 == (stack_st_X509_ATTRIBUTE *)0x0) &&
       (psVar6 = (stack_st_X509_ATTRIBUTE *)(*(code *)PTR_sk_new_null_006a6fa4)(),
       psVar6 == (stack_st_X509_ATTRIBUTE *)0x0)) {
      uVar5 = 0x41;
      uVar4 = 0x93;
      goto LAB_0057f850;
    }
    iVar1 = (*(code *)PTR_X509_ATTRIBUTE_dup_006a8f68)(attr);
    if (iVar1 != 0) {
      iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar6,iVar1);
      pcVar7 = (code *)PTR_X509_ATTRIBUTE_free_006a8ae4;
      if (iVar3 != 0) {
        if (*x == (stack_st_X509_ATTRIBUTE *)0x0) {
          *x = psVar6;
        }
        goto LAB_0057f78c;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x87,0x41,"x509_att.c",0x93);
      (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(iVar1);
    }
    (*(code *)PTR_sk_free_006a6e80)(psVar6);
  }
  psVar6 = (stack_st_X509_ATTRIBUTE *)0x0;
  pcVar7 = (code *)PTR_X509_ATTRIBUTE_free_006a8ae4;
LAB_0057f78c:
  (*pcVar7)(attr);
  return psVar6;
}

