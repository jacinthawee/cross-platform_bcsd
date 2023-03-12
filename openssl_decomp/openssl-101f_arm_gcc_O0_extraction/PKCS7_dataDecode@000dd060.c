
BIO * PKCS7_dataDecode(PKCS7 *p7,EVP_PKEY *pkey,BIO *in_bio,X509 *pcert)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  BIO_METHOD *pBVar3;
  char *pcVar4;
  EVP_MD *pEVar5;
  EVP_MD *bp;
  void *pvVar6;
  EVP_MD *key;
  EVP_MD *pEVar7;
  long lVar8;
  int iVar9;
  PKCS7_SIGN_ENVELOPE *pPVar10;
  PKCS7_ENC_CONTENT *pPVar11;
  pkcs7_st *ppVar12;
  int iVar13;
  EVP_MD *b;
  EVP_MD *pEVar14;
  EVP_MD *pEVar15;
  _STACK *p_Var16;
  EVP_MD *local_4c;
  X509_ALGOR *local_48;
  EVP_MD *local_44;
  ASN1_OCTET_STRING *local_3c;
  EVP_CIPHER_CTX *local_34;
  EVP_MD *local_30;
  EVP_MD *local_2c [2];
  
  b = (EVP_MD *)0x0;
  local_34 = (EVP_CIPHER_CTX *)0x0;
  local_30 = (EVP_MD *)0x0;
  local_2c[0] = (EVP_MD *)0x0;
  iVar1 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  if (iVar1 == 0x17) {
    pPVar11 = ((p7->d).enveloped)->enc_data;
    p_Var16 = (_STACK *)((p7->d).enveloped)->recipientinfo;
    local_48 = pPVar11->algorithm;
    local_3c = pPVar11->enc_data;
    iVar1 = OBJ_obj2nid(local_48->algorithm);
    pcVar4 = OBJ_nid2sn(iVar1);
    local_4c = (EVP_MD *)EVP_get_cipherbyname(pcVar4);
    if (local_4c == (EVP_MD *)0x0) {
      iVar1 = 0x1d0;
LAB_000dd1dc:
      iVar9 = 0x6f;
LAB_000dd0a6:
      ERR_put_error(0x21,0x70,iVar9,"pk7_doit.c",iVar1);
      local_44 = local_4c;
      pEVar5 = local_4c;
      b = local_4c;
      pEVar14 = local_4c;
      key = local_4c;
      goto LAB_000dd0b2;
    }
LAB_000dd20e:
    pBVar3 = BIO_f_cipher();
    bp = (EVP_MD *)BIO_new(pBVar3);
    pEVar5 = bp;
    if (bp == (EVP_MD *)0x0) {
      ERR_put_error(0x21,0x70,0x20,"pk7_doit.c",0x203);
      local_44 = bp;
      pEVar14 = bp;
      key = bp;
      goto LAB_000dd0b2;
    }
    if (pcert == (X509 *)0x0) {
      while( true ) {
        iVar1 = sk_num(p_Var16);
        if (iVar1 <= (int)pcert) break;
        pvVar6 = sk_value(p_Var16,(int)pcert);
        iVar1 = pkcs7_decrypt_rinfo(&local_30,local_2c,pvVar6,pkey);
        if (iVar1 < 0) {
          local_44 = (EVP_MD *)0x0;
          pEVar14 = (EVP_MD *)0x0;
          key = (EVP_MD *)0x0;
          goto LAB_000dd0b2;
        }
        ERR_clear_error();
        pcert = (X509 *)((int)&pcert->cert_info + 1);
      }
    }
    else {
      iVar1 = 0;
      do {
        iVar9 = sk_num(p_Var16);
        iVar13 = iVar1 + 1;
        if (iVar9 <= iVar1) {
          ERR_put_error(0x21,0x70,0x73,"pk7_doit.c",0x21a);
          local_44 = (EVP_MD *)0x0;
          pEVar14 = (EVP_MD *)0x0;
          key = (EVP_MD *)0x0;
          goto LAB_000dd0b2;
        }
        pvVar6 = sk_value(p_Var16,iVar1);
        iVar9 = X509_NAME_cmp(**(X509_NAME ***)((int)pvVar6 + 4),pcert->cert_info->issuer);
        iVar1 = iVar13;
      } while ((iVar9 != 0) ||
              (pEVar14 = (EVP_MD *)
                         ASN1_STRING_cmp(pcert->cert_info->serialNumber,
                                         *(ASN1_STRING **)(*(int *)((int)pvVar6 + 4) + 4)),
              pEVar14 != (EVP_MD *)0x0));
      iVar1 = pkcs7_decrypt_rinfo(&local_30,local_2c,pvVar6,pkey);
      local_44 = pEVar14;
      key = pEVar14;
      if (iVar1 < 0) goto LAB_000dd0b2;
      ERR_clear_error();
    }
    local_34 = (EVP_CIPHER_CTX *)0x0;
    BIO_ctrl((BIO *)bp,0x81,0,&local_34);
    iVar1 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)local_4c,(ENGINE *)0x0,(uchar *)0x0,
                              (uchar *)0x0,0);
    if ((iVar1 < 1) || (iVar1 = EVP_CIPHER_asn1_to_param(local_34,local_48->parameter), iVar1 < 0))
    {
      local_44 = (EVP_MD *)0x0;
      pEVar14 = (EVP_MD *)0x0;
      key = (EVP_MD *)0x0;
      goto LAB_000dd0b2;
    }
    pEVar14 = (EVP_MD *)EVP_CIPHER_CTX_key_length(local_34);
    key = (EVP_MD *)CRYPTO_malloc((int)pEVar14,"pk7_doit.c",0x240);
    local_44 = key;
    if ((key == (EVP_MD *)0x0) ||
       (iVar1 = EVP_CIPHER_CTX_rand_key(local_34,(uchar *)key), local_44 = (EVP_MD *)0x0, iVar1 < 1)
       ) goto LAB_000dd0b2;
    pEVar15 = key;
    if (local_30 == (EVP_MD *)0x0) {
      pEVar15 = local_30;
      local_30 = key;
      local_2c[0] = pEVar14;
    }
    pEVar7 = (EVP_MD *)EVP_CIPHER_CTX_key_length(local_34);
    key = pEVar15;
    if ((pEVar7 != local_2c[0]) &&
       (pEVar7 = (EVP_MD *)EVP_CIPHER_CTX_set_key_length(local_34,(int)local_2c[0]),
       pEVar7 == (EVP_MD *)0x0)) {
      OPENSSL_cleanse(local_30,(size_t)local_2c[0]);
      CRYPTO_free(local_30);
      key = pEVar7;
      local_30 = pEVar15;
      local_2c[0] = pEVar14;
    }
    ERR_clear_error();
    iVar1 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)local_30,
                              (uchar *)0x0,0);
    local_44 = (EVP_MD *)0x0;
    if (iVar1 < 1) goto LAB_000dd0b2;
    if (local_30 != (EVP_MD *)0x0) {
      OPENSSL_cleanse(local_30,(size_t)local_2c[0]);
      CRYPTO_free(local_30);
      local_30 = (EVP_MD *)0x0;
    }
    if (key != (EVP_MD *)0x0) {
      OPENSSL_cleanse(key,(size_t)pEVar14);
      CRYPTO_free(key);
    }
    if (b != (EVP_MD *)0x0) {
      BIO_push((BIO *)b,(BIO *)bp);
      bp = b;
    }
  }
  else {
    if (iVar1 == 0x18) {
      pPVar10 = (p7->d).signed_and_enveloped;
      p_Var16 = (_STACK *)pPVar10->recipientinfo;
      pEVar14 = (EVP_MD *)pPVar10->md_algs;
      local_48 = pPVar10->enc_data->algorithm;
      local_3c = pPVar10->enc_data->enc_data;
      iVar1 = OBJ_obj2nid(local_48->algorithm);
      pcVar4 = OBJ_nid2sn(iVar1);
      local_4c = (EVP_MD *)EVP_get_cipherbyname(pcVar4);
      if (local_4c == (EVP_MD *)0x0) {
        iVar1 = 0x1c5;
        goto LAB_000dd1dc;
      }
    }
    else {
      if (iVar1 != 0x16) {
        local_4c = (EVP_MD *)0x0;
        iVar9 = 0x70;
        iVar1 = 0x1d5;
        goto LAB_000dd0a6;
      }
      ppVar12 = ((p7->d).sign)->contents;
      iVar1 = OBJ_obj2nid(ppVar12->type);
      if (iVar1 == 0x15) {
        local_3c = (ppVar12->d).data;
      }
      else {
        iVar1 = OBJ_obj2nid(ppVar12->type);
        if (iVar1 - 0x15U < 6) {
LAB_000dd40e:
          local_3c = (ASN1_OCTET_STRING *)0x0;
        }
        else {
          local_3c = (ppVar12->d).data;
          if (local_3c != (ASN1_OCTET_STRING *)0x0) {
            if (local_3c->length != 4) goto LAB_000dd40e;
            local_3c = (ASN1_OCTET_STRING *)local_3c->type;
          }
        }
      }
      p_Var16 = (_STACK *)0x0;
      local_48 = (X509_ALGOR *)0x0;
      local_4c = (EVP_MD *)0x0;
      pEVar14 = (EVP_MD *)((p7->d).sign)->md_algs;
    }
    b = pEVar14;
    if (pEVar14 != (EVP_MD *)0x0) {
      b = (EVP_MD *)0x0;
      for (iVar1 = 0; iVar9 = sk_num((_STACK *)pEVar14), iVar1 < iVar9; iVar1 = iVar1 + 1) {
        ppAVar2 = (ASN1_OBJECT **)sk_value((_STACK *)pEVar14,iVar1);
        pBVar3 = BIO_f_md();
        local_44 = (EVP_MD *)BIO_new(pBVar3);
        if (local_44 == (EVP_MD *)0x0) {
          ERR_put_error(0x21,0x70,0x20,"pk7_doit.c",0x1e1);
          pEVar5 = local_44;
          pEVar14 = local_44;
          key = local_44;
          goto LAB_000dd0b2;
        }
        iVar9 = OBJ_obj2nid(*ppAVar2);
        pcVar4 = OBJ_nid2sn(iVar9);
        pEVar5 = EVP_get_digestbyname(pcVar4);
        if (pEVar5 == (EVP_MD *)0x0) {
          ERR_put_error(0x21,0x70,0x6d,"pk7_doit.c",0x1e9);
          pEVar14 = pEVar5;
          key = pEVar5;
          goto LAB_000dd0b2;
        }
        BIO_ctrl((BIO *)local_44,0x6f,0,pEVar5);
        if (b != (EVP_MD *)0x0) {
          BIO_push((BIO *)b,(BIO *)local_44);
          local_44 = b;
        }
        b = local_44;
      }
    }
    bp = b;
    pEVar14 = local_4c;
    if (local_4c != (EVP_MD *)0x0) goto LAB_000dd20e;
  }
  iVar1 = OBJ_obj2nid(p7->type);
  local_44 = (EVP_MD *)in_bio;
  if (((iVar1 != 0x16) || (lVar8 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar8 == 0)) &&
     (in_bio == (BIO *)0x0)) {
    if (local_3c->length < 1) {
      pBVar3 = BIO_s_mem();
      local_44 = (EVP_MD *)BIO_new(pBVar3);
      BIO_ctrl((BIO *)local_44,0x82,0,(void *)0x0);
    }
    else {
      local_44 = (EVP_MD *)BIO_new_mem_buf(local_3c->data,local_3c->length);
    }
    pEVar5 = local_44;
    b = bp;
    key = local_44;
    if (local_44 == (EVP_MD *)0x0) {
LAB_000dd0b2:
      if (local_30 != (EVP_MD *)0x0) {
        OPENSSL_cleanse(local_30,(size_t)local_2c[0]);
        CRYPTO_free(local_30);
      }
      if (key != (EVP_MD *)0x0) {
        OPENSSL_cleanse(key,(size_t)pEVar14);
        CRYPTO_free(key);
      }
      if (b != (EVP_MD *)0x0) {
        BIO_free_all((BIO *)b);
      }
      if (local_44 != (EVP_MD *)0x0) {
        BIO_free_all((BIO *)local_44);
      }
      if (pEVar5 != (EVP_MD *)0x0) {
        BIO_free_all((BIO *)pEVar5);
      }
      return (BIO *)0x0;
    }
  }
  BIO_push((BIO *)bp,(BIO *)local_44);
  return (BIO *)bp;
}

