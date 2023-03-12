
int CMS_EncryptedData_set1_key(CMS_ContentInfo *cms,EVP_CIPHER *ciph,uchar *key,size_t keylen)

{
  ASN1_VALUE *pAVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  undefined4 *puVar5;
  ASN1_OBJECT **ppAVar6;
  
  if (keylen == 0 || key == (uchar *)0x0) {
    ERR_put_error(0x2e,0x7b,0x82,"cms_enc.c",0xef);
    return 0;
  }
  if (ciph == (EVP_CIPHER *)0x0) {
    iVar4 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar4 != 0x1a) {
      ERR_put_error(0x2e,0x7b,0x7a,"cms_enc.c",0xfb);
      return 0;
    }
    puVar5 = *(undefined4 **)(cms + 4);
  }
  else {
    pAVar1 = ASN1_item_new((ASN1_ITEM *)CMS_EncryptedData_it);
    *(ASN1_VALUE **)(cms + 4) = pAVar1;
    if (pAVar1 == (ASN1_VALUE *)0x0) {
      ERR_put_error(0x2e,0x7b,0x41,"cms_enc.c",0xf5);
      return 0;
    }
    pAVar2 = OBJ_nid2obj(0x1a);
    puVar5 = *(undefined4 **)(cms + 4);
    *(ASN1_OBJECT **)cms = pAVar2;
    *puVar5 = 0;
  }
  ppAVar6 = (ASN1_OBJECT **)puVar5[1];
  ppAVar6[3] = (ASN1_OBJECT *)ciph;
  pAVar2 = (ASN1_OBJECT *)CRYPTO_malloc(keylen,"cms_enc.c",0xdf);
  ppAVar6[4] = pAVar2;
  if (pAVar2 != (ASN1_OBJECT *)0x0) {
    memcpy(pAVar2,key,keylen);
    ppAVar6[5] = (ASN1_OBJECT *)keylen;
    pAVar2 = (ASN1_OBJECT *)0x1;
    if (ciph != (EVP_CIPHER *)0x0) {
      pAVar3 = OBJ_nid2obj(0x15);
      pAVar2 = (ASN1_OBJECT *)0x1;
      *ppAVar6 = pAVar3;
    }
  }
  return (int)pAVar2;
}

