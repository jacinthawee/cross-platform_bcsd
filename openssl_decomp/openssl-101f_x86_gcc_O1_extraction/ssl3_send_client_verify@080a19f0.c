
undefined4 ssl3_send_client_verify(int *param_1)

{
  uint uVar1;
  uchar uVar2;
  undefined *puVar3;
  EVP_PKEY *pkey;
  undefined4 uVar4;
  EVP_MD *pEVar5;
  int iVar6;
  size_t cnt;
  int iVar7;
  uchar *puVar8;
  EVP_PKEY_CTX *ctx;
  int in_GS_OFFSET;
  uint local_a8;
  uint local_a4;
  void *local_a0;
  EVP_MD_CTX local_9c;
  uchar local_84 [16];
  uchar local_74 [19];
  uchar local_61;
  uchar local_60 [64];
  int local_20;
  
  ctx = (EVP_PKEY_CTX *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_a8 = 0;
  EVP_MD_CTX_init(&local_9c);
  if (param_1[0xd] == 0x1190) {
    puVar3 = *(undefined **)(param_1[0xf] + 4);
    pkey = *(EVP_PKEY **)(*(int *)param_1[0x26] + 4);
    ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    EVP_PKEY_sign_init(ctx);
    pEVar5 = EVP_sha1();
    iVar6 = EVP_PKEY_CTX_ctrl(ctx,-1,0xf8,1,0,pEVar5);
    if (iVar6 < 1) {
      ERR_clear_error();
      iVar6 = *param_1;
LAB_080a1c06:
      if ((0x302 < iVar6) && (iVar6 >> 8 == 3)) goto LAB_080a1ae4;
      iVar6 = pkey->type;
      if (iVar6 == 6) {
        (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,4,local_84);
        iVar6 = RSA_sign(0x72,local_84,0x24,puVar3 + 6,&local_a8,(pkey->pkey).rsa);
        if (iVar6 < 1) {
          ERR_put_error(0x14,0x99,4,"s3_clnt.c",0xbbb);
          goto LAB_080a1bc3;
        }
        puVar3[5] = (char)local_a8;
        iVar6 = local_a8 + 2;
        puVar3[4] = (char)(local_a8 >> 8);
LAB_080a1ccb:
        puVar3[1] = (char)((uint)iVar6 >> 0x10);
        puVar3[3] = (char)iVar6;
        *puVar3 = 0xf;
        puVar3[2] = (char)((uint)iVar6 >> 8);
        param_1[0xd] = 0x1191;
        param_1[0x11] = iVar6 + 4;
        param_1[0x12] = 0;
        goto LAB_080a1a30;
      }
      if (iVar6 != 0x74) {
        if (iVar6 == 0x198) {
          iVar6 = ECDSA_sign(pkey->save_type,local_74,0x14,puVar3 + 6,&local_a4,
                             (EC_KEY *)(pkey->pkey).rsa);
          if (iVar6 != 0) goto LAB_080a1da4;
          ERR_put_error(0x14,0x99,0x2a,"s3_clnt.c",0xbdc);
          goto LAB_080a1bc3;
        }
        if (iVar6 - 0x32bU < 2) {
          local_a0 = (void *)0x40;
          (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x329,local_84);
          iVar6 = EVP_PKEY_sign(ctx,local_60,(size_t *)&local_a0,local_84,0x20);
          if (0 < iVar6) {
            puVar8 = local_60 + 0x3f;
            local_a4 = 0;
            uVar1 = local_a4;
            do {
              local_a4 = uVar1;
              uVar2 = *puVar8;
              puVar8 = puVar8 + -1;
              puVar3[local_a4 + 6] = uVar2;
              uVar1 = local_a4 + 1;
            } while (&local_61 != puVar8);
            iVar6 = local_a4 + 3;
            puVar3[4] = (char)(uVar1 >> 8);
            puVar3[5] = (char)uVar1;
            local_a4 = uVar1;
            goto LAB_080a1ccb;
          }
          iVar6 = 0xbee;
        }
        else {
          iVar6 = 0xbf9;
        }
        goto LAB_080a1e18;
      }
      iVar6 = DSA_sign(pkey->save_type,local_74,0x14,puVar3 + 6,&local_a4,(DSA *)(pkey->pkey).rsa);
      if (iVar6 != 0) {
LAB_080a1da4:
        puVar3[5] = (char)local_a4;
        iVar6 = local_a4 + 2;
        puVar3[4] = (char)(local_a4 >> 8);
        goto LAB_080a1ccb;
      }
      ERR_put_error(0x14,0x99,10,"s3_clnt.c",0xbcb);
    }
    else {
      if ((*param_1 >> 8 != 3) || (*param_1 < 0x303)) {
        (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x40,local_74);
        iVar6 = *param_1;
        goto LAB_080a1c06;
      }
LAB_080a1ae4:
      pEVar5 = *(EVP_MD **)(*(int *)param_1[0x26] + 8);
      cnt = BIO_ctrl(*(BIO **)(param_1[0x16] + 0x178),3,0,&local_a0);
      if (((int)cnt < 1) || (iVar6 = tls12_get_sigandhash(puVar3 + 4,pkey,pEVar5), iVar6 == 0)) {
        iVar6 = 0xb9b;
LAB_080a1e18:
        ERR_put_error(0x14,0x99,0x44,"s3_clnt.c",iVar6);
      }
      else {
        iVar6 = EVP_DigestInit_ex(&local_9c,pEVar5,(ENGINE *)0x0);
        if (((iVar6 == 0) || (iVar6 = EVP_DigestUpdate(&local_9c,local_a0,cnt), iVar6 == 0)) ||
           (iVar6 = EVP_SignFinal(&local_9c,puVar3 + 8,&local_a8,pkey), iVar6 == 0)) {
          ERR_put_error(0x14,0x99,6,"s3_clnt.c",0xba8);
        }
        else {
          puVar3[7] = (char)local_a8;
          iVar6 = local_a8 + 4;
          puVar3[6] = (char)(local_a8 >> 8);
          iVar7 = ssl3_digest_cached_records(param_1);
          if (iVar7 != 0) goto LAB_080a1ccb;
        }
      }
    }
LAB_080a1bc3:
    EVP_MD_CTX_cleanup(&local_9c);
    EVP_PKEY_CTX_free(ctx);
    uVar4 = 0xffffffff;
  }
  else {
LAB_080a1a30:
    EVP_MD_CTX_cleanup(&local_9c);
    EVP_PKEY_CTX_free(ctx);
    uVar4 = ssl3_do_write(param_1,0x16);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

