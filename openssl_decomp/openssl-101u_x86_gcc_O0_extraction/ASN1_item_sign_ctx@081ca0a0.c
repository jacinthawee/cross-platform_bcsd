
int ASN1_item_sign_ctx(ASN1_ITEM *it,X509_ALGOR *algor1,X509_ALGOR *algor2,
                      ASN1_BIT_STRING *signature,void *asn,EVP_MD_CTX *ctx)

{
  EVP_MD *md;
  EVP_PKEY *pkey;
  int iVar1;
  size_t cnt;
  size_t len;
  uchar *sigret;
  size_t sVar2;
  int *piVar3;
  ASN1_OBJECT *pAVar4;
  int iVar5;
  uint ptype;
  int in_GS_OFFSET;
  uchar *local_2c;
  size_t local_28;
  int local_24;
  int local_20;
  
  local_2c = (uchar *)0x0;
  local_28 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  md = EVP_MD_CTX_md(ctx);
  pkey = EVP_PKEY_CTX_get0_pkey(ctx->pctx);
  if ((md == (EVP_MD *)0x0) || (pkey == (EVP_PKEY *)0x0)) {
    iVar5 = 0xf7;
    iVar1 = 0xd9;
LAB_081ca322:
    ERR_put_error(0xd,0xdc,iVar1,"a_sign.c",iVar5);
    sVar2 = 0;
    goto LAB_081ca280;
  }
  piVar3 = (int *)pkey->ameth;
  if ((code *)piVar3[0x1a] == (code *)0x0) {
    if ((*(byte *)&md->flags & 4) == 0) {
LAB_081ca2aa:
      local_24 = md->pkey_type;
    }
    else {
LAB_081ca370:
      iVar1 = *piVar3;
      iVar5 = EVP_MD_type(md);
      iVar1 = OBJ_find_sigid_by_algs(&local_24,iVar5,iVar1);
      if (iVar1 == 0) {
LAB_081ca430:
        iVar5 = 0x114;
        iVar1 = 0xc6;
        goto LAB_081ca322;
      }
      piVar3 = (int *)pkey->ameth;
    }
    ptype = -(uint)((piVar3[2] & 4U) == 0) | 5;
    if (algor1 != (X509_ALGOR *)0x0) {
      pAVar4 = OBJ_nid2obj(local_24);
      X509_ALGOR_set0(algor1,pAVar4,ptype,(void *)0x0);
    }
    if (algor2 != (X509_ALGOR *)0x0) {
      pAVar4 = OBJ_nid2obj(local_24);
      X509_ALGOR_set0(algor2,pAVar4,ptype,(void *)0x0);
    }
LAB_081ca153:
    cnt = ASN1_item_i2d((ASN1_VALUE *)asn,&local_2c,it);
    len = EVP_PKEY_size(pkey);
    local_28 = len;
    sigret = (uchar *)CRYPTO_malloc(len,"a_sign.c",0x128);
    if ((sigret == (uchar *)0x0) || (local_2c == (uchar *)0x0)) {
      local_28 = 0;
      ERR_put_error(0xd,0xdc,0x41,"a_sign.c",299);
      EVP_MD_CTX_cleanup(ctx);
      if (local_2c != (uchar *)0x0) goto LAB_081ca213;
      goto LAB_081ca22a;
    }
    iVar1 = EVP_DigestUpdate(ctx,local_2c,cnt);
    if ((iVar1 != 0) && (iVar1 = EVP_DigestSignFinal(ctx,sigret,&local_28), iVar1 != 0)) {
      if (signature->data != (uchar *)0x0) {
        CRYPTO_free(signature->data);
      }
      signature->length = local_28;
      signature->data = sigret;
      signature->flags = signature->flags & 0xfffffff0U | 8;
      goto LAB_081ca1fd;
    }
    local_28 = 0;
    ERR_put_error(0xd,0xdc,6,"a_sign.c",0x132);
    EVP_MD_CTX_cleanup(ctx);
    if (local_2c != (uchar *)0x0) goto LAB_081ca213;
  }
  else {
    iVar1 = (*(code *)piVar3[0x1a])(ctx,it,asn,algor1,algor2,signature);
    if (iVar1 == 1) {
      len = 0;
      cnt = 0;
      local_28 = signature->length;
LAB_081ca1fd:
      EVP_MD_CTX_cleanup(ctx);
      sVar2 = local_28;
      if (local_2c == (uchar *)0x0) goto LAB_081ca280;
      sigret = (uchar *)0x0;
    }
    else {
      if (0 < iVar1) {
        if (iVar1 == 2) {
          piVar3 = (int *)pkey->ameth;
          if ((*(byte *)&md->flags & 4) != 0) {
            if (piVar3 != (int *)0x0) goto LAB_081ca370;
            goto LAB_081ca430;
          }
          goto LAB_081ca2aa;
        }
        goto LAB_081ca153;
      }
      ERR_put_error(0xd,0xdc,6,"a_sign.c",0x107);
      EVP_MD_CTX_cleanup(ctx);
      sVar2 = local_28;
      if (local_2c == (uchar *)0x0) goto LAB_081ca280;
      len = 0;
      cnt = 0;
      sigret = (uchar *)0x0;
    }
LAB_081ca213:
    OPENSSL_cleanse(local_2c,cnt);
    CRYPTO_free(local_2c);
LAB_081ca22a:
    sVar2 = local_28;
    if (sigret == (uchar *)0x0) goto LAB_081ca280;
  }
  OPENSSL_cleanse(sigret,len);
  CRYPTO_free(sigret);
  sVar2 = local_28;
LAB_081ca280:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return sVar2;
}

