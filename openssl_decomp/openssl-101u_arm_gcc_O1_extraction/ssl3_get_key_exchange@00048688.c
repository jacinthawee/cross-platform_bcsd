
void ssl3_get_key_exchange(int *param_1)

{
  uchar uVar1;
  uchar uVar2;
  RSA *pRVar3;
  undefined4 uVar4;
  RSA *r;
  BIGNUM *pBVar5;
  undefined *puVar6;
  RSA *dh;
  EC_GROUP *group;
  EVP_MD *type;
  int iVar7;
  int iVar8;
  int iVar9;
  void *ptr;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  undefined *siglen;
  RSA *pRVar13;
  RSA *pRVar14;
  uchar *puVar15;
  uint uVar16;
  uchar *puVar17;
  RSA *local_dc;
  size_t local_d8;
  RSA *local_d4;
  undefined4 local_d0;
  int local_cc;
  uint local_c8;
  EVP_MD_CTX EStack_c4;
  uchar auStack_ac [128];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_c4);
  pRVar3 = (RSA *)(**(code **)(param_1[2] + 0x30))
                            (param_1,0x1140,0x1141,0xffffffff,param_1[0x42],&local_cc);
  if (local_cc == 0) goto LAB_000486ec;
  iVar9 = param_1[0x16];
  uVar11 = *(uint *)(*(int *)(iVar9 + 0x344) + 0xc);
  if (*(int *)(iVar9 + 0x340) != 0xc) {
    if ((uVar11 & 0x88) == 0) {
      if ((int)(uVar11 << 0x17) < 0) {
        iVar9 = param_1[0x30];
        uVar4 = ssl_sess_cert_new();
        iVar8 = param_1[0x39];
        ptr = *(void **)(iVar8 + 0x14c);
        *(undefined4 *)(iVar9 + 0x98) = uVar4;
        if (ptr != (void *)0x0) {
          CRYPTO_free(ptr);
          iVar8 = param_1[0x39];
        }
        iVar9 = param_1[0x16];
        *(undefined4 *)(iVar8 + 0x14c) = 0;
      }
      pRVar3 = (RSA *)0x1;
      *(undefined4 *)(iVar9 + 0x354) = 1;
      goto LAB_000486ec;
    }
    pRVar14 = (RSA *)0x0;
    ERR_put_error(0x14,0x8d,0xf4,"s3_clnt.c",0x538);
    local_d0 = 10;
    local_d4 = (RSA *)0x0;
    local_dc = (RSA *)0x0;
    pRVar13 = (RSA *)0x0;
    dh = pRVar14;
    goto LAB_00048c04;
  }
  iVar8 = param_1[0x30];
  pcVar10 = (char *)param_1[0x10];
  iVar9 = *(int *)(iVar8 + 0x98);
  if (iVar9 == 0) {
    uVar4 = ssl_sess_cert_new();
    *(undefined4 *)(iVar8 + 0x98) = uVar4;
  }
  else {
    if (*(RSA **)(iVar9 + 0x6c) != (RSA *)0x0) {
      RSA_free(*(RSA **)(iVar9 + 0x6c));
      iVar9 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar9 + 0x6c) = 0;
    }
    if (*(DH **)(iVar9 + 0x70) != (DH *)0x0) {
      DH_free(*(DH **)(iVar9 + 0x70));
      iVar9 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar9 + 0x70) = 0;
    }
    if (*(EC_KEY **)(iVar9 + 0x74) != (EC_KEY *)0x0) {
      EC_KEY_free(*(EC_KEY **)(iVar9 + 0x74));
      *(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x74) = 0;
    }
  }
  pRVar13 = (RSA *)(uVar11 & 0x100);
  local_d0 = 0x32;
  uVar12 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x10);
  if (pRVar13 == (RSA *)0x0) {
    pRVar14 = (RSA *)(uVar11 & 0x400);
    if (pRVar14 != (RSA *)0x0) {
      pRVar14 = pRVar13;
      if ((int)pRVar3 < 2) {
        iVar8 = 0x596;
        iVar9 = 0xa0;
      }
      else {
        puVar15 = (uchar *)(pcVar10 + 2);
        uVar11 = (uint)CONCAT11(*pcVar10,pcVar10[1]);
        if ((int)&pRVar3[-1].field_0x56 < (int)uVar11) {
          iVar8 = 0x59c;
          iVar9 = 0x15e;
        }
        else {
          r = (RSA *)BN_bin2bn(puVar15,uVar11,(BIGNUM *)0x0);
          param_1[0x6a] = (int)r;
          if (r == (RSA *)0x0) {
            iVar9 = 0x5a2;
LAB_00049246:
            ERR_put_error(0x14,0x8d,3,"s3_clnt.c",iVar9);
            pRVar13 = r;
            dh = r;
            local_dc = r;
            goto LAB_00048950;
          }
          if ((int)((int)pRVar3 - (uVar11 + 2)) < 2) {
            iVar8 = 0x5a8;
            iVar9 = 0xa0;
          }
          else {
            puVar17 = puVar15 + uVar11 + 2;
            uVar16 = (uint)CONCAT11(puVar15[uVar11],puVar15[uVar11 + 1]);
            if ((int)((int)pRVar3 - (uVar11 + 4)) < (int)uVar16) {
              iVar8 = 0x5b0;
              iVar9 = 0x15d;
            }
            else {
              r = (RSA *)BN_bin2bn(puVar17,uVar16,(BIGNUM *)0x0);
              iVar9 = uVar11 + 4 + uVar16;
              param_1[0x6b] = (int)r;
              if (r == (RSA *)0x0) {
                iVar9 = 0x5b6;
                goto LAB_00049246;
              }
              if (0 < (int)pRVar3 - iVar9) {
                iVar9 = iVar9 + 1;
                uVar11 = (uint)puVar17[uVar16];
                puVar17 = puVar17 + uVar16 + 1;
                if ((int)pRVar3 - iVar9 < (int)uVar11) {
                  iVar8 = 0x5c5;
                  iVar9 = 0x15f;
                  goto LAB_00048c28;
                }
                iVar9 = iVar9 + uVar11;
                r = (RSA *)BN_bin2bn(puVar17,uVar11,(BIGNUM *)0x0);
                param_1[0x6c] = (int)r;
                if (r == (RSA *)0x0) {
                  iVar9 = 0x5cb;
                  goto LAB_00049246;
                }
                if ((int)pRVar3 - iVar9 < 2) {
                  iVar8 = 0x5d1;
                  goto LAB_000491c0;
                }
                iVar9 = iVar9 + 2;
                uVar16 = (uint)CONCAT11(puVar17[uVar11],puVar17[uVar11 + 1]);
                if ((int)pRVar3 - iVar9 < (int)uVar16) {
                  iVar8 = 0x5d9;
                  iVar9 = 0x15c;
                  goto LAB_00048c28;
                }
                local_d8 = iVar9 + uVar16;
                r = (RSA *)BN_bin2bn(puVar17 + uVar11 + 2,uVar16,(BIGNUM *)0x0);
                param_1[0x6d] = (int)r;
                if (r == (RSA *)0x0) {
                  iVar9 = 0x5df;
                  goto LAB_00049246;
                }
                pRVar14 = (RSA *)srp_verify_server_param(param_1,&local_d0);
                puVar15 = puVar17 + uVar11 + 2 + uVar16;
                pRVar3 = (RSA *)((int)pRVar3 - local_d8);
                if (pRVar14 == (RSA *)0x0) {
                  iVar8 = 0x5e6;
                  iVar9 = 0x173;
                  goto LAB_00048c2c;
                }
                if ((int)(uVar12 << 0x1f) < 0) {
                  pRVar14 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc))
                  ;
                }
                else {
                  if (-1 < (int)(uVar12 << 0x1e)) goto LAB_00048920;
                  pRVar14 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0x24)
                                                  );
                }
LAB_00048a90:
                if (pRVar14 == (RSA *)0x0) goto LAB_00048920;
                if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
                  if ((int)pRVar3 < 2) {
                    iVar9 = 0x72c;
                    goto LAB_00049052;
                  }
                  uVar11 = tls12_get_sigid(pRVar14);
                  if (uVar11 == 0xffffffff) {
                    ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x733);
                    local_dc = (RSA *)0x0;
                    r = pRVar14;
                    pRVar13 = (RSA *)0x0;
                    dh = (RSA *)0x0;
                    goto LAB_00048950;
                  }
                  if (puVar15[1] != uVar11) {
                    ERR_put_error(0x14,0x8d,0x172,"s3_clnt.c",0x739);
                    local_d0 = 0x32;
                    local_d4 = (RSA *)0x0;
                    local_dc = (RSA *)0x0;
                    pRVar13 = (RSA *)0x0;
                    dh = (RSA *)0x0;
                    goto LAB_00048c04;
                  }
                  pRVar3 = (RSA *)&pRVar3[-1].field_0x56;
                  pRVar13 = (RSA *)tls12_get_hash(*puVar15);
                  puVar15 = puVar15 + 2;
                  if (pRVar13 != (RSA *)0x0) goto LAB_00048aee;
                  iVar9 = 0x73f;
                  iVar8 = 0x170;
                }
                else {
                  pRVar13 = (RSA *)EVP_sha1();
LAB_00048aee:
                  if ((int)pRVar3 < 2) {
                    iVar9 = 0x74b;
LAB_00049052:
                    iVar8 = 0xa0;
                  }
                  else {
                    uVar2 = *puVar15;
                    uVar1 = puVar15[1];
                    siglen = &pRVar3[-1].field_0x56;
                    puVar6 = (undefined *)EVP_PKEY_size((EVP_PKEY *)pRVar14);
                    if ((int)siglen <= (int)puVar6) {
                      puVar6 = (undefined *)(uint)CONCAT11(uVar2,uVar1);
                    }
                    if ((siglen == puVar6) && (0 < (int)siglen)) {
                      if ((*(int *)pRVar14 == 6) && ((*param_1 >> 8 != 3 || (*param_1 < 0x303)))) {
                        puVar17 = auStack_ac;
                        iVar9 = 2;
                        uVar11 = 0;
                        do {
                          EVP_MD_CTX_set_flags(&EStack_c4,8);
                          if (iVar9 == 2) {
                            type = *(EVP_MD **)(param_1[0x39] + 0x8c);
                          }
                          else {
                            type = *(EVP_MD **)(param_1[0x39] + 0x90);
                          }
                          iVar8 = EVP_DigestInit_ex(&EStack_c4,type,(ENGINE *)0x0);
                          if (((iVar8 < 1) ||
                              (iVar8 = EVP_DigestUpdate(&EStack_c4,(void *)(param_1[0x16] + 0xc0),
                                                        0x20), iVar8 < 1)) ||
                             ((iVar8 = EVP_DigestUpdate(&EStack_c4,(void *)(param_1[0x16] + 0xa0),
                                                        0x20), iVar8 < 1 ||
                              ((iVar8 = EVP_DigestUpdate(&EStack_c4,pcVar10,local_d8), iVar8 < 1 ||
                               (iVar8 = EVP_DigestFinal_ex(&EStack_c4,puVar17,&local_c8), iVar8 < 1)
                               ))))) {
                            ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x76e);
                            local_d0 = 0x50;
                            goto LAB_00048bf6;
                          }
                          iVar9 = iVar9 + -1;
                          puVar17 = puVar17 + local_c8;
                          uVar11 = uVar11 + local_c8;
                        } while (iVar9 != 0);
                        iVar9 = RSA_verify(0x72,auStack_ac,uVar11,puVar15 + 2,(uint)siglen,
                                           *(RSA **)&pRVar14->field_0x14);
                        if (iVar9 < 0) {
                          local_d0 = 0x33;
                          ERR_put_error(0x14,0x8d,0x76,"s3_clnt.c",0x778);
                        }
                        else {
                          if (iVar9 != 0) {
LAB_000487bc:
                            EVP_PKEY_free((EVP_PKEY *)pRVar14);
                            EVP_MD_CTX_cleanup(&EStack_c4);
                            pRVar3 = (RSA *)0x1;
                            goto LAB_000486ec;
                          }
                          local_d0 = 0x33;
                          ERR_put_error(0x14,0x8d,0x7b,"s3_clnt.c",0x77e);
                        }
LAB_00048bf6:
                        local_d4 = (RSA *)0x0;
                        local_dc = (RSA *)0x0;
                        pRVar13 = (RSA *)0x0;
                        dh = (RSA *)0x0;
                      }
                      else {
                        iVar9 = EVP_DigestInit_ex(&EStack_c4,(EVP_MD *)pRVar13,(ENGINE *)0x0);
                        if ((iVar9 < 1) ||
                           (((iVar9 = EVP_DigestUpdate(&EStack_c4,(void *)(param_1[0x16] + 0xc0),
                                                       0x20), iVar9 < 1 ||
                             (iVar9 = EVP_DigestUpdate(&EStack_c4,(void *)(param_1[0x16] + 0xa0),
                                                       0x20), iVar9 < 1)) ||
                            (iVar9 = EVP_DigestUpdate(&EStack_c4,pcVar10,local_d8), iVar9 < 1)))) {
                          iVar8 = 0x78b;
                          iVar9 = 6;
                          local_d0 = 0x50;
                        }
                        else {
                          iVar9 = EVP_VerifyFinal(&EStack_c4,puVar15 + 2,(uint)siglen,
                                                  (EVP_PKEY *)pRVar14);
                          if (0 < iVar9) goto LAB_000487bc;
                          iVar8 = 0x791;
                          iVar9 = 0x7b;
                          local_d0 = 0x33;
                        }
                        local_d4 = (RSA *)0x0;
                        local_dc = (RSA *)0x0;
                        ERR_put_error(0x14,0x8d,iVar9,"s3_clnt.c",iVar8);
                        pRVar13 = (RSA *)0x0;
                        dh = (RSA *)0x0;
                      }
                      goto LAB_00048c04;
                    }
                    iVar9 = 0x757;
                    iVar8 = 0x108;
                  }
                  pRVar13 = (RSA *)0x0;
                }
                ERR_put_error(0x14,0x8d,iVar8,"s3_clnt.c",iVar9);
                dh = pRVar13;
                local_dc = pRVar13;
                local_d4 = pRVar13;
                goto LAB_00048c04;
              }
              iVar8 = 0x5bc;
              iVar9 = 0xa0;
            }
          }
        }
      }
      goto LAB_00048c2c;
    }
    pRVar13 = (RSA *)(uVar11 & 1);
    if (pRVar13 == (RSA *)0x0) {
      if ((RSA *)(uVar11 & 8) == (RSA *)0x0) {
        pRVar14 = (RSA *)(uVar11 & 6);
        if (pRVar14 != (RSA *)0x0) {
          iVar9 = 0x6b0;
          iVar8 = 0xeb;
          local_d0 = 0x2f;
          pRVar14 = (RSA *)(uVar11 & 8);
          goto LAB_00048d0a;
        }
        pRVar13 = (RSA *)(uVar11 & 0x80);
        if (pRVar13 == (RSA *)0x0) {
          if (uVar11 != 0) {
            iVar9 = 0x720;
            goto LAB_00048d00;
          }
LAB_00048920:
          pRVar14 = pRVar3;
          if ((uVar12 & 0x404) != 0) goto LAB_000487b2;
          ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x798);
          local_dc = (RSA *)0x0;
          r = (RSA *)0x0;
          pRVar13 = (RSA *)0x0;
          dh = (RSA *)0x0;
        }
        else {
          local_dc = (RSA *)EC_KEY_new();
          if (local_dc != (RSA *)0x0) {
            if ((int)pRVar3 < 4) {
              ERR_put_error(0x14,0x8d,0xa0,"s3_clnt.c",0x6cc);
              pRVar13 = pRVar14;
              dh = pRVar14;
              local_d4 = pRVar14;
            }
            else {
              if ((*pcVar10 == '\x03') && (iVar9 = tls1_ec_curve_id2nid(pcVar10[2]), iVar9 != 0)) {
                r = (RSA *)EC_GROUP_new_by_curve_name(iVar9);
                if (r == (RSA *)0x0) {
                  ERR_put_error(0x14,0x8d,0x10,"s3_clnt.c",0x6da);
                  pRVar13 = r;
                  dh = r;
                }
                else {
                  pRVar13 = (RSA *)EC_KEY_set_group((EC_KEY *)local_dc,(EC_GROUP *)r);
                  if (pRVar13 == (RSA *)0x0) {
                    ERR_put_error(0x14,0x8d,0x10,"s3_clnt.c",0x6de);
                    r = pRVar13;
                    dh = pRVar13;
                  }
                  else {
                    EC_GROUP_free((EC_GROUP *)r);
                    group = EC_KEY_get0_group((EC_KEY *)local_dc);
                    if ((*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x20) << 0x1e < 0) &&
                       (iVar9 = EC_GROUP_get_degree(group), 0xa3 < iVar9)) {
                      iVar8 = 0x6e9;
                      iVar9 = 0x136;
                      local_d0 = 0x3c;
                      goto LAB_000491a6;
                    }
                    pRVar13 = (RSA *)EC_POINT_new(group);
                    if ((pRVar13 != (RSA *)0x0) &&
                       (local_d4 = (RSA *)BN_CTX_new(), local_d4 != (RSA *)0x0)) {
                      uVar11 = (uint)(byte)pcVar10[3];
                      if (((int)uVar11 <= (int)&pRVar3[-1].field_0x54) &&
                         (iVar9 = EC_POINT_oct2point(group,(EC_POINT *)pRVar13,
                                                     (uchar *)(pcVar10 + 4),uVar11,
                                                     (BN_CTX *)local_d4), iVar9 != 0)) {
                        local_d8 = uVar11 + 4;
                        puVar15 = (uchar *)(pcVar10 + 4 + uVar11);
                        pRVar3 = (RSA *)((int)pRVar3 - local_d8);
                        if ((int)(uVar12 << 0x1f) < 0) {
                          pRVar14 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98)
                                                                     + 0xc));
                        }
                        else {
                          pRVar14 = (RSA *)(uVar12 & 0x40);
                          if (pRVar14 != (RSA *)0x0) {
                            pRVar14 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] +
                                                                                0x98) + 0x48));
                          }
                        }
                        EC_KEY_set_public_key((EC_KEY *)local_dc,(EC_POINT *)pRVar13);
                        *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x74) = local_dc;
                        BN_CTX_free((BN_CTX *)local_d4);
                        EC_POINT_free((EC_POINT *)pRVar13);
                        goto LAB_00048a90;
                      }
                      ERR_put_error(0x14,0x8d,0x132,"s3_clnt.c",0x6fc);
                      pRVar14 = (RSA *)0x0;
                      dh = (RSA *)0x0;
                      goto LAB_00048c04;
                    }
                    ERR_put_error(0x14,0x8d,0x41,"s3_clnt.c",0x6f2);
                    r = (RSA *)0x0;
                    dh = (RSA *)0x0;
                  }
                }
                goto LAB_00048950;
              }
              iVar8 = 0x6d4;
              iVar9 = 0x13a;
              local_d0 = 0x50;
LAB_000491a6:
              local_d4 = (RSA *)0x0;
              pRVar14 = (RSA *)0x0;
              ERR_put_error(0x14,0x8d,iVar9,"s3_clnt.c",iVar8);
              pRVar13 = (RSA *)0x0;
              dh = (RSA *)0x0;
            }
            goto LAB_00048c04;
          }
          ERR_put_error(0x14,0x8d,0x41,"s3_clnt.c",0x6bb);
          r = local_dc;
          pRVar13 = local_dc;
          dh = local_dc;
        }
      }
      else {
        dh = (RSA *)DH_new();
        if (dh != (RSA *)0x0) {
          pRVar14 = pRVar13;
          if ((int)pRVar3 < 2) {
            iVar8 = 0x650;
            iVar9 = 0xa0;
          }
          else {
            puVar15 = (uchar *)(pcVar10 + 2);
            uVar11 = (uint)CONCAT11(*pcVar10,pcVar10[1]);
            if ((int)&pRVar3[-1].field_0x56 < (int)uVar11) {
              iVar8 = 0x656;
              iVar9 = 0x6e;
            }
            else {
              r = (RSA *)BN_bin2bn(puVar15,uVar11,(BIGNUM *)0x0);
              *(RSA **)&dh->field_0x8 = r;
              if (r == (RSA *)0x0) {
                iVar9 = 0x65c;
LAB_000494ec:
                ERR_put_error(0x14,0x8d,3,"s3_clnt.c",iVar9);
                pRVar13 = r;
                local_dc = r;
                goto LAB_00048950;
              }
              if (*(RSA **)&r->field_0x4 == (RSA *)0x0) {
                iVar8 = 0x662;
                iVar9 = 0x18b;
                pRVar14 = *(RSA **)&r->field_0x4;
              }
              else if ((int)((int)pRVar3 - (uVar11 + 2)) < 2) {
                iVar8 = 0x668;
LAB_000495ca:
                iVar9 = 0xa0;
                pRVar14 = (RSA *)0x0;
              }
              else {
                puVar17 = puVar15 + uVar11 + 2;
                uVar16 = (uint)CONCAT11(puVar15[uVar11],puVar15[uVar11 + 1]);
                if ((int)((int)pRVar3 - (uVar11 + 4)) < (int)uVar16) {
                  iVar8 = 0x670;
                  iVar9 = 0x6c;
                  pRVar14 = (RSA *)0x0;
                }
                else {
                  iVar9 = uVar11 + 4 + uVar16;
                  r = (RSA *)BN_bin2bn(puVar17,uVar16,(BIGNUM *)0x0);
                  *(RSA **)&dh->field_0xc = r;
                  if (r == (RSA *)0x0) {
                    iVar9 = 0x676;
                    goto LAB_000494ec;
                  }
                  if (*(RSA **)&r->field_0x4 == (RSA *)0x0) {
                    iVar8 = 0x67c;
                    iVar9 = 0x177;
                    pRVar14 = *(RSA **)&r->field_0x4;
                  }
                  else {
                    if ((int)pRVar3 - iVar9 < 2) {
                      iVar8 = 0x681;
                      goto LAB_000495ca;
                    }
                    iVar9 = iVar9 + 2;
                    uVar11 = (uint)CONCAT11(puVar17[uVar16],puVar17[uVar16 + 1]);
                    if ((int)pRVar3 - iVar9 < (int)uVar11) {
                      iVar8 = 0x689;
                      iVar9 = 0x6d;
                      pRVar14 = (RSA *)0x0;
                    }
                    else {
                      local_d8 = iVar9 + uVar11;
                      r = (RSA *)BN_bin2bn(puVar17 + uVar16 + 2,uVar11,(BIGNUM *)0x0);
                      *(RSA **)&dh->field_0x14 = r;
                      if (r == (RSA *)0x0) {
                        iVar9 = 0x68f;
                        goto LAB_000494ec;
                      }
                      puVar15 = puVar17 + uVar16 + 2 + uVar11;
                      pRVar3 = (RSA *)((int)pRVar3 - local_d8);
                      if (*(RSA **)&r->field_0x4 != (RSA *)0x0) {
                        if ((int)(uVar12 << 0x1f) < 0) {
                          pRVar14 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98)
                                                                     + 0xc));
                        }
                        else {
                          pRVar14 = (RSA *)(uVar12 & 2);
                          if (pRVar14 != (RSA *)0x0) {
                            pRVar14 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] +
                                                                                0x98) + 0x24));
                          }
                        }
                        *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x70) = dh;
                        goto LAB_00048a90;
                      }
                      iVar8 = 0x696;
                      iVar9 = 0x189;
                      pRVar14 = *(RSA **)&r->field_0x4;
                    }
                  }
                }
              }
            }
          }
          ERR_put_error(0x14,0x8d,iVar9,"s3_clnt.c",iVar8);
          pRVar13 = pRVar14;
          local_dc = pRVar14;
          local_d4 = pRVar14;
          goto LAB_00048c04;
        }
        ERR_put_error(0x14,0x8d,5,"s3_clnt.c",0x64a);
        r = dh;
        pRVar13 = dh;
        local_dc = dh;
      }
LAB_00048950:
      local_d4 = (RSA *)0x0;
      EVP_PKEY_free((EVP_PKEY *)r);
      goto LAB_0004895a;
    }
    pRVar13 = (RSA *)(*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2);
    if (pRVar13 == (RSA *)0x0) {
      iVar9 = 0x601;
LAB_00048d00:
      iVar8 = 0xf4;
      local_d0 = 10;
      pRVar14 = pRVar13;
      goto LAB_00048d0a;
    }
    r = RSA_new();
    if (r == (RSA *)0x0) {
      ERR_put_error(0x14,0x8d,0x41,"s3_clnt.c",0x605);
      pRVar13 = r;
      dh = r;
      local_dc = r;
      goto LAB_00048950;
    }
    if ((int)pRVar3 < 2) {
      iVar9 = 0x60b;
LAB_00049344:
      ERR_put_error(0x14,0x8d,0xa0,"s3_clnt.c",iVar9);
LAB_00049146:
      ssl3_send_alert(param_1,2,local_d0);
      EVP_PKEY_free((EVP_PKEY *)pRVar14);
    }
    else {
      puVar15 = (uchar *)(pcVar10 + 2);
      uVar11 = (uint)CONCAT11(*pcVar10,pcVar10[1]);
      if ((int)&pRVar3[-1].field_0x56 < (int)uVar11) {
        ERR_put_error(0x14,0x8d,0x79,"s3_clnt.c",0x611);
        goto LAB_00049146;
      }
      pBVar5 = BN_bin2bn(puVar15,uVar11,*(BIGNUM **)&r->field_0x10);
      *(BIGNUM **)&r->field_0x10 = pBVar5;
      if (pBVar5 != (BIGNUM *)0x0) {
        if ((int)((int)pRVar3 - (uVar11 + 2)) < 2) {
          iVar9 = 0x61d;
          goto LAB_00049344;
        }
        uVar16 = (uint)CONCAT11(puVar15[uVar11],puVar15[uVar11 + 1]);
        if ((int)((int)pRVar3 - (uVar11 + 4)) < (int)uVar16) {
          pRVar14 = (RSA *)0x0;
          ERR_put_error(0x14,0x8d,0x78,"s3_clnt.c",0x625);
        }
        else {
          local_d8 = uVar11 + 4 + uVar16;
          pBVar5 = BN_bin2bn(puVar15 + uVar11 + 2,uVar16,*(BIGNUM **)&r->field_0x14);
          *(BIGNUM **)&r->field_0x14 = pBVar5;
          if (pBVar5 == (BIGNUM *)0x0) {
            iVar9 = 0x62b;
            goto LAB_00049404;
          }
          puVar15 = puVar15 + uVar11 + 2 + uVar16;
          pRVar3 = (RSA *)((int)pRVar3 - local_d8);
          if (-1 < (int)(uVar12 << 0x1f)) {
            ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x637);
            goto LAB_000491e6;
          }
          pRVar14 = (RSA *)X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
          iVar9 = EVP_PKEY_bits((EVP_PKEY *)pRVar14);
          if ((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 8) == 0) {
            iVar8 = 0x400;
          }
          else {
            iVar8 = 0x200;
          }
          if (iVar8 < iVar9) {
            *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x6c) = r;
            goto LAB_00048a90;
          }
          local_d0 = 10;
          ERR_put_error(0x14,0x8d,0xf4,"s3_clnt.c",0x63d);
        }
        goto LAB_00049146;
      }
      iVar9 = 0x617;
LAB_00049404:
      ERR_put_error(0x14,0x8d,3,"s3_clnt.c",iVar9);
LAB_000491e6:
      EVP_PKEY_free((EVP_PKEY *)0x0);
    }
    RSA_free(r);
    BN_CTX_free((BN_CTX *)0x0);
    EC_POINT_free((EC_POINT *)0x0);
  }
  else {
    if ((int)pRVar3 < 2) {
      iVar8 = 0x570;
LAB_000491c0:
      iVar9 = 0xa0;
LAB_00048c28:
      pRVar14 = (RSA *)0x0;
LAB_00048c2c:
      ERR_put_error(0x14,0x8d,iVar9,"s3_clnt.c",iVar8);
      pRVar13 = pRVar14;
      dh = pRVar14;
      local_dc = pRVar14;
      local_d4 = pRVar14;
    }
    else {
      uVar11 = (uint)CONCAT11(*pcVar10,pcVar10[1]);
      if (uVar11 < 0x81) {
        if ((int)&pRVar3[-1].field_0x56 < (int)uVar11) {
          iVar8 = 0x582;
          iVar9 = 0x13c;
        }
        else {
          iVar9 = param_1[0x30];
          pcVar10 = BUF_strndup(pcVar10 + 2,uVar11);
          iVar7 = param_1[0x30];
          *(char **)(iVar9 + 0x8c) = pcVar10;
          pRVar14 = (RSA *)((int)pRVar3 - (uVar11 + 2));
          if (*(RSA **)(iVar7 + 0x8c) == (RSA *)0x0) {
            iVar9 = 0x58a;
            iVar8 = 0x41;
            local_d0 = 0x28;
            pRVar14 = *(RSA **)(iVar7 + 0x8c);
            goto LAB_00048d0a;
          }
LAB_000487b2:
          if (pRVar14 == (RSA *)0x0) goto LAB_000487bc;
          iVar8 = 0x79d;
          iVar9 = 0x99;
        }
        goto LAB_00048c28;
      }
      iVar9 = 0x57d;
      iVar8 = 0x92;
      local_d0 = 0x28;
      pRVar14 = (RSA *)0x0;
LAB_00048d0a:
      ERR_put_error(0x14,0x8d,iVar8,"s3_clnt.c",iVar9);
      pRVar13 = pRVar14;
      dh = pRVar14;
      local_dc = pRVar14;
      local_d4 = pRVar14;
    }
LAB_00048c04:
    ssl3_send_alert(param_1,2,local_d0);
    EVP_PKEY_free((EVP_PKEY *)pRVar14);
LAB_0004895a:
    if (dh != (RSA *)0x0) {
      DH_free((DH *)dh);
    }
    BN_CTX_free((BN_CTX *)local_d4);
    EC_POINT_free((EC_POINT *)pRVar13);
    if (local_dc != (RSA *)0x0) {
      EC_KEY_free((EC_KEY *)local_dc);
    }
  }
  EVP_MD_CTX_cleanup(&EStack_c4);
  pRVar3 = (RSA *)0xffffffff;
  param_1[0xd] = 5;
LAB_000486ec:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pRVar3);
  }
  return;
}

