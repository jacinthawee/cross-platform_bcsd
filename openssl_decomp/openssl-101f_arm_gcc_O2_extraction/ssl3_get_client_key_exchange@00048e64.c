
void ssl3_get_client_key_exchange(uint *param_1)

{
  byte bVar1;
  uchar uVar2;
  int iVar3;
  undefined4 uVar4;
  BIGNUM *pBVar5;
  size_t sVar6;
  EVP_PKEY_CTX *ctx;
  EVP_PKEY *pEVar7;
  EC_KEY *key;
  EC_GROUP *group;
  EVP_PKEY *p;
  EC_POINT *src;
  char *pcVar8;
  uint uVar9;
  int *piVar10;
  RSA *rsa;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  DH *dh;
  EC_KEY *key_00;
  byte *s;
  code *pcVar14;
  EVP_PKEY *local_2c8;
  EVP_PKEY *local_2c4;
  int local_2bc;
  size_t local_2b8;
  undefined auStack_2b4 [132];
  uchar local_230 [516];
  int local_2c;
  
  local_2c = __TMC_END__;
  local_2c4 = (EVP_PKEY *)
              (**(code **)(param_1[2] + 0x30))(param_1,0x2190,0x2191,0x10,0x800,&local_2bc);
  if (local_2bc == 0) goto LAB_00048f5e;
  uVar9 = param_1[0x16];
  s = (byte *)param_1[0x10];
  uVar12 = *(uint *)(*(int *)(uVar9 + 0x344) + 0xc);
  if ((int)(uVar12 << 0x1f) < 0) {
    if (*(int *)(uVar9 + 0x370) == 0) {
      piVar10 = *(int **)(param_1[0x26] + 0x34);
      if (((piVar10 == (int *)0x0) || (*piVar10 != 6)) ||
         (rsa = (RSA *)piVar10[5], rsa == (RSA *)0x0)) {
        uVar4 = 0x28;
        ERR_put_error(0x14,0x8b,0xa8,"s3_srvr.c",0x886);
LAB_00049078:
        pEVar7 = (EVP_PKEY *)0x0;
        ssl3_send_alert(param_1,2,uVar4);
        EVP_PKEY_free((EVP_PKEY *)0x0);
        EC_POINT_free((EC_POINT *)0x0);
        goto LAB_00049090;
      }
    }
    else if ((param_1[0x26] == 0) || (rsa = *(RSA **)(param_1[0x26] + 0x18), rsa == (RSA *)0x0)) {
      uVar4 = 0x28;
      ERR_put_error(0x14,0x8b,0xad,"s3_srvr.c",0x879);
      goto LAB_00049078;
    }
    if (0x300 < (int)*param_1) {
      bVar1 = *s;
      pbVar11 = s + 1;
      if ((EVP_PKEY *)((int)&((EVP_PKEY *)(uint)CONCAT11(bVar1,*pbVar11))->type + 2) == local_2c4) {
        s = s + 2;
        local_2c4 = (EVP_PKEY *)(uint)CONCAT11(bVar1,*pbVar11);
      }
      else if (-1 < (int)(param_1[0x40] << 0x17)) {
        ERR_put_error(0x14,0x8b,0xea,"s3_srvr.c",0x894);
        goto LAB_00049224;
      }
    }
    iVar3 = RSA_private_decrypt((int)local_2c4,s,s,rsa,1);
    if (iVar3 == 0x30) {
      if ((((uint)*s != (int)param_1[0x44] >> 8) || ((uint)s[1] != (param_1[0x44] & 0xff))) &&
         ((-1 < (int)(param_1[0x40] << 8) ||
          (((uint)*s != (int)*param_1 >> 8 || ((uint)s[1] != (*param_1 & 0xff)))))))
      goto LAB_00048f16;
    }
    else {
LAB_00048f16:
      ERR_clear_error();
      *s = (byte)(param_1[0x44] >> 8);
      s[1] = (byte)param_1[0x44];
      iVar3 = RAND_pseudo_bytes(s + 2,0x2e);
      if (iVar3 < 1) goto LAB_00049224;
    }
    uVar9 = param_1[0x30];
    uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,uVar9 + 0x14,s,0x30);
    *(undefined4 *)(uVar9 + 0x10) = uVar4;
    OPENSSL_cleanse(s,0x30);
    local_2c4 = (EVP_PKEY *)0x1;
  }
  else {
    if ((uVar12 & 0xe) == 0) {
      if ((uVar12 & 0xe0) == 0) {
        if ((uVar12 & 0x100) == 0) {
          if ((int)(uVar12 << 0x15) < 0) {
            if ((int)(CONCAT11(*s,s[1]) + 2) <= (int)local_2c4) {
              pBVar5 = BN_bin2bn(s + 2,(uint)CONCAT11(*s,s[1]),(BIGNUM *)0x0);
              param_1[0x6e] = (uint)pBVar5;
              if (pBVar5 == (BIGNUM *)0x0) {
                ERR_put_error(0x14,0x8b,3,"s3_srvr.c",0xae1);
              }
              else {
                uVar9 = param_1[0x30];
                if (*(void **)(uVar9 + 0xf0) != (void *)0x0) {
                  CRYPTO_free(*(void **)(uVar9 + 0xf0));
                  uVar9 = param_1[0x30];
                }
                pcVar8 = BUF_strdup((char *)param_1[0x69]);
                uVar12 = param_1[0x30];
                *(char **)(uVar9 + 0xf0) = pcVar8;
                if (*(int *)(uVar12 + 0xf0) == 0) {
                  iVar3 = 0xaea;
                  goto LAB_00049798;
                }
                iVar3 = SRP_generate_server_master_secret(param_1,uVar12 + 0x14);
                *(int *)(uVar12 + 0x10) = iVar3;
                if (-1 < iVar3) {
                  local_2c4 = (EVP_PKEY *)0x1;
                  goto LAB_00048f5e;
                }
                ERR_put_error(0x14,0x8b,0x44,"s3_srvr.c",0xaf0);
              }
              goto LAB_00049224;
            }
            uVar4 = 0x32;
            ERR_put_error(0x14,0x8b,0x15b,"s3_srvr.c",0xadc);
          }
          else {
            if ((int)(uVar12 << 0x16) < 0) {
              uVar9 = *(uint *)(*(int *)(uVar9 + 0x344) + 0x10);
              local_2b8 = 0x20;
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
              EVP_PKEY_decrypt_init(ctx);
              pEVar7 = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
              if ((pEVar7 != (EVP_PKEY *)0x0) &&
                 (iVar3 = EVP_PKEY_derive_set_peer(ctx,pEVar7), iVar3 < 1)) {
                ERR_clear_error();
              }
              if (*s == 0x30) {
                sVar6 = (size_t)s[1];
                if (sVar6 == 0x81) {
                  pbVar11 = s + 3;
                  sVar6 = (size_t)s[2];
                }
                else {
                  if ((int)(sVar6 << 0x18) < 0) {
                    iVar3 = 0xb26;
                    goto LAB_000493f4;
                  }
                  pbVar11 = s + 2;
                }
                iVar3 = EVP_PKEY_decrypt(ctx,local_230,&local_2b8,pbVar11,sVar6);
                if (0 < iVar3) {
                  uVar9 = param_1[0x30];
                  uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                    (param_1,uVar9 + 0x14,local_230,0x20);
                  *(undefined4 *)(uVar9 + 0x10) = uVar4;
                  iVar3 = EVP_PKEY_CTX_ctrl(ctx,-1,-1,2,2,(void *)0x0);
                  if (iVar3 < 1) {
                    local_2c4 = (EVP_PKEY *)0x1;
                  }
                  else {
                    local_2c4 = (EVP_PKEY *)0x2;
                  }
                  EVP_PKEY_free(pEVar7);
                  EVP_PKEY_CTX_free(ctx);
                  goto LAB_00048f5e;
                }
                iVar3 = 0xb2c;
              }
              else {
                iVar3 = 0xb17;
              }
LAB_000493f4:
              ERR_put_error(0x14,0x8b,0x93,"s3_srvr.c",iVar3);
              EVP_PKEY_free(pEVar7);
              EVP_PKEY_CTX_free(ctx);
              goto LAB_00049224;
            }
            uVar4 = 0x28;
            ERR_put_error(0x14,0x8b,0xf9,"s3_srvr.c",0xb44);
          }
        }
        else {
          uVar9 = (uint)CONCAT11(*s,s[1]);
          if ((EVP_PKEY *)(uVar9 + 2) == local_2c4) {
            if (uVar9 < 0x81) {
              pcVar14 = (code *)param_1[0x38];
              if (pcVar14 == (code *)0x0) {
                uVar4 = 0x28;
                ERR_put_error(0x14,0x8b,0xe1,"s3_srvr.c",0xa8e);
              }
              else {
                __memcpy_chk(auStack_2b4,s + 2,uVar9,0x81);
                memset(auStack_2b4 + uVar9,0,0x81 - uVar9);
                uVar9 = (*pcVar14)(param_1,auStack_2b4,local_230,0x204);
                OPENSSL_cleanse(auStack_2b4,0x81);
                if (uVar9 < 0x101) {
                  if (uVar9 == 0) {
                    uVar4 = 0x73;
                    ERR_put_error(0x14,0x8b,0xdf,"s3_srvr.c",0xaa4);
                  }
                  else {
                    memmove(local_230 + uVar9 + 4,local_230,uVar9);
                    uVar2 = (uchar)(uVar9 >> 8);
                    local_230[0] = uVar2;
                    local_230[1] = (uchar)uVar9;
                    __memset_chk(local_230 + 2,0,uVar9,0x202);
                    uVar12 = param_1[0x30];
                    (local_230 + 2)[uVar9] = uVar2;
                    local_230[uVar9 + 3] = (uchar)uVar9;
                    if (*(void **)(uVar12 + 0x90) != (void *)0x0) {
                      CRYPTO_free(*(void **)(uVar12 + 0x90));
                      uVar12 = param_1[0x30];
                    }
                    pcVar8 = BUF_strdup((char *)(s + 2));
                    uVar13 = param_1[0x30];
                    *(char **)(uVar12 + 0x90) = pcVar8;
                    if (*(int *)(uVar13 + 0x90) == 0) {
                      iVar3 = 0xab8;
                    }
                    else {
                      if (*(void **)(uVar13 + 0x8c) != (void *)0x0) {
                        CRYPTO_free(*(void **)(uVar13 + 0x8c));
                        uVar13 = param_1[0x30];
                      }
                      pcVar8 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
                      iVar3 = *(int *)(param_1[0x39] + 0x14c);
                      *(char **)(uVar13 + 0x8c) = pcVar8;
                      uVar12 = param_1[0x30];
                      if ((iVar3 == 0) || (*(int *)(uVar12 + 0x8c) != 0)) {
                        uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                          (param_1,uVar12 + 0x14,local_230,uVar9 * 2 + 4);
                        *(undefined4 *)(uVar12 + 0x10) = uVar4;
                        OPENSSL_cleanse(local_230,0x204);
                        local_2c4 = (EVP_PKEY *)0x1;
                        goto LAB_00048f5e;
                      }
                      iVar3 = 0xac3;
                    }
                    uVar4 = 0x28;
                    ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",iVar3);
                  }
                }
                else {
                  uVar4 = 0x28;
                  ERR_put_error(0x14,0x8b,0x44,"s3_srvr.c",0xa9d);
                }
              }
            }
            else {
              uVar4 = 0x28;
              ERR_put_error(0x14,0x8b,0x92,"s3_srvr.c",0xa88);
            }
          }
          else {
            ERR_put_error(0x14,0x8b,0x9f,"s3_srvr.c",0xa82);
            uVar4 = 0x28;
          }
          OPENSSL_cleanse(local_230,0x204);
        }
        goto LAB_00049078;
      }
      key = EC_KEY_new();
      iVar3 = 0x9e4;
      if (key == (EC_KEY *)0x0) {
LAB_00049798:
        ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",iVar3);
        goto LAB_00049224;
      }
      if ((uVar12 & 0x60) == 0) {
        key_00 = *(EC_KEY **)(param_1[0x16] + 0x34c);
      }
      else {
        key_00 = *(EC_KEY **)(*(int *)(param_1[0x26] + 0x70) + 0x14);
      }
      group = EC_KEY_get0_group(key_00);
      pBVar5 = EC_KEY_get0_private_key(key_00);
      iVar3 = EC_KEY_set_group(key,group);
      if ((iVar3 == 0) || (iVar3 = EC_KEY_set_private_key(key,pBVar5), iVar3 == 0)) {
        pEVar7 = (EVP_PKEY *)0x0;
        ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0x9fd);
        p = (EVP_PKEY *)0x0;
        local_2c8 = (EVP_PKEY *)0x0;
      }
      else {
        p = (EVP_PKEY *)EC_POINT_new(group);
        if (p == (EVP_PKEY *)0x0) {
          ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",0xa05);
          local_2c8 = p;
          pEVar7 = p;
        }
        else if (local_2c4 == (EVP_PKEY *)0x0) {
          if ((int)(uVar12 << 0x18) < 0) {
            ERR_put_error(0x14,0x8b,0x137,"s3_srvr.c",0xa10);
            local_2c8 = local_2c4;
          }
          else {
            local_2c8 = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
            if ((local_2c8 != (EVP_PKEY *)0x0) && (local_2c8->type == 0x198)) {
              src = EC_KEY_get0_public_key((EC_KEY *)(local_2c8->pkey).rsa);
              iVar3 = EC_POINT_copy((EC_POINT *)p,src);
              pEVar7 = local_2c4;
              if (iVar3 == 0) {
                ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa2c);
              }
              else {
                local_2c4 = (EVP_PKEY *)0x2;
LAB_00049356:
                iVar3 = EC_GROUP_get_degree(group);
                if (iVar3 < 1) {
                  iVar3 = 0xa58;
                }
                else {
                  sVar6 = ECDH_compute_key(s,iVar3 + 7 >> 3,(EC_POINT *)p,key,(KDF *)0x0);
                  if (0 < (int)sVar6) {
                    EVP_PKEY_free(local_2c8);
                    EC_POINT_free((EC_POINT *)p);
                    EC_KEY_free(key);
                    BN_CTX_free((BN_CTX *)pEVar7);
                    EC_KEY_free(*(EC_KEY **)(param_1[0x16] + 0x34c));
                    uVar9 = param_1[0x30];
                    iVar3 = *(int *)(param_1[2] + 100);
                    *(undefined4 *)(param_1[0x16] + 0x34c) = 0;
                    uVar4 = (**(code **)(iVar3 + 0xc))(param_1,uVar9 + 0x14,s,sVar6);
                    *(undefined4 *)(uVar9 + 0x10) = uVar4;
                    OPENSSL_cleanse(s,sVar6);
                    goto LAB_00048f5e;
                  }
                  iVar3 = 0xa5f;
                }
                ERR_put_error(0x14,0x8b,0x2b,"s3_srvr.c",iVar3);
              }
              goto LAB_00049584;
            }
            ERR_put_error(0x14,0x8b,0x139,"s3_srvr.c",0xa24);
          }
          ssl3_send_alert(param_1,2,0x28);
          pEVar7 = (EVP_PKEY *)0x0;
        }
        else {
          pEVar7 = (EVP_PKEY *)BN_CTX_new();
          if (pEVar7 == (EVP_PKEY *)0x0) {
            ERR_put_error(0x14,0x8b,0x41,"s3_srvr.c",0xa39);
            local_2c8 = pEVar7;
          }
          else if ((EVP_PKEY *)(*s + 1) == local_2c4) {
            local_2c8 = (EVP_PKEY *)
                        EC_POINT_oct2point(group,(EC_POINT *)p,s + 1,(uint)*s,(BN_CTX *)pEVar7);
            if (local_2c8 != (EVP_PKEY *)0x0) {
              local_2c4 = (EVP_PKEY *)0x1;
              local_2c8 = (EVP_PKEY *)0x0;
              s = *(byte **)(param_1[0xf] + 4);
              goto LAB_00049356;
            }
            ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa4a);
          }
          else {
            ERR_put_error(0x14,0x8b,0x10,"s3_srvr.c",0xa43);
            local_2c8 = (EVP_PKEY *)0x0;
          }
        }
      }
LAB_00049584:
      EVP_PKEY_free(local_2c8);
      EC_POINT_free((EC_POINT *)p);
      EC_KEY_free(key);
    }
    else {
      pEVar7 = (EVP_PKEY *)(uint)CONCAT11(*s,s[1]);
      if ((EVP_PKEY *)((int)&pEVar7->type + 2) == local_2c4) {
        s = s + 2;
      }
      else {
        if (-1 < (int)(param_1[0x40] << 0x18)) {
          ERR_put_error(0x14,0x8b,0x94,"s3_srvr.c",0x8de);
          goto LAB_00049224;
        }
        pEVar7 = local_2c4;
        if (local_2c4 == (EVP_PKEY *)0x0) {
          uVar4 = 0x28;
          ERR_put_error(0x14,0x8b,0xec,"s3_srvr.c",0x8eb);
          goto LAB_00049078;
        }
      }
      dh = *(DH **)(uVar9 + 0x348);
      if (dh == (DH *)0x0) {
        uVar4 = 0x28;
        ERR_put_error(0x14,0x8b,0xab,"s3_srvr.c",0x8f3);
        goto LAB_00049078;
      }
      pBVar5 = BN_bin2bn(s,(int)pEVar7,(BIGNUM *)0x0);
      if (pBVar5 == (BIGNUM *)0x0) {
        ERR_put_error(0x14,0x8b,0x82,"s3_srvr.c",0x8fd);
      }
      else {
        sVar6 = DH_compute_key(s,pBVar5,dh);
        if (0 < (int)sVar6) {
          DH_free(*(DH **)(param_1[0x16] + 0x348));
          *(undefined4 *)(param_1[0x16] + 0x348) = 0;
          BN_clear_free(pBVar5);
          uVar9 = param_1[0x30];
          uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))(param_1,uVar9 + 0x14,s,sVar6);
          *(undefined4 *)(uVar9 + 0x10) = uVar4;
          OPENSSL_cleanse(s,sVar6);
          local_2c4 = (EVP_PKEY *)0x1;
          goto LAB_00048f5e;
        }
        ERR_put_error(0x14,0x8b,5,"s3_srvr.c",0x905);
        BN_clear_free(pBVar5);
      }
LAB_00049224:
      pEVar7 = (EVP_PKEY *)0x0;
      EVP_PKEY_free((EVP_PKEY *)0x0);
      EC_POINT_free((EC_POINT *)0x0);
    }
LAB_00049090:
    BN_CTX_free((BN_CTX *)pEVar7);
    local_2c4 = (EVP_PKEY *)0xffffffff;
  }
LAB_00048f5e:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_2c4);
}

