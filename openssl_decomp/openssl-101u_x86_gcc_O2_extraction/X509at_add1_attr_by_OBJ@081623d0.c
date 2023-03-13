
stack_st_X509_ATTRIBUTE *
X509at_add1_attr_by_OBJ(stack_st_X509_ATTRIBUTE **x,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  X509_ATTRIBUTE *attr;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  X509_ATTRIBUTE *a;
  _STACK *st;
  _STACK *p_Var3;
  int line;
  
  attr = X509_ATTRIBUTE_new();
  if (attr == (X509_ATTRIBUTE *)0x0) {
    ERR_put_error(0xb,0x89,0x41,"x509_att.c",0xf7);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  if (obj == (ASN1_OBJECT *)0x0) {
LAB_081623f2:
    X509_ATTRIBUTE_free(attr);
    return (stack_st_X509_ATTRIBUTE *)0x0;
  }
  ASN1_OBJECT_free(attr->object);
  pAVar1 = OBJ_dup(obj);
  attr->object = pAVar1;
  iVar2 = X509_ATTRIBUTE_set1_data(attr,type,bytes,len);
  if (iVar2 == 0) goto LAB_081623f2;
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    line = 0x81;
    iVar2 = 0x43;
  }
  else {
    st = (_STACK *)*x;
    if ((st != (_STACK *)0x0) || (st = sk_new_null(), st != (_STACK *)0x0)) {
      a = X509_ATTRIBUTE_dup(attr);
      if (a != (X509_ATTRIBUTE *)0x0) {
        iVar2 = sk_push(st,a);
        if (iVar2 != 0) {
          p_Var3 = st;
          if (*x == (stack_st_X509_ATTRIBUTE *)0x0) {
            *x = (stack_st_X509_ATTRIBUTE *)st;
          }
          goto LAB_0816247c;
        }
        ERR_put_error(0xb,0x87,0x41,"x509_att.c",0x93);
        X509_ATTRIBUTE_free(a);
      }
      p_Var3 = (_STACK *)0x0;
      sk_free(st);
      goto LAB_0816247c;
    }
    line = 0x93;
    iVar2 = 0x41;
  }
  p_Var3 = (_STACK *)0x0;
  ERR_put_error(0xb,0x87,iVar2,"x509_att.c",line);
LAB_0816247c:
  X509_ATTRIBUTE_free(attr);
  return (stack_st_X509_ATTRIBUTE *)p_Var3;
}

