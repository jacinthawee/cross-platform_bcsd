
EVP_PKEY * ssl3_get_client_key_exchange(int *param_1)

{
  int *piVar1;
  DH *dh;
  code *pcVar2;
  ushort uVar3;
  EVP_PKEY *pEVar4;
  int iVar5;
  undefined4 uVar6;
  BIGNUM *pBVar7;
  size_t sVar8;
  EVP_PKEY_CTX *ctx;
  uint uVar9;
  EC_KEY *key;
  EC_GROUP *group;
  EC_POINT *src;
  char *pcVar10;
  undefined uVar11;
  RSA *rsa;
  uint uVar12;
  undefined4 *puVar13;
  ushort *in;
  ushort *s;
  int in_GS_OFFSET;
  byte bVar14;
  int iVar15;
  EVP_PKEY *local_2d0;
  EC_POINT *local_2cc;
  EC_KEY *local_2c0;
  int local_2b0;
  size_t local_2ac;
  undefined4 local_2a5;
  undefined auStack_2a1 [121];
  undefined4 uStack_228;
  undefined local_224 [516];
  int local_20;
  
  bVar14 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2d0 = (EVP_PKEY *)
              (**(code **)(param_1[2] + 0x30))(param_1,0x2190,0x2191,0x10,0x800,&local_2b0);
  if (local_2b0 == 0) goto LAB_0809ac89;
  iVar5 = param_1[0x16];
  s = (ushort *)param_1[0x10];
  uVar12 = *(uint *)(*(int *)(iVar5 + 0x344) + 0xc);
  if ((uVar12 & 1) == 0) {
    if ((uVar12 & 0xe) != 0) {
      pEVar4 = (EVP_PKEY *)(uint)(ushort)(*s << 8 | *s >> 8);
      if (local_2d0 == (EVP_PKEY *)((int)&pEVar4->type + 2U)) {
        s = s + 1;
      }
      else {
        if ((*(byte *)(param_1 + 0x40) & 0x80) == 0) {
          ERR_put_error(0x14,0x8b,0x94,"s3_srvr.c",0x8de);
          goto LAB_0809ae51;
        }
        pEVar4 = local_2d0;
        if (local_2d0 == (EVP_PKEY *)0x0) {
          iVar15 = 0x8eb;
          iVar5 = 0xec;
          goto LAB_0809adb1;
        }
      }
      dh = *(DH **)(iVar5 + 0x348);
      if (dh == (DH *)0x0) {
        iVar15 = 0x8f3;
        iVar5 = 0xab;
        goto LAB_0809adb1;
      }
      pBVar7 = BN_bin2bn((uchar *)s,(int)pEVar4,(BIGNUM *)0x0);
      if (pBVar7 == (BIGNUM *)0x0) {
        ERR_put_error(0x14,0x8b,0x82,"s3_srvr.c",0x8fd);
      }
      else {
        sVar8 = DH_compute_key((uchar *)s,pBVar7,dh);
        if (0 < (int)sVar8) {
          DH_free(*(DH **)(param_1[0x16] + 0x348));
          *(undefined4 *)(param_1[0x16] + 0x348) = 0;
          BN_clear_free(pBVar7);
          iVar5 = param_1[0x30];
          uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar5 + 0x14,s,sVar8);
          *(undefined4 *)(iVar5 + 0x10) = uVar6;
          OPENSSL_cleanse(s,sVar8);
          local_2d0 = (EVP_PKEY *)0x1;
          goto LAB_0809ac89;
        }
        ERR_put_error(0x14,0x8b,5,"s3_srvr.c",0x905);
        BN_clear_free(pBVar7);
      }
      goto LAB_0809ae51;
    }
    if ((uVar12 & 0xe0) == 0) {
      if ((uVar12 & 0x100) == 0) {
        if ((uVar12 & 0x400) == 0) {
          if ((uVar12 & 0x200) == 0) {
            iVar15 = 0xb44;
            iVar5 = 0xf9;
            goto LAB_0809adb1;
          }
          uVar12 = *(uint *)(*(int *)(iVar5 + 0x344) + 0x10);
          local_2ac = 0x20;
          if ((uVar12 & 0x100) == 0) {
            pEVar4 = (EVP_PKEY *)0x0;
            if ((uVar12 & 0x200) != 0) {
              pEVar4 = *(EVP_PKEY **)(param_1[0x26] + 0x88);
            }
          }
          else {
            pEVar4 = *(EVP_PKEY **)(param_1[0x26] + 0x7c);
          }
          ctx = EVP_PKEY_CTX_new(pEVar4,(ENGINE *)0x0);
          EVP_PKEY_decrypt_init(ctx);
          pEVar4 = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
          if ((pEVar4 != (EVP_PKEY *)0x0) &&
             (iVar5 = EVP_PKEY_derive_set_peer(ctx,pEVar4), iVar5 < 1)) {
            ERR_clear_error();
          }
          if (*(byte *)s == 0x30) {
            bVar14 = *(byte *)((int)s + 1);
            if (bVar14 == 0x81) {
              in = (ushort *)((int)s + 3);
              bVar14 = *(byte *)(s + 1);
            }
            else {
              if ((char)bVar14 < '\0') {
                iVar5 = 0xb26;
                goto LAB_0809af6b;
              }
              in = s + 1;
            }
            iVar5 = EVP_PKEY_decrypt(ctx,(uchar *)(&uStack_228 + 1),&local_2ac,(uchar *)in,
                                     (uint)bVar14);
            if (0 < iVar5) {
              iVar5 = param_1[0x30];
              uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                (param_1,iVar5 + 0x14,&uStack_228 + 1,0x20);
              *(undefined4 *)(iVar5 + 0x10) = uVar6;
              iVar5 = EVP_PKEY_CTX_ctrl(ctx,-1,-1,2,2,(void *)0x0);
              local_2d0 = (EVP_PKEY *)((0 < iVar5) + 1);
              EVP_PKEY_free(pEVar4);
              EVP_PKEY_CTX_free(ctx);
              goto LAB_0809ac89;
            }
            iVar5 = 0xb2c;
          }
          else {
            iVar5 = 0xb17;
          }
LAB_0809af6b:
          ERR_put_error(0x14,0x8b,0x93,"s3_srvr.c",iVar5);
          EVP_PKEY_free(pEVar4);
          EVP_PKEY_CTX_free(ctx);
          goto LAB_0809ae51;
        }
        uVar12 = (uint)(ushort)(*s << 8 | *s >> 8);
        if ((int)(uVar12 + 2) <= (int)local_2d0) {
          pBVar7 = BN_bin2bn((uchar *)(s + 1),uVar12,(BIGNUM *)0x0);
          param_1[0x6e] = (int)pBVar7;
          if (pBVar7 == (BIGNUM *)0x0) {
            ERR_put_error(0x14,0x8b,3,"s3_srvr.c",0xae1);
          }
          else {
            iVar5 = param_1[0x30];
            if (*(void **)(iVar5 + 0xf0) != (void *)0x0) {
              CRYPTO_free(*(void **)(iVar5 + 0xf0));
              iVar5 = param_1[0x30];
            }
            pcVar10 = BUF_strdup((char *)param_1[0x69]);
            *(char **)(iVar5 + 0xf0) = pcVar10;
            iVar5 = param_1[0x30];
            if (*(int *)(iVar5 + 0xf0) == 0) {
              iVar5 = 0xaea;
              goto LAB_0809b9cc;
            }
            iVar15 = SRP_generate_server_master_secret(param_1,iVar5 + 0x14);
            *(int *)(iVar5 + 0x10) = iVar15;
            if (-1 < iVar15) {
              local_2d0 = (EVP_PKEY *)0x1;
              goto LAB_0809ac89;
            }
            ERR_put_error(0x14,0x8b,0x44,"s3_srvr.c",0xaf0);
          }
          goto LAB_0809ae51;
        }
        uVar6 = 0x32;
        ERR_put_error(0x14,0x8b,0x15b,"s3_srvr.c",0xadc);
      }
      else {
        uVar3 = *s << 8 | *s >> 8;
        uVar12 = (uint)uVar3;
        if (local_2d0 == (EVP_PKEY *)(uVar12 + 2)) {
          if (0x80 < uVar3) {
            iVar15 = 0xa88;
            iVar5 = 0x92;
            goto LAB_0809ae13;
          }
          pcVar2 = (code *)param_1[0x38];
          if (pcVar2 == (code *)0x0) {
            iVar15 = 0xa8e;
            iVar5 = 0xe1;
            goto LAB_0809ae13;
          }
          __memcpy_chk(&local_2a5,s + 1,uVar12,0x81);
          uVar9 = -uVar12 + 0x81;
          puVar13 = (undefined4 *)((int)&local_2a5 + uVar12);
          if (uVar9 < 4) {
            if ((uVar9 != 0) && (*(undefined *)puVar13 = 0, (uVar9 & 2) != 0)) {
              *(undefined2 *)(-uVar12 + 0x7f + (int)puVar13) = 0;
            }
          }
          else {
            *puVar13 = 0;
            *(undefined4 *)((int)&uStack_228 + uVar9 + uVar12 + -0x81) = 0;
            uVar9 = (uint)((int)puVar13 +
                          (uVar9 - (int)(undefined4 *)((uint)(auStack_2a1 + uVar12) & 0xfffffffc)))
                    >> 2;
            puVar13 = (undefined4 *)((uint)(auStack_2a1 + uVar12) & 0xfffffffc);
            for (; uVar9 != 0; uVar9 = uVar9 - 1) {
              *puVar13 = 0;
              puVar13 = puVar13 + (uint)bVar14 * -2 + 1;
            }
          }
          puVar13 = &uStack_228 + 1;
          uVar12 = (*pcVar2)(param_1,&local_2a5,puVar13,0x204);
          OPENSSL_cleanse(&local_2a5,0x81);
          if (uVar12 < 0x101) {
            if (uVar12 != 0) {
              memmove((void *)((int)&uStack_228 + uVar12 + 8),puVar13,uVar12);
              uVar11 = (undefined)(uVar12 >> 8);
              local_224[0] = uVar11;
              local_224[1] = (char)uVar12;
              __memset_chk((int)&uStack_228 + 6,0,uVar12,0x202);
              *(char *)((int)&uStack_228 + uVar12 + 7) = (char)uVar12;
              local_2c0 = (EC_KEY *)param_1[0x30];
              *(undefined *)((int)&uStack_228 + 6 + uVar12) = uVar11;
              if (*(void **)((int)local_2c0 + 0x90) != (void *)0x0) {
                CRYPTO_free(*(void **)((int)local_2c0 + 0x90));
                local_2c0 = (EC_KEY *)param_1[0x30];
              }
              pcVar10 = BUF_strdup((char *)(s + 1));
              *(char **)((int)local_2c0 + 0x90) = pcVar10;
              local_2c0 = (EC_KEY *)param_1[0x30];
              if (*(int *)((int)local_2c0 + 0x90) == 0) {
                iVar15 = 0xab8;
              }
              else {
                if (*(void **)((int)local_2c0 + 0x8c) != (void *)0x0) {
                  CRYPTO_free(*(void **)((int)local_2c0 + 0x8c));
                  local_2c0 = (EC_KEY *)param_1[0x30];
                }
                pcVar10 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
                *(char **)((int)local_2c0 + 0x8c) = pcVar10;
                iVar5 = param_1[0x30];
                if ((*(int *)(param_1[0x39] + 0x14c) == 0) || (*(int *)(iVar5 + 0x8c) != 0)) {
                  uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                    (param_1,iVar5 + 0x14,puVar13,uVar12 * 2 + 4);
                  *(undefined4 *)(iVar5 + 0x10) = uVar6;
                  OPENSSL_cleanse(puVar13,0x204);
                  local_2d0 = (EVP_PKEY *)0x1;
                  goto LAB_0809ac89;
                }
                iVar15 = 0xac3;
              }
              iVar5 = 0x41;
              goto LAB_0809b752;
            }
            uVar6 = 0x73;
            ERR_put_error(0x14,0x8b,0xdf,"s3_srvr.c",0xaa4);
          }
          else {
            iVar15 = 0xa9d;
            iVar5 = 0x44;
LAB_0809b752:
            uVar6 = 0x28;
            ERR_put_error(0x14,0x8b,iVar5,"s3_srvr.c",iVar15);
          }
        }
        else {
          iVar15 = 0xa82;
          iVar5 = 0x9f;
LAB_0809ae13:
          uVar6 = 0x28;
          ERR_put_error(0x14,0x8b,iVar5,"s3_srvr.c",iVar15);
        }
        OPENSSL_cleanse(&uStack_228 + 1,0x204);
      }
      goto LAB_0809ae3e;
    }
    key = EC_KEY_new();
    if (key == (EC_KEY *)0x0) {
      iVar5 = 0x9e4;
LAB_0809b9cc:
      ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",iVar5);
      goto LAB_0809ae51;
    }
    if ((uVar12 & 0x60) == 0) {
      local_2c0 = *(EC_KEY **)(param_1[0x16] + 0x34c);
    }
    else {
      local_2c0 = *(EC_KEY **)(*(int *)(param_1[0x26] + 0x70) + 0x14);
    }
    group = EC_KEY_get0_group(local_2c0);
    pBVar7 = EC_KEY_get0_private_key(local_2c0);
    iVar5 = EC_KEY_set_group(key,group);
    if ((iVar5 == 0) || (iVar5 = EC_KEY_set_private_key(key,pBVar7), iVar5 == 0)) {
      pEVar4 = (EVP_PKEY *)0x0;
      ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0x9fd);
      local_2c0 = (EC_KEY *)0x0;
      local_2cc = (EC_POINT *)0x0;
LAB_0809b556:
      EVP_PKEY_free(pEVar4);
      EC_POINT_free(local_2cc);
    }
    else {
      local_2cc = EC_POINT_new(group);
      if (local_2cc == (EC_POINT *)0x0) {
        pEVar4 = (EVP_PKEY *)0x0;
        ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",0xa05);
        local_2c0 = (EC_KEY *)0x0;
        goto LAB_0809b556;
      }
      if (local_2d0 != (EVP_PKEY *)0x0) {
        local_2c0 = (EC_KEY *)BN_CTX_new();
        if (local_2c0 == (EC_KEY *)0x0) {
          iVar15 = 0xa39;
          iVar5 = 0x41;
        }
        else {
          if (local_2d0 == (EVP_PKEY *)(*(byte *)s + 1)) {
            iVar5 = EC_POINT_oct2point(group,local_2cc,(byte *)((int)s + 1),(uint)*(byte *)s,
                                       (BN_CTX *)local_2c0);
            if (iVar5 != 0) {
              local_2d0 = (EVP_PKEY *)0x1;
              pEVar4 = (EVP_PKEY *)0x0;
              s = *(ushort **)(param_1[0xf] + 4);
              goto LAB_0809b28d;
            }
            iVar15 = 0xa4a;
          }
          else {
            iVar15 = 0xa43;
          }
          iVar5 = 0x10;
        }
        pEVar4 = (EVP_PKEY *)0x0;
        ERR_put_error(0x14,0x8b,iVar5,"s3_srvr.c",iVar15);
        goto LAB_0809b556;
      }
      if ((uVar12 & 0x80) == 0) {
        pEVar4 = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
        if ((pEVar4 != (EVP_PKEY *)0x0) && (pEVar4->type == 0x198)) {
          src = EC_KEY_get0_public_key((EC_KEY *)(pEVar4->pkey).rsa);
          iVar5 = EC_POINT_copy(local_2cc,src);
          if (iVar5 == 0) {
            ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa2c);
            local_2c0 = (EC_KEY *)0x0;
          }
          else {
            local_2d0 = (EVP_PKEY *)0x2;
            local_2c0 = (EC_KEY *)0x0;
LAB_0809b28d:
            iVar5 = EC_GROUP_get_degree(group);
            if (iVar5 < 1) {
              iVar5 = 0xa58;
            }
            else {
              sVar8 = ECDH_compute_key(s,iVar5 + 7 >> 3,local_2cc,key,(KDF *)0x0);
              if (0 < (int)sVar8) {
                EVP_PKEY_free(pEVar4);
                EC_POINT_free(local_2cc);
                EC_KEY_free(key);
                BN_CTX_free((BN_CTX *)local_2c0);
                EC_KEY_free(*(EC_KEY **)(param_1[0x16] + 0x34c));
                *(undefined4 *)(param_1[0x16] + 0x34c) = 0;
                iVar5 = param_1[0x30];
                uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar5 + 0x14,s,sVar8);
                *(undefined4 *)(iVar5 + 0x10) = uVar6;
                OPENSSL_cleanse(s,sVar8);
                goto LAB_0809ac89;
              }
              iVar5 = 0xa5f;
            }
            ERR_put_error(0x14,0x8b,0x2b,"s3_srvr.c",iVar5);
          }
          goto LAB_0809b556;
        }
        ERR_put_error(0x14,0x8b,0x139,"s3_srvr.c",0xa24);
        local_2d0 = pEVar4;
      }
      else {
        ERR_put_error(0x14,0x8b,0x137,"s3_srvr.c",0xa10);
      }
      ssl3_send_alert(param_1,2,0x28);
      EVP_PKEY_free(local_2d0);
      EC_POINT_free(local_2cc);
      local_2c0 = (EC_KEY *)0x0;
    }
    EC_KEY_free(key);
  }
  else {
    iVar15 = param_1[0x26];
    if (*(int *)(iVar5 + 0x370) == 0) {
      piVar1 = *(int **)(iVar15 + 0x34);
      if (((piVar1 != (int *)0x0) && (*piVar1 == 6)) && (rsa = (RSA *)piVar1[5], rsa != (RSA *)0x0))
      {
LAB_0809abe7:
        pEVar4 = local_2d0;
        if (0x300 < *param_1) {
          pEVar4 = (EVP_PKEY *)(uint)(ushort)(*s << 8 | *s >> 8);
          if (local_2d0 == (EVP_PKEY *)((int)&pEVar4->type + 2U)) {
            s = s + 1;
          }
          else {
            pEVar4 = local_2d0;
            if ((*(byte *)((int)param_1 + 0x101) & 1) == 0) {
              ERR_put_error(0x14,0x8b,0xea,"s3_srvr.c",0x894);
              goto LAB_0809ae51;
            }
          }
        }
        iVar5 = RSA_private_decrypt((int)pEVar4,(uchar *)s,(uchar *)s,rsa,1);
        if (iVar5 == 0x30) {
          if ((((uint)*(byte *)s != param_1[0x44] >> 8) ||
              (*(byte *)((int)s + 1) != (byte)param_1[0x44])) &&
             (((*(byte *)((int)param_1 + 0x102) & 0x80) == 0 ||
              (((uint)*(byte *)s != *param_1 >> 8 || (*(byte *)((int)s + 1) != (byte)*param_1))))))
          goto LAB_0809ac2b;
        }
        else {
LAB_0809ac2b:
          ERR_clear_error();
          *(byte *)s = (byte)((uint)param_1[0x44] >> 8);
          *(byte *)((int)s + 1) = (byte)param_1[0x44];
          iVar5 = RAND_pseudo_bytes((uchar *)(s + 1),0x2e);
          if (iVar5 < 1) goto LAB_0809ae51;
        }
        iVar5 = param_1[0x30];
        uVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,iVar5 + 0x14,s,0x30);
        *(undefined4 *)(iVar5 + 0x10) = uVar6;
        OPENSSL_cleanse(s,0x30);
        local_2d0 = (EVP_PKEY *)0x1;
        goto LAB_0809ac89;
      }
      iVar15 = 0x886;
      iVar5 = 0xa8;
    }
    else {
      if ((iVar15 != 0) && (rsa = *(RSA **)(iVar15 + 0x18), rsa != (RSA *)0x0)) goto LAB_0809abe7;
      iVar15 = 0x879;
      iVar5 = 0xad;
    }
LAB_0809adb1:
    uVar6 = 0x28;
    ERR_put_error(0x14,0x8b,iVar5,"s3_srvr.c",iVar15);
LAB_0809ae3e:
    ssl3_send_alert(param_1,2,uVar6);
LAB_0809ae51:
    EVP_PKEY_free((EVP_PKEY *)0x0);
    EC_POINT_free((EC_POINT *)0x0);
    local_2c0 = (EC_KEY *)0x0;
  }
  BN_CTX_free((BN_CTX *)local_2c0);
  local_2d0 = (EVP_PKEY *)0xffffffff;
LAB_0809ac89:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_2d0;
}

