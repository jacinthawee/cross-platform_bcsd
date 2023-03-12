
int CMS_RecipientInfo_decrypt(CMS_ContentInfo *cms,CMS_RecipientInfo *ri)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  uchar *out;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  AES_KEY local_114;
  
  puVar2 = *(uchar **)ri;
  if (puVar2 == (uchar *)0x2) {
    iVar4 = *(int *)(ri + 4);
    iVar3 = *(int *)(iVar4 + 0x10);
    iVar1 = *(int *)(*(int *)(cms + 4) + 0xc);
    if (iVar3 == 0) {
      ERR_put_error(0x2e,0x87,0x82,"cms_env.c",0x2a1);
    }
    else {
      iVar3 = OBJ_obj2nid(**(ASN1_OBJECT ***)(iVar4 + 8));
      if (iVar3 - 0x314U < 3) {
        iVar3 = *(int *)(&CSWTCH_8 + (iVar3 - 0x314U) * 4);
      }
      else {
        iVar3 = 0;
      }
      if (*(int *)(iVar4 + 0x14) == iVar3) {
        if (**(int **)(iVar4 + 0xc) < 0x10) {
          ERR_put_error(0x2e,0x87,0x75,"cms_env.c",0x2b0);
          out = (uchar *)0x0;
        }
        else {
          puVar2 = (uchar *)AES_set_decrypt_key(*(uchar **)(iVar4 + 0x10),iVar3 << 3,&local_114);
          if (puVar2 == (uchar *)0x0) {
            out = (uchar *)CRYPTO_malloc(**(int **)(iVar4 + 0xc) + -8,"cms_env.c",0x2ba);
            if (out == (uchar *)0x0) {
              ERR_put_error(0x2e,0x87,0x41,"cms_env.c",0x2bd);
            }
            else {
              iVar3 = AES_unwrap_key(&local_114,(uchar *)0x0,out,
                                     (uchar *)(*(uint **)(iVar4 + 0xc))[2],**(uint **)(iVar4 + 0xc))
              ;
              if (0 < iVar3) {
                *(uchar **)(iVar1 + 0x10) = out;
              }
              if (iVar3 < 1) {
                ERR_put_error(0x2e,0x87,0x9d,"cms_env.c",0x2c6);
                CRYPTO_free(out);
                out = puVar2;
              }
              else {
                *(int *)(iVar1 + 0x14) = iVar3;
                out = (uchar *)0x1;
              }
            }
          }
          else {
            out = (uchar *)0x0;
            ERR_put_error(0x2e,0x87,0x73,"cms_env.c",0x2b6);
          }
        }
        OPENSSL_cleanse(&local_114,0xf4);
        return (int)out;
      }
      iVar3 = 0;
      ERR_put_error(0x2e,0x87,0x76,"cms_env.c",0x2a8);
    }
    return iVar3;
  }
  if (puVar2 == (uchar *)0x3) {
    iVar3 = cms_RecipientInfo_pwri_crypt(cms,ri,0);
    return iVar3;
  }
  if (puVar2 != (uchar *)0x0) {
    ERR_put_error(0x2e,0x86,0x9b,"cms_env.c",0x2e7);
    return 0;
  }
  iVar3 = *(int *)(ri + 4);
  iVar4 = *(int *)(*(int *)(cms + 4) + 0xc);
  if (*(EVP_PKEY **)(iVar3 + 0x14) == (EVP_PKEY *)0x0) {
    ERR_put_error(0x2e,0x8c,0x85,"cms_env.c",0x166);
    return 0;
  }
  ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(iVar3 + 0x14),(ENGINE *)0x0);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    return 0;
  }
  iVar1 = EVP_PKEY_decrypt_init(ctx);
  if (0 < iVar1) {
    iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x200,10,0,ri);
    if (iVar1 < 1) {
      ERR_put_error(0x2e,0x8c,0x6e,"cms_env.c",0x173);
      goto LAB_000e6a3e;
    }
    iVar1 = EVP_PKEY_decrypt(ctx,(uchar *)0x0,local_114.rd_key,
                             (uchar *)(*(size_t **)(iVar3 + 0xc))[2],**(size_t **)(iVar3 + 0xc));
    if (0 < iVar1) {
      puVar2 = (uchar *)CRYPTO_malloc(local_114.rd_key[0],"cms_env.c",0x17c);
      if (puVar2 == (uchar *)0x0) {
        ERR_put_error(0x2e,0x8c,0x41,"cms_env.c",0x17f);
      }
      else {
        iVar3 = EVP_PKEY_decrypt(ctx,puVar2,local_114.rd_key,(uchar *)(*(size_t **)(iVar3 + 0xc))[2]
                                 ,**(size_t **)(iVar3 + 0xc));
        if (iVar3 < 1) {
          ERR_put_error(0x2e,0x8c,0x68,"cms_env.c",0x186);
          EVP_PKEY_CTX_free(ctx);
          CRYPTO_free(puVar2);
          return 0;
        }
        if (*(void **)(iVar4 + 0x10) != (void *)0x0) {
          OPENSSL_cleanse(*(void **)(iVar4 + 0x10),*(size_t *)(iVar4 + 0x14));
          CRYPTO_free(*(void **)(iVar4 + 0x10));
        }
        *(uchar **)(iVar4 + 0x10) = puVar2;
        *(uint *)(iVar4 + 0x14) = local_114.rd_key[0];
        puVar2 = (uchar *)0x1;
      }
      goto LAB_000e6a3e;
    }
  }
  puVar2 = (uchar *)0x0;
LAB_000e6a3e:
  EVP_PKEY_CTX_free(ctx);
  return (int)puVar2;
}

