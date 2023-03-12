
X509_ATTRIBUTE * X509_ATTRIBUTE_create(int nid,int atrtype,void *value)

{
  X509_ATTRIBUTE *val;
  ASN1_OBJECT *pAVar1;
  _STACK *p_Var2;
  ASN1_TYPE *a;
  X509_ATTRIBUTE *pXVar3;
  
  val = (X509_ATTRIBUTE *)ASN1_item_new((ASN1_ITEM *)&X509_ATTRIBUTE_it);
  if (val != (X509_ATTRIBUTE *)0x0) {
    pAVar1 = OBJ_nid2obj(nid);
    val->object = pAVar1;
    val->single = 0;
    p_Var2 = sk_new_null();
    (val->value).set = (stack_st_ASN1_TYPE *)p_Var2;
    if ((p_Var2 == (_STACK *)0x0) || (a = ASN1_TYPE_new(), a == (ASN1_TYPE *)0x0)) {
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&X509_ATTRIBUTE_it);
      return (X509_ATTRIBUTE *)0x0;
    }
    pXVar3 = (X509_ATTRIBUTE *)sk_push((_STACK *)(val->value).set,a);
    if (pXVar3 == (X509_ATTRIBUTE *)0x0) {
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&X509_ATTRIBUTE_it);
      ASN1_TYPE_free(a);
      val = pXVar3;
    }
    else {
      ASN1_TYPE_set(a,atrtype,value);
    }
  }
  return val;
}

