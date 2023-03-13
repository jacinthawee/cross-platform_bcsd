
int X509_ATTRIBUTE_set1_data(X509_ATTRIBUTE *attr,int attrtype,void *data,int len)

{
  ASN1_STRING *str;
  int iVar1;
  _STACK *p_Var2;
  ASN1_TYPE *a;
  int iVar3;
  
  if (attr == (X509_ATTRIBUTE *)0x0) {
    return 0;
  }
  if ((attrtype & 0x1000U) == 0) {
    if (len == -1) {
      iVar3 = 0;
      str = (ASN1_STRING *)0x0;
      goto LAB_081621dc;
    }
    str = ASN1_STRING_type_new(attrtype);
    if ((str != (ASN1_STRING *)0x0) &&
       (iVar1 = ASN1_STRING_set(str,data,len), iVar3 = attrtype, iVar1 != 0)) goto LAB_081621dc;
  }
  else {
    iVar3 = OBJ_obj2nid(attr->object);
    str = ASN1_STRING_set_by_NID((ASN1_STRING **)0x0,(uchar *)data,len,attrtype,iVar3);
    if (str == (ASN1_STRING *)0x0) {
      iVar1 = 0x134;
      iVar3 = 0xd;
      goto LAB_081621ba;
    }
    iVar3 = str->type;
LAB_081621dc:
    p_Var2 = sk_new_null();
    (attr->value).set = (stack_st_ASN1_TYPE *)p_Var2;
    if (p_Var2 != (_STACK *)0x0) {
      attr->single = 0;
      if (attrtype == 0) {
        return 1;
      }
      a = ASN1_TYPE_new();
      if (a != (ASN1_TYPE *)0x0) {
        if (((attrtype & 0x1000U) == 0) && (len == -1)) {
          iVar3 = ASN1_TYPE_set1(a,attrtype,data);
          if (iVar3 == 0) goto LAB_081621ab;
        }
        else {
          ASN1_TYPE_set(a,iVar3,str);
        }
        iVar3 = sk_push((_STACK *)(attr->value).set,a);
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
  }
LAB_081621ab:
  iVar1 = 0x154;
  iVar3 = 0x41;
LAB_081621ba:
  ERR_put_error(0xb,0x8a,iVar3,"x509_att.c",iVar1);
  return 0;
}

