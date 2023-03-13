
int asn1_ex_c2i(ASN1_VALUE **pval,uchar *cont,int len,int utype,char *free_cont,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_INTEGER *pAVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  _union_257 *a;
  ASN1_TYPE *a_00;
  ASN1_STRING *str;
  code *pcVar5;
  byte *local_res4 [3];
  
  local_res4[0] = cont;
  if ((it->funcs != (void *)0x0) &&
     (pcVar5 = *(code **)((int)it->funcs + 0x14), pcVar5 != (code *)0x0)) {
    iVar1 = (*pcVar5)();
    return iVar1;
  }
  a_00 = (ASN1_TYPE *)0x0;
  if (it->utype == -4) {
    a_00 = (ASN1_TYPE *)*pval;
    if (a_00 == (ASN1_TYPE *)0x0) {
      a_00 = ASN1_TYPE_new();
      if (a_00 == (ASN1_TYPE *)0x0) {
        ASN1_TYPE_free((ASN1_TYPE *)0x0);
        return 0;
      }
      *pval = (ASN1_VALUE *)a_00;
    }
    if (utype != a_00->type) {
      ASN1_TYPE_set(a_00,utype,(void *)0x0);
    }
    a = &a_00->value;
  }
  else {
    a = (_union_257 *)pval;
    pval = (ASN1_VALUE **)0x0;
  }
  switch(utype) {
  default:
    if (utype == 0x1e) {
      if ((len & 1U) == 0) goto LAB_0055ebe4;
      uVar4 = 0xd6;
      uVar3 = 0x3a5;
    }
    else {
      if ((utype != 0x1c) || ((len & 3U) == 0)) {
LAB_0055ebe4:
        str = a->asn1_string;
        if (str == (ASN1_INTEGER *)0x0) {
          str = ASN1_STRING_type_new(utype);
          if (str == (ASN1_STRING *)0x0) {
            uVar4 = 0x41;
            uVar3 = 0x3b1;
            break;
          }
          a->asn1_string = str;
        }
        else {
          str->type = utype;
        }
        if (*free_cont == '\0') {
          iVar1 = ASN1_STRING_set(str,local_res4[0],len);
          if (iVar1 == 0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xcc,0x41,s_tasn_dec_c_0066a0bc,0x3c2);
            ASN1_STRING_free(str);
            a->ptr = (char *)0x0;
            goto LAB_0055eb90;
          }
        }
        else {
          if (str->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          str->length = len;
          str->data = local_res4[0];
          *free_cont = '\0';
        }
        goto LAB_0055eb48;
      }
      uVar4 = 0xd7;
      uVar3 = 0x3aa;
    }
    break;
  case 1:
    if (len == 1) {
      *a = (_union_257)(uint)*local_res4[0];
      return 1;
    }
    uVar4 = 0x6a;
    uVar3 = 0x37b;
    break;
  case 2:
  case 10:
    pAVar2 = c2i_ASN1_INTEGER(&a->integer,local_res4,len);
    if (pAVar2 == (ASN1_INTEGER *)0x0) goto LAB_0055eb90;
    a->asn1_string->type = a->asn1_string->type & 0x100U | utype;
LAB_0055eb48:
    if (a_00 == (ASN1_TYPE *)0x0) {
      return 1;
    }
    if (utype != 5) {
      return 1;
    }
LAB_0055eb04:
    (a_00->value).ptr = (char *)0x0;
    return 1;
  case 3:
    pcVar5 = (code *)PTR_c2i_ASN1_BIT_STRING_006a8d9c;
    goto LAB_0055eab0;
  case 5:
    if (len == 0) {
      a->boolean = 1;
      if (a_00 == (ASN1_TYPE *)0x0) {
        return 1;
      }
      goto LAB_0055eb04;
    }
    uVar4 = 0x90;
    uVar3 = 0x373;
    break;
  case 6:
    pcVar5 = (code *)PTR_c2i_ASN1_OBJECT_006a8d98;
LAB_0055eab0:
    iVar1 = (*pcVar5)(a,local_res4,len);
    if (iVar1 != 0) {
      return 1;
    }
    goto LAB_0055eb90;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xcc,uVar4,s_tasn_dec_c_0066a0bc,uVar3);
LAB_0055eb90:
  ASN1_TYPE_free(a_00);
  if (pval == (ASN1_VALUE **)0x0) {
    return 0;
  }
  *pval = (ASN1_VALUE *)0x0;
  return 0;
}

