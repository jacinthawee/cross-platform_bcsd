
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
                    /* WARNING: Could not recover jumptable at 0x0054f048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_OBJ_cmp_006a9de4)();
    return iVar1;
  }
  iVar1 = ASN1_STRING_cmp((a->value).asn1_string,(b->value).asn1_string);
  return iVar1;
}

