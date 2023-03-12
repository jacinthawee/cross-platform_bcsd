
int X509_REQ_add_extensions(X509_REQ *req,stack_st_X509_EXTENSION *exts)

{
  X509_REQ_INFO *pXVar1;
  ASN1_TYPE *a;
  ASN1_STRING *pAVar2;
  int iVar3;
  X509_ATTRIBUTE *a_00;
  _STACK *p_Var4;
  ASN1_OBJECT *pAVar5;
  
  a = ASN1_TYPE_new();
  if (a != (ASN1_TYPE *)0x0) {
    pAVar2 = ASN1_STRING_new();
    (a->value).asn1_string = pAVar2;
    if (pAVar2 != (ASN1_STRING *)0x0) {
      a->type = 0x10;
      iVar3 = ASN1_item_i2d((ASN1_VALUE *)exts,&pAVar2->data,(ASN1_ITEM *)X509_EXTENSIONS_it);
      pAVar2->length = iVar3;
      a_00 = X509_ATTRIBUTE_new();
      if (a_00 == (X509_ATTRIBUTE *)0x0) goto LAB_0815e7d6;
      p_Var4 = sk_new_null();
      (a_00->value).set = (stack_st_ASN1_TYPE *)p_Var4;
      if ((p_Var4 == (_STACK *)0x0) || (iVar3 = sk_push(p_Var4,a), iVar3 == 0)) goto LAB_0815e7d6;
      a_00->single = 0;
      pAVar5 = OBJ_nid2obj(0xac);
      a_00->object = pAVar5;
      pXVar1 = req->req_info;
      p_Var4 = (_STACK *)pXVar1->attributes;
      if (p_Var4 == (_STACK *)0x0) {
        p_Var4 = sk_new_null();
        pXVar1->attributes = (stack_st_X509_ATTRIBUTE *)p_Var4;
        if (p_Var4 != (_STACK *)0x0) {
          p_Var4 = (_STACK *)req->req_info->attributes;
          goto LAB_0815e826;
        }
      }
      else {
LAB_0815e826:
        iVar3 = sk_push(p_Var4,a_00);
        if (iVar3 != 0) {
          return 1;
        }
      }
      a = (ASN1_TYPE *)0x0;
      goto LAB_0815e7d6;
    }
  }
  a_00 = (X509_ATTRIBUTE *)0x0;
LAB_0815e7d6:
  X509_ATTRIBUTE_free(a_00);
  ASN1_TYPE_free(a);
  return 0;
}

