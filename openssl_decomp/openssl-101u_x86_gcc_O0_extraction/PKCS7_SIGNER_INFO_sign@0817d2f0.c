
int PKCS7_SIGNER_INFO_sign(PKCS7_SIGNER_INFO *si)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  int in_GS_OFFSET;
  EVP_PKEY_CTX *local_34;
  uchar *local_30;
  size_t local_2c;
  EVP_MD_CTX local_28;
  int local_10;
  
  local_30 = (uchar *)0x0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = OBJ_obj2nid(si->digest_alg->algorithm);
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  iVar1 = 0;
  if (type == (EVP_MD *)0x0) goto LAB_0817d4ba;
  EVP_MD_CTX_init(&local_28);
  iVar1 = EVP_DigestSignInit(&local_28,&local_34,type,(ENGINE *)0x0,si->pkey);
  if (iVar1 < 1) {
LAB_0817d498:
    if (local_30 != (uchar *)0x0) {
      CRYPTO_free(local_30);
    }
  }
  else {
    iVar1 = EVP_PKEY_CTX_ctrl(local_34,-1,8,5,0,si);
    if (iVar1 < 1) {
      iVar1 = 0x3a2;
LAB_0817d478:
      ERR_put_error(0x21,0x8b,0x98,"pk7_doit.c",iVar1);
      goto LAB_0817d498;
    }
    cnt = ASN1_item_i2d((ASN1_VALUE *)si->auth_attr,&local_30,(ASN1_ITEM *)PKCS7_ATTR_SIGN_it);
    if (local_30 != (uchar *)0x0) {
      iVar1 = EVP_DigestUpdate(&local_28,local_30,cnt);
      if (0 < iVar1) {
        CRYPTO_free(local_30);
        local_30 = (uchar *)0x0;
        iVar1 = EVP_DigestSignFinal(&local_28,(uchar *)0x0,&local_2c);
        if (0 < iVar1) {
          local_30 = (uchar *)CRYPTO_malloc(local_2c,"pk7_doit.c",0x3b0);
          if (local_30 == (uchar *)0x0) goto LAB_0817d4ac;
          iVar1 = EVP_DigestSignFinal(&local_28,local_30,&local_2c);
          if (0 < iVar1) {
            iVar1 = EVP_PKEY_CTX_ctrl(local_34,-1,8,5,1,si);
            if (0 < iVar1) {
              EVP_MD_CTX_cleanup(&local_28);
              ASN1_STRING_set0(si->enc_digest,local_30,local_2c);
              iVar1 = 1;
              goto LAB_0817d4ba;
            }
            iVar1 = 0x3b8;
            goto LAB_0817d478;
          }
        }
      }
      goto LAB_0817d498;
    }
  }
LAB_0817d4ac:
  EVP_MD_CTX_cleanup(&local_28);
  iVar1 = 0;
LAB_0817d4ba:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

