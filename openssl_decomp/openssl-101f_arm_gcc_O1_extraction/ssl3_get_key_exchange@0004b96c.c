
/* WARNING: Type propagation algorithm not settling */

void ssl3_get_key_exchange(int *param_1)

{
  RSA *pRVar1;
  undefined4 uVar2;
  BIGNUM *pBVar3;
  RSA *r;
  EC_GROUP *group;
  EVP_MD *type;
  int iVar4;
  int iVar5;
  void *ptr;
  undefined *puVar6;
  char *pcVar7;
  undefined *puVar8;
  uint uVar9;
  uint uVar10;
  RSA *pRVar11;
  RSA *pRVar12;
  uchar *puVar13;
  uchar *puVar14;
  RSA *local_e0;
  undefined *local_dc;
  RSA *local_d8;
  RSA *local_d4;
  undefined *local_d0;
  int local_cc;
  EVP_MD_CTX EStack_c8;
  uchar auStack_b0 [132];
  int local_2c;
  
  local_2c = __TMC_END__;
  pRVar1 = (RSA *)(**(code **)(param_1[2] + 0x30))
                            (param_1,0x1140,0x1141,0xffffffff,param_1[0x42],&local_cc);
  if (local_cc == 0) goto LAB_0004b9be;
  iVar5 = param_1[0x16];
  if (*(int *)(iVar5 + 0x340) != 0xc) {
    if (*(int *)(*(int *)(iVar5 + 0x344) + 0xc) << 0x17 < 0) {
      iVar5 = param_1[0x30];
      uVar2 = ssl_sess_cert_new();
      iVar4 = param_1[0x39];
      ptr = *(void **)(iVar4 + 0x14c);
      *(undefined4 *)(iVar5 + 0x98) = uVar2;
      if (ptr != (void *)0x0) {
        CRYPTO_free(ptr);
        iVar4 = param_1[0x39];
      }
      iVar5 = param_1[0x16];
      *(undefined4 *)(iVar4 + 0x14c) = 0;
    }
    pRVar1 = (RSA *)0x1;
    *(undefined4 *)(iVar5 + 0x354) = 1;
    goto LAB_0004b9be;
  }
  iVar4 = param_1[0x30];
  pcVar7 = (char *)param_1[0x10];
  iVar5 = *(int *)(iVar4 + 0x98);
  if (iVar5 == 0) {
    uVar2 = ssl_sess_cert_new();
    *(undefined4 *)(iVar4 + 0x98) = uVar2;
  }
  else {
    if (*(RSA **)(iVar5 + 0x6c) != (RSA *)0x0) {
      RSA_free(*(RSA **)(iVar5 + 0x6c));
      iVar5 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar5 + 0x6c) = 0;
    }
    if (*(DH **)(iVar5 + 0x70) != (DH *)0x0) {
      DH_free(*(DH **)(iVar5 + 0x70));
      iVar5 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar5 + 0x70) = 0;
    }
    if (*(EC_KEY **)(iVar5 + 0x74) != (EC_KEY *)0x0) {
      EC_KEY_free(*(EC_KEY **)(iVar5 + 0x74));
      *(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x74) = 0;
    }
  }
  uVar9 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  uVar10 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x10);
  EVP_MD_CTX_init(&EStack_c8);
  pRVar11 = (RSA *)(uVar9 & 0x100);
  if (pRVar11 != (RSA *)0x0) {
    puVar8 = (undefined *)(uint)CONCAT11(*pcVar7,pcVar7[1]);
    local_d0 = puVar8;
    if (puVar8 < (undefined *)0x81) {
      if ((int)pRVar1 < (int)(puVar8 + 2)) {
        ERR_put_error(0x14,0x8d,0x13c,"s3_clnt.c",0x55b);
        uVar2 = 0x32;
      }
      else {
        __memcpy_chk(auStack_b0,pcVar7 + 2,puVar8,0x81);
        memset(auStack_b0 + (int)puVar8,0,0x81 - (int)puVar8);
        iVar5 = param_1[0x39];
        if (*(void **)(iVar5 + 0x14c) != (void *)0x0) {
          CRYPTO_free(*(void **)(iVar5 + 0x14c));
          iVar5 = param_1[0x39];
        }
        pcVar7 = BUF_strdup((char *)auStack_b0);
        iVar4 = param_1[0x39];
        *(char **)(iVar5 + 0x14c) = pcVar7;
        pRVar11 = (RSA *)((int)pRVar1 - (int)(puVar8 + 2));
        if (*(int *)(iVar4 + 0x14c) != 0) {
LAB_0004ba9e:
          if (pRVar11 != (RSA *)0x0) {
            iVar4 = 0x725;
            iVar5 = 0x99;
            pRVar11 = (RSA *)0x0;
            goto LAB_0004bd8a;
          }
          goto LAB_0004baa6;
        }
        ERR_put_error(0x14,0x8d,0x41,"s3_clnt.c",0x569);
        uVar2 = 0x28;
      }
    }
    else {
      ERR_put_error(0x14,0x8d,0x92,"s3_clnt.c",0x554);
      uVar2 = 0x28;
    }
    local_d4 = (RSA *)0x0;
    local_d8 = (RSA *)0x0;
    local_e0 = (RSA *)0x0;
    pRVar11 = (RSA *)0x0;
    pRVar12 = (RSA *)0x0;
    goto LAB_0004bd62;
  }
  if ((int)(uVar9 << 0x15) < 0) {
    puVar14 = (uchar *)(pcVar7 + 2);
    local_d0 = (undefined *)(uint)CONCAT11(*pcVar7,pcVar7[1]);
    puVar8 = local_d0 + 2;
    if ((int)pRVar1 < (int)puVar8) {
      iVar4 = 0x57a;
      iVar5 = 0x15e;
LAB_0004bd8a:
      ERR_put_error(0x14,0x8d,iVar5,"s3_clnt.c",iVar4);
      uVar2 = 0x32;
      pRVar12 = pRVar11;
      local_e0 = pRVar11;
      local_d8 = pRVar11;
      local_d4 = pRVar11;
      goto LAB_0004bd62;
    }
    r = (RSA *)BN_bin2bn(puVar14,(int)local_d0,(BIGNUM *)0x0);
    param_1[0x6a] = (int)r;
    if (r != (RSA *)0x0) {
      puVar13 = puVar14 + (int)local_d0 + 2;
      local_d0 = (undefined *)(uint)CONCAT11(puVar14[(int)local_d0],(puVar14 + (int)local_d0)[1]);
      puVar8 = puVar8 + (int)(local_d0 + 2);
      if ((int)pRVar1 < (int)puVar8) {
        iVar4 = 0x589;
        iVar5 = 0x15d;
      }
      else {
        r = (RSA *)BN_bin2bn(puVar13,(int)local_d0,(BIGNUM *)0x0);
        param_1[0x6b] = (int)r;
        if (r == (RSA *)0x0) {
          iVar5 = 0x58e;
          goto LAB_0004c3d0;
        }
        puVar14 = puVar13 + (int)local_d0;
        local_d0 = (undefined *)(uint)puVar13[(int)local_d0];
        puVar14 = puVar14 + 1;
        puVar6 = local_d0 + 1;
        if ((int)pRVar1 < (int)(puVar8 + (int)puVar6)) {
          iVar4 = 0x599;
          iVar5 = 0x15f;
        }
        else {
          r = (RSA *)BN_bin2bn(puVar14,(int)local_d0,(BIGNUM *)0x0);
          param_1[0x6c] = (int)r;
          if (r == (RSA *)0x0) {
            iVar5 = 0x59e;
            goto LAB_0004c3d0;
          }
          puVar13 = puVar14 + (int)local_d0;
          local_d0 = (undefined *)(uint)CONCAT11(puVar14[(int)local_d0],puVar13[1]);
          local_dc = local_d0 + 2 + (int)(puVar8 + (int)puVar6);
          if ((int)local_dc <= (int)pRVar1) {
            pBVar3 = BN_bin2bn(puVar13 + 2,(int)local_d0,(BIGNUM *)0x0);
            param_1[0x6d] = (int)pBVar3;
            if (pBVar3 != (BIGNUM *)0x0) {
              puVar14 = puVar13 + 2 + (int)local_d0;
              pRVar1 = (RSA *)((int)pRVar1 - (int)local_dc);
              if ((uVar10 & 1) == 0) {
                if ((uVar10 & 2) == 0) goto LAB_0004bb0c;
                pRVar11 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x24));
              }
              else {
                pRVar11 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
              }
              goto LAB_0004bc42;
            }
            iVar4 = 0x5ad;
            iVar5 = 3;
            goto LAB_0004bb26;
          }
          iVar4 = 0x5a8;
          iVar5 = 0x15c;
        }
      }
      goto LAB_0004bd8a;
    }
    iVar5 = 0x57f;
LAB_0004c3d0:
    ERR_put_error(0x14,0x8d,3,"s3_clnt.c",iVar5);
    pRVar12 = r;
    local_e0 = r;
    local_d8 = r;
LAB_0004bb38:
    local_d4 = (RSA *)0x0;
    EVP_PKEY_free((EVP_PKEY *)r);
LAB_0004bb42:
    if (local_e0 != (RSA *)0x0) {
      DH_free((DH *)local_e0);
    }
    BN_CTX_free((BN_CTX *)local_d4);
    EC_POINT_free((EC_POINT *)pRVar12);
    if (local_d8 != (RSA *)0x0) {
      EC_KEY_free((EC_KEY *)local_d8);
    }
  }
  else {
    pRVar12 = (RSA *)(uVar9 & 1);
    if (pRVar12 == (RSA *)0x0) {
      pRVar11 = (RSA *)(uVar9 & 8);
      if (pRVar11 == (RSA *)0x0) {
        if ((uVar9 & 6) == 0) {
          pRVar11 = (RSA *)(uVar9 & 0x80);
          if (pRVar11 == (RSA *)0x0) {
            if (uVar9 != 0) {
              ERR_put_error(0x14,0x8d,0xf4,"s3_clnt.c",0x6ae);
              uVar2 = 10;
              pRVar12 = pRVar11;
              local_e0 = pRVar11;
              local_d8 = pRVar11;
              local_d4 = pRVar11;
              goto LAB_0004bd62;
            }
LAB_0004bb0c:
            pRVar11 = pRVar1;
            if ((uVar10 & 4) != 0) goto LAB_0004ba9e;
            iVar4 = 0x71e;
            iVar5 = 0x44;
LAB_0004bb26:
            ERR_put_error(0x14,0x8d,iVar5,"s3_clnt.c",iVar4);
            local_d8 = (RSA *)0x0;
            local_e0 = (RSA *)0x0;
            r = (RSA *)0x0;
            pRVar12 = (RSA *)0x0;
          }
          else {
            local_d8 = (RSA *)EC_KEY_new();
            if (local_d8 == (RSA *)0x0) {
              ERR_put_error(0x14,0x8d,0x41,"s3_clnt.c",0x64e);
              r = local_d8;
              pRVar12 = local_d8;
              local_e0 = local_d8;
            }
            else {
              if ((((int)pRVar1 < 3) || (*pcVar7 != '\x03')) ||
                 (iVar5 = tls1_ec_curve_id2nid(pcVar7[2]), iVar5 == 0)) {
                ERR_put_error(0x14,0x8d,0x13a,"s3_clnt.c",0x661);
                pRVar11 = (RSA *)0x0;
                local_d4 = (RSA *)0x0;
                uVar2 = 0x50;
                local_e0 = (RSA *)0x0;
                pRVar12 = (RSA *)0x0;
                goto LAB_0004bd62;
              }
              r = (RSA *)EC_GROUP_new_by_curve_name(iVar5);
              if (r == (RSA *)0x0) {
                ERR_put_error(0x14,0x8d,0x10,"s3_clnt.c",0x668);
                pRVar12 = r;
                local_e0 = r;
              }
              else {
                pRVar12 = (RSA *)EC_KEY_set_group((EC_KEY *)local_d8,(EC_GROUP *)r);
                if (pRVar12 != (RSA *)0x0) {
                  EC_GROUP_free((EC_GROUP *)r);
                  group = EC_KEY_get0_group((EC_KEY *)local_d8);
                  if ((*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x20) << 0x1e < 0) &&
                     (iVar5 = EC_GROUP_get_degree(group), 0xa3 < iVar5)) {
                    ERR_put_error(0x14,0x8d,0x136,"s3_clnt.c",0x678);
                    pRVar11 = (RSA *)0x0;
                    local_d4 = (RSA *)0x0;
                    uVar2 = 0x3c;
                    local_e0 = (RSA *)0x0;
                    pRVar12 = (RSA *)0x0;
                  }
                  else {
                    pRVar12 = (RSA *)EC_POINT_new(group);
                    if ((pRVar12 == (RSA *)0x0) ||
                       (local_d4 = (RSA *)BN_CTX_new(), local_d4 == (RSA *)0x0)) {
                      local_e0 = (RSA *)0x0;
                      ERR_put_error(0x14,0x8d,0x41,"s3_clnt.c",0x682);
                      r = local_e0;
                      goto LAB_0004bb38;
                    }
                    uVar9 = (uint)(byte)pcVar7[3];
                    local_dc = (undefined *)(uVar9 + 4);
                    if (((int)local_dc <= (int)pRVar1) &&
                       (iVar5 = EC_POINT_oct2point(group,(EC_POINT *)pRVar12,(uchar *)(pcVar7 + 4),
                                                   uVar9,(BN_CTX *)local_d4), iVar5 != 0)) {
                      puVar14 = (uchar *)(pcVar7 + 4 + uVar9);
                      pRVar1 = (RSA *)((int)pRVar1 - (int)local_dc);
                      if ((uVar10 & 1) == 0) {
                        pRVar11 = (RSA *)(uVar10 & 0x40);
                        if (pRVar11 != (RSA *)0x0) {
                          pRVar11 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98)
                                                                     + 0x48));
                        }
                      }
                      else {
                        pRVar11 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) +
                                                                   0xc));
                      }
                      EC_KEY_set_public_key((EC_KEY *)local_d8,(EC_POINT *)pRVar12);
                      *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x74) = local_d8;
                      BN_CTX_free((BN_CTX *)local_d4);
                      EC_POINT_free((EC_POINT *)pRVar12);
                      goto LAB_0004bc42;
                    }
                    local_e0 = (RSA *)0x0;
                    ERR_put_error(0x14,0x8d,0x132,"s3_clnt.c",0x68e);
                    uVar2 = 0x32;
                    pRVar11 = local_e0;
                  }
                  goto LAB_0004bd62;
                }
                ERR_put_error(0x14,0x8d,0x10,"s3_clnt.c",0x66d);
                r = pRVar12;
                local_e0 = pRVar12;
              }
            }
          }
          goto LAB_0004bb38;
        }
        ERR_put_error(0x14,0x8d,0xeb,"s3_clnt.c",0x641);
        uVar2 = 0x2f;
        pRVar12 = pRVar11;
        local_e0 = pRVar11;
        local_d8 = pRVar11;
        local_d4 = pRVar11;
      }
      else {
        local_e0 = (RSA *)DH_new();
        if (local_e0 == (RSA *)0x0) {
          ERR_put_error(0x14,0x8d,5,"s3_clnt.c",0x5fd);
          r = local_e0;
          pRVar12 = local_e0;
          local_d8 = local_e0;
          goto LAB_0004bb38;
        }
        puVar14 = (uchar *)(pcVar7 + 2);
        local_d0 = (undefined *)(uint)CONCAT11(*pcVar7,pcVar7[1]);
        puVar8 = local_d0 + 2;
        pRVar11 = pRVar12;
        if ((int)puVar8 <= (int)pRVar1) {
          r = (RSA *)BN_bin2bn(puVar14,(int)local_d0,(BIGNUM *)0x0);
          local_e0->meth = (RSA_METHOD *)r;
          if (r == (RSA *)0x0) {
            iVar5 = 0x60a;
          }
          else {
            puVar13 = puVar14 + (int)local_d0 + 2;
            local_d0 = (undefined *)
                       (uint)CONCAT11(puVar14[(int)local_d0],(puVar14 + (int)local_d0)[1]);
            puVar6 = local_d0 + 2;
            if ((int)pRVar1 < (int)(puVar8 + (int)puVar6)) {
              iVar4 = 0x614;
              iVar5 = 0x6c;
              goto LAB_0004c2bc;
            }
            r = (RSA *)BN_bin2bn(puVar13,(int)local_d0,(BIGNUM *)0x0);
            local_e0->engine = (ENGINE *)r;
            if (r == (RSA *)0x0) {
              iVar5 = 0x619;
            }
            else {
              puVar14 = puVar13 + (int)local_d0;
              local_d0 = (undefined *)(uint)CONCAT11(puVar13[(int)local_d0],puVar14[1]);
              local_dc = local_d0 + 2 + (int)(puVar8 + (int)puVar6);
              if ((int)pRVar1 < (int)local_dc) {
                iVar4 = 0x623;
                iVar5 = 0x6d;
                pRVar11 = (RSA *)0x0;
                goto LAB_0004c2bc;
              }
              r = (RSA *)BN_bin2bn(puVar14 + 2,(int)local_d0,(BIGNUM *)0x0);
              local_e0->e = (BIGNUM *)r;
              if (r != (RSA *)0x0) {
                puVar14 = puVar14 + 2 + (int)local_d0;
                pRVar1 = (RSA *)((int)pRVar1 - (int)local_dc);
                if ((uVar10 & 1) == 0) {
                  pRVar11 = (RSA *)(uVar10 & 2);
                  if (pRVar11 != (RSA *)0x0) {
                    pRVar11 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) +
                                                               0x24));
                  }
                }
                else {
                  pRVar11 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc))
                  ;
                }
                *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x70) = local_e0;
                goto LAB_0004bc42;
              }
              iVar5 = 0x628;
            }
          }
          ERR_put_error(0x14,0x8d,3,"s3_clnt.c",iVar5);
          pRVar12 = r;
          local_d8 = r;
          goto LAB_0004bb38;
        }
        iVar4 = 0x605;
        iVar5 = 0x6e;
LAB_0004c2bc:
        ERR_put_error(0x14,0x8d,iVar5,"s3_clnt.c",iVar4);
        uVar2 = 0x32;
        pRVar12 = pRVar11;
        local_d8 = pRVar11;
        local_d4 = pRVar11;
      }
LAB_0004bd62:
      ssl3_send_alert(param_1,2,uVar2);
      EVP_PKEY_free((EVP_PKEY *)pRVar11);
      goto LAB_0004bb42;
    }
    r = RSA_new();
    if (r == (RSA *)0x0) {
      ERR_put_error(0x14,0x8d,0x41,"s3_clnt.c",0x5c7);
      pRVar12 = r;
      local_e0 = r;
      local_d8 = r;
      goto LAB_0004bb38;
    }
    puVar14 = (uchar *)(pcVar7 + 2);
    local_d0 = (undefined *)(uint)CONCAT11(*pcVar7,pcVar7[1]);
    local_dc = local_d0 + 2;
    if ((int)pRVar1 < (int)local_dc) {
      ERR_put_error(0x14,0x8d,0x79,"s3_clnt.c",0x5cf);
LAB_0004c22c:
      ssl3_send_alert(param_1,2,0x32);
    }
    else {
      pBVar3 = BN_bin2bn(puVar14,(int)local_d0,r->n);
      iVar5 = 0x5d4;
      r->n = pBVar3;
      if (pBVar3 == (BIGNUM *)0x0) {
LAB_0004c48e:
        ERR_put_error(0x14,0x8d,3,"s3_clnt.c",iVar5);
      }
      else {
        puVar13 = puVar14 + (int)local_d0;
        local_d0 = (undefined *)(uint)CONCAT11(puVar14[(int)local_d0],puVar13[1]);
        local_dc = local_d0 + 2 + (int)local_dc;
        if ((int)pRVar1 < (int)local_dc) {
          ERR_put_error(0x14,0x8d,0x78,"s3_clnt.c",0x5de);
          goto LAB_0004c22c;
        }
        pBVar3 = BN_bin2bn(puVar13 + 2,(int)local_d0,r->e);
        r->e = pBVar3;
        if (pBVar3 == (BIGNUM *)0x0) {
          iVar5 = 0x5e3;
          goto LAB_0004c48e;
        }
        puVar14 = puVar13 + 2 + (int)local_d0;
        pRVar1 = (RSA *)((int)pRVar1 - (int)local_dc);
        if ((uVar10 & 1) != 0) {
          pRVar11 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
          *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x6c) = r;
LAB_0004bc42:
          if (pRVar11 == (RSA *)0x0) goto LAB_0004bb0c;
          if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
            uVar9 = tls12_get_sigid(pRVar11);
            if (uVar9 == 0xffffffff) {
              ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x6bf);
              local_d8 = (RSA *)0x0;
              local_e0 = (RSA *)0x0;
              r = pRVar11;
              pRVar12 = (RSA *)0x0;
              goto LAB_0004bb38;
            }
            if (puVar14[1] != uVar9) {
              iVar4 = 0x6c5;
              iVar5 = 0x172;
              goto LAB_0004c0d2;
            }
            pRVar1 = (RSA *)((int)&pRVar1[-1].mt_blinding + 2);
            pRVar12 = (RSA *)tls12_get_hash(*puVar14);
            puVar14 = puVar14 + 2;
            if (pRVar12 != (RSA *)0x0) goto LAB_0004bc62;
            iVar4 = 0x6cc;
            iVar5 = 0x170;
          }
          else {
            pRVar12 = (RSA *)EVP_sha1();
LAB_0004bc62:
            puVar6 = (undefined *)((int)&pRVar1[-1].mt_blinding + 2);
            local_d0 = (undefined *)(uint)CONCAT11(*puVar14,puVar14[1]);
            puVar8 = (undefined *)EVP_PKEY_size((EVP_PKEY *)pRVar11);
            if ((int)puVar6 <= (int)puVar8) {
              puVar8 = local_d0;
            }
            if ((puVar6 == puVar8) && (0 < (int)puVar6)) {
              if ((pRVar11->pad == 6) && ((*param_1 >> 8 != 3 || (*param_1 < 0x303)))) {
                local_e0 = (RSA *)0x0;
                pRVar12 = (RSA *)0x2;
                puVar13 = auStack_b0;
                do {
                  EVP_MD_CTX_set_flags(&EStack_c8,8);
                  if (pRVar12 == (RSA *)0x2) {
                    type = *(EVP_MD **)(param_1[0x39] + 0x8c);
                  }
                  else {
                    type = *(EVP_MD **)(param_1[0x39] + 0x90);
                  }
                  EVP_DigestInit_ex(&EStack_c8,type,(ENGINE *)0x0);
                  EVP_DigestUpdate(&EStack_c8,(void *)(param_1[0x16] + 0xc0),0x20);
                  EVP_DigestUpdate(&EStack_c8,(void *)(param_1[0x16] + 0xa0),0x20);
                  EVP_DigestUpdate(&EStack_c8,pcVar7,(size_t)local_dc);
                  EVP_DigestFinal_ex(&EStack_c8,puVar13,(uint *)&local_d0);
                  pRVar12 = (RSA *)((int)&pRVar12[-1].mt_blinding + 3);
                  puVar13 = puVar13 + (int)local_d0;
                  local_e0 = (RSA *)((int)local_e0 + (int)local_d0);
                } while (pRVar12 != (RSA *)0x0);
                local_d0 = (undefined *)
                           RSA_verify(0x72,auStack_b0,(uint)local_e0,puVar14 + 2,(uint)puVar6,
                                      (RSA *)pRVar11->e);
                if ((int)local_d0 < 0) {
                  iVar4 = 0x6fe;
                  iVar5 = 0x76;
                }
                else {
                  if (local_d0 != (undefined *)0x0) goto LAB_0004baa6;
                  iVar4 = 0x705;
                  iVar5 = 0x7b;
                }
              }
              else {
                EVP_DigestInit_ex(&EStack_c8,(EVP_MD *)pRVar12,(ENGINE *)0x0);
                EVP_DigestUpdate(&EStack_c8,(void *)(param_1[0x16] + 0xc0),0x20);
                EVP_DigestUpdate(&EStack_c8,(void *)(param_1[0x16] + 0xa0),0x20);
                EVP_DigestUpdate(&EStack_c8,pcVar7,(size_t)local_dc);
                iVar5 = EVP_VerifyFinal(&EStack_c8,puVar14 + 2,(uint)puVar6,(EVP_PKEY *)pRVar11);
                if (0 < iVar5) {
LAB_0004baa6:
                  EVP_PKEY_free((EVP_PKEY *)pRVar11);
                  EVP_MD_CTX_cleanup(&EStack_c8);
                  pRVar1 = (RSA *)0x1;
                  goto LAB_0004b9be;
                }
                iVar4 = 0x714;
                iVar5 = 0x7b;
                pRVar12 = (RSA *)0x0;
              }
              ERR_put_error(0x14,0x8d,iVar5,"s3_clnt.c",iVar4);
              uVar2 = 0x33;
              local_e0 = pRVar12;
              local_d8 = pRVar12;
              local_d4 = pRVar12;
              goto LAB_0004bd62;
            }
            iVar4 = 0x6e1;
            iVar5 = 0x108;
LAB_0004c0d2:
            pRVar12 = (RSA *)0x0;
          }
          ERR_put_error(0x14,0x8d,iVar5,"s3_clnt.c",iVar4);
          uVar2 = 0x32;
          local_e0 = pRVar12;
          local_d8 = pRVar12;
          local_d4 = pRVar12;
          goto LAB_0004bd62;
        }
        ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x5ee);
      }
    }
    EVP_PKEY_free((EVP_PKEY *)0x0);
    RSA_free(r);
    BN_CTX_free((BN_CTX *)0x0);
    EC_POINT_free((EC_POINT *)0x0);
  }
  EVP_MD_CTX_cleanup(&EStack_c8);
  pRVar1 = (RSA *)0xffffffff;
LAB_0004b9be:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pRVar1);
  }
  return;
}

