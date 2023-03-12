
void cms_EncryptedContent_init_bio(int param_1)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  BIO *type_00;
  BIO *ptr;
  char *name;
  EVP_CIPHER *pEVar3;
  EVP_CIPHER *key;
  EVP_CIPHER *enc;
  ASN1_OBJECT **ppAVar4;
  EVP_CIPHER *pEVar5;
  EVP_CIPHER *iv;
  EVP_CIPHER *local_44;
  EVP_CIPHER_CTX *local_40;
  uchar auStack_3c [16];
  ulong local_2c;
  
  enc = *(EVP_CIPHER **)(param_1 + 0xc);
  ppAVar4 = *(ASN1_OBJECT ***)(param_1 + 4);
  if (enc != (EVP_CIPHER *)0x0) {
    enc = (EVP_CIPHER *)0x1;
  }
  local_2c = __TMC_END__;
  type = BIO_f_cipher();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x59);
    goto LAB_000e8f52;
  }
  BIO_ctrl(bp,0x81,0,&local_40);
  if (enc == (EVP_CIPHER *)0x0) {
    iVar1 = OBJ_obj2nid(*ppAVar4);
    name = OBJ_nid2sn(iVar1);
    pEVar5 = EVP_get_cipherbyname(name);
    if (pEVar5 == (EVP_CIPHER *)0x0) {
      ERR_put_error(0x2e,0x78,0x94,"cms_enc.c",0x6f);
      pEVar3 = pEVar5;
    }
    else {
      iVar1 = EVP_CipherInit_ex(local_40,pEVar5,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,0);
      if (iVar1 < 1) goto LAB_000e911c;
      iVar1 = EVP_CIPHER_asn1_to_param(local_40,(ASN1_TYPE *)ppAVar4[1]);
      if (0 < iVar1) {
        pEVar3 = (EVP_CIPHER *)EVP_CIPHER_CTX_key_length(local_40);
        iv = enc;
        goto LAB_000e8fe0;
      }
      ERR_put_error(0x2e,0x78,0x66,"cms_enc.c",0x8b);
      pEVar5 = enc;
      pEVar3 = enc;
    }
LAB_000e9020:
    ptr = *(BIO **)(param_1 + 0x10);
    type_00 = ptr;
    if (ptr != (BIO *)0x0) {
LAB_000e8f88:
      type_00 = (BIO *)0x0;
      goto LAB_000e8f8a;
    }
  }
  else {
    pEVar3 = *(EVP_CIPHER **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    pEVar5 = (EVP_CIPHER *)0x0;
    iVar1 = EVP_CipherInit_ex(local_40,pEVar3,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,1);
    if (iVar1 < 1) {
LAB_000e911c:
      ERR_put_error(0x2e,0x78,0x65,"cms_enc.c",0x77);
      pEVar5 = (EVP_CIPHER *)0x0;
      pEVar3 = (EVP_CIPHER *)0x0;
      goto LAB_000e9020;
    }
    pEVar3 = EVP_CIPHER_CTX_cipher(local_40);
    iVar1 = EVP_CIPHER_type(pEVar3);
    pAVar2 = OBJ_nid2obj(iVar1);
    *ppAVar4 = pAVar2;
    iVar1 = EVP_CIPHER_CTX_iv_length(local_40);
    if (0 < iVar1) {
      iVar1 = RAND_pseudo_bytes(auStack_3c,iVar1);
      pEVar3 = pEVar5;
      if (iVar1 < 1) goto LAB_000e9020;
      pEVar5 = (EVP_CIPHER *)auStack_3c;
    }
    pEVar3 = (EVP_CIPHER *)EVP_CIPHER_CTX_key_length(local_40);
    key = (EVP_CIPHER *)0x0;
    iv = pEVar5;
    if (*(int *)(param_1 + 0x10) != 0) goto LAB_000e8ede;
LAB_000e8fe0:
    key = (EVP_CIPHER *)CRYPTO_malloc((int)pEVar3,"cms_enc.c",0x92);
    pEVar5 = key;
    if (key == (EVP_CIPHER *)0x0) {
      ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x96);
      goto LAB_000e9020;
    }
    iVar1 = EVP_CIPHER_CTX_rand_key(local_40,(uchar *)key);
    if (iVar1 < 1) goto LAB_000e9020;
    pEVar5 = *(EVP_CIPHER **)(param_1 + 0x10);
    if (pEVar5 != (EVP_CIPHER *)0x0) {
LAB_000e8ede:
      pEVar5 = key;
      if (*(EVP_CIPHER **)(param_1 + 0x14) == pEVar3) {
        key = *(EVP_CIPHER **)(param_1 + 0x10);
        local_44 = (EVP_CIPHER *)0x0;
        goto LAB_000e8ef6;
      }
      iVar1 = EVP_CIPHER_CTX_set_key_length(local_40,(int)*(EVP_CIPHER **)(param_1 + 0x14));
      if (0 < iVar1) {
        key = *(EVP_CIPHER **)(param_1 + 0x10);
        local_44 = (EVP_CIPHER *)0x0;
        goto LAB_000e8ef6;
      }
      if ((enc == (EVP_CIPHER *)0x0) && (*(int *)(param_1 + 0x18) == 0)) {
        OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
        CRYPTO_free(*(void **)(param_1 + 0x10));
        *(EVP_CIPHER **)(param_1 + 0x10) = pEVar5;
        *(EVP_CIPHER **)(param_1 + 0x14) = pEVar3;
        ERR_clear_error();
        key = *(EVP_CIPHER **)(param_1 + 0x10);
        pEVar5 = enc;
        local_44 = enc;
        goto LAB_000e8ef6;
      }
      ERR_put_error(0x2e,0x78,0x76,"cms_enc.c",0xb4);
      ptr = *(BIO **)(param_1 + 0x10);
      type_00 = ptr;
      if (ptr == (BIO *)0x0) goto LAB_000e8f3a;
      goto LAB_000e8f88;
    }
    *(EVP_CIPHER **)(param_1 + 0x10) = key;
    *(EVP_CIPHER **)(param_1 + 0x14) = pEVar3;
    if (enc == (EVP_CIPHER *)0x0) {
      ERR_clear_error();
      key = enc;
      goto LAB_000e8ede;
    }
    local_44 = (EVP_CIPHER *)0x1;
LAB_000e8ef6:
    iVar1 = EVP_CipherInit_ex(local_40,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)key,(uchar *)iv,
                              (int)enc);
    if (iVar1 < 1) {
      type_00 = (BIO *)0x0;
      ERR_put_error(0x2e,0x78,0x65,"cms_enc.c",199);
    }
    else if (iv == (EVP_CIPHER *)0x0) {
LAB_000e8f30:
      type_00 = (BIO *)0x1;
    }
    else {
      type_00 = (BIO *)ASN1_TYPE_new();
      ppAVar4[1] = (ASN1_OBJECT *)type_00;
      if (type_00 == (BIO *)0x0) {
        ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0xd1);
      }
      else {
        iVar1 = EVP_CIPHER_param_to_asn1(local_40,(ASN1_TYPE *)type_00);
        if (0 < iVar1) goto LAB_000e8f30;
        type_00 = (BIO *)0x0;
        ERR_put_error(0x2e,0x78,0x66,"cms_enc.c",0xd7);
      }
    }
    ptr = *(BIO **)(param_1 + 0x10);
    if ((ptr == (BIO *)0x0) || (local_44 != (EVP_CIPHER *)0x0)) goto LAB_000e8f3a;
LAB_000e8f8a:
    OPENSSL_cleanse(ptr,*(size_t *)(param_1 + 0x14));
    CRYPTO_free(*(void **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
LAB_000e8f3a:
  if (pEVar5 != (EVP_CIPHER *)0x0) {
    OPENSSL_cleanse(pEVar5,(size_t)pEVar3);
    CRYPTO_free(pEVar5);
  }
  if (type_00 == (BIO *)0x0) {
    BIO_free(bp);
    bp = type_00;
  }
LAB_000e8f52:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(bp);
}

