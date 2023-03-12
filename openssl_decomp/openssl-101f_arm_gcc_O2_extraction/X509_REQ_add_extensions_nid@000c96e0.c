
int X509_REQ_add_extensions_nid(X509_REQ *req,stack_st_X509_EXTENSION *exts,int nid)

{
  _STACK *p_Var1;
  _STACK *a;
  int iVar2;
  _STACK *st;
  ASN1_OBJECT *pAVar3;
  X509_REQ_INFO *pXVar4;
  
  p_Var1 = (_STACK *)ASN1_TYPE_new();
  a = p_Var1;
  if (p_Var1 != (_STACK *)0x0) {
    a = (_STACK *)ASN1_STRING_new();
    ((_union_257 *)&p_Var1->data)->asn1_string = (ASN1_STRING *)a;
    if (a != (_STACK *)0x0) {
      p_Var1->num = 0x10;
      iVar2 = ASN1_item_i2d((ASN1_VALUE *)exts,(uchar **)&a->sorted,(ASN1_ITEM *)X509_EXTENSIONS_it)
      ;
      a->num = iVar2;
      a = (_STACK *)X509_ATTRIBUTE_new();
      if (a != (_STACK *)0x0) {
        st = sk_new_null();
        a->sorted = (int)st;
        if ((st != (_STACK *)0x0) && (iVar2 = sk_push(st,p_Var1), iVar2 != 0)) {
          a->data = (char **)0x0;
          pAVar3 = OBJ_nid2obj(nid);
          pXVar4 = req->req_info;
          p_Var1 = (_STACK *)pXVar4->attributes;
          a->num = (int)pAVar3;
          if (p_Var1 == (_STACK *)0x0) {
            p_Var1 = sk_new_null();
            pXVar4->attributes = (stack_st_X509_ATTRIBUTE *)p_Var1;
            if (p_Var1 == (_STACK *)0x0) goto LAB_000c972c;
            p_Var1 = (_STACK *)req->req_info->attributes;
          }
          p_Var1 = (_STACK *)sk_push(p_Var1,a);
          if (p_Var1 != (_STACK *)0x0) {
            return 1;
          }
        }
      }
    }
  }
LAB_000c972c:
  X509_ATTRIBUTE_free((X509_ATTRIBUTE *)a);
  ASN1_TYPE_free((ASN1_TYPE *)p_Var1);
  return 0;
}

