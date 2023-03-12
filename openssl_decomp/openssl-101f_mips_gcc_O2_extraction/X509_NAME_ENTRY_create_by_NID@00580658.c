
X509_NAME_ENTRY *
X509_NAME_ENTRY_create_by_NID(X509_NAME_ENTRY **ne,int nid,int type,uchar *bytes,int len)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  X509_NAME_ENTRY *pXVar4;
  X509_NAME_ENTRY *ne_00;
  
  iVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(nid);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x72,0x6d,"x509name.c",0x12f);
    return (X509_NAME_ENTRY *)0x0;
  }
  if ((ne == (X509_NAME_ENTRY **)0x0) || (ne_00 = *ne, ne_00 == (X509_NAME_ENTRY *)0x0)) {
    ne_00 = (X509_NAME_ENTRY *)(*(code *)PTR_X509_NAME_ENTRY_new_006aa054)();
    if (ne_00 == (X509_NAME_ENTRY *)0x0) goto LAB_005806f0;
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(ne_00->object);
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(iVar1);
    ne_00->object = pAVar2;
    if ((pAVar2 == (ASN1_OBJECT *)0x0) ||
       (iVar3 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar3 == 0)) {
      if (ne != (X509_NAME_ENTRY **)0x0) goto LAB_005806d8;
      goto LAB_005806e4;
    }
    if (ne == (X509_NAME_ENTRY **)0x0) goto LAB_005806f4;
    pXVar4 = *ne;
  }
  else {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(ne_00->object);
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_dup_006a95b4)(iVar1);
    ne_00->object = pAVar2;
    if ((pAVar2 == (ASN1_OBJECT *)0x0) ||
       (iVar3 = X509_NAME_ENTRY_set_data(ne_00,type,bytes,len), iVar3 == 0)) {
LAB_005806d8:
      if (ne_00 != *ne) {
LAB_005806e4:
        (*(code *)PTR_X509_NAME_ENTRY_free_006a8250)(ne_00);
      }
LAB_005806f0:
      ne_00 = (X509_NAME_ENTRY *)0x0;
      goto LAB_005806f4;
    }
    pXVar4 = *ne;
  }
  if (pXVar4 == (X509_NAME_ENTRY *)0x0) {
    *ne = ne_00;
  }
LAB_005806f4:
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
  return ne_00;
}

