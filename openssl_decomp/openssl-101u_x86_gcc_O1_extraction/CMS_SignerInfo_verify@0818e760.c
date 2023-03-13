
int CMS_SignerInfo_verify(CMS_SignerInfo *si)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  int in_GS_OFFSET;
  EVP_PKEY_CTX *local_30;
  uchar *local_2c;
  EVP_MD_CTX local_28;
  int local_10;
  
  local_2c = (uchar *)0x0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(si + 0x20) == 0) {
    ERR_put_error(0x2e,0x98,0x86,"cms_sd.c",0x2c7);
    iVar1 = -1;
    goto LAB_0818e86b;
  }
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(si + 8));
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type == (EVP_MD *)0x0) {
    iVar1 = -1;
    goto LAB_0818e86b;
  }
  EVP_MD_CTX_init(&local_28);
  iVar1 = EVP_DigestVerifyInit(&local_28,&local_30,type,(ENGINE *)0x0,*(EVP_PKEY **)(si + 0x20));
  if (iVar1 < 1) {
LAB_0818e858:
    iVar1 = -1;
  }
  else {
    cnt = ASN1_item_i2d(*(ASN1_VALUE **)(si + 0xc),&local_2c,(ASN1_ITEM *)CMS_Attributes_Verify_it);
    if (local_2c == (uchar *)0x0) goto LAB_0818e858;
    iVar1 = EVP_DigestUpdate(&local_28,local_2c,cnt);
    CRYPTO_free(local_2c);
    if (iVar1 < 1) goto LAB_0818e858;
    iVar1 = EVP_DigestVerifyFinal
                      (&local_28,(uchar *)(*(size_t **)(si + 0x14))[2],**(size_t **)(si + 0x14));
    if (iVar1 < 1) {
      ERR_put_error(0x2e,0x98,0x9e,"cms_sd.c",0x2df);
    }
  }
  EVP_MD_CTX_cleanup(&local_28);
LAB_0818e86b:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

