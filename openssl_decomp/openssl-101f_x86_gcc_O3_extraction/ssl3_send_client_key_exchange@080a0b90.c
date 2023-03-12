
undefined4 ssl3_send_client_key_exchange(int *param_1)

{
  undefined *puVar1;
  DH *pDVar2;
  int iVar3;
  undefined4 uVar4;
  EC_GROUP *group;
  EC_POINT *pEVar5;
  EC_KEY *key;
  size_t sVar6;
  uchar *puVar7;
  BN_CTX *c;
  DH *dh;
  char *pcVar8;
  X509 *x;
  EVP_PKEY_CTX *ctx;
  EVP_MD_CTX *ctx_00;
  EVP_MD *type;
  EVP_PKEY *pEVar9;
  uint uVar10;
  uint uVar11;
  uchar uVar12;
  undefined4 in_ECX;
  uint *puVar13;
  rsa_st *key_00;
  uint *puVar14;
  int in_GS_OFFSET;
  bool bVar15;
  int iVar16;
  undefined *local_2dc;
  EVP_PKEY *local_2d8;
  RSA *local_2d0;
  uint local_2cc;
  uint local_2c8;
  uchar local_2c4 [32];
  uint local_2a4 [32];
  uchar local_224;
  uchar local_223;
  uchar local_222 [514];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1[0xd] != 0x1180) {
LAB_080a0cd9:
    uVar4 = ssl3_do_write(param_1,0x16);
    goto LAB_080a0ce7;
  }
  puVar1 = *(undefined **)(param_1[0xf] + 4);
  puVar7 = puVar1 + 4;
  uVar10 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  if ((uVar10 & 1) == 0) {
    if ((uVar10 & 0xe) != 0) {
      if (*(int *)(param_1[0x30] + 0x98) == 0) {
        ssl3_send_alert(param_1,2,10,0);
        iVar16 = 0x98f;
        iVar3 = 0xf4;
      }
      else {
        pDVar2 = *(DH **)(*(int *)(param_1[0x30] + 0x98) + 0x70);
        if (pDVar2 == (DH *)0x0) {
          ssl3_send_alert(param_1,2,0x28);
          iVar16 = 0x999;
          iVar3 = 0xee;
        }
        else {
          dh = DHparams_dup(pDVar2);
          if (dh != (DH *)0x0) {
            iVar3 = DH_generate_key(dh);
            if (iVar3 == 0) {
              iVar3 = 0x9a5;
            }
            else {
              sVar6 = DH_compute_key(puVar7,*(BIGNUM **)&pDVar2->field_0x14,dh);
              if (0 < (int)sVar6) {
                iVar3 = param_1[0x30];
                uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar3 + 0x14,puVar7,sVar6);
                *(undefined4 *)(iVar3 + 0x10) = uVar4;
                memset(puVar7,0,sVar6);
                iVar16 = BN_num_bits(*(BIGNUM **)&dh->field_0x14);
                iVar3 = iVar16 + 7;
                if (iVar16 + 7 < 0) {
                  iVar3 = iVar16 + 0xe;
                }
                puVar1[4] = (char)(iVar3 >> 0xb);
                puVar1[5] = (char)(iVar3 >> 3);
                BN_bn2bin(*(BIGNUM **)&dh->field_0x14,puVar1 + 6);
                local_2d0 = (RSA *)((iVar3 >> 3) + 2);
                DH_free(dh);
                goto LAB_080a0ca7;
              }
              iVar3 = 0x9b1;
            }
            ERR_put_error(0x14,0x98,5,"s3_clnt.c",iVar3);
            DH_free(dh);
            goto LAB_080a1155;
          }
          iVar16 = 0x9a0;
          iVar3 = 5;
        }
      }
LAB_080a1146:
      ERR_put_error(0x14,0x98,iVar3,"s3_clnt.c",iVar16);
      goto LAB_080a1155;
    }
    if ((uVar10 & 0xe0) == 0) {
      if ((uVar10 & 0x200) != 0) {
        x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x60);
        if ((x == (X509 *)0x0) &&
           (x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x54), x == (X509 *)0x0)) {
          ERR_put_error(0x14,0x98,0x14a,"s3_clnt.c",0xa93);
        }
        else {
          pEVar9 = X509_get_pubkey(x);
          ctx = EVP_PKEY_CTX_new(pEVar9,(ENGINE *)0x0);
          EVP_PKEY_encrypt_init(ctx);
          RAND_bytes(local_2c4,0x20);
          if ((*(int *)(param_1[0x16] + 0x358) != 0) &&
             (*(EVP_PKEY **)(*(int *)param_1[0x26] + 4) != (EVP_PKEY *)0x0)) {
            iVar3 = EVP_PKEY_derive_set_peer(ctx,*(EVP_PKEY **)(*(int *)param_1[0x26] + 4));
            if (iVar3 < 1) {
              ERR_clear_error();
            }
          }
          ctx_00 = EVP_MD_CTX_create();
          pcVar8 = OBJ_nid2sn(0x329);
          type = EVP_get_digestbyname(pcVar8);
          EVP_DigestInit(ctx_00,type);
          EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xc0),0x20);
          EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xa0),0x20);
          EVP_DigestFinal_ex(ctx_00,(uchar *)local_2a4,&local_2c8);
          EVP_MD_CTX_destroy(ctx_00);
          iVar3 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,8,8,local_2a4);
          if (iVar3 < 0) {
            iVar3 = 0xab7;
          }
          else {
            puVar1[4] = 0x30;
            local_2cc = 0xff;
            iVar3 = EVP_PKEY_encrypt(ctx,&local_224,&local_2cc,local_2c4,0x20);
            if (-1 < iVar3) {
              if (local_2cc < 0x80) {
                local_2dc = puVar1 + 6;
                local_2d0 = (RSA *)(local_2cc + 2);
                uVar10 = local_2cc;
              }
              else {
                local_2d0 = (RSA *)(local_2cc + 3);
                local_2dc = puVar1 + 7;
                puVar1[6] = (char)local_2cc;
                uVar10 = 0xffffff81;
              }
              puVar1[5] = (char)uVar10;
              memcpy(local_2dc,&local_224,local_2cc);
              iVar3 = EVP_PKEY_CTX_ctrl(ctx,-1,-1,2,2,(void *)0x0);
              if (0 < iVar3) {
                *(uint *)param_1[0x16] = *(uint *)param_1[0x16] | 0x10;
              }
              EVP_PKEY_CTX_free(ctx);
              iVar3 = param_1[0x30];
              uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                (param_1,iVar3 + 0x14,local_2c4,0x20);
              *(undefined4 *)(iVar3 + 0x10) = uVar4;
              EVP_PKEY_free(pEVar9);
              goto LAB_080a0ca7;
            }
            iVar3 = 0xac0;
          }
          ERR_put_error(0x14,0x98,0x112,"s3_clnt.c",iVar3);
        }
        goto LAB_080a1155;
      }
      if ((uVar10 & 0x400) == 0) {
        if ((uVar10 & 0x100) != 0) {
          if ((code *)param_1[0x37] == (code *)0x0) {
            ERR_put_error(0x14,0x98,0xe0,"s3_clnt.c",0xb0a);
          }
          else {
            uVar10 = (*(code *)param_1[0x37])
                               (param_1,*(undefined4 *)(param_1[0x39] + 0x14c),local_2a4,0x80,
                                &local_224,0x204);
            if (uVar10 < 0x101) {
              if (uVar10 == 0) {
                ERR_put_error(0x14,0x98,0xdf,"s3_clnt.c",0xb1a);
              }
              else {
                memmove(local_222 + uVar10 + 2,&local_224,uVar10);
                uVar12 = (uchar)(uVar10 >> 8);
                local_224 = uVar12;
                local_223 = (uchar)uVar10;
                __memset_chk(local_222,0,uVar10,0x202);
                local_222[uVar10 + 1] = (uchar)uVar10;
                local_2d0 = (RSA *)param_1[0x30];
                local_222[uVar10] = uVar12;
                if (*(void **)((int)local_2d0 + 0x8c) != (void *)0x0) {
                  CRYPTO_free(*(void **)((int)local_2d0 + 0x8c));
                  local_2d0 = (RSA *)param_1[0x30];
                }
                pcVar8 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
                *(char **)((int)local_2d0 + 0x8c) = pcVar8;
                local_2d0 = (RSA *)param_1[0x30];
                if ((*(int *)(param_1[0x39] + 0x14c) == 0) || (*(int *)((int)local_2d0 + 0x8c) != 0)
                   ) {
                  if (*(void **)((int)local_2d0 + 0x90) != (void *)0x0) {
                    CRYPTO_free(*(void **)((int)local_2d0 + 0x90));
                    local_2d0 = (RSA *)param_1[0x30];
                  }
                  pcVar8 = BUF_strdup((char *)local_2a4);
                  *(char **)((int)local_2d0 + 0x90) = pcVar8;
                  iVar3 = param_1[0x30];
                  if (*(int *)(iVar3 + 0x90) != 0) {
                    uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                      (param_1,iVar3 + 0x14,&local_224,uVar10 * 2 + 4);
                    *(undefined4 *)(iVar3 + 0x10) = uVar4;
                    puVar14 = local_2a4;
                    do {
                      puVar13 = puVar14;
                      uVar11 = *puVar13 + 0xfefefeff & ~*puVar13;
                      uVar10 = uVar11 & 0x80808080;
                      puVar14 = puVar13 + 1;
                    } while (uVar10 == 0);
                    bVar15 = (uVar11 & 0x8080) == 0;
                    if (bVar15) {
                      uVar10 = uVar10 >> 0x10;
                    }
                    puVar14 = (uint *)((int)puVar13 + 6);
                    if (!bVar15) {
                      puVar14 = puVar13 + 1;
                    }
                    sVar6 = (int)puVar14 +
                            ((-3 - (uint)CARRY1((byte)uVar10,(byte)uVar10)) - (int)local_2a4);
                    puVar1[5] = (char)sVar6;
                    puVar1[4] = (char)(sVar6 >> 8);
                    memcpy(puVar1 + 6,local_2a4,sVar6);
                    local_2d0 = (RSA *)(sVar6 + 2);
                    OPENSSL_cleanse(local_2a4,0x80);
                    OPENSSL_cleanse(&local_224,0x204);
                    goto LAB_080a0ca7;
                  }
                  iVar3 = 0xb38;
                }
                else {
                  iVar3 = 0xb2e;
                }
                ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",iVar3);
              }
            }
            else {
              ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0xb14);
            }
            OPENSSL_cleanse(local_2a4,0x80);
            OPENSSL_cleanse(&local_224,0x204);
            ssl3_send_alert(param_1,2,0x28);
          }
          goto LAB_080a1155;
        }
        ssl3_send_alert(param_1,2,0x28,in_ECX);
        iVar16 = 0xb54;
      }
      else if ((BIGNUM *)param_1[0x6e] == (BIGNUM *)0x0) {
        iVar16 = 0xae9;
      }
      else {
        iVar16 = BN_num_bits((BIGNUM *)param_1[0x6e]);
        iVar3 = iVar16 + 7;
        if (iVar16 + 7 < 0) {
          iVar3 = iVar16 + 0xe;
        }
        puVar1[4] = (char)(iVar3 >> 0xb);
        puVar1[5] = (char)(iVar3 >> 3);
        BN_bn2bin((BIGNUM *)param_1[0x6e],puVar1 + 6);
        local_2d0 = (RSA *)((iVar3 >> 3) + 2);
        iVar3 = param_1[0x30];
        if (*(void **)(iVar3 + 0xf0) != (void *)0x0) {
          CRYPTO_free(*(void **)(iVar3 + 0xf0));
          iVar3 = param_1[0x30];
        }
        pcVar8 = BUF_strdup((char *)param_1[0x69]);
        *(char **)(iVar3 + 0xf0) = pcVar8;
        iVar3 = param_1[0x30];
        if (*(int *)(iVar3 + 0xf0) == 0) {
          iVar16 = 0xaf2;
          iVar3 = 0x41;
          goto LAB_080a1146;
        }
        iVar16 = SRP_generate_client_master_secret(param_1,iVar3 + 0x14);
        *(int *)(iVar3 + 0x10) = iVar16;
        if (-1 < iVar16) goto LAB_080a0ca7;
        iVar16 = 0xaf8;
      }
LAB_080a113f:
      iVar3 = 0x44;
      goto LAB_080a1146;
    }
    local_2d8 = (EVP_PKEY *)0x0;
    key_00 = *(rsa_st **)(*(int *)(param_1[0x30] + 0x98) + 0x74);
    if (key_00 == (rsa_st *)0x0) {
      local_2d8 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x48));
      if (((local_2d8 != (EVP_PKEY *)0x0) && (local_2d8->type == 0x198)) &&
         (key_00 = (local_2d8->pkey).rsa, key_00 != (rsa_st *)0x0)) goto LAB_080a0d31;
      iVar3 = 0x9fb;
LAB_080a14eb:
      ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",iVar3);
      goto LAB_080a115f;
    }
LAB_080a0d31:
    group = EC_KEY_get0_group((EC_KEY *)key_00);
    pEVar5 = EC_KEY_get0_public_key((EC_KEY *)key_00);
    if ((group == (EC_GROUP *)0x0) || (pEVar5 == (EC_POINT *)0x0)) {
      iVar3 = 0xa08;
      goto LAB_080a14eb;
    }
    key = EC_KEY_new();
    if (key == (EC_KEY *)0x0) {
      ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xa0e);
      goto LAB_080a115f;
    }
    iVar3 = EC_KEY_set_group(key,group);
    if (iVar3 == 0) {
      ERR_put_error(0x14,0x98,0x10,"s3_clnt.c",0xa14);
LAB_080a17cb:
      BN_CTX_free((BN_CTX *)0x0);
    }
    else {
      iVar3 = EC_KEY_generate_key(key);
      if (iVar3 == 0) {
        iVar3 = 0xa30;
LAB_080a17f6:
        ERR_put_error(0x14,0x98,0x2b,"s3_clnt.c",iVar3);
        goto LAB_080a17cb;
      }
      iVar3 = EC_GROUP_get_degree(group);
      if (iVar3 < 1) {
        iVar3 = 0xa3d;
        goto LAB_080a17f6;
      }
      sVar6 = ECDH_compute_key(puVar7,iVar3 + 7 >> 3,pEVar5,key,(KDF *)0x0);
      if ((int)sVar6 < 1) {
        iVar3 = 0xa44;
        goto LAB_080a17f6;
      }
      iVar3 = param_1[0x30];
      uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar3 + 0x14,puVar7,sVar6);
      *(undefined4 *)(iVar3 + 0x10) = uVar4;
      memset(puVar7,0,sVar6);
      pEVar5 = EC_KEY_get0_public_key(key);
      sVar6 = EC_POINT_point2oct(group,pEVar5,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                 (BN_CTX *)0x0);
      puVar7 = (uchar *)CRYPTO_malloc(sVar6,"s3_clnt.c",0xa62);
      c = BN_CTX_new();
      if ((puVar7 != (uchar *)0x0) && (c != (BN_CTX *)0x0)) {
        pEVar5 = EC_KEY_get0_public_key(key);
        sVar6 = EC_POINT_point2oct(group,pEVar5,POINT_CONVERSION_UNCOMPRESSED,puVar7,sVar6,c);
        puVar1[4] = (char)sVar6;
        memcpy(puVar1 + 5,puVar7,sVar6);
        local_2d0 = (RSA *)(sVar6 + 1);
        BN_CTX_free(c);
        CRYPTO_free(puVar7);
        EC_KEY_free(key);
        EVP_PKEY_free(local_2d8);
        goto LAB_080a0ca7;
      }
      ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xa67);
      BN_CTX_free(c);
      if (puVar7 != (uchar *)0x0) {
        CRYPTO_free(puVar7);
      }
    }
    EC_KEY_free(key);
  }
  else {
    local_2d0 = *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x6c);
    if (local_2d0 == (RSA *)0x0) {
      pEVar9 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
      if (((pEVar9 == (EVP_PKEY *)0x0) || (pEVar9->type != 6)) ||
         (local_2d0 = (pEVar9->pkey).rsa, local_2d0 == (rsa_st *)0x0)) {
        iVar16 = 0x8d5;
        goto LAB_080a113f;
      }
      EVP_PKEY_free(pEVar9);
    }
    local_223 = (uchar)param_1[0x44];
    local_224 = (uchar)((uint)param_1[0x44] >> 8);
    iVar3 = RAND_bytes(local_222,0x2e);
    if (0 < iVar3) {
      iVar3 = *param_1;
      *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
      if (0x300 < iVar3) {
        puVar7 = puVar1 + 6;
      }
      local_2d0 = (RSA *)RSA_public_encrypt(0x30,&local_224,puVar7,local_2d0,1);
      if (0 < (int)local_2d0) {
        if (0x300 < *param_1) {
          puVar1[4] = (char)((uint)local_2d0 >> 8);
          puVar1[5] = (char)local_2d0;
          local_2d0 = (RSA *)((int)local_2d0 + 2);
        }
        iVar3 = param_1[0x30];
        uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                          (param_1,iVar3 + 0x14,&local_224,0x30);
        *(undefined4 *)(iVar3 + 0x10) = uVar4;
        OPENSSL_cleanse(&local_224,0x30);
LAB_080a0ca7:
        *puVar1 = 0x10;
        puVar1[3] = (char)local_2d0;
        puVar1[1] = (char)((uint)local_2d0 >> 0x10);
        puVar1[2] = (char)((uint)local_2d0 >> 8);
        param_1[0xd] = 0x1181;
        param_1[0x12] = 0;
        param_1[0x11] = (int)local_2d0 + 4;
        goto LAB_080a0cd9;
      }
      ERR_put_error(0x14,0x98,0x77,"s3_clnt.c",0x8ef);
    }
LAB_080a1155:
    local_2d8 = (EVP_PKEY *)0x0;
LAB_080a115f:
    BN_CTX_free((BN_CTX *)0x0);
  }
  EVP_PKEY_free(local_2d8);
  uVar4 = 0xffffffff;
LAB_080a0ce7:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

