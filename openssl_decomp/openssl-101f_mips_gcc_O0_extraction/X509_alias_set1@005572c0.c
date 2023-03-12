
int X509_alias_set1(X509 *x,uchar *name,int len)

{
  int iVar1;
  ASN1_UTF8STRING *pAVar2;
  ASN1_VALUE *pAVar3;
  
  if (name == (uchar *)0x0) {
    if (((x == (X509 *)0x0) || (*(int *)(x->sha1_hash + 0xc) == 0)) ||
       (pAVar2 = *(ASN1_UTF8STRING **)(*(int *)(x->sha1_hash + 0xc) + 8),
       pAVar2 == (ASN1_UTF8STRING *)0x0)) {
      return 1;
    }
    ASN1_UTF8STRING_free(pAVar2);
    iVar1 = 1;
    *(undefined4 *)(*(int *)(x->sha1_hash + 0xc) + 8) = 0;
  }
  else {
    iVar1 = 0;
    if (x != (X509 *)0x0) {
      pAVar3 = *(ASN1_VALUE **)(x->sha1_hash + 0xc);
      if (pAVar3 == (ASN1_VALUE *)0x0) {
        pAVar3 = ASN1_item_new((ASN1_ITEM *)X509_CERT_AUX_it);
        *(ASN1_VALUE **)(x->sha1_hash + 0xc) = pAVar3;
        if (pAVar3 == (ASN1_VALUE *)0x0) {
          return 0;
        }
      }
      pAVar2 = *(ASN1_UTF8STRING **)(pAVar3 + 8);
      if (pAVar2 == (ASN1_STRING *)0x0) {
        pAVar2 = ASN1_UTF8STRING_new();
        *(ASN1_UTF8STRING **)(pAVar3 + 8) = pAVar2;
        if (pAVar2 == (ASN1_UTF8STRING *)0x0) {
          return 0;
        }
      }
      iVar1 = ASN1_STRING_set(pAVar2,name,len);
      return iVar1;
    }
  }
  return iVar1;
}

