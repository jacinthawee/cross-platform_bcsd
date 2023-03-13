
int ASN1_item_verify(ASN1_ITEM *it,X509_ALGOR *algor1,ASN1_BIT_STRING *signature,void *data,
                    EVP_PKEY *pkey)

{
  code *pcVar1;
  int iVar2;
  char *name;
  EVP_MD *type;
  size_t cnt;
  int in_GS_OFFSET;
  int reason;
  int iVar3;
  uchar *local_44;
  int local_40;
  int local_3c;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_44 = (uchar *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (pkey == (EVP_PKEY *)0x0) {
    iVar3 = 0x92;
    iVar2 = 0x43;
  }
  else {
    if ((signature->type != 3) || ((*(byte *)&signature->flags & 7) == 0)) {
      EVP_MD_CTX_init(&local_38);
      iVar2 = OBJ_obj2nid(algor1->algorithm);
      iVar2 = OBJ_find_sigid_algs(iVar2,&local_40,&local_3c);
      if (iVar2 == 0) {
        iVar3 = 0x9f;
LAB_081ca9b0:
        reason = 199;
LAB_081ca9ba:
        iVar2 = -1;
        ERR_put_error(0xd,0xc5,reason,"a_verify.c",iVar3);
      }
      else {
        if (local_40 != 0) {
          name = OBJ_nid2sn(local_40);
          type = EVP_get_digestbyname(name);
          if (type == (EVP_MD *)0x0) {
            iVar3 = 0xb6;
            reason = 0xa1;
          }
          else {
            iVar2 = EVP_PKEY_type(local_3c);
            if (iVar2 == *(int *)pkey->ameth) {
              iVar2 = EVP_DigestVerifyInit(&local_38,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
              if (iVar2 != 0) goto LAB_081ca9e8;
              iVar3 = 0xc1;
              goto LAB_081caa28;
            }
            iVar3 = 0xbc;
            reason = 200;
          }
          goto LAB_081ca9ba;
        }
        if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
           (pcVar1 = *(code **)(pkey->ameth + 100), pcVar1 == (code *)0x0)) {
          iVar3 = 0xa5;
          goto LAB_081ca9b0;
        }
        iVar2 = (*pcVar1)(&local_38,it,data,algor1,signature,pkey);
        if (iVar2 == 2) {
LAB_081ca9e8:
          cnt = ASN1_item_i2d((ASN1_VALUE *)data,&local_44,it);
          if (local_44 == (uchar *)0x0) {
            iVar3 = 0xcb;
            reason = 0x41;
            goto LAB_081ca9ba;
          }
          iVar2 = EVP_DigestUpdate(&local_38,local_44,cnt);
          if (iVar2 == 0) {
            iVar3 = 0xd0;
          }
          else {
            iVar2 = 1;
            OPENSSL_cleanse(local_44,cnt);
            CRYPTO_free(local_44);
            iVar3 = EVP_DigestVerifyFinal(&local_38,signature->data,signature->length);
            if (0 < iVar3) goto LAB_081ca8f9;
            iVar3 = 0xda;
          }
LAB_081caa28:
          iVar2 = 0;
          ERR_put_error(0xd,0xc5,6,"a_verify.c",iVar3);
        }
      }
LAB_081ca8f9:
      EVP_MD_CTX_cleanup(&local_38);
      goto LAB_081ca907;
    }
    iVar3 = 0x97;
    iVar2 = 0xdc;
  }
  ERR_put_error(0xd,0xc5,iVar2,"a_verify.c",iVar3);
  iVar2 = -1;
LAB_081ca907:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

