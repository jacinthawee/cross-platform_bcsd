
BIO * cms_EnvelopedData_init_bio(int param_1)

{
  BIO *a;
  int iVar1;
  uchar **p2;
  uchar *puVar2;
  EVP_PKEY_CTX *ctx;
  int iVar3;
  _STACK *p_Var4;
  int iVar5;
  int iVar6;
  BIO *pBVar7;
  uchar *puVar8;
  uchar *out;
  AES_KEY local_11c;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  a = (BIO *)cms_EncryptedContent_init_bio(iVar6);
  if ((a == (BIO *)0x0) || (*(int *)(iVar6 + 0xc) == 0)) {
    return a;
  }
  iVar5 = 0;
  p_Var4 = *(_STACK **)(*(int *)(param_1 + 4) + 8);
  do {
    iVar1 = sk_num(p_Var4);
    if (iVar1 <= iVar5) {
      pBVar7 = (BIO *)0x1;
LAB_000e8be0:
      *(undefined4 *)(iVar6 + 0xc) = 0;
      if (*(void **)(iVar6 + 0x10) != (void *)0x0) {
        OPENSSL_cleanse(*(void **)(iVar6 + 0x10),*(size_t *)(iVar6 + 0x14));
        CRYPTO_free(*(void **)(iVar6 + 0x10));
        *(undefined4 *)(iVar6 + 0x10) = 0;
        *(undefined4 *)(iVar6 + 0x14) = 0;
      }
      if (pBVar7 == (BIO *)0x0) {
        BIO_free(a);
        a = pBVar7;
      }
      return a;
    }
    p2 = (uchar **)sk_value(p_Var4,iVar5);
    out = *p2;
    if (out == (uchar *)0x2) {
      puVar8 = p2[1];
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
      if (*(uchar **)(puVar8 + 0x10) != (uchar *)0x0) {
        puVar2 = (uchar *)AES_set_encrypt_key(*(uchar **)(puVar8 + 0x10),
                                              *(int *)(puVar8 + 0x14) << 3,&local_11c);
        if (puVar2 == (uchar *)0x0) {
          out = (uchar *)CRYPTO_malloc(*(int *)(iVar1 + 0x14) + 8,"cms_env.c",0x2a2);
          if (out == (uchar *)0x0) {
            ERR_put_error(0x2e,0x88,0x41,"cms_env.c",0x2a7);
          }
          else {
            iVar1 = AES_wrap_key(&local_11c,(uchar *)0x0,out,*(uchar **)(iVar1 + 0x10),
                                 *(uint *)(iVar1 + 0x14));
            if (iVar1 < 1) {
              ERR_put_error(0x2e,0x88,0x9f,"cms_env.c",0x2af);
              CRYPTO_free(out);
              out = puVar2;
            }
            else {
              ASN1_STRING_set0(*(ASN1_STRING **)(puVar8 + 0xc),out,iVar1);
              out = (uchar *)0x1;
            }
          }
        }
        else {
          ERR_put_error(0x2e,0x88,0x73,"cms_env.c",0x29e);
          out = (uchar *)0x0;
        }
        OPENSSL_cleanse(&local_11c,0xf4);
        goto LAB_000e8c12;
      }
      ERR_put_error(0x2e,0x88,0x82,"cms_env.c",0x297);
LAB_000e8da8:
      pBVar7 = (BIO *)0x0;
      ERR_put_error(0x2e,0x7d,0x74,"cms_env.c",0x357);
      goto LAB_000e8be0;
    }
    if (out == (uchar *)0x3) {
      out = (uchar *)cms_RecipientInfo_pwri_crypt(param_1,p2,1);
    }
    else {
      if (out != (uchar *)0x0) {
        pBVar7 = (BIO *)0x0;
        ERR_put_error(0x2e,0x7d,0x9a,"cms_env.c",0x350);
        goto LAB_000e8be0;
      }
      puVar8 = p2[1];
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
      ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(puVar8 + 0x14),(ENGINE *)0x0);
      if (ctx == (EVP_PKEY_CTX *)0x0) goto LAB_000e8da8;
      iVar3 = EVP_PKEY_encrypt_init(ctx);
      if (iVar3 < 1) {
LAB_000e8d54:
        out = (uchar *)0x0;
      }
      else {
        iVar3 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,9,0,p2);
        if (iVar3 < 1) {
          ERR_put_error(0x2e,0x8d,0x6e,"cms_env.c",0x14a);
        }
        else {
          iVar3 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,local_11c.rd_key,*(uchar **)(iVar1 + 0x10),
                                   *(size_t *)(iVar1 + 0x14));
          if (iVar3 < 1) goto LAB_000e8d54;
          out = (uchar *)CRYPTO_malloc(local_11c.rd_key[0],"cms_env.c",0x151);
          if (out == (uchar *)0x0) {
            ERR_put_error(0x2e,0x8d,0x41,"cms_env.c",0x156);
          }
          else {
            iVar1 = EVP_PKEY_encrypt(ctx,out,local_11c.rd_key,*(uchar **)(iVar1 + 0x10),
                                     *(size_t *)(iVar1 + 0x14));
            if (iVar1 < 1) {
              EVP_PKEY_CTX_free(ctx);
              CRYPTO_free(out);
              goto LAB_000e8da8;
            }
            ASN1_STRING_set0(*(ASN1_STRING **)(puVar8 + 0xc),out,local_11c.rd_key[0]);
            out = (uchar *)0x1;
          }
        }
      }
      EVP_PKEY_CTX_free(ctx);
    }
LAB_000e8c12:
    if ((int)out < 1) goto LAB_000e8da8;
    iVar5 = iVar5 + 1;
  } while( true );
}

