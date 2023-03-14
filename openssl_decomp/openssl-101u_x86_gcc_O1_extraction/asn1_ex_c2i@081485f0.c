
int asn1_ex_c2i(ASN1_VALUE **pval,uchar *cont,int len,int utype,char *free_cont,ASN1_ITEM *it)

{
  code *pcVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  ASN1_INTEGER *pAVar4;
  int iVar5;
  ASN1_STRING *str;
  ASN1_TYPE *a;
  _union_257 *a_00;
  ASN1_VALUE **ppAVar6;
  
  iVar2 = utype;
  if ((it->funcs != (void *)0x0) &&
     (pcVar1 = *(code **)((int)it->funcs + 0x14), pcVar1 != (code *)0x0)) {
    iVar2 = (*pcVar1)(pval,cont,len,utype,free_cont,it);
    return iVar2;
  }
  a = (ASN1_TYPE *)0x0;
  a_00 = (_union_257 *)pval;
  ppAVar6 = (ASN1_VALUE **)0x0;
  if (it->utype == -4) {
    a = (ASN1_TYPE *)*pval;
    if (a == (ASN1_TYPE *)0x0) {
      a = ASN1_TYPE_new();
      if (a == (ASN1_TYPE *)0x0) {
        ASN1_TYPE_free((ASN1_TYPE *)0x0);
        return 0;
      }
      *pval = (ASN1_VALUE *)a;
    }
    if (iVar2 != a->type) {
      ASN1_TYPE_set(a,iVar2,(void *)0x0);
    }
    a_00 = &a->value;
    ppAVar6 = pval;
  }
  switch(iVar2) {
  default:
    if (iVar2 == 0x1e) {
      if ((len & 1U) != 0) {
        ERR_put_error(0xd,0xcc,0xd6,"tasn_dec.c",0x3a5);
        break;
      }
    }
    else if ((iVar2 == 0x1c) && ((len & 3U) != 0)) {
      ERR_put_error(0xd,0xcc,0xd7,"tasn_dec.c",0x3aa);
      break;
    }
    str = a_00->asn1_string;
    if (str == (ASN1_STRING *)0x0) {
      str = ASN1_STRING_type_new(iVar2);
      if (str == (ASN1_STRING *)0x0) {
        ERR_put_error(0xd,0xcc,0x41,"tasn_dec.c",0x3b1);
        break;
      }
      a_00->asn1_string = str;
    }
    else {
      str->type = iVar2;
    }
    if (*free_cont == '\0') {
      iVar5 = ASN1_STRING_set(str,cont,len);
      if (iVar5 == 0) {
        ERR_put_error(0xd,0xcc,0x41,"tasn_dec.c",0x3c2);
        ASN1_STRING_free(str);
        a_00->ptr = (char *)0x0;
        break;
      }
    }
    else {
      if (str->data != (uchar *)0x0) {
        CRYPTO_free(str->data);
      }
      str->data = cont;
      str->length = len;
      *free_cont = '\0';
    }
LAB_08148692:
    if (a == (ASN1_TYPE *)0x0) {
      return 1;
    }
    if (iVar2 == 5) {
      (a->value).ptr = (char *)0x0;
      return 1;
    }
    return 1;
  case 1:
    if (len == 1) {
      *a_00 = (_union_257)(uint)*cont;
      return 1;
    }
    ERR_put_error(0xd,0xcc,0x6a,"tasn_dec.c",0x37b);
    break;
  case 2:
  case 10:
    pAVar4 = c2i_ASN1_INTEGER(&a_00->integer,&cont,len);
    if (pAVar4 != (ASN1_INTEGER *)0x0) {
      a_00->asn1_string->type = a_00->asn1_string->type & 0x100U | iVar2;
      goto LAB_08148692;
    }
    break;
  case 3:
    pAVar3 = (ASN1_OBJECT *)c2i_ASN1_BIT_STRING(&a_00->bit_string,&cont,len);
    goto joined_r0x08148667;
  case 5:
    if (len == 0) {
      a_00->boolean = 1;
      goto LAB_08148692;
    }
    ERR_put_error(0xd,0xcc,0x90,"tasn_dec.c",0x373);
    break;
  case 6:
    pAVar3 = c2i_ASN1_OBJECT(&a_00->object,&cont,len);
joined_r0x08148667:
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      return 1;
    }
  }
  ASN1_TYPE_free(a);
  if (ppAVar6 == (ASN1_VALUE **)0x0) {
    return 0;
  }
  *ppAVar6 = (ASN1_VALUE *)0x0;
  return 0;
}
