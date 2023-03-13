
undefined4 ssl3_send_client_verify(int *param_1)

{
  uint uVar1;
  uchar uVar2;
  undefined *puVar3;
  EVP_PKEY *pkey;
  undefined4 uVar4;
  int iVar5;
  EVP_MD *pEVar6;
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
    if ((ctx == (EVP_PKEY_CTX *)0x0) || (iVar5 = EVP_PKEY_sign_init(ctx), iVar5 < 1)) {
      iVar5 = 0xc25;
      goto LAB_0809e1b8;
    }
    pEVar6 = EVP_sha1();
    iVar5 = EVP_PKEY_CTX_ctrl(ctx,-1,0xf8,1,0,pEVar6);
    if (iVar5 < 1) {
      ERR_clear_error();
      iVar5 = *param_1;
LAB_0809e0a6:
      if ((0x302 < iVar5) && (iVar5 >> 8 == 3)) goto LAB_0809df7c;
      iVar5 = pkey->type;
      if (iVar5 == 6) {
        (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,4,local_84);
        iVar5 = RSA_sign(0x72,local_84,0x24,puVar3 + 6,&local_a8,(pkey->pkey).rsa);
        if (iVar5 < 1) {
          ERR_put_error(0x14,0x99,4,"s3_clnt.c",0xc54);
          goto LAB_0809e05b;
        }
        puVar3[5] = (char)local_a8;
        iVar5 = local_a8 + 2;
        puVar3[4] = (char)(local_a8 >> 8);
LAB_0809e16b:
        puVar3[1] = (char)((uint)iVar5 >> 0x10);
        puVar3[3] = (char)iVar5;
        *puVar3 = 0xf;
        puVar3[2] = (char)((uint)iVar5 >> 8);
        param_1[0xd] = 0x1191;
        param_1[0x11] = iVar5 + 4;
        param_1[0x12] = 0;
        goto LAB_0809deb0;
      }
      if (iVar5 != 0x74) {
        if (iVar5 == 0x198) {
          iVar5 = ECDSA_sign(pkey->save_type,local_74,0x14,puVar3 + 6,&local_a4,
                             (EC_KEY *)(pkey->pkey).rsa);
          if (iVar5 != 0) goto LAB_0809e267;
          ERR_put_error(0x14,0x99,0x2a,"s3_clnt.c",0xc6e);
          goto LAB_0809e05b;
        }
        if (iVar5 - 0x32bU < 2) {
          local_a0 = (void *)0x40;
          (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x329,local_84);
          iVar5 = EVP_PKEY_sign(ctx,local_60,(size_t *)&local_a0,local_84,0x20);
          if (0 < iVar5) {
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
            iVar5 = local_a4 + 3;
            puVar3[4] = (char)(uVar1 >> 8);
            puVar3[5] = (char)uVar1;
            local_a4 = uVar1;
            goto LAB_0809e16b;
          }
          iVar5 = 0xc7d;
        }
        else {
          iVar5 = 0xc86;
        }
        goto LAB_0809e1b8;
      }
      iVar5 = DSA_sign(pkey->save_type,local_74,0x14,puVar3 + 6,&local_a4,(DSA *)(pkey->pkey).rsa);
      if (iVar5 != 0) {
LAB_0809e267:
        puVar3[5] = (char)local_a4;
        iVar5 = local_a4 + 2;
        puVar3[4] = (char)(local_a4 >> 8);
        goto LAB_0809e16b;
      }
      ERR_put_error(0x14,0x99,10,"s3_clnt.c",0xc61);
    }
    else {
      if ((*param_1 >> 8 != 3) || (*param_1 < 0x303)) {
        (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x40,local_74);
        iVar5 = *param_1;
        goto LAB_0809e0a6;
      }
LAB_0809df7c:
      pEVar6 = *(EVP_MD **)(*(int *)param_1[0x26] + 8);
      cnt = BIO_ctrl(*(BIO **)(param_1[0x16] + 0x178),3,0,&local_a0);
      if (((int)cnt < 1) || (iVar5 = tls12_get_sigandhash(puVar3 + 4,pkey,pEVar6), iVar5 == 0)) {
        iVar5 = 0xc3b;
LAB_0809e1b8:
        ERR_put_error(0x14,0x99,0x44,"s3_clnt.c",iVar5);
      }
      else {
        iVar5 = EVP_DigestInit_ex(&local_9c,pEVar6,(ENGINE *)0x0);
        if (((iVar5 == 0) || (iVar5 = EVP_DigestUpdate(&local_9c,local_a0,cnt), iVar5 == 0)) ||
           (iVar5 = EVP_SignFinal(&local_9c,puVar3 + 8,&local_a8,pkey), iVar5 == 0)) {
          ERR_put_error(0x14,0x99,6,"s3_clnt.c",0xc46);
        }
        else {
          puVar3[7] = (char)local_a8;
          iVar5 = local_a8 + 4;
          puVar3[6] = (char)(local_a8 >> 8);
          iVar7 = ssl3_digest_cached_records(param_1);
          if (iVar7 != 0) goto LAB_0809e16b;
        }
      }
    }
LAB_0809e05b:
    EVP_MD_CTX_cleanup(&local_9c);
    EVP_PKEY_CTX_free(ctx);
    param_1[0xd] = 5;
    uVar4 = 0xffffffff;
  }
  else {
LAB_0809deb0:
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

