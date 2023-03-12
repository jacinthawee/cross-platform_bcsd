
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_NID(stack_st_X509_ATTRIBUTE **x,int nid,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *o;
  X509_ATTRIBUTE *attr;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *a;
  _STACK *st;
  
  o = OBJ_nid2obj(nid);
  if (o == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x88,0x6d,"x509_att.c",0xe4);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  attr = X509_ATTRIBUTE_new();
  if (attr == (X509_ATTRIBUTE *)0x0) {
    attr = (X509_ATTRIBUTE *)X509_ATTRIBUTE_create_by_OBJ_part_0();
    if (attr == (X509_ATTRIBUTE *)0x0) goto LAB_000cae96;
  }
  else {
    ASN1_OBJECT_free(attr->object);
    pAVar1 = OBJ_dup(o);
    attr->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
    if (iVar2 == 0) {
      X509_ATTRIBUTE_free(attr);
LAB_000cae96:
      ASN1_OBJECT_free(o);
      return (stack_st_X509_ATTRIBUTE *)0x0;
    }
  }
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    ERR_put_error(0xb,0x87,0x43,"x509_att.c",0x81);
  }
  else {
    st = (_STACK *)*x;
    if ((st == (_STACK *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) {
      ERR_put_error(0xb,0x87,0x41,"x509_att.c",0x93);
      goto LAB_000caea4;
    }
    a = X509_ATTRIBUTE_dup(attr);
    if (a != (X509_ATTRIBUTE *)0x0) {
      iVar2 = sk_push(st,a);
      if (iVar2 != 0) {
        if (*x == (stack_st_X509_ATTRIBUTE *)0x0) {
          *x = (stack_st_X509_ATTRIBUTE *)st;
        }
        goto LAB_000caea4;
      }
      ERR_put_error(0xb,0x87,0x41,"x509_att.c",0x93);
      X509_ATTRIBUTE_free(a);
LAB_000cae7a:
      sk_free(st);
      X509_ATTRIBUTE_free(attr);
      return (stack_st_X509_ATTRIBUTE *)0x0;
    }
    if (st != (_STACK *)0x0) goto LAB_000cae7a;
  }
  st = (_STACK *)0x0;
LAB_000caea4:
  X509_ATTRIBUTE_free(attr);
  return (stack_st_X509_ATTRIBUTE *)st;
}

