
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
  if (utype == 5) {
    if (len == 0) {
      a->boolean = 1;
      if (a_00 == (ASN1_TYPE *)0x0) {
        return 1;
      }
      goto LAB_00562afc;
    }
    uVar4 = 0x90;
    uVar3 = 0x3c1;
  }
  else if (utype < 6) {
    if (utype == 2) {
LAB_00562ab4:
      pAVar2 = c2i_ASN1_INTEGER(&a->integer,local_res4,len);
      if (pAVar2 == (ASN1_INTEGER *)0x0) goto LAB_005629d4;
      a->asn1_string->type = a->asn1_string->type & 0x100U | utype;
LAB_00562980:
      if (a_00 == (ASN1_TYPE *)0x0) {
        return 1;
      }
      if (utype != 5) {
        return 1;
      }
LAB_00562afc:
      (a_00->value).ptr = (char *)0x0;
      return 1;
    }
    pcVar5 = (code *)PTR_c2i_ASN1_BIT_STRING_006a9eb8;
    if (utype == 3) {
LAB_005629c0:
      iVar1 = (*pcVar5)(a,local_res4,len);
      if (iVar1 != 0) {
        return 1;
      }
      goto LAB_005629d4;
    }
    if (utype != 1) goto LAB_00562928;
    if (len == 1) {
      *a = (_union_257)(uint)*local_res4[0];
      return 1;
    }
    uVar4 = 0x6a;
    uVar3 = 0x3cb;
  }
  else {
    if (utype == 10) goto LAB_00562ab4;
    if (utype < 0xb) {
      pcVar5 = (code *)PTR_c2i_ASN1_OBJECT_006a9ebc;
      if (utype == 6) goto LAB_005629c0;
    }
    else if ((utype == 0x102) || (utype == 0x10a)) goto LAB_00562ab4;
LAB_00562928:
    if (utype == 0x1e) {
      if ((len & 1U) == 0) goto LAB_00562938;
      uVar4 = 0xd6;
      uVar3 = 0x3fb;
    }
    else {
      if ((utype != 0x1c) || ((len & 3U) == 0)) {
LAB_00562938:
        str = a->asn1_string;
        if (str == (ASN1_INTEGER *)0x0) {
          str = ASN1_STRING_type_new(utype);
          if (str == (ASN1_STRING *)0x0) {
            uVar4 = 0x41;
            uVar3 = 0x40b;
            goto LAB_00562a88;
          }
          a->asn1_string = str;
        }
        else {
          str->type = utype;
        }
        if (*free_cont == '\0') {
          iVar1 = ASN1_STRING_set(str,local_res4[0],len);
          if (iVar1 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xcc,0x41,s_tasn_dec_c_0066ab0c,0x423);
            ASN1_STRING_free(str);
            a->ptr = (char *)0x0;
            goto LAB_005629d4;
          }
        }
        else {
          if (str->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          str->length = len;
          str->data = local_res4[0];
          *free_cont = '\0';
        }
        goto LAB_00562980;
      }
      uVar4 = 0xd7;
      uVar3 = 0x401;
    }
  }
LAB_00562a88:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xcc,uVar4,s_tasn_dec_c_0066ab0c,uVar3);
LAB_005629d4:
  ASN1_TYPE_free(a_00);
  if (pval == (ASN1_VALUE **)0x0) {
    return 0;
  }
  *pval = (ASN1_VALUE *)0x0;
  return 0;
}

