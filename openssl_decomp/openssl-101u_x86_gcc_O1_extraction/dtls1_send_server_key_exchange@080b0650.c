
/* WARNING: Could not reconcile some variable overlaps */

undefined4 dtls1_send_server_key_exchange(int param_1)

{
  int *piVar1;
  BUF_MEM *str;
  char *__s;
  uint uVar2;
  BIGNUM *a;
  int iVar3;
  uchar *d;
  EVP_MD *pEVar4;
  int iVar5;
  undefined4 uVar6;
  DH *dh;
  EC_KEY *pEVar7;
  EC_POINT *pEVar8;
  EC_GROUP *group;
  size_t sVar9;
  RSA *r;
  BIGNUM *pBVar10;
  DH *pDVar11;
  int iVar12;
  size_t sVar13;
  uchar *md;
  BN_CTX *ctx;
  uchar *puVar14;
  uint uVar15;
  int in_GS_OFFSET;
  EVP_PKEY *local_a4;
  uchar *local_a0;
  size_t local_9c;
  int local_90;
  uint local_84;
  uint local_80;
  EVP_MD_CTX local_7c;
  BIGNUM *local_64 [2];
  int local_5c;
  undefined4 local_58;
  int aiStack_54 [4];
  uchar local_44 [36];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_7c);
  if (*(int *)(param_1 + 0x34) != 0x2150) {
LAB_080b0906:
    *(undefined4 *)(param_1 + 0x34) = 0x2151;
    EVP_MD_CTX_cleanup(&local_7c);
    uVar6 = dtls1_do_write(param_1,0x16);
    goto LAB_080b0927;
  }
  iVar12 = *(int *)(param_1 + 0x58);
  str = *(BUF_MEM **)(param_1 + 0x3c);
  iVar5 = *(int *)(param_1 + 0x98);
  local_58 = 0;
  local_5c = 0;
  local_64[1] = (BIGNUM *)0x0;
  iVar3 = *(int *)(iVar12 + 0x344);
  local_64[0] = (BIGNUM *)0x0;
  uVar15 = *(uint *)(iVar3 + 0xc);
  if ((uVar15 & 1) == 0) {
    if ((uVar15 & 8) != 0) {
      pDVar11 = *(DH **)(iVar5 + 0x20);
      if (pDVar11 == (DH *)0x0) {
        if ((*(code **)(iVar5 + 0x24) == (code *)0x0) ||
           (pDVar11 = (DH *)(**(code **)(iVar5 + 0x24))
                                      (param_1,*(uint *)(iVar3 + 0x20) & 2,
                                       (-(uint)((*(uint *)(iVar3 + 0x20) & 8) == 0) & 0x200) + 0x200
                                      ), pDVar11 == (DH *)0x0)) {
          iVar3 = 0x493;
          iVar5 = 0xab;
          goto LAB_080b1072;
        }
        iVar12 = *(int *)(param_1 + 0x58);
      }
      if (*(int *)(iVar12 + 0x348) != 0) {
        DH_free((DH *)0x0);
        iVar5 = 0x49a;
LAB_080b0f5e:
        ctx = (BN_CTX *)0x0;
        ERR_put_error(0x14,0x10b,0x44,"d1_srvr.c",iVar5);
        goto LAB_080b0e9f;
      }
      dh = DHparams_dup(pDVar11);
      if (dh == (DH *)0x0) {
        iVar5 = 0x49f;
      }
      else {
        *(DH **)(*(int *)(param_1 + 0x58) + 0x348) = dh;
        if (((*(BIGNUM **)&pDVar11->field_0x14 == (BIGNUM *)0x0) ||
            (*(int *)&pDVar11->field_0x18 == 0)) || ((*(byte *)(param_1 + 0x102) & 0x10) != 0)) {
          iVar5 = DH_generate_key(dh);
          if (iVar5 != 0) {
            iVar5 = *(int *)&dh->field_0x14;
            goto LAB_080b09c5;
          }
          iVar5 = 0x4a9;
        }
        else {
          pBVar10 = BN_dup(*(BIGNUM **)&pDVar11->field_0x14);
          *(BIGNUM **)&dh->field_0x14 = pBVar10;
          pBVar10 = BN_dup(*(BIGNUM **)&pDVar11->field_0x18);
          *(BIGNUM **)&dh->field_0x18 = pBVar10;
          iVar5 = *(int *)&dh->field_0x14;
          if ((pBVar10 != (BIGNUM *)0x0) && (iVar5 != 0)) {
LAB_080b09c5:
            pBVar10 = *(BIGNUM **)&dh->field_0x8;
            local_64[1] = *(BIGNUM **)&dh->field_0xc;
            local_5c = iVar5;
            goto LAB_080b06f4;
          }
          iVar5 = 0x4b1;
        }
      }
      ctx = (BN_CTX *)0x0;
      ERR_put_error(0x14,0x10b,5,"d1_srvr.c",iVar5);
      goto LAB_080b0e9f;
    }
    if ((uVar15 & 0x80) == 0) {
      if ((uVar15 & 0x100) == 0) {
        iVar3 = 0x540;
        iVar5 = 0xfa;
        goto LAB_080b1072;
      }
      sVar13 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
      sVar13 = sVar13 + 2;
      local_90 = 0;
      local_9c = 0;
      local_a0 = (uchar *)0x0;
LAB_080b0de0:
      local_80 = 0;
      pBVar10 = (BIGNUM *)0x0;
      goto LAB_080b0762;
    }
    pEVar7 = *(EC_KEY **)(iVar5 + 0x28);
    if (pEVar7 == (EC_KEY *)0x0) {
      if ((*(code **)(iVar5 + 0x2c) == (code *)0x0) ||
         (pEVar7 = (EC_KEY *)
                   (**(code **)(iVar5 + 0x2c))
                             (param_1,*(uint *)(iVar3 + 0x20) & 2,
                              (-(uint)((*(uint *)(iVar3 + 0x20) & 8) == 0) & 0x200) + 0x200),
         pEVar7 == (EC_KEY *)0x0)) {
        iVar3 = 0x4c9;
        iVar5 = 0x137;
        goto LAB_080b1072;
      }
      iVar12 = *(int *)(param_1 + 0x58);
    }
    if (*(EC_KEY **)(iVar12 + 0x34c) != (EC_KEY *)0x0) {
      EC_KEY_free(*(EC_KEY **)(iVar12 + 0x34c));
      iVar5 = 0x4d0;
      goto LAB_080b0f5e;
    }
    pEVar7 = EC_KEY_dup(pEVar7);
    if (pEVar7 == (EC_KEY *)0x0) {
      iVar5 = 0x4da;
    }
    else {
      *(EC_KEY **)(*(int *)(param_1 + 0x58) + 0x34c) = pEVar7;
      pEVar8 = EC_KEY_get0_public_key(pEVar7);
      if ((((pEVar8 == (EC_POINT *)0x0) ||
           (pBVar10 = EC_KEY_get0_private_key(pEVar7), pBVar10 == (BIGNUM *)0x0)) ||
          ((*(byte *)(param_1 + 0x102) & 8) != 0)) &&
         (iVar5 = EC_KEY_generate_key(pEVar7), iVar5 == 0)) {
        iVar5 = 0x4e4;
      }
      else {
        group = EC_KEY_get0_group(pEVar7);
        if (((group != (EC_GROUP *)0x0) &&
            (pEVar8 = EC_KEY_get0_public_key(pEVar7), pEVar8 != (EC_POINT *)0x0)) &&
           (pBVar10 = EC_KEY_get0_private_key(pEVar7), pBVar10 != (BIGNUM *)0x0)) {
          if (((*(byte *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 2) == 0) ||
             (iVar5 = EC_GROUP_get_degree(group), iVar5 < 0xa4)) {
            iVar5 = EC_GROUP_get_curve_name(group);
            local_90 = tls1_ec_nid2curve_id(iVar5);
            if (local_90 != 0) {
              pEVar8 = EC_KEY_get0_public_key(pEVar7);
              sVar13 = EC_POINT_point2oct(group,pEVar8,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                          (BN_CTX *)0x0);
              local_a0 = (uchar *)CRYPTO_malloc(sVar13,"d1_srvr.c",0x50e);
              ctx = BN_CTX_new();
              if ((local_a0 == (uchar *)0x0) || (ctx == (BN_CTX *)0x0)) {
                ERR_put_error(0x14,0x10b,0x41,"d1_srvr.c",0x512);
                goto LAB_080b0e88;
              }
              pEVar8 = EC_KEY_get0_public_key(pEVar7);
              local_9c = EC_POINT_point2oct(group,pEVar8,POINT_CONVERSION_UNCOMPRESSED,local_a0,
                                            sVar13,ctx);
              if (local_9c != 0) {
                BN_CTX_free(ctx);
                local_64[0] = (BIGNUM *)0x0;
                local_64[1] = (BIGNUM *)0x0;
                local_5c = 0;
                local_58 = 0;
                iVar12 = *(int *)(param_1 + 0x58);
                sVar13 = local_9c + 4;
                goto LAB_080b0de0;
              }
              ERR_put_error(0x14,0x10b,0x2b,"d1_srvr.c",0x51c);
              goto LAB_080b0e90;
            }
            ctx = (BN_CTX *)0x0;
            ERR_put_error(0x14,0x10b,0x13b,"d1_srvr.c",0x500);
          }
          else {
            ctx = (BN_CTX *)0x0;
            ERR_put_error(0x14,0x10b,0x136,"d1_srvr.c",0x4f3);
          }
          goto LAB_080b0e9f;
        }
        iVar5 = 0x4ec;
      }
    }
    ctx = (BN_CTX *)0x0;
    ERR_put_error(0x14,0x10b,0x2b,"d1_srvr.c",iVar5);
  }
  else {
    r = *(RSA **)(iVar5 + 0x18);
    if (r == (RSA *)0x0) {
      if (*(code **)(iVar5 + 0x1c) == (code *)0x0) {
        iVar3 = 0x47f;
        iVar5 = 0xac;
      }
      else {
        r = (RSA *)(**(code **)(iVar5 + 0x1c))
                             (param_1,*(uint *)(iVar3 + 0x20) & 2,
                              (-(uint)((*(uint *)(iVar3 + 0x20) & 8) == 0) & 0x200) + 0x200);
        if (r != (RSA *)0x0) {
          RSA_up_ref(r);
          *(RSA **)(iVar5 + 0x18) = r;
          iVar12 = *(int *)(param_1 + 0x58);
          goto LAB_080b06dc;
        }
        iVar3 = 0x476;
        iVar5 = 0x11a;
      }
LAB_080b1072:
      ERR_put_error(0x14,0x10b,iVar5,"d1_srvr.c",iVar3);
      uVar6 = 0x28;
      local_a0 = (uchar *)0x0;
LAB_080b0f37:
      ctx = (BN_CTX *)0x0;
      ssl3_send_alert(param_1,2,uVar6);
    }
    else {
LAB_080b06dc:
      pBVar10 = *(BIGNUM **)&r->field_0x10;
      local_64[1] = *(BIGNUM **)&r->field_0x14;
      *(undefined4 *)(iVar12 + 0x370) = 1;
LAB_080b06f4:
      local_80 = 0;
      local_64[0] = pBVar10;
      if (pBVar10 == (BIGNUM *)0x0) {
        local_90._0_1_ = '\0';
        local_9c = 0;
        sVar13 = 0;
        local_a0 = (uchar *)0x0;
        iVar12 = *(int *)(param_1 + 0x58);
      }
      else {
        sVar13 = 0;
        a = pBVar10;
        do {
          uVar2 = local_80;
          iVar3 = BN_num_bits(a);
          iVar5 = iVar3 + 7;
          if (iVar3 + 7 < 0) {
            iVar5 = iVar3 + 0xe;
          }
          aiStack_54[uVar2] = iVar5 >> 3;
          piVar1 = aiStack_54 + local_80;
          local_80 = local_80 + 1;
          sVar13 = sVar13 + 2 + *piVar1;
          a = local_64[local_80];
        } while (a != (BIGNUM *)0x0);
        iVar12 = *(int *)(param_1 + 0x58);
        local_90._0_1_ = '\0';
        local_9c = 0;
        local_a0 = (uchar *)0x0;
      }
LAB_080b0762:
      iVar5 = *(int *)(iVar12 + 0x344);
      iVar3 = 0;
      local_a4 = (EVP_PKEY *)0x0;
      if (((*(byte *)(iVar5 + 0x10) & 4) == 0) && ((*(byte *)(iVar5 + 0xd) & 1) == 0)) {
        local_a4 = (EVP_PKEY *)ssl_get_sign_pkey(param_1,iVar5,0);
        if (local_a4 == (EVP_PKEY *)0x0) {
          uVar6 = 0x32;
          goto LAB_080b0f37;
        }
        iVar3 = EVP_PKEY_size(local_a4);
      }
      iVar5 = sVar13 + 0xc;
      iVar3 = BUF_MEM_grow_clean(str,iVar3 + iVar5);
      if (iVar3 == 0) {
        iVar3 = 0x556;
        iVar5 = 7;
      }
      else {
        local_80 = 0;
        iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
        d = (uchar *)(iVar3 + 0xc);
        puVar14 = d;
        while (pBVar10 != (BIGNUM *)0x0) {
          *puVar14 = (uchar)((uint)aiStack_54[local_80] >> 8);
          puVar14[1] = (uchar)aiStack_54[local_80];
          BN_bn2bin(local_64[local_80],puVar14 + 2);
          puVar14 = puVar14 + 2 + aiStack_54[local_80];
          local_80 = local_80 + 1;
          pBVar10 = local_64[local_80];
        }
        if ((uVar15 & 0x80) != 0) {
          *puVar14 = '\x03';
          puVar14[1] = '\0';
          puVar14[3] = (uchar)local_9c;
          puVar14[2] = (uchar)local_90;
          memcpy(puVar14 + 4,local_a0,local_9c);
          CRYPTO_free(local_a0);
          puVar14 = puVar14 + 4 + local_9c;
          local_a0 = (uchar *)0x0;
        }
        if ((uVar15 & 0x100) != 0) {
          sVar9 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
          *puVar14 = (uchar)(sVar9 >> 8);
          sVar9 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
          puVar14[1] = (uchar)sVar9;
          __s = *(char **)(*(int *)(param_1 + 0xe4) + 0x14c);
          sVar9 = strlen(__s);
          strncpy((char *)(puVar14 + 2),__s,sVar9);
          sVar9 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
          puVar14 = puVar14 + 2 + sVar9;
        }
        if (local_a4 == (EVP_PKEY *)0x0) {
LAB_080b08db:
          dtls1_set_message_header(param_1,iVar3,0xc,sVar13,0,sVar13);
          *(int *)(param_1 + 0x44) = iVar5;
          *(undefined4 *)(param_1 + 0x48) = 0;
          dtls1_buffer_message(param_1,0);
          goto LAB_080b0906;
        }
        iVar5 = local_a4->type;
        if (iVar5 == 6) {
          md = local_44;
          uVar15 = 0;
          iVar5 = 2;
          do {
            if (iVar5 == 2) {
              pEVar4 = *(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c);
            }
            else {
              pEVar4 = *(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90);
            }
            EVP_DigestInit_ex(&local_7c,pEVar4,(ENGINE *)0x0);
            EVP_DigestUpdate(&local_7c,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
            EVP_DigestUpdate(&local_7c,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
            EVP_DigestUpdate(&local_7c,d,sVar13);
            EVP_DigestFinal_ex(&local_7c,md,&local_80);
            md = md + local_80;
            uVar15 = uVar15 + local_80;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          iVar5 = RSA_sign(0x72,local_44,uVar15,puVar14 + 2,&local_84,(local_a4->pkey).rsa);
          if (0 < iVar5) {
            *puVar14 = (uchar)(local_84 >> 8);
            puVar14[1] = (uchar)local_84;
            sVar13 = sVar13 + 2 + local_84;
            iVar5 = sVar13 + 0xc;
            goto LAB_080b08db;
          }
          iVar3 = 0x59e;
          iVar5 = 4;
        }
        else if (iVar5 == 0x74) {
          pEVar4 = EVP_dss1();
          EVP_DigestInit_ex(&local_7c,pEVar4,(ENGINE *)0x0);
          EVP_DigestUpdate(&local_7c,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
          EVP_DigestUpdate(&local_7c,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
          EVP_DigestUpdate(&local_7c,d,sVar13);
          iVar5 = EVP_SignFinal(&local_7c,puVar14 + 2,&local_80,local_a4);
          if (iVar5 != 0) {
LAB_080b08c0:
            *puVar14 = (uchar)(local_80 >> 8);
            puVar14[1] = (uchar)local_80;
            sVar13 = sVar13 + 2 + local_80;
            iVar5 = sVar13 + 0xc;
            goto LAB_080b08db;
          }
          iVar3 = 0x5b0;
          iVar5 = 10;
        }
        else {
          if (iVar5 != 0x198) {
            ERR_put_error(0x14,0x10b,0xfb,"d1_srvr.c",0x5ce);
            uVar6 = 0x28;
            goto LAB_080b0f37;
          }
          pEVar4 = EVP_ecdsa();
          EVP_DigestInit_ex(&local_7c,pEVar4,(ENGINE *)0x0);
          EVP_DigestUpdate(&local_7c,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
          EVP_DigestUpdate(&local_7c,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
          EVP_DigestUpdate(&local_7c,d,sVar13);
          iVar5 = EVP_SignFinal(&local_7c,puVar14 + 2,&local_80,local_a4);
          if (iVar5 != 0) goto LAB_080b08c0;
          iVar3 = 0x5c3;
          iVar5 = 0x2a;
        }
      }
      ctx = (BN_CTX *)0x0;
      ERR_put_error(0x14,0x10b,iVar5,"d1_srvr.c",iVar3);
    }
LAB_080b0e88:
    if (local_a0 != (uchar *)0x0) {
LAB_080b0e90:
      CRYPTO_free(local_a0);
    }
  }
LAB_080b0e9f:
  BN_CTX_free(ctx);
  EVP_MD_CTX_cleanup(&local_7c);
  uVar6 = 0xffffffff;
LAB_080b0927:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

