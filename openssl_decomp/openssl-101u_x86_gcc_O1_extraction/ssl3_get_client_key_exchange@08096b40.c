
uint ssl3_get_client_key_exchange(int *param_1)

{
  byte bVar1;
  int *piVar2;
  DH *dh;
  code *pcVar3;
  undefined uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 uVar8;
  BIGNUM *pBVar9;
  size_t sVar10;
  EVP_PKEY_CTX *ctx;
  EVP_PKEY *pEVar11;
  EC_KEY *key;
  EC_GROUP *group;
  EC_POINT *p;
  EC_POINT *src;
  char *pcVar12;
  ushort uVar13;
  uint uVar14;
  ushort *puVar15;
  EC_KEY *key_00;
  RSA *rsa;
  BN_CTX *ctx_00;
  undefined4 *puVar16;
  int in_GS_OFFSET;
  byte bVar17;
  int iVar18;
  uint local_2dc;
  undefined4 *local_2d4;
  EVP_PKEY *local_2d0;
  int local_2c0;
  ushort *local_2bc;
  size_t local_2b8;
  int local_2b4;
  int local_2b0;
  size_t local_2ac;
  undefined4 local_2a5;
  undefined auStack_2a1 [121];
  undefined4 uStack_228;
  undefined local_224 [516];
  int local_20;
  
  bVar17 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2dc = (**(code **)(param_1[2] + 0x30))(param_1,0x2190,0x2191,0x10,0x800,&local_2c0);
  if (local_2c0 == 0) goto LAB_08096d72;
  iVar5 = param_1[0x16];
  local_2bc = (ushort *)param_1[0x10];
  uVar14 = *(uint *)(*(int *)(iVar5 + 0x344) + 0xc);
  if ((uVar14 & 1) == 0) {
    if ((uVar14 & 0xe) != 0) {
      puVar15 = local_2bc + 1;
      local_2d0 = (EVP_PKEY *)(uint)(ushort)(*local_2bc << 8 | *local_2bc >> 8);
      if (local_2dc != (int)local_2d0 + 2U) {
        if ((*(byte *)(param_1 + 0x40) & 0x80) == 0) {
          local_2bc = puVar15;
          ERR_put_error(0x14,0x8b,0x94,"s3_srvr.c",0x938);
          goto LAB_08096f67;
        }
        puVar15 = local_2bc;
        local_2d0 = (EVP_PKEY *)local_2dc;
        if (local_2dc == 0) {
          iVar18 = 0x943;
          iVar5 = 0xec;
          goto LAB_08096eb1;
        }
      }
      dh = *(DH **)(iVar5 + 0x348);
      local_2bc = puVar15;
      if (dh == (DH *)0x0) {
        iVar18 = 0x949;
        iVar5 = 0xab;
        goto LAB_08096eb1;
      }
      pBVar9 = BN_bin2bn((uchar *)puVar15,(int)local_2d0,(BIGNUM *)0x0);
      if (pBVar9 == (BIGNUM *)0x0) {
        ERR_put_error(0x14,0x8b,0x82,"s3_srvr.c",0x951);
      }
      else {
        sVar10 = DH_compute_key((uchar *)local_2bc,pBVar9,dh);
        if (0 < (int)sVar10) {
          DH_free(*(DH **)(param_1[0x16] + 0x348));
          *(undefined4 *)(param_1[0x16] + 0x348) = 0;
          BN_clear_free(pBVar9);
          iVar5 = param_1[0x30];
          uVar8 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar5 + 0x14,local_2bc,sVar10);
          *(undefined4 *)(iVar5 + 0x10) = uVar8;
          OPENSSL_cleanse(local_2bc,sVar10);
          local_2dc = 1;
          goto LAB_08096d72;
        }
        ERR_put_error(0x14,0x8b,5,"s3_srvr.c",0x958);
        BN_clear_free(pBVar9);
      }
      goto LAB_08096f67;
    }
    if ((uVar14 & 0xe0) == 0) {
      if ((uVar14 & 0x100) == 0) {
        if ((uVar14 & 0x400) != 0) {
          puVar15 = local_2bc + 1;
          uVar14 = (uint)(ushort)(*local_2bc << 8 | *local_2bc >> 8);
          if ((int)(uVar14 + 2) <= (int)local_2dc) {
            local_2bc = puVar15;
            pBVar9 = BN_bin2bn((uchar *)puVar15,uVar14,(BIGNUM *)0x0);
            param_1[0x6e] = (int)pBVar9;
            if (pBVar9 == (BIGNUM *)0x0) {
              ERR_put_error(0x14,0x8b,3,"s3_srvr.c",0xb12);
            }
            else {
              iVar5 = BN_ucmp(pBVar9,(BIGNUM *)param_1[0x6a]);
              if ((-1 < iVar5) || (*(int *)(param_1[0x6e] + 4) == 0)) {
                uVar8 = 0x2f;
                ERR_put_error(0x14,0x8b,0x173,"s3_srvr.c",0xb19);
                goto LAB_08096f54;
              }
              iVar5 = param_1[0x30];
              if (*(void **)(iVar5 + 0xf0) != (void *)0x0) {
                CRYPTO_free(*(void **)(iVar5 + 0xf0));
                iVar5 = param_1[0x30];
              }
              pcVar12 = BUF_strdup((char *)param_1[0x69]);
              *(char **)(iVar5 + 0xf0) = pcVar12;
              iVar5 = param_1[0x30];
              if (*(int *)(iVar5 + 0xf0) == 0) {
                iVar5 = 0xb20;
                goto LAB_08097a8e;
              }
              iVar18 = SRP_generate_server_master_secret(param_1,iVar5 + 0x14);
              *(int *)(iVar5 + 0x10) = iVar18;
              if (-1 < iVar18) {
                local_2dc = 1;
                goto LAB_08096d72;
              }
              ERR_put_error(0x14,0x8b,0x44,"s3_srvr.c",0xb27);
            }
            goto LAB_08096f67;
          }
          iVar18 = 0xb0e;
          iVar5 = 0x15b;
          goto LAB_08097974;
        }
        if ((uVar14 & 0x200) == 0) {
          iVar18 = 0xb7b;
          iVar5 = 0xf9;
          goto LAB_08096eb1;
        }
        uVar14 = *(uint *)(*(int *)(iVar5 + 0x344) + 0x10);
        local_2b8 = 0x20;
        if ((uVar14 & 0x100) == 0) {
          pEVar11 = (EVP_PKEY *)0x0;
          if ((uVar14 & 0x200) != 0) {
            pEVar11 = *(EVP_PKEY **)(param_1[0x26] + 0x88);
          }
        }
        else {
          pEVar11 = *(EVP_PKEY **)(param_1[0x26] + 0x7c);
        }
        ctx = EVP_PKEY_CTX_new(pEVar11,(ENGINE *)0x0);
        if (ctx != (EVP_PKEY_CTX *)0x0) {
          iVar5 = EVP_PKEY_decrypt_init(ctx);
          if (iVar5 < 1) {
            pEVar11 = (EVP_PKEY *)0x0;
            ERR_put_error(0x14,0x8b,0x44,"s3_srvr.c",0xb46);
          }
          else {
            pEVar11 = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
            if ((pEVar11 != (EVP_PKEY *)0x0) &&
               (iVar5 = EVP_PKEY_derive_set_peer(ctx,pEVar11), iVar5 < 1)) {
              ERR_clear_error();
            }
            iVar5 = ASN1_get_object((uchar **)&local_2bc,(long *)&local_2ac,&local_2b4,&local_2b0,
                                    local_2dc);
            if (((iVar5 == 0x20) && (local_2b4 == 0x10)) && (local_2b0 == 0)) {
              iVar5 = EVP_PKEY_decrypt(ctx,(uchar *)(&uStack_228 + 1),&local_2b8,(uchar *)local_2bc,
                                       local_2ac);
              if (0 < iVar5) {
                iVar5 = param_1[0x30];
                uVar8 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar5 + 0x14,&uStack_228 + 1,0x20);
                *(undefined4 *)(iVar5 + 0x10) = uVar8;
                OPENSSL_cleanse(&uStack_228 + 1,0x20);
                iVar5 = EVP_PKEY_CTX_ctrl(ctx,-1,-1,2,2,(void *)0x0);
                local_2dc = (0 < iVar5) + 1;
                EVP_PKEY_free(pEVar11);
                EVP_PKEY_CTX_free(ctx);
                goto LAB_08096d72;
              }
              iVar5 = 0xb62;
            }
            else {
              iVar5 = 0xb5a;
            }
            ERR_put_error(0x14,0x8b,0x93,"s3_srvr.c",iVar5);
          }
          EVP_PKEY_free(pEVar11);
          EVP_PKEY_CTX_free(ctx);
          goto LAB_08096f67;
        }
        uVar8 = 0x50;
        ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",0xb42);
        goto LAB_08096f54;
      }
      uVar13 = *local_2bc;
      local_2bc = local_2bc + 1;
      uVar13 = uVar13 << 8 | uVar13 >> 8;
      uVar14 = (uint)uVar13;
      if (local_2dc == uVar14 + 2) {
        if (0x80 < uVar13) {
          iVar18 = 0xabe;
          iVar5 = 0x92;
          goto LAB_08096f1e;
        }
        pcVar3 = (code *)param_1[0x38];
        if (pcVar3 == (code *)0x0) {
          iVar18 = 0xac3;
          iVar5 = 0xe1;
          goto LAB_08096f1e;
        }
        __memcpy_chk(&local_2a5,local_2bc,uVar14,0x81);
        uVar6 = -uVar14 + 0x81;
        puVar16 = (undefined4 *)((int)&local_2a5 + uVar14);
        if (uVar6 < 4) {
          if ((uVar6 != 0) && (*(undefined *)puVar16 = 0, (uVar6 & 2) != 0)) {
            *(undefined2 *)(-uVar14 + 0x7f + (int)puVar16) = 0;
          }
        }
        else {
          *puVar16 = 0;
          *(undefined4 *)((int)&uStack_228 + uVar6 + uVar14 + -0x81) = 0;
          uVar6 = (uint)((int)puVar16 +
                        (uVar6 - (int)(undefined4 *)((uint)(auStack_2a1 + uVar14) & 0xfffffffc))) >>
                  2;
          puVar16 = (undefined4 *)((uint)(auStack_2a1 + uVar14) & 0xfffffffc);
          for (; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar16 = 0;
            puVar16 = puVar16 + (uint)bVar17 * -2 + 1;
          }
        }
        puVar16 = &uStack_228 + 1;
        uVar6 = (*pcVar3)(param_1,&local_2a5,puVar16,0x204);
        OPENSSL_cleanse(&local_2a5,0x81);
        if (uVar6 < 0x101) {
          if (uVar6 != 0) {
            memmove((void *)((int)&uStack_228 + uVar6 + 8),puVar16,uVar6);
            uVar4 = (undefined)(uVar6 >> 8);
            local_224[0] = uVar4;
            local_224[1] = (char)uVar6;
            __memset_chk((int)&uStack_228 + 6,0,uVar6,0x202);
            *(undefined *)((int)&uStack_228 + 6 + uVar6) = uVar4;
            *(char *)((int)&uStack_228 + uVar6 + 7) = (char)uVar6;
            iVar5 = param_1[0x30];
            if (*(void **)(iVar5 + 0x90) != (void *)0x0) {
              CRYPTO_free(*(void **)(iVar5 + 0x90));
              iVar5 = param_1[0x30];
            }
            pcVar12 = BUF_strndup((char *)local_2bc,uVar14);
            *(char **)(iVar5 + 0x90) = pcVar12;
            iVar5 = param_1[0x30];
            if (*(int *)(iVar5 + 0x90) == 0) {
              iVar18 = 0xaeb;
            }
            else {
              if (*(void **)(iVar5 + 0x8c) != (void *)0x0) {
                CRYPTO_free(*(void **)(iVar5 + 0x8c));
                iVar5 = param_1[0x30];
              }
              pcVar12 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
              *(char **)(iVar5 + 0x8c) = pcVar12;
              iVar5 = param_1[0x30];
              if ((*(int *)(param_1[0x39] + 0x14c) == 0) || (*(int *)(iVar5 + 0x8c) != 0)) {
                uVar8 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar5 + 0x14,puVar16,uVar6 * 2 + 4);
                *(undefined4 *)(iVar5 + 0x10) = uVar8;
                OPENSSL_cleanse(puVar16,0x204);
                local_2dc = 1;
                goto LAB_08096d72;
              }
              iVar18 = 0xaf4;
            }
            iVar5 = 0x41;
            goto LAB_08097782;
          }
          uVar8 = 0x73;
          ERR_put_error(0x14,0x8b,0xdf,"s3_srvr.c",0xad9);
        }
        else {
          iVar18 = 0xad2;
          iVar5 = 0x44;
LAB_08097782:
          uVar8 = 0x28;
          ERR_put_error(0x14,0x8b,iVar5,"s3_srvr.c",iVar18);
        }
      }
      else {
        iVar18 = 0xab9;
        iVar5 = 0x9f;
LAB_08096f1e:
        uVar8 = 0x28;
        ERR_put_error(0x14,0x8b,iVar5,"s3_srvr.c",iVar18);
      }
      local_2d4 = &uStack_228 + 1;
      OPENSSL_cleanse(local_2d4,0x204);
      goto LAB_08096f54;
    }
    key = EC_KEY_new();
    if (key == (EC_KEY *)0x0) {
      iVar5 = 0xa32;
LAB_08097a8e:
      ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",iVar5);
      goto LAB_08096f67;
    }
    if ((uVar14 & 0x60) == 0) {
      key_00 = *(EC_KEY **)(param_1[0x16] + 0x34c);
    }
    else {
      key_00 = *(EC_KEY **)(*(int *)(param_1[0x26] + 0x70) + 0x14);
    }
    group = EC_KEY_get0_group(key_00);
    pBVar9 = EC_KEY_get0_private_key(key_00);
    iVar5 = EC_KEY_set_group(key,group);
    if ((iVar5 == 0) || (iVar5 = EC_KEY_set_private_key(key,pBVar9), iVar5 == 0)) {
      ctx_00 = (BN_CTX *)0x0;
      p = (EC_POINT *)0x0;
      ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa47);
      local_2d0 = (EVP_PKEY *)0x0;
LAB_080975dd:
      EVP_PKEY_free(local_2d0);
      EC_POINT_free(p);
    }
    else {
      p = EC_POINT_new(group);
      if (p == (EC_POINT *)0x0) {
        ctx_00 = (BN_CTX *)0x0;
        ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",0xa4d);
        local_2d0 = (EVP_PKEY *)0x0;
        goto LAB_080975dd;
      }
      if (local_2dc != 0) {
        ctx_00 = BN_CTX_new();
        if (ctx_00 == (BN_CTX *)0x0) {
          iVar18 = 0xa78;
          iVar5 = 0x41;
        }
        else {
          bVar17 = *(byte *)local_2bc;
          local_2bc = (ushort *)((int)local_2bc + 1);
          if (local_2dc == bVar17 + 1) {
            iVar5 = EC_POINT_oct2point(group,p,(uchar *)local_2bc,(uint)bVar17,ctx_00);
            if (iVar5 != 0) {
              local_2dc = 1;
              local_2d0 = (EVP_PKEY *)0x0;
              local_2bc = *(ushort **)(param_1[0xf] + 4);
              goto LAB_08097382;
            }
            iVar18 = 0xa84;
          }
          else {
            iVar18 = 0xa80;
          }
          iVar5 = 0x10;
        }
        ERR_put_error(0x14,0x8b,iVar5,"s3_srvr.c",iVar18);
        local_2d0 = (EVP_PKEY *)0x0;
        goto LAB_080975dd;
      }
      if ((uVar14 & 0x80) == 0) {
        local_2d0 = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
        if ((local_2d0 != (EVP_PKEY *)0x0) && (local_2d0->type == 0x198)) {
          src = EC_KEY_get0_public_key((EC_KEY *)(local_2d0->pkey).rsa);
          iVar5 = EC_POINT_copy(p,src);
          if (iVar5 == 0) {
            ctx_00 = (BN_CTX *)0x0;
            ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa6d);
          }
          else {
            local_2dc = 2;
            ctx_00 = (BN_CTX *)0x0;
LAB_08097382:
            iVar5 = EC_GROUP_get_degree(group);
            if (iVar5 < 1) {
              iVar5 = 0xa91;
            }
            else {
              sVar10 = ECDH_compute_key(local_2bc,iVar5 + 7 >> 3,p,key,(KDF *)0x0);
              if (0 < (int)sVar10) {
                EVP_PKEY_free(local_2d0);
                EC_POINT_free(p);
                EC_KEY_free(key);
                BN_CTX_free(ctx_00);
                EC_KEY_free(*(EC_KEY **)(param_1[0x16] + 0x34c));
                iVar5 = param_1[0x30];
                *(undefined4 *)(param_1[0x16] + 0x34c) = 0;
                uVar8 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar5 + 0x14,local_2bc,sVar10);
                *(undefined4 *)(iVar5 + 0x10) = uVar8;
                OPENSSL_cleanse(local_2bc,sVar10);
                goto LAB_08096d72;
              }
              iVar5 = 0xa97;
            }
            ERR_put_error(0x14,0x8b,0x2b,"s3_srvr.c",iVar5);
          }
          goto LAB_080975dd;
        }
        ERR_put_error(0x14,0x8b,0x139,"s3_srvr.c",0xa66);
      }
      else {
        ERR_put_error(0x14,0x8b,0x137,"s3_srvr.c",0xa57);
        local_2d0 = (EVP_PKEY *)0x0;
      }
      ctx_00 = (BN_CTX *)0x0;
      ssl3_send_alert(param_1,2,0x28);
      EVP_PKEY_free(local_2d0);
      EC_POINT_free(p);
    }
    EC_KEY_free(key);
  }
  else {
    iVar18 = param_1[0x26];
    if (*(int *)(iVar5 + 0x370) == 0) {
      piVar2 = *(int **)(iVar18 + 0x34);
      if (((piVar2 == (int *)0x0) || (*piVar2 != 6)) || (rsa = (RSA *)piVar2[5], rsa == (RSA *)0x0))
      {
        iVar18 = 0x8bf;
        iVar5 = 0xa8;
        goto LAB_08096eb1;
      }
LAB_08096be4:
      local_2d0 = (EVP_PKEY *)local_2dc;
      puVar15 = local_2bc;
      if (0x300 < *param_1) {
        local_2d0 = (EVP_PKEY *)(uint)(ushort)(*local_2bc << 8 | *local_2bc >> 8);
        puVar15 = local_2bc + 1;
        if ((local_2dc != (int)local_2d0 + 2U) &&
           (local_2d0 = (EVP_PKEY *)local_2dc, puVar15 = local_2bc,
           (*(byte *)((int)param_1 + 0x101) & 1) == 0)) {
          iVar18 = 0x8cc;
          iVar5 = 0xea;
LAB_08097974:
          local_2bc = local_2bc + 1;
          uVar8 = 0x32;
          ERR_put_error(0x14,0x8b,iVar5,"s3_srvr.c",iVar18);
          goto LAB_08096f54;
        }
      }
      local_2bc = puVar15;
      if (0x2f < (int)local_2d0) {
        iVar5 = RAND_bytes((uchar *)(&uStack_228 + 1),0x30);
        if (0 < iVar5) {
          uVar6 = RSA_private_decrypt((int)local_2d0,(uchar *)local_2bc,(uchar *)local_2bc,rsa,1);
          ERR_clear_error();
          uVar14 = param_1[0x44];
          bVar17 = (byte)((uVar14 & 0xff ^ (uint)*(byte *)((int)local_2bc + 1)) - 1 >> 0x18) &
                   (byte)(((int)uVar14 >> 8 ^ (uint)*(byte *)local_2bc) - 1 >> 0x18) &
                   ~(byte)((int)uVar14 >> 0x1f);
          if ((*(byte *)((int)param_1 + 0x102) & 0x80) != 0) {
            bVar17 = bVar17 | (byte)((*(byte *)param_1 ^ *(byte *)((int)local_2bc + 1)) - 1 >> 0x18)
                              & (byte)(((uint)*(byte *)local_2bc ^ *param_1 >> 8) - 1 >> 0x18) &
                                ~(byte)(*param_1 >> 0x1f);
          }
          iVar5 = 0;
          do {
            bVar1 = *(byte *)((int)(&uStack_228 + 1) + iVar5);
            pbVar7 = (byte *)((int)local_2bc + iVar5);
            iVar5 = iVar5 + 1;
            *pbVar7 = bVar1 ^ (bVar1 ^ *pbVar7) &
                              (char)(bVar17 & ~(byte)(uVar6 >> 0x18) &
                                              (byte)((uVar6 ^ 0x30) - 1 >> 0x18)) >> 7;
          } while (iVar5 != 0x30);
          iVar5 = param_1[0x30];
          uVar8 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar5 + 0x14,local_2bc,0x30);
          *(undefined4 *)(iVar5 + 0x10) = uVar8;
          OPENSSL_cleanse(local_2bc,0x30);
          local_2dc = 1;
          goto LAB_08096d72;
        }
        goto LAB_08096f67;
      }
      uVar8 = 0x33;
      ERR_put_error(0x14,0x8b,0xea,"s3_srvr.c",0x8de);
    }
    else {
      if ((iVar18 != 0) && (rsa = *(RSA **)(iVar18 + 0x18), rsa != (RSA *)0x0)) goto LAB_08096be4;
      iVar18 = 0x8b5;
      iVar5 = 0xad;
LAB_08096eb1:
      uVar8 = 0x28;
      ERR_put_error(0x14,0x8b,iVar5,"s3_srvr.c",iVar18);
    }
LAB_08096f54:
    ssl3_send_alert(param_1,2,uVar8);
LAB_08096f67:
    EVP_PKEY_free((EVP_PKEY *)0x0);
    ctx_00 = (BN_CTX *)0x0;
    EC_POINT_free((EC_POINT *)0x0);
  }
  BN_CTX_free(ctx_00);
  param_1[0xd] = 5;
  local_2dc = 0xffffffff;
LAB_08096d72:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_2dc;
}

