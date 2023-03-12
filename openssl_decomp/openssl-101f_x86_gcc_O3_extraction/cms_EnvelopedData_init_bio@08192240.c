
BIO * cms_EnvelopedData_init_bio(int param_1)

{
  int iVar1;
  _STACK *p_Var2;
  BIO *a;
  int iVar3;
  int *p2;
  EVP_PKEY_CTX *ctx;
  int iVar4;
  uchar *puVar5;
  int iVar6;
  int iVar7;
  int in_GS_OFFSET;
  size_t local_118;
  AES_KEY local_114;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  a = (BIO *)cms_EncryptedContent_init_bio(iVar1);
  if (a == (BIO *)0x0) {
    a = (BIO *)0x0;
  }
  else if (*(int *)(iVar1 + 0xc) != 0) {
    p_Var2 = *(_STACK **)(*(int *)(param_1 + 4) + 8);
    for (iVar7 = 0; iVar3 = sk_num(p_Var2), iVar7 < iVar3; iVar7 = iVar7 + 1) {
      p2 = (int *)sk_value(p_Var2,iVar7);
      iVar3 = *p2;
      if (iVar3 == 2) {
        iVar3 = p2[1];
        iVar6 = *(int *)(*(int *)(param_1 + 4) + 0xc);
        if (*(uchar **)(iVar3 + 0x10) != (uchar *)0x0) {
          iVar4 = AES_set_encrypt_key(*(uchar **)(iVar3 + 0x10),*(int *)(iVar3 + 0x14) << 3,
                                      &local_114);
          if (iVar4 == 0) {
            puVar5 = (uchar *)CRYPTO_malloc(*(int *)(iVar6 + 0x14) + 8,"cms_env.c",0x2a2);
            if (puVar5 == (uchar *)0x0) {
              iVar6 = 0x2a7;
              iVar3 = 0x41;
              goto LAB_081923cb;
            }
            iVar6 = AES_wrap_key(&local_114,(uchar *)0x0,puVar5,*(uchar **)(iVar6 + 0x10),
                                 *(uint *)(iVar6 + 0x14));
            if (iVar6 < 1) {
              iVar4 = 0;
              ERR_put_error(0x2e,0x88,0x9f,"cms_env.c",0x2af);
              CRYPTO_free(puVar5);
            }
            else {
              iVar4 = 1;
              ASN1_STRING_set0(*(ASN1_STRING **)(iVar3 + 0xc),puVar5,iVar6);
            }
          }
          else {
            iVar6 = 0x29e;
            iVar3 = 0x73;
LAB_081923cb:
            iVar4 = 0;
            ERR_put_error(0x2e,0x88,iVar3,"cms_env.c",iVar6);
          }
          OPENSSL_cleanse(&local_114,0xf4);
          goto LAB_08192371;
        }
        ERR_put_error(0x2e,0x88,0x82,"cms_env.c",0x297);
LAB_081925f7:
        ERR_put_error(0x2e,0x7d,0x74,"cms_env.c",0x357);
LAB_081922f5:
        *(undefined4 *)(iVar1 + 0xc) = 0;
        if (*(void **)(iVar1 + 0x10) != (void *)0x0) {
          OPENSSL_cleanse(*(void **)(iVar1 + 0x10),*(size_t *)(iVar1 + 0x14));
          CRYPTO_free(*(void **)(iVar1 + 0x10));
          *(undefined4 *)(iVar1 + 0x10) = 0;
          *(undefined4 *)(iVar1 + 0x14) = 0;
        }
        BIO_free(a);
        a = (BIO *)0x0;
        goto LAB_08192340;
      }
      if (iVar3 != 3) {
        if (iVar3 == 0) {
          iVar3 = p2[1];
          iVar6 = *(int *)(*(int *)(param_1 + 4) + 0xc);
          ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(iVar3 + 0x14),(ENGINE *)0x0);
          if (ctx == (EVP_PKEY_CTX *)0x0) goto LAB_081925f7;
          iVar4 = EVP_PKEY_encrypt_init(ctx);
          if (iVar4 < 1) {
LAB_08192590:
            iVar4 = 0;
          }
          else {
            iVar4 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,9,0,p2);
            if (iVar4 < 1) {
              iVar6 = 0x14a;
              iVar3 = 0x6e;
LAB_0819269f:
              iVar4 = 0;
              ERR_put_error(0x2e,0x8d,iVar3,"cms_env.c",iVar6);
            }
            else {
              iVar4 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,&local_118,*(uchar **)(iVar6 + 0x10),
                                       *(size_t *)(iVar6 + 0x14));
              if (iVar4 < 1) goto LAB_08192590;
              puVar5 = (uchar *)CRYPTO_malloc(local_118,"cms_env.c",0x151);
              if (puVar5 == (uchar *)0x0) {
                iVar6 = 0x156;
                iVar3 = 0x41;
                goto LAB_0819269f;
              }
              iVar6 = EVP_PKEY_encrypt(ctx,puVar5,&local_118,*(uchar **)(iVar6 + 0x10),
                                       *(size_t *)(iVar6 + 0x14));
              if (iVar6 < 1) {
                EVP_PKEY_CTX_free(ctx);
                CRYPTO_free(puVar5);
                goto LAB_081925f7;
              }
              iVar4 = 1;
              ASN1_STRING_set0(*(ASN1_STRING **)(iVar3 + 0xc),puVar5,local_118);
            }
          }
          EVP_PKEY_CTX_free(ctx);
          goto LAB_08192371;
        }
        ERR_put_error(0x2e,0x7d,0x9a,"cms_env.c",0x350);
        goto LAB_081922f5;
      }
      iVar4 = cms_RecipientInfo_pwri_crypt(param_1,p2,1);
LAB_08192371:
      if (iVar4 < 1) goto LAB_081925f7;
    }
    *(undefined4 *)(iVar1 + 0xc) = 0;
    if (*(void **)(iVar1 + 0x10) != (void *)0x0) {
      OPENSSL_cleanse(*(void **)(iVar1 + 0x10),*(size_t *)(iVar1 + 0x14));
      CRYPTO_free(*(void **)(iVar1 + 0x10));
      *(undefined4 *)(iVar1 + 0x10) = 0;
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
  }
LAB_08192340:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a;
}

