
undefined4 dtls1_send_client_key_exchange(int *param_1)

{
  DH *pDVar1;
  int iVar2;
  undefined4 uVar3;
  EC_GROUP *group;
  EC_POINT *pEVar4;
  EC_KEY *key;
  size_t sVar5;
  uchar *puVar6;
  BN_CTX *c;
  DH *dh;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  EVP_PKEY *pkey;
  uchar uVar11;
  uint *puVar12;
  uint *puVar13;
  RSA *rsa;
  rsa_st *key_00;
  int in_GS_OFFSET;
  bool bVar14;
  int iVar15;
  EVP_PKEY *local_2bc;
  char *local_2b4;
  uint local_2a4 [32];
  uchar local_224;
  uchar local_223;
  uchar local_222 [514];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1[0xd] != 0x1180) {
LAB_080b2e93:
    uVar3 = dtls1_do_write(param_1,0x16);
    goto LAB_080b2ea1;
  }
  iVar15 = *(int *)(param_1[0xf] + 4);
  puVar6 = (uchar *)(iVar15 + 0xc);
  uVar8 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  if ((uVar8 & 1) == 0) {
    if ((uVar8 & 0xe) != 0) {
      if (*(int *)(param_1[0x30] + 0x98) == 0) {
        ssl3_send_alert(param_1,2,10);
        iVar2 = 0x4b8;
        iVar15 = 0xf4;
      }
      else {
        pDVar1 = *(DH **)(*(int *)(param_1[0x30] + 0x98) + 0x70);
        if (pDVar1 == (DH *)0x0) {
          ssl3_send_alert(param_1,2,0x28);
          iVar2 = 0x4c2;
          iVar15 = 0xee;
        }
        else {
          dh = DHparams_dup(pDVar1);
          if (dh == (DH *)0x0) {
            iVar2 = 0x4c8;
            iVar15 = 5;
          }
          else {
            iVar2 = DH_generate_key(dh);
            if (iVar2 == 0) {
              iVar2 = 0x4cc;
              iVar15 = 5;
            }
            else {
              sVar5 = DH_compute_key(puVar6,*(BIGNUM **)&pDVar1->field_0x14,dh);
              if (0 < (int)sVar5) {
                iVar2 = param_1[0x30];
                uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar2 + 0x14,puVar6,sVar5);
                *(undefined4 *)(iVar2 + 0x10) = uVar3;
                memset(puVar6,0,sVar5);
                iVar7 = BN_num_bits(*(BIGNUM **)&dh->field_0x14);
                iVar2 = iVar7 + 7;
                if (iVar7 + 7 < 0) {
                  iVar2 = iVar7 + 0xe;
                }
                *(char *)(iVar15 + 0xc) = (char)(iVar2 >> 0xb);
                *(char *)(iVar15 + 0xd) = (char)(iVar2 >> 3);
                BN_bn2bin(*(BIGNUM **)&dh->field_0x14,(uchar *)(iVar15 + 0xe));
                local_2b4 = (char *)((iVar2 >> 3) + 2);
                DH_free(dh);
                goto LAB_080b2e54;
              }
              iVar2 = 0x4d8;
              iVar15 = 5;
            }
          }
        }
      }
      goto LAB_080b3585;
    }
    if ((uVar8 & 0xe0) == 0) {
      if ((uVar8 & 0x100) == 0) {
        ssl3_send_alert(param_1,2,0x28);
        iVar2 = 0x5ed;
        goto LAB_080b35a1;
      }
      if ((code *)param_1[0x37] == (code *)0x0) {
        ERR_put_error(0x14,0x106,0xe0,"d1_clnt.c",0x5a7);
      }
      else {
        uVar8 = (*(code *)param_1[0x37])
                          (param_1,*(undefined4 *)(param_1[0x39] + 0x14c),local_2a4,0x80,&local_224,
                           0x204);
        if (uVar8 < 0x101) {
          if (uVar8 == 0) {
            ERR_put_error(0x14,0x106,0xdf,"d1_clnt.c",0x5b5);
          }
          else {
            memmove(local_222 + uVar8 + 2,&local_224,uVar8);
            uVar11 = (uchar)(uVar8 >> 8);
            local_224 = uVar11;
            local_223 = (uchar)uVar8;
            __memset_chk(local_222,0,uVar8,0x202);
            local_222[uVar8 + 1] = (uchar)uVar8;
            local_2b4 = (char *)param_1[0x30];
            local_222[uVar8] = uVar11;
            if (*(void **)((int)local_2b4 + 0x8c) != (void *)0x0) {
              CRYPTO_free(*(void **)((int)local_2b4 + 0x8c));
              local_2b4 = (char *)param_1[0x30];
            }
            pcVar9 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
            *(char **)((int)local_2b4 + 0x8c) = pcVar9;
            local_2b4 = (char *)param_1[0x30];
            if ((*(int *)(param_1[0x39] + 0x14c) == 0) || (*(int *)((int)local_2b4 + 0x8c) != 0)) {
              if (*(void **)((int)local_2b4 + 0x90) != (void *)0x0) {
                CRYPTO_free(*(void **)((int)local_2b4 + 0x90));
                local_2b4 = (char *)param_1[0x30];
              }
              pcVar9 = BUF_strdup((char *)local_2a4);
              *(char **)((int)local_2b4 + 0x90) = pcVar9;
              iVar2 = param_1[0x30];
              if (*(int *)(iVar2 + 0x90) != 0) {
                uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar2 + 0x14,&local_224,uVar8 * 2 + 4);
                *(undefined4 *)(iVar2 + 0x10) = uVar3;
                puVar13 = local_2a4;
                do {
                  puVar12 = puVar13;
                  uVar10 = *puVar12 + 0xfefefeff & ~*puVar12;
                  uVar8 = uVar10 & 0x80808080;
                  puVar13 = puVar12 + 1;
                } while (uVar8 == 0);
                bVar14 = (uVar10 & 0x8080) == 0;
                if (bVar14) {
                  uVar8 = uVar8 >> 0x10;
                }
                puVar13 = (uint *)((int)puVar12 + 6);
                if (!bVar14) {
                  puVar13 = puVar12 + 1;
                }
                local_2b4 = (char *)((int)puVar13 +
                                    ((-3 - (uint)CARRY1((byte)uVar8,(byte)uVar8)) - (int)local_2a4))
                ;
                *(char *)(iVar15 + 0xd) = (char)local_2b4;
                *(char *)(iVar15 + 0xc) = (char)((uint)local_2b4 >> 8);
                memcpy((void *)(iVar15 + 0xe),local_2a4,(size_t)local_2b4);
                local_2b4 = local_2b4 + 2;
                OPENSSL_cleanse(local_2a4,0x80);
                OPENSSL_cleanse(&local_224,0x204);
                goto LAB_080b2e54;
              }
              iVar15 = 0x5d2;
            }
            else {
              iVar15 = 0x5c9;
            }
            ERR_put_error(0x14,0x106,0x41,"d1_clnt.c",iVar15);
          }
        }
        else {
          ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",0x5b1);
        }
        OPENSSL_cleanse(local_2a4,0x80);
        OPENSSL_cleanse(&local_224,0x204);
        ssl3_send_alert(param_1,2,0x28);
      }
      goto LAB_080b348c;
    }
    iVar2 = *(int *)(param_1[0x30] + 0x98);
    if (iVar2 == 0) {
      ssl3_send_alert(param_1,2,10,0);
      iVar2 = 0x4fa;
      iVar15 = 0xf4;
      goto LAB_080b3585;
    }
    key_00 = *(rsa_st **)(iVar2 + 0x74);
    local_2bc = (EVP_PKEY *)0x0;
    if (key_00 == (rsa_st *)0x0) {
      local_2bc = X509_get_pubkey(*(X509 **)(iVar2 + 0x48));
      if (((local_2bc != (EVP_PKEY *)0x0) && (local_2bc->type == 0x198)) &&
         (key_00 = (local_2bc->pkey).rsa, key_00 != (rsa_st *)0x0)) goto LAB_080b2ef9;
      iVar15 = 0x51d;
LAB_080b355b:
      ERR_put_error(0x14,0x106,0x44,"d1_clnt.c",iVar15);
      goto LAB_080b3496;
    }
LAB_080b2ef9:
    group = EC_KEY_get0_group((EC_KEY *)key_00);
    pEVar4 = EC_KEY_get0_public_key((EC_KEY *)key_00);
    if ((group == (EC_GROUP *)0x0) || (pEVar4 == (EC_POINT *)0x0)) {
      iVar15 = 0x529;
      goto LAB_080b355b;
    }
    key = EC_KEY_new();
    if (key == (EC_KEY *)0x0) {
      ERR_put_error(0x14,0x106,0x41,"d1_clnt.c",0x52f);
      goto LAB_080b3496;
    }
    iVar2 = EC_KEY_set_group(key,group);
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x106,0x10,"d1_clnt.c",0x534);
LAB_080b35f5:
      BN_CTX_free((BN_CTX *)0x0);
    }
    else {
      iVar2 = EC_KEY_generate_key(key);
      if (iVar2 == 0) {
        iVar15 = 0x54d;
LAB_080b3620:
        ERR_put_error(0x14,0x106,0x2b,"d1_clnt.c",iVar15);
        goto LAB_080b35f5;
      }
      iVar2 = EC_GROUP_get_degree(group);
      if (iVar2 < 1) {
        iVar15 = 0x559;
        goto LAB_080b3620;
      }
      sVar5 = ECDH_compute_key(puVar6,iVar2 + 7 >> 3,pEVar4,key,(KDF *)0x0);
      if ((int)sVar5 < 1) {
        iVar15 = 0x55f;
        goto LAB_080b3620;
      }
      iVar2 = param_1[0x30];
      uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar2 + 0x14,puVar6,sVar5);
      *(undefined4 *)(iVar2 + 0x10) = uVar3;
      memset(puVar6,0,sVar5);
      pEVar4 = EC_KEY_get0_public_key(key);
      sVar5 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                 (BN_CTX *)0x0);
      puVar6 = (uchar *)CRYPTO_malloc(sVar5,"d1_clnt.c",0x57b);
      c = BN_CTX_new();
      if ((puVar6 != (uchar *)0x0) && (c != (BN_CTX *)0x0)) {
        pEVar4 = EC_KEY_get0_public_key(key);
        sVar5 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,puVar6,sVar5,c);
        *(char *)(iVar15 + 0xc) = (char)sVar5;
        memcpy((void *)(iVar15 + 0xd),puVar6,sVar5);
        local_2b4 = (char *)(sVar5 + 1);
        BN_CTX_free(c);
        CRYPTO_free(puVar6);
        EC_KEY_free(key);
        EVP_PKEY_free(local_2bc);
        goto LAB_080b2e54;
      }
      ERR_put_error(0x14,0x106,0x41,"d1_clnt.c",0x57f);
      BN_CTX_free(c);
      if (puVar6 != (uchar *)0x0) {
        CRYPTO_free(puVar6);
      }
    }
    EC_KEY_free(key);
  }
  else {
    iVar2 = *(int *)(param_1[0x30] + 0x98);
    if (iVar2 == 0) {
      iVar2 = 0x3f5;
LAB_080b35a1:
      iVar15 = 0x44;
LAB_080b3585:
      ERR_put_error(0x14,0x106,iVar15,"d1_clnt.c",iVar2);
    }
    else {
      rsa = *(RSA **)(iVar2 + 0x6c);
      if (rsa == (RSA *)0x0) {
        pkey = X509_get_pubkey(*(X509 **)(iVar2 + 0xc));
        if (((pkey == (EVP_PKEY *)0x0) || (pkey->type != 6)) ||
           (rsa = (pkey->pkey).rsa, rsa == (rsa_st *)0x0)) {
          iVar2 = 0x403;
          goto LAB_080b35a1;
        }
        EVP_PKEY_free(pkey);
      }
      local_223 = (uchar)param_1[0x44];
      local_224 = (uchar)((uint)param_1[0x44] >> 8);
      iVar2 = RAND_bytes(local_222,0x2e);
      if (0 < iVar2) {
        *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
        if (0x300 < *param_1) {
          puVar6 = (uchar *)(iVar15 + 0xe);
        }
        local_2b4 = (char *)RSA_public_encrypt(0x30,&local_224,puVar6,rsa,1);
        if (0 < (int)local_2b4) {
          if (0x300 < *param_1) {
            *(char *)(iVar15 + 0xc) = (char)((uint)local_2b4 >> 8);
            *(char *)(iVar15 + 0xd) = (char)local_2b4;
            local_2b4 = local_2b4 + 2;
          }
          iVar2 = param_1[0x30];
          uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar2 + 0x14,&local_224,0x30);
          *(undefined4 *)(iVar2 + 0x10) = uVar3;
          OPENSSL_cleanse(&local_224,0x30);
LAB_080b2e54:
          dtls1_set_message_header(param_1,iVar15,0x10,local_2b4,0,local_2b4);
          param_1[0xd] = 0x1181;
          param_1[0x12] = 0;
          param_1[0x11] = (int)(local_2b4 + 0xc);
          dtls1_buffer_message(param_1,0);
          goto LAB_080b2e93;
        }
        ERR_put_error(0x14,0x106,0x77,"d1_clnt.c",0x41f);
      }
    }
LAB_080b348c:
    local_2bc = (EVP_PKEY *)0x0;
LAB_080b3496:
    BN_CTX_free((BN_CTX *)0x0);
  }
  EVP_PKEY_free(local_2bc);
  uVar3 = 0xffffffff;
LAB_080b2ea1:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

