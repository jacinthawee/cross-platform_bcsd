
int asn1_ex_c2i(ASN1_VALUE **pval,uchar *cont,int len,int utype,char *free_cont,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_INTEGER *pAVar3;
  ASN1_TYPE *pAVar4;
  ASN1_TYPE *a;
  code *pcVar5;
  _union_257 *a_00;
  ASN1_STRING *str;
  byte *local_24 [2];
  
  local_24[0] = cont;
  if ((it->funcs != (void *)0x0) &&
     (pcVar5 = *(code **)((int)it->funcs + 0x14), pcVar5 != (code *)0x0)) {
    iVar1 = (*pcVar5)();
    return iVar1;
  }
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
    if (a->type != utype) {
      ASN1_TYPE_set(a,utype,(void *)0x0);
    }
    a_00 = &a->value;
    pAVar4 = (ASN1_TYPE *)pval;
  }
  else {
    a = (ASN1_TYPE *)0x0;
    pAVar4 = a;
    a_00 = (_union_257 *)pval;
  }
  switch(utype) {
  case 1:
    if (len == 1) {
      *a_00 = (_union_257)(uint)*local_24[0];
      return 1;
    }
    ERR_put_error(0xd,0xcc,0x6a,"tasn_dec.c",0x37b);
    break;
  case 2:
  case 10:
    pAVar3 = c2i_ASN1_INTEGER(&a_00->integer,local_24,len);
    if (pAVar3 != (ASN1_INTEGER *)0x0) {
      a_00->asn1_string->type = a_00->asn1_string->type & 0x100U | utype;
      goto LAB_000bac6e;
    }
    break;
  case 3:
    pAVar2 = (ASN1_OBJECT *)c2i_ASN1_BIT_STRING(&a_00->bit_string,local_24,len);
    goto joined_r0x000bac58;
  default:
    if (utype == 0x1e) {
      if ((len & 1U) != 0) {
        ERR_put_error(0xd,0xcc,0xd6,"tasn_dec.c",0x3a5);
        break;
      }
    }
    else if ((utype == 0x1c) && ((len & 3U) != 0)) {
      ERR_put_error(0xd,0xcc,0xd7,"tasn_dec.c",0x3aa);
      break;
    }
    str = a_00->asn1_string;
    if (str == (ASN1_STRING *)0x0) {
      str = ASN1_STRING_type_new(utype);
      if (str == (ASN1_STRING *)0x0) {
        ERR_put_error(0xd,0xcc,0x41,"tasn_dec.c",0x3b1);
        break;
      }
      a_00->asn1_string = str;
    }
    else {
      str->type = utype;
    }
    if (*free_cont == '\0') {
      iVar1 = ASN1_STRING_set(str,local_24[0],len);
      if (iVar1 == 0) {
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
      str->length = len;
      str->data = local_24[0];
      *free_cont = '\0';
    }
LAB_000bac6e:
    pAVar4 = a;
    if (a != (ASN1_TYPE *)0x0) {
      pAVar4 = (ASN1_TYPE *)0x1;
    }
    if (utype != 5) {
      pAVar4 = (ASN1_TYPE *)0x0;
    }
    if (pAVar4 == (ASN1_TYPE *)0x0) {
      return 1;
    }
    (a->value).ptr = (char *)0x0;
    return 1;
  case 5:
    if (len == 0) {
      a_00->boolean = 1;
      goto LAB_000bac6e;
    }
    ERR_put_error(0xd,0xcc,0x90,"tasn_dec.c",0x373);
    break;
  case 6:
    pAVar2 = c2i_ASN1_OBJECT(&a_00->object,local_24,len);
joined_r0x000bac58:
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      return 1;
    }
  }
  ASN1_TYPE_free(a);
  if (pAVar4 == (ASN1_TYPE *)0x0) {
    return 0;
  }
  pAVar4->type = 0;
  return 0;
}

