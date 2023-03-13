
int PKCS7_stream(uchar ***boundary,PKCS7 *p7)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
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
    pAVar2 = (ASN1_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (pAVar2 != (ASN1_STRING *)0x0) goto LAB_0817bcb1;
    pAVar2 = ASN1_STRING_type_new(4);
    ((p7->d).enveloped)->enc_data->enc_data = pAVar2;
  }
  else {
    if (iVar1 != 0x18) {
      return 0;
    }
    pAVar2 = (ASN1_STRING *)((p7->d).sign)->contents->state;
    if (pAVar2 != (ASN1_STRING *)0x0) goto LAB_0817bcb1;
    pAVar2 = ASN1_STRING_type_new(4);
    ((p7->d).signed_and_enveloped)->enc_data->enc_data = pAVar2;
  }
  if (pAVar2 == (ASN1_STRING *)0x0) {
    return 0;
  }
LAB_0817bcb1:
  pAVar2->flags = pAVar2->flags | 0x10;
  *boundary = &pAVar2->data;
  return 1;
}

