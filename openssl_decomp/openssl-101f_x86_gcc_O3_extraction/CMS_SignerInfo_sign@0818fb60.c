
int CMS_SignerInfo_sign(CMS_SignerInfo *si)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  ASN1_TIME *a;
  int in_GS_OFFSET;
  EVP_PKEY_CTX *local_44;
  uchar *local_40;
  size_t local_3c;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_40 = (uchar *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(si + 8));
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  iVar1 = 0;
  if (type == (EVP_MD *)0x0) goto LAB_0818fd32;
  EVP_MD_CTX_init(&local_38);
  iVar1 = CMS_signed_get_attr_by_NID(si,0x34,-1);
  if (iVar1 < 0) {
    a = X509_gmtime_adj((ASN1_TIME *)0x0,0);
    if (a != (ASN1_TIME *)0x0) {
      iVar1 = CMS_signed_add1_attr_by_NID(si,0x34,a->type,a,-1);
      if (0 < iVar1) {
        ASN1_TIME_free(a);
        goto LAB_0818fbcd;
      }
    }
    ASN1_TIME_free(a);
    ERR_put_error(0x2e,0x67,0x41,"cms_sd.c",0x1e6);
LAB_0818fd10:
    if (local_40 != (uchar *)0x0) {
      CRYPTO_free(local_40);
    }
  }
  else {
LAB_0818fbcd:
    iVar1 = EVP_DigestSignInit(&local_38,&local_44,type,(ENGINE *)0x0,*(EVP_PKEY **)(si + 0x20));
    if (iVar1 < 1) goto LAB_0818fd10;
    iVar1 = EVP_PKEY_CTX_ctrl(local_44,-1,8,0xb,0,si);
    if (iVar1 < 1) {
      iVar1 = 0x2d9;
LAB_0818fcf8:
      ERR_put_error(0x2e,0x97,0x6e,"cms_sd.c",iVar1);
      goto LAB_0818fd10;
    }
    cnt = ASN1_item_i2d(*(ASN1_VALUE **)(si + 0xc),&local_40,(ASN1_ITEM *)CMS_Attributes_Sign_it);
    if (local_40 != (uchar *)0x0) {
      iVar1 = EVP_DigestUpdate(&local_38,local_40,cnt);
      if (0 < iVar1) {
        iVar1 = EVP_DigestSignFinal(&local_38,(uchar *)0x0,&local_3c);
        if (0 < iVar1) {
          CRYPTO_free(local_40);
          local_40 = (uchar *)CRYPTO_malloc(local_3c,"cms_sd.c",0x2e6);
          if (local_40 == (uchar *)0x0) goto LAB_0818fd24;
          iVar1 = EVP_DigestSignFinal(&local_38,local_40,&local_3c);
          if (0 < iVar1) {
            iVar1 = EVP_PKEY_CTX_ctrl(local_44,-1,8,0xb,1,si);
            if (0 < iVar1) {
              EVP_MD_CTX_cleanup(&local_38);
              ASN1_STRING_set0(*(ASN1_STRING **)(si + 0x14),local_40,local_3c);
              iVar1 = 1;
              goto LAB_0818fd32;
            }
            iVar1 = 0x2ef;
            goto LAB_0818fcf8;
          }
        }
      }
      goto LAB_0818fd10;
    }
  }
LAB_0818fd24:
  EVP_MD_CTX_cleanup(&local_38);
  iVar1 = 0;
LAB_0818fd32:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

