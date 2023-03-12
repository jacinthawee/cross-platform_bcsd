
BIO * PKCS7_dataInit(PKCS7 *p7,BIO *bio)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  BIO_METHOD *pBVar3;
  BIO *bp;
  char *pcVar4;
  EVP_MD *pEVar5;
  BIO *pBVar6;
  size_t len;
  ASN1_OBJECT *pAVar7;
  uchar *out;
  void *p2;
  EVP_PKEY *pkey;
  EVP_PKEY_CTX *ctx;
  long lVar8;
  ASN1_TYPE *type;
  _STACK *p_Var9;
  ASN1_OCTET_STRING *pAVar10;
  PKCS7_SIGN_ENVELOPE *pPVar11;
  stack_st_X509 *psVar12;
  pkcs7_st *ppVar13;
  int iVar14;
  BIO *pBVar15;
  BIO *pBVar16;
  EVP_CIPHER *local_9c;
  X509_ALGOR *local_98;
  X509_ALGOR *local_94;
  BIO *local_90;
  _STACK *local_8c;
  EVP_CIPHER_CTX *local_84;
  size_t local_80;
  uchar auStack_7c [16];
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __TMC_END__;
  iVar1 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch(iVar1) {
  case 0x15:
    pAVar10 = (ASN1_OCTET_STRING *)0x0;
    local_98 = (X509_ALGOR *)0x0;
    p_Var9 = (_STACK *)0x0;
    local_8c = (_STACK *)0x0;
    local_9c = (EVP_CIPHER *)0x0;
    local_94 = (X509_ALGOR *)0x0;
    break;
  case 0x16:
    ppVar13 = ((p7->d).sign)->contents;
    p_Var9 = (_STACK *)((p7->d).sign)->md_algs;
    iVar1 = OBJ_obj2nid(ppVar13->type);
    if (iVar1 == 0x15) {
      pAVar10 = (ppVar13->d).data;
    }
    else {
      iVar1 = OBJ_obj2nid(ppVar13->type);
      if (iVar1 - 0x15U < 6) {
LAB_000dcf32:
        pAVar10 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        pAVar10 = (ppVar13->d).data;
        if (pAVar10 != (ASN1_OCTET_STRING *)0x0) {
          if (pAVar10->length != 4) goto LAB_000dcf32;
          pAVar10 = (ASN1_OCTET_STRING *)pAVar10->type;
        }
      }
    }
    local_98 = (X509_ALGOR *)0x0;
    local_8c = (_STACK *)0x0;
    local_9c = (EVP_CIPHER *)0x0;
    local_94 = (X509_ALGOR *)0x0;
    break;
  case 0x17:
    psVar12 = ((p7->d).sign)->cert;
    local_8c = (_STACK *)((p7->d).sign)->md_algs;
    local_9c = (EVP_CIPHER *)(psVar12->stack).num_alloc;
    local_98 = (X509_ALGOR *)(psVar12->stack).data;
    if (local_9c == (EVP_CIPHER *)0x0) {
      iVar1 = 0x12f;
LAB_000dd00e:
      ERR_put_error(0x21,0x69,0x74,"pk7_doit.c",iVar1);
      goto LAB_000dcf28;
    }
    pAVar10 = (ASN1_OCTET_STRING *)0x0;
    local_94 = (X509_ALGOR *)0x0;
    p_Var9 = (_STACK *)0x0;
    break;
  case 0x18:
    pPVar11 = (p7->d).signed_and_enveloped;
    local_8c = (_STACK *)pPVar11->recipientinfo;
    p_Var9 = (_STACK *)pPVar11->md_algs;
    local_9c = pPVar11->enc_data->cipher;
    local_98 = pPVar11->enc_data->algorithm;
    if (local_9c == (EVP_CIPHER *)0x0) {
      iVar1 = 0x124;
      goto LAB_000dd00e;
    }
    pAVar10 = (ASN1_OCTET_STRING *)0x0;
    local_94 = (X509_ALGOR *)0x0;
    break;
  case 0x19:
    ppVar13 = ((p7->d).digest)->contents;
    local_94 = ((p7->d).digest)->md;
    iVar1 = OBJ_obj2nid(ppVar13->type);
    if (iVar1 == 0x15) {
      pAVar10 = (ppVar13->d).data;
    }
    else {
      iVar1 = OBJ_obj2nid(ppVar13->type);
      if (iVar1 - 0x15U < 6) {
LAB_000dcf2c:
        pAVar10 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        pAVar10 = (ppVar13->d).data;
        if (pAVar10 != (ASN1_OCTET_STRING *)0x0) {
          if (pAVar10->length != 4) goto LAB_000dcf2c;
          pAVar10 = (ASN1_OCTET_STRING *)pAVar10->type;
        }
      }
    }
    p_Var9 = (_STACK *)0x0;
    local_98 = (X509_ALGOR *)0x0;
    local_8c = (_STACK *)0x0;
    local_9c = (EVP_CIPHER *)0x0;
    break;
  default:
    ERR_put_error(0x21,0x69,0x70,"pk7_doit.c",0x13a);
LAB_000dcf28:
    local_90 = (BIO *)0x0;
    goto LAB_000dcdd4;
  }
  pBVar15 = (BIO *)0x0;
  iVar1 = sk_num(p_Var9);
  iVar14 = 0;
  pBVar16 = pBVar15;
  if (0 < iVar1) {
    do {
      ppAVar2 = (ASN1_OBJECT **)sk_value(p_Var9,iVar14);
      pBVar3 = BIO_f_md();
      bp = BIO_new(pBVar3);
      pBVar15 = pBVar16;
      if (bp == (BIO *)0x0) goto LAB_000dcdaa;
      iVar1 = OBJ_obj2nid(*ppAVar2);
      pcVar4 = OBJ_nid2sn(iVar1);
      pEVar5 = EVP_get_digestbyname(pcVar4);
      if (pEVar5 == (EVP_MD *)0x0) goto LAB_000dcde8;
      BIO_ctrl(bp,0x6f,0,pEVar5);
      pBVar15 = bp;
      if ((pBVar16 != (BIO *)0x0) &&
         (pBVar6 = BIO_push(pBVar16,bp), pBVar15 = pBVar16, pBVar6 == (BIO *)0x0))
      goto LAB_000dce06;
      iVar14 = iVar14 + 1;
      iVar1 = sk_num(p_Var9);
      pBVar16 = pBVar15;
    } while (iVar14 < iVar1);
  }
  pBVar16 = pBVar15;
  if (local_94 == (X509_ALGOR *)0x0) {
LAB_000dcc30:
    pBVar15 = pBVar16;
    if (local_9c == (EVP_CIPHER *)0x0) {
LAB_000dcefc:
      local_90 = bio;
      if (bio == (BIO *)0x0) {
        iVar1 = OBJ_obj2nid(p7->type);
        if ((iVar1 == 0x16) && (lVar8 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar8 != 0)) {
          pBVar3 = BIO_s_null();
          local_90 = BIO_new(pBVar3);
LAB_000dcf6e:
          if (local_90 != (BIO *)0x0) goto LAB_000dcf00;
        }
        else if ((pAVar10 != (ASN1_OCTET_STRING *)0x0) && (0 < pAVar10->length)) {
          local_90 = BIO_new_mem_buf(pAVar10->data,pAVar10->length);
          goto LAB_000dcf6e;
        }
        pBVar3 = BIO_s_mem();
        local_90 = BIO_new(pBVar3);
        pBVar16 = pBVar15;
        if (local_90 == (BIO *)0x0) goto LAB_000dcdc2;
        BIO_ctrl(local_90,0x82,0,(void *)0x0);
      }
LAB_000dcf00:
      if (pBVar15 != (BIO *)0x0) {
        BIO_push(pBVar15,local_90);
        local_90 = pBVar15;
      }
      goto LAB_000dcdd4;
    }
    pBVar3 = BIO_f_cipher();
    local_90 = BIO_new(pBVar3);
    if (local_90 == (BIO *)0x0) {
      ERR_put_error(0x21,0x69,0x20,"pk7_doit.c",0x14e);
    }
    else {
      BIO_ctrl(local_90,0x81,0,&local_84);
      len = EVP_CIPHER_key_length(local_9c);
      iVar1 = EVP_CIPHER_iv_length(local_9c);
      iVar14 = EVP_CIPHER_type(local_9c);
      pAVar7 = OBJ_nid2obj(iVar14);
      local_98->algorithm = pAVar7;
      if ((((iVar1 < 1) || (iVar14 = RAND_pseudo_bytes(auStack_7c,iVar1), 0 < iVar14)) &&
          (iVar14 = EVP_CipherInit_ex(local_84,local_9c,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,1),
          0 < iVar14)) &&
         ((iVar14 = EVP_CIPHER_CTX_rand_key(local_84,auStack_6c), 0 < iVar14 &&
          (iVar14 = EVP_CipherInit_ex(local_84,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_6c,auStack_7c
                                      ,1), 0 < iVar14)))) {
        if (0 < iVar1) {
          type = local_98->parameter;
          if (type == (ASN1_TYPE *)0x0) {
            type = ASN1_TYPE_new();
            local_98->parameter = type;
            if (type == (ASN1_TYPE *)0x0) goto LAB_000dcdc2;
          }
          iVar1 = EVP_CIPHER_param_to_asn1(local_84,type);
          if (iVar1 < 0) goto LAB_000dcdc2;
        }
        for (iVar1 = 0; iVar14 = sk_num(local_8c), iVar1 < iVar14; iVar1 = iVar1 + 1) {
          p2 = sk_value(local_8c,iVar1);
          pkey = X509_get_pubkey(*(X509 **)((int)p2 + 0x10));
          if ((pkey == (EVP_PKEY *)0x0) ||
             (ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0), ctx == (EVP_PKEY_CTX *)0x0))
          goto LAB_000dcdc2;
          iVar14 = EVP_PKEY_encrypt_init(ctx);
          if (iVar14 < 1) {
LAB_000dcda2:
            out = (uchar *)0x0;
          }
          else {
            iVar14 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,3,0,p2);
            if (iVar14 < 1) {
              out = (uchar *)0x0;
              ERR_put_error(0x21,0x84,0x98,"pk7_doit.c",0xa5);
            }
            else {
              iVar14 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,&local_80,auStack_6c,len);
              if (iVar14 < 1) goto LAB_000dcda2;
              out = (uchar *)CRYPTO_malloc(local_80,"pk7_doit.c",0xac);
              if (out == (uchar *)0x0) {
                ERR_put_error(0x21,0x84,0x41,"pk7_doit.c",0xb0);
              }
              else {
                iVar14 = EVP_PKEY_encrypt(ctx,out,&local_80,auStack_6c,len);
                if (iVar14 < 1) {
                  EVP_PKEY_free(pkey);
                  EVP_PKEY_CTX_free(ctx);
                  CRYPTO_free(out);
                  goto LAB_000dcdc2;
                }
                ASN1_STRING_set0(*(ASN1_STRING **)((int)p2 + 0xc),out,local_80);
                out = (uchar *)0x1;
              }
            }
          }
          EVP_PKEY_free(pkey);
          EVP_PKEY_CTX_free(ctx);
          if (out == (uchar *)0x0) goto LAB_000dcdc2;
        }
        OPENSSL_cleanse(auStack_6c,len);
        pBVar15 = local_90;
        if (pBVar16 != (BIO *)0x0) {
          BIO_push(pBVar16,local_90);
          pBVar15 = pBVar16;
        }
        goto LAB_000dcefc;
      }
    }
  }
  else {
    pBVar3 = BIO_f_md();
    bp = BIO_new(pBVar3);
    if (bp == (BIO *)0x0) {
LAB_000dcdaa:
      ERR_put_error(0x21,0x7d,0x20,"pk7_doit.c",0x6f);
      pBVar16 = pBVar15;
    }
    else {
      iVar1 = OBJ_obj2nid(local_94->algorithm);
      pcVar4 = OBJ_nid2sn(iVar1);
      pEVar5 = EVP_get_digestbyname(pcVar4);
      if (pEVar5 == (EVP_MD *)0x0) {
LAB_000dcde8:
        ERR_put_error(0x21,0x7d,0x6d,"pk7_doit.c",0x76);
      }
      else {
        BIO_ctrl(bp,0x6f,0,pEVar5);
        pBVar16 = bp;
        if ((pBVar15 == (BIO *)0x0) ||
           (pBVar6 = BIO_push(pBVar15,bp), pBVar16 = pBVar15, pBVar6 != (BIO *)0x0))
        goto LAB_000dcc30;
LAB_000dce06:
        ERR_put_error(0x21,0x7d,0x20,"pk7_doit.c",0x7f);
      }
      BIO_free(bp);
      pBVar16 = pBVar15;
    }
    local_90 = (BIO *)0x0;
  }
LAB_000dcdc2:
  if (pBVar16 != (BIO *)0x0) {
    BIO_free_all(pBVar16);
  }
  if (local_90 != (BIO *)0x0) {
    BIO_free_all(local_90);
    local_90 = (BIO *)0x0;
  }
LAB_000dcdd4:
  if (local_2c == __TMC_END__) {
    return local_90;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

