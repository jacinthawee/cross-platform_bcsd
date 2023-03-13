
ASN1_TYPE * X509_ATTRIBUTE_get0_type(X509_ATTRIBUTE *attr,int idx)

{
  int iVar1;
  ASN1_TYPE *pAVar2;
  
  if (attr == (X509_ATTRIBUTE *)0x0) {
    return (ASN1_TYPE *)0x0;
  }
  if (attr->single == 0) {
    iVar1 = sk_num((_STACK *)(attr->value).set);
    if (iVar1 <= idx) {
      return (ASN1_TYPE *)0x0;
    }
    if (attr->single == 0) {
      pAVar2 = (ASN1_TYPE *)sk_value((_STACK *)(attr->value).set,idx);
      return pAVar2;
    }
    pAVar2 = (ASN1_TYPE *)(attr->value).ptr;
  }
  else {
    pAVar2 = (ASN1_TYPE *)(attr->value).ptr;
    if ((int)(uint)(pAVar2 != (ASN1_TYPE *)0x0) <= idx) {
      return (ASN1_TYPE *)0x0;
    }
  }
  return pAVar2;
}

