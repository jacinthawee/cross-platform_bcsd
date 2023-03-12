
void cms_EncryptedContent_init_bio(int param_1)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  BIO *len;
  char *name;
  BIO *pBVar3;
  EVP_CIPHER *pEVar4;
  BIO *enc;
  ASN1_OBJECT **ppAVar5;
  BIO *pBVar6;
  BIO *pBVar7;
  BIO *pBVar8;
  int iVar9;
  BIO *local_44;
  EVP_CIPHER_CTX *local_40;
  uchar auStack_3c [16];
  int local_2c;
  
  enc = *(BIO **)(param_1 + 0xc);
  ppAVar5 = *(ASN1_OBJECT ***)(param_1 + 4);
  if (enc != (BIO *)0x0) {
    enc = (BIO *)0x1;
  }
  local_2c = __stack_chk_guard;
  type = BIO_f_cipher();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x58);
    goto LAB_000e6f4e;
  }
  BIO_ctrl(bp,0x81,0,&local_40);
  if (enc == (BIO *)0x0) {
    iVar1 = OBJ_obj2nid(*ppAVar5);
    name = OBJ_nid2sn(iVar1);
    pBVar6 = (BIO *)EVP_get_cipherbyname(name);
    if (pBVar6 == (BIO *)0x0) {
      iVar9 = 0x69;
      iVar1 = 0x94;
      goto LAB_000e70d4;
    }
    iVar1 = EVP_CipherInit_ex(local_40,(EVP_CIPHER *)pBVar6,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,
                              0);
    if (iVar1 < 1) goto LAB_000e71c4;
    iVar1 = EVP_CIPHER_asn1_to_param(local_40,(ASN1_TYPE *)ppAVar5[1]);
    pBVar6 = enc;
    if (iVar1 < 1) {
      iVar9 = 0x80;
      iVar1 = 0x66;
      goto LAB_000e70d4;
    }
    len = (BIO *)EVP_CIPHER_CTX_key_length(local_40);
LAB_000e6fb6:
    pBVar3 = (BIO *)CRYPTO_malloc((int)len,"cms_enc.c",0x86);
    if (pBVar3 == (BIO *)0x0) {
      ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x88);
      local_44 = (BIO *)0x1;
      pBVar6 = pBVar3;
      pBVar7 = pBVar3;
    }
    else {
      iVar1 = EVP_CIPHER_CTX_rand_key(local_40,(uchar *)pBVar3);
      if (iVar1 < 1) {
        local_44 = (BIO *)0x1;
        pBVar6 = (BIO *)0x0;
        pBVar7 = (BIO *)0x0;
      }
      else {
        pBVar8 = *(BIO **)(param_1 + 0x10);
        if (pBVar8 == (BIO *)0x0) {
          *(BIO **)(param_1 + 0x10) = pBVar3;
          *(BIO **)(param_1 + 0x14) = len;
          if (enc == (BIO *)0x0) {
            ERR_clear_error();
            pBVar3 = enc;
            goto LAB_000e6eea;
          }
          pBVar7 = (BIO *)0x1;
          iVar1 = EVP_CipherInit_ex(local_40,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)pBVar3,
                                    (uchar *)pBVar6,(int)enc);
          enc = pBVar8;
          if (iVar1 < 1) goto LAB_000e7012;
LAB_000e7052:
          pBVar6 = (BIO *)ASN1_TYPE_new();
          ppAVar5[1] = (ASN1_OBJECT *)pBVar6;
          pBVar3 = pBVar8;
          if (pBVar6 == (BIO *)0x0) {
            ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0xb9);
            local_44 = (BIO *)0x1;
          }
          else {
            iVar1 = EVP_CIPHER_param_to_asn1(local_40,(ASN1_TYPE *)pBVar6);
            if (iVar1 < 1) {
              iVar9 = 0xbe;
              iVar1 = 0x66;
              enc = pBVar8;
              goto LAB_000e7024;
            }
            if (ppAVar5[1]->sn == (char *)0xffffffff) {
              ASN1_TYPE_free((ASN1_TYPE *)ppAVar5[1]);
              local_44 = (BIO *)0x0;
              ppAVar5[1] = (ASN1_OBJECT *)0x0;
              pBVar6 = (BIO *)0x1;
            }
            else {
              local_44 = (BIO *)0x0;
              pBVar6 = (BIO *)0x1;
            }
          }
        }
        else {
LAB_000e6eea:
          pBVar7 = enc;
          if ((*(BIO **)(param_1 + 0x14) == len) ||
             (iVar1 = EVP_CIPHER_CTX_set_key_length(local_40,(int)*(BIO **)(param_1 + 0x14)),
             0 < iVar1)) {
            iVar1 = EVP_CipherInit_ex(local_40,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                      *(uchar **)(param_1 + 0x10),(uchar *)pBVar6,(int)enc);
            if (iVar1 < 1) {
              enc = pBVar3;
              pBVar7 = (BIO *)0x0;
LAB_000e7012:
              iVar9 = 0xb3;
              iVar1 = 0x65;
LAB_000e7024:
              local_44 = (BIO *)0x1;
              ERR_put_error(0x2e,0x78,iVar1,"cms_enc.c",iVar9);
              pBVar6 = (BIO *)0x0;
              pBVar3 = enc;
            }
            else {
              if (enc != (BIO *)0x0) {
                pBVar7 = (BIO *)0x0;
                pBVar8 = pBVar3;
                goto LAB_000e7052;
              }
              pBVar6 = (BIO *)0x1;
              local_44 = enc;
            }
          }
          else if ((enc == (BIO *)0x0) &&
                  (local_44 = *(BIO **)(param_1 + 0x18), local_44 == (BIO *)0x0)) {
            OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
            CRYPTO_free(*(void **)(param_1 + 0x10));
            *(BIO **)(param_1 + 0x10) = pBVar3;
            *(BIO **)(param_1 + 0x14) = len;
            ERR_clear_error();
            iVar1 = EVP_CipherInit_ex(local_40,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                      *(uchar **)(param_1 + 0x10),(uchar *)pBVar6,0);
            if (iVar1 < 1) goto LAB_000e7012;
            pBVar6 = (BIO *)0x1;
            pBVar3 = enc;
          }
          else {
            ERR_put_error(0x2e,0x78,0x76,"cms_enc.c",0xa3);
            local_44 = (BIO *)0x1;
            pBVar6 = (BIO *)0x0;
            pBVar7 = (BIO *)0x0;
          }
        }
      }
    }
  }
  else {
    pEVar4 = *(EVP_CIPHER **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    pBVar6 = (BIO *)0x0;
    iVar1 = EVP_CipherInit_ex(local_40,pEVar4,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,1);
    if (0 < iVar1) {
      pEVar4 = EVP_CIPHER_CTX_cipher(local_40);
      iVar1 = EVP_CIPHER_type(pEVar4);
      pAVar2 = OBJ_nid2obj(iVar1);
      *ppAVar5 = pAVar2;
      iVar1 = EVP_CIPHER_CTX_iv_length(local_40);
      if (0 < iVar1) {
        iVar1 = RAND_bytes(auStack_3c,iVar1);
        if (iVar1 < 1) {
          local_44 = (BIO *)0x1;
          pBVar3 = pBVar6;
          len = pBVar6;
          pBVar7 = pBVar6;
          goto LAB_000e6f24;
        }
        pBVar6 = (BIO *)auStack_3c;
      }
      len = (BIO *)EVP_CIPHER_CTX_key_length(local_40);
      pBVar3 = (BIO *)0x0;
      if (*(int *)(param_1 + 0x10) == 0) goto LAB_000e6fb6;
      goto LAB_000e6eea;
    }
LAB_000e71c4:
    iVar9 = 0x70;
    iVar1 = 0x65;
    pBVar6 = (BIO *)0x0;
LAB_000e70d4:
    ERR_put_error(0x2e,0x78,iVar1,"cms_enc.c",iVar9);
    local_44 = (BIO *)0x1;
    pBVar3 = pBVar6;
    len = pBVar6;
    pBVar7 = pBVar6;
  }
LAB_000e6f24:
  if ((*(void **)(param_1 + 0x10) != (void *)0x0) &&
     ((((uint)pBVar7 ^ 1 | (uint)local_44) & 1) != 0)) {
    OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
    CRYPTO_free(*(void **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if (pBVar3 != (BIO *)0x0) {
    OPENSSL_cleanse(pBVar3,(size_t)len);
    CRYPTO_free(pBVar3);
  }
  if (pBVar6 == (BIO *)0x0) {
    BIO_free(bp);
    bp = pBVar6;
  }
LAB_000e6f4e:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(bp);
}

