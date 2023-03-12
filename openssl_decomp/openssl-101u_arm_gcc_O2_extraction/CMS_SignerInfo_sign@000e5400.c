
int CMS_SignerInfo_sign(CMS_SignerInfo *si)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  ASN1_TIME *a;
  EVP_PKEY_CTX *local_34;
  uchar *local_30;
  size_t local_2c;
  EVP_MD_CTX EStack_28;
  
  local_30 = (uchar *)0x0;
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(si + 8));
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type == (EVP_MD *)0x0) {
    return 0;
  }
  EVP_MD_CTX_init(&EStack_28);
  iVar1 = CMS_signed_get_attr_by_NID(si,0x34,-1);
  if (iVar1 < 0) {
    a = X509_gmtime_adj((ASN1_TIME *)0x0,0);
    if ((a != (ASN1_TIME *)0x0) &&
       (iVar1 = CMS_signed_add1_attr_by_NID(si,0x34,a->type,a,-1), 0 < iVar1)) {
      ASN1_TIME_free(a);
      goto LAB_000e5436;
    }
    ASN1_TIME_free(a);
    ERR_put_error(0x2e,0x67,0x41,"cms_sd.c",0x1b8);
  }
  else {
LAB_000e5436:
    iVar1 = EVP_DigestSignInit(&EStack_28,&local_34,type,(ENGINE *)0x0,*(EVP_PKEY **)(si + 0x20));
    if (0 < iVar1) {
      iVar1 = EVP_PKEY_CTX_ctrl(local_34,-1,8,0xb,0,si);
      if (iVar1 < 1) {
        iVar1 = 0x297;
LAB_000e54fa:
        ERR_put_error(0x2e,0x97,0x6e,"cms_sd.c",iVar1);
      }
      else {
        cnt = ASN1_item_i2d(*(ASN1_VALUE **)(si + 0xc),&local_30,(ASN1_ITEM *)CMS_Attributes_Sign_it
                           );
        if (local_30 == (uchar *)0x0) goto LAB_000e5512;
        iVar1 = EVP_DigestUpdate(&EStack_28,local_30,cnt);
        if ((0 < iVar1) &&
           (iVar1 = EVP_DigestSignFinal(&EStack_28,(uchar *)0x0,&local_2c), 0 < iVar1)) {
          CRYPTO_free(local_30);
          local_30 = (uchar *)CRYPTO_malloc(local_2c,"cms_sd.c",0x2a4);
          if (local_30 == (uchar *)0x0) goto LAB_000e5512;
          iVar1 = EVP_DigestSignFinal(&EStack_28,local_30,&local_2c);
          if (0 < iVar1) {
            iVar1 = EVP_PKEY_CTX_ctrl(local_34,-1,8,0xb,1,si);
            if (0 < iVar1) {
              EVP_MD_CTX_cleanup(&EStack_28);
              ASN1_STRING_set0(*(ASN1_STRING **)(si + 0x14),local_30,local_2c);
              return 1;
            }
            iVar1 = 0x2ac;
            goto LAB_000e54fa;
          }
        }
      }
    }
  }
  if (local_30 != (uchar *)0x0) {
    CRYPTO_free(local_30);
  }
LAB_000e5512:
  EVP_MD_CTX_cleanup(&EStack_28);
  return 0;
}

