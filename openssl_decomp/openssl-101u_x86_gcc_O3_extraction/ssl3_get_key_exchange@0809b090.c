
int ssl3_get_key_exchange(int *param_1)

{
  byte *pbVar1;
  ushort *d;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  RSA *r;
  BIGNUM *pBVar7;
  EVP_MD *type;
  EC_GROUP *pEVar8;
  ushort *puVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  EC_KEY *key;
  uchar *md;
  int in_GS_OFFSET;
  int iVar13;
  EVP_PKEY *local_e8;
  uint local_e0;
  size_t local_dc;
  DH *local_d8;
  EVP_MD *local_d4;
  BN_CTX *local_d0;
  undefined4 local_c4;
  int local_c0;
  uint local_bc;
  EVP_MD_CTX local_b8;
  uchar local_a0 [128];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_b8);
  iVar3 = (**(code **)(param_1[2] + 0x30))(param_1,0x1140,0x1141,0xffffffff,param_1[0x42],&local_c0)
  ;
  if (local_c0 == 0) goto LAB_0809b123;
  iVar13 = param_1[0x16];
  uVar11 = *(uint *)(*(int *)(iVar13 + 0x344) + 0xc);
  if (*(int *)(iVar13 + 0x340) == 0xc) {
    d = (ushort *)param_1[0x10];
    iVar13 = param_1[0x30];
    iVar4 = *(int *)(iVar13 + 0x98);
    if (iVar4 == 0) {
      uVar6 = ssl_sess_cert_new();
      *(undefined4 *)(iVar13 + 0x98) = uVar6;
    }
    else {
      if (*(RSA **)(iVar4 + 0x6c) != (RSA *)0x0) {
        RSA_free(*(RSA **)(iVar4 + 0x6c));
        iVar4 = *(int *)(param_1[0x30] + 0x98);
        *(undefined4 *)(iVar4 + 0x6c) = 0;
      }
      if (*(DH **)(iVar4 + 0x70) != (DH *)0x0) {
        DH_free(*(DH **)(iVar4 + 0x70));
        iVar4 = *(int *)(param_1[0x30] + 0x98);
        *(undefined4 *)(iVar4 + 0x70) = 0;
      }
      if (*(EC_KEY **)(iVar4 + 0x74) != (EC_KEY *)0x0) {
        EC_KEY_free(*(EC_KEY **)(iVar4 + 0x74));
        *(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x74) = 0;
      }
    }
    local_c4 = 0x32;
    uVar2 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x10);
    if ((uVar11 & 0x100) != 0) {
      if (iVar3 < 2) {
        iVar13 = 0x570;
        iVar3 = 0xa0;
      }
      else {
        uVar10 = *d << 8 | *d >> 8;
        uVar11 = (uint)uVar10;
        if (uVar10 < 0x81) {
          if (iVar3 + -2 < (int)uVar11) {
            iVar13 = 0x582;
            iVar3 = 0x13c;
          }
          else {
            iVar13 = param_1[0x30];
            pcVar5 = BUF_strndup((char *)(d + 1),uVar11);
            *(char **)(iVar13 + 0x8c) = pcVar5;
            if (*(int *)(param_1[0x30] + 0x8c) == 0) {
              local_c4 = 0x28;
              iVar13 = 0x58a;
              iVar3 = 0x41;
            }
            else {
              iVar3 = iVar3 - (uVar11 + 2);
LAB_0809b268:
              if (iVar3 == 0) {
                local_e8 = (EVP_PKEY *)0x0;
                goto LAB_0809b5b5;
              }
              iVar13 = 0x79d;
              iVar3 = 0x99;
            }
          }
        }
        else {
          local_c4 = 0x28;
          iVar13 = 0x57d;
          iVar3 = 0x92;
        }
      }
LAB_0809b850:
      ERR_put_error(0x14,0x8d,iVar3,"s3_clnt.c",iVar13);
      goto LAB_0809b863;
    }
    if ((uVar11 & 0x400) != 0) {
      if (iVar3 < 2) {
        iVar13 = 0x596;
        iVar3 = 0xa0;
      }
      else {
        uVar11 = (uint)(ushort)(*d << 8 | *d >> 8);
        if (iVar3 + -2 < (int)uVar11) {
          iVar13 = 0x59c;
          iVar3 = 0x15e;
        }
        else {
          pBVar7 = BN_bin2bn((uchar *)(d + 1),uVar11,(BIGNUM *)0x0);
          param_1[0x6a] = (int)pBVar7;
          if (pBVar7 == (BIGNUM *)0x0) {
            iVar13 = 0x5a2;
            iVar3 = 3;
LAB_0809b798:
            key = (EC_KEY *)0x0;
            ERR_put_error(0x14,0x8d,iVar3,"s3_clnt.c",iVar13);
            local_d4 = (EVP_MD *)0x0;
            local_d8 = (DH *)0x0;
            local_e8 = (EVP_PKEY *)0x0;
            goto LAB_0809b7c1;
          }
          puVar9 = (ushort *)((int)(d + 1) + uVar11);
          if ((int)(iVar3 - (uVar11 + 2)) < 2) {
            iVar13 = 0x5a8;
            iVar3 = 0xa0;
          }
          else {
            uVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            uVar12 = (uint)(ushort)(uVar10 << 8 | uVar10 >> 8);
            if ((int)(iVar3 - (uVar11 + 4)) < (int)uVar12) {
              iVar13 = 0x5b0;
              iVar3 = 0x15d;
            }
            else {
              iVar13 = uVar11 + 4 + uVar12;
              pBVar7 = BN_bin2bn((uchar *)puVar9,uVar12,(BIGNUM *)0x0);
              param_1[0x6b] = (int)pBVar7;
              if (pBVar7 == (BIGNUM *)0x0) {
                iVar13 = 0x5b6;
                iVar3 = 3;
                goto LAB_0809b798;
              }
              pbVar1 = (byte *)((int)puVar9 + uVar12);
              if (iVar3 == iVar13 || iVar3 - iVar13 < 0) {
                iVar13 = 0x5bc;
                iVar3 = 0xa0;
              }
              else {
                uVar11 = (uint)*pbVar1;
                pbVar1 = pbVar1 + 1;
                if (iVar3 - (iVar13 + 1) < (int)uVar11) {
                  iVar13 = 0x5c5;
                  iVar3 = 0x15f;
                }
                else {
                  iVar13 = iVar13 + 1 + uVar11;
                  pBVar7 = BN_bin2bn(pbVar1,uVar11,(BIGNUM *)0x0);
                  param_1[0x6c] = (int)pBVar7;
                  if (pBVar7 == (BIGNUM *)0x0) {
                    iVar13 = 0x5cb;
                    iVar3 = 3;
                    goto LAB_0809b798;
                  }
                  puVar9 = (ushort *)(pbVar1 + uVar11);
                  if (iVar3 - iVar13 < 2) {
                    iVar13 = 0x5d1;
                    iVar3 = 0xa0;
                  }
                  else {
                    iVar13 = iVar13 + 2;
                    uVar11 = (uint)(ushort)(*puVar9 << 8 | *puVar9 >> 8);
                    if (iVar3 - iVar13 < (int)uVar11) {
                      iVar13 = 0x5d9;
                      iVar3 = 0x15c;
                    }
                    else {
                      local_dc = iVar13 + uVar11;
                      pBVar7 = BN_bin2bn((uchar *)(puVar9 + 1),uVar11,(BIGNUM *)0x0);
                      param_1[0x6d] = (int)pBVar7;
                      if (pBVar7 == (BIGNUM *)0x0) {
                        iVar13 = 0x5df;
                        iVar3 = 3;
                        goto LAB_0809b798;
                      }
                      puVar9 = (ushort *)((int)(puVar9 + 1) + uVar11);
                      iVar3 = iVar3 - local_dc;
                      iVar13 = srp_verify_server_param(param_1,&local_c4);
                      if (iVar13 != 0) {
                        if ((uVar2 & 1) == 0) {
                          if ((uVar2 & 2) == 0) goto LAB_0809b77b;
                          local_e8 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) +
                                                               0x24));
                        }
                        else {
                          local_e8 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc
                                                               ));
                        }
LAB_0809b436:
                        if (local_e8 == (EVP_PKEY *)0x0) goto LAB_0809b77b;
                        if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
                          if (iVar3 < 2) {
                            iVar13 = 0x72c;
                            iVar3 = 0xa0;
                          }
                          else {
                            uVar11 = tls12_get_sigid(local_e8);
                            if (uVar11 == 0xffffffff) {
                              key = (EC_KEY *)0x0;
                              ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x733);
                              local_d4 = (EVP_MD *)0x0;
                              local_d8 = (DH *)0x0;
                              goto LAB_0809b7c1;
                            }
                            if (uVar11 != *(byte *)((int)puVar9 + 1)) {
                              key = (EC_KEY *)0x0;
                              ERR_put_error(0x14,0x8d,0x172,"s3_clnt.c",0x739);
                              local_c4 = 0x32;
                              local_d4 = (EVP_MD *)0x0;
                              local_d0 = (BN_CTX *)0x0;
                              local_d8 = (DH *)0x0;
                              goto LAB_0809b885;
                            }
                            local_d4 = (EVP_MD *)tls12_get_hash(*(byte *)puVar9);
                            if (local_d4 != (EVP_MD *)0x0) {
                              puVar9 = puVar9 + 1;
                              iVar3 = iVar3 + -2;
                              goto LAB_0809b4bc;
                            }
                            iVar13 = 0x73f;
                            iVar3 = 0x170;
                          }
                        }
                        else {
                          local_d4 = EVP_sha1();
LAB_0809b4bc:
                          if (iVar3 < 2) {
                            iVar13 = 0x74b;
                            iVar3 = 0xa0;
                          }
                          else {
                            uVar10 = *puVar9;
                            uVar11 = iVar3 - 2;
                            iVar3 = EVP_PKEY_size(local_e8);
                            if (((ushort)(uVar10 << 8 | uVar10 >> 8) == uVar11 && 0 < (int)uVar11)
                               && ((int)uVar11 <= iVar3)) {
                              if ((local_e8->type == 6) &&
                                 ((*param_1 >> 8 != 3 || (*param_1 < 0x303)))) {
                                md = local_a0;
                                local_e0 = 0;
                                iVar3 = 2;
                                do {
                                  EVP_MD_CTX_set_flags(&local_b8,8);
                                  if (iVar3 == 2) {
                                    type = *(EVP_MD **)(param_1[0x39] + 0x8c);
                                  }
                                  else {
                                    type = *(EVP_MD **)(param_1[0x39] + 0x90);
                                  }
                                  iVar13 = EVP_DigestInit_ex(&local_b8,type,(ENGINE *)0x0);
                                  if (iVar13 < 1) {
LAB_0809bacf:
                                    ERR_put_error(0x14,0x8d,0x44,"s3_clnt.c",0x76e);
                                    local_c4 = 0x50;
                                    goto LAB_0809b9fb;
                                  }
                                  iVar13 = EVP_DigestUpdate(&local_b8,(void *)(param_1[0x16] + 0xc0)
                                                            ,0x20);
                                  if (iVar13 < 1) goto LAB_0809bacf;
                                  iVar13 = EVP_DigestUpdate(&local_b8,(void *)(param_1[0x16] + 0xa0)
                                                            ,0x20);
                                  if (iVar13 < 1) goto LAB_0809bacf;
                                  iVar13 = EVP_DigestUpdate(&local_b8,d,local_dc);
                                  if (iVar13 < 1) goto LAB_0809bacf;
                                  iVar13 = EVP_DigestFinal_ex(&local_b8,md,&local_bc);
                                  if (iVar13 < 1) goto LAB_0809bacf;
                                  local_e0 = local_e0 + local_bc;
                                  md = md + local_bc;
                                  iVar3 = iVar3 + -1;
                                } while (iVar3 != 0);
                                iVar3 = RSA_verify(0x72,local_a0,local_e0,(uchar *)(puVar9 + 1),
                                                   uVar11,(local_e8->pkey).rsa);
                                if (iVar3 < 0) {
                                  local_c4 = 0x33;
                                  iVar13 = 0x778;
                                  iVar3 = 0x76;
                                }
                                else {
                                  if (iVar3 != 0) {
LAB_0809b5b5:
                                    EVP_PKEY_free(local_e8);
                                    EVP_MD_CTX_cleanup(&local_b8);
                                    iVar3 = 1;
                                    goto LAB_0809b123;
                                  }
                                  local_c4 = 0x33;
                                  iVar13 = 0x77e;
                                  iVar3 = 0x7b;
                                }
                              }
                              else {
                                iVar3 = EVP_DigestInit_ex(&local_b8,local_d4,(ENGINE *)0x0);
                                if (0 < iVar3) {
                                  iVar3 = EVP_DigestUpdate(&local_b8,(void *)(param_1[0x16] + 0xc0),
                                                           0x20);
                                  if (0 < iVar3) {
                                    iVar3 = EVP_DigestUpdate(&local_b8,
                                                             (void *)(param_1[0x16] + 0xa0),0x20);
                                    if (0 < iVar3) {
                                      iVar3 = EVP_DigestUpdate(&local_b8,d,local_dc);
                                      if (0 < iVar3) {
                                        iVar3 = EVP_VerifyFinal(&local_b8,(uchar *)(puVar9 + 1),
                                                                uVar11,local_e8);
                                        if (0 < iVar3) goto LAB_0809b5b5;
                                        local_c4 = 0x33;
                                        iVar13 = 0x791;
                                        iVar3 = 0x7b;
                                        goto LAB_0809b9e8;
                                      }
                                    }
                                  }
                                }
                                local_c4 = 0x50;
                                iVar13 = 0x78b;
                                iVar3 = 6;
                              }
                            }
                            else {
                              iVar13 = 0x757;
                              iVar3 = 0x108;
                            }
                          }
                        }
LAB_0809b9e8:
                        ERR_put_error(0x14,0x8d,iVar3,"s3_clnt.c",iVar13);
LAB_0809b9fb:
                        local_d4 = (EVP_MD *)0x0;
                        local_d0 = (BN_CTX *)0x0;
                        key = (EC_KEY *)0x0;
                        local_d8 = (DH *)0x0;
                        goto LAB_0809b885;
                      }
                      iVar13 = 0x5e6;
                      iVar3 = 0x173;
                    }
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_0809b850;
    }
    if ((uVar11 & 1) == 0) {
      if ((uVar11 & 8) == 0) {
        if ((uVar11 & 6) == 0) {
          if ((uVar11 & 0x80) != 0) {
            key = EC_KEY_new();
            if (key == (EC_KEY *)0x0) {
              iVar13 = 0x6bb;
              iVar3 = 0x41;
LAB_0809c4be:
              ERR_put_error(0x14,0x8d,iVar3,"s3_clnt.c",iVar13);
              local_d4 = (EVP_MD *)0x0;
              local_d8 = (DH *)0x0;
              local_e8 = (EVP_PKEY *)0x0;
              goto LAB_0809b7c1;
            }
            if (iVar3 < 4) {
              iVar13 = 0x6cc;
              iVar3 = 0xa0;
            }
            else {
              if (*(char *)d == '\x03') {
                iVar13 = tls1_ec_curve_id2nid(*(char *)(d + 1));
                if (iVar13 != 0) {
                  pEVar8 = EC_GROUP_new_by_curve_name(iVar13);
                  if (pEVar8 == (EC_GROUP *)0x0) {
                    iVar13 = 0x6da;
                  }
                  else {
                    iVar13 = EC_KEY_set_group(key,pEVar8);
                    if (iVar13 != 0) {
                      EC_GROUP_free(pEVar8);
                      pEVar8 = EC_KEY_get0_group(key);
                      if ((*(byte *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) != 0) {
                        iVar13 = EC_GROUP_get_degree(pEVar8);
                        if (0xa3 < iVar13) {
                          local_c4 = 0x3c;
                          iVar13 = 0x6e9;
                          iVar3 = 0x136;
                          goto LAB_0809c0aa;
                        }
                      }
                      local_d4 = (EVP_MD *)EC_POINT_new(pEVar8);
                      if (local_d4 != (EVP_MD *)0x0) {
                        local_d0 = BN_CTX_new();
                        if (local_d0 != (BN_CTX *)0x0) {
                          uVar11 = (uint)*(byte *)((int)d + 3);
                          if ((int)uVar11 <= iVar3 + -4) {
                            iVar13 = EC_POINT_oct2point(pEVar8,(EC_POINT *)local_d4,(uchar *)(d + 2)
                                                        ,uVar11,local_d0);
                            if (iVar13 != 0) {
                              local_dc = uVar11 + 4;
                              puVar9 = (ushort *)(uVar11 + (int)(d + 2));
                              iVar3 = iVar3 - local_dc;
                              if ((uVar2 & 1) == 0) {
                                local_e8 = (EVP_PKEY *)0x0;
                                if ((uVar2 & 0x40) != 0) {
                                  local_e8 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] +
                                                                                0x98) + 0x48));
                                }
                              }
                              else {
                                local_e8 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98)
                                                                     + 0xc));
                              }
                              EC_KEY_set_public_key(key,(EC_POINT *)local_d4);
                              *(EC_KEY **)(*(int *)(param_1[0x30] + 0x98) + 0x74) = key;
                              BN_CTX_free(local_d0);
                              EC_POINT_free((EC_POINT *)local_d4);
                              goto LAB_0809b436;
                            }
                          }
                          ERR_put_error(0x14,0x8d,0x132,"s3_clnt.c",0x6fc);
                          local_d8 = (DH *)0x0;
                          local_e8 = (EVP_PKEY *)0x0;
                          goto LAB_0809b885;
                        }
                      }
                      ERR_put_error(0x14,0x8d,0x41,"s3_clnt.c",0x6f2);
                      local_d8 = (DH *)0x0;
                      local_e8 = (EVP_PKEY *)0x0;
                      goto LAB_0809b7c1;
                    }
                    iVar13 = 0x6de;
                  }
                  iVar3 = 0x10;
                  goto LAB_0809c4be;
                }
              }
              local_c4 = 0x50;
              iVar13 = 0x6d4;
              iVar3 = 0x13a;
            }
LAB_0809c0aa:
            ERR_put_error(0x14,0x8d,iVar3,"s3_clnt.c",iVar13);
            local_d4 = (EVP_MD *)0x0;
            local_d0 = (BN_CTX *)0x0;
            local_d8 = (DH *)0x0;
            local_e8 = (EVP_PKEY *)0x0;
            goto LAB_0809b885;
          }
          if (uVar11 == 0) {
LAB_0809b77b:
            if ((uVar2 & 0x404) != 0) goto LAB_0809b268;
            iVar13 = 0x798;
            iVar3 = 0x44;
            goto LAB_0809b798;
          }
          local_c4 = 10;
          iVar13 = 0x720;
          iVar3 = 0xf4;
        }
        else {
          local_c4 = 0x2f;
          iVar13 = 0x6b0;
          iVar3 = 0xeb;
        }
        goto LAB_0809b850;
      }
      local_d8 = DH_new();
      if (local_d8 != (DH *)0x0) {
        if (iVar3 < 2) {
          iVar13 = 0x650;
          iVar3 = 0xa0;
        }
        else {
          uVar11 = (uint)(ushort)(*d << 8 | *d >> 8);
          if (iVar3 + -2 < (int)uVar11) {
            iVar13 = 0x656;
            iVar3 = 0x6e;
          }
          else {
            pBVar7 = BN_bin2bn((uchar *)(d + 1),uVar11,(BIGNUM *)0x0);
            *(BIGNUM **)&local_d8->field_0x8 = pBVar7;
            if (pBVar7 == (BIGNUM *)0x0) {
              iVar13 = 0x65c;
LAB_0809c574:
              iVar3 = 3;
              goto LAB_0809c57b;
            }
            puVar9 = (ushort *)((int)(d + 1) + uVar11);
            if (pBVar7->top == 0) {
              iVar13 = 0x662;
              iVar3 = 0x18b;
            }
            else if ((int)(iVar3 - (uVar11 + 2)) < 2) {
              iVar13 = 0x668;
              iVar3 = 0xa0;
            }
            else {
              uVar10 = *puVar9;
              puVar9 = puVar9 + 1;
              uVar12 = (uint)(ushort)(uVar10 << 8 | uVar10 >> 8);
              if ((int)(iVar3 - (uVar11 + 4)) < (int)uVar12) {
                iVar13 = 0x670;
                iVar3 = 0x6c;
              }
              else {
                iVar13 = uVar11 + 4 + uVar12;
                pBVar7 = BN_bin2bn((uchar *)puVar9,uVar12,(BIGNUM *)0x0);
                *(BIGNUM **)&local_d8->field_0xc = pBVar7;
                if (pBVar7 == (BIGNUM *)0x0) {
                  iVar13 = 0x676;
                  goto LAB_0809c574;
                }
                puVar9 = (ushort *)(uVar12 + (int)puVar9);
                if (pBVar7->top == 0) {
                  iVar13 = 0x67c;
                  iVar3 = 0x177;
                }
                else if (iVar3 - iVar13 < 2) {
                  iVar13 = 0x681;
                  iVar3 = 0xa0;
                }
                else {
                  iVar13 = iVar13 + 2;
                  uVar10 = *puVar9;
                  puVar9 = puVar9 + 1;
                  uVar11 = (uint)(ushort)(uVar10 << 8 | uVar10 >> 8);
                  if (iVar3 - iVar13 < (int)uVar11) {
                    iVar13 = 0x689;
                    iVar3 = 0x6d;
                  }
                  else {
                    local_dc = iVar13 + uVar11;
                    pBVar7 = BN_bin2bn((uchar *)puVar9,uVar11,(BIGNUM *)0x0);
                    *(BIGNUM **)&local_d8->field_0x14 = pBVar7;
                    if (pBVar7 == (BIGNUM *)0x0) {
                      iVar13 = 0x68f;
                      goto LAB_0809c574;
                    }
                    iVar3 = iVar3 - local_dc;
                    puVar9 = (ushort *)((int)puVar9 + uVar11);
                    if (pBVar7->top != 0) {
                      if ((uVar2 & 1) == 0) {
                        local_e8 = (EVP_PKEY *)0x0;
                        if ((uVar2 & 2) != 0) {
                          local_e8 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) +
                                                               0x24));
                        }
                      }
                      else {
                        local_e8 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc))
                        ;
                      }
                      *(DH **)(*(int *)(param_1[0x30] + 0x98) + 0x70) = local_d8;
                      goto LAB_0809b436;
                    }
                    iVar13 = 0x696;
                    iVar3 = 0x189;
                  }
                }
              }
            }
          }
        }
        key = (EC_KEY *)0x0;
        ERR_put_error(0x14,0x8d,iVar3,"s3_clnt.c",iVar13);
        local_d4 = (EVP_MD *)0x0;
        local_d0 = (BN_CTX *)0x0;
        local_e8 = (EVP_PKEY *)0x0;
        goto LAB_0809b885;
      }
      iVar13 = 0x64a;
      iVar3 = 5;
LAB_0809c57b:
      key = (EC_KEY *)0x0;
      ERR_put_error(0x14,0x8d,iVar3,"s3_clnt.c",iVar13);
      local_d4 = (EVP_MD *)0x0;
      local_e8 = (EVP_PKEY *)0x0;
LAB_0809b7c1:
      EVP_PKEY_free(local_e8);
      local_d0 = (BN_CTX *)0x0;
      goto LAB_0809b7e0;
    }
    if ((*(byte *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) == 0) {
      local_c4 = 10;
      iVar13 = 0x601;
      iVar3 = 0xf4;
      goto LAB_0809b850;
    }
    r = RSA_new();
    if (r == (RSA *)0x0) {
      iVar13 = 0x605;
      iVar3 = 0x41;
      goto LAB_0809b798;
    }
    if (iVar3 < 2) {
      iVar13 = 0x60b;
      iVar3 = 0xa0;
LAB_0809c028:
      ERR_put_error(0x14,0x8d,iVar3,"s3_clnt.c",iVar13);
      local_e8 = (EVP_PKEY *)0x0;
LAB_0809c043:
      ssl3_send_alert(param_1,2,local_c4);
      EVP_PKEY_free(local_e8);
    }
    else {
      uVar11 = (uint)(ushort)(*d << 8 | *d >> 8);
      if (iVar3 + -2 < (int)uVar11) {
        iVar13 = 0x611;
        iVar3 = 0x79;
        goto LAB_0809c028;
      }
      pBVar7 = BN_bin2bn((uchar *)(d + 1),uVar11,*(BIGNUM **)&r->field_0x10);
      *(BIGNUM **)&r->field_0x10 = pBVar7;
      if (pBVar7 == (BIGNUM *)0x0) {
        iVar13 = 0x617;
        iVar3 = 3;
        goto LAB_0809c10d;
      }
      puVar9 = (ushort *)((int)(d + 1) + uVar11);
      if ((int)(iVar3 - (uVar11 + 2)) < 2) {
        iVar13 = 0x61d;
        iVar3 = 0xa0;
        goto LAB_0809c028;
      }
      uVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      uVar12 = (uint)(ushort)(uVar10 << 8 | uVar10 >> 8);
      if ((int)(iVar3 - (uVar11 + 4)) < (int)uVar12) {
        iVar13 = 0x625;
        iVar3 = 0x78;
        goto LAB_0809c028;
      }
      local_dc = uVar11 + 4 + uVar12;
      pBVar7 = BN_bin2bn((uchar *)puVar9,uVar12,*(BIGNUM **)&r->field_0x14);
      *(BIGNUM **)&r->field_0x14 = pBVar7;
      if (pBVar7 != (BIGNUM *)0x0) {
        iVar3 = iVar3 - local_dc;
        puVar9 = (ushort *)((int)puVar9 + uVar12);
        if ((uVar2 & 1) == 0) {
          iVar13 = 0x637;
          iVar3 = 0x44;
          goto LAB_0809c10d;
        }
        local_e8 = X509_get_pubkey(*(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xc));
        iVar13 = EVP_PKEY_bits(local_e8);
        if ((int)((-(uint)((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 8) == 0) & 0x200) +
                 0x200) < iVar13) {
          *(RSA **)(*(int *)(param_1[0x30] + 0x98) + 0x6c) = r;
          goto LAB_0809b436;
        }
        local_c4 = 10;
        ERR_put_error(0x14,0x8d,0xf4,"s3_clnt.c",0x63d);
        goto LAB_0809c043;
      }
      iVar13 = 0x62b;
      iVar3 = 3;
LAB_0809c10d:
      ERR_put_error(0x14,0x8d,iVar3,"s3_clnt.c",iVar13);
      EVP_PKEY_free((EVP_PKEY *)0x0);
    }
    RSA_free(r);
    BN_CTX_free((BN_CTX *)0x0);
    EC_POINT_free((EC_POINT *)0x0);
  }
  else {
    if ((uVar11 & 0x88) == 0) {
      if ((uVar11 & 0x100) != 0) {
        iVar3 = param_1[0x30];
        uVar6 = ssl_sess_cert_new();
        *(undefined4 *)(iVar3 + 0x98) = uVar6;
        iVar3 = param_1[0x39];
        if (*(void **)(iVar3 + 0x14c) != (void *)0x0) {
          CRYPTO_free(*(void **)(iVar3 + 0x14c));
          iVar3 = param_1[0x39];
        }
        *(undefined4 *)(iVar3 + 0x14c) = 0;
        iVar13 = param_1[0x16];
      }
      *(undefined4 *)(iVar13 + 0x354) = 1;
      iVar3 = 1;
      goto LAB_0809b123;
    }
    ERR_put_error(0x14,0x8d,0xf4,"s3_clnt.c",0x538);
    local_c4 = 10;
LAB_0809b863:
    local_d4 = (EVP_MD *)0x0;
    local_d0 = (BN_CTX *)0x0;
    key = (EC_KEY *)0x0;
    local_d8 = (DH *)0x0;
    local_e8 = (EVP_PKEY *)0x0;
LAB_0809b885:
    ssl3_send_alert(param_1,2,local_c4);
    EVP_PKEY_free(local_e8);
LAB_0809b7e0:
    if (local_d8 != (DH *)0x0) {
      DH_free(local_d8);
    }
    BN_CTX_free(local_d0);
    EC_POINT_free((EC_POINT *)local_d4);
    if (key != (EC_KEY *)0x0) {
      EC_KEY_free(key);
    }
  }
  EVP_MD_CTX_cleanup(&local_b8);
  param_1[0xd] = 5;
  iVar3 = -1;
LAB_0809b123:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

