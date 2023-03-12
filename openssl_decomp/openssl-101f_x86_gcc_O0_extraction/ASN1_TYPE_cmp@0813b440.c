
int ASN1_TYPE_cmp(ASN1_TYPE *a,ASN1_TYPE *b)

{
  int iVar1;
  
  if (((a == (ASN1_TYPE *)0x0) || (b == (ASN1_TYPE *)0x0)) || (iVar1 = a->type, iVar1 != b->type)) {
    return -1;
  }
  if (iVar1 == 5) {
    return 0;
  }
  if (iVar1 == 6) {
    iVar1 = OBJ_cmp((ASN1_OBJECT *)(a->value).asn1_string,(ASN1_OBJECT *)(b->value).asn1_string);
    return iVar1;
  }
  iVar1 = ASN1_STRING_cmp((ASN1_STRING *)(ASN1_OBJECT *)(a->value).asn1_string,
                          (ASN1_STRING *)(ASN1_OBJECT *)(b->value).asn1_string);
  return iVar1;
}

