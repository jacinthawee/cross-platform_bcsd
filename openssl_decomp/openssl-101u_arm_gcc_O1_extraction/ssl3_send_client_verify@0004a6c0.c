
void ssl3_send_client_verify(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  EVP_MD *pEVar3;
  size_t cnt;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined *puVar7;
  EVP_PKEY_CTX *ctx;
  EVP_PKEY *pkey;
  uint local_b4;
  uint local_b0;
  void *local_ac;
  EVP_MD_CTX EStack_a8;
  uchar auStack_90 [16];
  uchar auStack_80 [20];
  int aiStack_6c [16];
  int local_2c [2];
  
  local_b4 = 0;
  local_2c[0] = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_a8);
  if (param_1[0xd] == 0x1190) {
    puVar7 = *(undefined **)(param_1[0xf] + 4);
    pkey = *(EVP_PKEY **)(*(int *)param_1[0x26] + 4);
    ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if ((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = EVP_PKEY_sign_init(ctx), iVar2 < 1)) {
      iVar2 = 0xc25;
      goto LAB_0004a8c8;
    }
    pEVar3 = EVP_sha1();
    iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0xf8,1,0,pEVar3);
    if (iVar2 < 1) {
      ERR_clear_error();
LAB_0004a778:
      if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) goto LAB_0004a826;
      iVar2 = pkey->type;
      if (iVar2 == 6) {
        (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,4,auStack_90);
        iVar2 = RSA_sign(0x72,auStack_90,0x24,puVar7 + 6,&local_b4,(pkey->pkey).rsa);
        if (iVar2 < 1) {
          ERR_put_error(0x14,0x99,4,"s3_clnt.c",0xc54);
          goto LAB_0004a89c;
        }
        iVar2 = local_b4 + 2;
        puVar7[5] = (char)local_b4;
        puVar7[4] = (char)(local_b4 >> 8);
LAB_0004a7fa:
        puVar7[3] = (char)iVar2;
        puVar7[1] = (char)((uint)iVar2 >> 0x10);
        *puVar7 = 0xf;
        puVar7[2] = (char)((uint)iVar2 >> 8);
        param_1[0x11] = iVar2 + 4;
        param_1[0xd] = 0x1191;
        param_1[0x12] = 0;
        goto LAB_0004a6ee;
      }
      if (iVar2 != 0x74) {
        if (iVar2 == 0x198) {
          iVar2 = ECDSA_sign(pkey->save_type,auStack_80,0x14,puVar7 + 6,&local_b0,
                             (EC_KEY *)(pkey->pkey).rsa);
          if (iVar2 != 0) goto LAB_0004a93a;
          ERR_put_error(0x14,0x99,0x2a,"s3_clnt.c",0xc6e);
          goto LAB_0004a89c;
        }
        if (iVar2 - 0x32bU < 2) {
          local_ac = (void *)0x40;
          (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x329,auStack_90);
          iVar2 = EVP_PKEY_sign(ctx,(uchar *)aiStack_6c,(size_t *)&local_ac,auStack_90,0x20);
          piVar5 = local_2c;
          if (0 < iVar2) {
            local_b0 = 0;
            uVar6 = local_b0;
            do {
              local_b0 = uVar6;
              piVar5 = (int *)((int)piVar5 + -1);
              (puVar7 + 4)[local_b0 + 2] = *(uchar *)piVar5;
              uVar6 = local_b0 + 1;
            } while (piVar5 != aiStack_6c);
            iVar2 = local_b0 + 3;
            puVar7[5] = (char)uVar6;
            puVar7[4] = (char)(uVar6 >> 8);
            local_b0 = uVar6;
            goto LAB_0004a7fa;
          }
          iVar2 = 0xc7d;
        }
        else {
          iVar2 = 0xc86;
        }
        goto LAB_0004a8c8;
      }
      iVar2 = DSA_sign(pkey->save_type,auStack_80,0x14,puVar7 + 6,&local_b0,(DSA *)(pkey->pkey).rsa)
      ;
      if (iVar2 != 0) {
LAB_0004a93a:
        iVar2 = local_b0 + 2;
        puVar7[5] = (char)local_b0;
        puVar7[4] = (char)(local_b0 >> 8);
        goto LAB_0004a7fa;
      }
      ERR_put_error(0x14,0x99,10,"s3_clnt.c",0xc61);
    }
    else {
      if ((*param_1 >> 8 != 3) || (*param_1 < 0x303)) {
        (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x40,auStack_80);
        goto LAB_0004a778;
      }
LAB_0004a826:
      pEVar3 = *(EVP_MD **)(*(int *)param_1[0x26] + 8);
      cnt = BIO_ctrl(*(BIO **)(param_1[0x16] + 0x178),3,0,&local_ac);
      if (((int)cnt < 1) || (iVar2 = tls12_get_sigandhash(puVar7 + 4,pkey,pEVar3), iVar2 == 0)) {
        iVar2 = 0xc3b;
LAB_0004a8c8:
        ERR_put_error(0x14,0x99,0x44,"s3_clnt.c",iVar2);
      }
      else {
        iVar2 = EVP_DigestInit_ex(&EStack_a8,pEVar3,(ENGINE *)0x0);
        if (((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&EStack_a8,local_ac,cnt), iVar2 == 0)) ||
           (iVar2 = EVP_SignFinal(&EStack_a8,puVar7 + 8,&local_b4,pkey), iVar2 == 0)) {
          ERR_put_error(0x14,0x99,6,"s3_clnt.c",0xc46);
        }
        else {
          iVar2 = local_b4 + 4;
          puVar7[7] = (char)local_b4;
          puVar7[6] = (char)(local_b4 >> 8);
          iVar4 = ssl3_digest_cached_records(param_1);
          if (iVar4 != 0) goto LAB_0004a7fa;
        }
      }
    }
LAB_0004a89c:
    EVP_MD_CTX_cleanup(&EStack_a8);
    EVP_PKEY_CTX_free(ctx);
    uVar1 = 0xffffffff;
    param_1[0xd] = 5;
  }
  else {
    ctx = (EVP_PKEY_CTX *)0x0;
LAB_0004a6ee:
    EVP_MD_CTX_cleanup(&EStack_a8);
    EVP_PKEY_CTX_free(ctx);
    uVar1 = ssl3_do_write(param_1,0x16);
  }
  if (local_2c[0] == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

