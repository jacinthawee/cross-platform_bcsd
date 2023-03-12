
int X509_keyid_set1(X509 *x,uchar *id,int len)

{
  int iVar1;
  ASN1_OCTET_STRING *pAVar2;
  ASN1_VALUE *pAVar3;
  
  if (id == (uchar *)0x0) {
    if (((x == (X509 *)0x0) || (*(int *)(x->sha1_hash + 0xc) == 0)) ||
       (pAVar2 = *(ASN1_OCTET_STRING **)(*(int *)(x->sha1_hash + 0xc) + 0xc),
       pAVar2 == (ASN1_OCTET_STRING *)0x0)) {
      return 1;
    }
    ASN1_OCTET_STRING_free(pAVar2);
    iVar1 = 1;
    *(undefined4 *)(*(int *)(x->sha1_hash + 0xc) + 0xc) = 0;
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
      pAVar2 = *(ASN1_OCTET_STRING **)(pAVar3 + 0xc);
      if (pAVar2 == (ASN1_STRING *)0x0) {
        pAVar2 = ASN1_OCTET_STRING_new();
        *(ASN1_OCTET_STRING **)(pAVar3 + 0xc) = pAVar2;
        if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
          return 0;
        }
      }
      iVar1 = ASN1_STRING_set(pAVar2,id,len);
      return iVar1;
    }
  }
  return iVar1;
}

