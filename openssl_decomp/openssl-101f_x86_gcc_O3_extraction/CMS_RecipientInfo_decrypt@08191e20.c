
int CMS_RecipientInfo_decrypt(CMS_ContentInfo *cms,CMS_RecipientInfo *ri)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  int iVar5;
  size_t local_118;
  AES_KEY local_114;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = *(int *)ri;
  if (iVar4 != 2) {
    if (iVar4 == 3) {
      iVar4 = cms_RecipientInfo_pwri_crypt(cms,ri,0);
      goto LAB_08191e83;
    }
    if (iVar4 != 0) {
      iVar4 = 0;
      ERR_put_error(0x2e,0x86,0x9b,"cms_env.c",0x321);
      goto LAB_08191e83;
    }
    iVar3 = *(int *)(ri + 4);
    iVar5 = *(int *)(*(int *)(cms + 4) + 0xc);
    if (*(EVP_PKEY **)(iVar3 + 0x14) == (EVP_PKEY *)0x0) {
      ERR_put_error(0x2e,0x8c,0x85,"cms_env.c",0x17b);
      goto LAB_08191e83;
    }
    ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(iVar3 + 0x14),(ENGINE *)0x0);
    if (ctx == (EVP_PKEY_CTX *)0x0) goto LAB_08191e83;
    iVar1 = EVP_PKEY_decrypt_init(ctx);
    if (iVar1 < 1) {
LAB_08192088:
      iVar4 = 0;
    }
    else {
      iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,0x200,10,0,ri);
      if (iVar1 < 1) {
        iVar5 = 0x189;
        iVar3 = 0x6e;
LAB_081921ff:
        iVar4 = 0;
        ERR_put_error(0x2e,0x8c,iVar3,"cms_env.c",iVar5);
      }
      else {
        iVar1 = EVP_PKEY_decrypt(ctx,(uchar *)0x0,&local_118,(uchar *)(*(size_t **)(iVar3 + 0xc))[2]
                                 ,**(size_t **)(iVar3 + 0xc));
        if (iVar1 < 1) goto LAB_08192088;
        puVar2 = (uchar *)CRYPTO_malloc(local_118,"cms_env.c",0x192);
        if (puVar2 == (uchar *)0x0) {
          iVar5 = 0x197;
          iVar3 = 0x41;
          goto LAB_081921ff;
        }
        iVar3 = EVP_PKEY_decrypt(ctx,puVar2,&local_118,(uchar *)(*(size_t **)(iVar3 + 0xc))[2],
                                 **(size_t **)(iVar3 + 0xc));
        if (iVar3 < 1) {
          ERR_put_error(0x2e,0x8c,0x68,"cms_env.c",0x19f);
          EVP_PKEY_CTX_free(ctx);
          CRYPTO_free(puVar2);
          goto LAB_08191e83;
        }
        if (*(void **)(iVar5 + 0x10) != (void *)0x0) {
          OPENSSL_cleanse(*(void **)(iVar5 + 0x10),*(size_t *)(iVar5 + 0x14));
          CRYPTO_free(*(void **)(iVar5 + 0x10));
        }
        iVar4 = 1;
        *(uchar **)(iVar5 + 0x10) = puVar2;
        *(size_t *)(iVar5 + 0x14) = local_118;
      }
    }
    EVP_PKEY_CTX_free(ctx);
    goto LAB_08191e83;
  }
  iVar4 = *(int *)(ri + 4);
  iVar3 = *(int *)(*(int *)(cms + 4) + 0xc);
  if (*(int *)(iVar4 + 0x10) == 0) {
    iVar5 = 0x2d3;
    iVar3 = 0x82;
LAB_0819206b:
    iVar4 = 0;
    ERR_put_error(0x2e,0x87,iVar3,"cms_env.c",iVar5);
    goto LAB_08191e83;
  }
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(iVar4 + 8));
  iVar5 = 0;
  if (iVar1 - 0x314U < 3) {
    iVar5 = *(int *)(CSWTCH_8 + (iVar1 - 0x314U) * 4);
    if (*(int *)(iVar4 + 0x14) != iVar5) goto LAB_0819205c;
  }
  else if (*(int *)(iVar4 + 0x14) != 0) {
LAB_0819205c:
    iVar5 = 0x2db;
    iVar3 = 0x76;
    goto LAB_0819206b;
  }
  if (**(int **)(iVar4 + 0xc) < 0x10) {
    iVar4 = 0;
    ERR_put_error(0x2e,0x87,0x75,"cms_env.c",0x2e4);
  }
  else {
    iVar5 = AES_set_decrypt_key(*(uchar **)(iVar4 + 0x10),iVar5 << 3,&local_114);
    if (iVar5 == 0) {
      puVar2 = (uchar *)CRYPTO_malloc(**(int **)(iVar4 + 0xc) + -8,"cms_env.c",0x2ef);
      if (puVar2 != (uchar *)0x0) {
        iVar4 = AES_unwrap_key(&local_114,(uchar *)0x0,puVar2,(uchar *)(*(uint **)(iVar4 + 0xc))[2],
                               **(uint **)(iVar4 + 0xc));
        if (iVar4 < 1) {
          iVar4 = 0;
          ERR_put_error(0x2e,0x87,0x9d,"cms_env.c",0x2ff);
          CRYPTO_free(puVar2);
        }
        else {
          *(uchar **)(iVar3 + 0x10) = puVar2;
          *(int *)(iVar3 + 0x14) = iVar4;
          iVar4 = 1;
        }
        goto LAB_08192035;
      }
      iVar5 = 0x2f4;
      iVar3 = 0x41;
    }
    else {
      iVar5 = 0x2eb;
      iVar3 = 0x73;
    }
    iVar4 = 0;
    ERR_put_error(0x2e,0x87,iVar3,"cms_env.c",iVar5);
  }
LAB_08192035:
  OPENSSL_cleanse(&local_114,0xf4);
LAB_08191e83:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

