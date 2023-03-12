
void ssl3_send_server_key_exchange(int *param_1)

{
  EVP_PKEY *pEVar1;
  BN_CTX *ctx;
  undefined4 uVar2;
  EC_KEY *pEVar3;
  EC_POINT *pEVar4;
  BIGNUM *pBVar5;
  EC_GROUP *group;
  size_t sVar6;
  DH *pDVar7;
  EVP_PKEY *pkey;
  uchar *d;
  EVP_MD *type;
  int iVar8;
  undefined *puVar9;
  RSA *pRVar10;
  int iVar11;
  uint uVar12;
  BUF_MEM *str;
  undefined *puVar13;
  int iVar14;
  RSA *pRVar15;
  char *__s;
  uchar *puVar16;
  RSA *pRVar17;
  RSA *pRVar18;
  uchar *puVar19;
  int *local_ac;
  RSA *local_a8;
  RSA *local_a0;
  RSA *local_9c;
  uint local_94;
  EVP_MD *local_90;
  RSA *local_8c;
  RSA *local_88;
  int local_84;
  int local_80;
  int local_7c;
  int aiStack_78 [4];
  EVP_MD_CTX EStack_68;
  uchar auStack_50 [36];
  int local_2c;
  
  local_90 = (EVP_MD *)0x0;
  local_2c = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_68);
  if (param_1[0xd] != 0x2150) {
LAB_00045086:
    param_1[0xd] = 0x2151;
    EVP_MD_CTX_cleanup(&EStack_68);
    uVar2 = ssl3_do_write(param_1,0x16);
    goto LAB_0004509a;
  }
  iVar11 = param_1[0x16];
  local_7c = 0;
  local_80 = 0;
  iVar8 = *(int *)(iVar11 + 0x344);
  local_84 = 0;
  local_88 = (RSA *)0x0;
  uVar12 = *(uint *)(iVar8 + 0xc);
  iVar14 = param_1[0x26];
  str = (BUF_MEM *)param_1[0xf];
  if ((int)(uVar12 << 0x1f) < 0) {
    local_a0 = *(RSA **)(iVar14 + 0x18);
    if (local_a0 == (RSA *)0x0) {
      local_a0 = *(RSA **)(iVar14 + 0x1c);
      if (local_a0 == (RSA *)0x0) {
        ERR_put_error(0x14,0x9b,0xac,"s3_srvr.c",0x6a0);
        uVar2 = 0x28;
      }
      else {
        if ((*(uint *)(iVar8 + 0x20) & 8) == 0) {
          uVar2 = 0x400;
        }
        else {
          uVar2 = 0x200;
        }
        local_a0 = (RSA *)(*(code *)local_a0)(param_1,*(uint *)(iVar8 + 0x20) & 2,uVar2);
        if (local_a0 != (RSA *)0x0) {
          RSA_up_ref(local_a0);
          *(RSA **)(iVar14 + 0x18) = local_a0;
          iVar11 = param_1[0x16];
          goto LAB_00044e9c;
        }
        ERR_put_error(0x14,0x9b,0x11a,"s3_srvr.c",0x697);
        uVar2 = 0x28;
      }
      goto LAB_0004533c;
    }
LAB_00044e9c:
    pRVar15 = *(RSA **)&local_a0->field_0x10;
    local_84 = *(int *)&local_a0->field_0x14;
    *(undefined4 *)(iVar11 + 0x370) = 1;
LAB_00044eae:
    local_8c = (RSA *)0x0;
    pRVar10 = pRVar15;
    local_88 = pRVar15;
    if (pRVar15 == (RSA *)0x0) {
      iVar11 = param_1[0x16];
      local_a8 = pRVar15;
      local_a0 = pRVar15;
      local_9c = pRVar15;
    }
    else {
      pRVar17 = (RSA *)(uVar12 & 0x400);
      pRVar18 = pRVar17;
      iVar11 = local_84;
      iVar8 = local_80;
      iVar14 = local_7c;
      if (pRVar17 == (RSA *)0x0) {
        do {
          iVar8 = BN_num_bits((BIGNUM *)pRVar15);
          puVar13 = &local_8c->field_0x1;
          iVar11 = iVar8 + 7;
          if (iVar8 + 7 < 0) {
            iVar11 = iVar8 + 0xe;
          }
          aiStack_78[(int)pRVar18] = iVar11 >> 3;
          pRVar17 = (RSA *)(&pRVar17->field_0x2 + aiStack_78[(int)local_8c]);
          local_8c = (RSA *)puVar13;
        } while (((int)puVar13 < 4) &&
                (pRVar15 = (&local_88)[(int)puVar13], pRVar18 = (RSA *)puVar13,
                pRVar15 != (RSA *)0x0));
      }
      else {
LAB_0004522a:
        local_7c = iVar14;
        local_80 = iVar8;
        local_84 = iVar11;
        local_88 = pRVar15;
        pRVar10 = local_88;
        local_8c = (RSA *)0x0;
        pRVar17 = (RSA *)0x0;
        pRVar15 = local_88;
        do {
          pRVar18 = local_8c;
          iVar8 = BN_num_bits((BIGNUM *)pRVar15);
          iVar11 = iVar8 + 7;
          if (iVar8 + 7 < 0) {
            iVar11 = iVar8 + 0xe;
          }
          aiStack_78[(int)pRVar18] = iVar11 >> 3;
          if (local_8c == (RSA *)0x2) {
            local_8c = (RSA *)0x3;
            pRVar17 = (RSA *)(&pRVar17->field_0x1 + aiStack_78[2]);
          }
          else {
            puVar13 = &local_8c->field_0x1;
            pRVar17 = (RSA *)(&pRVar17->field_0x2 + aiStack_78[(int)local_8c]);
            local_8c = (RSA *)puVar13;
            if (3 < (int)puVar13) break;
          }
          pRVar15 = (&local_88)[(int)local_8c];
        } while (pRVar15 != (RSA *)0x0);
      }
      iVar11 = param_1[0x16];
      local_a8 = (RSA *)0x0;
      local_9c = (RSA *)0x0;
      local_a0 = (RSA *)0x0;
      pRVar15 = pRVar17;
    }
LAB_00044f12:
    iVar11 = *(int *)(iVar11 + 0x344);
    pEVar1 = (EVP_PKEY *)(*(uint *)(iVar11 + 0x10) & 0x404);
    if (pEVar1 == (EVP_PKEY *)0x0) {
      pkey = pEVar1;
      if (-1 < *(int *)(iVar11 + 0xc) << 0x17) {
        pkey = (EVP_PKEY *)ssl_get_sign_pkey(param_1,iVar11,&local_90);
        if (pkey == (EVP_PKEY *)0x0) {
          uVar2 = 0x32;
          goto LAB_0004533c;
        }
        pEVar1 = (EVP_PKEY *)EVP_PKEY_size(pkey);
      }
    }
    else {
      pEVar1 = (EVP_PKEY *)0x0;
      pkey = (EVP_PKEY *)0x0;
    }
    local_ac = (int *)&pRVar15->field_0x4;
    ctx = (BN_CTX *)BUF_MEM_grow_clean(str,(int)&pEVar1->type + (int)local_ac);
    if (ctx != (BN_CTX *)0x0) {
      local_8c = (RSA *)0x0;
      puVar13 = *(undefined **)(param_1[0xf] + 4);
      d = puVar13 + 4;
      puVar19 = d;
      if (pRVar10 != (RSA *)0x0) {
        puVar9 = (undefined *)(uVar12 & 0x400);
        if (puVar9 == (undefined *)0x0) {
          do {
            *puVar19 = (uchar)((uint)aiStack_78[(int)puVar9] >> 8);
            puVar19[1] = (uchar)aiStack_78[(int)local_8c];
            BN_bn2bin((BIGNUM *)(&local_88)[(int)local_8c],puVar19 + 2);
            puVar9 = &local_8c->field_0x1;
            puVar19 = puVar19 + 2 + aiStack_78[(int)local_8c];
            local_8c = (RSA *)puVar9;
            if (3 < (int)puVar9) break;
          } while ((&local_88)[(int)puVar9] != (RSA *)0x0);
        }
        else {
          do {
            if (local_8c == (RSA *)0x2) {
              puVar16 = puVar19 + 1;
              *puVar19 = (uchar)aiStack_78[2];
            }
            else {
              puVar16 = puVar19 + 2;
              *puVar19 = (uchar)((uint)aiStack_78[(int)local_8c] >> 8);
              puVar19[1] = (uchar)aiStack_78[(int)local_8c];
            }
            BN_bn2bin((BIGNUM *)(&local_88)[(int)local_8c],puVar16);
            puVar9 = &local_8c->field_0x1;
            puVar19 = puVar16 + aiStack_78[(int)local_8c];
            local_8c = (RSA *)puVar9;
          } while (((int)puVar9 < 4) && ((&local_88)[(int)puVar9] != (RSA *)0x0));
        }
      }
      if ((int)(uVar12 << 0x18) < 0) {
        puVar19[2] = (uchar)local_a8;
        puVar19[3] = (uchar)local_9c;
        *puVar19 = '\x03';
        puVar19[1] = '\0';
        memcpy(puVar19 + 4,local_a0,(size_t)local_9c);
        CRYPTO_free(local_a0);
        local_a0 = (RSA *)0x0;
        puVar19 = puVar19 + 4 + (int)&local_9c->field_0x0;
      }
      if ((int)(uVar12 << 0x17) < 0) {
        sVar6 = strlen(*(char **)(param_1[0x39] + 0x14c));
        *puVar19 = (uchar)(sVar6 >> 8);
        sVar6 = strlen(*(char **)(param_1[0x39] + 0x14c));
        puVar19[1] = (uchar)sVar6;
        __s = *(char **)(param_1[0x39] + 0x14c);
        sVar6 = strlen(__s);
        strncpy((char *)(puVar19 + 2),__s,sVar6);
        sVar6 = strlen(*(char **)(param_1[0x39] + 0x14c));
        puVar19 = puVar19 + 2 + sVar6;
      }
      if (pkey != (EVP_PKEY *)0x0) {
        if ((pkey->type != 6) || ((*param_1 >> 8 == 3 && (0x302 < *param_1)))) {
          if (local_90 == (EVP_MD *)0x0) {
            ERR_put_error(0x14,0x9b,0xfb,"s3_srvr.c",0x7ff);
            uVar2 = 0x28;
          }
          else {
            if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
              iVar11 = tls12_get_sigandhash(puVar19,pkey);
              puVar19 = puVar19 + 2;
              if (iVar11 == 0) {
                ERR_put_error(0x14,0x9b,0x44,"s3_srvr.c",0x7e3);
                uVar2 = 0x50;
                goto LAB_0004533c;
              }
            }
            iVar11 = EVP_DigestInit_ex(&EStack_68,local_90,(ENGINE *)0x0);
            if ((((0 < iVar11) &&
                 (iVar11 = EVP_DigestUpdate(&EStack_68,(void *)(param_1[0x16] + 0xc0),0x20),
                 0 < iVar11)) &&
                (iVar11 = EVP_DigestUpdate(&EStack_68,(void *)(param_1[0x16] + 0xa0),0x20),
                0 < iVar11)) &&
               ((iVar11 = EVP_DigestUpdate(&EStack_68,d,(size_t)pRVar15), 0 < iVar11 &&
                (iVar11 = EVP_SignFinal(&EStack_68,puVar19 + 2,(uint *)&local_8c,pkey), 0 < iVar11))
               )) {
              *puVar19 = (uchar)((uint)local_8c >> 8);
              puVar19[1] = (uchar)local_8c;
              pRVar15 = (RSA *)(&local_8c->field_0x2 + (int)&pRVar15->field_0x0);
              if (*param_1 >> 8 == 3) {
                if (*param_1 < 0x303) {
                  local_ac = (int *)&pRVar15->field_0x4;
                }
                else {
                  local_ac = (int *)&pRVar15->field_0x6;
                  pRVar15 = (RSA *)&pRVar15->field_0x2;
                }
              }
              else {
                local_ac = (int *)&pRVar15->field_0x4;
              }
              goto LAB_00045068;
            }
            iVar11 = 0x7f3;
LAB_0004559e:
            ERR_put_error(0x14,0x9b,6,"s3_srvr.c",iVar11);
            uVar2 = 0x50;
          }
LAB_0004533c:
          ctx = (BN_CTX *)0x0;
          ssl3_send_alert(param_1,2,uVar2);
          goto LAB_00045346;
        }
        puVar16 = auStack_50;
        local_ac = (int *)0x0;
        ctx = (BN_CTX *)0x2;
        do {
          EVP_MD_CTX_set_flags(&EStack_68,8);
          if (ctx == (BN_CTX *)0x2) {
            type = *(EVP_MD **)(param_1[0x39] + 0x8c);
          }
          else {
            type = *(EVP_MD **)(param_1[0x39] + 0x90);
          }
          iVar11 = EVP_DigestInit_ex(&EStack_68,type,(ENGINE *)0x0);
          if (((iVar11 < 1) ||
              (iVar11 = EVP_DigestUpdate(&EStack_68,(void *)(param_1[0x16] + 0xc0),0x20), iVar11 < 1
              )) || ((iVar11 = EVP_DigestUpdate(&EStack_68,(void *)(param_1[0x16] + 0xa0),0x20),
                     iVar11 < 1 ||
                     ((iVar11 = EVP_DigestUpdate(&EStack_68,d,(size_t)pRVar15), iVar11 < 1 ||
                      (iVar11 = EVP_DigestFinal_ex(&EStack_68,puVar16,(uint *)&local_8c), iVar11 < 1
                      )))))) {
            iVar11 = 0x7ca;
            goto LAB_0004559e;
          }
          ctx = ctx + -1;
          puVar16 = puVar16 + (int)local_8c;
          local_ac = (int *)(&local_8c->field_0x0 + (int)local_ac);
        } while (ctx != (BN_CTX *)0x0);
        iVar11 = RSA_sign(0x72,auStack_50,(uint)local_ac,puVar19 + 2,&local_94,(pkey->pkey).rsa);
        if (iVar11 < 1) {
          ERR_put_error(0x14,0x9b,4,"s3_srvr.c",0x7d3);
          goto LAB_00045346;
        }
        *puVar19 = (uchar)(local_94 >> 8);
        puVar19[1] = (uchar)local_94;
        pRVar15 = (RSA *)(&pRVar15->field_0x2 + local_94);
        local_ac = (int *)&pRVar15->field_0x4;
      }
LAB_00045068:
      puVar13[3] = (char)pRVar15;
      puVar13[2] = (char)((uint)pRVar15 >> 8);
      puVar13[1] = (char)((uint)pRVar15 >> 0x10);
      *puVar13 = 0xc;
      param_1[0x11] = (int)local_ac;
      param_1[0x12] = 0;
      goto LAB_00045086;
    }
    ERR_put_error(0x14,0x9b,7,"s3_srvr.c",0x77c);
LAB_00045346:
    if (local_a0 != (RSA *)0x0) {
LAB_0004534a:
      CRYPTO_free(local_a0);
    }
  }
  else {
    if ((int)(uVar12 << 0x1c) < 0) {
      pDVar7 = *(DH **)(iVar14 + 0x20);
      if (pDVar7 == (DH *)0x0) {
        if (*(code **)(iVar14 + 0x24) != (code *)0x0) {
          if ((*(uint *)(iVar8 + 0x20) & 8) == 0) {
            uVar2 = 0x400;
          }
          else {
            uVar2 = 0x200;
          }
          pDVar7 = (DH *)(**(code **)(iVar14 + 0x24))(param_1,*(uint *)(iVar8 + 0x20) & 2,uVar2);
          if (pDVar7 != (DH *)0x0) {
            iVar11 = param_1[0x16];
            goto LAB_000453c0;
          }
        }
        local_a0 = (RSA *)0x0;
        ERR_put_error(0x14,0x9b,0xab,"s3_srvr.c",0x6b4);
        uVar2 = 0x28;
        goto LAB_0004533c;
      }
LAB_000453c0:
      if (*(int *)(iVar11 + 0x348) != 0) {
        iVar11 = 0x6ba;
LAB_000455c6:
        ERR_put_error(0x14,0x9b,0x44,"s3_srvr.c",iVar11);
        goto LAB_000455d6;
      }
      pDVar7 = DHparams_dup(pDVar7);
      iVar11 = 0x6bf;
      if (pDVar7 != (DH *)0x0) {
        *(DH **)(param_1[0x16] + 0x348) = pDVar7;
        iVar11 = DH_generate_key(pDVar7);
        if (iVar11 != 0) {
          pRVar15 = *(RSA **)&pDVar7->field_0x8;
          local_84 = *(int *)&pDVar7->field_0xc;
          local_80 = *(int *)&pDVar7->field_0x14;
          goto LAB_00044eae;
        }
        iVar11 = 0x6c5;
      }
      ERR_put_error(0x14,0x9b,5,"s3_srvr.c",iVar11);
      goto LAB_000455d6;
    }
    local_a8 = (RSA *)(uVar12 & 0x80);
    if (local_a8 == (RSA *)0x0) {
      if (-1 < (int)(uVar12 << 0x17)) {
        local_a0 = (RSA *)(uVar12 & 0x400);
        if (local_a0 == (RSA *)0x0) {
          ERR_put_error(0x14,0x9b,0xfa,"s3_srvr.c",0x761);
          uVar2 = 0x28;
          goto LAB_0004533c;
        }
        if (((((RSA *)param_1[0x6a] == (RSA *)0x0) || (param_1[0x6b] == 0)) || (param_1[0x6c] == 0))
           || (pRVar15 = (RSA *)param_1[0x6a], iVar11 = param_1[0x6b], iVar8 = param_1[0x6c],
              iVar14 = param_1[0x6d], param_1[0x6d] == 0)) {
          ERR_put_error(0x14,0x9b,0x166,"s3_srvr.c",0x755);
          goto LAB_000455d6;
        }
        goto LAB_0004522a;
      }
      sVar6 = strlen(*(char **)(param_1[0x39] + 0x14c));
      pRVar15 = (RSA *)(sVar6 + 2);
      local_a0 = local_a8;
      local_9c = local_a8;
LAB_000451dc:
      pRVar10 = (RSA *)0x0;
      local_8c = (RSA *)0x0;
      goto LAB_00044f12;
    }
    pEVar3 = *(EC_KEY **)(iVar14 + 0x28);
    if (pEVar3 == (EC_KEY *)0x0) {
      if (*(code **)(iVar14 + 0x2c) != (code *)0x0) {
        if ((*(uint *)(iVar8 + 0x20) & 8) == 0) {
          uVar2 = 0x400;
        }
        else {
          uVar2 = 0x200;
        }
        pEVar3 = (EC_KEY *)(**(code **)(iVar14 + 0x2c))(param_1,*(uint *)(iVar8 + 0x20) & 2,uVar2);
        if (pEVar3 != (EC_KEY *)0x0) {
          iVar11 = param_1[0x16];
          goto LAB_000450c2;
        }
      }
      local_a0 = (RSA *)0x0;
      ERR_put_error(0x14,0x9b,0x137,"s3_srvr.c",0x6dc);
      uVar2 = 0x28;
      goto LAB_0004533c;
    }
LAB_000450c2:
    if (*(int *)(iVar11 + 0x34c) != 0) {
      iVar11 = 0x6e2;
      goto LAB_000455c6;
    }
    pEVar3 = EC_KEY_dup(pEVar3);
    iVar11 = 0x6ec;
    if (pEVar3 == (EC_KEY *)0x0) {
LAB_00045686:
      ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",iVar11);
    }
    else {
      *(EC_KEY **)(param_1[0x16] + 0x34c) = pEVar3;
      pEVar4 = EC_KEY_get0_public_key(pEVar3);
      if ((((pEVar4 == (EC_POINT *)0x0) ||
           (pBVar5 = EC_KEY_get0_private_key(pEVar3), pBVar5 == (BIGNUM *)0x0)) ||
          (param_1[0x40] << 0xc < 0)) && (iVar11 = EC_KEY_generate_key(pEVar3), iVar11 == 0)) {
        iVar11 = 0x6f6;
        goto LAB_00045686;
      }
      group = EC_KEY_get0_group(pEVar3);
      if (((group == (EC_GROUP *)0x0) ||
          (pEVar4 = EC_KEY_get0_public_key(pEVar3), pEVar4 == (EC_POINT *)0x0)) ||
         (pBVar5 = EC_KEY_get0_private_key(pEVar3), pBVar5 == (BIGNUM *)0x0)) {
        iVar11 = 0x6fe;
        goto LAB_00045686;
      }
      if ((*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x20) << 0x1e < 0) &&
         (iVar11 = EC_GROUP_get_degree(group), 0xa3 < iVar11)) {
        ERR_put_error(0x14,0x9b,0x136,"s3_srvr.c",0x705);
      }
      else {
        EC_GROUP_get_curve_name(group);
        local_a8 = (RSA *)tls1_ec_nid2curve_id();
        if (local_a8 != (RSA *)0x0) {
          pEVar4 = EC_KEY_get0_public_key(pEVar3);
          sVar6 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                     (BN_CTX *)0x0);
          local_a0 = (RSA *)CRYPTO_malloc(sVar6,"s3_srvr.c",0x720);
          ctx = BN_CTX_new();
          if (local_a0 == (RSA *)0x0 || ctx == (BN_CTX *)0x0) {
            ERR_put_error(0x14,0x9b,0x41,"s3_srvr.c",0x724);
            goto LAB_00045346;
          }
          pEVar4 = EC_KEY_get0_public_key(pEVar3);
          local_9c = (RSA *)EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,
                                               (uchar *)local_a0,sVar6,ctx);
          if (local_9c != (RSA *)0x0) {
            BN_CTX_free(ctx);
            iVar11 = param_1[0x16];
            pRVar15 = (RSA *)&local_9c->field_0x4;
            local_88 = (RSA *)0x0;
            local_84 = 0;
            local_80 = 0;
            local_7c = 0;
            goto LAB_000451dc;
          }
          ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",0x72e);
          goto LAB_0004534a;
        }
        ERR_put_error(0x14,0x9b,0x13b,"s3_srvr.c",0x712);
      }
    }
LAB_000455d6:
    ctx = (BN_CTX *)0x0;
  }
  BN_CTX_free(ctx);
  EVP_MD_CTX_cleanup(&EStack_68);
  uVar2 = 0xffffffff;
  param_1[0xd] = 5;
LAB_0004509a:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

