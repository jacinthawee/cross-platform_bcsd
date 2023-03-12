
int X509_ATTRIBUTE_set1_data(X509_ATTRIBUTE *attr,int attrtype,void *data,int len)

{
  ASN1_STRING *str;
  int iVar1;
  _STACK *p_Var2;
  ASN1_TYPE *a;
  ASN1_STRING *pAVar3;
  ASN1_STRING *type;
  
  if (attr == (X509_ATTRIBUTE *)0x0) {
    return 0;
  }
  pAVar3 = (ASN1_STRING *)(attrtype & 0x1000);
  if (pAVar3 == (ASN1_STRING *)0x0) {
    str = pAVar3;
    type = pAVar3;
    if ((len != -1) &&
       ((str = ASN1_STRING_type_new(attrtype), str == (ASN1_STRING *)0x0 ||
        (iVar1 = ASN1_STRING_set(str,data,len), type = (ASN1_STRING *)attrtype, iVar1 == 0))))
    goto LAB_000cabee;
  }
  else {
    iVar1 = OBJ_obj2nid(attr->object);
    str = ASN1_STRING_set_by_NID((ASN1_STRING **)0x0,(uchar *)data,len,attrtype,iVar1);
    if (str == (ASN1_STRING *)0x0) {
      ERR_put_error(0xb,0x8a,0xd,"x509_att.c",0x134);
      return 0;
    }
    type = (ASN1_STRING *)str->type;
  }
  p_Var2 = sk_new_null();
  (attr->value).set = (stack_st_ASN1_TYPE *)p_Var2;
  if (p_Var2 != (_STACK *)0x0) {
    attr->single = 0;
    if (attrtype == 0) {
      return 1;
    }
    a = ASN1_TYPE_new();
    if (a != (ASN1_TYPE *)0x0) {
      if ((len == -1) && (pAVar3 == (ASN1_STRING *)0x0)) {
        iVar1 = ASN1_TYPE_set1(a,attrtype,data);
        if (iVar1 == 0) goto LAB_000cabee;
      }
      else {
        ASN1_TYPE_set(a,(int)type,str);
      }
      iVar1 = sk_push((_STACK *)(attr->value).set,a);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
LAB_000cabee:
  ERR_put_error(0xb,0x8a,0x41,"x509_att.c",0x154);
  return 0;
}

