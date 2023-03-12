
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
  
  attr = (X509_ATTRIBUTE *)(*(code *)PTR_X509_ATTRIBUTE_new_006a9fe0)();
  if (attr == (X509_ATTRIBUTE *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x89,0x41,"x509_att.c",0xed);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  if (obj == (ASN1_OBJECT *)0x0) {
LAB_00582358:
    (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(attr);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(attr->object);
  pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(obj);
  attr->object = pAVar1;
  iVar2 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
  if (iVar2 == 0) goto LAB_00582358;
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    uVar5 = 0x43;
    uVar4 = 0x81;
LAB_005823dc:
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x87,uVar5,"x509_att.c",uVar4);
  }
  else {
    psVar6 = *x;
    if ((psVar6 == (stack_st_X509_ATTRIBUTE *)0x0) &&
       (psVar6 = (stack_st_X509_ATTRIBUTE *)(*(code *)PTR_sk_new_null_006a80a4)(),
       psVar6 == (stack_st_X509_ATTRIBUTE *)0x0)) {
      uVar5 = 0x41;
      uVar4 = 0x95;
      goto LAB_005823dc;
    }
    iVar2 = (*(code *)PTR_X509_ATTRIBUTE_dup_006aa084)(attr);
    if (iVar2 != 0) {
      iVar3 = (*(code *)PTR_sk_push_006a80a8)(psVar6,iVar2);
      pcVar7 = (code *)PTR_X509_ATTRIBUTE_free_006a9c00;
      if (iVar3 != 0) {
        if (*x == (stack_st_X509_ATTRIBUTE *)0x0) {
          *x = psVar6;
        }
        goto LAB_0058232c;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x87,0x41,"x509_att.c",0x95);
      (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(iVar2);
    }
    (*(code *)PTR_sk_free_006a7f80)(psVar6);
  }
  psVar6 = (stack_st_X509_ATTRIBUTE *)0x0;
  pcVar7 = (code *)PTR_X509_ATTRIBUTE_free_006a9c00;
LAB_0058232c:
  (*pcVar7)(attr);
  return psVar6;
}

