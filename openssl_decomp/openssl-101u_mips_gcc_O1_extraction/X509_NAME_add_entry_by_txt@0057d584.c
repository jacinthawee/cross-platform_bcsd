
int X509_NAME_add_entry_by_txt
              (X509_NAME *name,char *field,int type,uchar *bytes,int len,int loc,int set)

{
  int iVar1;
  X509_NAME_ENTRY *ne;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_OBJ_txt2obj_006a7000)(field,0);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x83,0x77,"x509name.c",0x127);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"name=",field);
  }
  else {
    ne = (X509_NAME_ENTRY *)(*(code *)PTR_X509_NAME_ENTRY_new_006a8f38)();
    if (ne != (X509_NAME_ENTRY *)0x0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a7004)(ne->object);
      pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a8494)(iVar1);
      ne->object = pAVar2;
      if (pAVar2 != (ASN1_OBJECT *)0x0) {
        iVar3 = X509_NAME_ENTRY_set_data(ne,type,bytes,len);
        if (iVar3 != 0) {
          (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar1);
          iVar1 = X509_NAME_add_entry(name,ne,loc,set);
          (*(code *)PTR_X509_NAME_ENTRY_free_006a7150)(ne);
          return iVar1;
        }
      }
      (*(code *)PTR_X509_NAME_ENTRY_free_006a7150)(ne);
    }
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar1);
  }
  return 0;
}

