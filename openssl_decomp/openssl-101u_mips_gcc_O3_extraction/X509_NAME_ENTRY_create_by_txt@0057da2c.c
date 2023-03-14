
X509_NAME_ENTRY *
X509_NAME_ENTRY_create_by_txt(X509_NAME_ENTRY **ne,char *field,int type,uchar *bytes,int len)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  X509_NAME_ENTRY *pXVar4;
  X509_NAME_ENTRY *ne_00;
  
  iVar1 = (*(code *)PTR_OBJ_txt2obj_006a7000)(field,0);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x83,0x77,"x509name.c",0x127);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"name=",field);
    return (X509_NAME_ENTRY *)0x0;
  }
  if ((ne == (X509_NAME_ENTRY **)0x0) || (ne_00 = *ne, ne_00 == (X509_NAME_ENTRY *)0x0)) {
    ne_00 = (X509_NAME_ENTRY *)(*(code *)PTR_X509_NAME_ENTRY_new_006a8f38)();
    if (ne_00 == (X509_NAME_ENTRY *)0x0) goto LAB_0057dacc;
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(ne_00->object);
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a8494)(iVar1);
    ne_00->object = pAVar2;
    if ((pAVar2 == (ASN1_OBJECT *)0x0) ||
       (iVar3 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar3 == 0)) {
      if (ne != (X509_NAME_ENTRY **)0x0) goto LAB_0057dab4;
      goto LAB_0057dac0;
    }
    if (ne == (X509_NAME_ENTRY **)0x0) goto LAB_0057dad0;
    pXVar4 = *ne;
  }
  else {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(ne_00->object);
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a8494)(iVar1);
    ne_00->object = pAVar2;
    if ((pAVar2 == (ASN1_OBJECT *)0x0) ||
       (iVar3 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar3 == 0)) {
LAB_0057dab4:
      if (ne_00 != *ne) {
LAB_0057dac0:
        (*(code *)PTR_X509_NAME_ENTRY_free_006a7150)(ne_00);
      }
LAB_0057dacc:
      ne_00 = (X509_NAME_ENTRY *)0x0;
      goto LAB_0057dad0;
    }
    pXVar4 = *ne;
  }
  if (pXVar4 == (X509_NAME_ENTRY *)0x0) {
    *ne = ne_00;
  }
LAB_0057dad0:
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar1);
  return ne_00;
}
