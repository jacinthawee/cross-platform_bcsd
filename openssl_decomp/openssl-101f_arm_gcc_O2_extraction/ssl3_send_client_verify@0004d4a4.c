
void ssl3_send_client_verify(int *param_1)

{
  undefined4 uVar1;
  EVP_MD *pEVar2;
  int iVar3;
  size_t cnt;
  int *piVar4;
  uint uVar5;
  EVP_PKEY_CTX *ctx;
  int iVar6;
  undefined *puVar7;
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
  local_2c[0] = __TMC_END__;
  EVP_MD_CTX_init(&EStack_a8);
  if (param_1[0xd] == 0x1190) {
    puVar7 = *(undefined **)(param_1[0xf] + 4);
    pkey = *(EVP_PKEY **)(*(int *)param_1[0x26] + 4);
    ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    EVP_PKEY_sign_init(ctx);
    pEVar2 = EVP_sha1();
    iVar3 = EVP_PKEY_CTX_ctrl(ctx,-1,0xf8,1,0,pEVar2);
    if (0 < iVar3) {
      if ((*param_1 >> 8 != 3) || (*param_1 < 0x303)) {
        (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x40,auStack_80);
        goto LAB_0004d54a;
      }
LAB_0004d600:
      pEVar2 = *(EVP_MD **)(*(int *)param_1[0x26] + 8);
      cnt = BIO_ctrl(*(BIO **)(param_1[0x16] + 0x178),3,0,&local_ac);
      if (((int)cnt < 1) || (iVar3 = tls12_get_sigandhash(puVar7 + 4,pkey,pEVar2), iVar3 == 0)) {
        iVar3 = 0xb9b;
LAB_0004d6a4:
        ERR_put_error(0x14,0x99,0x44,"s3_clnt.c",iVar3);
      }
      else {
        iVar3 = EVP_DigestInit_ex(&EStack_a8,pEVar2,(ENGINE *)0x0);
        if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&EStack_a8,local_ac,cnt), iVar3 == 0)) ||
           (iVar3 = EVP_SignFinal(&EStack_a8,puVar7 + 8,&local_b4,pkey), iVar3 == 0)) {
          ERR_put_error(0x14,0x99,6,"s3_clnt.c",0xba8);
        }
        else {
          iVar6 = local_b4 + 4;
          puVar7[7] = (char)local_b4;
          puVar7[6] = (char)(local_b4 >> 8);
          iVar3 = ssl3_digest_cached_records(param_1);
          if (iVar3 != 0) goto LAB_0004d5d2;
        }
      }
LAB_0004d678:
      EVP_MD_CTX_cleanup(&EStack_a8);
      EVP_PKEY_CTX_free(ctx);
      uVar1 = 0xffffffff;
      goto LAB_0004d4e4;
    }
    ERR_clear_error();
LAB_0004d54a:
    if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) goto LAB_0004d600;
    iVar3 = pkey->type;
    if (iVar3 != 6) {
      if (iVar3 == 0x74) {
        iVar3 = DSA_sign(pkey->save_type,auStack_80,0x14,puVar7 + 6,&local_b0,
                         (DSA *)(pkey->pkey).rsa);
        if (iVar3 != 0) {
LAB_0004d70e:
          iVar6 = local_b0 + 2;
          puVar7[5] = (char)local_b0;
          puVar7[4] = (char)(local_b0 >> 8);
          goto LAB_0004d5d2;
        }
        ERR_put_error(0x14,0x99,10,"s3_clnt.c",0xbcb);
        goto LAB_0004d678;
      }
      if (iVar3 == 0x198) {
        iVar3 = ECDSA_sign(pkey->save_type,auStack_80,0x14,puVar7 + 6,&local_b0,
                           (EC_KEY *)(pkey->pkey).rsa);
        if (iVar3 != 0) goto LAB_0004d70e;
        ERR_put_error(0x14,0x99,0x2a,"s3_clnt.c",0xbdc);
        goto LAB_0004d678;
      }
      if (iVar3 - 0x32bU < 2) {
        local_ac = (void *)0x40;
        (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x329,auStack_90);
        iVar3 = EVP_PKEY_sign(ctx,(uchar *)aiStack_6c,(size_t *)&local_ac,auStack_90,0x20);
        if (0 < iVar3) {
          piVar4 = local_2c;
          local_b0 = 0;
          uVar5 = local_b0;
          do {
            local_b0 = uVar5;
            piVar4 = (int *)((int)piVar4 + -1);
            (puVar7 + 4)[local_b0 + 2] = *(uchar *)piVar4;
            uVar5 = local_b0 + 1;
          } while (piVar4 != aiStack_6c);
          iVar6 = local_b0 + 3;
          puVar7[5] = (char)uVar5;
          puVar7[4] = (char)(uVar5 >> 8);
          local_b0 = uVar5;
          goto LAB_0004d5d2;
        }
        iVar3 = 0xbee;
      }
      else {
        iVar3 = 0xbf9;
      }
      goto LAB_0004d6a4;
    }
    (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,4,auStack_90);
    iVar3 = RSA_sign(0x72,auStack_90,0x24,puVar7 + 6,&local_b4,(pkey->pkey).rsa);
    if (iVar3 < 1) {
      ERR_put_error(0x14,0x99,4,"s3_clnt.c",0xbbb);
      goto LAB_0004d678;
    }
    iVar6 = local_b4 + 2;
    puVar7[5] = (char)local_b4;
    puVar7[4] = (char)(local_b4 >> 8);
LAB_0004d5d2:
    puVar7[3] = (char)iVar6;
    puVar7[1] = (char)((uint)iVar6 >> 0x10);
    *puVar7 = 0xf;
    puVar7[2] = (char)((uint)iVar6 >> 8);
    param_1[0x11] = iVar6 + 4;
    param_1[0xd] = 0x1191;
    param_1[0x12] = 0;
  }
  else {
    ctx = (EVP_PKEY_CTX *)0x0;
  }
  EVP_MD_CTX_cleanup(&EStack_a8);
  EVP_PKEY_CTX_free(ctx);
  uVar1 = ssl3_do_write(param_1,0x16);
LAB_0004d4e4:
  if (local_2c[0] == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

