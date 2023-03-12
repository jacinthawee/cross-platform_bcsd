
int PKCS7_SIGNER_INFO_sign(PKCS7_SIGNER_INFO *si)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  EVP_PKEY_CTX *local_3c;
  uchar *local_38;
  size_t local_34;
  EVP_MD_CTX EStack_30;
  
  local_38 = (uchar *)0x0;
  iVar1 = OBJ_obj2nid(si->digest_alg->algorithm);
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type == (EVP_MD *)0x0) {
    return 0;
  }
  EVP_MD_CTX_init(&EStack_30);
  iVar1 = EVP_DigestSignInit(&EStack_30,&local_3c,type,(ENGINE *)0x0,si->pkey);
  if (0 < iVar1) {
    iVar1 = EVP_PKEY_CTX_ctrl(local_3c,-1,8,5,0,si);
    if (iVar1 < 1) {
      iVar1 = 0x398;
LAB_000dd5b8:
      ERR_put_error(0x21,0x8b,0x98,"pk7_doit.c",iVar1);
    }
    else {
      cnt = ASN1_item_i2d((ASN1_VALUE *)si->auth_attr,&local_38,(ASN1_ITEM *)PKCS7_ATTR_SIGN_it);
      if (local_38 == (uchar *)0x0) goto LAB_000dd5d0;
      iVar1 = EVP_DigestUpdate(&EStack_30,local_38,cnt);
      if (0 < iVar1) {
        CRYPTO_free(local_38);
        iVar1 = EVP_DigestSignFinal(&EStack_30,(uchar *)0x0,&local_34);
        if (0 < iVar1) {
          local_38 = (uchar *)CRYPTO_malloc(local_34,"pk7_doit.c",0x3a5);
          if (local_38 == (uchar *)0x0) goto LAB_000dd5d0;
          iVar1 = EVP_DigestSignFinal(&EStack_30,local_38,&local_34);
          if (0 < iVar1) {
            iVar1 = EVP_PKEY_CTX_ctrl(local_3c,-1,8,5,1,si);
            if (0 < iVar1) {
              EVP_MD_CTX_cleanup(&EStack_30);
              ASN1_STRING_set0(si->enc_digest,local_38,local_34);
              return 1;
            }
            iVar1 = 0x3ae;
            goto LAB_000dd5b8;
          }
        }
      }
    }
  }
  if (local_38 != (uchar *)0x0) {
    CRYPTO_free(local_38);
  }
LAB_000dd5d0:
  EVP_MD_CTX_cleanup(&EStack_30);
  return 0;
}

