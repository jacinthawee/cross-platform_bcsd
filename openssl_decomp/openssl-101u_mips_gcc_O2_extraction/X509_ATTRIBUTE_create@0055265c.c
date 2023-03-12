
X509_ATTRIBUTE * X509_ATTRIBUTE_create(int nid,int atrtype,void *value)

{
  undefined *puVar1;
  X509_ATTRIBUTE *val;
  ASN1_OBJECT *pAVar2;
  char *pcVar3;
  ASN1_TYPE *a;
  int iVar4;
  X509_ATTRIBUTE *pXVar5;
  
  val = (X509_ATTRIBUTE *)ASN1_item_new((ASN1_ITEM *)X509_ATTRIBUTE_it);
  pXVar5 = val;
  if (val != (X509_ATTRIBUTE *)0x0) {
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(nid);
    val->object = pAVar2;
    puVar1 = PTR_sk_new_null_006a6fa4;
    val->single = 0;
    pcVar3 = (char *)(*(code *)puVar1)();
    (val->value).ptr = pcVar3;
    if ((pcVar3 == (char *)0x0) || (a = ASN1_TYPE_new(), a == (ASN1_TYPE *)0x0)) {
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_ATTRIBUTE_it);
      return (X509_ATTRIBUTE *)0x0;
    }
    iVar4 = (*(code *)PTR_sk_push_006a6fa8)((val->value).ptr,a);
    if (iVar4 == 0) {
      pXVar5 = (X509_ATTRIBUTE *)0x0;
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_ATTRIBUTE_it);
      ASN1_TYPE_free(a);
    }
    else {
      ASN1_TYPE_set(a,atrtype,value);
    }
  }
  return pXVar5;
}

