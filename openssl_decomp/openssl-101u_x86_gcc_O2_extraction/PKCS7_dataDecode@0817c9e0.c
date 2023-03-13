
BIO * PKCS7_dataDecode(PKCS7 *p7,EVP_PKEY *pkey,BIO *in_bio,X509 *pcert)

{
  PKCS7_SIGN_ENVELOPE *pPVar1;
  pkcs7_st *ppVar2;
  PKCS7_ENC_CONTENT *pPVar3;
  ASN1_OCTET_STRING *pAVar4;
  int iVar5;
  int iVar6;
  ASN1_OBJECT **ppAVar7;
  BIO_METHOD *pBVar8;
  char *pcVar9;
  EVP_MD *parg;
  long lVar10;
  void *pvVar11;
  size_t sVar12;
  size_t len;
  BIO *bp;
  BIO *b;
  BIO *bp_00;
  uchar *key;
  _STACK *p_Var13;
  uchar *puVar14;
  int in_GS_OFFSET;
  bool bVar15;
  BIO *local_48;
  ASN1_OCTET_STRING *local_40;
  EVP_CIPHER *local_38;
  _STACK *local_34;
  X509_ALGOR *local_30;
  EVP_CIPHER_CTX *local_2c;
  uchar *local_28;
  size_t local_24;
  int local_20;
  
  local_2c = (EVP_CIPHER_CTX *)0x0;
  local_28 = (uchar *)0x0;
  local_24 = 0;
  local_48 = in_bio;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (p7 == (PKCS7 *)0x0) {
    iVar6 = 0x1b2;
    iVar5 = 0x8f;
  }
  else {
    if ((p7->d).ptr != (char *)0x0) {
      iVar5 = OBJ_obj2nid(p7->type);
      p7->state = 0;
      if (iVar5 == 0x17) {
        local_34 = (_STACK *)((p7->d).enveloped)->recipientinfo;
        pPVar3 = ((p7->d).enveloped)->enc_data;
        local_30 = pPVar3->algorithm;
        local_40 = pPVar3->enc_data;
        iVar5 = OBJ_obj2nid(local_30->algorithm);
        pcVar9 = OBJ_nid2sn(iVar5);
        local_38 = EVP_get_cipherbyname(pcVar9);
        if (local_38 != (EVP_CIPHER *)0x0) {
          if ((in_bio != (BIO *)0x0) || (local_40 != (ASN1_OCTET_STRING *)0x0)) {
            b = (BIO *)0x0;
            goto LAB_0817cd72;
          }
          goto LAB_0817ccfc;
        }
        iVar5 = 0x1e3;
LAB_0817d1b9:
        ERR_put_error(0x21,0x70,0x6f,"pk7_doit.c",iVar5);
LAB_0817ca85:
        if (local_28 != (uchar *)0x0) {
          len = 0;
          key = (uchar *)0x0;
          bp_00 = (BIO *)0x0;
          bp = (BIO *)0x0;
          b = (BIO *)0x0;
LAB_0817ca97:
          OPENSSL_cleanse(local_28,local_24);
          CRYPTO_free(local_28);
LAB_0817cab7:
          if (key != (uchar *)0x0) {
LAB_0817cabb:
            OPENSSL_cleanse(key,len);
            CRYPTO_free(key);
          }
          goto LAB_0817cad0;
        }
      }
      else {
        if (iVar5 == 0x18) {
          pPVar1 = (p7->d).signed_and_enveloped;
          local_34 = (_STACK *)pPVar1->recipientinfo;
          p_Var13 = (_STACK *)pPVar1->md_algs;
          local_40 = pPVar1->enc_data->enc_data;
          local_30 = pPVar1->enc_data->algorithm;
          iVar5 = OBJ_obj2nid(local_30->algorithm);
          pcVar9 = OBJ_nid2sn(iVar5);
          local_38 = EVP_get_cipherbyname(pcVar9);
          bVar15 = local_40 == (ASN1_OCTET_STRING *)0x0;
          if (local_38 == (EVP_CIPHER *)0x0) {
            iVar5 = 0x1d7;
            goto LAB_0817d1b9;
          }
        }
        else {
          if (iVar5 != 0x16) {
            ERR_put_error(0x21,0x70,0x70,"pk7_doit.c",0x1e8);
            goto LAB_0817ca85;
          }
          ppVar2 = ((p7->d).sign)->contents;
          iVar5 = OBJ_obj2nid(ppVar2->type);
          if (iVar5 == 0x15) {
            local_40 = (ASN1_OCTET_STRING *)(ppVar2->d).ptr;
LAB_0817cd23:
            iVar5 = OBJ_obj2nid(p7->type);
            if (iVar5 == 0x16) {
LAB_0817cc7e:
              lVar10 = PKCS7_ctrl(p7,2,0,(char *)0x0);
              if (lVar10 != 0) {
                bVar15 = local_40 == (ASN1_OCTET_STRING *)0x0;
                goto LAB_0817cd4c;
              }
            }
            if (local_40 == (ASN1_OCTET_STRING *)0x0) {
LAB_0817d1db:
              ERR_put_error(0x21,0x70,0x9b,"pk7_doit.c",0x1c9);
              goto LAB_0817ca85;
            }
            bVar15 = false;
          }
          else {
            iVar5 = OBJ_obj2nid(ppVar2->type);
            if (iVar5 - 0x15U < 6) {
              iVar5 = OBJ_obj2nid(p7->type);
              if (iVar5 == 0x16) {
                local_40 = (ASN1_OCTET_STRING *)0x0;
                goto LAB_0817cc7e;
              }
              goto LAB_0817d1db;
            }
            pAVar4 = (ppVar2->d).data;
            if ((pAVar4 != (ASN1_OCTET_STRING *)0x0) && (pAVar4->length == 4)) {
              local_40 = (ASN1_OCTET_STRING *)pAVar4->type;
              goto LAB_0817cd23;
            }
            iVar5 = OBJ_obj2nid(p7->type);
            if ((iVar5 != 0x16) || (lVar10 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar10 == 0))
            goto LAB_0817d1db;
            bVar15 = true;
            local_40 = (ASN1_OCTET_STRING *)0x0;
          }
LAB_0817cd4c:
          local_34 = (_STACK *)0x0;
          local_30 = (X509_ALGOR *)0x0;
          local_38 = (EVP_CIPHER *)0x0;
          p_Var13 = (_STACK *)((p7->d).sign)->md_algs;
        }
        if ((in_bio == (BIO *)0x0) && (bVar15)) {
LAB_0817ccfc:
          ERR_put_error(0x21,0x70,0x7a,"pk7_doit.c",0x1ee);
          goto LAB_0817ca85;
        }
        b = (BIO *)0x0;
        if (p_Var13 != (_STACK *)0x0) {
          for (iVar5 = 0; iVar6 = sk_num(p_Var13), iVar5 < iVar6; iVar5 = iVar5 + 1) {
            ppAVar7 = (ASN1_OBJECT **)sk_value(p_Var13,iVar5);
            pBVar8 = BIO_f_md();
            bp = BIO_new(pBVar8);
            if (bp == (BIO *)0x0) {
              ERR_put_error(0x21,0x70,0x20,"pk7_doit.c",0x1f7);
              len = 0;
              bp_00 = (BIO *)0x0;
              goto LAB_0817cfc4;
            }
            iVar6 = OBJ_obj2nid(*ppAVar7);
            pcVar9 = OBJ_nid2sn(iVar6);
            parg = EVP_get_digestbyname(pcVar9);
            if (parg == (EVP_MD *)0x0) {
              ERR_put_error(0x21,0x70,0x6d,"pk7_doit.c",0x1ff);
              len = 0;
              bp_00 = (BIO *)0x0;
              goto LAB_0817cfc4;
            }
            BIO_ctrl(bp,0x6f,0,parg);
            if (b != (BIO *)0x0) {
              BIO_push(b,bp);
              bp = b;
            }
            b = bp;
          }
        }
        if (local_38 == (EVP_CIPHER *)0x0) {
          len = 0;
          bp_00 = b;
LAB_0817cfee:
          if (in_bio == (BIO *)0x0) {
            if (local_40->length < 1) {
              pBVar8 = BIO_s_mem();
              local_48 = BIO_new(pBVar8);
              if (local_48 == (BIO *)0x0) goto LAB_0817d0e2;
              BIO_ctrl(local_48,0x82,0,(void *)0x0);
            }
            else {
              local_48 = BIO_new_mem_buf(local_40->data,local_40->length);
              if (local_48 == (BIO *)0x0) {
LAB_0817d0e2:
                bp = (BIO *)0x0;
                b = bp_00;
                bp_00 = (BIO *)0x0;
                goto LAB_0817cfc4;
              }
            }
          }
          BIO_push(bp_00,local_48);
          goto LAB_0817cb02;
        }
LAB_0817cd72:
        pBVar8 = BIO_f_cipher();
        bp_00 = BIO_new(pBVar8);
        if (bp_00 != (BIO *)0x0) {
          iVar5 = 0;
          if (pcert != (X509 *)0x0) {
            for (; iVar6 = sk_num(local_34), iVar5 < iVar6; iVar5 = iVar5 + 1) {
              pvVar11 = sk_value(local_34,iVar5);
              iVar6 = X509_NAME_cmp(**(X509_NAME ***)((int)pvVar11 + 4),pcert->cert_info->issuer);
              if ((iVar6 == 0) &&
                 (iVar6 = ASN1_STRING_cmp(pcert->cert_info->serialNumber,
                                          *(ASN1_STRING **)(*(int *)((int)pvVar11 + 4) + 4)),
                 iVar6 == 0)) {
                iVar5 = pkcs7_decrypt_rinfo(pkey);
                if (iVar5 < 0) goto LAB_0817cfc0;
                ERR_clear_error();
                goto LAB_0817ce34;
              }
            }
            bp = (BIO *)0x0;
            ERR_put_error(0x21,0x70,0x73,"pk7_doit.c",0x22e);
            len = 0;
            goto LAB_0817cfc4;
          }
          for (; iVar6 = sk_num(local_34), iVar5 < iVar6; iVar5 = iVar5 + 1) {
            sk_value(local_34,iVar5);
            iVar6 = pkcs7_decrypt_rinfo(pkey);
            if (iVar6 < 0) {
              len = 0;
              bp = (BIO *)0x0;
              goto LAB_0817cfc4;
            }
            ERR_clear_error();
          }
LAB_0817ce34:
          local_2c = (EVP_CIPHER_CTX *)0x0;
          BIO_ctrl(bp_00,0x81,0,&local_2c);
          iVar5 = EVP_CipherInit_ex(local_2c,local_38,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,0);
          if ((iVar5 < 1) ||
             (iVar5 = EVP_CIPHER_asn1_to_param(local_2c,local_30->parameter), iVar5 < 0)) {
LAB_0817cfc0:
            len = 0;
LAB_0817cfc2:
            bp = (BIO *)0x0;
            goto LAB_0817cfc4;
          }
          len = EVP_CIPHER_CTX_key_length(local_2c);
          key = (uchar *)CRYPTO_malloc(len,"pk7_doit.c",0x24f);
          if (key == (uchar *)0x0) goto LAB_0817cfc2;
          iVar5 = EVP_CIPHER_CTX_rand_key(local_2c,key);
          if (0 < iVar5) {
            puVar14 = key;
            if (local_28 == (uchar *)0x0) {
              puVar14 = (uchar *)0x0;
              local_28 = key;
              local_24 = len;
            }
            sVar12 = EVP_CIPHER_CTX_key_length(local_2c);
            key = puVar14;
            if ((sVar12 != local_24) &&
               (iVar5 = EVP_CIPHER_CTX_set_key_length(local_2c,local_24), iVar5 == 0)) {
              OPENSSL_cleanse(local_28,local_24);
              CRYPTO_free(local_28);
              key = (uchar *)0x0;
              local_28 = puVar14;
              local_24 = len;
            }
            ERR_clear_error();
            iVar5 = EVP_CipherInit_ex(local_2c,(EVP_CIPHER *)0x0,(ENGINE *)0x0,local_28,(uchar *)0x0
                                      ,0);
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
              goto LAB_0817cfee;
            }
            bp = (BIO *)0x0;
            if (local_28 != (uchar *)0x0) goto LAB_0817ca97;
            goto LAB_0817cab7;
          }
          bp = (BIO *)0x0;
          if (local_28 != (uchar *)0x0) goto LAB_0817ca97;
          goto LAB_0817cabb;
        }
        bp = (BIO *)0x0;
        ERR_put_error(0x21,0x70,0x20,"pk7_doit.c",0x217);
        len = 0;
LAB_0817cfc4:
        key = (uchar *)0x0;
        if (local_28 != (uchar *)0x0) goto LAB_0817ca97;
LAB_0817cad0:
        if (b != (BIO *)0x0) {
          BIO_free_all(b);
        }
        if (bp != (BIO *)0x0) {
          BIO_free_all(bp);
        }
        if (bp_00 != (BIO *)0x0) {
          BIO_free_all(bp_00);
        }
      }
      bp_00 = (BIO *)0x0;
      goto LAB_0817cb02;
    }
    iVar6 = 0x1b7;
    iVar5 = 0x7a;
  }
  ERR_put_error(0x21,0x70,iVar5,"pk7_doit.c",iVar6);
  bp_00 = (BIO *)0x0;
LAB_0817cb02:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bp_00;
}

