
void ssl3_get_client_key_exchange(uint *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  BIGNUM *pBVar5;
  size_t sVar6;
  EVP_PKEY_CTX *ctx;
  EVP_PKEY *pEVar7;
  byte *s;
  EC_KEY *key;
  EC_GROUP *group;
  EVP_PKEY *p;
  EVP_PKEY *pkey;
  EC_POINT *src;
  char *pcVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  EC_KEY *key_00;
  RSA *rsa;
  DH *dh;
  uint uVar12;
  code *pcVar13;
  EVP_PKEY *local_2d4;
  byte *local_2d0 [2];
  int local_2c8;
  size_t local_2c4;
  int local_2c0;
  int local_2bc;
  size_t local_2b8;
  undefined auStack_2b4 [132];
  byte local_230 [516];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_2d4 = (EVP_PKEY *)
              (**(code **)(param_1[2] + 0x30))(param_1,0x2190,0x2191,0x10,0x800,&local_2c8);
  if (local_2c8 == 0) goto LAB_00045b78;
  uVar9 = param_1[0x16];
  local_2d0[0] = (byte *)param_1[0x10];
  uVar12 = *(uint *)(*(int *)(uVar9 + 0x344) + 0xc);
  if ((int)(uVar12 << 0x1f) < 0) {
    if (*(int *)(uVar9 + 0x370) == 0) {
      piVar10 = *(int **)(param_1[0x26] + 0x34);
      if (((piVar10 == (int *)0x0) || (*piVar10 != 6)) ||
         (rsa = (RSA *)piVar10[5], rsa == (RSA *)0x0)) {
        uVar3 = 0x28;
        ERR_put_error(0x14,0x8b,0xa8,"s3_srvr.c",0x8bf);
      }
      else {
LAB_00045a76:
        pEVar7 = local_2d4;
        pbVar4 = local_2d0[0];
        if (0x300 < (int)*param_1) {
          pEVar7 = (EVP_PKEY *)(uint)CONCAT11(*local_2d0[0],local_2d0[0][1]);
          pbVar4 = local_2d0[0] + 2;
          if (((EVP_PKEY *)
               ((int)&((EVP_PKEY *)(uint)CONCAT11(*local_2d0[0],local_2d0[0][1]))->type + 2) !=
               local_2d4) &&
             (pEVar7 = local_2d4, pbVar4 = local_2d0[0], -1 < (int)(param_1[0x40] << 0x17))) {
            uVar3 = 0x32;
            local_2d0[0] = local_2d0[0] + 2;
            ERR_put_error(0x14,0x8b,0xea,"s3_srvr.c",0x8cc);
            goto LAB_00045c9a;
          }
        }
        local_2d0[0] = pbVar4;
        if (0x2f < (int)pEVar7) {
          iVar2 = RAND_bytes(local_230,0x30);
          if (0 < iVar2) {
            uVar9 = RSA_private_decrypt((int)pEVar7,local_2d0[0],local_2d0[0],rsa,1);
            ERR_clear_error();
            uVar12 = param_1[0x44];
            bVar1 = (byte)(((uint)*local_2d0[0] ^ (int)uVar12 >> 8) - 1 >> 0x18) &
                    ~(byte)((int)uVar12 >> 0x1f) &
                    (byte)((uVar12 & 0xff ^ (uint)local_2d0[0][1]) - 1 >> 0x18);
            if ((int)(param_1[0x40] << 8) < 0) {
              uVar12 = *param_1;
              bVar1 = bVar1 | (byte)(((uint)local_2d0[0][1] ^ uVar12 & 0xff) - 1 >> 0x18) &
                              (byte)(((uint)*local_2d0[0] ^ (int)uVar12 >> 8) - 1 >> 0x18) &
                              ~(byte)((int)uVar12 >> 0x1f);
            }
            bVar1 = (char)(bVar1 & (byte)((uVar9 ^ 0x30) - 1 >> 0x18) & ~(byte)(uVar9 >> 0x18)) >> 7
            ;
            iVar2 = 0;
            do {
              local_2d0[0][iVar2] = local_230[iVar2] & ~bVar1 | local_2d0[0][iVar2] & bVar1;
              iVar2 = iVar2 + 1;
            } while (iVar2 != 0x30);
            uVar9 = param_1[0x30];
            uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                              (param_1,uVar9 + 0x14,local_2d0[0],0x30);
            *(undefined4 *)(uVar9 + 0x10) = uVar3;
            OPENSSL_cleanse(local_2d0[0],0x30);
            local_2d4 = (EVP_PKEY *)0x1;
            goto LAB_00045b78;
          }
LAB_00045d58:
          pEVar7 = (EVP_PKEY *)0x0;
          EVP_PKEY_free((EVP_PKEY *)0x0);
          EC_POINT_free((EC_POINT *)0x0);
          goto LAB_00045cb2;
        }
        uVar3 = 0x33;
        ERR_put_error(0x14,0x8b,0xea,"s3_srvr.c",0x8de);
      }
    }
    else {
      if ((param_1[0x26] != 0) && (rsa = *(RSA **)(param_1[0x26] + 0x18), rsa != (RSA *)0x0))
      goto LAB_00045a76;
      uVar3 = 0x28;
      ERR_put_error(0x14,0x8b,0xad,"s3_srvr.c",0x8b5);
    }
LAB_00045c9a:
    pEVar7 = (EVP_PKEY *)0x0;
    ssl3_send_alert(param_1,2,uVar3);
    EVP_PKEY_free((EVP_PKEY *)0x0);
    EC_POINT_free((EC_POINT *)0x0);
  }
  else {
    if ((uVar12 & 0xe) != 0) {
      pbVar4 = local_2d0[0] + 2;
      pEVar7 = (EVP_PKEY *)(uint)CONCAT11(*local_2d0[0],local_2d0[0][1]);
      if ((EVP_PKEY *)((int)&pEVar7->type + 2) != local_2d4) {
        if (-1 < (int)(param_1[0x40] << 0x18)) {
          local_2d0[0] = pbVar4;
          ERR_put_error(0x14,0x8b,0x94,"s3_srvr.c",0x938);
          goto LAB_00045d58;
        }
        pbVar4 = local_2d0[0];
        pEVar7 = local_2d4;
        if (local_2d4 == (EVP_PKEY *)0x0) {
          uVar3 = 0x28;
          ERR_put_error(0x14,0x8b,0xec,"s3_srvr.c",0x943);
          goto LAB_00045c9a;
        }
      }
      dh = *(DH **)(uVar9 + 0x348);
      local_2d0[0] = pbVar4;
      if (dh != (DH *)0x0) {
        pBVar5 = BN_bin2bn(pbVar4,(int)pEVar7,(BIGNUM *)0x0);
        if (pBVar5 == (BIGNUM *)0x0) {
          ERR_put_error(0x14,0x8b,0x82,"s3_srvr.c",0x951);
        }
        else {
          sVar6 = DH_compute_key(local_2d0[0],pBVar5,dh);
          if (0 < (int)sVar6) {
            DH_free(*(DH **)(param_1[0x16] + 0x348));
            *(undefined4 *)(param_1[0x16] + 0x348) = 0;
            BN_clear_free(pBVar5);
            uVar9 = param_1[0x30];
            uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                              (param_1,uVar9 + 0x14,local_2d0[0],sVar6);
            *(undefined4 *)(uVar9 + 0x10) = uVar3;
            OPENSSL_cleanse(local_2d0[0],sVar6);
            local_2d4 = (EVP_PKEY *)0x1;
            goto LAB_00045b78;
          }
          ERR_put_error(0x14,0x8b,5,"s3_srvr.c",0x958);
          BN_clear_free(pBVar5);
        }
        goto LAB_00045d58;
      }
      uVar3 = 0x28;
      ERR_put_error(0x14,0x8b,0xab,"s3_srvr.c",0x949);
      goto LAB_00045c9a;
    }
    if ((uVar12 & 0xe0) == 0) {
      if ((uVar12 & 0x100) == 0) {
        if ((int)(uVar12 << 0x15) < 0) {
          bVar1 = *local_2d0[0];
          s = local_2d0[0] + 2;
          pbVar4 = local_2d0[0] + 1;
          local_2d0[0] = s;
          if ((int)(CONCAT11(bVar1,*pbVar4) + 2) <= (int)local_2d4) {
            pBVar5 = BN_bin2bn(s,(uint)CONCAT11(bVar1,*pbVar4),(BIGNUM *)0x0);
            param_1[0x6e] = (uint)pBVar5;
            if (pBVar5 == (BIGNUM *)0x0) {
              ERR_put_error(0x14,0x8b,3,"s3_srvr.c",0xb12);
            }
            else {
              iVar2 = BN_ucmp(pBVar5,(BIGNUM *)param_1[0x6a]);
              if ((-1 < iVar2) || (*(int *)(param_1[0x6e] + 4) == 0)) {
                uVar3 = 0x2f;
                ERR_put_error(0x14,0x8b,0x173,"s3_srvr.c",0xb19);
                goto LAB_00045c9a;
              }
              uVar9 = param_1[0x30];
              if (*(void **)(uVar9 + 0xf0) != (void *)0x0) {
                CRYPTO_free(*(void **)(uVar9 + 0xf0));
                uVar9 = param_1[0x30];
              }
              pcVar8 = BUF_strdup((char *)param_1[0x69]);
              uVar12 = param_1[0x30];
              *(char **)(uVar9 + 0xf0) = pcVar8;
              if (*(int *)(uVar12 + 0xf0) == 0) {
                iVar2 = 0xb20;
                goto LAB_00046434;
              }
              iVar2 = SRP_generate_server_master_secret(param_1,uVar12 + 0x14);
              *(int *)(uVar12 + 0x10) = iVar2;
              if (-1 < iVar2) {
                local_2d4 = (EVP_PKEY *)0x1;
                goto LAB_00045b78;
              }
              ERR_put_error(0x14,0x8b,0x44,"s3_srvr.c",0xb27);
            }
            goto LAB_00045d58;
          }
          uVar3 = 0x32;
          ERR_put_error(0x14,0x8b,0x15b,"s3_srvr.c",0xb0e);
        }
        else if ((int)(uVar12 << 0x16) < 0) {
          uVar9 = *(uint *)(*(int *)(uVar9 + 0x344) + 0x10);
          local_2c4 = 0x20;
          if ((int)(uVar9 << 0x17) < 0) {
            pEVar7 = *(EVP_PKEY **)(param_1[0x26] + 0x7c);
          }
          else {
            pEVar7 = (EVP_PKEY *)(uVar9 & 0x200);
            if (pEVar7 != (EVP_PKEY *)0x0) {
              pEVar7 = *(EVP_PKEY **)(param_1[0x26] + 0x88);
            }
          }
          ctx = EVP_PKEY_CTX_new(pEVar7,(ENGINE *)0x0);
          if (ctx != (EVP_PKEY_CTX *)0x0) {
            iVar2 = EVP_PKEY_decrypt_init(ctx);
            if (iVar2 < 1) {
              pEVar7 = (EVP_PKEY *)0x0;
              ERR_put_error(0x14,0x8b,0x44,"s3_srvr.c",0xb46);
            }
            else {
              pEVar7 = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
              if ((pEVar7 != (EVP_PKEY *)0x0) &&
                 (iVar2 = EVP_PKEY_derive_set_peer(ctx,pEVar7), iVar2 < 1)) {
                ERR_clear_error();
              }
              iVar2 = ASN1_get_object(local_2d0,(long *)&local_2b8,&local_2c0,&local_2bc,
                                      (long)local_2d4);
              if (((iVar2 == 0x20) && (local_2c0 == 0x10)) && (local_2bc == 0)) {
                iVar2 = EVP_PKEY_decrypt(ctx,local_230,&local_2c4,local_2d0[0],local_2b8);
                if (0 < iVar2) {
                  uVar9 = param_1[0x30];
                  uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                    (param_1,uVar9 + 0x14,local_230,0x20);
                  *(undefined4 *)(uVar9 + 0x10) = uVar3;
                  OPENSSL_cleanse(local_230,0x20);
                  iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,-1,2,2,(void *)0x0);
                  if (iVar2 < 1) {
                    local_2d4 = (EVP_PKEY *)0x1;
                  }
                  else {
                    local_2d4 = (EVP_PKEY *)0x2;
                  }
                  EVP_PKEY_free(pEVar7);
                  EVP_PKEY_CTX_free(ctx);
                  goto LAB_00045b78;
                }
                iVar2 = 0xb62;
              }
              else {
                iVar2 = 0xb5a;
              }
              ERR_put_error(0x14,0x8b,0x93,"s3_srvr.c",iVar2);
            }
            EVP_PKEY_free(pEVar7);
            EVP_PKEY_CTX_free(ctx);
            goto LAB_00045d58;
          }
          uVar3 = 0x50;
          ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",0xb42);
        }
        else {
          uVar3 = 0x28;
          ERR_put_error(0x14,0x8b,0xf9,"s3_srvr.c",0xb7b);
        }
      }
      else {
        pbVar4 = local_2d0[0] + 2;
        uVar9 = (uint)CONCAT11(*local_2d0[0],local_2d0[0][1]);
        local_2d0[0] = pbVar4;
        if ((EVP_PKEY *)(uVar9 + 2) == local_2d4) {
          if (uVar9 < 0x81) {
            pcVar13 = (code *)param_1[0x38];
            if (pcVar13 == (code *)0x0) {
              uVar3 = 0x28;
              ERR_put_error(0x14,0x8b,0xe1,"s3_srvr.c",0xac3);
            }
            else {
              __memcpy_chk(auStack_2b4,pbVar4,uVar9,0x81);
              memset(auStack_2b4 + uVar9,0,0x81 - uVar9);
              uVar12 = (*pcVar13)(param_1,auStack_2b4,local_230,0x204);
              OPENSSL_cleanse(auStack_2b4,0x81);
              if (uVar12 < 0x101) {
                if (uVar12 == 0) {
                  uVar3 = 0x73;
                  ERR_put_error(0x14,0x8b,0xdf,"s3_srvr.c",0xad9);
                }
                else {
                  memmove(local_230 + uVar12 + 4,local_230,uVar12);
                  bVar1 = (byte)(uVar12 >> 8);
                  local_230[0] = bVar1;
                  local_230[1] = (byte)uVar12;
                  __memset_chk(local_230 + 2,0,uVar12,0x202);
                  uVar11 = param_1[0x30];
                  (local_230 + 2)[uVar12] = bVar1;
                  local_230[uVar12 + 3] = (byte)uVar12;
                  if (*(void **)(uVar11 + 0x90) != (void *)0x0) {
                    CRYPTO_free(*(void **)(uVar11 + 0x90));
                    uVar11 = param_1[0x30];
                  }
                  pcVar8 = BUF_strndup((char *)local_2d0[0],uVar9);
                  uVar9 = param_1[0x30];
                  *(char **)(uVar11 + 0x90) = pcVar8;
                  if (*(int *)(uVar9 + 0x90) == 0) {
                    iVar2 = 0xaeb;
                  }
                  else {
                    if (*(void **)(uVar9 + 0x8c) != (void *)0x0) {
                      CRYPTO_free(*(void **)(uVar9 + 0x8c));
                      uVar9 = param_1[0x30];
                    }
                    pcVar8 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
                    iVar2 = *(int *)(param_1[0x39] + 0x14c);
                    *(char **)(uVar9 + 0x8c) = pcVar8;
                    uVar9 = param_1[0x30];
                    if ((iVar2 == 0) || (*(int *)(uVar9 + 0x8c) != 0)) {
                      uVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                        (param_1,uVar9 + 0x14,local_230,uVar12 * 2 + 4);
                      *(undefined4 *)(uVar9 + 0x10) = uVar3;
                      OPENSSL_cleanse(local_230,0x204);
                      local_2d4 = (EVP_PKEY *)0x1;
                      goto LAB_00045b78;
                    }
                    iVar2 = 0xaf4;
                  }
                  uVar3 = 0x28;
                  ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",iVar2);
                }
              }
              else {
                uVar3 = 0x28;
                ERR_put_error(0x14,0x8b,0x44,"s3_srvr.c",0xad2);
              }
            }
          }
          else {
            uVar3 = 0x28;
            ERR_put_error(0x14,0x8b,0x92,"s3_srvr.c",0xabe);
          }
        }
        else {
          ERR_put_error(0x14,0x8b,0x9f,"s3_srvr.c",0xab9);
          uVar3 = 0x28;
        }
        OPENSSL_cleanse(local_230,0x204);
      }
      goto LAB_00045c9a;
    }
    key = EC_KEY_new();
    iVar2 = 0xa32;
    if (key == (EC_KEY *)0x0) {
LAB_00046434:
      ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",iVar2);
      goto LAB_00045d58;
    }
    if ((uVar12 & 0x60) == 0) {
      key_00 = *(EC_KEY **)(param_1[0x16] + 0x34c);
    }
    else {
      key_00 = *(EC_KEY **)(*(int *)(param_1[0x26] + 0x70) + 0x14);
    }
    group = EC_KEY_get0_group(key_00);
    pBVar5 = EC_KEY_get0_private_key(key_00);
    iVar2 = EC_KEY_set_group(key,group);
    if ((iVar2 == 0) || (iVar2 = EC_KEY_set_private_key(key,pBVar5), iVar2 == 0)) {
      pEVar7 = (EVP_PKEY *)0x0;
      ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa47);
      p = (EVP_PKEY *)0x0;
      pkey = (EVP_PKEY *)0x0;
    }
    else {
      p = (EVP_PKEY *)EC_POINT_new(group);
      if (p == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",0xa4d);
        pEVar7 = p;
        pkey = p;
      }
      else if (local_2d4 == (EVP_PKEY *)0x0) {
        if ((int)(uVar12 << 0x18) < 0) {
          ERR_put_error(0x14,0x8b,0x137,"s3_srvr.c",0xa57);
        }
        else {
          pkey = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
          if ((pkey != (EVP_PKEY *)0x0) && (pkey->type == 0x198)) {
            src = EC_KEY_get0_public_key((EC_KEY *)(pkey->pkey).rsa);
            iVar2 = EC_POINT_copy((EC_POINT *)p,src);
            pEVar7 = local_2d4;
            if (iVar2 == 0) {
              ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa6d);
            }
            else {
              local_2d4 = (EVP_PKEY *)0x2;
LAB_00045f18:
              iVar2 = EC_GROUP_get_degree(group);
              if (iVar2 < 1) {
                iVar2 = 0xa91;
              }
              else {
                sVar6 = ECDH_compute_key(local_2d0[0],iVar2 + 7 >> 3,(EC_POINT *)p,key,(KDF *)0x0);
                if (0 < (int)sVar6) {
                  EVP_PKEY_free(pkey);
                  EC_POINT_free((EC_POINT *)p);
                  EC_KEY_free(key);
                  BN_CTX_free((BN_CTX *)pEVar7);
                  EC_KEY_free(*(EC_KEY **)(param_1[0x16] + 0x34c));
                  uVar9 = param_1[0x30];
                  iVar2 = *(int *)(param_1[2] + 100);
                  *(undefined4 *)(param_1[0x16] + 0x34c) = 0;
                  uVar3 = (**(code **)(iVar2 + 0xc))(param_1,uVar9 + 0x14,local_2d0[0],sVar6);
                  *(undefined4 *)(uVar9 + 0x10) = uVar3;
                  OPENSSL_cleanse(local_2d0[0],sVar6);
                  goto LAB_00045b78;
                }
                iVar2 = 0xa97;
              }
              ERR_put_error(0x14,0x8b,0x2b,"s3_srvr.c",iVar2);
            }
            goto LAB_0004616a;
          }
          ERR_put_error(0x14,0x8b,0x139,"s3_srvr.c",0xa66);
          local_2d4 = pkey;
        }
        ssl3_send_alert(param_1,2,0x28);
        pEVar7 = (EVP_PKEY *)0x0;
        pkey = local_2d4;
      }
      else {
        pEVar7 = (EVP_PKEY *)BN_CTX_new();
        if (pEVar7 == (EVP_PKEY *)0x0) {
          ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",0xa78);
          pkey = pEVar7;
        }
        else {
          pbVar4 = local_2d0[0] + 1;
          bVar1 = *local_2d0[0];
          local_2d0[0] = pbVar4;
          if ((EVP_PKEY *)(bVar1 + 1) == local_2d4) {
            pkey = (EVP_PKEY *)
                   EC_POINT_oct2point(group,(EC_POINT *)p,pbVar4,(uint)bVar1,(BN_CTX *)pEVar7);
            if (pkey != (EVP_PKEY *)0x0) {
              pkey = (EVP_PKEY *)0x0;
              local_2d4 = (EVP_PKEY *)0x1;
              local_2d0[0] = *(byte **)(param_1[0xf] + 4);
              goto LAB_00045f18;
            }
            ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa84);
          }
          else {
            ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa80);
            pkey = (EVP_PKEY *)0x0;
          }
        }
      }
    }
LAB_0004616a:
    EVP_PKEY_free(pkey);
    EC_POINT_free((EC_POINT *)p);
    EC_KEY_free(key);
  }
LAB_00045cb2:
  BN_CTX_free((BN_CTX *)pEVar7);
  local_2d4 = (EVP_PKEY *)0xffffffff;
  param_1[0xd] = 5;
LAB_00045b78:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_2d4);
}

