
void ssl3_send_client_key_exchange(int *param_1)

{
  uchar uVar1;
  int iVar2;
  undefined4 uVar3;
  EC_GROUP *group;
  EC_POINT *pEVar4;
  size_t sVar5;
  BN_CTX *c;
  DH *pDVar6;
  X509 *x;
  EVP_PKEY_CTX *ctx;
  EVP_MD_CTX *ctx_00;
  char *pcVar7;
  EVP_MD *type;
  undefined *__dest;
  EVP_PKEY *pEVar8;
  undefined uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined *puVar13;
  uchar *puVar14;
  code *pcVar15;
  DH *pDVar16;
  RSA *rsa;
  EC_KEY *pEVar17;
  DH *pkey;
  uint local_2e0;
  uint uStack_2dc;
  uchar auStack_2d8 [32];
  uchar auStack_2b8 [129];
  undefined local_237;
  uchar local_230 [516];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (param_1[0xd] != 0x1180) {
LAB_00049dec:
    uVar3 = ssl3_do_write(param_1,0x16);
    goto LAB_00049df4;
  }
  puVar13 = *(undefined **)(param_1[0xf] + 4);
  uVar10 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  puVar14 = puVar13 + 4;
  if ((DH *)(uVar10 & 1) == (DH *)0x0) {
    pkey = (DH *)(uVar10 & 0xe);
    if (pkey != (DH *)0x0) {
      pkey = *(DH **)(param_1[0x30] + 0x98);
      if (pkey == (DH *)0x0) {
        ssl3_send_alert(param_1,2,10);
        ERR_put_error(0x14,0x98,0xf4,"s3_clnt.c",0xa22);
      }
      else {
        pkey = *(DH **)&pkey[1].field_0x24;
        if (pkey == (DH *)0x0) {
          ssl3_send_alert(param_1,2,0x28);
          ERR_put_error(0x14,0x98,0xee,"s3_clnt.c",0xa2c);
        }
        else {
          pDVar16 = DHparams_dup(pkey);
          if (pDVar16 == (DH *)0x0) {
            ERR_put_error(0x14,0x98,5,"s3_clnt.c",0xa32);
            pkey = pDVar16;
          }
          else {
            pDVar6 = (DH *)DH_generate_key(pDVar16);
            if (pDVar6 == (DH *)0x0) {
              ERR_put_error(0x14,0x98,5,"s3_clnt.c",0xa36);
              DH_free(pDVar16);
              pkey = pDVar6;
            }
            else {
              sVar5 = DH_compute_key(puVar14,*(BIGNUM **)&pkey->field_0x14,pDVar16);
              if (0 < (int)sVar5) {
                iVar11 = param_1[0x30];
                uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar11 + 0x14,puVar14,sVar5);
                *(undefined4 *)(iVar11 + 0x10) = uVar3;
                memset(puVar14,0,sVar5);
                iVar2 = BN_num_bits(*(BIGNUM **)&pDVar16->field_0x14);
                iVar11 = iVar2 + 7;
                if (iVar2 + 7 < 0) {
                  iVar11 = iVar2 + 0xe;
                }
                puVar13[5] = (char)(iVar11 >> 3);
                iVar2 = (iVar11 >> 3) + 2;
                puVar13[4] = (char)(iVar11 >> 0xb);
                BN_bn2bin(*(BIGNUM **)&pDVar16->field_0x14,puVar13 + 6);
                DH_free(pDVar16);
                goto LAB_00049dc2;
              }
              ERR_put_error(0x14,0x98,5,"s3_clnt.c",0xa43);
              DH_free(pDVar16);
              pkey = (DH *)(uVar10 & 1);
            }
          }
        }
      }
      goto LAB_0004a1d0;
    }
    if ((uVar10 & 0xe0) == 0) {
      if ((int)(uVar10 << 0x16) < 0) {
        x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x60);
        if ((x == (X509 *)0x0) &&
           (x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x54), x == (X509 *)0x0)) {
          ERR_put_error(0x14,0x98,0x14a,"s3_clnt.c",0xb24);
        }
        else {
          pEVar8 = X509_get_pubkey(x);
          ctx = EVP_PKEY_CTX_new(pEVar8,(ENGINE *)0x0);
          if (ctx == (EVP_PKEY_CTX *)0x0) {
            ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xb2c);
          }
          else {
            iVar11 = EVP_PKEY_encrypt_init(ctx);
            if ((iVar11 < 1) || (iVar11 = RAND_bytes(auStack_2d8,0x20), iVar11 < 1)) {
              EVP_PKEY_CTX_free(ctx);
              iVar11 = 0xb3e;
            }
            else {
              ctx_00 = EVP_MD_CTX_create();
              pcVar7 = OBJ_nid2sn(0x329);
              type = EVP_get_digestbyname(pcVar7);
              iVar11 = EVP_DigestInit(ctx_00,type);
              if ((((0 < iVar11) &&
                   (iVar11 = EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xc0),0x20),
                   0 < iVar11)) &&
                  (iVar11 = EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xa0),0x20), 0 < iVar11
                  )) && (iVar11 = EVP_DigestFinal_ex(ctx_00,auStack_2b8,&uStack_2dc), 0 < iVar11)) {
                EVP_MD_CTX_destroy(ctx_00);
                iVar11 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,8,8,auStack_2b8);
                if (iVar11 < 0) {
                  iVar11 = 0xb57;
                }
                else {
                  puVar13[4] = 0x30;
                  puVar14 = auStack_2d8;
                  local_2e0 = 0xff;
                  iVar11 = EVP_PKEY_encrypt(ctx,local_230,&local_2e0,puVar14,0x20);
                  if (0 < iVar11) {
                    uVar9 = (char)puVar14;
                    if (local_2e0 < 0x80) {
                      uVar9 = (char)local_2e0;
                    }
                    if (local_2e0 < 0x80) {
                      __dest = puVar13 + 6;
                    }
                    else {
                      puVar13[6] = (char)local_2e0;
                      uVar9 = 0x81;
                      __dest = puVar13 + 7;
                    }
                    puVar13[5] = uVar9;
                    if (local_2e0 < 0x80) {
                      iVar2 = local_2e0 + 2;
                    }
                    else {
                      iVar2 = local_2e0 + 3;
                    }
                    memcpy(__dest,local_230,local_2e0);
                    EVP_PKEY_CTX_free(ctx);
                    iVar11 = param_1[0x30];
                    uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                      (param_1,iVar11 + 0x14,auStack_2d8,0x20);
                    *(undefined4 *)(iVar11 + 0x10) = uVar3;
                    EVP_PKEY_free(pEVar8);
                    goto LAB_00049dc2;
                  }
                  iVar11 = 0xb63;
                }
                ERR_put_error(0x14,0x98,0x112,"s3_clnt.c",iVar11);
                goto LAB_0004a2a4;
              }
              EVP_MD_CTX_destroy(ctx_00);
              iVar11 = 0xb4f;
            }
            ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",iVar11);
          }
        }
        goto LAB_0004a2a4;
      }
      if ((uVar10 & 0x400) == 0) {
        if ((DH *)(uVar10 & 0x100) != (DH *)0x0) {
          pcVar15 = (code *)param_1[0x37];
          if (pcVar15 == (code *)0x0) {
            ERR_put_error(0x14,0x98,0xe0,"s3_clnt.c",0xbaa);
            goto LAB_0004a2a4;
          }
          memset(auStack_2b8,0,0x82);
          uVar10 = (*pcVar15)(param_1,*(undefined4 *)(param_1[0x30] + 0x8c),auStack_2b8,0x81,
                              local_230,0x204);
          if (uVar10 < 0x101) {
            if (uVar10 == 0) {
              ERR_put_error(0x14,0x98,0xdf,"s3_clnt.c",0xbb9);
            }
            else {
              local_237 = 0;
              sVar5 = strlen((char *)auStack_2b8);
              if (0x80 < sVar5) {
                iVar11 = 0xbc0;
                goto LAB_0004a278;
              }
              memmove(local_230 + uVar10 + 4,local_230,uVar10);
              uVar1 = (uchar)(uVar10 >> 8);
              local_230[0] = uVar1;
              local_230[1] = (uchar)uVar10;
              __memset_chk(local_230 + 2,0,uVar10,0x202);
              iVar11 = param_1[0x30];
              (local_230 + 2)[uVar10] = uVar1;
              local_230[uVar10 + 3] = (uchar)uVar10;
              if (*(void **)(iVar11 + 0x8c) != (void *)0x0) {
                CRYPTO_free(*(void **)(iVar11 + 0x8c));
                iVar11 = param_1[0x30];
              }
              pcVar7 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
              iVar12 = param_1[0x30];
              iVar2 = *(int *)(param_1[0x39] + 0x14c);
              *(char **)(iVar11 + 0x8c) = pcVar7;
              if ((iVar2 == 0) || (*(int *)(iVar12 + 0x8c) != 0)) {
                if (*(void **)(iVar12 + 0x90) != (void *)0x0) {
                  CRYPTO_free(*(void **)(iVar12 + 0x90));
                  iVar12 = param_1[0x30];
                }
                pcVar7 = BUF_strdup((char *)auStack_2b8);
                iVar11 = param_1[0x30];
                *(char **)(iVar12 + 0x90) = pcVar7;
                if (*(int *)(iVar11 + 0x90) != 0) {
                  iVar2 = sVar5 + 2;
                  uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                    (param_1,iVar11 + 0x14,local_230,uVar10 * 2 + 4);
                  *(undefined4 *)(iVar11 + 0x10) = uVar3;
                  puVar13[4] = 0;
                  puVar13[5] = (char)sVar5;
                  memcpy(puVar13 + 6,auStack_2b8,sVar5);
                  OPENSSL_cleanse(auStack_2b8,0x82);
                  OPENSSL_cleanse(local_230,0x204);
                  goto LAB_00049dc2;
                }
                iVar11 = 0xbdc;
              }
              else {
                iVar11 = 0xbd3;
              }
              ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",iVar11);
            }
          }
          else {
            iVar11 = 0xbb5;
LAB_0004a278:
            ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",iVar11);
          }
          OPENSSL_cleanse(auStack_2b8,0x82);
          OPENSSL_cleanse(local_230,0x204);
          ssl3_send_alert(param_1,2,0x28);
          goto LAB_0004a2a4;
        }
        ssl3_send_alert(param_1,2,0x28);
        ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0xbf5);
        pkey = (DH *)(uVar10 & 0x100);
      }
      else {
        pkey = (DH *)param_1[0x6e];
        if (pkey == (DH *)0x0) {
          ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0xb83);
        }
        else {
          iVar2 = BN_num_bits((BIGNUM *)pkey);
          iVar11 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            iVar11 = iVar2 + 0xe;
          }
          puVar13[5] = (char)(iVar11 >> 3);
          iVar2 = (iVar11 >> 3) + 2;
          puVar13[4] = (char)(iVar11 >> 0xb);
          BN_bn2bin((BIGNUM *)param_1[0x6e],puVar13 + 6);
          iVar11 = param_1[0x30];
          if (*(void **)(iVar11 + 0xf0) != (void *)0x0) {
            CRYPTO_free(*(void **)(iVar11 + 0xf0));
            iVar11 = param_1[0x30];
          }
          pcVar7 = BUF_strdup((char *)param_1[0x69]);
          iVar12 = param_1[0x30];
          *(char **)(iVar11 + 0xf0) = pcVar7;
          pkey = *(DH **)(iVar12 + 0xf0);
          if (pkey == (DH *)0x0) {
            ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xb8b);
          }
          else {
            iVar11 = SRP_generate_client_master_secret(param_1,iVar12 + 0x14);
            *(int *)(iVar12 + 0x10) = iVar11;
            if (-1 < iVar11) goto LAB_00049dc2;
            ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0xb94);
            pkey = (DH *)0x0;
          }
        }
      }
      goto LAB_0004a1d0;
    }
    pDVar16 = *(DH **)(param_1[0x30] + 0x98);
    if (pDVar16 == (DH *)0x0) {
      ssl3_send_alert(param_1,2,10);
      ERR_put_error(0x14,0x98,0xf4,"s3_clnt.c",0xa65);
      pkey = pDVar16;
      goto LAB_0004a1d0;
    }
    pEVar17 = *(EC_KEY **)&pDVar16[1].field_0x28;
    if ((pEVar17 == (EC_KEY *)0x0) &&
       (((pkey = (DH *)X509_get_pubkey(*(X509 **)&pDVar16->field_0x48), pkey == (DH *)0x0 ||
         (*(int *)pkey != 0x198)) ||
        (pEVar17 = *(EC_KEY **)&pkey->field_0x14, pEVar17 == (EC_KEY *)0x0)))) {
      iVar11 = 0xa90;
LAB_0004a2d0:
      ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",iVar11);
      goto LAB_0004a1d0;
    }
    group = EC_KEY_get0_group(pEVar17);
    pEVar4 = EC_KEY_get0_public_key(pEVar17);
    if (group == (EC_GROUP *)0x0 || pEVar4 == (EC_POINT *)0x0) {
      iVar11 = 0xa9c;
      goto LAB_0004a2d0;
    }
    pEVar17 = EC_KEY_new();
    if (pEVar17 == (EC_KEY *)0x0) {
      ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xaa2);
      goto LAB_0004a1d0;
    }
    iVar11 = EC_KEY_set_group(pEVar17,group);
    if (iVar11 == 0) {
      ERR_put_error(0x14,0x98,0x10,"s3_clnt.c",0xaa7);
LAB_0004a35e:
      BN_CTX_free((BN_CTX *)0x0);
    }
    else {
      iVar11 = EC_KEY_generate_key(pEVar17);
      iVar2 = 0xabf;
      if (iVar11 == 0) {
LAB_0004a34e:
        ERR_put_error(0x14,0x98,0x2b,"s3_clnt.c",iVar2);
        goto LAB_0004a35e;
      }
      iVar11 = EC_GROUP_get_degree(group);
      if (iVar11 < 1) {
        iVar2 = 0xacb;
        goto LAB_0004a34e;
      }
      sVar5 = ECDH_compute_key(puVar14,iVar11 + 7 >> 3,pEVar4,pEVar17,(KDF *)0x0);
      if ((int)sVar5 < 1) {
        iVar2 = 0xad1;
        goto LAB_0004a34e;
      }
      iVar11 = param_1[0x30];
      uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar11 + 0x14,puVar14,sVar5);
      *(undefined4 *)(iVar11 + 0x10) = uVar3;
      memset(puVar14,0,sVar5);
      pEVar4 = EC_KEY_get0_public_key(pEVar17);
      sVar5 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                 (BN_CTX *)0x0);
      puVar14 = (uchar *)CRYPTO_malloc(sVar5,"s3_clnt.c",0xaed);
      c = BN_CTX_new();
      if (puVar14 != (uchar *)0x0 && c != (BN_CTX *)0x0) {
        pEVar4 = EC_KEY_get0_public_key(pEVar17);
        sVar5 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,puVar14,sVar5,c);
        puVar13[4] = (char)sVar5;
        memcpy(puVar13 + 5,puVar14,sVar5);
        BN_CTX_free(c);
        CRYPTO_free(puVar14);
        EC_KEY_free(pEVar17);
        iVar2 = sVar5 + 1;
        EVP_PKEY_free((EVP_PKEY *)pkey);
        goto LAB_00049dc2;
      }
      ERR_put_error(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
      BN_CTX_free(c);
      if (puVar14 != (uchar *)0x0) {
        CRYPTO_free(puVar14);
      }
    }
    EC_KEY_free(pEVar17);
  }
  else {
    iVar11 = *(int *)(param_1[0x30] + 0x98);
    if (iVar11 == 0) {
      ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0x95b);
    }
    else {
      rsa = *(RSA **)(iVar11 + 0x6c);
      if (rsa == (RSA *)0x0) {
        pEVar8 = X509_get_pubkey(*(X509 **)(iVar11 + 0xc));
        if (((pEVar8 == (EVP_PKEY *)0x0) || (pEVar8->type != 6)) ||
           (rsa = (pEVar8->pkey).rsa, rsa == (rsa_st *)0x0)) {
          ERR_put_error(0x14,0x98,0x44,"s3_clnt.c",0x969);
          EVP_PKEY_free(pEVar8);
          goto LAB_0004a2a4;
        }
        EVP_PKEY_free(pEVar8);
      }
      local_230[1] = (uchar)param_1[0x44];
      local_230[0] = (uchar)((uint)param_1[0x44] >> 8);
      iVar11 = RAND_bytes(local_230 + 2,0x2e);
      if (0 < iVar11) {
        if (0x300 < *param_1) {
          puVar14 = puVar13 + 6;
        }
        *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
        iVar2 = RSA_public_encrypt(0x30,local_230,puVar14,rsa,1);
        if (0 < iVar2) {
          iVar12 = *param_1;
          iVar11 = iVar12;
          if (0x300 < iVar12) {
            puVar13[5] = (char)iVar2;
            iVar11 = iVar2 >> 8;
          }
          if (0x300 < iVar12) {
            puVar13[4] = (char)iVar11;
          }
          iVar11 = param_1[0x30];
          if (0x300 < iVar12) {
            iVar2 = iVar2 + 2;
          }
          uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar11 + 0x14,local_230,0x30);
          *(undefined4 *)(iVar11 + 0x10) = uVar3;
          OPENSSL_cleanse(local_230,0x30);
LAB_00049dc2:
          puVar13[3] = (char)iVar2;
          *puVar13 = 0x10;
          puVar13[1] = (char)((uint)iVar2 >> 0x10);
          puVar13[2] = (char)((uint)iVar2 >> 8);
          param_1[0x11] = iVar2 + 4;
          param_1[0xd] = 0x1181;
          param_1[0x12] = 0;
          goto LAB_00049dec;
        }
        ERR_put_error(0x14,0x98,0x77,"s3_clnt.c",0x986);
      }
    }
LAB_0004a2a4:
    pkey = (DH *)0x0;
LAB_0004a1d0:
    BN_CTX_free((BN_CTX *)0x0);
  }
  EVP_PKEY_free((EVP_PKEY *)pkey);
  uVar3 = 0xffffffff;
  param_1[0xd] = 5;
LAB_00049df4:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

