
BIO * cms_EncryptedContent_init_bio(int param_1)

{
  ASN1_OBJECT **ppAVar1;
  bool bVar2;
  uint enc;
  BIO_METHOD *type;
  BIO *bp;
  int iVar3;
  EVP_CIPHER *pEVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  char *name;
  uchar *key;
  int in_GS_OFFSET;
  size_t local_44;
  uchar *local_40;
  EVP_CIPHER_CTX *local_34;
  uchar local_30 [16];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = *(int *)(param_1 + 0xc);
  ppAVar1 = *(ASN1_OBJECT ***)(param_1 + 4);
  enc = (uint)(iVar6 != 0);
  type = BIO_f_cipher();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x58);
    bp = (BIO *)0x0;
    goto LAB_08190fdd;
  }
  BIO_ctrl(bp,0x81,0,&local_34);
  if (iVar6 == 0) {
    iVar3 = OBJ_obj2nid(*ppAVar1);
    name = OBJ_nid2sn(iVar3);
    pEVar4 = EVP_get_cipherbyname(name);
    if (pEVar4 == (EVP_CIPHER *)0x0) {
      ERR_put_error(0x2e,0x78,0x94,"cms_enc.c",0x69);
    }
    else {
      iVar3 = EVP_CipherInit_ex(local_34,pEVar4,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,enc);
      if (iVar3 < 1) goto LAB_08191010;
      iVar3 = EVP_CIPHER_asn1_to_param(local_34,(ASN1_TYPE *)ppAVar1[1]);
      if (0 < iVar3) {
        local_44 = EVP_CIPHER_CTX_key_length(local_34);
        local_40 = (uchar *)0x0;
        goto LAB_081910c8;
      }
      ERR_put_error(0x2e,0x78,0x66,"cms_enc.c",0x80);
    }
LAB_08191028:
    if (*(void **)(param_1 + 0x10) != (void *)0x0) {
      OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
      CRYPTO_free(*(void **)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  else {
    pEVar4 = *(EVP_CIPHER **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar3 = EVP_CipherInit_ex(local_34,pEVar4,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,enc);
    if (iVar3 < 1) {
LAB_08191010:
      ERR_put_error(0x2e,0x78,0x65,"cms_enc.c",0x70);
      goto LAB_08191028;
    }
    pEVar4 = EVP_CIPHER_CTX_cipher(local_34);
    iVar3 = EVP_CIPHER_type(pEVar4);
    pAVar5 = OBJ_nid2obj(iVar3);
    *ppAVar1 = pAVar5;
    iVar3 = EVP_CIPHER_CTX_iv_length(local_34);
    if (iVar3 < 1) {
      local_40 = (uchar *)0x0;
    }
    else {
      local_40 = local_30;
      iVar3 = RAND_bytes(local_40,iVar3);
      if (iVar3 < 1) goto LAB_08191028;
    }
    local_44 = EVP_CIPHER_CTX_key_length(local_34);
    if (*(int *)(param_1 + 0x10) == 0) {
LAB_081910c8:
      key = (uchar *)CRYPTO_malloc(local_44,"cms_enc.c",0x86);
      if (key == (uchar *)0x0) {
        ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x88);
        goto LAB_08191028;
      }
      iVar3 = EVP_CIPHER_CTX_rand_key(local_34,key);
      if (0 < iVar3) {
        if (*(int *)(param_1 + 0x10) != 0) goto LAB_08190f1a;
        *(uchar **)(param_1 + 0x10) = key;
        *(size_t *)(param_1 + 0x14) = local_44;
        if (iVar6 == 0) {
          ERR_clear_error();
          goto LAB_08190f18;
        }
        iVar6 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)0x0,(ENGINE *)0x0,key,local_40,enc);
        if (0 < iVar6) {
          bVar2 = false;
          key = (uchar *)0x0;
          goto LAB_08190f6b;
        }
        goto LAB_081911b0;
      }
      if (*(void **)(param_1 + 0x10) == (void *)0x0) goto LAB_081911a1;
      OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
      CRYPTO_free(*(void **)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
      bVar2 = false;
LAB_08190fbf:
      OPENSSL_cleanse(key,local_44);
      CRYPTO_free(key);
      if (bVar2) goto LAB_08190fdd;
    }
    else {
LAB_08190f18:
      key = (uchar *)0x0;
LAB_08190f1a:
      if ((*(size_t *)(param_1 + 0x14) == local_44) ||
         (iVar3 = EVP_CIPHER_CTX_set_key_length(local_34,*(size_t *)(param_1 + 0x14)), 0 < iVar3)) {
        iVar3 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                  *(uchar **)(param_1 + 0x10),local_40,enc);
        if (iVar3 < 1) goto LAB_081911b8;
        bVar2 = true;
        if (iVar6 == 0) {
LAB_08190fa5:
          if ((*(void **)(param_1 + 0x10) != (void *)0x0) && (bVar2)) {
            OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
            CRYPTO_free(*(void **)(param_1 + 0x10));
            *(undefined4 *)(param_1 + 0x10) = 0;
          }
          bVar2 = true;
          if (key == (uchar *)0x0) goto LAB_08190fdd;
          goto LAB_08190fbf;
        }
LAB_08190f6b:
        pAVar5 = (ASN1_OBJECT *)ASN1_TYPE_new();
        ppAVar1[1] = pAVar5;
        if (pAVar5 == (ASN1_OBJECT *)0x0) {
          ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0xb9);
        }
        else {
          iVar6 = EVP_CIPHER_param_to_asn1(local_34,(ASN1_TYPE *)pAVar5);
          if (0 < iVar6) {
            if (ppAVar1[1]->sn == (char *)0xffffffff) {
              ASN1_TYPE_free((ASN1_TYPE *)ppAVar1[1]);
              ppAVar1[1] = (ASN1_OBJECT *)0x0;
            }
            goto LAB_08190fa5;
          }
          ERR_put_error(0x2e,0x78,0x66,"cms_enc.c",0xbe);
        }
      }
      else {
        if ((iVar6 != 0) || (*(int *)(param_1 + 0x18) != 0)) {
          ERR_put_error(0x2e,0x78,0x76,"cms_enc.c",0xa3);
          goto LAB_08191173;
        }
        OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
        CRYPTO_free(*(void **)(param_1 + 0x10));
        *(uchar **)(param_1 + 0x10) = key;
        *(size_t *)(param_1 + 0x14) = local_44;
        ERR_clear_error();
        iVar6 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                  *(uchar **)(param_1 + 0x10),local_40,enc);
        if (0 < iVar6) {
          if (*(void **)(param_1 + 0x10) != (void *)0x0) {
            OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
            CRYPTO_free(*(void **)(param_1 + 0x10));
            *(undefined4 *)(param_1 + 0x10) = 0;
          }
          goto LAB_08190fdd;
        }
LAB_081911b0:
        key = (uchar *)0x0;
LAB_081911b8:
        ERR_put_error(0x2e,0x78,0x65,"cms_enc.c",0xb3);
      }
LAB_08191173:
      if (*(void **)(param_1 + 0x10) != (void *)0x0) {
        OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
        CRYPTO_free(*(void **)(param_1 + 0x10));
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
      if (key != (uchar *)0x0) {
LAB_081911a1:
        bVar2 = false;
        goto LAB_08190fbf;
      }
    }
  }
  BIO_free(bp);
  bp = (BIO *)0x0;
LAB_08190fdd:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bp;
}

