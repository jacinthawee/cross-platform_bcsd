
/* WARNING: Could not reconcile some variable overlaps */

void ssl3_send_server_key_exchange(int *param_1)

{
  RSA *pRVar1;
  RSA *pRVar2;
  BN_CTX *ctx;
  undefined4 uVar3;
  DH *dh;
  BIGNUM *pBVar4;
  EC_KEY *pEVar5;
  EC_POINT *pEVar6;
  EC_GROUP *group;
  size_t sVar7;
  EVP_PKEY *pEVar8;
  EVP_MD *type;
  int iVar9;
  uchar *d;
  undefined *puVar10;
  RSA *pRVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uchar *puVar15;
  BUF_MEM *str;
  undefined *puVar16;
  int iVar17;
  RSA *cnt;
  RSA *pRVar18;
  int *piVar19;
  RSA *pRVar20;
  DH *pDVar21;
  char *__s;
  uchar *puVar22;
  EVP_PKEY *local_ac;
  RSA *local_a8;
  RSA *local_a0;
  RSA *local_9c;
  uint local_94;
  EVP_MD *local_90;
  RSA *local_8c;
  RSA *local_88;
  int local_84;
  int local_80;
  RSA *local_7c;
  int aiStack_78 [4];
  EVP_MD_CTX EStack_68;
  uchar auStack_50 [36];
  int local_2c;
  
  local_90 = (EVP_MD *)0x0;
  local_2c = __TMC_END__;
  EVP_MD_CTX_init(&EStack_68);
  if (param_1[0xd] == 0x2150) {
    iVar12 = param_1[0x16];
    local_7c = (RSA *)0x0;
    local_80 = 0;
    iVar9 = *(int *)(iVar12 + 0x344);
    local_84 = 0;
    local_88 = (RSA *)0x0;
    uVar14 = *(uint *)(iVar9 + 0xc);
    iVar17 = param_1[0x26];
    str = (BUF_MEM *)param_1[0xf];
    if ((int)(uVar14 << 0x1f) < 0) {
      local_a0 = *(RSA **)(iVar17 + 0x18);
      if (local_a0 != (RSA *)0x0) {
LAB_00048300:
        pRVar20 = *(RSA **)&local_a0->field_0x10;
        local_84 = *(int *)&local_a0->field_0x14;
        *(undefined4 *)(iVar12 + 0x370) = 1;
        goto LAB_00048314;
      }
      local_a0 = *(RSA **)(iVar17 + 0x1c);
      if (local_a0 == (RSA *)0x0) {
        ERR_put_error(0x14,0x9b,0xac,"s3_srvr.c",0x64b);
        uVar3 = 0x28;
      }
      else {
        if ((*(uint *)(iVar9 + 0x20) & 8) == 0) {
          uVar3 = 0x400;
        }
        else {
          uVar3 = 0x200;
        }
        local_a0 = (RSA *)(*(code *)local_a0)(param_1,*(uint *)(iVar9 + 0x20) & 2,uVar3);
        if (local_a0 != (RSA *)0x0) {
          RSA_up_ref(local_a0);
          *(RSA **)(iVar17 + 0x18) = local_a0;
          iVar12 = param_1[0x16];
          goto LAB_00048300;
        }
        ERR_put_error(0x14,0x9b,0x11a,"s3_srvr.c",0x642);
        uVar3 = 0x28;
      }
      goto LAB_000486ec;
    }
    if ((int)(uVar14 << 0x1c) < 0) {
      pDVar21 = *(DH **)(iVar17 + 0x20);
      if (pDVar21 == (DH *)0x0) {
        if (*(code **)(iVar17 + 0x24) != (code *)0x0) {
          if ((*(uint *)(iVar9 + 0x20) & 8) == 0) {
            uVar3 = 0x400;
          }
          else {
            uVar3 = 0x200;
          }
          pDVar21 = (DH *)(**(code **)(iVar17 + 0x24))(param_1,*(uint *)(iVar9 + 0x20) & 2,uVar3);
          if (pDVar21 != (DH *)0x0) {
            iVar12 = param_1[0x16];
            goto LAB_0004850a;
          }
        }
        local_a0 = (RSA *)0x0;
        ERR_put_error(0x14,0x9b,0xab,"s3_srvr.c",0x65f);
        uVar3 = 0x28;
        goto LAB_000486ec;
      }
LAB_0004850a:
      if (*(int *)(iVar12 + 0x348) != 0) {
        iVar12 = 0x665;
LAB_00048a18:
        ERR_put_error(0x14,0x9b,0x44,"s3_srvr.c",iVar12);
        goto LAB_00048a28;
      }
      dh = DHparams_dup(pDVar21);
      iVar12 = 0x66b;
      if (dh == (DH *)0x0) {
LAB_00048a56:
        ERR_put_error(0x14,0x9b,5,"s3_srvr.c",iVar12);
        goto LAB_00048a28;
      }
      pBVar4 = *(BIGNUM **)&pDVar21->field_0x14;
      *(DH **)(param_1[0x16] + 0x348) = dh;
      if (((pBVar4 == (BIGNUM *)0x0) || (*(int *)&pDVar21->field_0x18 == 0)) ||
         (param_1[0x40] << 0xb < 0)) {
        iVar9 = DH_generate_key(dh);
        iVar12 = 0x677;
        if (iVar9 == 0) goto LAB_00048a56;
        iVar12 = *(int *)&dh->field_0x14;
      }
      else {
        pBVar4 = BN_dup(pBVar4);
        *(BIGNUM **)&dh->field_0x14 = pBVar4;
        pBVar4 = BN_dup(*(BIGNUM **)&pDVar21->field_0x18);
        iVar12 = *(int *)&dh->field_0x14;
        *(BIGNUM **)&dh->field_0x18 = pBVar4;
        if ((iVar12 == 0) || (pBVar4 == (BIGNUM *)0x0)) {
          iVar12 = 0x682;
          goto LAB_00048a56;
        }
      }
      pRVar20 = *(RSA **)&dh->field_0x8;
      local_84 = *(int *)&dh->field_0xc;
      local_80 = iVar12;
LAB_00048314:
      local_8c = (RSA *)0x0;
      pRVar11 = pRVar20;
      local_88 = pRVar20;
      if (pRVar20 == (RSA *)0x0) {
        iVar12 = param_1[0x16];
        local_a8 = pRVar20;
        local_a0 = pRVar20;
        local_9c = pRVar20;
        goto LAB_0004837a;
      }
      cnt = (RSA *)(uVar14 & 0x400);
      pRVar2 = pRVar20;
      pRVar18 = cnt;
      iVar12 = local_84;
      iVar9 = local_80;
      pRVar1 = local_7c;
      if (cnt != (RSA *)0x0) goto LAB_000485b6;
      do {
        iVar9 = BN_num_bits((BIGNUM *)pRVar2);
        puVar16 = &local_8c->field_0x1;
        iVar12 = iVar9 + 7;
        if (iVar9 + 7 < 0) {
          iVar12 = iVar9 + 0xe;
        }
        aiStack_78[(int)pRVar18] = iVar12 >> 3;
        pRVar2 = (&local_88)[(int)puVar16];
        cnt = (RSA *)(&cnt->field_0x2 + aiStack_78[(int)local_8c]);
        local_8c = (RSA *)puVar16;
        if (pRVar2 == (RSA *)0x0) goto LAB_00048370;
        pRVar18 = (RSA *)puVar16;
      } while ((int)puVar16 < 4);
LAB_0004860c:
      local_a8._0_1_ = '\0';
      local_9c = (RSA *)0x0;
      local_a0 = (RSA *)0x0;
      iVar12 = *(int *)(param_1[0x16] + 0x344);
      uVar13 = *(uint *)(iVar12 + 0x10);
      pRVar11 = pRVar20;
      goto joined_r0x00048620;
    }
    local_a8 = (RSA *)(uVar14 & 0x80);
    if (local_a8 == (RSA *)0x0) {
      if ((int)(uVar14 << 0x17) < 0) {
        sVar7 = strlen(*(char **)(param_1[0x39] + 0x14c));
        pRVar20 = (RSA *)(sVar7 + 2);
        local_a0 = local_a8;
        local_9c = local_a8;
LAB_00048844:
        pRVar11 = (RSA *)0x0;
        local_8c = (RSA *)0x0;
        goto LAB_0004837a;
      }
      local_a0 = (RSA *)(uVar14 & 0x400);
      if (local_a0 == (RSA *)0x0) {
        ERR_put_error(0x14,0x9b,0xfa,"s3_srvr.c",0x726);
        uVar3 = 0x28;
        goto LAB_000486ec;
      }
      if ((((RSA *)param_1[0x6a] == (RSA *)0x0) || (param_1[0x6b] == 0)) ||
         ((param_1[0x6c] == 0 ||
          (pRVar20 = (RSA *)param_1[0x6a], iVar12 = param_1[0x6b], iVar9 = param_1[0x6c],
          pRVar1 = (RSA *)param_1[0x6d], (RSA *)param_1[0x6d] == (RSA *)0x0)))) {
        ERR_put_error(0x14,0x9b,0x166,"s3_srvr.c",0x71a);
        goto LAB_00048a28;
      }
LAB_000485b6:
      local_7c = pRVar1;
      local_80 = iVar9;
      local_84 = iVar12;
      local_88 = pRVar20;
      pRVar20 = local_88;
      local_8c = (RSA *)0x0;
      cnt = (RSA *)0x0;
      pRVar2 = local_88;
      do {
        while( true ) {
          pRVar11 = local_8c;
          iVar9 = BN_num_bits((BIGNUM *)pRVar2);
          iVar12 = iVar9 + 7;
          if (iVar9 + 7 < 0) {
            iVar12 = iVar9 + 0xe;
          }
          aiStack_78[(int)pRVar11] = iVar12 >> 3;
          pRVar11 = pRVar20;
          if (local_8c != (RSA *)0x2) break;
          local_8c = (RSA *)0x3;
          cnt = (RSA *)(&cnt->field_0x1 + aiStack_78[2]);
          pRVar2 = local_7c;
          if (local_7c == (RSA *)0x0) goto LAB_00048370;
        }
        puVar16 = &local_8c->field_0x1;
        pRVar2 = (&local_88)[(int)puVar16];
        cnt = (RSA *)(&cnt->field_0x2 + aiStack_78[(int)local_8c]);
        local_8c = (RSA *)puVar16;
        if (pRVar2 == (RSA *)0x0) goto LAB_00048370;
      } while ((int)puVar16 < 4);
      goto LAB_0004860c;
    }
    pEVar5 = *(EC_KEY **)(iVar17 + 0x28);
    if (pEVar5 == (EC_KEY *)0x0) {
      if (*(code **)(iVar17 + 0x2c) != (code *)0x0) {
        if ((*(uint *)(iVar9 + 0x20) & 8) == 0) {
          uVar3 = 0x400;
        }
        else {
          uVar3 = 0x200;
        }
        pEVar5 = (EC_KEY *)(**(code **)(iVar17 + 0x2c))(param_1,*(uint *)(iVar9 + 0x20) & 2,uVar3);
        if (pEVar5 != (EC_KEY *)0x0) {
          iVar12 = param_1[0x16];
          goto LAB_00048726;
        }
      }
      local_a0 = (RSA *)0x0;
      ERR_put_error(0x14,0x9b,0x137,"s3_srvr.c",0x69b);
      uVar3 = 0x28;
      goto LAB_000486ec;
    }
LAB_00048726:
    if (*(int *)(iVar12 + 0x34c) != 0) {
      iVar12 = 0x6a1;
      goto LAB_00048a18;
    }
    pEVar5 = EC_KEY_dup(pEVar5);
    iVar12 = 0x6ad;
    if (pEVar5 != (EC_KEY *)0x0) {
      *(EC_KEY **)(param_1[0x16] + 0x34c) = pEVar5;
      pEVar6 = EC_KEY_get0_public_key(pEVar5);
      if ((((pEVar6 == (EC_POINT *)0x0) ||
           (pBVar4 = EC_KEY_get0_private_key(pEVar5), pBVar4 == (BIGNUM *)0x0)) ||
          (param_1[0x40] << 0xc < 0)) && (iVar12 = EC_KEY_generate_key(pEVar5), iVar12 == 0)) {
        iVar12 = 0x6b8;
        goto LAB_00048b2a;
      }
      group = EC_KEY_get0_group(pEVar5);
      if (((group == (EC_GROUP *)0x0) ||
          (pEVar6 = EC_KEY_get0_public_key(pEVar5), pEVar6 == (EC_POINT *)0x0)) ||
         (pBVar4 = EC_KEY_get0_private_key(pEVar5), pBVar4 == (BIGNUM *)0x0)) {
        iVar12 = 0x6c1;
        goto LAB_00048b2a;
      }
      if ((*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x20) << 0x1e < 0) &&
         (iVar12 = EC_GROUP_get_degree(group), 0xa3 < iVar12)) {
        ERR_put_error(0x14,0x9b,0x136,"s3_srvr.c",0x6c8);
        goto LAB_00048a28;
      }
      EC_GROUP_get_curve_name(group);
      local_a8 = (RSA *)tls1_ec_nid2curve_id();
      if (local_a8 == (RSA *)0x0) {
        ERR_put_error(0x14,0x9b,0x13b,"s3_srvr.c",0x6d4);
        goto LAB_00048a28;
      }
      pEVar6 = EC_KEY_get0_public_key(pEVar5);
      sVar7 = EC_POINT_point2oct(group,pEVar6,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                 (BN_CTX *)0x0);
      local_a0 = (RSA *)CRYPTO_malloc(sVar7,"s3_srvr.c",0x6e2);
      ctx = BN_CTX_new();
      if (local_a0 == (RSA *)0x0 || ctx == (BN_CTX *)0x0) {
        ERR_put_error(0x14,0x9b,0x41,"s3_srvr.c",0x6e6);
        goto LAB_000486f8;
      }
      pEVar6 = EC_KEY_get0_public_key(pEVar5);
      local_9c = (RSA *)EC_POINT_point2oct(group,pEVar6,POINT_CONVERSION_UNCOMPRESSED,
                                           (uchar *)local_a0,sVar7,ctx);
      if (local_9c != (RSA *)0x0) {
        pRVar20 = (RSA *)&local_9c->field_0x4;
        BN_CTX_free(ctx);
        iVar12 = param_1[0x16];
        local_88 = (RSA *)0x0;
        local_84 = 0;
        local_80 = 0;
        local_7c = (RSA *)0x0;
        goto LAB_00048844;
      }
      ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",0x6f2);
      goto LAB_000486fc;
    }
LAB_00048b2a:
    ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",iVar12);
LAB_00048a28:
    ctx = (BN_CTX *)0x0;
LAB_00048702:
    BN_CTX_free(ctx);
    EVP_MD_CTX_cleanup(&EStack_68);
    uVar3 = 0xffffffff;
    goto LAB_000484e8;
  }
  goto LAB_000484d4;
LAB_00048370:
  iVar12 = param_1[0x16];
  local_a8 = (RSA *)0x0;
  local_9c = (RSA *)0x0;
  local_a0 = (RSA *)0x0;
  pRVar20 = cnt;
LAB_0004837a:
  iVar12 = *(int *)(iVar12 + 0x344);
  uVar13 = *(uint *)(iVar12 + 0x10);
  cnt = pRVar20;
joined_r0x00048620:
  pEVar8 = (EVP_PKEY *)(uVar13 & 4);
  if (pEVar8 == (EVP_PKEY *)0x0) {
    local_ac = pEVar8;
    if (-1 < *(int *)(iVar12 + 0xc) << 0x17) {
      local_ac = (EVP_PKEY *)ssl_get_sign_pkey(param_1,iVar12,&local_90);
      if (local_ac == (EVP_PKEY *)0x0) {
        uVar3 = 0x32;
        goto LAB_000486ec;
      }
      pEVar8 = (EVP_PKEY *)EVP_PKEY_size(local_ac);
    }
  }
  else {
    pEVar8 = (EVP_PKEY *)0x0;
    local_ac = (EVP_PKEY *)0x0;
  }
  piVar19 = (int *)&cnt->field_0x4;
  ctx = (BN_CTX *)BUF_MEM_grow_clean(str,(int)&pEVar8->type + (int)piVar19);
  if (ctx == (BN_CTX *)0x0) {
    ERR_put_error(0x14,0x9b,7,"s3_srvr.c",0x747);
    goto LAB_000486f8;
  }
  local_8c = (RSA *)0x0;
  puVar16 = *(undefined **)(param_1[0xf] + 4);
  d = puVar16 + 4;
  puVar22 = d;
  if (pRVar11 != (RSA *)0x0) {
    puVar10 = (undefined *)(uVar14 & 0x400);
    if (puVar10 == (undefined *)0x0) {
      do {
        *puVar22 = (uchar)((uint)aiStack_78[(int)puVar10] >> 8);
        puVar22[1] = (uchar)aiStack_78[(int)local_8c];
        BN_bn2bin((BIGNUM *)(&local_88)[(int)local_8c],puVar22 + 2);
        puVar10 = &local_8c->field_0x1;
        puVar22 = puVar22 + 2 + aiStack_78[(int)local_8c];
        local_8c = (RSA *)puVar10;
        if ((&local_88)[(int)puVar10] == (RSA *)0x0) break;
      } while ((int)puVar10 < 4);
    }
    else {
      do {
        if (local_8c == (RSA *)0x2) {
          puVar15 = puVar22 + 1;
          *puVar22 = (uchar)aiStack_78[2];
        }
        else {
          puVar15 = puVar22 + 2;
          *puVar22 = (uchar)((uint)aiStack_78[(int)local_8c] >> 8);
          puVar22[1] = (uchar)aiStack_78[(int)local_8c];
        }
        BN_bn2bin((BIGNUM *)(&local_88)[(int)local_8c],puVar15);
        puVar10 = &local_8c->field_0x1;
        puVar22 = puVar15 + aiStack_78[(int)local_8c];
        local_8c = (RSA *)puVar10;
      } while (((&local_88)[(int)puVar10] != (RSA *)0x0) && ((int)puVar10 < 4));
    }
  }
  if ((int)(uVar14 << 0x18) < 0) {
    puVar22[2] = (uchar)local_a8;
    puVar22[3] = (uchar)local_9c;
    *puVar22 = '\x03';
    puVar22[1] = '\0';
    memcpy(puVar22 + 4,local_a0,(size_t)local_9c);
    CRYPTO_free(local_a0);
    local_a0 = (RSA *)0x0;
    puVar22 = puVar22 + 4 + (int)&local_9c->field_0x0;
  }
  if ((int)(uVar14 << 0x17) < 0) {
    sVar7 = strlen(*(char **)(param_1[0x39] + 0x14c));
    *puVar22 = (uchar)(sVar7 >> 8);
    sVar7 = strlen(*(char **)(param_1[0x39] + 0x14c));
    puVar22[1] = (uchar)sVar7;
    __s = *(char **)(param_1[0x39] + 0x14c);
    sVar7 = strlen(__s);
    strncpy((char *)(puVar22 + 2),__s,sVar7);
    sVar7 = strlen(*(char **)(param_1[0x39] + 0x14c));
    puVar22 = puVar22 + 2 + sVar7;
  }
  if (local_ac != (EVP_PKEY *)0x0) {
    if ((local_ac->type != 6) || ((*param_1 >> 8 == 3 && (0x302 < *param_1)))) {
      if (local_90 == (EVP_MD *)0x0) {
        ERR_put_error(0x14,0x9b,0xfb,"s3_srvr.c",0x7ca);
        uVar3 = 0x28;
LAB_000486ec:
        ctx = (BN_CTX *)0x0;
        ssl3_send_alert(param_1,2,uVar3);
      }
      else {
        if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
          iVar12 = tls12_get_sigandhash(puVar22,local_ac);
          puVar22 = puVar22 + 2;
          if (iVar12 == 0) {
            ERR_put_error(0x14,0x9b,0x44,"s3_srvr.c",0x7ae);
            uVar3 = 0x50;
            goto LAB_000486ec;
          }
        }
        EVP_DigestInit_ex(&EStack_68,local_90,(ENGINE *)0x0);
        EVP_DigestUpdate(&EStack_68,(void *)(param_1[0x16] + 0xc0),0x20);
        EVP_DigestUpdate(&EStack_68,(void *)(param_1[0x16] + 0xa0),0x20);
        EVP_DigestUpdate(&EStack_68,d,(size_t)cnt);
        ctx = (BN_CTX *)EVP_SignFinal(&EStack_68,puVar22 + 2,(uint *)&local_8c,local_ac);
        if (ctx != (BN_CTX *)0x0) {
          *puVar22 = (uchar)((uint)local_8c >> 8);
          puVar22[1] = (uchar)local_8c;
          cnt = (RSA *)(&local_8c->field_0x2 + (int)&cnt->field_0x0);
          if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
            piVar19 = (int *)&cnt->field_0x6;
            cnt = (RSA *)&cnt->field_0x2;
          }
          else {
            piVar19 = (int *)&cnt->field_0x4;
          }
          goto LAB_000484b6;
        }
        ERR_put_error(0x14,0x9b,6,"s3_srvr.c",0x7be);
      }
LAB_000486f8:
      if (local_a0 != (RSA *)0x0) {
LAB_000486fc:
        CRYPTO_free(local_a0);
      }
      goto LAB_00048702;
    }
    puVar15 = auStack_50;
    ctx = (BN_CTX *)0x2;
    puVar10 = (undefined *)0x0;
    do {
      EVP_MD_CTX_set_flags(&EStack_68,8);
      if (ctx == (BN_CTX *)0x2) {
        type = *(EVP_MD **)(param_1[0x39] + 0x8c);
      }
      else {
        type = *(EVP_MD **)(param_1[0x39] + 0x90);
      }
      EVP_DigestInit_ex(&EStack_68,type,(ENGINE *)0x0);
      EVP_DigestUpdate(&EStack_68,(void *)(param_1[0x16] + 0xc0),0x20);
      EVP_DigestUpdate(&EStack_68,(void *)(param_1[0x16] + 0xa0),0x20);
      EVP_DigestUpdate(&EStack_68,d,(size_t)cnt);
      EVP_DigestFinal_ex(&EStack_68,puVar15,(uint *)&local_8c);
      ctx = ctx + -1;
      puVar15 = puVar15 + (int)local_8c;
      puVar10 = &local_8c->field_0x0 + (int)puVar10;
    } while (ctx != (BN_CTX *)0x0);
    iVar12 = RSA_sign(0x72,auStack_50,(uint)puVar10,puVar22 + 2,&local_94,(local_ac->pkey).rsa);
    if (iVar12 < 1) {
      ERR_put_error(0x14,0x9b,4,"s3_srvr.c",0x79c);
      goto LAB_000486f8;
    }
    *puVar22 = (uchar)(local_94 >> 8);
    puVar22[1] = (uchar)local_94;
    cnt = (RSA *)(&cnt->field_0x2 + local_94);
    piVar19 = (int *)&cnt->field_0x4;
  }
LAB_000484b6:
  puVar16[3] = (char)cnt;
  puVar16[1] = (char)((uint)cnt >> 0x10);
  *puVar16 = 0xc;
  puVar16[2] = (char)((uint)cnt >> 8);
  param_1[0x11] = (int)piVar19;
  param_1[0x12] = 0;
LAB_000484d4:
  param_1[0xd] = 0x2151;
  EVP_MD_CTX_cleanup(&EStack_68);
  uVar3 = ssl3_do_write(param_1,0x16);
LAB_000484e8:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

