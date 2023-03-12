
BIO * PKCS7_dataDecode(PKCS7 *p7,EVP_PKEY *pkey,BIO *in_bio,X509 *pcert)

{
  pkcs7_st *ppVar1;
  PKCS7_SIGN_ENVELOPE *pPVar2;
  PKCS7_ENC_CONTENT *pPVar3;
  PKCS7_SIGNED *pPVar4;
  int iVar5;
  int iVar6;
  ASN1_OBJECT **ppAVar7;
  BIO_METHOD *pBVar8;
  char *pcVar9;
  EVP_MD *parg;
  void *pvVar10;
  size_t sVar11;
  long lVar12;
  size_t len;
  BIO *bp;
  BIO *b;
  BIO *bp_00;
  uchar *key;
  _STACK *p_Var13;
  uchar *puVar14;
  int in_GS_OFFSET;
  BIO *local_40;
  _STACK *local_3c;
  EVP_CIPHER *local_38;
  ASN1_OCTET_STRING *local_34;
  X509_ALGOR *local_30;
  EVP_CIPHER_CTX *local_2c;
  uchar *local_28;
  size_t local_24;
  int local_20;
  
  local_2c = (EVP_CIPHER_CTX *)0x0;
  local_28 = (uchar *)0x0;
  local_24 = 0;
  local_40 = in_bio;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  if (iVar5 == 0x17) {
    b = (BIO *)0x0;
    local_3c = (_STACK *)((p7->d).enveloped)->recipientinfo;
    pPVar3 = ((p7->d).enveloped)->enc_data;
    local_30 = pPVar3->algorithm;
    local_34 = pPVar3->enc_data;
    iVar5 = OBJ_obj2nid(local_30->algorithm);
    pcVar9 = OBJ_nid2sn(iVar5);
    local_38 = EVP_get_cipherbyname(pcVar9);
    if (local_38 != (EVP_CIPHER *)0x0) goto LAB_0817eac2;
    iVar5 = 0x1d0;
LAB_0817eeed:
    ERR_put_error(0x21,0x70,0x6f,"pk7_doit.c",iVar5);
LAB_0817e832:
    if (local_28 != (uchar *)0x0) {
      len = 0;
      key = (uchar *)0x0;
      bp_00 = (BIO *)0x0;
      bp = (BIO *)0x0;
      b = (BIO *)0x0;
      goto LAB_0817e8f1;
    }
  }
  else {
    if (iVar5 != 0x18) {
      if (iVar5 != 0x16) {
        ERR_put_error(0x21,0x70,0x70,"pk7_doit.c",0x1d5);
        goto LAB_0817e832;
      }
      ppVar1 = ((p7->d).sign)->contents;
      iVar5 = OBJ_obj2nid(ppVar1->type);
      if (iVar5 == 0x15) {
        local_34 = (ppVar1->d).data;
      }
      else {
        iVar5 = OBJ_obj2nid(ppVar1->type);
        if ((iVar5 - 0x15U < 6) || (pPVar4 = (ppVar1->d).sign, pPVar4 == (PKCS7_SIGNED *)0x0)) {
          local_34 = (ASN1_OCTET_STRING *)0x0;
        }
        else {
          local_34 = (ASN1_OCTET_STRING *)0x0;
          if (pPVar4->version == (ASN1_INTEGER *)0x4) {
            local_34 = (ASN1_OCTET_STRING *)pPVar4->md_algs;
          }
        }
      }
      p_Var13 = (_STACK *)((p7->d).sign)->md_algs;
      if (p_Var13 != (_STACK *)0x0) {
        local_3c = (_STACK *)0x0;
        local_30 = (X509_ALGOR *)0x0;
        local_38 = (EVP_CIPHER *)0x0;
        goto LAB_0817e9d3;
      }
      len = 0;
      bp_00 = (BIO *)0x0;
LAB_0817ed12:
      iVar5 = OBJ_obj2nid(p7->type);
      if (((iVar5 != 0x16) || (lVar12 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar12 == 0)) &&
         (in_bio == (BIO *)0x0)) {
        if (local_34->length < 1) {
          pBVar8 = BIO_s_mem();
          local_40 = BIO_new(pBVar8);
          BIO_ctrl(local_40,0x82,0,(void *)0x0);
        }
        else {
          local_40 = BIO_new_mem_buf(local_34->data,local_34->length);
        }
        if (local_40 == (BIO *)0x0) {
          bp = (BIO *)0x0;
          b = bp_00;
          bp_00 = (BIO *)0x0;
          goto LAB_0817e8e7;
        }
      }
      BIO_push(bp_00,local_40);
      goto LAB_0817e95e;
    }
    pPVar2 = (p7->d).signed_and_enveloped;
    local_3c = (_STACK *)pPVar2->recipientinfo;
    p_Var13 = (_STACK *)pPVar2->md_algs;
    local_34 = pPVar2->enc_data->enc_data;
    local_30 = pPVar2->enc_data->algorithm;
    iVar5 = OBJ_obj2nid(local_30->algorithm);
    pcVar9 = OBJ_nid2sn(iVar5);
    local_38 = EVP_get_cipherbyname(pcVar9);
    if (local_38 == (EVP_CIPHER *)0x0) {
      iVar5 = 0x1c5;
      goto LAB_0817eeed;
    }
    if (p_Var13 == (_STACK *)0x0) {
      b = (BIO *)0x0;
    }
    else {
LAB_0817e9d3:
      b = (BIO *)0x0;
      for (iVar5 = 0; iVar6 = sk_num(p_Var13), iVar5 < iVar6; iVar5 = iVar5 + 1) {
        ppAVar7 = (ASN1_OBJECT **)sk_value(p_Var13,iVar5);
        pBVar8 = BIO_f_md();
        bp = BIO_new(pBVar8);
        if (bp == (BIO *)0x0) {
          ERR_put_error(0x21,0x70,0x20,"pk7_doit.c",0x1e1);
          len = 0;
          bp_00 = (BIO *)0x0;
          goto LAB_0817e8e7;
        }
        iVar6 = OBJ_obj2nid(*ppAVar7);
        pcVar9 = OBJ_nid2sn(iVar6);
        parg = EVP_get_digestbyname(pcVar9);
        if (parg == (EVP_MD *)0x0) {
          ERR_put_error(0x21,0x70,0x6d,"pk7_doit.c",0x1e9);
          len = 0;
          bp_00 = (BIO *)0x0;
          goto LAB_0817e8e7;
        }
        BIO_ctrl(bp,0x6f,0,parg);
        if (b != (BIO *)0x0) {
          BIO_push(b,bp);
          bp = b;
        }
        b = bp;
      }
      len = 0;
      bp_00 = b;
      if (local_38 == (EVP_CIPHER *)0x0) goto LAB_0817ed12;
    }
LAB_0817eac2:
    pBVar8 = BIO_f_cipher();
    bp_00 = BIO_new(pBVar8);
    if (bp_00 == (BIO *)0x0) {
      bp = (BIO *)0x0;
      ERR_put_error(0x21,0x70,0x20,"pk7_doit.c",0x203);
      len = 0;
LAB_0817e8e7:
      key = (uchar *)0x0;
      if (local_28 != (uchar *)0x0) {
LAB_0817e8f1:
        OPENSSL_cleanse(local_28,local_24);
        CRYPTO_free(local_28);
LAB_0817e913:
        if (key != (uchar *)0x0) goto LAB_0817e917;
      }
    }
    else {
      iVar5 = 0;
      if (pcert != (X509 *)0x0) {
        for (; iVar6 = sk_num(local_3c), iVar5 < iVar6; iVar5 = iVar5 + 1) {
          pvVar10 = sk_value(local_3c,iVar5);
          iVar6 = X509_NAME_cmp(**(X509_NAME ***)((int)pvVar10 + 4),pcert->cert_info->issuer);
          if ((iVar6 == 0) &&
             (iVar6 = ASN1_STRING_cmp(pcert->cert_info->serialNumber,
                                      *(ASN1_STRING **)(*(int *)((int)pvVar10 + 4) + 4)), iVar6 == 0
             )) {
            iVar5 = pkcs7_decrypt_rinfo(pkey);
            if (iVar5 < 0) goto LAB_0817ed70;
            ERR_clear_error();
            goto LAB_0817eb85;
          }
        }
        bp = (BIO *)0x0;
        ERR_put_error(0x21,0x70,0x73,"pk7_doit.c",0x21a);
        len = 0;
        goto LAB_0817e8e7;
      }
      for (; iVar6 = sk_num(local_3c), iVar5 < iVar6; iVar5 = iVar5 + 1) {
        sk_value(local_3c,iVar5);
        iVar6 = pkcs7_decrypt_rinfo(pkey);
        if (iVar6 < 0) {
          len = 0;
          bp = (BIO *)0x0;
          goto LAB_0817e8e7;
        }
        ERR_clear_error();
      }
LAB_0817eb85:
      local_2c = (EVP_CIPHER_CTX *)0x0;
      BIO_ctrl(bp_00,0x81,0,&local_2c);
      iVar5 = EVP_CipherInit_ex(local_2c,local_38,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,0);
      if ((iVar5 < 1) || (iVar5 = EVP_CIPHER_asn1_to_param(local_2c,local_30->parameter), iVar5 < 0)
         ) {
LAB_0817ed70:
        len = 0;
LAB_0817ed72:
        bp = (BIO *)0x0;
        goto LAB_0817e8e7;
      }
      len = EVP_CIPHER_CTX_key_length(local_2c);
      key = (uchar *)CRYPTO_malloc(len,"pk7_doit.c",0x240);
      if (key == (uchar *)0x0) goto LAB_0817ed72;
      iVar5 = EVP_CIPHER_CTX_rand_key(local_2c,key);
      if (0 < iVar5) {
        puVar14 = key;
        if (local_28 == (uchar *)0x0) {
          puVar14 = (uchar *)0x0;
          local_28 = key;
          local_24 = len;
        }
        sVar11 = EVP_CIPHER_CTX_key_length(local_2c);
        key = puVar14;
        if ((sVar11 != local_24) &&
           (iVar5 = EVP_CIPHER_CTX_set_key_length(local_2c,local_24), iVar5 == 0)) {
          OPENSSL_cleanse(local_28,local_24);
          CRYPTO_free(local_28);
          key = (uchar *)0x0;
          local_28 = puVar14;
          local_24 = len;
        }
        ERR_clear_error();
        iVar5 = EVP_CipherInit_ex(local_2c,(EVP_CIPHER *)0x0,(ENGINE *)0x0,local_28,(uchar *)0x0,0);
        if (0 < iVar5) {
          if (local_28 != (uchar *)0x0) {
            OPENSSL_cleanse(local_28,local_24);
            CRYPTO_free(local_28);
            local_28 = (uchar *)0x0;
          }
          if (key != (uchar *)0x0) {
            OPENSSL_cleanse(key,len);
            CRYPTO_free(key);
          }
          if (b != (BIO *)0x0) {
            BIO_push(b,bp_00);
            bp_00 = b;
          }
          goto LAB_0817ed12;
        }
        bp = (BIO *)0x0;
        if (local_28 != (uchar *)0x0) goto LAB_0817e8f1;
        goto LAB_0817e913;
      }
      bp = (BIO *)0x0;
      if (local_28 != (uchar *)0x0) goto LAB_0817e8f1;
LAB_0817e917:
      OPENSSL_cleanse(key,len);
      CRYPTO_free(key);
    }
    if (b != (BIO *)0x0) {
      BIO_free_all(b);
    }
    if (bp != (BIO *)0x0) {
      BIO_free_all(bp);
    }
    if (bp_00 == (BIO *)0x0) goto LAB_0817e95e;
    BIO_free_all(bp_00);
  }
  bp_00 = (BIO *)0x0;
LAB_0817e95e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bp_00;
}

