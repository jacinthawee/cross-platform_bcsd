
int X509_NAME_add_entry_by_NID
              (X509_NAME *name,int nid,int type,uchar *bytes,int len,int loc,int set)

{
  int iVar1;
  X509_NAME_ENTRY *ne;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(nid);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x72,0x6d,"x509name.c",0x12f);
  }
  else {
    ne = (X509_NAME_ENTRY *)(*(code *)PTR_X509_NAME_ENTRY_new_006aa054)();
    if (ne != (X509_NAME_ENTRY *)0x0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a8104)(ne->object);
      pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(iVar1);
      ne->object = pAVar2;
      if (pAVar2 != (ASN1_OBJECT *)0x0) {
        iVar3 = X509_NAME_ENTRY_set_data(ne,type,bytes,len);
        if (iVar3 != 0) {
          (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
          iVar1 = X509_NAME_add_entry(name,ne,loc,set);
          (*(code *)PTR_X509_NAME_ENTRY_free_006a8250)(ne);
          return iVar1;
        }
      }
      (*(code *)PTR_X509_NAME_ENTRY_free_006a8250)(ne);
    }
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
  }
  return 0;
}
