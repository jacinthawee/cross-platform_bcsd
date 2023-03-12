
int X509_alias_set1(X509 *x,uchar *name,int len)

{
  ASN1_UTF8STRING *a;
  int iVar1;
  ASN1_STRING *str;
  ASN1_VALUE *pAVar2;
  
  if (name == (uchar *)0x0) {
    if ((x == (X509 *)0x0) || (*(int *)(x->sha1_hash + 0xc) == 0)) {
      iVar1 = 1;
    }
    else {
      a = *(ASN1_UTF8STRING **)(*(int *)(x->sha1_hash + 0xc) + 8);
      iVar1 = 1;
      if (a != (ASN1_UTF8STRING *)0x0) {
        ASN1_UTF8STRING_free(a);
        *(undefined4 *)(*(int *)(x->sha1_hash + 0xc) + 8) = 0;
      }
    }
  }
  else {
    if (x != (X509 *)0x0) {
      pAVar2 = *(ASN1_VALUE **)(x->sha1_hash + 0xc);
      if (pAVar2 == (ASN1_VALUE *)0x0) {
        pAVar2 = ASN1_item_new((ASN1_ITEM *)X509_CERT_AUX_it);
        *(ASN1_VALUE **)(x->sha1_hash + 0xc) = pAVar2;
        if (pAVar2 == (ASN1_VALUE *)0x0) {
          return 0;
        }
      }
      str = *(ASN1_STRING **)(pAVar2 + 8);
      if (str != (ASN1_STRING *)0x0) {
LAB_08142029:
        iVar1 = ASN1_STRING_set(str,name,len);
        return iVar1;
      }
      str = ASN1_UTF8STRING_new();
      *(ASN1_STRING **)(pAVar2 + 8) = str;
      if (str != (ASN1_UTF8STRING *)0x0) goto LAB_08142029;
    }
    iVar1 = 0;
  }
  return iVar1;
}
