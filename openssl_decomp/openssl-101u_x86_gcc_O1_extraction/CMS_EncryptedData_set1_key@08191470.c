
int CMS_EncryptedData_set1_key(CMS_ContentInfo *cms,EVP_CIPHER *ciph,uchar *key,size_t keylen)

{
  ASN1_OBJECT **ppAVar1;
  ASN1_VALUE *pAVar2;
  ASN1_OBJECT *pAVar3;
  void *__dest;
  int iVar4;
  int line;
  
  if ((key == (uchar *)0x0) || (keylen == 0)) {
    line = 0xef;
    iVar4 = 0x82;
  }
  else if (ciph == (EVP_CIPHER *)0x0) {
    iVar4 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar4 == 0x1a) {
      iVar4 = *(int *)(*(int *)(cms + 4) + 4);
      *(undefined4 *)(iVar4 + 0xc) = 0;
      __dest = CRYPTO_malloc(keylen,"cms_enc.c",0xdf);
      *(void **)(iVar4 + 0x10) = __dest;
      if (__dest == (void *)0x0) {
        return 0;
      }
      memcpy(__dest,key,keylen);
      *(size_t *)(iVar4 + 0x14) = keylen;
      return 1;
    }
    line = 0xfb;
    iVar4 = 0x7a;
  }
  else {
    pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_EncryptedData_it);
    *(ASN1_VALUE **)(cms + 4) = pAVar2;
    if (pAVar2 != (ASN1_VALUE *)0x0) {
      pAVar3 = OBJ_nid2obj(0x1a);
      *(ASN1_OBJECT **)cms = pAVar3;
      ppAVar1 = (ASN1_OBJECT **)(*(undefined4 **)(cms + 4))[1];
      **(undefined4 **)(cms + 4) = 0;
      ppAVar1[3] = (ASN1_OBJECT *)ciph;
      pAVar3 = (ASN1_OBJECT *)CRYPTO_malloc(keylen,"cms_enc.c",0xdf);
      ppAVar1[4] = pAVar3;
      if (pAVar3 == (ASN1_OBJECT *)0x0) {
        return 0;
      }
      memcpy(pAVar3,key,keylen);
      ppAVar1[5] = (ASN1_OBJECT *)keylen;
      pAVar3 = OBJ_nid2obj(0x15);
      *ppAVar1 = pAVar3;
      return 1;
    }
    line = 0xf5;
    iVar4 = 0x41;
  }
  ERR_put_error(0x2e,0x7b,iVar4,"cms_enc.c",line);
  return 0;
}

