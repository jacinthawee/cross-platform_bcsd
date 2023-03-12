
int X509_ALGOR_cmp(X509_ALGOR *a,X509_ALGOR *b)

{
  ASN1_TYPE *b_00;
  int iVar1;
  
  b_00 = (ASN1_TYPE *)OBJ_cmp(a->algorithm,b->algorithm);
  if (b_00 == (ASN1_TYPE *)0x0) {
    b_00 = b->parameter;
    if ((a->parameter != (ASN1_TYPE *)0x0) || (b_00 != (ASN1_TYPE *)0x0)) {
      iVar1 = ASN1_TYPE_cmp(a->parameter,b_00);
      return iVar1;
    }
  }
  return (int)b_00;
}

