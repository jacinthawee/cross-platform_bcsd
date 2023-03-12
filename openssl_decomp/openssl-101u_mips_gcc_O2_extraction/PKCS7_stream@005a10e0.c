
int PKCS7_stream(uchar ***boundary,PKCS7 *p7)

{
  int iVar1;
  ASN1_OCTET_STRING *pAVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if (iVar1 == 0x16) {
    pAVar2 = (((p7->d).sign)->contents->d).data;
  }
  else if (iVar1 < 0x17) {
    if (iVar1 != 0x15) {
      return 0;
    }
    pAVar2 = (p7->d).data;
  }
  else if (iVar1 == 0x17) {
    pAVar2 = (ASN1_OCTET_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (pAVar2 != (ASN1_OCTET_STRING *)0x0) goto LAB_005a114c;
    pAVar2 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
    (((p7->d).sign)->cert->stack).sorted = (int)pAVar2;
  }
  else {
    if (iVar1 != 0x18) {
      return 0;
    }
    pAVar2 = (ASN1_OCTET_STRING *)((p7->d).sign)->contents->state;
    if (pAVar2 != (ASN1_OCTET_STRING *)0x0) goto LAB_005a114c;
    pAVar2 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
    ((p7->d).sign)->contents->state = (int)pAVar2;
  }
  if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
    return 0;
  }
LAB_005a114c:
  pAVar2->flags = pAVar2->flags | 0x10;
  *boundary = &pAVar2->data;
  return 1;
}

