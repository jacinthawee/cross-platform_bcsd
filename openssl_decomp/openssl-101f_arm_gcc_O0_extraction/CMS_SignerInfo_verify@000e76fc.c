
int CMS_SignerInfo_verify(CMS_SignerInfo *si)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  EVP_PKEY_CTX *pEStack_38;
  uchar *local_34;
  EVP_MD_CTX EStack_30;
  
  local_34 = (uchar *)0x0;
  if (*(int *)(si + 0x20) == 0) {
    ERR_put_error(0x2e,0x98,0x86,"cms_sd.c",0x30b);
    return -1;
  }
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(si + 8));
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type == (EVP_MD *)0x0) {
    return -1;
  }
  EVP_MD_CTX_init(&EStack_30);
  iVar1 = EVP_DigestVerifyInit(&EStack_30,&pEStack_38,type,(ENGINE *)0x0,*(EVP_PKEY **)(si + 0x20));
  if ((0 < iVar1) &&
     (cnt = ASN1_item_i2d(*(ASN1_VALUE **)(si + 0xc),&local_34,(ASN1_ITEM *)CMS_Attributes_Verify_it
                         ), local_34 != (uchar *)0x0)) {
    iVar1 = EVP_DigestUpdate(&EStack_30,local_34,cnt);
    CRYPTO_free(local_34);
    if (0 < iVar1) {
      iVar1 = EVP_DigestVerifyFinal
                        (&EStack_30,(uchar *)(*(size_t **)(si + 0x14))[2],**(size_t **)(si + 0x14));
      if (iVar1 < 1) {
        ERR_put_error(0x2e,0x98,0x9e,"cms_sd.c",0x324);
      }
      goto LAB_000e7792;
    }
  }
  iVar1 = -1;
LAB_000e7792:
  EVP_MD_CTX_cleanup(&EStack_30);
  return iVar1;
}

