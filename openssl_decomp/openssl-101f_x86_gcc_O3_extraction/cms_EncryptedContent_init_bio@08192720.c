
BIO * cms_EncryptedContent_init_bio(int param_1)

{
  uchar *puVar1;
  ASN1_OBJECT **ppAVar2;
  bool bVar3;
  bool bVar4;
  uint enc;
  BIO_METHOD *type;
  BIO *bp;
  int iVar5;
  EVP_CIPHER *pEVar6;
  ASN1_OBJECT *pAVar7;
  void *ptr;
  char *name;
  uchar *key;
  uchar *puVar8;
  int in_GS_OFFSET;
  int iVar9;
  size_t local_4c;
  uchar *local_44;
  EVP_CIPHER_CTX *local_34;
  uchar local_30 [16];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  puVar1 = *(uchar **)(param_1 + 0xc);
  ppAVar2 = *(ASN1_OBJECT ***)(param_1 + 4);
  enc = (uint)(puVar1 != (uchar *)0x0);
  type = BIO_f_cipher();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x59);
    bp = (BIO *)0x0;
    goto LAB_081928e9;
  }
  BIO_ctrl(bp,0x81,0,&local_34);
  if (puVar1 == (uchar *)0x0) {
    iVar5 = OBJ_obj2nid(*ppAVar2);
    name = OBJ_nid2sn(iVar5);
    pEVar6 = EVP_get_cipherbyname(name);
    if (pEVar6 == (EVP_CIPHER *)0x0) {
      iVar9 = 0x6f;
      iVar5 = 0x94;
      goto LAB_08192924;
    }
    iVar5 = EVP_CipherInit_ex(local_34,pEVar6,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,enc);
    if (iVar5 < 1) goto LAB_08192918;
    iVar5 = EVP_CIPHER_asn1_to_param(local_34,(ASN1_TYPE *)ppAVar2[1]);
    if (iVar5 < 1) {
      iVar9 = 0x8b;
      iVar5 = 0x66;
      goto LAB_08192924;
    }
    local_4c = EVP_CIPHER_CTX_key_length(local_34);
    local_44 = (uchar *)0x0;
LAB_081929f4:
    key = (uchar *)CRYPTO_malloc(local_4c,"cms_enc.c",0x92);
    if (key == (uchar *)0x0) {
      ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x96);
      goto LAB_08192938;
    }
    iVar5 = EVP_CIPHER_CTX_rand_key(local_34,key);
    puVar8 = key;
    if (0 < iVar5) {
      if (*(int *)(param_1 + 0x10) == 0) {
        *(uchar **)(param_1 + 0x10) = key;
        bVar4 = false;
        *(size_t *)(param_1 + 0x14) = local_4c;
        puVar8 = (uchar *)0x0;
        if (puVar1 == (uchar *)0x0) {
          ERR_clear_error();
          puVar8 = puVar1;
          goto LAB_0819282b;
        }
LAB_08192854:
        iVar5 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)0x0,(ENGINE *)0x0,key,local_44,enc);
        if (iVar5 < 1) {
          iVar9 = 199;
          iVar5 = 0x65;
        }
        else {
          bVar3 = true;
          if (local_44 == (uchar *)0x0) goto LAB_081928b1;
          pAVar7 = (ASN1_OBJECT *)ASN1_TYPE_new();
          ppAVar2[1] = pAVar7;
          if (pAVar7 == (ASN1_OBJECT *)0x0) {
            iVar9 = 0xd1;
            iVar5 = 0x41;
          }
          else {
            iVar5 = EVP_CIPHER_param_to_asn1(local_34,(ASN1_TYPE *)pAVar7);
            if (0 < iVar5) goto LAB_081928b1;
            iVar9 = 0xd7;
            iVar5 = 0x66;
          }
        }
        bVar3 = false;
        ERR_put_error(0x2e,0x78,iVar5,"cms_enc.c",iVar9);
      }
      else {
LAB_0819282b:
        if ((*(size_t *)(param_1 + 0x14) == local_4c) ||
           (iVar5 = EVP_CIPHER_CTX_set_key_length(local_34,*(size_t *)(param_1 + 0x14)), 0 < iVar5))
        {
          key = *(uchar **)(param_1 + 0x10);
          bVar4 = true;
          goto LAB_08192854;
        }
        if ((puVar1 == (uchar *)0x0) && (*(int *)(param_1 + 0x18) == 0)) {
          OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
          CRYPTO_free(*(void **)(param_1 + 0x10));
          *(uchar **)(param_1 + 0x10) = puVar8;
          puVar8 = (uchar *)0x0;
          *(size_t *)(param_1 + 0x14) = local_4c;
          ERR_clear_error();
          key = *(uchar **)(param_1 + 0x10);
          bVar4 = true;
          goto LAB_08192854;
        }
        bVar3 = false;
        ERR_put_error(0x2e,0x78,0x76,"cms_enc.c",0xb4);
        bVar4 = true;
      }
LAB_081928b1:
      ptr = *(void **)(param_1 + 0x10);
      if ((ptr != (void *)0x0) && (bVar4)) goto LAB_08192947;
      goto LAB_081928c3;
    }
    ptr = *(void **)(param_1 + 0x10);
    bVar3 = false;
    if (ptr != (void *)0x0) goto LAB_08192947;
LAB_081928c7:
    OPENSSL_cleanse(key,local_4c);
    CRYPTO_free(key);
LAB_081928df:
    if (bVar3) goto LAB_081928e9;
  }
  else {
    pEVar6 = *(EVP_CIPHER **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar5 = EVP_CipherInit_ex(local_34,pEVar6,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,enc);
    if (0 < iVar5) {
      pEVar6 = EVP_CIPHER_CTX_cipher(local_34);
      iVar5 = EVP_CIPHER_type(pEVar6);
      pAVar7 = OBJ_nid2obj(iVar5);
      *ppAVar2 = pAVar7;
      iVar5 = EVP_CIPHER_CTX_iv_length(local_34);
      if (iVar5 < 1) {
        local_44 = (uchar *)0x0;
      }
      else {
        local_44 = local_30;
        iVar5 = RAND_pseudo_bytes(local_44,iVar5);
        if (iVar5 < 1) {
          local_4c = 0;
          goto LAB_08192938;
        }
      }
      local_4c = EVP_CIPHER_CTX_key_length(local_34);
      if (*(int *)(param_1 + 0x10) == 0) goto LAB_081929f4;
      puVar8 = (uchar *)0x0;
      goto LAB_0819282b;
    }
LAB_08192918:
    iVar9 = 0x77;
    iVar5 = 0x65;
LAB_08192924:
    ERR_put_error(0x2e,0x78,iVar5,"cms_enc.c",iVar9);
    local_4c = 0;
LAB_08192938:
    ptr = *(void **)(param_1 + 0x10);
    bVar3 = false;
    puVar8 = (uchar *)0x0;
    if (ptr != (void *)0x0) {
LAB_08192947:
      OPENSSL_cleanse(ptr,*(size_t *)(param_1 + 0x14));
      CRYPTO_free(*(void **)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
LAB_081928c3:
      key = puVar8;
      if (puVar8 != (uchar *)0x0) goto LAB_081928c7;
      goto LAB_081928df;
    }
  }
  BIO_free(bp);
  bp = (BIO *)0x0;
LAB_081928e9:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bp;
}

