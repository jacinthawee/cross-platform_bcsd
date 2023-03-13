
int ASN1_sign(undefined1 *i2d,X509_ALGOR *algor1,X509_ALGOR *algor2,ASN1_BIT_STRING *signature,
             char *data,EVP_PKEY *pkey,EVP_MD *type)

{
  ASN1_TYPE *pAVar1;
  ASN1_OBJECT *pAVar2;
  size_t cnt;
  void *d;
  size_t len;
  uchar *md;
  int iVar3;
  X509_ALGOR *pXVar4;
  int in_GS_OFFSET;
  void *local_40;
  size_t local_3c;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_3c = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_38);
  if (algor1 == (X509_ALGOR *)0x0) {
    if (algor2 != (X509_ALGOR *)0x0) {
      iVar3 = 1;
      do {
        do {
          iVar3 = iVar3 + 1;
        } while (iVar3 == 1);
        if (type->pkey_type == 0x71) {
          ASN1_TYPE_free(algor2->parameter);
          algor2->parameter = (ASN1_TYPE *)0x0;
        }
        else {
          pAVar1 = algor2->parameter;
          if ((pAVar1 == (ASN1_TYPE *)0x0) || (pAVar1->type != 5)) {
            ASN1_TYPE_free(pAVar1);
            pAVar1 = ASN1_TYPE_new();
            algor2->parameter = pAVar1;
            if (pAVar1 == (ASN1_TYPE *)0x0) goto LAB_081ca019;
            pAVar1->type = 5;
          }
        }
        ASN1_OBJECT_free(algor2->algorithm);
        pAVar2 = OBJ_nid2obj(type->pkey_type);
        algor2->algorithm = pAVar2;
        if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_081ca030;
        if (pAVar2->length == 0) goto LAB_081c9ff8;
      } while (iVar3 != 2);
    }
  }
  else {
    if (algor2 == (X509_ALGOR *)0x0) {
      if (type->pkey_type == 0x71) {
        ASN1_TYPE_free(algor1->parameter);
        algor1->parameter = (ASN1_TYPE *)0x0;
LAB_081c9fc8:
        ASN1_OBJECT_free(algor1->algorithm);
        pAVar2 = OBJ_nid2obj(type->pkey_type);
        algor1->algorithm = pAVar2;
        if (pAVar2 == (ASN1_OBJECT *)0x0) {
LAB_081ca030:
          ERR_put_error(0xd,0x80,0xa2,"a_sign.c",0xa4);
        }
        else {
          if (pAVar2->length != 0) goto LAB_081c9d1e;
LAB_081c9ff8:
          ERR_put_error(0xd,0x80,0x9a,"a_sign.c",0xa9);
        }
      }
      else {
        pAVar1 = algor1->parameter;
        if ((pAVar1 != (ASN1_TYPE *)0x0) && (pAVar1->type == 5)) goto LAB_081c9fc8;
        ASN1_TYPE_free(pAVar1);
        pAVar1 = ASN1_TYPE_new();
        algor1->parameter = pAVar1;
        if (pAVar1 != (ASN1_TYPE *)0x0) {
          pAVar1->type = 5;
          goto LAB_081c9fc8;
        }
      }
LAB_081ca019:
      EVP_MD_CTX_cleanup(&local_38);
      goto LAB_081c9e65;
    }
    iVar3 = 0;
    do {
      pXVar4 = algor1;
      if (iVar3 != 0) {
        pXVar4 = algor2;
      }
      if (type->pkey_type == 0x71) {
        ASN1_TYPE_free(pXVar4->parameter);
        pXVar4->parameter = (ASN1_TYPE *)0x0;
      }
      else {
        pAVar1 = pXVar4->parameter;
        if ((pAVar1 == (ASN1_TYPE *)0x0) || (pAVar1->type != 5)) {
          ASN1_TYPE_free(pAVar1);
          pAVar1 = ASN1_TYPE_new();
          pXVar4->parameter = pAVar1;
          if (pAVar1 == (ASN1_TYPE *)0x0) goto LAB_081ca019;
          pAVar1->type = 5;
        }
      }
      ASN1_OBJECT_free(pXVar4->algorithm);
      pAVar2 = OBJ_nid2obj(type->pkey_type);
      pXVar4->algorithm = pAVar2;
      if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_081ca030;
      if (pAVar2->length == 0) goto LAB_081c9ff8;
      iVar3 = iVar3 + 1;
    } while (iVar3 != 2);
  }
LAB_081c9d1e:
  cnt = (*(code *)i2d)(data,0);
  d = CRYPTO_malloc(cnt,"a_sign.c",0xae);
  len = EVP_PKEY_size(pkey);
  local_3c = len;
  md = (uchar *)CRYPTO_malloc(len,"a_sign.c",0xb0);
  if ((d == (void *)0x0) || (md == (uchar *)0x0)) {
    local_3c = 0;
    ERR_put_error(0xd,0x80,0x41,"a_sign.c",0xb3);
    EVP_MD_CTX_cleanup(&local_38);
    if (d != (void *)0x0) goto LAB_081c9e37;
  }
  else {
    local_40 = d;
    (*(code *)i2d)(data,&local_40);
    iVar3 = EVP_DigestInit_ex(&local_38,type,(ENGINE *)0x0);
    if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&local_38,d,cnt), iVar3 == 0)) ||
       (iVar3 = EVP_SignFinal(&local_38,md,&local_3c,pkey), iVar3 == 0)) {
      local_3c = 0;
      ERR_put_error(0xd,0x80,6,"a_sign.c",0xbe);
    }
    else {
      if (signature->data != (uchar *)0x0) {
        CRYPTO_free(signature->data);
      }
      signature->length = local_3c;
      signature->data = md;
      md = (uchar *)0x0;
      signature->flags = signature->flags & 0xfffffff0U | 8;
    }
    EVP_MD_CTX_cleanup(&local_38);
LAB_081c9e37:
    OPENSSL_cleanse(d,cnt);
    CRYPTO_free(d);
  }
  if (md != (uchar *)0x0) {
    OPENSSL_cleanse(md,len);
    CRYPTO_free(md);
  }
LAB_081c9e65:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_3c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

