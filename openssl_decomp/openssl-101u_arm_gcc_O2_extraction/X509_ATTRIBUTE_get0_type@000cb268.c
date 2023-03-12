
ASN1_TYPE * X509_ATTRIBUTE_get0_type(X509_ATTRIBUTE *attr,int idx)

{
  _STACK *p_Var1;
  ASN1_TYPE *pAVar2;
  
  if (attr != (X509_ATTRIBUTE *)0x0) {
    p_Var1 = (_STACK *)(attr->value).set;
    if (attr->single == 0) {
      p_Var1 = (_STACK *)sk_num(p_Var1);
    }
    else if (p_Var1 != (_STACK *)0x0) {
      p_Var1 = (_STACK *)0x1;
    }
    if (idx < (int)p_Var1) {
      if (attr->single != 0) {
        return (ASN1_TYPE *)(_STACK *)(attr->value).set;
      }
      pAVar2 = (ASN1_TYPE *)sk_value((_STACK *)(attr->value).set,idx);
      return pAVar2;
    }
  }
  return (ASN1_TYPE *)0x0;
}

