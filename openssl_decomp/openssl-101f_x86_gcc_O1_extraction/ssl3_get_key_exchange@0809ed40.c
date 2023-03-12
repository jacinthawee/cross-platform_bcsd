
int ssl3_get_key_exchange(int *param_1)

{
  ushort *d;
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  BIGNUM *pBVar7;
  EVP_MD *type;
  EC_GROUP *pEVar8;
  RSA *r;
  uint uVar9;
  ushort *puVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  int in_GS_OFFSET;
  byte bVar13;
  int iVar14;
  BN_CTX *local_ec;
  EC_POINT *local_e8;
  DH *local_e4;
  size_t local_e0;
  uint local_dc;
  EVP_PKEY *local_d4;
  int *local_d0;
  uint local_c4;
  int local_c0;
  EVP_MD_CTX local_bc;
  undefined4 local_a1;
  undefined auStack_9d [121];
  undefined4 uStack_24;
  int local_20;
  
  bVar13 = 0;
  local_d0 = param_1;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = (**(code **)(param_1[2] + 0x30))(param_1,0x1140,0x1141,0xffffffff,param_1[0x42],&local_c0)
  ;
  if (local_c0 == 0) goto LAB_0809edbc;
  iVar14 = param_1[0x16];
  if (*(int *)(iVar14 + 0x340) != 0xc) {
    if ((*(byte *)(*(int *)(iVar14 + 0x344) + 0xd) & 1) != 0) {
      iVar2 = param_1[0x30];
      uVar6 = ssl_sess_cert_new();
      *(undefined4 *)(iVar2 + 0x98) = uVar6;
      iVar2 = param_1[0x39];
      if (*(void **)(iVar2 + 0x14c) != (void *)0x0) {
        CRYPTO_free(*(void **)(iVar2 + 0x14c));
        iVar2 = param_1[0x39];
      }
      *(undefined4 *)(iVar2 + 0x14c) = 0;
      iVar14 = param_1[0x16];
    }
    *(undefined4 *)(iVar14 + 0x354) = 1;
    iVar2 = 1;
    goto LAB_0809edbc;
  }
  d = (ushort *)param_1[0x10];
  iVar14 = param_1[0x30];
  iVar3 = *(int *)(iVar14 + 0x98);
  if (iVar3 == 0) {
    uVar6 = ssl_sess_cert_new();
    *(undefined4 *)(iVar14 + 0x98) = uVar6;
  }
  else {
    if (*(RSA **)(iVar3 + 0x6c) != (RSA *)0x0) {
      RSA_free(*(RSA **)(iVar3 + 0x6c));
      iVar3 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar3 + 0x6c) = 0;
    }
    if (*(DH **)(iVar3 + 0x70) != (DH *)0x0) {
      DH_free(*(DH **)(iVar3 + 0x70));
      iVar3 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar3 + 0x70) = 0;
    }
    if (*(EC_KEY **)(iVar3 + 0x74) != (EC_KEY *)0x0) {
      EC_KEY_free(*(EC_KEY **)(iVar3 + 0x74));
      *(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x74) = 0;
    }
  }
  uVar9 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  uVar4 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x10);
  EVP_MD_CTX_init(&local_bc);
  if ((uVar9 & 0x100) == 0) {
    if ((uVar9 & 0x400) != 0) {
      uVar9 = (uint)(ushort)(*d << 8 | *d >> 8);
      local_c4 = uVar9;
      if ((int)(uVar9 + 2) <= iVar2) {
        pBVar7 = BN_bin2bn((uchar *)(d + 1),uVar9,(BIGNUM *)0x0);
        param_1[0x6a] = (int)pBVar7;
        if (pBVar7 == (BIGNUM *)0x0) {
          iVar14 = 0x57f;
          iVar2 = 3;
        }
        else {
          puVar10 = (ushort *)((int)(d + 1) + local_c4);
          uVar1 = *puVar10;
          puVar10 = puVar10 + 1;
          local_c4 = (uint)(ushort)(uVar1 << 8 | uVar1 >> 8);
          iVar14 = uVar9 + 4 + local_c4;
          if (iVar2 < iVar14) {
            iVar14 = 0x589;
            iVar2 = 0x15d;
            goto LAB_0809fb39;
          }
          pBVar7 = BN_bin2bn((uchar *)puVar10,local_c4,(BIGNUM *)0x0);
          param_1[0x6b] = (int)pBVar7;
          if (pBVar7 == (BIGNUM *)0x0) {
            iVar14 = 0x58e;
            iVar2 = 3;
          }
          else {
            pbVar11 = (byte *)((int)puVar10 + local_c4);
            local_c4 = (uint)*pbVar11;
            pbVar11 = pbVar11 + 1;
            iVar14 = iVar14 + 1 + local_c4;
            if (iVar2 < iVar14) {
              iVar14 = 0x599;
              iVar2 = 0x15f;
              goto LAB_0809fb39;
            }
            pBVar7 = BN_bin2bn(pbVar11,local_c4,(BIGNUM *)0x0);
            param_1[0x6c] = (int)pBVar7;
            if (pBVar7 == (BIGNUM *)0x0) {
              iVar14 = 0x59e;
              iVar2 = 3;
            }
            else {
              puVar10 = (ushort *)(pbVar11 + local_c4);
              local_c4 = (uint)(ushort)(*puVar10 << 8 | *puVar10 >> 8);
              local_e0 = iVar14 + 2 + local_c4;
              if (iVar2 < (int)local_e0) {
                iVar14 = 0x5a8;
                iVar2 = 0x15c;
                goto LAB_0809fb39;
              }
              pBVar7 = BN_bin2bn((uchar *)(puVar10 + 1),local_c4,(BIGNUM *)0x0);
              param_1[0x6d] = (int)pBVar7;
              if (pBVar7 != (BIGNUM *)0x0) {
                puVar10 = (ushort *)((int)(puVar10 + 1) + local_c4);
                iVar2 = iVar2 - local_e0;
                if ((uVar4 & 1) == 0) {
                  if ((uVar4 & 2) == 0) goto LAB_0809f3a8;
                  local_d4 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x24));
                }
                else {
                  local_d4 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
                }
                goto LAB_0809f168;
              }
              iVar14 = 0x5ad;
              iVar2 = 3;
            }
          }
        }
LAB_0809ff24:
        r = (RSA *)0x0;
        ERR_put_error(0x14,0x8d,iVar2,"s3_clnt.c",iVar14);
        local_e8 = (EC_POINT *)0x0;
        local_e4 = (DH *)0x0;
        local_d4 = (EVP_PKEY *)0x0;
        goto LAB_0809fee1;
      }
      iVar14 = 0x57a;
      iVar2 = 0x15e;
LAB_0809fb39:
      r = (RSA *)0x0;
      ERR_put_error(0x14,0x8d,iVar2,"s3_clnt.c",iVar14);
      local_e8 = (EC_POINT *)0x0;
      local_ec = (BN_CTX *)0x0;
      local_e4 = (DH *)0x0;
      local_d4 = (EVP_PKEY *)0x0;
      uVar6 = 0x32;
      goto LAB_0809f2e8;
    }
    if ((uVar9 & 1) == 0) {
      if ((uVar9 & 8) == 0) {
        if ((uVar9 & 6) == 0) {
          if ((uVar9 & 0x80) == 0) {
            if (uVar9 == 0) {
LAB_0809f3a8:
              if ((uVar4 & 4) != 0) goto LAB_0809f3b5;
              iVar14 = 0x71e;
              iVar2 = 0x44;
              goto LAB_0809ff24;
            }
            r = (RSA *)0x0;
            ERR_put_error(0x14,0x8d,0xf4,"s3_clnt.c",0x6ae);
            local_e8 = (EC_POINT *)0x0;
            local_ec = (BN_CTX *)0x0;
            local_e4 = (DH *)0x0;
            local_d4 = (EVP_PKEY *)0x0;
            uVar6 = 10;
          }
          else {
            r = (RSA *)EC_KEY_new();
            if (r == (RSA *)0x0) {
              iVar14 = 0x64e;
              iVar2 = 0x41;
              goto LAB_0809feb4;
            }
            if (((2 < iVar2) && (*(char *)d == '\x03')) &&
               (iVar14 = tls1_ec_curve_id2nid(*(char *)(d + 1)), iVar14 != 0)) {
              pEVar8 = EC_GROUP_new_by_curve_name(iVar14);
              if (pEVar8 == (EC_GROUP *)0x0) {
                iVar14 = 0x668;
              }
              else {
                iVar14 = EC_KEY_set_group((EC_KEY *)r,pEVar8);
                if (iVar14 != 0) {
                  EC_GROUP_free(pEVar8);
                  pEVar8 = EC_KEY_get0_group((EC_KEY *)r);
                  if (((*(byte *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) == 0) ||
                     (iVar14 = EC_GROUP_get_degree(pEVar8), iVar14 < 0xa4)) {
                    local_e8 = EC_POINT_new(pEVar8);
                    if ((local_e8 == (EC_POINT *)0x0) ||
                       (local_ec = BN_CTX_new(), local_ec == (BN_CTX *)0x0)) {
                      ERR_put_error(0x14,0x8d,0x41,"s3_clnt.c",0x682);
                      local_e4 = (DH *)0x0;
                      local_d4 = (EVP_PKEY *)0x0;
                      goto LAB_0809fee1;
                    }
                    uVar9 = (uint)*(byte *)((int)d + 3);
                    local_e0 = uVar9 + 4;
                    if (((int)local_e0 <= iVar2) &&
                       (iVar14 = EC_POINT_oct2point(pEVar8,local_e8,(uchar *)(d + 2),uVar9,local_ec)
                       , iVar14 != 0)) {
                      iVar2 = iVar2 - local_e0;
                      puVar10 = (ushort *)(uVar9 + (int)(d + 2));
                      if ((uVar4 & 1) == 0) {
                        local_d4 = (EVP_PKEY *)0x0;
                        if ((uVar4 & 0x40) != 0) {
                          local_d4 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) +
                                                               0x48));
                        }
                      }
                      else {
                        local_d4 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc))
                        ;
                      }
                      EC_KEY_set_public_key((EC_KEY *)r,local_e8);
                      *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x74) = r;
                      BN_CTX_free(local_ec);
                      EC_POINT_free(local_e8);
                      goto LAB_0809f168;
                    }
                    ERR_put_error(0x14,0x8d,0x132,"s3_clnt.c",0x68e);
                    local_e4 = (DH *)0x0;
                    local_d4 = (EVP_PKEY *)0x0;
                    uVar6 = 0x32;
                  }
                  else {
                    ERR_put_error(0x14,0x8d,0x136,"s3_clnt.c",0x678);
                    local_e8 = (EC_POINT *)0x0;
                    local_ec = (BN_CTX *)0x0;
                    local_e4 = (DH *)0x0;
                    local_d4 = (EVP_PKEY *)0x0;
                    uVar6 = 0x3c;
                  }
                  goto LAB_0809f2e8;
                }
                iVar14 = 0x66d;
              }
              iVar2 = 0x10;
              goto LAB_0809feb4;
            }
            ERR_put_error(0x14,0x8d,0x13a,"s3_clnt.c",0x661);
            local_e8 = (EC_POINT *)0x0;
            local_ec = (BN_CTX *)0x0;
            local_e4 = (DH *)0x0;
            local_d4 = (EVP_PKEY *)0x0;
            uVar6 = 0x50;
          }
        }
        else {
          r = (RSA *)0x0;
          ERR_put_error(0x14,0x8d,0xeb,"s3_clnt.c",0x641);
          local_e8 = (EC_POINT *)0x0;
          local_ec = (BN_CTX *)0x0;
          local_e4 = (DH *)0x0;
          local_d4 = (EVP_PKEY *)0x0;
          uVar6 = 0x2f;
        }
        goto LAB_0809f2e8;
      }
      local_e4 = DH_new();
      if (local_e4 == (DH *)0x0) {
        iVar14 = 0x5fd;
        iVar2 = 5;
      }
      else {
        uVar9 = (uint)(ushort)(*d << 8 | *d >> 8);
        local_c4 = uVar9;
        if (iVar2 < (int)(uVar9 + 2)) {
          iVar14 = 0x605;
          iVar2 = 0x6e;
LAB_0809fde1:
          r = (RSA *)0x0;
          ERR_put_error(0x14,0x8d,iVar2,"s3_clnt.c",iVar14);
          local_e8 = (EC_POINT *)0x0;
          local_ec = (BN_CTX *)0x0;
          local_d4 = (EVP_PKEY *)0x0;
          uVar6 = 0x32;
          goto LAB_0809f2e8;
        }
        pBVar7 = BN_bin2bn((uchar *)(d + 1),uVar9,(BIGNUM *)0x0);
        local_e4->p = pBVar7;
        if (pBVar7 == (BIGNUM *)0x0) {
          iVar14 = 0x60a;
        }
        else {
          puVar10 = (ushort *)((int)(d + 1) + local_c4);
          uVar1 = *puVar10;
          puVar10 = puVar10 + 1;
          local_c4 = (uint)(ushort)(uVar1 << 8 | uVar1 >> 8);
          iVar14 = uVar9 + 4 + local_c4;
          if (iVar2 < iVar14) {
            iVar14 = 0x614;
            iVar2 = 0x6c;
            goto LAB_0809fde1;
          }
          pBVar7 = BN_bin2bn((uchar *)puVar10,local_c4,(BIGNUM *)0x0);
          local_e4->g = pBVar7;
          if (pBVar7 == (BIGNUM *)0x0) {
            iVar14 = 0x619;
          }
          else {
            puVar10 = (ushort *)((int)puVar10 + local_c4);
            uVar1 = *puVar10;
            puVar10 = puVar10 + 1;
            local_c4 = (uint)(ushort)(uVar1 << 8 | uVar1 >> 8);
            local_e0 = iVar14 + 2 + local_c4;
            if (iVar2 < (int)local_e0) {
              iVar14 = 0x623;
              iVar2 = 0x6d;
              goto LAB_0809fde1;
            }
            pBVar7 = BN_bin2bn((uchar *)puVar10,local_c4,(BIGNUM *)0x0);
            local_e4->pub_key = pBVar7;
            if (pBVar7 != (BIGNUM *)0x0) {
              puVar10 = (ushort *)((int)puVar10 + local_c4);
              iVar2 = iVar2 - local_e0;
              if ((uVar4 & 1) == 0) {
                local_d4 = (EVP_PKEY *)0x0;
                if ((uVar4 & 2) != 0) {
                  local_d4 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x24));
                }
              }
              else {
                local_d4 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
              }
              *(DH **)(*(int *)(param_1[0x30] + 0x98) + 0x70) = local_e4;
              goto LAB_0809f168;
            }
            iVar14 = 0x628;
          }
        }
        iVar2 = 3;
      }
      r = (RSA *)0x0;
      ERR_put_error(0x14,0x8d,iVar2,"s3_clnt.c",iVar14);
      local_e8 = (EC_POINT *)0x0;
      local_d4 = (EVP_PKEY *)0x0;
LAB_0809fee1:
      EVP_PKEY_free(local_d4);
      local_ec = (BN_CTX *)0x0;
      goto LAB_0809f308;
    }
    r = RSA_new();
    if (r == (RSA *)0x0) {
      iVar14 = 0x5c7;
      iVar2 = 0x41;
LAB_0809feb4:
      ERR_put_error(0x14,0x8d,iVar2,"s3_clnt.c",iVar14);
      local_e8 = (EC_POINT *)0x0;
      local_e4 = (DH *)0x0;
      local_d4 = (EVP_PKEY *)0x0;
      goto LAB_0809fee1;
    }
    uVar9 = (uint)(ushort)(*d << 8 | *d >> 8);
    local_c4 = uVar9;
    if (iVar2 < (int)(uVar9 + 2)) {
      ERR_put_error(0x14,0x8d,0x79,"s3_clnt.c",0x5cf);
LAB_0809fcdf:
      ssl3_send_alert(param_1,2,0x32);
      EVP_PKEY_free((EVP_PKEY *)0x0);
    }
    else {
      pBVar7 = BN_bin2bn((uchar *)(d + 1),uVar9,r->n);
      r->n = pBVar7;
      if (pBVar7 == (BIGNUM *)0x0) {
        iVar2 = 0x5d4;
LAB_080a0122:
        ERR_put_error(0x14,0x8d,3,"s3_clnt.c",iVar2);
      }
      else {
        puVar10 = (ushort *)((int)(d + 1) + local_c4);
        uVar1 = *puVar10;
        puVar10 = puVar10 + 1;
        local_c4 = (uint)(ushort)(uVar1 << 8 | uVar1 >> 8);
        local_e0 = uVar9 + 4 + local_c4;
        if (iVar2 < (int)local_e0) {
          ERR_put_error(0x14,0x8d,0x78,"s3_clnt.c",0x5de);
          goto LAB_0809fcdf;
        }
        pBVar7 = BN_bin2bn((uchar *)puVar10,local_c4,r->e);
        r->e = pBVar7;
        if (pBVar7 == (BIGNUM *)0x0) {
          iVar2 = 0x5e3;
          goto LAB_080a0122;
        }
        puVar10 = (ushort *)((int)puVar10 + local_c4);
        iVar2 = iVar2 - local_e0;
        if ((uVar4 & 1) != 0) {
          local_d4 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
          *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x6c) = r;
LAB_0809f168:
          if (local_d4 == (EVP_PKEY *)0x0) goto LAB_0809f3a8;
          if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
            uVar9 = tls12_get_sigid(local_d4);
            if (uVar9 == 0xffffffff) {
              r = (RSA *)0x0;
              ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x6bf);
              local_e8 = (EC_POINT *)0x0;
              local_e4 = (DH *)0x0;
              goto LAB_0809fee1;
            }
            if (uVar9 == *(byte *)((int)puVar10 + 1)) {
              r = (RSA *)tls12_get_hash(*(byte *)puVar10);
              if (r == (RSA *)0x0) {
                ERR_put_error(0x14,0x8d,0x170,"s3_clnt.c",0x6cc);
                local_e8 = (EC_POINT *)0x0;
                local_ec = (BN_CTX *)0x0;
                local_e4 = (DH *)0x0;
                uVar6 = 0x32;
                goto LAB_0809f2e8;
              }
              puVar10 = puVar10 + 1;
              iVar2 = iVar2 + -2;
              goto LAB_0809f194;
            }
            iVar14 = 0x6c5;
            iVar2 = 0x172;
          }
          else {
            r = (RSA *)EVP_sha1();
LAB_0809f194:
            uVar9 = iVar2 - 2;
            local_c4 = (uint)(ushort)(*puVar10 << 8 | *puVar10 >> 8);
            iVar2 = EVP_PKEY_size(local_d4);
            if ((local_c4 == uVar9 && (int)uVar9 <= iVar2) && (0 < (int)uVar9)) {
              if ((local_d4->type == 6) && ((*param_1 >> 8 != 3 || (*param_1 < 0x303)))) {
                local_dc = 0;
                iVar2 = 2;
                puVar12 = &local_a1;
                do {
                  EVP_MD_CTX_set_flags(&local_bc,8);
                  if (iVar2 == 2) {
                    type = *(EVP_MD **)(param_1[0x39] + 0x8c);
                  }
                  else {
                    type = *(EVP_MD **)(param_1[0x39] + 0x90);
                  }
                  EVP_DigestInit_ex(&local_bc,type,(ENGINE *)0x0);
                  EVP_DigestUpdate(&local_bc,(void *)(param_1[0x16] + 0xc0),0x20);
                  EVP_DigestUpdate(&local_bc,(void *)(param_1[0x16] + 0xa0),0x20);
                  EVP_DigestUpdate(&local_bc,d,local_e0);
                  EVP_DigestFinal_ex(&local_bc,(uchar *)puVar12,&local_c4);
                  local_dc = local_dc + local_c4;
                  puVar12 = (undefined4 *)((int)puVar12 + local_c4);
                  iVar2 = iVar2 + -1;
                } while (iVar2 != 0);
                local_c4 = RSA_verify(0x72,(uchar *)&local_a1,local_dc,(uchar *)(puVar10 + 1),uVar9,
                                      (local_d4->pkey).rsa);
                if ((int)local_c4 < 0) {
                  iVar2 = 0x6fe;
                  iVar14 = 0x76;
LAB_0809f2b1:
                  ERR_put_error(0x14,0x8d,iVar14,"s3_clnt.c",iVar2);
                  local_e8 = (EC_POINT *)0x0;
                  local_ec = (BN_CTX *)0x0;
                  local_e4 = (DH *)0x0;
                  uVar6 = 0x33;
                  r = (RSA *)0x0;
                  goto LAB_0809f2e8;
                }
                if (local_c4 == 0) {
                  iVar2 = 0x705;
                  goto LAB_0809f2aa;
                }
              }
              else {
                EVP_DigestInit_ex(&local_bc,(EVP_MD *)r,(ENGINE *)0x0);
                EVP_DigestUpdate(&local_bc,(void *)(param_1[0x16] + 0xc0),0x20);
                EVP_DigestUpdate(&local_bc,(void *)(param_1[0x16] + 0xa0),0x20);
                EVP_DigestUpdate(&local_bc,d,local_e0);
                iVar2 = EVP_VerifyFinal(&local_bc,(uchar *)(puVar10 + 1),uVar9,local_d4);
                if (iVar2 < 1) {
                  iVar2 = 0x714;
LAB_0809f2aa:
                  iVar14 = 0x7b;
                  goto LAB_0809f2b1;
                }
              }
LAB_0809f3d0:
              EVP_PKEY_free(local_d4);
              EVP_MD_CTX_cleanup(&local_bc);
              iVar2 = 1;
              goto LAB_0809edbc;
            }
            iVar14 = 0x6e1;
            iVar2 = 0x108;
          }
          r = (RSA *)0x0;
          ERR_put_error(0x14,0x8d,iVar2,"s3_clnt.c",iVar14);
          local_e8 = (EC_POINT *)0x0;
          local_ec = (BN_CTX *)0x0;
          local_e4 = (DH *)0x0;
          uVar6 = 0x32;
          goto LAB_0809f2e8;
        }
        ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x5ee);
      }
      EVP_PKEY_free((EVP_PKEY *)0x0);
    }
    RSA_free(r);
    BN_CTX_free((BN_CTX *)0x0);
    EC_POINT_free((EC_POINT *)0x0);
  }
  else {
    uVar1 = *d << 8 | *d >> 8;
    uVar9 = (uint)uVar1;
    local_d4 = (EVP_PKEY *)(uVar9 + 2);
    local_c4 = uVar9;
    if (uVar1 < 0x81) {
      if ((int)local_d4 <= iVar2) {
        __memcpy_chk(&local_a1,d + 1,uVar9,0x81);
        puVar12 = (undefined4 *)((int)&local_a1 + uVar9);
        uVar4 = 0x81 - uVar9;
        if (uVar4 < 4) {
          if ((uVar4 != 0) && (*(undefined *)puVar12 = 0, (uVar4 & 2) != 0)) {
            *(undefined2 *)((int)&uStack_24 + uVar4 + uVar9 + -0x7f) = 0;
          }
        }
        else {
          *puVar12 = 0;
          *(undefined4 *)((int)&uStack_24 + uVar4 + uVar9 + -0x81) = 0;
          uVar9 = (uint)((int)puVar12 +
                        (uVar4 - (int)(undefined4 *)((uint)(auStack_9d + uVar9) & 0xfffffffc))) >> 2
          ;
          puVar12 = (undefined4 *)((uint)(auStack_9d + uVar9) & 0xfffffffc);
          for (; uVar9 != 0; uVar9 = uVar9 - 1) {
            *puVar12 = 0;
            puVar12 = puVar12 + (uint)bVar13 * -2 + 1;
          }
        }
        iVar14 = local_d0[0x39];
        if (*(void **)(iVar14 + 0x14c) != (void *)0x0) {
          CRYPTO_free(*(void **)(iVar14 + 0x14c));
          iVar14 = local_d0[0x39];
        }
        pcVar5 = BUF_strdup((char *)&local_a1);
        *(char **)(iVar14 + 0x14c) = pcVar5;
        if (*(int *)(local_d0[0x39] + 0x14c) != 0) {
          iVar2 = iVar2 - (int)local_d4;
LAB_0809f3b5:
          if (iVar2 != 0) {
            iVar14 = 0x725;
            iVar2 = 0x99;
            goto LAB_0809fb39;
          }
          local_d4 = (EVP_PKEY *)0x0;
          goto LAB_0809f3d0;
        }
        iVar14 = 0x569;
        iVar2 = 0x41;
        goto LAB_0809fbfe;
      }
      ERR_put_error(0x14,0x8d,0x13c,"s3_clnt.c",0x55b);
      uVar6 = 0x32;
    }
    else {
      iVar14 = 0x554;
      iVar2 = 0x92;
LAB_0809fbfe:
      ERR_put_error(0x14,0x8d,iVar2,"s3_clnt.c",iVar14);
      uVar6 = 0x28;
    }
    local_e8 = (EC_POINT *)0x0;
    local_ec = (BN_CTX *)0x0;
    r = (RSA *)0x0;
    local_e4 = (DH *)0x0;
    local_d4 = (EVP_PKEY *)0x0;
LAB_0809f2e8:
    ssl3_send_alert(local_d0,2,uVar6);
    EVP_PKEY_free(local_d4);
LAB_0809f308:
    if (local_e4 != (DH *)0x0) {
      DH_free(local_e4);
    }
    BN_CTX_free(local_ec);
    EC_POINT_free(local_e8);
    if (r != (RSA *)0x0) {
      EC_KEY_free((EC_KEY *)r);
    }
  }
  EVP_MD_CTX_cleanup(&local_bc);
  iVar2 = -1;
LAB_0809edbc:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

