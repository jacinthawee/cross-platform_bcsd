
/* WARNING: Could not reconcile some variable overlaps */

undefined4 ssl3_send_server_key_exchange(int *param_1)

{
  int *piVar1;
  BUF_MEM *str;
  uint uVar2;
  char *__s;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  EC_KEY *pEVar7;
  EC_POINT *pEVar8;
  BIGNUM *pBVar9;
  EC_GROUP *group;
  DH *pDVar10;
  size_t sVar11;
  EVP_MD *type;
  RSA *r;
  int iVar12;
  size_t sVar13;
  uchar *puVar14;
  uchar *puVar15;
  BN_CTX *ctx;
  int in_GS_OFFSET;
  uint local_b0;
  BIGNUM *local_ac;
  EVP_PKEY *local_a8;
  uchar *local_a4;
  uchar *local_a0;
  int local_9c;
  size_t local_98;
  undefined *local_94;
  int local_90;
  uint local_88;
  EVP_MD *local_84;
  uint local_80;
  EVP_MD_CTX local_7c;
  BIGNUM *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int aiStack_54 [4];
  uchar local_44 [36];
  int local_20;
  
  local_84 = (EVP_MD *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_7c);
  if (param_1[0xd] != 0x2150) {
LAB_08095d40:
    param_1[0xd] = 0x2151;
    EVP_MD_CTX_cleanup(&local_7c);
    uVar6 = ssl3_do_write(param_1,0x16);
    goto LAB_08095d5d;
  }
  iVar12 = param_1[0x16];
  str = (BUF_MEM *)param_1[0xf];
  iVar5 = param_1[0x26];
  local_58 = 0;
  local_5c = 0;
  local_60 = 0;
  iVar4 = *(int *)(iVar12 + 0x344);
  local_64 = (BIGNUM *)0x0;
  uVar2 = *(uint *)(iVar4 + 0xc);
  if ((uVar2 & 1) == 0) {
    local_ac = (BIGNUM *)iVar12;
    if ((uVar2 & 8) != 0) {
      pDVar10 = *(DH **)(iVar5 + 0x20);
      if (pDVar10 == (DH *)0x0) {
        if ((*(code **)(iVar5 + 0x24) == (code *)0x0) ||
           (pDVar10 = (DH *)(**(code **)(iVar5 + 0x24))
                                      (param_1,*(uint *)(iVar4 + 0x20) & 2,
                                       (-(uint)((*(uint *)(iVar4 + 0x20) & 8) == 0) & 0x200) + 0x200
                                      ), pDVar10 == (DH *)0x0)) {
          iVar4 = 0x6b4;
          iVar5 = 0xab;
          goto LAB_08096606;
        }
        local_ac = (BIGNUM *)param_1[0x16];
      }
      if (*(int *)((int)local_ac + 0x348) != 0) {
        iVar5 = 0x6ba;
LAB_08096510:
        ctx = (BN_CTX *)0x0;
        ERR_put_error(0x14,0x9b,0x44,"s3_srvr.c",iVar5);
        goto LAB_08096483;
      }
      pDVar10 = DHparams_dup(pDVar10);
      if (pDVar10 == (DH *)0x0) {
        iVar5 = 0x6bf;
      }
      else {
        *(DH **)(param_1[0x16] + 0x348) = pDVar10;
        iVar5 = DH_generate_key(pDVar10);
        if (iVar5 != 0) {
          local_64 = *(BIGNUM **)&pDVar10->field_0x8;
          local_60 = *(int *)&pDVar10->field_0xc;
          local_5c = *(int *)&pDVar10->field_0x14;
          goto LAB_08095aa2;
        }
        iVar5 = 0x6c5;
      }
      ctx = (BN_CTX *)0x0;
      ERR_put_error(0x14,0x9b,5,"s3_srvr.c",iVar5);
      goto LAB_08096483;
    }
    if ((uVar2 & 0x80) == 0) {
      if ((uVar2 & 0x100) == 0) {
        if ((uVar2 & 0x400) == 0) {
          iVar4 = 0x761;
          iVar5 = 0xfa;
          goto LAB_08096606;
        }
        if (((((BIGNUM *)param_1[0x6a] == (BIGNUM *)0x0) || (param_1[0x6b] == 0)) ||
            (param_1[0x6c] == 0)) ||
           (pBVar9 = (BIGNUM *)param_1[0x6a], iVar5 = param_1[0x6b], iVar4 = param_1[0x6c],
           iVar12 = param_1[0x6d], param_1[0x6d] == 0)) {
          ctx = (BN_CTX *)0x0;
          ERR_put_error(0x14,0x9b,0x166,"s3_srvr.c",0x755);
          goto LAB_08096483;
        }
        goto LAB_08095ab6;
      }
      sVar13 = strlen(*(char **)(param_1[0x39] + 0x14c));
      sVar13 = sVar13 + 2;
      local_90 = 0;
      local_98 = 0;
      local_a0 = (uchar *)0x0;
LAB_08095f56:
      local_80 = 0;
      local_ac = (BIGNUM *)0x0;
      goto LAB_08095b27;
    }
    pEVar7 = *(EC_KEY **)(iVar5 + 0x28);
    if (pEVar7 == (EC_KEY *)0x0) {
      if ((*(code **)(iVar5 + 0x2c) == (code *)0x0) ||
         (pEVar7 = (EC_KEY *)
                   (**(code **)(iVar5 + 0x2c))
                             (param_1,*(uint *)(iVar4 + 0x20) & 2,
                              (-(uint)((*(uint *)(iVar4 + 0x20) & 8) == 0) & 0x200) + 0x200),
         pEVar7 == (EC_KEY *)0x0)) {
        iVar4 = 0x6dc;
        iVar5 = 0x137;
        goto LAB_08096606;
      }
      local_ac = (BIGNUM *)param_1[0x16];
    }
    if (*(int *)((int)local_ac + 0x34c) != 0) {
      iVar5 = 0x6e2;
      goto LAB_08096510;
    }
    pEVar7 = EC_KEY_dup(pEVar7);
    if (pEVar7 != (EC_KEY *)0x0) {
      *(EC_KEY **)(param_1[0x16] + 0x34c) = pEVar7;
      pEVar8 = EC_KEY_get0_public_key(pEVar7);
      if ((((pEVar8 == (EC_POINT *)0x0) ||
           (pBVar9 = EC_KEY_get0_private_key(pEVar7), pBVar9 == (BIGNUM *)0x0)) ||
          ((*(byte *)((int)param_1 + 0x102) & 8) != 0)) &&
         (iVar5 = EC_KEY_generate_key(pEVar7), iVar5 == 0)) {
        iVar5 = 0x6f6;
        goto LAB_08096666;
      }
      group = EC_KEY_get0_group(pEVar7);
      if (((group == (EC_GROUP *)0x0) ||
          (pEVar8 = EC_KEY_get0_public_key(pEVar7), pEVar8 == (EC_POINT *)0x0)) ||
         (pBVar9 = EC_KEY_get0_private_key(pEVar7), pBVar9 == (BIGNUM *)0x0)) {
        iVar5 = 0x6fe;
        goto LAB_08096666;
      }
      if (((*(byte *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) != 0) &&
         (iVar5 = EC_GROUP_get_degree(group), 0xa3 < iVar5)) {
        ctx = (BN_CTX *)0x0;
        ERR_put_error(0x14,0x9b,0x136,"s3_srvr.c",0x705);
        goto LAB_08096483;
      }
      iVar5 = EC_GROUP_get_curve_name(group);
      local_90 = tls1_ec_nid2curve_id(iVar5);
      if (local_90 == 0) {
        ctx = (BN_CTX *)0x0;
        ERR_put_error(0x14,0x9b,0x13b,"s3_srvr.c",0x712);
        goto LAB_08096483;
      }
      pEVar8 = EC_KEY_get0_public_key(pEVar7);
      sVar13 = EC_POINT_point2oct(group,pEVar8,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                  (BN_CTX *)0x0);
      local_a0 = (uchar *)CRYPTO_malloc(sVar13,"s3_srvr.c",0x720);
      ctx = BN_CTX_new();
      if ((local_a0 == (uchar *)0x0) || (ctx == (BN_CTX *)0x0)) {
        ERR_put_error(0x14,0x9b,0x41,"s3_srvr.c",0x724);
        goto LAB_0809646c;
      }
      pEVar8 = EC_KEY_get0_public_key(pEVar7);
      local_98 = EC_POINT_point2oct(group,pEVar8,POINT_CONVERSION_UNCOMPRESSED,local_a0,sVar13,ctx);
      if (local_98 != 0) {
        BN_CTX_free(ctx);
        iVar12 = param_1[0x16];
        local_64 = (BIGNUM *)0x0;
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        sVar13 = local_98 + 4;
        goto LAB_08095f56;
      }
      ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",0x72e);
      goto LAB_08096474;
    }
    iVar5 = 0x6ec;
LAB_08096666:
    ctx = (BN_CTX *)0x0;
    ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",iVar5);
  }
  else {
    r = *(RSA **)(iVar5 + 0x18);
    if (r == (RSA *)0x0) {
      if (*(code **)(iVar5 + 0x1c) == (code *)0x0) {
        iVar4 = 0x6a0;
        iVar5 = 0xac;
      }
      else {
        r = (RSA *)(**(code **)(iVar5 + 0x1c))
                             (param_1,*(uint *)(iVar4 + 0x20) & 2,
                              (-(uint)((*(uint *)(iVar4 + 0x20) & 8) == 0) & 0x200) + 0x200);
        if (r != (RSA *)0x0) {
          RSA_up_ref(r);
          *(RSA **)(iVar5 + 0x18) = r;
          iVar12 = param_1[0x16];
          goto LAB_08095a86;
        }
        iVar4 = 0x697;
        iVar5 = 0x11a;
      }
LAB_08096606:
      ERR_put_error(0x14,0x9b,iVar5,"s3_srvr.c",iVar4);
      uVar6 = 0x28;
      local_a0 = (uchar *)0x0;
LAB_0809645b:
      ctx = (BN_CTX *)0x0;
      ssl3_send_alert(param_1,2,uVar6);
    }
    else {
LAB_08095a86:
      local_64 = *(BIGNUM **)&r->field_0x10;
      local_60 = *(int *)&r->field_0x14;
      *(undefined4 *)(iVar12 + 0x370) = 1;
LAB_08095aa2:
      local_80 = 0;
      pBVar9 = local_64;
      iVar5 = local_60;
      iVar4 = local_5c;
      iVar12 = local_58;
      if (local_64 == (BIGNUM *)0x0) {
        local_90._0_1_ = '\0';
        local_98 = 0;
        sVar13 = 0;
        local_a0 = (uchar *)0x0;
        iVar12 = param_1[0x16];
        local_ac = local_64;
      }
      else {
LAB_08095ab6:
        local_58 = iVar12;
        local_5c = iVar4;
        local_60 = iVar5;
        local_64 = pBVar9;
        local_ac = local_64;
        local_80 = 0;
        sVar13 = 0;
        pBVar9 = local_64;
        if ((uVar2 & 0x400) == 0) {
          do {
            uVar3 = local_80;
            iVar4 = BN_num_bits(pBVar9);
            iVar5 = iVar4 + 7;
            if (iVar4 + 7 < 0) {
              iVar5 = iVar4 + 0xe;
            }
            aiStack_54[uVar3] = iVar5 >> 3;
            piVar1 = aiStack_54 + local_80;
            local_80 = local_80 + 1;
            sVar13 = sVar13 + 2 + *piVar1;
          } while (((int)local_80 < 4) &&
                  (pBVar9 = (&local_64)[local_80], (&local_64)[local_80] != (BIGNUM *)0x0));
        }
        else {
          do {
            uVar3 = local_80;
            iVar4 = BN_num_bits(pBVar9);
            iVar5 = iVar4 + 7;
            if (iVar4 + 7 < 0) {
              iVar5 = iVar4 + 0xe;
            }
            aiStack_54[uVar3] = iVar5 >> 3;
            if (local_80 == 2) {
              local_80 = 3;
              sVar13 = sVar13 + 1 + aiStack_54[2];
            }
            else {
              piVar1 = aiStack_54 + local_80;
              local_80 = local_80 + 1;
              sVar13 = sVar13 + 2 + *piVar1;
              if (3 < (int)local_80) break;
            }
            pBVar9 = (&local_64)[local_80];
          } while (pBVar9 != (BIGNUM *)0x0);
        }
        iVar12 = param_1[0x16];
        local_90._0_1_ = '\0';
        local_98 = 0;
        local_a0 = (uchar *)0x0;
      }
LAB_08095b27:
      iVar5 = *(int *)(iVar12 + 0x344);
      if ((*(uint *)(iVar5 + 0x10) & 0x404) == 0) {
        iVar4 = 0;
        local_a8 = (EVP_PKEY *)0x0;
        if ((*(byte *)(iVar5 + 0xd) & 1) == 0) {
          local_a8 = (EVP_PKEY *)ssl_get_sign_pkey(param_1,iVar5,&local_84);
          if (local_a8 == (EVP_PKEY *)0x0) {
            uVar6 = 0x32;
            goto LAB_0809645b;
          }
          iVar4 = EVP_PKEY_size(local_a8);
        }
        iVar5 = BUF_MEM_grow_clean(str,iVar4 + sVar13 + 4);
        if (iVar5 == 0) goto LAB_080965c2;
        local_94 = *(undefined **)(param_1[0xf] + 4);
LAB_08095b88:
        local_9c = sVar13 + 4;
        local_a4 = local_94 + 4;
        local_80 = 0;
        puVar14 = local_a4;
        if (local_ac != (BIGNUM *)0x0) {
          if ((uVar2 & 0x400) == 0) {
            do {
              *puVar14 = (uchar)((uint)aiStack_54[local_80] >> 8);
              puVar14[1] = (uchar)aiStack_54[local_80];
              BN_bn2bin((&local_64)[local_80],puVar14 + 2);
              puVar14 = puVar14 + 2 + aiStack_54[local_80];
              local_80 = local_80 + 1;
              if (3 < (int)local_80) break;
            } while ((&local_64)[local_80] != (BIGNUM *)0x0);
          }
          else {
            do {
              if (local_80 == 2) {
                puVar15 = puVar14 + 1;
                *puVar14 = (uchar)aiStack_54[2];
              }
              else {
                puVar15 = puVar14 + 2;
                *puVar14 = (uchar)((uint)aiStack_54[local_80] >> 8);
                puVar14[1] = (uchar)aiStack_54[local_80];
              }
              BN_bn2bin((&local_64)[local_80],puVar15);
              puVar14 = puVar15 + aiStack_54[local_80];
              local_80 = local_80 + 1;
            } while (((int)local_80 < 4) && ((&local_64)[local_80] != (BIGNUM *)0x0));
          }
        }
        if ((uVar2 & 0x80) != 0) {
          *puVar14 = '\x03';
          puVar14[1] = '\0';
          puVar14[3] = (uchar)local_98;
          puVar14[2] = (uchar)local_90;
          memcpy(puVar14 + 4,local_a0,local_98);
          CRYPTO_free(local_a0);
          puVar14 = puVar14 + 4 + local_98;
          local_a0 = (uchar *)0x0;
        }
        if ((uVar2 & 0x100) != 0) {
          sVar11 = strlen(*(char **)(param_1[0x39] + 0x14c));
          *puVar14 = (uchar)(sVar11 >> 8);
          sVar11 = strlen(*(char **)(param_1[0x39] + 0x14c));
          puVar14[1] = (uchar)sVar11;
          __s = *(char **)(param_1[0x39] + 0x14c);
          sVar11 = strlen(__s);
          strncpy((char *)(puVar14 + 2),__s,sVar11);
          sVar11 = strlen(*(char **)(param_1[0x39] + 0x14c));
          puVar14 = puVar14 + 2 + sVar11;
        }
        if (local_a8 == (EVP_PKEY *)0x0) {
LAB_08095d18:
          local_94[1] = (char)(sVar13 >> 0x10);
          *local_94 = 0xc;
          local_94[3] = (char)sVar13;
          local_94[2] = (char)(sVar13 >> 8);
          param_1[0x12] = 0;
          param_1[0x11] = local_9c;
          goto LAB_08095d40;
        }
        if ((local_a8->type != 6) || ((*param_1 >> 8 == 3 && (0x302 < *param_1)))) {
          if (local_84 == (EVP_MD *)0x0) {
            ERR_put_error(0x14,0x9b,0xfb,"s3_srvr.c",0x7ff);
            uVar6 = 0x28;
            goto LAB_0809645b;
          }
          if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
            iVar5 = tls12_get_sigandhash(puVar14,local_a8,local_84);
            if (iVar5 != 0) {
              puVar14 = puVar14 + 2;
              goto LAB_08095c4a;
            }
            iVar5 = 0x7e3;
            iVar4 = 0x44;
          }
          else {
LAB_08095c4a:
            iVar5 = EVP_DigestInit_ex(&local_7c,local_84,(ENGINE *)0x0);
            if ((((0 < iVar5) &&
                 (iVar5 = EVP_DigestUpdate(&local_7c,(void *)(param_1[0x16] + 0xc0),0x20), 0 < iVar5
                 )) && (iVar5 = EVP_DigestUpdate(&local_7c,(void *)(param_1[0x16] + 0xa0),0x20),
                       0 < iVar5)) &&
               ((iVar5 = EVP_DigestUpdate(&local_7c,local_a4,sVar13), 0 < iVar5 &&
                (iVar5 = EVP_SignFinal(&local_7c,puVar14 + 2,&local_80,local_a8), 0 < iVar5)))) {
              *puVar14 = (uchar)(local_80 >> 8);
              puVar14[1] = (uchar)local_80;
              sVar13 = sVar13 + 2 + local_80;
              if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
                local_9c = sVar13 + 6;
                sVar13 = sVar13 + 2;
              }
              else {
                local_9c = sVar13 + 4;
              }
              goto LAB_08095d18;
            }
            iVar5 = 0x7f3;
LAB_08096440:
            iVar4 = 6;
          }
          ERR_put_error(0x14,0x9b,iVar4,"s3_srvr.c",iVar5);
          uVar6 = 0x50;
          goto LAB_0809645b;
        }
        puVar15 = local_44;
        local_ac = (BIGNUM *)0x2;
        local_b0 = 0;
        do {
          EVP_MD_CTX_set_flags(&local_7c,8);
          if (local_ac == (BIGNUM *)0x2) {
            type = *(EVP_MD **)(param_1[0x39] + 0x8c);
          }
          else {
            type = *(EVP_MD **)(param_1[0x39] + 0x90);
          }
          iVar5 = EVP_DigestInit_ex(&local_7c,type,(ENGINE *)0x0);
          if (((iVar5 < 1) ||
              (iVar5 = EVP_DigestUpdate(&local_7c,(void *)(param_1[0x16] + 0xc0),0x20), iVar5 < 1))
             || ((iVar5 = EVP_DigestUpdate(&local_7c,(void *)(param_1[0x16] + 0xa0),0x20), iVar5 < 1
                 || ((iVar5 = EVP_DigestUpdate(&local_7c,local_a4,sVar13), iVar5 < 1 ||
                     (iVar5 = EVP_DigestFinal_ex(&local_7c,puVar15,&local_80), iVar5 < 1)))))) {
            iVar5 = 0x7ca;
            goto LAB_08096440;
          }
          local_b0 = local_b0 + local_80;
          puVar15 = puVar15 + local_80;
          local_ac = (BIGNUM *)((int)local_ac + -1);
        } while (local_ac != (BIGNUM *)0x0);
        iVar5 = RSA_sign(0x72,local_44,local_b0,puVar14 + 2,&local_88,(local_a8->pkey).rsa);
        if (0 < iVar5) {
          *puVar14 = (uchar)(local_88 >> 8);
          puVar14[1] = (uchar)local_88;
          sVar13 = sVar13 + 2 + local_88;
          local_9c = sVar13 + 4;
          goto LAB_08095d18;
        }
        iVar4 = 0x7d3;
        iVar5 = 4;
      }
      else {
        iVar5 = BUF_MEM_grow_clean(str,sVar13 + 4);
        if (iVar5 != 0) {
          local_a8 = (EVP_PKEY *)0x0;
          local_94 = *(undefined **)(param_1[0xf] + 4);
          goto LAB_08095b88;
        }
LAB_080965c2:
        iVar4 = 0x77c;
        iVar5 = 7;
      }
      ctx = (BN_CTX *)0x0;
      ERR_put_error(0x14,0x9b,iVar5,"s3_srvr.c",iVar4);
    }
LAB_0809646c:
    if (local_a0 != (uchar *)0x0) {
LAB_08096474:
      CRYPTO_free(local_a0);
    }
  }
LAB_08096483:
  BN_CTX_free(ctx);
  EVP_MD_CTX_cleanup(&local_7c);
  param_1[0xd] = 5;
  uVar6 = 0xffffffff;
LAB_08095d5d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}

