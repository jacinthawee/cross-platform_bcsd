
void * X509_ATTRIBUTE_get0_data(X509_ATTRIBUTE *attr,int idx,int atrtype,void *data)

{
  int iVar1;
  ASN1_TYPE *a;
  char *pcVar2;
  
  if (attr != (X509_ATTRIBUTE *)0x0) {
    if (attr->single == 0) {
      iVar1 = sk_num((_STACK *)(attr->value).set);
      if (iVar1 <= idx) {
        return (void *)0x0;
      }
      if (attr->single == 0) {
        a = (ASN1_TYPE *)sk_value((_STACK *)(attr->value).set,idx);
      }
      else {
        a = (attr->value).single;
      }
    }
    else {
      a = (attr->value).single;
      if ((int)(uint)(a != (ASN1_TYPE *)0x0) <= idx) {
        return (void *)0x0;
      }
    }
    if (a != (ASN1_TYPE *)0x0) {
      iVar1 = ASN1_TYPE_get(a);
      if (iVar1 == atrtype) {
        pcVar2 = (a->value).ptr;
      }
      else {
        ERR_put_error(0xb,0x8b,0x7a,"x509_att.c",0x170);
        pcVar2 = (char *)0x0;
      }
      return pcVar2;
    }
  }
  return (void *)0x0;
}

