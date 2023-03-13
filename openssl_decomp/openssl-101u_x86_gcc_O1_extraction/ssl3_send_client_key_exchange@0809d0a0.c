
/* WARNING: Could not reconcile some variable overlaps */

undefined4 ssl3_send_client_key_exchange(int *param_1)

{
  undefined *puVar1;
  DH *pDVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  EC_GROUP *group;
  EC_POINT *pEVar7;
  EC_KEY *key;
  size_t sVar8;
  uchar *puVar9;
  BN_CTX *c;
  DH *dh;
  X509 *x;
  EVP_PKEY_CTX *ctx;
  EVP_MD_CTX *ctx_00;
  char *pcVar10;
  EVP_MD *type;
  int iVar11;
  EVP_PKEY *pEVar12;
  uchar uVar13;
  undefined4 in_ECX;
  undefined *__dest;
  uint uVar14;
  RSA *rsa;
  rsa_st *key_00;
  undefined4 *puVar15;
  int in_GS_OFFSET;
  EVP_PKEY *local_2e4;
  uint local_2d0;
  uint local_2cc;
  uchar local_2c6 [32];
  undefined local_2a6 [2];
  undefined4 auStack_2a4 [31];
  uint local_228;
  uchar local_224 [516];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1[0xd] != 0x1180) {
LAB_0809d1e0:
    uVar6 = ssl3_do_write(param_1,0x16);
    goto LAB_0809d1ee;
  }
  puVar1 = *(undefined **)(param_1[0xf] + 4);
  puVar9 = puVar1 + 4;
  uVar14 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  if ((uVar14 & 1) == 0) {
    if ((uVar14 & 0xe) != 0) {
      if (*(int *)(param_1[0x30] + 0x98) == 0) {
        ssl3_send_alert(param_1,2,10);
        iVar4 = 0xa22;
LAB_0809dda9:
        iVar5 = 0xf4;
      }
      else {
        pDVar2 = *(DH **)(*(int *)(param_1[0x30] + 0x98) + 0x70);
        if (pDVar2 == (DH *)0x0) {
          ssl3_send_alert(param_1,2,0x28);
          iVar4 = 0xa2c;
          iVar5 = 0xee;
        }
        else {
          dh = DHparams_dup(pDVar2);
          if (dh != (DH *)0x0) {
            iVar4 = DH_generate_key(dh);
            if (iVar4 == 0) {
              iVar4 = 0xa36;
            }
            else {
              sVar8 = DH_compute_key(puVar9,*(BIGNUM **)&pDVar2->field_0x14,dh);
              if (0 < (int)sVar8) {
                iVar4 = param_1[0x30];
                uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar4 + 0x14,puVar9,sVar8);
                *(undefined4 *)(iVar4 + 0x10) = uVar6;
                memset(puVar9,0,sVar8);
                iVar5 = BN_num_bits(*(BIGNUM **)&dh->field_0x14);
                iVar4 = iVar5 + 7;
                if (iVar5 + 7 < 0) {
                  iVar4 = iVar5 + 0xe;
                }
                puVar1[4] = (char)(iVar4 >> 0xb);
                puVar1[5] = (char)(iVar4 >> 3);
                BN_bn2bin(*(BIGNUM **)&dh->field_0x14,puVar1 + 6);
                iVar4 = (iVar4 >> 3) + 2;
                DH_free(dh);
                goto LAB_0809d1b5;
              }
              iVar4 = 0xa43;
            }
            ERR_put_error(0x14,0x98,5,"s3_clnt.c",iVar4);
            DH_free(dh);
            goto LAB_0809d7bc;
          }
          iVar4 = 0xa32;
          iVar5 = 5;
        }
      }
LAB_0809d7ad:
      ERR_put_error(0x14,0x98,iVar5,"s3_clnt.c",iVar4);
      goto LAB_0809d7bc;
    }
    if ((uVar14 & 0xe0) == 0) {
      if ((uVar14 & 0x200) != 0) {
        x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x60);
        if ((x == (X509 *)0x0) &&
           (x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x54), x == (X509 *)0x0)) {
          ERR_put_error(0x14,0x98,0x14a,"s3_clnt.c",0xb24);
        }
        else {
          pEVar12 = X509_get_pubkey(x);
          ctx = EVP_PKEY_CTX_new(pEVar12,(ENGINE *)0x0);
          if (ctx != (EVP_PKEY_CTX *)0x0) {
            iVar4 = EVP_PKEY_encrypt_init(ctx);
            if (0 < iVar4) {
              iVar4 = RAND_bytes(local_2c6,0x20);
              if (0 < iVar4) {
                ctx_00 = EVP_MD_CTX_create();
                pcVar10 = OBJ_nid2sn(0x329);
                type = EVP_get_digestbyname(pcVar10);
                iVar4 = EVP_DigestInit(ctx_00,type);
                if (0 < iVar4) {
                  iVar4 = EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xc0),0x20);
                  if (0 < iVar4) {
                    iVar4 = EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xa0),0x20);
                    if (0 < iVar4) {
                      iVar4 = EVP_DigestFinal_ex(ctx_00,local_2a6,&local_2cc);
                      if (0 < iVar4) {
                        EVP_MD_CTX_destroy(ctx_00);
                        iVar4 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,8,8,local_2a6);
                        if (iVar4 < 0) {
                          iVar4 = 0xb57;
                        }
                        else {
                          local_2d0 = 0xff;
                          puVar1[4] = 0x30;
                          iVar4 = EVP_PKEY_encrypt(ctx,local_224,&local_2d0,local_2c6,0x20);
                          if (0 < iVar4) {
                            local_2e4._0_1_ = (undefined)local_2d0;
                            if (local_2d0 < 0x80) {
                              __dest = puVar1 + 6;
                              iVar4 = local_2d0 + 2;
                            }
                            else {
                              __dest = puVar1 + 7;
                              iVar4 = local_2d0 + 3;
                              puVar1[6] = local_2e4._0_1_;
                              local_2e4._0_1_ = 0x81;
                            }
                            puVar1[5] = local_2e4._0_1_;
                            memcpy(__dest,local_224,local_2d0);
                            EVP_PKEY_CTX_free(ctx);
                            iVar5 = param_1[0x30];
                            uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                              (param_1,iVar5 + 0x14,local_2c6,0x20);
                            *(undefined4 *)(iVar5 + 0x10) = uVar6;
                            EVP_PKEY_free(pEVar12);
                            goto LAB_0809d1b5;
                          }
                          iVar4 = 0xb63;
                        }
                        ERR_put_error(0x14,0x98,0x112,"s3_clnt.c",iVar4);
                        goto LAB_0809d7bc;
                      }
                    }
                  }
                }
                EVP_MD_CTX_destroy(ctx_00);
                iVar4 = 0xb4f;
                goto LAB_0809d7a6;
              }
            }
            EVP_PKEY_CTX_free(ctx);
            iVar4 = 0xb3e;
            goto LAB_0809d7a6;
          }
          ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xb2c);
        }
        goto LAB_0809d7bc;
      }
      if ((uVar14 & 0x400) == 0) {
        if ((uVar14 & 0x100) != 0) {
          pcVar3 = (code *)param_1[0x37];
          if (pcVar3 == (code *)0x0) {
            ERR_put_error(0x14,0x98,0xe0,"s3_clnt.c",0xbaa);
            goto LAB_0809d7bc;
          }
          _local_2a6 = 0;
          local_228 = 0;
          puVar15 = (undefined4 *)(local_2a6 + 2);
          for (uVar14 = (uint)(local_224 + -(int)(local_2a6 + 2)) >> 2; uVar14 != 0;
              uVar14 = uVar14 - 1) {
            *puVar15 = 0;
            puVar15 = puVar15 + 1;
          }
          uVar14 = (*pcVar3)(param_1,*(undefined4 *)(param_1[0x30] + 0x8c),local_2a6,0x81,local_224,
                             0x204);
          if (uVar14 < 0x101) {
            if (uVar14 == 0) {
              ERR_put_error(0x14,0x98,0xdf,"s3_clnt.c",0xbb9);
            }
            else {
              local_228 = local_228 & 0xffffff;
              sVar8 = strlen(local_2a6);
              if (0x80 < sVar8) {
                iVar4 = 0xbc0;
                goto LAB_0809d8e6;
              }
              memmove(local_224 + uVar14 + 4,local_224,uVar14);
              uVar13 = (uchar)(uVar14 >> 8);
              local_224[0] = uVar13;
              local_224[1] = (uchar)uVar14;
              __memset_chk(local_224 + 2,0,uVar14,0x202);
              iVar4 = param_1[0x30];
              (local_224 + 2)[uVar14] = uVar13;
              local_224[uVar14 + 3] = (uchar)uVar14;
              if (*(void **)(iVar4 + 0x8c) != (void *)0x0) {
                CRYPTO_free(*(void **)(iVar4 + 0x8c));
                iVar4 = param_1[0x30];
              }
              pcVar10 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
              *(char **)(iVar4 + 0x8c) = pcVar10;
              iVar4 = param_1[0x30];
              if ((*(int *)(param_1[0x39] + 0x14c) == 0) || (*(int *)(iVar4 + 0x8c) != 0)) {
                if (*(void **)(iVar4 + 0x90) != (void *)0x0) {
                  CRYPTO_free(*(void **)(iVar4 + 0x90));
                  iVar4 = param_1[0x30];
                }
                pcVar10 = BUF_strdup(local_2a6);
                *(char **)(iVar4 + 0x90) = pcVar10;
                iVar4 = param_1[0x30];
                if (*(int *)(iVar4 + 0x90) != 0) {
                  uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                    (param_1,iVar4 + 0x14,local_224,uVar14 * 2 + 4);
                  *(undefined4 *)(iVar4 + 0x10) = uVar6;
                  puVar1[4] = 0;
                  puVar1[5] = (char)sVar8;
                  memcpy(puVar1 + 6,local_2a6,sVar8);
                  iVar4 = sVar8 + 2;
                  OPENSSL_cleanse(local_2a6,0x82);
                  OPENSSL_cleanse(local_224,0x204);
                  goto LAB_0809d1b5;
                }
                iVar4 = 0xbdc;
              }
              else {
                iVar4 = 0xbd3;
              }
              ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",iVar4);
            }
          }
          else {
            iVar4 = 0xbb5;
LAB_0809d8e6:
            ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",iVar4);
          }
          OPENSSL_cleanse(local_2a6,0x82);
          OPENSSL_cleanse(local_224,0x204);
          ssl3_send_alert(param_1,2,0x28);
          goto LAB_0809d7bc;
        }
        ssl3_send_alert(param_1,2,0x28,in_ECX);
        iVar4 = 0xbf5;
      }
      else if ((BIGNUM *)param_1[0x6e] == (BIGNUM *)0x0) {
        iVar4 = 0xb83;
      }
      else {
        iVar5 = BN_num_bits((BIGNUM *)param_1[0x6e]);
        iVar4 = iVar5 + 7;
        if (iVar5 + 7 < 0) {
          iVar4 = iVar5 + 0xe;
        }
        puVar1[4] = (char)(iVar4 >> 0xb);
        puVar1[5] = (char)(iVar4 >> 3);
        BN_bn2bin((BIGNUM *)param_1[0x6e],puVar1 + 6);
        iVar4 = (iVar4 >> 3) + 2;
        iVar5 = param_1[0x30];
        if (*(void **)(iVar5 + 0xf0) != (void *)0x0) {
          CRYPTO_free(*(void **)(iVar5 + 0xf0));
          iVar5 = param_1[0x30];
        }
        pcVar10 = BUF_strdup((char *)param_1[0x69]);
        *(char **)(iVar5 + 0xf0) = pcVar10;
        iVar5 = param_1[0x30];
        if (*(int *)(iVar5 + 0xf0) == 0) {
          iVar4 = 0xb8b;
          iVar5 = 0x41;
          goto LAB_0809d7ad;
        }
        iVar11 = SRP_generate_client_master_secret(param_1,iVar5 + 0x14);
        *(int *)(iVar5 + 0x10) = iVar11;
        if (-1 < iVar11) goto LAB_0809d1b5;
        iVar4 = 0xb94;
      }
LAB_0809d7a6:
      iVar5 = 0x44;
      goto LAB_0809d7ad;
    }
    iVar4 = *(int *)(param_1[0x30] + 0x98);
    if (iVar4 == 0) {
      ssl3_send_alert(param_1,2,10,0);
      iVar4 = 0xa65;
      goto LAB_0809dda9;
    }
    key_00 = *(rsa_st **)(iVar4 + 0x74);
    local_2e4 = (EVP_PKEY *)0x0;
    if (key_00 == (rsa_st *)0x0) {
      local_2e4 = X509_get_pubkey(*(X509 **)(iVar4 + 0x48));
      if (((local_2e4 != (EVP_PKEY *)0x0) && (local_2e4->type == 0x198)) &&
         (key_00 = (local_2e4->pkey).rsa, key_00 != (rsa_st *)0x0)) goto LAB_0809d249;
      iVar4 = 0xa90;
LAB_0809d971:
      ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",iVar4);
      goto LAB_0809d7c4;
    }
LAB_0809d249:
    group = EC_KEY_get0_group((EC_KEY *)key_00);
    pEVar7 = EC_KEY_get0_public_key((EC_KEY *)key_00);
    if ((group == (EC_GROUP *)0x0) || (pEVar7 == (EC_POINT *)0x0)) {
      iVar4 = 0xa9c;
      goto LAB_0809d971;
    }
    key = EC_KEY_new();
    if (key == (EC_KEY *)0x0) {
      ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xaa2);
      goto LAB_0809d7c4;
    }
    iVar4 = EC_KEY_set_group(key,group);
    if (iVar4 == 0) {
      ERR_put_error(0x14,0x98,0x10,"s3_clnt.c",0xaa7);
LAB_0809dc18:
      BN_CTX_free((BN_CTX *)0x0);
    }
    else {
      iVar4 = EC_KEY_generate_key(key);
      if (iVar4 == 0) {
        iVar4 = 0xabf;
LAB_0809dc44:
        ERR_put_error(0x14,0x98,0x2b,"s3_clnt.c",iVar4);
        goto LAB_0809dc18;
      }
      iVar4 = EC_GROUP_get_degree(group);
      if (iVar4 < 1) {
        iVar4 = 0xacb;
        goto LAB_0809dc44;
      }
      sVar8 = ECDH_compute_key(puVar9,iVar4 + 7 >> 3,pEVar7,key,(KDF *)0x0);
      if ((int)sVar8 < 1) {
        iVar4 = 0xad1;
        goto LAB_0809dc44;
      }
      iVar4 = param_1[0x30];
      uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar4 + 0x14,puVar9,sVar8);
      *(undefined4 *)(iVar4 + 0x10) = uVar6;
      memset(puVar9,0,sVar8);
      pEVar7 = EC_KEY_get0_public_key(key);
      sVar8 = EC_POINT_point2oct(group,pEVar7,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                 (BN_CTX *)0x0);
      puVar9 = (uchar *)CRYPTO_malloc(sVar8,"s3_clnt.c",0xaed);
      c = BN_CTX_new();
      if ((puVar9 != (uchar *)0x0) && (c != (BN_CTX *)0x0)) {
        pEVar7 = EC_KEY_get0_public_key(key);
        sVar8 = EC_POINT_point2oct(group,pEVar7,POINT_CONVERSION_UNCOMPRESSED,puVar9,sVar8,c);
        puVar1[4] = (char)sVar8;
        memcpy(puVar1 + 5,puVar9,sVar8);
        iVar4 = sVar8 + 1;
        BN_CTX_free(c);
        CRYPTO_free(puVar9);
        EC_KEY_free(key);
        EVP_PKEY_free(local_2e4);
        goto LAB_0809d1b5;
      }
      ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
      BN_CTX_free(c);
      if (puVar9 != (uchar *)0x0) {
        CRYPTO_free(puVar9);
      }
    }
    EC_KEY_free(key);
  }
  else {
    iVar4 = *(int *)(param_1[0x30] + 0x98);
    if (iVar4 == 0) {
      iVar4 = 0x95b;
      goto LAB_0809d7a6;
    }
    rsa = *(RSA **)(iVar4 + 0x6c);
    if (rsa == (RSA *)0x0) {
      pEVar12 = X509_get_pubkey(*(X509 **)(iVar4 + 0xc));
      if (((pEVar12 == (EVP_PKEY *)0x0) || (pEVar12->type != 6)) ||
         (rsa = (pEVar12->pkey).rsa, rsa == (rsa_st *)0x0)) {
        ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0x969);
        EVP_PKEY_free(pEVar12);
        goto LAB_0809d7bc;
      }
      EVP_PKEY_free(pEVar12);
    }
    local_224[1] = (uchar)param_1[0x44];
    local_224[0] = (uchar)((uint)param_1[0x44] >> 8);
    iVar4 = RAND_bytes(local_224 + 2,0x2e);
    if (0 < iVar4) {
      iVar4 = *param_1;
      *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
      if (0x300 < iVar4) {
        puVar9 = puVar1 + 6;
      }
      iVar5 = RSA_public_encrypt(0x30,local_224,puVar9,rsa,1);
      if (0 < iVar5) {
        iVar4 = iVar5;
        if (0x300 < *param_1) {
          puVar1[5] = (char)iVar5;
          iVar4 = iVar5 + 2;
          puVar1[4] = (char)((uint)iVar5 >> 8);
        }
        iVar5 = param_1[0x30];
        uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar5 + 0x14,local_224,0x30)
        ;
        *(undefined4 *)(iVar5 + 0x10) = uVar6;
        OPENSSL_cleanse(local_224,0x30);
LAB_0809d1b5:
        puVar1[3] = (char)iVar4;
        *puVar1 = 0x10;
        puVar1[1] = (char)((uint)iVar4 >> 0x10);
        puVar1[2] = (char)((uint)iVar4 >> 8);
        param_1[0xd] = 0x1181;
        param_1[0x11] = iVar4 + 4;
        param_1[0x12] = 0;
        goto LAB_0809d1e0;
      }
      ERR_put_error(0x14,0x98,0x77,"s3_clnt.c",0x986);
    }
LAB_0809d7bc:
    local_2e4 = (EVP_PKEY *)0x0;
LAB_0809d7c4:
    BN_CTX_free((BN_CTX *)0x0);
  }
  EVP_PKEY_free(local_2e4);
  param_1[0xd] = 5;
  uVar6 = 0xffffffff;
LAB_0809d1ee:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

