
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_txt(stack_st_X509_ATTRIBUTE **x,char *attrname,int type,uchar *bytes,int len)

{
  ASN1_OBJECT *a;
  X509_ATTRIBUTE *attr;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *a_00;
  _STACK *st;
  
  a = OBJ_txt2obj(attrname,0);
  if (a == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xb,0x8c,0x77,"x509_att.c",0x116);
    ERR_add_error_data(2,"name=",attrname);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  attr = X509_ATTRIBUTE_new();
  if (attr == (X509_ATTRIBUTE *)0x0) {
    attr = (X509_ATTRIBUTE *)X509_ATTRIBUTE_create_by_OBJ_part_0();
    ASN1_OBJECT_free(a);
    if (attr == (X509_ATTRIBUTE *)0x0) {
      return (stack_st_X509_ATTRIBUTE *)0x0;
    }
  }
  else {
    ASN1_OBJECT_free(attr->object);
    pAVar1 = OBJ_dup(a);
    attr->object = pAVar1;
    iVar2 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
    if (iVar2 == 0) {
      X509_ATTRIBUTE_free(attr);
      ASN1_OBJECT_free(a);
      return (stack_st_X509_ATTRIBUTE *)0x0;
    }
    ASN1_OBJECT_free(a);
  }
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    ERR_put_error(0xb,0x87,0x43,"x509_att.c",0x81);
LAB_000cafae:
    st = (_STACK *)0x0;
  }
  else {
    st = (_STACK *)*x;
    if ((st == (_STACK *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) {
      ERR_put_error(0xb,0x87,0x41,"x509_att.c",0x93);
      goto LAB_000caf9e;
    }
    a_00 = X509_ATTRIBUTE_dup(attr);
    if (a_00 == (X509_ATTRIBUTE *)0x0) {
      if (st == (_STACK *)0x0) goto LAB_000cafae;
    }
    else {
      iVar2 = sk_push(st,a_00);
      if (iVar2 != 0) {
        if (*x == (stack_st_X509_ATTRIBUTE *)0x0) {
          *x = (stack_st_X509_ATTRIBUTE *)st;
        }
        goto LAB_000caf9e;
      }
      ERR_put_error(0xb,0x87,0x41,"x509_att.c",0x93);
      X509_ATTRIBUTE_free(a_00);
    }
    sk_free(st);
    st = (_STACK *)0x0;
  }
LAB_000caf9e:
  X509_ATTRIBUTE_free(attr);
  return (stack_st_X509_ATTRIBUTE *)st;
}

