
void dtls1_send_server_key_exchange(int param_1)

{
  uint uVar1;
  BN_CTX *ctx;
  EVP_MD *pEVar2;
  undefined4 uVar3;
  DH *dh;
  BIGNUM *pBVar4;
  size_t sVar5;
  EC_KEY *pEVar6;
  EC_POINT *pEVar7;
  EC_GROUP *group;
  void *pvVar8;
  EVP_PKEY *pkey;
  int iVar9;
  uchar *d;
  int iVar10;
  uint uVar11;
  EVP_PKEY *pEVar12;
  uint uVar13;
  uchar *md;
  BUF_MEM *str;
  RSA *cnt;
  int iVar14;
  RSA *pRVar15;
  uchar *puVar16;
  DH *pDVar17;
  char *__s;
  int *piVar18;
  RSA *local_a4;
  RSA *local_98;
  RSA *local_94;
  uint local_90;
  uint local_8c;
  RSA *local_88 [2];
  int local_80;
  undefined4 local_7c;
  int aiStack_78 [4];
  EVP_MD_CTX EStack_68;
  uchar auStack_50 [36];
  int local_2c;
  
  local_2c = __TMC_END__;
  EVP_MD_CTX_init(&EStack_68);
  if (*(int *)(param_1 + 0x34) != 0x2150) {
LAB_00058e50:
    *(undefined4 *)(param_1 + 0x34) = 0x2151;
    EVP_MD_CTX_cleanup(&EStack_68);
    uVar3 = dtls1_do_write(param_1,0x16);
    goto LAB_00058e64;
  }
  iVar10 = *(int *)(param_1 + 0x58);
  iVar14 = *(int *)(param_1 + 0x98);
  local_7c = 0;
  iVar9 = *(int *)(iVar10 + 0x344);
  local_80 = 0;
  local_88[1] = (RSA *)0x0;
  uVar13 = *(uint *)(iVar9 + 0xc);
  local_88[0] = (RSA *)0x0;
  str = *(BUF_MEM **)(param_1 + 0x3c);
  if ((int)(uVar13 << 0x1f) < 0) {
    local_98 = *(RSA **)(iVar14 + 0x18);
    if (local_98 == (RSA *)0x0) {
      local_98 = *(RSA **)(iVar14 + 0x1c);
      if (local_98 == (RSA *)0x0) {
        ERR_put_error(0x14,0x10b,0xac,"d1_srvr.c",0x446);
        uVar3 = 0x28;
      }
      else {
        if ((*(uint *)(iVar9 + 0x20) & 8) == 0) {
          uVar3 = 0x400;
        }
        else {
          uVar3 = 0x200;
        }
        local_98 = (RSA *)(*(code *)local_98)(param_1,*(uint *)(iVar9 + 0x20) & 2,uVar3);
        if (local_98 != (RSA *)0x0) {
          RSA_up_ref(local_98);
          *(RSA **)(iVar14 + 0x18) = local_98;
          iVar10 = *(int *)(param_1 + 0x58);
          goto LAB_00058c9a;
        }
        ERR_put_error(0x14,0x10b,0x11a,"d1_srvr.c",0x43d);
        uVar3 = 0x28;
      }
LAB_00059254:
      ctx = (BN_CTX *)0x0;
      ssl3_send_alert(param_1,2,uVar3);
    }
    else {
LAB_00058c9a:
      pRVar15 = *(RSA **)&local_98->field_0x10;
      local_88[1] = *(RSA **)&local_98->field_0x14;
      *(undefined4 *)(iVar10 + 0x370) = 1;
LAB_00058cae:
      local_8c = 0;
      local_a4 = pRVar15;
      local_88[0] = pRVar15;
      if (pRVar15 == (RSA *)0x0) {
        iVar10 = *(int *)(param_1 + 0x58);
        cnt = pRVar15;
        local_98 = pRVar15;
        local_94 = pRVar15;
      }
      else {
        cnt = (RSA *)0x0;
        do {
          uVar1 = local_8c;
          iVar10 = BN_num_bits((BIGNUM *)local_a4);
          uVar11 = local_8c + 1;
          iVar9 = iVar10 + 7;
          if (iVar10 + 7 < 0) {
            iVar9 = iVar10 + 0xe;
          }
          aiStack_78[uVar1] = iVar9 >> 3;
          local_a4 = local_88[uVar11];
          cnt = (RSA *)(&cnt->field_0x2 + aiStack_78[local_8c]);
          local_8c = uVar11;
        } while (local_a4 != (RSA *)0x0);
        iVar10 = *(int *)(param_1 + 0x58);
        local_98 = local_a4;
        local_94 = local_a4;
      }
LAB_00058d06:
      pEVar12 = (EVP_PKEY *)(*(uint *)(*(int *)(iVar10 + 0x344) + 0x10) & 4);
      if (pEVar12 == (EVP_PKEY *)0x0) {
        pkey = pEVar12;
        if ((*(uint *)(*(int *)(iVar10 + 0x344) + 0xc) & 0x100) == 0) {
          pkey = (EVP_PKEY *)ssl_get_sign_pkey(param_1);
          if (pkey == (EVP_PKEY *)0x0) {
            uVar3 = 0x32;
            goto LAB_00059254;
          }
          pEVar12 = (EVP_PKEY *)EVP_PKEY_size(pkey);
        }
      }
      else {
        pEVar12 = (EVP_PKEY *)0x0;
        pkey = (EVP_PKEY *)0x0;
      }
      piVar18 = (int *)&cnt->field_0xc;
      ctx = (BN_CTX *)BUF_MEM_grow_clean(str,(int)&pEVar12->type + (int)piVar18);
      if (ctx == (BN_CTX *)0x0) {
        ERR_put_error(0x14,0x10b,7,"d1_srvr.c",0x52d);
      }
      else {
        local_8c = 0;
        iVar9 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
        d = (uchar *)(iVar9 + 0xc);
        puVar16 = d;
        while (pRVar15 != (RSA *)0x0) {
          *puVar16 = (uchar)((uint)aiStack_78[local_8c] >> 8);
          puVar16[1] = (uchar)aiStack_78[local_8c];
          BN_bn2bin((BIGNUM *)local_88[local_8c],puVar16 + 2);
          puVar16 = puVar16 + 2 + aiStack_78[local_8c];
          pRVar15 = local_88[local_8c + 1];
          local_8c = local_8c + 1;
        }
        if ((int)(uVar13 << 0x18) < 0) {
          puVar16[2] = (uchar)local_a4;
          puVar16[3] = (uchar)local_94;
          *puVar16 = '\x03';
          puVar16[1] = '\0';
          pvVar8 = memcpy(puVar16 + 4,local_98,(size_t)local_94);
          CRYPTO_free(local_98);
          puVar16 = (uchar *)((int)&local_94->field_0x0 + (int)pvVar8);
        }
        if ((int)(uVar13 << 0x17) < 0) {
          sVar5 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
          *puVar16 = (uchar)(sVar5 >> 8);
          sVar5 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
          puVar16[1] = (uchar)sVar5;
          __s = *(char **)(*(int *)(param_1 + 0xe4) + 0x14c);
          sVar5 = strlen(__s);
          strncpy((char *)(puVar16 + 2),__s,sVar5);
          sVar5 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
          puVar16 = puVar16 + 2 + sVar5;
        }
        if (pkey == (EVP_PKEY *)0x0) {
LAB_00058e2e:
          dtls1_set_message_header(param_1,iVar9,0xc,cnt,0,cnt);
          *(undefined4 *)(param_1 + 0x48) = 0;
          *(int **)(param_1 + 0x44) = piVar18;
          dtls1_buffer_message(param_1,0);
          goto LAB_00058e50;
        }
        iVar10 = pkey->type;
        if (iVar10 == 6) {
          md = auStack_50;
          ctx = (BN_CTX *)0x2;
          uVar13 = 0;
          do {
            if (ctx == (BN_CTX *)0x2) {
              pEVar2 = *(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c);
            }
            else {
              pEVar2 = *(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90);
            }
            EVP_DigestInit_ex(&EStack_68,pEVar2,(ENGINE *)0x0);
            EVP_DigestUpdate(&EStack_68,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
            EVP_DigestUpdate(&EStack_68,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
            EVP_DigestUpdate(&EStack_68,d,(size_t)cnt);
            EVP_DigestFinal_ex(&EStack_68,md,&local_8c);
            ctx = ctx + -1;
            md = md + local_8c;
            uVar13 = uVar13 + local_8c;
          } while (ctx != (BN_CTX *)0x0);
          iVar10 = RSA_sign(0x72,auStack_50,uVar13,puVar16 + 2,&local_90,(pkey->pkey).rsa);
          if (0 < iVar10) {
            *puVar16 = (uchar)(local_90 >> 8);
            puVar16[1] = (uchar)local_90;
            cnt = (RSA *)(&cnt->field_0x2 + local_90);
            piVar18 = (int *)&cnt->field_0xc;
            goto LAB_00058e2e;
          }
          ERR_put_error(0x14,0x10b,4,"d1_srvr.c",0x577);
        }
        else if (iVar10 == 0x74) {
          pEVar2 = EVP_dss1();
          EVP_DigestInit_ex(&EStack_68,pEVar2,(ENGINE *)0x0);
          EVP_DigestUpdate(&EStack_68,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
          EVP_DigestUpdate(&EStack_68,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
          EVP_DigestUpdate(&EStack_68,d,(size_t)cnt);
          ctx = (BN_CTX *)EVP_SignFinal(&EStack_68,puVar16 + 2,&local_8c,pkey);
          if (ctx != (BN_CTX *)0x0) {
LAB_00058e16:
            *puVar16 = (uchar)(local_8c >> 8);
            puVar16[1] = (uchar)local_8c;
            cnt = (RSA *)(&cnt->field_0x2 + local_8c);
            piVar18 = (int *)&cnt->field_0xc;
            goto LAB_00058e2e;
          }
          ERR_put_error(0x14,0x10b,10,"d1_srvr.c",0x58a);
        }
        else {
          if (iVar10 != 0x198) {
            ERR_put_error(0x14,0x10b,0xfb,"d1_srvr.c",0x5a8);
            uVar3 = 0x28;
            goto LAB_00059254;
          }
          pEVar2 = EVP_ecdsa();
          EVP_DigestInit_ex(&EStack_68,pEVar2,(ENGINE *)0x0);
          EVP_DigestUpdate(&EStack_68,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
          EVP_DigestUpdate(&EStack_68,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
          EVP_DigestUpdate(&EStack_68,d,(size_t)cnt);
          ctx = (BN_CTX *)EVP_SignFinal(&EStack_68,puVar16 + 2,&local_8c,pkey);
          if (ctx != (BN_CTX *)0x0) goto LAB_00058e16;
          ERR_put_error(0x14,0x10b,0x2a,"d1_srvr.c",0x59d);
        }
      }
    }
LAB_000591e0:
    if (local_98 != (RSA *)0x0) {
LAB_000591e4:
      CRYPTO_free(local_98);
    }
  }
  else {
    if ((int)(uVar13 << 0x1c) < 0) {
      pDVar17 = *(DH **)(iVar14 + 0x20);
      if (pDVar17 == (DH *)0x0) {
        if (*(code **)(iVar14 + 0x24) != (code *)0x0) {
          if ((*(uint *)(iVar9 + 0x20) & 8) == 0) {
            uVar3 = 0x400;
          }
          else {
            uVar3 = 0x200;
          }
          pDVar17 = (DH *)(**(code **)(iVar14 + 0x24))(param_1,*(uint *)(iVar9 + 0x20) & 2,uVar3);
          if (pDVar17 != (DH *)0x0) {
            iVar10 = *(int *)(param_1 + 0x58);
            goto LAB_00058e84;
          }
        }
        local_98 = (RSA *)0x0;
        ERR_put_error(0x14,0x10b,0xab,"d1_srvr.c",0x45a);
        uVar3 = 0x28;
        goto LAB_00059254;
      }
LAB_00058e84:
      if (*(int *)(iVar10 + 0x348) != 0) {
        DH_free((DH *)0x0);
        iVar9 = 0x461;
LAB_00059274:
        ERR_put_error(0x14,0x10b,0x44,"d1_srvr.c",iVar9);
        goto LAB_00059282;
      }
      dh = DHparams_dup(pDVar17);
      iVar9 = 0x467;
      if (dh == (DH *)0x0) {
LAB_000592b0:
        ERR_put_error(0x14,0x10b,5,"d1_srvr.c",iVar9);
        goto LAB_00059282;
      }
      pBVar4 = *(BIGNUM **)&pDVar17->field_0x14;
      *(DH **)(*(int *)(param_1 + 0x58) + 0x348) = dh;
      if (((pBVar4 == (BIGNUM *)0x0) || (*(int *)&pDVar17->field_0x18 == 0)) ||
         (*(int *)(param_1 + 0x100) << 0xb < 0)) {
        iVar10 = DH_generate_key(dh);
        iVar9 = 0x473;
        if (iVar10 == 0) goto LAB_000592b0;
        iVar9 = *(int *)&dh->field_0x14;
      }
      else {
        pBVar4 = BN_dup(pBVar4);
        *(BIGNUM **)&dh->field_0x14 = pBVar4;
        pBVar4 = BN_dup(*(BIGNUM **)&pDVar17->field_0x18);
        iVar9 = *(int *)&dh->field_0x14;
        *(BIGNUM **)&dh->field_0x18 = pBVar4;
        if ((iVar9 == 0) || (pBVar4 == (BIGNUM *)0x0)) {
          iVar9 = 0x47e;
          goto LAB_000592b0;
        }
      }
      pRVar15 = *(RSA **)&dh->field_0x8;
      local_88[1] = *(RSA **)&dh->field_0xc;
      local_80 = iVar9;
      goto LAB_00058cae;
    }
    local_a4 = (RSA *)(uVar13 & 0x80);
    if (local_a4 == (RSA *)0x0) {
      local_98 = (RSA *)(uVar13 & 0x100);
      if (local_98 == (RSA *)0x0) {
        ERR_put_error(0x14,0x10b,0xfa,"d1_srvr.c",0x511);
        uVar3 = 0x28;
        goto LAB_00059254;
      }
      sVar5 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
      cnt = (RSA *)(sVar5 + 2);
      local_98 = local_a4;
      local_94 = local_a4;
LAB_00059176:
      pRVar15 = (RSA *)0x0;
      local_8c = 0;
      goto LAB_00058d06;
    }
    pEVar6 = *(EC_KEY **)(iVar14 + 0x28);
    if (pEVar6 == (EC_KEY *)0x0) {
      if (*(code **)(iVar14 + 0x2c) != (code *)0x0) {
        if ((*(uint *)(iVar9 + 0x20) & 8) == 0) {
          uVar3 = 0x400;
        }
        else {
          uVar3 = 0x200;
        }
        pEVar6 = (EC_KEY *)(**(code **)(iVar14 + 0x2c))(param_1,*(uint *)(iVar9 + 0x20) & 2,uVar3);
        if (pEVar6 != (EC_KEY *)0x0) {
          iVar10 = *(int *)(param_1 + 0x58);
          goto LAB_00058f4c;
        }
      }
      local_98 = (RSA *)0x0;
      ERR_put_error(0x14,0x10b,0x137,"d1_srvr.c",0x497);
      uVar3 = 0x28;
      goto LAB_00059254;
    }
LAB_00058f4c:
    if (*(EC_KEY **)(iVar10 + 0x34c) != (EC_KEY *)0x0) {
      EC_KEY_free(*(EC_KEY **)(iVar10 + 0x34c));
      iVar9 = 0x49e;
      goto LAB_00059274;
    }
    pEVar6 = EC_KEY_dup(pEVar6);
    iVar9 = 0x4aa;
    if (pEVar6 == (EC_KEY *)0x0) {
LAB_000593ba:
      ERR_put_error(0x14,0x10b,0x2b,"d1_srvr.c",iVar9);
    }
    else {
      *(EC_KEY **)(*(int *)(param_1 + 0x58) + 0x34c) = pEVar6;
      pEVar7 = EC_KEY_get0_public_key(pEVar6);
      if ((((pEVar7 == (EC_POINT *)0x0) ||
           (pBVar4 = EC_KEY_get0_private_key(pEVar6), pBVar4 == (BIGNUM *)0x0)) ||
          (*(int *)(param_1 + 0x100) << 0xc < 0)) &&
         (iVar9 = EC_KEY_generate_key(pEVar6), iVar9 == 0)) {
        iVar9 = 0x4b5;
        goto LAB_000593ba;
      }
      group = EC_KEY_get0_group(pEVar6);
      if (((group == (EC_GROUP *)0x0) ||
          (pEVar7 = EC_KEY_get0_public_key(pEVar6), pEVar7 == (EC_POINT *)0x0)) ||
         (pBVar4 = EC_KEY_get0_private_key(pEVar6), pBVar4 == (BIGNUM *)0x0)) {
        iVar9 = 0x4be;
        goto LAB_000593ba;
      }
      if ((*(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) << 0x1e < 0) &&
         (iVar9 = EC_GROUP_get_degree(group), 0xa3 < iVar9)) {
        ERR_put_error(0x14,0x10b,0x136,"d1_srvr.c",0x4c5);
      }
      else {
        EC_GROUP_get_curve_name(group);
        local_a4 = (RSA *)tls1_ec_nid2curve_id();
        if (local_a4 != (RSA *)0x0) {
          pEVar7 = EC_KEY_get0_public_key(pEVar6);
          sVar5 = EC_POINT_point2oct(group,pEVar7,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                     (BN_CTX *)0x0);
          local_98 = (RSA *)CRYPTO_malloc(sVar5,"d1_srvr.c",0x4df);
          ctx = BN_CTX_new();
          if (local_98 == (RSA *)0x0 || ctx == (BN_CTX *)0x0) {
            ERR_put_error(0x14,0x10b,0x41,"d1_srvr.c",0x4e3);
            goto LAB_000591e0;
          }
          pEVar7 = EC_KEY_get0_public_key(pEVar6);
          local_94 = (RSA *)EC_POINT_point2oct(group,pEVar7,POINT_CONVERSION_UNCOMPRESSED,
                                               (uchar *)local_98,sVar5,ctx);
          if (local_94 != (RSA *)0x0) {
            cnt = (RSA *)&local_94->field_0x4;
            BN_CTX_free(ctx);
            local_88[0] = (RSA *)0x0;
            local_88[1] = (RSA *)0x0;
            local_80 = 0;
            local_7c = 0;
            iVar10 = *(int *)(param_1 + 0x58);
            goto LAB_00059176;
          }
          ERR_put_error(0x14,0x10b,0x2b,"d1_srvr.c",0x4ef);
          goto LAB_000591e4;
        }
        ERR_put_error(0x14,0x10b,0x13b,"d1_srvr.c",0x4d1);
      }
    }
LAB_00059282:
    ctx = (BN_CTX *)0x0;
  }
  BN_CTX_free(ctx);
  EVP_MD_CTX_cleanup(&EStack_68);
  uVar3 = 0xffffffff;
LAB_00058e64:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}

