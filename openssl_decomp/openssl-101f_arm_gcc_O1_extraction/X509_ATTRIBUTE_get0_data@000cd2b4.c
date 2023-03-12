
void * X509_ATTRIBUTE_get0_data(X509_ATTRIBUTE *attr,int idx,int atrtype,void *data)

{
  _STACK *p_Var1;
  int iVar2;
  ASN1_TYPE *a;
  
  if (attr != (X509_ATTRIBUTE *)0x0) {
    p_Var1 = (_STACK *)(attr->value).set;
    if (attr->single == 0) {
      p_Var1 = (_STACK *)sk_num(p_Var1);
    }
    else if (p_Var1 != (_STACK *)0x0) {
      p_Var1 = (_STACK *)0x1;
    }
    if (idx < (int)p_Var1) {
      if (attr->single == 0) {
        a = (ASN1_TYPE *)sk_value((_STACK *)(attr->value).set,idx);
      }
      else {
        a = (attr->value).single;
      }
      if (a != (ASN1_TYPE *)0x0) {
        iVar2 = ASN1_TYPE_get(a);
        if (iVar2 == atrtype) {
          a = (ASN1_TYPE *)(a->value).ptr;
        }
        else {
          ERR_put_error(0xb,0x8b,0x7a,"x509_att.c",0x15b);
          a = (ASN1_TYPE *)0x0;
        }
      }
      return a;
    }
  }
  return (void *)0x0;
}

