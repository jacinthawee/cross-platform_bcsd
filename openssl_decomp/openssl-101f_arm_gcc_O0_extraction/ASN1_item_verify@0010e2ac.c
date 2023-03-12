
int ASN1_item_verify(ASN1_ITEM *it,X509_ALGOR *algor1,ASN1_BIT_STRING *signature,void *data,
                    EVP_PKEY *pkey)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  int iVar2;
  code *pcVar3;
  uchar *local_44;
  int local_40;
  int local_3c;
  EVP_MD_CTX EStack_38;
  
  local_44 = (uchar *)0x0;
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0xd,0xc5,0x43,"a_verify.c",0x91);
    return -1;
  }
  EVP_MD_CTX_init(&EStack_38);
  iVar1 = OBJ_obj2nid(algor1->algorithm);
  iVar1 = OBJ_find_sigid_algs(iVar1,&local_40,&local_3c);
  iVar2 = 0x9a;
  if (iVar1 == 0) {
LAB_0010e318:
    iVar1 = -1;
    ERR_put_error(0xd,0xc5,199,"a_verify.c",iVar2);
  }
  else {
    if (local_40 == 0) {
      if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
         (pcVar3 = *(code **)(pkey->ameth + 100), pcVar3 == (code *)0x0)) {
        iVar2 = 0xa1;
        goto LAB_0010e318;
      }
      iVar1 = (*pcVar3)(&EStack_38,it,data,algor1,signature,pkey);
      if (iVar1 != 2) goto LAB_0010e304;
LAB_0010e37e:
      cnt = ASN1_item_i2d((ASN1_VALUE *)data,&local_44,it);
      if (local_44 == (uchar *)0x0) {
        iVar1 = -1;
        ERR_put_error(0xd,0xc5,0x41,"a_verify.c",0xcc);
        goto LAB_0010e304;
      }
      iVar1 = EVP_DigestUpdate(&EStack_38,local_44,cnt);
      if (iVar1 != 0) {
        OPENSSL_cleanse(local_44,cnt);
        CRYPTO_free(local_44);
        iVar1 = EVP_DigestVerifyFinal(&EStack_38,signature->data,signature->length);
        if (iVar1 < 1) {
          iVar1 = 0;
          ERR_put_error(0xd,0xc5,6,"a_verify.c",0xdd);
        }
        else {
          iVar1 = 1;
        }
        goto LAB_0010e304;
      }
      iVar2 = 0xd2;
    }
    else {
      name = OBJ_nid2sn(local_40);
      type = EVP_get_digestbyname(name);
      if (type == (EVP_MD *)0x0) {
        iVar1 = -1;
        ERR_put_error(0xd,0xc5,0xa1,"a_verify.c",0xb4);
        goto LAB_0010e304;
      }
      iVar1 = EVP_PKEY_type(local_3c);
      if (iVar1 != *(int *)pkey->ameth) {
        iVar1 = -1;
        ERR_put_error(0xd,0xc5,200,"a_verify.c",0xbb);
        goto LAB_0010e304;
      }
      iVar1 = EVP_DigestVerifyInit(&EStack_38,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
      iVar2 = 0xc1;
      if (iVar1 != 0) goto LAB_0010e37e;
    }
    ERR_put_error(0xd,0xc5,6,"a_verify.c",iVar2);
  }
LAB_0010e304:
  EVP_MD_CTX_cleanup(&EStack_38);
  return iVar1;
}

