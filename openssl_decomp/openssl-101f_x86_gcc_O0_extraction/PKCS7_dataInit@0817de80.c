
BIO * PKCS7_dataInit(PKCS7 *p7,BIO *bio)

{
  stack_st_X509 *psVar1;
  PKCS7_SIGN_ENVELOPE *pPVar2;
  pkcs7_st *ppVar3;
  PKCS7_SIGNED *pPVar4;
  bool bVar5;
  int iVar6;
  BIO *pBVar7;
  int iVar8;
  ASN1_OBJECT **ppAVar9;
  BIO_METHOD *pBVar10;
  BIO *pBVar11;
  char *pcVar12;
  EVP_MD *pEVar13;
  BIO *pBVar14;
  BIO *pBVar15;
  size_t len;
  ASN1_OBJECT *pAVar16;
  uchar *out;
  void *p2;
  EVP_PKEY *pkey;
  EVP_PKEY_CTX *ctx;
  ASN1_TYPE *type;
  long lVar17;
  BIO *pBVar18;
  _STACK *p_Var19;
  int in_GS_OFFSET;
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
  iVar6 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch(iVar6) {
  case 0x15:
    local_80 = (ASN1_OCTET_STRING *)0x0;
    local_84 = (X509_ALGOR *)0x0;
    p_Var19 = (_STACK *)0x0;
    local_90 = (_STACK *)0x0;
    local_94 = (EVP_CIPHER *)0x0;
    local_8c = (X509_ALGOR *)0x0;
    break;
  case 0x16:
    ppVar3 = ((p7->d).sign)->contents;
    p_Var19 = (_STACK *)((p7->d).sign)->md_algs;
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
    p_Var19 = (_STACK *)0x0;
    local_80 = (ASN1_OCTET_STRING *)0x0;
    local_8c = (X509_ALGOR *)0x0;
    local_90 = (_STACK *)((p7->d).sign)->md_algs;
    psVar1 = ((p7->d).sign)->cert;
    local_84 = (X509_ALGOR *)(psVar1->stack).data;
    local_94 = (EVP_CIPHER *)(psVar1->stack).num_alloc;
    if (local_94 == (EVP_CIPHER *)0x0) {
      iVar6 = 0x12f;
LAB_0817e42a:
      local_88 = (BIO *)0x0;
      ERR_put_error(0x21,0x69,0x74,"pk7_doit.c",iVar6);
      goto LAB_0817dfdc;
    }
    break;
  case 0x18:
    local_80 = (ASN1_OCTET_STRING *)0x0;
    local_8c = (X509_ALGOR *)0x0;
    pPVar2 = (p7->d).signed_and_enveloped;
    local_90 = (_STACK *)pPVar2->recipientinfo;
    p_Var19 = (_STACK *)pPVar2->md_algs;
    local_84 = pPVar2->enc_data->algorithm;
    local_94 = pPVar2->enc_data->cipher;
    if (local_94 == (EVP_CIPHER *)0x0) {
      iVar6 = 0x124;
      goto LAB_0817e42a;
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
        p_Var19 = (_STACK *)0x0;
        local_90 = (_STACK *)0x0;
        local_94 = (EVP_CIPHER *)0x0;
        break;
      }
      local_80 = (ASN1_OCTET_STRING *)pPVar4->md_algs;
    }
    local_84 = (X509_ALGOR *)0x0;
    p_Var19 = (_STACK *)0x0;
    local_90 = (_STACK *)0x0;
    local_94 = (EVP_CIPHER *)0x0;
    break;
  default:
    ERR_put_error(0x21,0x69,0x70,"pk7_doit.c",0x13a);
    local_88 = (BIO *)0x0;
    goto LAB_0817dfdc;
  }
  pBVar15 = (BIO *)0x0;
  for (iVar6 = 0; iVar8 = sk_num(p_Var19), pBVar18 = pBVar15, iVar6 < iVar8; iVar6 = iVar6 + 1) {
    ppAVar9 = (ASN1_OBJECT **)sk_value(p_Var19,iVar6);
    pBVar10 = BIO_f_md();
    pBVar11 = BIO_new(pBVar10);
    if (pBVar11 == (BIO *)0x0) goto LAB_0817dfa0;
    iVar8 = OBJ_obj2nid(*ppAVar9);
    pcVar12 = OBJ_nid2sn(iVar8);
    pEVar13 = EVP_get_digestbyname(pcVar12);
    if (pEVar13 == (EVP_MD *)0x0) {
      ERR_put_error(0x21,0x7d,0x6d,"pk7_doit.c",0x76);
LAB_0817e018:
      BIO_free(pBVar11);
      goto joined_r0x0817dfbc;
    }
    BIO_ctrl(pBVar11,0x6f,0,pEVar13);
    pBVar14 = pBVar11;
    if ((pBVar15 != (BIO *)0x0) &&
       (pBVar7 = BIO_push(pBVar15,pBVar11), pBVar14 = pBVar15, pBVar7 == (BIO *)0x0)) {
      ERR_put_error(0x21,0x7d,0x20,"pk7_doit.c",0x7f);
      goto LAB_0817e018;
    }
    pBVar15 = pBVar14;
  }
  if (local_8c == (X509_ALGOR *)0x0) {
LAB_0817e0c3:
    pBVar15 = pBVar18;
    if (local_94 == (EVP_CIPHER *)0x0) {
LAB_0817e4e2:
      if (bio == (BIO *)0x0) {
        iVar6 = OBJ_obj2nid(p7->type);
        if ((iVar6 == 0x16) && (lVar17 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar17 != 0)) {
          pBVar10 = BIO_s_null();
          local_88 = BIO_new(pBVar10);
LAB_0817e6e1:
          if (local_88 != (BIO *)0x0) goto LAB_0817e4ee;
        }
        else if ((local_80 != (ASN1_OCTET_STRING *)0x0) &&
                (iVar6 = ((_STACK *)&local_80->length)->num, 0 < iVar6)) {
          local_88 = BIO_new_mem_buf(local_80->data,iVar6);
          goto LAB_0817e6e1;
        }
        pBVar10 = BIO_s_mem();
        local_88 = BIO_new(pBVar10);
        pBVar18 = pBVar15;
        if (local_88 == (BIO *)0x0) goto joined_r0x0817dfbc;
        BIO_ctrl(local_88,0x82,0,(void *)0x0);
      }
LAB_0817e4ee:
      if (pBVar15 != (BIO *)0x0) {
        BIO_push(pBVar15,local_88);
        local_88 = pBVar15;
      }
      goto LAB_0817dfdc;
    }
    pBVar10 = BIO_f_cipher();
    pBVar15 = BIO_new(pBVar10);
    if (pBVar15 == (BIO *)0x0) {
      ERR_put_error(0x21,0x69,0x20,"pk7_doit.c",0x14e);
      if (pBVar18 == (BIO *)0x0) {
        local_88 = (BIO *)0x0;
        goto LAB_0817dfdc;
      }
      goto LAB_0817dfbe;
    }
    BIO_ctrl(pBVar15,0x81,0,&local_78);
    len = EVP_CIPHER_key_length(local_94);
    iVar6 = EVP_CIPHER_iv_length(local_94);
    iVar8 = EVP_CIPHER_type(local_94);
    pAVar16 = OBJ_nid2obj(iVar8);
    local_84->algorithm = pAVar16;
    if ((((iVar6 < 1) || (iVar8 = RAND_pseudo_bytes(local_70,iVar6), 0 < iVar8)) &&
        (iVar8 = EVP_CipherInit_ex(local_78,local_94,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,1),
        0 < iVar8)) &&
       ((iVar8 = EVP_CIPHER_CTX_rand_key(local_78,local_60), 0 < iVar8 &&
        (iVar8 = EVP_CipherInit_ex(local_78,(EVP_CIPHER *)0x0,(ENGINE *)0x0,local_60,local_70,1),
        0 < iVar8)))) {
      if (0 < iVar6) {
        type = local_84->parameter;
        if (type == (ASN1_TYPE *)0x0) {
          type = ASN1_TYPE_new();
          local_84->parameter = type;
          if (type == (ASN1_TYPE *)0x0) goto joined_r0x0817e621;
        }
        iVar6 = EVP_CIPHER_param_to_asn1(local_78,type);
        if (iVar6 < 0) goto joined_r0x0817e621;
      }
      for (iVar6 = 0; iVar8 = sk_num(local_90), iVar6 < iVar8; iVar6 = iVar6 + 1) {
        p2 = sk_value(local_90,iVar6);
        pkey = X509_get_pubkey(*(X509 **)((int)p2 + 0x10));
        if ((pkey == (EVP_PKEY *)0x0) ||
           (ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0), ctx == (EVP_PKEY_CTX *)0x0))
        goto joined_r0x0817e621;
        iVar8 = EVP_PKEY_encrypt_init(ctx);
        if (iVar8 < 1) {
LAB_0817e327:
          bVar5 = false;
        }
        else {
          iVar8 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,3,0,p2);
          if (iVar8 < 1) {
            line = 0xa5;
            iVar8 = 0x98;
LAB_0817e68b:
            bVar5 = false;
            ERR_put_error(0x21,0x84,iVar8,"pk7_doit.c",line);
          }
          else {
            iVar8 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,&local_74,local_60,len);
            if (iVar8 < 1) goto LAB_0817e327;
            out = (uchar *)CRYPTO_malloc(local_74,"pk7_doit.c",0xac);
            if (out == (uchar *)0x0) {
              line = 0xb0;
              iVar8 = 0x41;
              goto LAB_0817e68b;
            }
            iVar8 = EVP_PKEY_encrypt(ctx,out,&local_74,local_60,len);
            if (iVar8 < 1) {
              EVP_PKEY_free(pkey);
              EVP_PKEY_CTX_free(ctx);
              CRYPTO_free(out);
              goto joined_r0x0817e621;
            }
            bVar5 = true;
            ASN1_STRING_set0(*(ASN1_STRING **)((int)p2 + 0xc),out,local_74);
          }
        }
        EVP_PKEY_free(pkey);
        EVP_PKEY_CTX_free(ctx);
        if (!bVar5) goto joined_r0x0817e621;
      }
      OPENSSL_cleanse(local_60,len);
      if (pBVar18 != (BIO *)0x0) {
        BIO_push(pBVar18,pBVar15);
        pBVar15 = pBVar18;
      }
      goto LAB_0817e4e2;
    }
joined_r0x0817e621:
    if (pBVar18 != (BIO *)0x0) goto LAB_0817dfbe;
LAB_0817dfce:
    BIO_free_all(pBVar15);
    local_88 = (BIO *)0x0;
  }
  else {
    pBVar10 = BIO_f_md();
    pBVar11 = BIO_new(pBVar10);
    if (pBVar11 == (BIO *)0x0) {
LAB_0817dfa0:
      ERR_put_error(0x21,0x7d,0x20,"pk7_doit.c",0x6f);
    }
    else {
      iVar6 = OBJ_obj2nid(local_8c->algorithm);
      pcVar12 = OBJ_nid2sn(iVar6);
      pEVar13 = EVP_get_digestbyname(pcVar12);
      if (pEVar13 == (EVP_MD *)0x0) {
        ERR_put_error(0x21,0x7d,0x6d,"pk7_doit.c",0x76);
      }
      else {
        BIO_ctrl(pBVar11,0x6f,0,pEVar13);
        pBVar18 = pBVar11;
        if ((pBVar15 == (BIO *)0x0) ||
           (pBVar14 = BIO_push(pBVar15,pBVar11), pBVar18 = pBVar15, pBVar14 != (BIO *)0x0))
        goto LAB_0817e0c3;
        ERR_put_error(0x21,0x7d,0x20,"pk7_doit.c",0x7f);
      }
      BIO_free(pBVar11);
      pBVar18 = pBVar15;
    }
joined_r0x0817dfbc:
    pBVar15 = (BIO *)0x0;
    if (pBVar18 != (BIO *)0x0) {
LAB_0817dfbe:
      BIO_free_all(pBVar18);
      if (pBVar15 != (BIO *)0x0) goto LAB_0817dfce;
    }
    local_88 = (BIO *)0x0;
  }
LAB_0817dfdc:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_88;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

