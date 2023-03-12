
/* WARNING: Could not reconcile some variable overlaps */

undefined4 ssl3_send_server_key_exchange(int *param_1)

{
  int *piVar1;
  BUF_MEM *str;
  uint uVar2;
  undefined *puVar3;
  char *__s;
  uint uVar4;
  int iVar5;
  int iVar6;
  uchar *d;
  undefined4 uVar7;
  DH *dh;
  EC_KEY *pEVar8;
  EC_POINT *pEVar9;
  EC_GROUP *group;
  size_t sVar10;
  EVP_MD *type;
  RSA *r;
  BIGNUM *pBVar11;
  DH *pDVar12;
  int iVar13;
  uchar *puVar14;
  uchar *puVar15;
  size_t sVar16;
  BN_CTX *ctx;
  int in_GS_OFFSET;
  uint local_b0;
  BIGNUM *local_ac;
  EVP_PKEY *local_a8;
  int local_a4;
  uchar *local_98;
  size_t local_94;
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
LAB_08099dba:
    param_1[0xd] = 0x2151;
    EVP_MD_CTX_cleanup(&local_7c);
    uVar7 = ssl3_do_write(param_1,0x16);
    goto LAB_08099dd7;
  }
  iVar13 = param_1[0x16];
  str = (BUF_MEM *)param_1[0xf];
  iVar6 = param_1[0x26];
  local_58 = 0;
  local_5c = 0;
  local_60 = 0;
  iVar5 = *(int *)(iVar13 + 0x344);
  local_64 = (BIGNUM *)0x0;
  uVar2 = *(uint *)(iVar5 + 0xc);
  if ((uVar2 & 1) == 0) {
    local_ac = (BIGNUM *)iVar13;
    if ((uVar2 & 8) != 0) {
      pDVar12 = *(DH **)(iVar6 + 0x20);
      if (pDVar12 == (DH *)0x0) {
        if ((*(code **)(iVar6 + 0x24) == (code *)0x0) ||
           (pDVar12 = (DH *)(**(code **)(iVar6 + 0x24))
                                      (param_1,*(uint *)(iVar5 + 0x20) & 2,
                                       (-(uint)((*(uint *)(iVar5 + 0x20) & 8) == 0) & 0x200) + 0x200
                                      ), pDVar12 == (DH *)0x0)) {
          iVar5 = 0x65f;
          iVar6 = 0xab;
          goto LAB_0809a61c;
        }
        local_ac = (BIGNUM *)param_1[0x16];
      }
      if (*(int *)((int)local_ac + 0x348) != 0) {
        iVar6 = 0x665;
LAB_0809a4b8:
        ERR_put_error(0x14,0x9b,0x44,"s3_srvr.c",iVar6);
        goto LAB_0809a4ce;
      }
      dh = DHparams_dup(pDVar12);
      if (dh == (DH *)0x0) {
        iVar6 = 0x66b;
      }
      else {
        *(DH **)(param_1[0x16] + 0x348) = dh;
        if (((*(BIGNUM **)&pDVar12->field_0x14 == (BIGNUM *)0x0) ||
            (*(int *)&pDVar12->field_0x18 == 0)) || ((*(byte *)((int)param_1 + 0x102) & 0x10) != 0))
        {
          iVar6 = DH_generate_key(dh);
          if (iVar6 != 0) {
            iVar6 = *(int *)&dh->field_0x14;
            goto LAB_08099e81;
          }
          iVar6 = 0x677;
        }
        else {
          pBVar11 = BN_dup(*(BIGNUM **)&pDVar12->field_0x14);
          *(BIGNUM **)&dh->field_0x14 = pBVar11;
          pBVar11 = BN_dup(*(BIGNUM **)&pDVar12->field_0x18);
          iVar6 = *(int *)&dh->field_0x14;
          *(BIGNUM **)&dh->field_0x18 = pBVar11;
          if ((iVar6 != 0) && (pBVar11 != (BIGNUM *)0x0)) {
LAB_08099e81:
            local_64 = *(BIGNUM **)&dh->field_0x8;
            local_60 = *(int *)&dh->field_0xc;
            local_5c = iVar6;
            goto LAB_08099b52;
          }
          iVar6 = 0x682;
        }
      }
      ERR_put_error(0x14,0x9b,5,"s3_srvr.c",iVar6);
      goto LAB_0809a4ce;
    }
    if ((uVar2 & 0x80) == 0) {
      if ((uVar2 & 0x100) == 0) {
        if ((uVar2 & 0x400) == 0) {
          iVar5 = 0x726;
          iVar6 = 0xfa;
          goto LAB_0809a61c;
        }
        if (((((BIGNUM *)param_1[0x6a] == (BIGNUM *)0x0) || (param_1[0x6b] == 0)) ||
            (param_1[0x6c] == 0)) ||
           (pBVar11 = (BIGNUM *)param_1[0x6a], iVar6 = param_1[0x6b], iVar5 = param_1[0x6c],
           iVar13 = param_1[0x6d], param_1[0x6d] == 0)) {
          ERR_put_error(0x14,0x9b,0x166,"s3_srvr.c",0x71a);
          goto LAB_0809a4ce;
        }
        goto LAB_08099b66;
      }
      sVar16 = strlen(*(char **)(param_1[0x39] + 0x14c));
      sVar16 = sVar16 + 2;
      local_90 = 0;
      local_94 = 0;
      local_98 = (uchar *)0x0;
LAB_0809a12b:
      local_80 = 0;
      local_ac = (BIGNUM *)0x0;
      goto LAB_08099bd7;
    }
    pEVar8 = *(EC_KEY **)(iVar6 + 0x28);
    if (pEVar8 == (EC_KEY *)0x0) {
      if ((*(code **)(iVar6 + 0x2c) == (code *)0x0) ||
         (pEVar8 = (EC_KEY *)
                   (**(code **)(iVar6 + 0x2c))
                             (param_1,*(uint *)(iVar5 + 0x20) & 2,
                              (-(uint)((*(uint *)(iVar5 + 0x20) & 8) == 0) & 0x200) + 0x200),
         pEVar8 == (EC_KEY *)0x0)) {
        iVar5 = 0x69b;
        iVar6 = 0x137;
        goto LAB_0809a61c;
      }
      local_ac = (BIGNUM *)param_1[0x16];
    }
    if (*(int *)((int)local_ac + 0x34c) != 0) {
      iVar6 = 0x6a1;
      goto LAB_0809a4b8;
    }
    pEVar8 = EC_KEY_dup(pEVar8);
    if (pEVar8 == (EC_KEY *)0x0) {
      iVar6 = 0x6ad;
LAB_0809a688:
      ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",iVar6);
    }
    else {
      *(EC_KEY **)(param_1[0x16] + 0x34c) = pEVar8;
      pEVar9 = EC_KEY_get0_public_key(pEVar8);
      if ((((pEVar9 == (EC_POINT *)0x0) ||
           (pBVar11 = EC_KEY_get0_private_key(pEVar8), pBVar11 == (BIGNUM *)0x0)) ||
          ((*(byte *)((int)param_1 + 0x102) & 8) != 0)) &&
         (iVar6 = EC_KEY_generate_key(pEVar8), iVar6 == 0)) {
        iVar6 = 0x6b8;
        goto LAB_0809a688;
      }
      group = EC_KEY_get0_group(pEVar8);
      if (((group == (EC_GROUP *)0x0) ||
          (pEVar9 = EC_KEY_get0_public_key(pEVar8), pEVar9 == (EC_POINT *)0x0)) ||
         (pBVar11 = EC_KEY_get0_private_key(pEVar8), pBVar11 == (BIGNUM *)0x0)) {
        iVar6 = 0x6c1;
        goto LAB_0809a688;
      }
      if (((*(byte *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) == 0) ||
         (iVar6 = EC_GROUP_get_degree(group), iVar6 < 0xa4)) {
        iVar6 = EC_GROUP_get_curve_name(group);
        local_90 = tls1_ec_nid2curve_id(iVar6);
        if (local_90 != 0) {
          pEVar9 = EC_KEY_get0_public_key(pEVar8);
          sVar16 = EC_POINT_point2oct(group,pEVar9,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                      (BN_CTX *)0x0);
          local_98 = (uchar *)CRYPTO_malloc(sVar16,"s3_srvr.c",0x6e2);
          ctx = BN_CTX_new();
          if ((local_98 == (uchar *)0x0) || (ctx == (BN_CTX *)0x0)) {
            ERR_put_error(0x14,0x9b,0x41,"s3_srvr.c",0x6e6);
            goto LAB_0809a5ea;
          }
          pEVar9 = EC_KEY_get0_public_key(pEVar8);
          local_94 = EC_POINT_point2oct(group,pEVar9,POINT_CONVERSION_UNCOMPRESSED,local_98,sVar16,
                                        ctx);
          if (local_94 != 0) {
            BN_CTX_free(ctx);
            iVar13 = param_1[0x16];
            local_64 = (BIGNUM *)0x0;
            local_60 = 0;
            local_5c = 0;
            local_58 = 0;
            sVar16 = local_94 + 4;
            goto LAB_0809a12b;
          }
          ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",0x6f2);
          goto LAB_0809a5f6;
        }
        ERR_put_error(0x14,0x9b,0x13b,"s3_srvr.c",0x6d4);
      }
      else {
        ERR_put_error(0x14,0x9b,0x136,"s3_srvr.c",0x6c8);
      }
    }
LAB_0809a4ce:
    ctx = (BN_CTX *)0x0;
  }
  else {
    r = *(RSA **)(iVar6 + 0x18);
    if (r == (RSA *)0x0) {
      if (*(code **)(iVar6 + 0x1c) == (code *)0x0) {
        iVar5 = 0x64b;
        iVar6 = 0xac;
      }
      else {
        r = (RSA *)(**(code **)(iVar6 + 0x1c))
                             (param_1,*(uint *)(iVar5 + 0x20) & 2,
                              (-(uint)((*(uint *)(iVar5 + 0x20) & 8) == 0) & 0x200) + 0x200);
        if (r != (RSA *)0x0) {
          RSA_up_ref(r);
          *(RSA **)(iVar6 + 0x18) = r;
          iVar13 = param_1[0x16];
          goto LAB_08099b36;
        }
        iVar5 = 0x642;
        iVar6 = 0x11a;
      }
LAB_0809a61c:
      ERR_put_error(0x14,0x9b,iVar6,"s3_srvr.c",iVar5);
      uVar7 = 0x28;
      local_98 = (uchar *)0x0;
      goto LAB_0809a638;
    }
LAB_08099b36:
    local_64 = *(BIGNUM **)&r->field_0x10;
    local_60 = *(int *)&r->field_0x14;
    *(undefined4 *)(iVar13 + 0x370) = 1;
LAB_08099b52:
    local_80 = 0;
    pBVar11 = local_64;
    iVar6 = local_60;
    iVar5 = local_5c;
    iVar13 = local_58;
    if (local_64 == (BIGNUM *)0x0) {
      local_90._0_1_ = '\0';
      local_94 = 0;
      sVar16 = 0;
      local_98 = (uchar *)0x0;
      iVar13 = param_1[0x16];
      local_ac = local_64;
    }
    else {
LAB_08099b66:
      local_58 = iVar13;
      local_5c = iVar5;
      local_60 = iVar6;
      local_64 = pBVar11;
      local_ac = local_64;
      local_80 = 0;
      sVar16 = 0;
      pBVar11 = local_64;
      if ((uVar2 & 0x400) == 0) {
        do {
          uVar4 = local_80;
          iVar5 = BN_num_bits(pBVar11);
          iVar6 = iVar5 + 7;
          if (iVar5 + 7 < 0) {
            iVar6 = iVar5 + 0xe;
          }
          aiStack_54[uVar4] = iVar6 >> 3;
          piVar1 = aiStack_54 + local_80;
          local_80 = local_80 + 1;
          sVar16 = sVar16 + 2 + *piVar1;
        } while (((&local_64)[local_80] != (BIGNUM *)0x0) &&
                (pBVar11 = (&local_64)[local_80], (int)local_80 < 4));
      }
      else {
        do {
          uVar4 = local_80;
          iVar5 = BN_num_bits(pBVar11);
          iVar6 = iVar5 + 7;
          if (iVar5 + 7 < 0) {
            iVar6 = iVar5 + 0xe;
          }
          aiStack_54[uVar4] = iVar6 >> 3;
          if (local_80 == 2) {
            sVar16 = sVar16 + 1 + aiStack_54[2];
          }
          else {
            sVar16 = sVar16 + 2 + aiStack_54[local_80];
          }
          local_80 = local_80 + 1;
          pBVar11 = (&local_64)[local_80];
        } while ((pBVar11 != (BIGNUM *)0x0) && ((int)local_80 < 4));
      }
      iVar13 = param_1[0x16];
      local_90._0_1_ = '\0';
      local_94 = 0;
      local_98 = (uchar *)0x0;
    }
LAB_08099bd7:
    iVar6 = *(int *)(iVar13 + 0x344);
    iVar5 = 0;
    local_a8 = (EVP_PKEY *)0x0;
    if (((*(byte *)(iVar6 + 0x10) & 4) == 0) && ((*(byte *)(iVar6 + 0xd) & 1) == 0)) {
      local_a8 = (EVP_PKEY *)ssl_get_sign_pkey(param_1,iVar6,&local_84);
      if (local_a8 == (EVP_PKEY *)0x0) {
        uVar7 = 0x32;
        goto LAB_0809a638;
      }
      iVar5 = EVP_PKEY_size(local_a8);
    }
    local_a4 = sVar16 + 4;
    iVar6 = BUF_MEM_grow_clean(str,iVar5 + local_a4);
    if (iVar6 != 0) {
      local_80 = 0;
      puVar3 = *(undefined **)(param_1[0xf] + 4);
      d = puVar3 + 4;
      puVar14 = d;
      if (local_ac != (BIGNUM *)0x0) {
        if ((uVar2 & 0x400) == 0) {
          do {
            *puVar14 = (uchar)((uint)aiStack_54[local_80] >> 8);
            puVar14[1] = (uchar)aiStack_54[local_80];
            BN_bn2bin((&local_64)[local_80],puVar14 + 2);
            puVar14 = puVar14 + 2 + aiStack_54[local_80];
            local_80 = local_80 + 1;
            if ((&local_64)[local_80] == (BIGNUM *)0x0) break;
          } while ((int)local_80 < 4);
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
          } while (((&local_64)[local_80] != (BIGNUM *)0x0) && ((int)local_80 < 4));
        }
      }
      if ((uVar2 & 0x80) != 0) {
        *puVar14 = '\x03';
        puVar14[1] = '\0';
        puVar14[3] = (uchar)local_94;
        puVar14[2] = (uchar)local_90;
        memcpy(puVar14 + 4,local_98,local_94);
        CRYPTO_free(local_98);
        puVar14 = puVar14 + 4 + local_94;
        local_98 = (uchar *)0x0;
      }
      if ((uVar2 & 0x100) != 0) {
        sVar10 = strlen(*(char **)(param_1[0x39] + 0x14c));
        *puVar14 = (uchar)(sVar10 >> 8);
        sVar10 = strlen(*(char **)(param_1[0x39] + 0x14c));
        puVar14[1] = (uchar)sVar10;
        __s = *(char **)(param_1[0x39] + 0x14c);
        sVar10 = strlen(__s);
        strncpy((char *)(puVar14 + 2),__s,sVar10);
        sVar10 = strlen(*(char **)(param_1[0x39] + 0x14c));
        puVar14 = puVar14 + 2 + sVar10;
      }
      if (local_a8 != (EVP_PKEY *)0x0) {
        if ((local_a8->type == 6) && ((*param_1 >> 8 != 3 || (*param_1 < 0x303)))) {
          puVar15 = local_44;
          local_b0 = 0;
          iVar6 = 2;
          do {
            EVP_MD_CTX_set_flags(&local_7c,8);
            if (iVar6 == 2) {
              type = *(EVP_MD **)(param_1[0x39] + 0x8c);
            }
            else {
              type = *(EVP_MD **)(param_1[0x39] + 0x90);
            }
            EVP_DigestInit_ex(&local_7c,type,(ENGINE *)0x0);
            EVP_DigestUpdate(&local_7c,(void *)(param_1[0x16] + 0xc0),0x20);
            EVP_DigestUpdate(&local_7c,(void *)(param_1[0x16] + 0xa0),0x20);
            EVP_DigestUpdate(&local_7c,d,sVar16);
            EVP_DigestFinal_ex(&local_7c,puVar15,&local_80);
            local_b0 = local_b0 + local_80;
            puVar15 = puVar15 + local_80;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          iVar6 = RSA_sign(0x72,local_44,local_b0,puVar14 + 2,&local_88,(local_a8->pkey).rsa);
          if (iVar6 < 1) {
            iVar5 = 0x79c;
            iVar6 = 4;
            goto LAB_0809a5d9;
          }
          *puVar14 = (uchar)(local_88 >> 8);
          puVar14[1] = (uchar)local_88;
          sVar16 = sVar16 + 2 + local_88;
          local_a4 = sVar16 + 4;
        }
        else {
          if (local_84 == (EVP_MD *)0x0) {
            ERR_put_error(0x14,0x9b,0xfb,"s3_srvr.c",0x7ca);
            uVar7 = 0x28;
LAB_0809a638:
            ctx = (BN_CTX *)0x0;
            ssl3_send_alert(param_1,2,uVar7);
            goto LAB_0809a5ea;
          }
          if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
            iVar6 = tls12_get_sigandhash(puVar14,local_a8,local_84);
            if (iVar6 == 0) {
              ERR_put_error(0x14,0x9b,0x44,"s3_srvr.c",0x7ae);
              uVar7 = 0x50;
              goto LAB_0809a638;
            }
            puVar14 = puVar14 + 2;
          }
          EVP_DigestInit_ex(&local_7c,local_84,(ENGINE *)0x0);
          EVP_DigestUpdate(&local_7c,(void *)(param_1[0x16] + 0xc0),0x20);
          EVP_DigestUpdate(&local_7c,(void *)(param_1[0x16] + 0xa0),0x20);
          EVP_DigestUpdate(&local_7c,d,sVar16);
          iVar6 = EVP_SignFinal(&local_7c,puVar14 + 2,&local_80,local_a8);
          if (iVar6 == 0) {
            iVar5 = 0x7be;
            iVar6 = 6;
            goto LAB_0809a5d9;
          }
          *puVar14 = (uchar)(local_80 >> 8);
          puVar14[1] = (uchar)local_80;
          sVar16 = sVar16 + 2 + local_80;
          if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
            local_a4 = sVar16 + 6;
            sVar16 = sVar16 + 2;
          }
          else {
            local_a4 = sVar16 + 4;
          }
        }
      }
      puVar3[1] = (char)(sVar16 >> 0x10);
      *puVar3 = 0xc;
      puVar3[2] = (char)(sVar16 >> 8);
      puVar3[3] = (char)sVar16;
      param_1[0x12] = 0;
      param_1[0x11] = local_a4;
      goto LAB_08099dba;
    }
    iVar5 = 0x747;
    iVar6 = 7;
LAB_0809a5d9:
    ctx = (BN_CTX *)0x0;
    ERR_put_error(0x14,0x9b,iVar6,"s3_srvr.c",iVar5);
LAB_0809a5ea:
    if (local_98 != (uchar *)0x0) {
LAB_0809a5f6:
      CRYPTO_free(local_98);
    }
  }
  BN_CTX_free(ctx);
  EVP_MD_CTX_cleanup(&local_7c);
  uVar7 = 0xffffffff;
LAB_08099dd7:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}

