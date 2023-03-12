
BIO * PKCS7_dataDecode(PKCS7 *p7,EVP_PKEY *pkey,BIO *in_bio,X509 *pcert)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  BIO_METHOD *pBVar3;
  EVP_MD *pEVar4;
  char *pcVar5;
  EVP_MD *pEVar6;
  EVP_MD *bp;
  void *pvVar7;
  EVP_MD *pEVar8;
  long lVar9;
  int iVar10;
  PKCS7_SIGN_ENVELOPE *pPVar11;
  PKCS7_ENC_CONTENT *pPVar12;
  int iVar13;
  EVP_MD *pEVar14;
  pkcs7_st *ppVar15;
  EVP_MD *pEVar16;
  EVP_MD *pEVar17;
  _STACK *p_Var18;
  EVP_MD *local_48;
  EVP_MD *local_44;
  X509_ALGOR *local_40;
  EVP_CIPHER_CTX *local_34;
  EVP_MD *local_30;
  EVP_MD *local_2c [2];
  
  local_34 = (EVP_CIPHER_CTX *)0x0;
  local_30 = (EVP_MD *)0x0;
  local_2c[0] = (EVP_MD *)0x0;
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x70,0x8f,"pk7_doit.c",0x1b2);
    return (BIO *)0x0;
  }
  if ((p7->d).ptr == (char *)0x0) {
    ERR_put_error(0x21,0x70,0x7a,"pk7_doit.c",0x1b7);
    return (BIO *)0x0;
  }
  iVar1 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  if (iVar1 == 0x17) {
    pPVar12 = ((p7->d).enveloped)->enc_data;
    p_Var18 = (_STACK *)((p7->d).enveloped)->recipientinfo;
    local_40 = pPVar12->algorithm;
    pEVar4 = (EVP_MD *)pPVar12->enc_data;
    iVar1 = OBJ_obj2nid(local_40->algorithm);
    pcVar5 = OBJ_nid2sn(iVar1);
    local_48 = (EVP_MD *)EVP_get_cipherbyname(pcVar5);
    iVar1 = 0x1e3;
    if (local_48 != (EVP_MD *)0x0) {
      if ((in_bio != (BIO *)0x0) || (pEVar4 != (EVP_MD *)0x0)) {
        pEVar16 = (EVP_MD *)0x0;
        local_44 = local_48;
        goto LAB_000db05c;
      }
      goto LAB_000db1fa;
    }
LAB_000db2a2:
    iVar10 = 0x6f;
  }
  else {
    if (iVar1 == 0x18) {
      pPVar11 = (p7->d).signed_and_enveloped;
      p_Var18 = (_STACK *)pPVar11->recipientinfo;
      pEVar17 = (EVP_MD *)pPVar11->md_algs;
      local_40 = pPVar11->enc_data->algorithm;
      pEVar4 = (EVP_MD *)pPVar11->enc_data->enc_data;
      iVar1 = OBJ_obj2nid(local_40->algorithm);
      pcVar5 = OBJ_nid2sn(iVar1);
      local_48 = (EVP_MD *)EVP_get_cipherbyname(pcVar5);
      local_44 = local_48;
      if (local_48 == (EVP_MD *)0x0) {
        iVar1 = 0x1d7;
        goto LAB_000db2a2;
      }
    }
    else {
      if (iVar1 != 0x16) {
        local_48 = (EVP_MD *)0x0;
        iVar10 = 0x70;
        iVar1 = 0x1e8;
        goto LAB_000daece;
      }
      ppVar15 = ((p7->d).sign)->contents;
      iVar1 = OBJ_obj2nid(ppVar15->type);
      if (iVar1 == 0x15) {
        local_48 = (EVP_MD *)(ppVar15->d).data;
      }
      else {
        iVar1 = OBJ_obj2nid(ppVar15->type);
        if (iVar1 - 0x15U < 6) {
LAB_000db250:
          local_48 = (EVP_MD *)0x0;
        }
        else {
          local_48 = (EVP_MD *)(ppVar15->d).data;
          if (local_48 != (EVP_MD *)0x0) {
            if ((BIO_METHOD *)local_48->type != (BIO_METHOD *)0x4) goto LAB_000db250;
            local_48 = (EVP_MD *)local_48->pkey_type;
          }
        }
      }
      iVar1 = OBJ_obj2nid(p7->type);
      if (((iVar1 != 0x16) || (lVar9 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar9 == 0)) &&
         (local_48 == (EVP_MD *)0x0)) {
        iVar1 = 0x1c9;
        iVar10 = 0x9b;
        goto LAB_000daece;
      }
      p_Var18 = (_STACK *)0x0;
      local_40 = (X509_ALGOR *)0x0;
      local_44 = (EVP_MD *)0x0;
      pEVar17 = (EVP_MD *)((p7->d).sign)->md_algs;
      pEVar4 = local_48;
    }
    local_48 = pEVar4;
    if (local_48 != (EVP_MD *)0x0 || in_bio != (BIO *)0x0) {
      pEVar14 = (EVP_MD *)0x0;
      pEVar16 = pEVar14;
      bp = pEVar17;
      if (pEVar17 != (EVP_MD *)0x0) {
        for (; iVar1 = sk_num((_STACK *)pEVar17), bp = pEVar16, (int)pEVar14 < iVar1;
            pEVar14 = (EVP_MD *)((int)&pEVar14->type + 1)) {
          ppAVar2 = (ASN1_OBJECT **)sk_value((_STACK *)pEVar17,(int)pEVar14);
          pBVar3 = BIO_f_md();
          pEVar4 = (EVP_MD *)BIO_new(pBVar3);
          if (pEVar4 == (EVP_MD *)0x0) {
            ERR_put_error(0x21,0x70,0x20,"pk7_doit.c",0x1f7);
            pEVar6 = pEVar4;
            pEVar17 = pEVar4;
            pEVar14 = pEVar4;
            goto LAB_000daeda;
          }
          iVar1 = OBJ_obj2nid(*ppAVar2);
          pcVar5 = OBJ_nid2sn(iVar1);
          pEVar6 = EVP_get_digestbyname(pcVar5);
          if (pEVar6 == (EVP_MD *)0x0) {
            ERR_put_error(0x21,0x70,0x6d,"pk7_doit.c",0x1ff);
            pEVar17 = pEVar6;
            pEVar14 = pEVar6;
            goto LAB_000daeda;
          }
          BIO_ctrl((BIO *)pEVar4,0x6f,0,pEVar6);
          if (pEVar16 != (EVP_MD *)0x0) {
            BIO_push((BIO *)pEVar16,(BIO *)pEVar4);
            pEVar4 = pEVar16;
          }
          pEVar16 = pEVar4;
        }
      }
      pEVar16 = bp;
      pEVar17 = local_44;
      pEVar4 = local_48;
      if (local_44 != (EVP_MD *)0x0) {
LAB_000db05c:
        local_48 = pEVar4;
        pBVar3 = BIO_f_cipher();
        bp = (EVP_MD *)BIO_new(pBVar3);
        pEVar6 = bp;
        if (bp == (EVP_MD *)0x0) {
          ERR_put_error(0x21,0x70,0x20,"pk7_doit.c",0x217);
          pEVar4 = bp;
          pEVar17 = bp;
          pEVar14 = bp;
          goto LAB_000daeda;
        }
        if (pcert == (X509 *)0x0) {
          while( true ) {
            iVar1 = sk_num(p_Var18);
            if (iVar1 <= (int)pcert) break;
            pvVar7 = sk_value(p_Var18,(int)pcert);
            iVar1 = pkcs7_decrypt_rinfo(&local_30,local_2c,pvVar7,pkey);
            if (iVar1 < 0) {
              pEVar4 = (EVP_MD *)0x0;
              pEVar17 = (EVP_MD *)0x0;
              pEVar14 = (EVP_MD *)0x0;
              goto LAB_000daeda;
            }
            ERR_clear_error();
            pcert = (X509 *)((int)&pcert->cert_info + 1);
          }
        }
        else {
          iVar1 = 0;
          do {
            iVar10 = sk_num(p_Var18);
            iVar13 = iVar1 + 1;
            if (iVar10 <= iVar1) {
              ERR_put_error(0x21,0x70,0x73,"pk7_doit.c",0x22e);
              pEVar4 = (EVP_MD *)0x0;
              pEVar17 = (EVP_MD *)0x0;
              pEVar14 = (EVP_MD *)0x0;
              goto LAB_000daeda;
            }
            pvVar7 = sk_value(p_Var18,iVar1);
            iVar10 = X509_NAME_cmp(**(X509_NAME ***)((int)pvVar7 + 4),pcert->cert_info->issuer);
            iVar1 = iVar13;
          } while ((iVar10 != 0) ||
                  (pEVar17 = (EVP_MD *)
                             ASN1_STRING_cmp(pcert->cert_info->serialNumber,
                                             *(ASN1_STRING **)(*(int *)((int)pvVar7 + 4) + 4)),
                  pEVar17 != (EVP_MD *)0x0));
          iVar1 = pkcs7_decrypt_rinfo(&local_30,local_2c,pvVar7,pkey);
          pEVar4 = pEVar17;
          pEVar14 = pEVar17;
          if (iVar1 < 0) goto LAB_000daeda;
          ERR_clear_error();
        }
        local_34 = (EVP_CIPHER_CTX *)0x0;
        BIO_ctrl((BIO *)bp,0x81,0,&local_34);
        iVar1 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)local_44,(ENGINE *)0x0,(uchar *)0x0,
                                  (uchar *)0x0,0);
        if ((iVar1 < 1) ||
           (iVar1 = EVP_CIPHER_asn1_to_param(local_34,local_40->parameter), iVar1 < 0)) {
          pEVar4 = (EVP_MD *)0x0;
          pEVar17 = (EVP_MD *)0x0;
          pEVar14 = (EVP_MD *)0x0;
          goto LAB_000daeda;
        }
        pEVar17 = (EVP_MD *)EVP_CIPHER_CTX_key_length(local_34);
        pEVar14 = (EVP_MD *)CRYPTO_malloc((int)pEVar17,"pk7_doit.c",0x24f);
        pEVar4 = pEVar14;
        if ((pEVar14 == (EVP_MD *)0x0) ||
           (iVar1 = EVP_CIPHER_CTX_rand_key(local_34,(uchar *)pEVar14), pEVar4 = (EVP_MD *)0x0,
           iVar1 < 1)) goto LAB_000daeda;
        pEVar4 = pEVar14;
        if (local_30 == (EVP_MD *)0x0) {
          pEVar4 = local_30;
          local_30 = pEVar14;
          local_2c[0] = pEVar17;
        }
        pEVar8 = (EVP_MD *)EVP_CIPHER_CTX_key_length(local_34);
        pEVar14 = pEVar4;
        if ((pEVar8 != local_2c[0]) &&
           (pEVar8 = (EVP_MD *)EVP_CIPHER_CTX_set_key_length(local_34,(int)local_2c[0]),
           pEVar8 == (EVP_MD *)0x0)) {
          OPENSSL_cleanse(local_30,(size_t)local_2c[0]);
          CRYPTO_free(local_30);
          pEVar14 = pEVar8;
          local_30 = pEVar4;
          local_2c[0] = pEVar17;
        }
        ERR_clear_error();
        iVar1 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)local_30,
                                  (uchar *)0x0,0);
        pEVar4 = (EVP_MD *)0x0;
        if (iVar1 < 1) goto LAB_000daeda;
        if (local_30 != (EVP_MD *)0x0) {
          OPENSSL_cleanse(local_30,(size_t)local_2c[0]);
          CRYPTO_free(local_30);
          local_30 = (EVP_MD *)0x0;
        }
        if (pEVar14 != (EVP_MD *)0x0) {
          OPENSSL_cleanse(pEVar14,(size_t)pEVar17);
          CRYPTO_free(pEVar14);
        }
        if (pEVar16 != (EVP_MD *)0x0) {
          BIO_push((BIO *)pEVar16,(BIO *)bp);
          bp = pEVar16;
        }
      }
      pEVar4 = (EVP_MD *)in_bio;
      if (in_bio != (BIO *)0x0) {
LAB_000db1ae:
        BIO_push((BIO *)bp,(BIO *)pEVar4);
        return (BIO *)bp;
      }
      pEVar16 = bp;
      if ((int)(BIO_METHOD *)local_48->type < 1) {
        pBVar3 = BIO_s_mem();
        pEVar4 = (EVP_MD *)BIO_new(pBVar3);
        pEVar6 = pEVar4;
        pEVar14 = pEVar4;
        if (pEVar4 != (EVP_MD *)0x0) {
          BIO_ctrl((BIO *)pEVar4,0x82,0,(void *)0x0);
          goto LAB_000db1ae;
        }
      }
      else {
        pEVar4 = (EVP_MD *)
                 BIO_new_mem_buf((uchar *)local_48->md_size,(int)(BIO_METHOD *)local_48->type);
        pEVar6 = pEVar4;
        pEVar14 = pEVar4;
        if (pEVar4 != (EVP_MD *)0x0) goto LAB_000db1ae;
      }
      goto LAB_000daeda;
    }
LAB_000db1fa:
    iVar1 = 0x1ee;
    iVar10 = 0x7a;
    local_48 = (EVP_MD *)0x0;
  }
LAB_000daece:
  ERR_put_error(0x21,0x70,iVar10,"pk7_doit.c",iVar1);
  pEVar4 = local_48;
  pEVar6 = local_48;
  pEVar16 = local_48;
  pEVar17 = local_48;
  pEVar14 = local_48;
LAB_000daeda:
  if (local_30 != (EVP_MD *)0x0) {
    OPENSSL_cleanse(local_30,(size_t)local_2c[0]);
    CRYPTO_free(local_30);
  }
  if (pEVar14 != (EVP_MD *)0x0) {
    OPENSSL_cleanse(pEVar14,(size_t)pEVar17);
    CRYPTO_free(pEVar14);
  }
  if (pEVar16 != (EVP_MD *)0x0) {
    BIO_free_all((BIO *)pEVar16);
  }
  if (pEVar4 != (EVP_MD *)0x0) {
    BIO_free_all((BIO *)pEVar4);
  }
  if (pEVar6 != (EVP_MD *)0x0) {
    BIO_free_all((BIO *)pEVar6);
  }
  return (BIO *)0x0;
}

