
ASN1_INTEGER * ASN1_INTEGER_dup(ASN1_INTEGER *x)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_dup(x);
  return pAVar1;
}

