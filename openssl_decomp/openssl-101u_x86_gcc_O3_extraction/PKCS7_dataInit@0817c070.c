
BIO * PKCS7_dataInit(PKCS7 *p7,BIO *bio)

{
  stack_st_X509 *psVar1;
  PKCS7_SIGN_ENVELOPE *pPVar2;
  pkcs7_st *ppVar3;
  PKCS7_SIGNED *pPVar4;
  bool bVar5;
  int iVar6;
  BIO *pBVar7;
  ASN1_OBJECT **ppAVar8;
  BIO_METHOD *pBVar9;
  BIO *pBVar10;
  char *pcVar11;
  EVP_MD *pEVar12;
  BIO *pBVar13;
  BIO *b;
  size_t len;
  ASN1_OBJECT *pAVar14;
  uchar *out;
  void *p2;
  EVP_PKEY *pkey;
  EVP_PKEY_CTX *ctx;
  ASN1_TYPE *type;
  long lVar15;
  _STACK *p_Var16;
  int in_GS_OFFSET;
  int iVar17;
  int line;
  EVP_CIPHER *local_94;
  _STACK *local_90;
  X509_ALGOR *local_8c;
  BIO *local_88;
  X509_ALGOR *local_84;
  ASN1_OCTET_STRING *local_80;
  EVP_CIPHER_CTX *local_78;
  size_t local_74;
  uchar local_70 [16];
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_88 = bio;
  if (p7 == (PKCS7 *)0x0) {
    iVar17 = 0x109;
    iVar6 = 0x8f;
LAB_0817c8a7:
    ERR_put_error(0x21,0x69,iVar6,"pk7_doit.c",iVar17);
    local_88 = (BIO *)0x0;
    goto LAB_0817c2c2;
  }
  if ((p7->d).ptr == (char *)0x0) {
    iVar17 = 0x117;
    iVar6 = 0x7a;
    goto LAB_0817c8a7;
  }
  iVar6 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch(iVar6) {
  case 0x15:
    local_80 = (ASN1_OCTET_STRING *)0x0;
    local_84 = (X509_ALGOR *)0x0;
    p_Var16 = (_STACK *)0x0;
    local_90 = (_STACK *)0x0;
    local_94 = (EVP_CIPHER *)0x0;
    local_8c = (X509_ALGOR *)0x0;
    break;
  case 0x16:
    ppVar3 = ((p7->d).sign)->contents;
    p_Var16 = (_STACK *)((p7->d).sign)->md_algs;
    iVar6 = OBJ_obj2nid(ppVar3->type);
    if (iVar6 == 0x15) {
      local_80 = (ppVar3->d).data;
    }
    else {
      iVar6 = OBJ_obj2nid(ppVar3->type);
      if (((iVar6 - 0x15U < 6) || (pPVar4 = (ppVar3->d).sign, pPVar4 == (PKCS7_SIGNED *)0x0)) ||
         (pPVar4->version != (ASN1_INTEGER *)0x4)) {
        local_80 = (ASN1_OCTET_STRING *)0x0;
        local_84 = (X509_ALGOR *)0x0;
        local_90 = (_STACK *)0x0;
        local_94 = (EVP_CIPHER *)0x0;
        local_8c = (X509_ALGOR *)0x0;
        break;
      }
      local_80 = (ASN1_OCTET_STRING *)pPVar4->md_algs;
    }
    local_84 = (X509_ALGOR *)0x0;
    local_90 = (_STACK *)0x0;
    local_94 = (EVP_CIPHER *)0x0;
    local_8c = (X509_ALGOR *)0x0;
    break;
  case 0x17:
    p_Var16 = (_STACK *)0x0;
    local_80 = (ASN1_OCTET_STRING *)0x0;
    local_8c = (X509_ALGOR *)0x0;
    local_90 = (_STACK *)((p7->d).sign)->md_algs;
    psVar1 = ((p7->d).sign)->cert;
    local_84 = (X509_ALGOR *)(psVar1->stack).data;
    local_94 = (EVP_CIPHER *)(psVar1->stack).num_alloc;
    if (local_94 != (EVP_CIPHER *)0x0) break;
    iVar6 = 0x132;
LAB_0817c2aa:
    ERR_put_error(0x21,0x69,0x74,"pk7_doit.c",iVar6);
    goto LAB_0817c2c0;
  case 0x18:
    local_80 = (ASN1_OCTET_STRING *)0x0;
    local_8c = (X509_ALGOR *)0x0;
    pPVar2 = (p7->d).signed_and_enveloped;
    local_90 = (_STACK *)pPVar2->recipientinfo;
    p_Var16 = (_STACK *)pPVar2->md_algs;
    local_84 = pPVar2->enc_data->algorithm;
    local_94 = pPVar2->enc_data->cipher;
    if (local_94 == (EVP_CIPHER *)0x0) {
      iVar6 = 0x129;
      goto LAB_0817c2aa;
    }
    break;
  case 0x19:
    local_8c = ((p7->d).digest)->md;
    ppVar3 = ((p7->d).digest)->contents;
    iVar6 = OBJ_obj2nid(ppVar3->type);
    if (iVar6 == 0x15) {
      local_80 = (ppVar3->d).data;
    }
    else {
      iVar6 = OBJ_obj2nid(ppVar3->type);
      if (((iVar6 - 0x15U < 6) || (pPVar4 = (ppVar3->d).sign, pPVar4 == (PKCS7_SIGNED *)0x0)) ||
         (pPVar4->version != (ASN1_INTEGER *)0x4)) {
        local_80 = (ASN1_OCTET_STRING *)0x0;
        local_84 = (X509_ALGOR *)0x0;
        p_Var16 = (_STACK *)0x0;
        local_90 = (_STACK *)0x0;
        local_94 = (EVP_CIPHER *)0x0;
        break;
      }
      local_80 = (ASN1_OCTET_STRING *)pPVar4->md_algs;
    }
    local_84 = (X509_ALGOR *)0x0;
    p_Var16 = (_STACK *)0x0;
    local_90 = (_STACK *)0x0;
    local_94 = (EVP_CIPHER *)0x0;
    break;
  default:
    ERR_put_error(0x21,0x69,0x70,"pk7_doit.c",0x13d);
    goto LAB_0817c2c0;
  }
  b = (BIO *)0x0;
  for (iVar6 = 0; iVar17 = sk_num(p_Var16), iVar6 < iVar17; iVar6 = iVar6 + 1) {
    ppAVar8 = (ASN1_OBJECT **)sk_value(p_Var16,iVar6);
    pBVar9 = BIO_f_md();
    pBVar10 = BIO_new(pBVar9);
    if (pBVar10 == (BIO *)0x0) goto LAB_0817c350;
    iVar17 = OBJ_obj2nid(*ppAVar8);
    pcVar11 = OBJ_nid2sn(iVar17);
    pEVar12 = EVP_get_digestbyname(pcVar11);
    if (pEVar12 == (EVP_MD *)0x0) {
      ERR_put_error(0x21,0x7d,0x6d,"pk7_doit.c",0x73);
LAB_0817c3b8:
      BIO_free(pBVar10);
      goto LAB_0817c368;
    }
    BIO_ctrl(pBVar10,0x6f,0,pEVar12);
    pBVar13 = pBVar10;
    if ((b != (BIO *)0x0) && (pBVar7 = BIO_push(b,pBVar10), pBVar13 = b, pBVar7 == (BIO *)0x0)) {
      ERR_put_error(0x21,0x7d,0x20,"pk7_doit.c",0x7b);
      goto LAB_0817c3b8;
    }
    b = pBVar13;
  }
  pBVar10 = b;
  if (local_8c == (X509_ALGOR *)0x0) {
LAB_0817c463:
    b = pBVar10;
    if (local_94 == (EVP_CIPHER *)0x0) {
LAB_0817c7a3:
      if (bio == (BIO *)0x0) {
        iVar6 = OBJ_obj2nid(p7->type);
        if ((iVar6 == 0x16) && (lVar15 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar15 != 0)) {
          pBVar9 = BIO_s_null();
          local_88 = BIO_new(pBVar9);
LAB_0817c92b:
          if (local_88 != (BIO *)0x0) goto LAB_0817c7af;
        }
        else if ((local_80 != (ASN1_OCTET_STRING *)0x0) &&
                (iVar6 = ((_STACK *)&local_80->length)->num, 0 < iVar6)) {
          local_88 = BIO_new_mem_buf(local_80->data,iVar6);
          goto LAB_0817c92b;
        }
        pBVar9 = BIO_s_mem();
        local_88 = BIO_new(pBVar9);
        if (local_88 == (BIO *)0x0) goto LAB_0817c368;
        BIO_ctrl(local_88,0x82,0,(void *)0x0);
      }
LAB_0817c7af:
      if (b != (BIO *)0x0) {
        BIO_push(b,local_88);
        local_88 = b;
      }
      goto LAB_0817c2c2;
    }
    pBVar9 = BIO_f_cipher();
    b = BIO_new(pBVar9);
    if (b == (BIO *)0x0) {
      ERR_put_error(0x21,0x69,0x20,"pk7_doit.c",0x14f);
      pBVar13 = b;
      goto joined_r0x0817c862;
    }
    BIO_ctrl(b,0x81,0,&local_78);
    len = EVP_CIPHER_key_length(local_94);
    iVar6 = EVP_CIPHER_iv_length(local_94);
    iVar17 = EVP_CIPHER_type(local_94);
    pAVar14 = OBJ_nid2obj(iVar17);
    local_84->algorithm = pAVar14;
    if ((((iVar6 < 1) || (iVar17 = RAND_bytes(local_70,iVar6), 0 < iVar17)) &&
        (iVar17 = EVP_CipherInit_ex(local_78,local_94,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,1),
        0 < iVar17)) &&
       ((iVar17 = EVP_CIPHER_CTX_rand_key(local_78,local_60), 0 < iVar17 &&
        (iVar17 = EVP_CipherInit_ex(local_78,(EVP_CIPHER *)0x0,(ENGINE *)0x0,local_60,local_70,1),
        0 < iVar17)))) {
      if (0 < iVar6) {
        type = local_84->parameter;
        if (type == (ASN1_TYPE *)0x0) {
          type = ASN1_TYPE_new();
          local_84->parameter = type;
          if (type == (ASN1_TYPE *)0x0) goto joined_r0x0817c80a;
        }
        iVar6 = EVP_CIPHER_param_to_asn1(local_78,type);
        if (iVar6 < 0) goto joined_r0x0817c80a;
      }
      for (iVar6 = 0; iVar17 = sk_num(local_90), iVar6 < iVar17; iVar6 = iVar6 + 1) {
        p2 = sk_value(local_90,iVar6);
        pkey = X509_get_pubkey(*(X509 **)((int)p2 + 0x10));
        if ((pkey == (EVP_PKEY *)0x0) ||
           (ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0), ctx == (EVP_PKEY_CTX *)0x0))
        goto joined_r0x0817c80a;
        iVar17 = EVP_PKEY_encrypt_init(ctx);
        if (iVar17 < 1) {
LAB_0817c6bb:
          bVar5 = false;
        }
        else {
          iVar17 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,3,0,p2);
          if (iVar17 < 1) {
            line = 0xa0;
            iVar17 = 0x98;
LAB_0817c882:
            bVar5 = false;
            ERR_put_error(0x21,0x84,iVar17,"pk7_doit.c",line);
          }
          else {
            iVar17 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,&local_74,local_60,len);
            if (iVar17 < 1) goto LAB_0817c6bb;
            out = (uchar *)CRYPTO_malloc(local_74,"pk7_doit.c",0xa7);
            if (out == (uchar *)0x0) {
              line = 0xaa;
              iVar17 = 0x41;
              goto LAB_0817c882;
            }
            iVar17 = EVP_PKEY_encrypt(ctx,out,&local_74,local_60,len);
            if (iVar17 < 1) {
              EVP_PKEY_free(pkey);
              EVP_PKEY_CTX_free(ctx);
              CRYPTO_free(out);
              goto joined_r0x0817c80a;
            }
            bVar5 = true;
            ASN1_STRING_set0(*(ASN1_STRING **)((int)p2 + 0xc),out,local_74);
          }
        }
        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(ctx);
        if (!bVar5) goto joined_r0x0817c80a;
      }
      OPENSSL_cleanse(local_60,len);
      if (pBVar10 != (BIO *)0x0) {
        BIO_push(pBVar10,b);
        b = pBVar10;
      }
      goto LAB_0817c7a3;
    }
joined_r0x0817c80a:
    if (pBVar10 != (BIO *)0x0) goto LAB_0817c372;
LAB_0817c386:
    BIO_free_all(b);
  }
  else {
    pBVar9 = BIO_f_md();
    pBVar13 = BIO_new(pBVar9);
    if (pBVar13 == (BIO *)0x0) {
LAB_0817c350:
      ERR_put_error(0x21,0x7d,0x20,"pk7_doit.c",0x6d);
    }
    else {
      iVar6 = OBJ_obj2nid(local_8c->algorithm);
      pcVar11 = OBJ_nid2sn(iVar6);
      pEVar12 = EVP_get_digestbyname(pcVar11);
      if (pEVar12 == (EVP_MD *)0x0) {
        ERR_put_error(0x21,0x7d,0x6d,"pk7_doit.c",0x73);
      }
      else {
        BIO_ctrl(pBVar13,0x6f,0,pEVar12);
        pBVar10 = pBVar13;
        if ((b == (BIO *)0x0) || (pBVar7 = BIO_push(b,pBVar13), pBVar10 = b, pBVar7 != (BIO *)0x0))
        goto LAB_0817c463;
        ERR_put_error(0x21,0x7d,0x20,"pk7_doit.c",0x7b);
      }
      BIO_free(pBVar13);
    }
LAB_0817c368:
    pBVar13 = (BIO *)0x0;
    pBVar10 = b;
joined_r0x0817c862:
    b = pBVar13;
    if (pBVar10 != (BIO *)0x0) {
LAB_0817c372:
      BIO_free_all(pBVar10);
      if (b != (BIO *)0x0) goto LAB_0817c386;
    }
  }
LAB_0817c2c0:
  local_88 = (BIO *)0x0;
LAB_0817c2c2:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_88;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

