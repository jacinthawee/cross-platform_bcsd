
void dtls1_send_client_key_exchange(int *param_1)

{
  uchar uVar1;
  int iVar2;
  undefined4 uVar3;
  EC_GROUP *group;
  EC_POINT *pEVar4;
  size_t sVar5;
  BN_CTX *c;
  DH *pDVar6;
  char *pcVar7;
  EVP_PKEY *pkey;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uchar *puVar12;
  DH *pDVar13;
  RSA *rsa;
  EC_KEY *pEVar14;
  DH *pkey_00;
  char acStack_2b0 [128];
  uchar local_230 [516];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (param_1[0xd] != 0x1180) {
LAB_00057fa4:
    uVar3 = dtls1_do_write(param_1,0x16);
    goto LAB_00057fac;
  }
  iVar11 = *(int *)(param_1[0xf] + 4);
  uVar8 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  puVar12 = (uchar *)(iVar11 + 0xc);
  if ((DH *)(uVar8 & 1) == (DH *)0x0) {
    pkey_00 = (DH *)(uVar8 & 0xe);
    if (pkey_00 != (DH *)0x0) {
      pkey_00 = *(DH **)(param_1[0x30] + 0x98);
      if (pkey_00 == (DH *)0x0) {
        ssl3_send_alert(param_1,2,10);
        ERR_put_error(0x14,0x106,0xf4,"d1_clnt.c",0x4b8);
      }
      else {
        pkey_00 = *(DH **)&pkey_00[1].field_0x24;
        if (pkey_00 == (DH *)0x0) {
          ssl3_send_alert(param_1,2,0x28);
          ERR_put_error(0x14,0x106,0xee,"d1_clnt.c",0x4c2);
        }
        else {
          pDVar13 = DHparams_dup(pkey_00);
          if (pDVar13 == (DH *)0x0) {
            ERR_put_error(0x14,0x106,5,"d1_clnt.c",0x4c8);
            pkey_00 = pDVar13;
          }
          else {
            pDVar6 = (DH *)DH_generate_key(pDVar13);
            if (pDVar6 == (DH *)0x0) {
              ERR_put_error(0x14,0x106,5,"d1_clnt.c",0x4cc);
              pkey_00 = pDVar6;
            }
            else {
              sVar5 = DH_compute_key(puVar12,*(BIGNUM **)&pkey_00->field_0x14,pDVar13);
              if (0 < (int)sVar5) {
                iVar9 = param_1[0x30];
                uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar9 + 0x14,puVar12,sVar5);
                *(undefined4 *)(iVar9 + 0x10) = uVar3;
                memset(puVar12,0,sVar5);
                iVar2 = BN_num_bits(*(BIGNUM **)&pDVar13->field_0x14);
                iVar9 = iVar2 + 7;
                if (iVar2 + 7 < 0) {
                  iVar9 = iVar2 + 0xe;
                }
                *(char *)(iVar11 + 0xd) = (char)(iVar9 >> 3);
                iVar2 = (iVar9 >> 3) + 2;
                *(char *)(iVar11 + 0xc) = (char)(iVar9 >> 0xb);
                BN_bn2bin(*(BIGNUM **)&pDVar13->field_0x14,(uchar *)(iVar11 + 0xe));
                DH_free(pDVar13);
                goto LAB_00057f78;
              }
              ERR_put_error(0x14,0x106,5,"d1_clnt.c",0x4d8);
              pkey_00 = (DH *)(uVar8 & 1);
            }
          }
        }
      }
      goto LAB_0005831e;
    }
    if ((uVar8 & 0xe0) == 0) {
      if ((DH *)(uVar8 & 0x100) != (DH *)0x0) {
        if ((code *)param_1[0x37] == (code *)0x0) {
          ERR_put_error(0x14,0x106,0xe0,"d1_clnt.c",0x5a7);
        }
        else {
          uVar8 = (*(code *)param_1[0x37])
                            (param_1,*(undefined4 *)(param_1[0x39] + 0x14c),acStack_2b0,0x80,
                             local_230,0x204);
          if (uVar8 < 0x101) {
            if (uVar8 == 0) {
              ERR_put_error(0x14,0x106,0xdf,"d1_clnt.c",0x5b5);
            }
            else {
              memmove(local_230 + uVar8 + 4,local_230,uVar8);
              uVar1 = (uchar)(uVar8 >> 8);
              local_230[0] = uVar1;
              local_230[1] = (uchar)uVar8;
              __memset_chk(local_230 + 2,0,uVar8,0x202);
              iVar9 = param_1[0x30];
              (local_230 + 2)[uVar8] = uVar1;
              local_230[uVar8 + 3] = (uchar)uVar8;
              if (*(void **)(iVar9 + 0x8c) != (void *)0x0) {
                CRYPTO_free(*(void **)(iVar9 + 0x8c));
                iVar9 = param_1[0x30];
              }
              pcVar7 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
              iVar10 = param_1[0x30];
              iVar2 = *(int *)(param_1[0x39] + 0x14c);
              *(char **)(iVar9 + 0x8c) = pcVar7;
              if ((iVar2 == 0) || (*(int *)(iVar10 + 0x8c) != 0)) {
                if (*(void **)(iVar10 + 0x90) != (void *)0x0) {
                  CRYPTO_free(*(void **)(iVar10 + 0x90));
                  iVar10 = param_1[0x30];
                }
                pcVar7 = BUF_strdup(acStack_2b0);
                iVar9 = param_1[0x30];
                *(char **)(iVar10 + 0x90) = pcVar7;
                if (*(int *)(iVar9 + 0x90) != 0) {
                  uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                    (param_1,iVar9 + 0x14,local_230,uVar8 * 2 + 4);
                  *(undefined4 *)(iVar9 + 0x10) = uVar3;
                  sVar5 = strlen(acStack_2b0);
                  *(char *)(iVar11 + 0xd) = (char)sVar5;
                  *(char *)(iVar11 + 0xc) = (char)(sVar5 >> 8);
                  memcpy((void *)(iVar11 + 0xe),acStack_2b0,sVar5);
                  iVar2 = sVar5 + 2;
                  OPENSSL_cleanse(acStack_2b0,0x80);
                  OPENSSL_cleanse(local_230,0x204);
                  goto LAB_00057f78;
                }
                iVar11 = 0x5d2;
              }
              else {
                iVar11 = 0x5c9;
              }
              ERR_put_error(0x14,0x106,0x41,"d1_clnt.c",iVar11);
            }
          }
          else {
            ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",0x5b1);
          }
          OPENSSL_cleanse(acStack_2b0,0x80);
          OPENSSL_cleanse(local_230,0x204);
          ssl3_send_alert(param_1,2,0x28);
        }
        goto LAB_0005831a;
      }
      ssl3_send_alert(param_1,2,0x28);
      ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",0x5ed);
      pkey_00 = (DH *)(uVar8 & 0x100);
      goto LAB_0005831e;
    }
    pDVar13 = *(DH **)(param_1[0x30] + 0x98);
    if (pDVar13 == (DH *)0x0) {
      ssl3_send_alert(param_1,2,10);
      ERR_put_error(0x14,0x106,0xf4,"d1_clnt.c",0x4fa);
      pkey_00 = pDVar13;
      goto LAB_0005831e;
    }
    pEVar14 = *(EC_KEY **)&pDVar13[1].field_0x28;
    if ((pEVar14 == (EC_KEY *)0x0) &&
       (((pkey_00 = (DH *)X509_get_pubkey(*(X509 **)&pDVar13->field_0x48), pkey_00 == (DH *)0x0 ||
         (*(int *)pkey_00 != 0x198)) ||
        (pEVar14 = *(EC_KEY **)&pkey_00->field_0x14, pEVar14 == (EC_KEY *)0x0)))) {
      iVar11 = 0x51d;
LAB_00058392:
      ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",iVar11);
      goto LAB_0005831e;
    }
    group = EC_KEY_get0_group(pEVar14);
    pEVar4 = EC_KEY_get0_public_key(pEVar14);
    if (group == (EC_GROUP *)0x0 || pEVar4 == (EC_POINT *)0x0) {
      iVar11 = 0x529;
      goto LAB_00058392;
    }
    pEVar14 = EC_KEY_new();
    if (pEVar14 == (EC_KEY *)0x0) {
      ERR_put_error(0x14,0x106,0x41,"d1_clnt.c",0x52f);
      goto LAB_0005831e;
    }
    iVar9 = EC_KEY_set_group(pEVar14,group);
    if (iVar9 == 0) {
      ERR_put_error(0x14,0x106,0x10,"d1_clnt.c",0x534);
LAB_000583f8:
      BN_CTX_free((BN_CTX *)0x0);
    }
    else {
      iVar9 = EC_KEY_generate_key(pEVar14);
      iVar2 = 0x54d;
      if (iVar9 == 0) {
LAB_000583e6:
        ERR_put_error(0x14,0x106,0x2b,"d1_clnt.c",iVar2);
        goto LAB_000583f8;
      }
      iVar9 = EC_GROUP_get_degree(group);
      if (iVar9 < 1) {
        iVar2 = 0x559;
        goto LAB_000583e6;
      }
      sVar5 = ECDH_compute_key(puVar12,iVar9 + 7 >> 3,pEVar4,pEVar14,(KDF *)0x0);
      if ((int)sVar5 < 1) {
        iVar2 = 0x55f;
        goto LAB_000583e6;
      }
      iVar9 = param_1[0x30];
      uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar9 + 0x14,puVar12,sVar5);
      *(undefined4 *)(iVar9 + 0x10) = uVar3;
      memset(puVar12,0,sVar5);
      pEVar4 = EC_KEY_get0_public_key(pEVar14);
      sVar5 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                 (BN_CTX *)0x0);
      puVar12 = (uchar *)CRYPTO_malloc(sVar5,"d1_clnt.c",0x57b);
      c = BN_CTX_new();
      if (puVar12 != (uchar *)0x0 && c != (BN_CTX *)0x0) {
        pEVar4 = EC_KEY_get0_public_key(pEVar14);
        sVar5 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,puVar12,sVar5,c);
        *(char *)(iVar11 + 0xc) = (char)sVar5;
        memcpy((void *)(iVar11 + 0xd),puVar12,sVar5);
        BN_CTX_free(c);
        CRYPTO_free(puVar12);
        EC_KEY_free(pEVar14);
        iVar2 = sVar5 + 1;
        EVP_PKEY_free((EVP_PKEY *)pkey_00);
        goto LAB_00057f78;
      }
      ERR_put_error(0x14,0x106,0x41,"d1_clnt.c",0x57f);
      BN_CTX_free(c);
      if (puVar12 != (uchar *)0x0) {
        CRYPTO_free(puVar12);
      }
    }
    EC_KEY_free(pEVar14);
  }
  else {
    iVar9 = *(int *)(param_1[0x30] + 0x98);
    if (iVar9 == 0) {
      iVar11 = 0x3f5;
LAB_000583ca:
      ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",iVar11);
    }
    else {
      rsa = *(RSA **)(iVar9 + 0x6c);
      if (rsa == (RSA *)0x0) {
        pkey = X509_get_pubkey(*(X509 **)(iVar9 + 0xc));
        if (((pkey == (EVP_PKEY *)0x0) || (pkey->type != 6)) ||
           (rsa = (pkey->pkey).rsa, rsa == (rsa_st *)0x0)) {
          iVar11 = 0x403;
          goto LAB_000583ca;
        }
        EVP_PKEY_free(pkey);
      }
      local_230[1] = (uchar)param_1[0x44];
      local_230[0] = (uchar)((uint)param_1[0x44] >> 8);
      iVar9 = RAND_bytes(local_230 + 2,0x2e);
      if (0 < iVar9) {
        if (0x300 < *param_1) {
          puVar12 = (uchar *)(iVar11 + 0xe);
        }
        *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
        iVar2 = RSA_public_encrypt(0x30,local_230,puVar12,rsa,1);
        if (0 < iVar2) {
          iVar10 = *param_1;
          iVar9 = iVar10;
          if (0x300 < iVar10) {
            *(char *)(iVar11 + 0xd) = (char)iVar2;
            iVar9 = iVar2 >> 8;
          }
          if (0x300 < iVar10) {
            *(char *)(iVar11 + 0xc) = (char)iVar9;
          }
          iVar9 = param_1[0x30];
          if (0x300 < iVar10) {
            iVar2 = iVar2 + 2;
          }
          uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar9 + 0x14,local_230,0x30);
          *(undefined4 *)(iVar9 + 0x10) = uVar3;
          OPENSSL_cleanse(local_230,0x30);
LAB_00057f78:
          dtls1_set_message_header(param_1,iVar11,0x10,iVar2,0,iVar2);
          param_1[0x12] = 0;
          param_1[0x11] = iVar2 + 0xc;
          param_1[0xd] = 0x1181;
          dtls1_buffer_message(param_1,0);
          goto LAB_00057fa4;
        }
        ERR_put_error(0x14,0x106,0x77,"d1_clnt.c",0x41f);
      }
    }
LAB_0005831a:
    pkey_00 = (DH *)0x0;
LAB_0005831e:
    BN_CTX_free((BN_CTX *)0x0);
  }
  EVP_PKEY_free((EVP_PKEY *)pkey_00);
  uVar3 = 0xffffffff;
LAB_00057fac:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

