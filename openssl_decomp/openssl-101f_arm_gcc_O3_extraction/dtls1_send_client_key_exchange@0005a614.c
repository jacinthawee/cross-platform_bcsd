
void dtls1_send_client_key_exchange(int *param_1)

{
  uchar uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  EC_GROUP *group;
  EC_POINT *pEVar5;
  size_t sVar6;
  BN_CTX *c;
  DH *dh;
  DH *pDVar7;
  char *pcVar8;
  EVP_PKEY *pkey;
  uint uVar9;
  int iVar10;
  int iVar11;
  uchar *puVar12;
  RSA *rsa;
  EC_KEY *pEVar13;
  DH *pkey_00;
  char acStack_2b0 [128];
  uchar local_230 [516];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (param_1[0xd] != 0x1180) {
LAB_0005a70e:
    uVar4 = dtls1_do_write(param_1,0x16);
    goto LAB_0005a716;
  }
  iVar11 = *(int *)(param_1[0xf] + 4);
  uVar9 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  puVar12 = (uchar *)(iVar11 + 0xc);
  if ((DH *)(uVar9 & 1) == (DH *)0x0) {
    pkey_00 = (DH *)(uVar9 & 0xe);
    if (pkey_00 != (DH *)0x0) {
      pkey_00 = *(DH **)(*(int *)(param_1[0x30] + 0x98) + 0x70);
      if (pkey_00 != (DH *)0x0) {
        dh = DHparams_dup(pkey_00);
        if (dh == (DH *)0x0) {
          ERR_put_error(0x14,0x106,5,"d1_clnt.c",0x4ac);
          pkey_00 = dh;
          goto LAB_0005aa7a;
        }
        pDVar7 = (DH *)DH_generate_key(dh);
        if (pDVar7 == (DH *)0x0) {
          ERR_put_error(0x14,0x106,5,"d1_clnt.c",0x4b1);
          pkey_00 = pDVar7;
          goto LAB_0005aa7a;
        }
        sVar6 = DH_compute_key(puVar12,*(BIGNUM **)&pkey_00->field_0x14,dh);
        if ((int)sVar6 < 1) {
          ERR_put_error(0x14,0x106,5,"d1_clnt.c",0x4bc);
          pkey_00 = (DH *)(uVar9 & 1);
          goto LAB_0005aa7a;
        }
        iVar2 = param_1[0x30];
        uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar2 + 0x14,puVar12,sVar6);
        *(undefined4 *)(iVar2 + 0x10) = uVar4;
        memset(puVar12,0,sVar6);
        iVar3 = BN_num_bits(*(BIGNUM **)&dh->field_0x14);
        iVar2 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar2 = iVar3 + 0xe;
        }
        *(char *)(iVar11 + 0xd) = (char)(iVar2 >> 3);
        iVar3 = (iVar2 >> 3) + 2;
        *(char *)(iVar11 + 0xc) = (char)(iVar2 >> 0xb);
        BN_bn2bin(*(BIGNUM **)&dh->field_0x14,(uchar *)(iVar11 + 0xe));
        DH_free(dh);
LAB_0005a6e2:
        dtls1_set_message_header(param_1,iVar11,0x10,iVar3,0,iVar3);
        param_1[0x12] = 0;
        param_1[0x11] = iVar3 + 0xc;
        param_1[0xd] = 0x1181;
        dtls1_buffer_message(param_1,0);
        goto LAB_0005a70e;
      }
      ssl3_send_alert(param_1,2,0x28);
      ERR_put_error(0x14,0x106,0xee,"d1_clnt.c",0x4a5);
      goto LAB_0005aa7a;
    }
    if ((uVar9 & 0xe0) == 0) {
      if ((DH *)(uVar9 & 0x100) != (DH *)0x0) {
        if ((code *)param_1[0x37] == (code *)0x0) {
          ERR_put_error(0x14,0x106,0xe0,"d1_clnt.c",0x599);
        }
        else {
          uVar9 = (*(code *)param_1[0x37])
                            (param_1,*(undefined4 *)(param_1[0x39] + 0x14c),acStack_2b0,0x80,
                             local_230,0x204);
          if (uVar9 < 0x101) {
            if (uVar9 == 0) {
              ERR_put_error(0x14,0x106,0xdf,"d1_clnt.c",0x5a9);
            }
            else {
              memmove(local_230 + uVar9 + 4,local_230,uVar9);
              uVar1 = (uchar)(uVar9 >> 8);
              local_230[0] = uVar1;
              local_230[1] = (uchar)uVar9;
              __memset_chk(local_230 + 2,0,uVar9,0x202);
              iVar2 = param_1[0x30];
              (local_230 + 2)[uVar9] = uVar1;
              local_230[uVar9 + 3] = (uchar)uVar9;
              if (*(void **)(iVar2 + 0x8c) != (void *)0x0) {
                CRYPTO_free(*(void **)(iVar2 + 0x8c));
                iVar2 = param_1[0x30];
              }
              pcVar8 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
              iVar10 = param_1[0x30];
              iVar3 = *(int *)(param_1[0x39] + 0x14c);
              *(char **)(iVar2 + 0x8c) = pcVar8;
              if ((iVar3 == 0) || (*(int *)(iVar10 + 0x8c) != 0)) {
                if (*(void **)(iVar10 + 0x90) != (void *)0x0) {
                  CRYPTO_free(*(void **)(iVar10 + 0x90));
                  iVar10 = param_1[0x30];
                }
                pcVar8 = BUF_strdup(acStack_2b0);
                iVar2 = param_1[0x30];
                *(char **)(iVar10 + 0x90) = pcVar8;
                if (*(int *)(iVar2 + 0x90) != 0) {
                  uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                    (param_1,iVar2 + 0x14,local_230,uVar9 * 2 + 4);
                  *(undefined4 *)(iVar2 + 0x10) = uVar4;
                  sVar6 = strlen(acStack_2b0);
                  *(char *)(iVar11 + 0xd) = (char)sVar6;
                  *(char *)(iVar11 + 0xc) = (char)(sVar6 >> 8);
                  memcpy((void *)(iVar11 + 0xe),acStack_2b0,sVar6);
                  iVar3 = sVar6 + 2;
                  OPENSSL_cleanse(acStack_2b0,0x80);
                  OPENSSL_cleanse(local_230,0x204);
                  goto LAB_0005a6e2;
                }
                iVar11 = 0x5c7;
              }
              else {
                iVar11 = 0x5bd;
              }
              ERR_put_error(0x14,0x106,0x41,"d1_clnt.c",iVar11);
            }
          }
          else {
            ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",0x5a3);
          }
          OPENSSL_cleanse(acStack_2b0,0x80);
          OPENSSL_cleanse(local_230,0x204);
          ssl3_send_alert(param_1,2,0x28);
        }
        goto LAB_0005aa76;
      }
      ssl3_send_alert(param_1,2,0x28);
      ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",0x5e1);
      pkey_00 = (DH *)(uVar9 & 0x100);
      goto LAB_0005aa7a;
    }
    pEVar13 = *(EC_KEY **)(*(int *)(param_1[0x30] + 0x98) + 0x74);
    if ((pEVar13 == (EC_KEY *)0x0) &&
       (((pkey_00 = (DH *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x48)),
         pkey_00 == (DH *)0x0 || (*(int *)pkey_00 != 0x198)) ||
        (pEVar13 = *(EC_KEY **)&pkey_00->field_0x14, pEVar13 == (EC_KEY *)0x0)))) {
      iVar11 = 0x504;
LAB_0005aaee:
      ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",iVar11);
      goto LAB_0005aa7a;
    }
    group = EC_KEY_get0_group(pEVar13);
    pEVar5 = EC_KEY_get0_public_key(pEVar13);
    if (group == (EC_GROUP *)0x0 || pEVar5 == (EC_POINT *)0x0) {
      iVar11 = 0x511;
      goto LAB_0005aaee;
    }
    pEVar13 = EC_KEY_new();
    if (pEVar13 == (EC_KEY *)0x0) {
      ERR_put_error(0x14,0x106,0x41,"d1_clnt.c",0x517);
      goto LAB_0005aa7a;
    }
    iVar2 = EC_KEY_set_group(pEVar13,group);
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x106,0x10,"d1_clnt.c",0x51d);
LAB_0005ab54:
      BN_CTX_free((BN_CTX *)0x0);
    }
    else {
      iVar2 = EC_KEY_generate_key(pEVar13);
      iVar3 = 0x539;
      if (iVar2 == 0) {
LAB_0005ab42:
        ERR_put_error(0x14,0x106,0x2b,"d1_clnt.c",iVar3);
        goto LAB_0005ab54;
      }
      iVar2 = EC_GROUP_get_degree(group);
      if (iVar2 < 1) {
        iVar3 = 0x546;
        goto LAB_0005ab42;
      }
      sVar6 = ECDH_compute_key(puVar12,iVar2 + 7 >> 3,pEVar5,pEVar13,(KDF *)0x0);
      if ((int)sVar6 < 1) {
        iVar3 = 0x54d;
        goto LAB_0005ab42;
      }
      iVar2 = param_1[0x30];
      uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar2 + 0x14,puVar12,sVar6);
      *(undefined4 *)(iVar2 + 0x10) = uVar4;
      memset(puVar12,0,sVar6);
      pEVar5 = EC_KEY_get0_public_key(pEVar13);
      sVar6 = EC_POINT_point2oct(group,pEVar5,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                 (BN_CTX *)0x0);
      puVar12 = (uchar *)CRYPTO_malloc(sVar6,"d1_clnt.c",0x56b);
      c = BN_CTX_new();
      if (puVar12 != (uchar *)0x0 && c != (BN_CTX *)0x0) {
        pEVar5 = EC_KEY_get0_public_key(pEVar13);
        sVar6 = EC_POINT_point2oct(group,pEVar5,POINT_CONVERSION_UNCOMPRESSED,puVar12,sVar6,c);
        *(char *)(iVar11 + 0xc) = (char)sVar6;
        memcpy((void *)(iVar11 + 0xd),puVar12,sVar6);
        BN_CTX_free(c);
        CRYPTO_free(puVar12);
        EC_KEY_free(pEVar13);
        iVar3 = sVar6 + 1;
        EVP_PKEY_free((EVP_PKEY *)pkey_00);
        goto LAB_0005a6e2;
      }
      ERR_put_error(0x14,0x106,0x41,"d1_clnt.c",0x570);
      BN_CTX_free(c);
      if (puVar12 != (uchar *)0x0) {
        CRYPTO_free(puVar12);
      }
    }
    EC_KEY_free(pEVar13);
  }
  else {
    rsa = *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x6c);
    if (rsa == (RSA *)0x0) {
      pkey = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
      if (((pkey != (EVP_PKEY *)0x0) && (pkey->type == 6)) &&
         (rsa = (pkey->pkey).rsa, rsa != (rsa_st *)0x0)) {
        EVP_PKEY_free(pkey);
        goto LAB_0005a65c;
      }
      ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",0x3ea);
    }
    else {
LAB_0005a65c:
      local_230[1] = (uchar)param_1[0x44];
      local_230[0] = (uchar)((uint)param_1[0x44] >> 8);
      iVar2 = RAND_bytes(local_230 + 2,0x2e);
      if (0 < iVar2) {
        if (0x300 < *param_1) {
          puVar12 = (uchar *)(iVar11 + 0xe);
        }
        *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
        iVar3 = RSA_public_encrypt(0x30,local_230,puVar12,rsa,1);
        if (0 < iVar3) {
          iVar10 = *param_1;
          iVar2 = iVar10;
          if (0x300 < iVar10) {
            *(char *)(iVar11 + 0xd) = (char)iVar3;
            iVar2 = iVar3 >> 8;
          }
          if (0x300 < iVar10) {
            *(char *)(iVar11 + 0xc) = (char)iVar2;
          }
          iVar2 = param_1[0x30];
          if (0x300 < iVar10) {
            iVar3 = iVar3 + 2;
          }
          uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar2 + 0x14,local_230,0x30);
          *(undefined4 *)(iVar2 + 0x10) = uVar4;
          OPENSSL_cleanse(local_230,0x30);
          goto LAB_0005a6e2;
        }
        ERR_put_error(0x14,0x106,0x77,"d1_clnt.c",0x404);
      }
    }
LAB_0005aa76:
    pkey_00 = (DH *)0x0;
LAB_0005aa7a:
    BN_CTX_free((BN_CTX *)0x0);
  }
  EVP_PKEY_free((EVP_PKEY *)pkey_00);
  uVar4 = 0xffffffff;
LAB_0005a716:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}

