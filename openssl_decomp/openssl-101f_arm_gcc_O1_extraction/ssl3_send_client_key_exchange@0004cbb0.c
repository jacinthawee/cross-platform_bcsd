
void ssl3_send_client_key_exchange(int *param_1)

{
  uchar uVar1;
  int iVar2;
  undefined4 uVar3;
  EC_GROUP *group;
  EC_POINT *pEVar4;
  size_t sVar5;
  BN_CTX *c;
  DH *dh;
  DH *pDVar6;
  char *pcVar7;
  X509 *x;
  EVP_PKEY_CTX *ctx;
  EVP_MD_CTX *ctx_00;
  EVP_MD *type;
  undefined *__dest;
  EVP_PKEY *pEVar8;
  undefined uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined *puVar13;
  uchar *puVar14;
  RSA *rsa;
  EC_KEY *pEVar15;
  DH *pkey;
  uint local_2d8;
  uint uStack_2d4;
  uchar auStack_2d0 [32];
  uchar auStack_2b0 [128];
  uchar local_230 [516];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (param_1[0xd] != 0x1180) {
LAB_0004cc9e:
    uVar3 = ssl3_do_write(param_1,0x16);
    goto LAB_0004cca6;
  }
  puVar13 = *(undefined **)(param_1[0xf] + 4);
  uVar10 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  puVar14 = puVar13 + 4;
  if ((DH *)(uVar10 & 1) != (DH *)0x0) {
    rsa = *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x6c);
    if (rsa == (RSA *)0x0) {
      pEVar8 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
      if (((pEVar8 == (EVP_PKEY *)0x0) || (pEVar8->type != 6)) ||
         (rsa = (pEVar8->pkey).rsa, rsa == (rsa_st *)0x0)) {
        ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0x8d5);
        goto LAB_0004d130;
      }
      EVP_PKEY_free(pEVar8);
    }
    local_230[1] = (uchar)param_1[0x44];
    local_230[0] = (uchar)((uint)param_1[0x44] >> 8);
    iVar2 = RAND_bytes(local_230 + 2,0x2e);
    if (0 < iVar2) {
      if (0x300 < *param_1) {
        puVar14 = puVar13 + 6;
      }
      *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
      iVar2 = RSA_public_encrypt(0x30,local_230,puVar14,rsa,1);
      if (0 < iVar2) {
        iVar11 = *param_1;
        iVar12 = iVar11;
        if (0x300 < iVar11) {
          puVar13[5] = (char)iVar2;
          iVar12 = iVar2 >> 8;
        }
        if (0x300 < iVar11) {
          puVar13[4] = (char)iVar12;
        }
        iVar12 = param_1[0x30];
        if (0x300 < iVar11) {
          iVar2 = iVar2 + 2;
        }
        uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                          (param_1,iVar12 + 0x14,local_230,0x30);
        *(undefined4 *)(iVar12 + 0x10) = uVar3;
        OPENSSL_cleanse(local_230,0x30);
LAB_0004cc7a:
        puVar13[3] = (char)iVar2;
        *puVar13 = 0x10;
        puVar13[1] = (char)((uint)iVar2 >> 0x10);
        puVar13[2] = (char)((uint)iVar2 >> 8);
        param_1[0x11] = iVar2 + 4;
        param_1[0xd] = 0x1181;
        param_1[0x12] = 0;
        goto LAB_0004cc9e;
      }
      ERR_put_error(0x14,0x98,0x77,"s3_clnt.c",0x8ef);
    }
    goto LAB_0004d130;
  }
  pkey = (DH *)(uVar10 & 0xe);
  if (pkey != (DH *)0x0) {
    pkey = *(DH **)(param_1[0x30] + 0x98);
    if (pkey == (DH *)0x0) {
      ssl3_send_alert(param_1,2,10);
      ERR_put_error(0x14,0x98,0xf4,"s3_clnt.c",0x98f);
    }
    else {
      pkey = *(DH **)&pkey[1].field_0x24;
      if (pkey == (DH *)0x0) {
        ssl3_send_alert(param_1,2,0x28);
        ERR_put_error(0x14,0x98,0xee,"s3_clnt.c",0x999);
      }
      else {
        dh = DHparams_dup(pkey);
        if (dh == (DH *)0x0) {
          ERR_put_error(0x14,0x98,5,"s3_clnt.c",0x9a0);
          pkey = dh;
        }
        else {
          pDVar6 = (DH *)DH_generate_key(dh);
          if (pDVar6 == (DH *)0x0) {
            ERR_put_error(0x14,0x98,5,"s3_clnt.c",0x9a5);
            DH_free(dh);
            pkey = pDVar6;
          }
          else {
            sVar5 = DH_compute_key(puVar14,*(BIGNUM **)&pkey->field_0x14,dh);
            if (0 < (int)sVar5) {
              iVar2 = param_1[0x30];
              uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                (param_1,iVar2 + 0x14,puVar14,sVar5);
              *(undefined4 *)(iVar2 + 0x10) = uVar3;
              memset(puVar14,0,sVar5);
              iVar2 = BN_num_bits(*(BIGNUM **)&dh->field_0x14);
              iVar12 = iVar2 + 7;
              if (iVar2 + 7 < 0) {
                iVar12 = iVar2 + 0xe;
              }
              puVar13[5] = (char)(iVar12 >> 3);
              iVar2 = (iVar12 >> 3) + 2;
              puVar13[4] = (char)(iVar12 >> 0xb);
              BN_bn2bin(*(BIGNUM **)&dh->field_0x14,puVar13 + 6);
              DH_free(dh);
              goto LAB_0004cc7a;
            }
            ERR_put_error(0x14,0x98,5,"s3_clnt.c",0x9b1);
            DH_free(dh);
            pkey = (DH *)(uVar10 & 1);
          }
        }
      }
    }
    goto LAB_0004cf46;
  }
  if ((uVar10 & 0xe0) == 0) {
    if ((int)(uVar10 << 0x16) < 0) {
      x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x60);
      if ((x == (X509 *)0x0) &&
         (x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x54), x == (X509 *)0x0)) {
        ERR_put_error(0x14,0x98,0x14a,"s3_clnt.c",0xa93);
      }
      else {
        pEVar8 = X509_get_pubkey(x);
        ctx = EVP_PKEY_CTX_new(pEVar8,(ENGINE *)0x0);
        EVP_PKEY_encrypt_init(ctx);
        RAND_bytes(auStack_2d0,0x20);
        if ((*(int *)(param_1[0x16] + 0x358) != 0) &&
           ((*(EVP_PKEY **)(*(int *)param_1[0x26] + 4) != (EVP_PKEY *)0x0 &&
            (iVar2 = EVP_PKEY_derive_set_peer(ctx,*(EVP_PKEY **)(*(int *)param_1[0x26] + 4)),
            iVar2 < 1)))) {
          ERR_clear_error();
        }
        ctx_00 = EVP_MD_CTX_create();
        pcVar7 = OBJ_nid2sn(0x329);
        type = EVP_get_digestbyname(pcVar7);
        EVP_DigestInit(ctx_00,type);
        EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xc0),0x20);
        EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xa0),0x20);
        EVP_DigestFinal_ex(ctx_00,auStack_2b0,&uStack_2d4);
        EVP_MD_CTX_destroy(ctx_00);
        iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,8,8,auStack_2b0);
        if (iVar2 < 0) {
          iVar2 = 0xab7;
        }
        else {
          puVar13[4] = 0x30;
          puVar14 = auStack_2d0;
          local_2d8 = 0xff;
          iVar2 = EVP_PKEY_encrypt(ctx,local_230,&local_2d8,puVar14,0x20);
          if (-1 < iVar2) {
            uVar9 = (char)puVar14;
            if (local_2d8 < 0x80) {
              uVar9 = (char)local_2d8;
            }
            if (local_2d8 < 0x80) {
              __dest = puVar13 + 6;
            }
            else {
              puVar13[6] = (char)local_2d8;
              uVar9 = 0x81;
              __dest = puVar13 + 7;
            }
            puVar13[5] = uVar9;
            if (local_2d8 < 0x80) {
              iVar2 = local_2d8 + 2;
            }
            else {
              iVar2 = local_2d8 + 3;
            }
            memcpy(__dest,local_230,local_2d8);
            iVar12 = EVP_PKEY_CTX_ctrl(ctx,-1,-1,2,2,(void *)0x0);
            if (0 < iVar12) {
              *(uint *)param_1[0x16] = *(uint *)param_1[0x16] | 0x10;
            }
            EVP_PKEY_CTX_free(ctx);
            iVar12 = param_1[0x30];
            uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                              (param_1,iVar12 + 0x14,auStack_2d0,0x20);
            *(undefined4 *)(iVar12 + 0x10) = uVar3;
            EVP_PKEY_free(pEVar8);
            goto LAB_0004cc7a;
          }
          iVar2 = 0xac0;
        }
        ERR_put_error(0x14,0x98,0x112,"s3_clnt.c",iVar2);
      }
LAB_0004d130:
      pkey = (DH *)0x0;
    }
    else if ((int)(uVar10 << 0x15) < 0) {
      pkey = (DH *)param_1[0x6e];
      if (pkey == (DH *)0x0) {
        ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0xae9);
      }
      else {
        iVar2 = BN_num_bits((BIGNUM *)pkey);
        iVar12 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar12 = iVar2 + 0xe;
        }
        puVar13[5] = (char)(iVar12 >> 3);
        iVar2 = (iVar12 >> 3) + 2;
        puVar13[4] = (char)(iVar12 >> 0xb);
        BN_bn2bin((BIGNUM *)param_1[0x6e],puVar13 + 6);
        iVar12 = param_1[0x30];
        if (*(void **)(iVar12 + 0xf0) != (void *)0x0) {
          CRYPTO_free(*(void **)(iVar12 + 0xf0));
          iVar12 = param_1[0x30];
        }
        pcVar7 = BUF_strdup((char *)param_1[0x69]);
        iVar11 = param_1[0x30];
        *(char **)(iVar12 + 0xf0) = pcVar7;
        pkey = *(DH **)(iVar11 + 0xf0);
        if (pkey == (DH *)0x0) {
          iVar2 = 0xaf2;
          goto LAB_0004d40e;
        }
        iVar12 = SRP_generate_client_master_secret(param_1,iVar11 + 0x14);
        *(int *)(iVar11 + 0x10) = iVar12;
        if (-1 < iVar12) goto LAB_0004cc7a;
        ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0xaf8);
        pkey = (DH *)0x0;
      }
    }
    else {
      if ((DH *)(uVar10 & 0x100) != (DH *)0x0) {
        if ((code *)param_1[0x37] == (code *)0x0) {
          ERR_put_error(0x14,0x98,0xe0,"s3_clnt.c",0xb0a);
        }
        else {
          uVar10 = (*(code *)param_1[0x37])
                             (param_1,*(undefined4 *)(param_1[0x39] + 0x14c),auStack_2b0,0x80,
                              local_230,0x204);
          if (uVar10 < 0x101) {
            if (uVar10 == 0) {
              ERR_put_error(0x14,0x98,0xdf,"s3_clnt.c",0xb1a);
            }
            else {
              memmove(local_230 + uVar10 + 4,local_230,uVar10);
              uVar1 = (uchar)(uVar10 >> 8);
              local_230[0] = uVar1;
              local_230[1] = (uchar)uVar10;
              __memset_chk(local_230 + 2,0,uVar10,0x202);
              iVar2 = param_1[0x30];
              (local_230 + 2)[uVar10] = uVar1;
              local_230[uVar10 + 3] = (uchar)uVar10;
              if (*(void **)(iVar2 + 0x8c) != (void *)0x0) {
                CRYPTO_free(*(void **)(iVar2 + 0x8c));
                iVar2 = param_1[0x30];
              }
              pcVar7 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
              iVar11 = param_1[0x30];
              iVar12 = *(int *)(param_1[0x39] + 0x14c);
              *(char **)(iVar2 + 0x8c) = pcVar7;
              if ((iVar12 == 0) || (*(int *)(iVar11 + 0x8c) != 0)) {
                if (*(void **)(iVar11 + 0x90) != (void *)0x0) {
                  CRYPTO_free(*(void **)(iVar11 + 0x90));
                  iVar11 = param_1[0x30];
                }
                pcVar7 = BUF_strdup((char *)auStack_2b0);
                iVar2 = param_1[0x30];
                *(char **)(iVar11 + 0x90) = pcVar7;
                if (*(int *)(iVar2 + 0x90) != 0) {
                  uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                    (param_1,iVar2 + 0x14,local_230,uVar10 * 2 + 4);
                  *(undefined4 *)(iVar2 + 0x10) = uVar3;
                  sVar5 = strlen((char *)auStack_2b0);
                  puVar13[5] = (char)sVar5;
                  puVar13[4] = (char)(sVar5 >> 8);
                  memcpy(puVar13 + 6,auStack_2b0,sVar5);
                  iVar2 = sVar5 + 2;
                  OPENSSL_cleanse(auStack_2b0,0x80);
                  OPENSSL_cleanse(local_230,0x204);
                  goto LAB_0004cc7a;
                }
                iVar2 = 0xb38;
              }
              else {
                iVar2 = 0xb2e;
              }
              ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",iVar2);
            }
          }
          else {
            ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0xb14);
          }
          OPENSSL_cleanse(auStack_2b0,0x80);
          OPENSSL_cleanse(local_230,0x204);
          ssl3_send_alert(param_1,2,0x28);
        }
        goto LAB_0004d130;
      }
      ssl3_send_alert(param_1,2,0x28);
      ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0xb54);
      pkey = (DH *)(uVar10 & 0x100);
    }
LAB_0004cf46:
    BN_CTX_free((BN_CTX *)0x0);
  }
  else {
    pEVar15 = *(EC_KEY **)(*(int *)(param_1[0x30] + 0x98) + 0x74);
    if ((pEVar15 == (EC_KEY *)0x0) &&
       (((pkey = (DH *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x48)),
         pkey == (DH *)0x0 || (*(int *)pkey != 0x198)) ||
        (pEVar15 = *(EC_KEY **)&pkey->field_0x14, pEVar15 == (EC_KEY *)0x0)))) {
      iVar2 = 0x9fb;
LAB_0004d15c:
      ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",iVar2);
      goto LAB_0004cf46;
    }
    group = EC_KEY_get0_group(pEVar15);
    pEVar4 = EC_KEY_get0_public_key(pEVar15);
    if (group == (EC_GROUP *)0x0 || pEVar4 == (EC_POINT *)0x0) {
      iVar2 = 0xa08;
      goto LAB_0004d15c;
    }
    pEVar15 = EC_KEY_new();
    iVar2 = 0xa0e;
    if (pEVar15 == (EC_KEY *)0x0) {
LAB_0004d40e:
      ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",iVar2);
      goto LAB_0004cf46;
    }
    iVar2 = EC_KEY_set_group(pEVar15,group);
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x98,0x10,"s3_clnt.c",0xa14);
LAB_0004d2ee:
      BN_CTX_free((BN_CTX *)0x0);
    }
    else {
      iVar2 = EC_KEY_generate_key(pEVar15);
      iVar12 = 0xa30;
      if (iVar2 == 0) {
LAB_0004d2de:
        ERR_put_error(0x14,0x98,0x2b,"s3_clnt.c",iVar12);
        goto LAB_0004d2ee;
      }
      iVar2 = EC_GROUP_get_degree(group);
      if (iVar2 < 1) {
        iVar12 = 0xa3d;
        goto LAB_0004d2de;
      }
      sVar5 = ECDH_compute_key(puVar14,iVar2 + 7 >> 3,pEVar4,pEVar15,(KDF *)0x0);
      if ((int)sVar5 < 1) {
        iVar12 = 0xa44;
        goto LAB_0004d2de;
      }
      iVar2 = param_1[0x30];
      uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar2 + 0x14,puVar14,sVar5);
      *(undefined4 *)(iVar2 + 0x10) = uVar3;
      memset(puVar14,0,sVar5);
      pEVar4 = EC_KEY_get0_public_key(pEVar15);
      sVar5 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                 (BN_CTX *)0x0);
      puVar14 = (uchar *)CRYPTO_malloc(sVar5,"s3_clnt.c",0xa62);
      c = BN_CTX_new();
      if (puVar14 != (uchar *)0x0 && c != (BN_CTX *)0x0) {
        pEVar4 = EC_KEY_get0_public_key(pEVar15);
        sVar5 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,puVar14,sVar5,c);
        puVar13[4] = (char)sVar5;
        memcpy(puVar13 + 5,puVar14,sVar5);
        BN_CTX_free(c);
        CRYPTO_free(puVar14);
        EC_KEY_free(pEVar15);
        iVar2 = sVar5 + 1;
        EVP_PKEY_free((EVP_PKEY *)pkey);
        goto LAB_0004cc7a;
      }
      ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xa67);
      BN_CTX_free(c);
      if (puVar14 != (uchar *)0x0) {
        CRYPTO_free(puVar14);
      }
    }
    EC_KEY_free(pEVar15);
  }
  EVP_PKEY_free((EVP_PKEY *)pkey);
  uVar3 = 0xffffffff;
LAB_0004cca6:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

