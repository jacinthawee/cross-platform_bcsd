
int ASN1_sign(undefined1 *i2d,X509_ALGOR *algor1,X509_ALGOR *algor2,ASN1_BIT_STRING *signature,
             char *data,EVP_PKEY *pkey,EVP_MD *type)

{
  ASN1_OBJECT *pAVar1;
  size_t cnt;
  void *d;
  size_t len;
  uchar *md;
  ASN1_TYPE *pAVar2;
  int iVar3;
  X509_ALGOR *pXVar4;
  void *local_48;
  size_t local_44;
  EVP_MD_CTX EStack_40;
  
  iVar3 = 0;
  local_44 = 0;
  EVP_MD_CTX_init(&EStack_40);
  do {
    pXVar4 = algor2;
    if (iVar3 == 0) {
      pXVar4 = algor1;
    }
    if (pXVar4 != (X509_ALGOR *)0x0) {
      if (type->pkey_type == 0x71) {
        ASN1_TYPE_free(pXVar4->parameter);
        pXVar4->parameter = (ASN1_TYPE *)0x0;
      }
      else {
        pAVar2 = pXVar4->parameter;
        if ((pAVar2 == (ASN1_TYPE *)0x0) || (pAVar2->type != 5)) {
          ASN1_TYPE_free(pAVar2);
          pAVar2 = ASN1_TYPE_new();
          pXVar4->parameter = pAVar2;
          if (pAVar2 == (ASN1_TYPE *)0x0) goto LAB_0010de60;
          pAVar2->type = 5;
        }
      }
      ASN1_OBJECT_free(pXVar4->algorithm);
      pAVar1 = OBJ_nid2obj(type->pkey_type);
      pXVar4->algorithm = pAVar1;
      if (pAVar1 == (ASN1_OBJECT *)0x0) {
        ERR_put_error(0xd,0x80,0xa2,"a_sign.c",0xa5);
LAB_0010de60:
        EVP_MD_CTX_cleanup(&EStack_40);
        return local_44;
      }
      if (pAVar1->length == 0) {
        ERR_put_error(0xd,0x80,0x9a,"a_sign.c",0xaa);
        goto LAB_0010de60;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 2);
  cnt = (*(code *)i2d)(data,0);
  d = CRYPTO_malloc(cnt,"a_sign.c",0xaf);
  len = EVP_PKEY_size(pkey);
  local_44 = len;
  md = (uchar *)CRYPTO_malloc(len,"a_sign.c",0xb1);
  if (d != (void *)0x0 && md != (uchar *)0x0) {
    local_48 = d;
    (*(code *)i2d)(data,&local_48);
    iVar3 = EVP_DigestInit_ex(&EStack_40,type,
                              (ENGINE *)(uint)(d == (void *)0x0 || md == (uchar *)0x0));
    if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&EStack_40,d,cnt), iVar3 == 0)) ||
       (iVar3 = EVP_SignFinal(&EStack_40,md,&local_44,pkey), iVar3 == 0)) {
      local_44 = 0;
      ERR_put_error(0xd,0x80,6,"a_sign.c",0xc1);
    }
    else {
      if (signature->data != (uchar *)0x0) {
        CRYPTO_free(signature->data);
      }
      signature->data = md;
      md = (uchar *)0x0;
      signature->flags = signature->flags & 0xfffffff0U | 8;
      signature->length = local_44;
    }
    EVP_MD_CTX_cleanup(&EStack_40);
  }
  else {
    local_44 = 0;
    ERR_put_error(0xd,0x80,0x41,"a_sign.c",0xb5);
    EVP_MD_CTX_cleanup(&EStack_40);
    if (d == (void *)0x0) goto LAB_0010dda6;
  }
  OPENSSL_cleanse(d,cnt);
  CRYPTO_free(d);
LAB_0010dda6:
  if (md != (uchar *)0x0) {
    OPENSSL_cleanse(md,len);
    CRYPTO_free(md);
  }
  return local_44;
}

