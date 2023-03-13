
int ssl3_get_cert_verify(int *param_1)

{
  uchar uVar1;
  X509 *x;
  uint *puVar2;
  int iVar3;
  EVP_PKEY *pubkey;
  uint uVar4;
  int iVar5;
  size_t cnt;
  undefined4 uVar6;
  EVP_PKEY_CTX *ctx;
  uchar *puVar7;
  uchar *puVar8;
  ushort *sigbuf;
  int in_GS_OFFSET;
  uint local_98;
  EVP_MD *local_90;
  int local_80;
  void *local_7c;
  undefined local_78 [24];
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init((EVP_MD_CTX *)local_78);
  if (*(int *)(param_1[0x30] + 0x9c) == 0) {
    iVar3 = 1;
    pubkey = (EVP_PKEY *)0x0;
    goto LAB_08097dc7;
  }
  iVar3 = (**(code **)(param_1[2] + 0x30))(param_1,0x21a0,0x21a1,0xf,0x4000,&local_80);
  if (local_80 == 0) goto LAB_08097c3e;
  x = *(X509 **)(param_1[0x30] + 0x9c);
  pubkey = X509_get_pubkey(x);
  uVar4 = X509_certificate_type(x,pubkey);
  if ((uVar4 & 0x10) == 0) {
    ERR_put_error(0x14,0x88,0xdc,"s3_srvr.c",3000);
    uVar6 = 0x2f;
LAB_08097e36:
    iVar3 = 0;
    ssl3_send_alert(param_1,2,uVar6);
    param_1[0xd] = 5;
  }
  else {
    sigbuf = (ushort *)param_1[0x10];
    if ((iVar3 != 0x40) || (1 < pubkey->type - 0x32bU)) {
      if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
        uVar4 = tls12_get_sigid(pubkey);
        if (uVar4 == 0xffffffff) {
          iVar5 = 0xbcc;
          iVar3 = 0x44;
          goto LAB_08097da4;
        }
        if (uVar4 == *(byte *)((int)sigbuf + 1)) {
          iVar3 = iVar3 + -2;
          local_90 = (EVP_MD *)tls12_get_hash(*(undefined *)sigbuf);
          sigbuf = sigbuf + 1;
          if (local_90 != (EVP_MD *)0x0) goto LAB_08097cbe;
          iVar5 = 0xbd9;
          iVar3 = 0x170;
        }
        else {
          iVar5 = 0xbd3;
          iVar3 = 0x172;
        }
      }
      else {
        local_90 = (EVP_MD *)0x0;
LAB_08097cbe:
        iVar3 = iVar3 + -2;
        local_98 = (uint)(ushort)(*sigbuf << 8 | *sigbuf >> 8);
        if ((int)local_98 <= iVar3) {
          iVar5 = EVP_PKEY_size(pubkey);
          if ((iVar5 < (int)local_98 || iVar5 < iVar3) || (sigbuf = sigbuf + 1, iVar3 < 1))
          goto LAB_08097eb0;
          goto LAB_08097d0f;
        }
        iVar5 = 0xbe6;
        iVar3 = 0x9f;
      }
LAB_08097ec2:
      ERR_put_error(0x14,0x88,iVar3,"s3_srvr.c",iVar5);
      uVar6 = 0x32;
      goto LAB_08097e36;
    }
    iVar3 = EVP_PKEY_size(pubkey);
    if (iVar3 < 0x40) {
LAB_08097eb0:
      iVar5 = 0xbed;
      iVar3 = 0x109;
      goto LAB_08097ec2;
    }
    local_90 = (EVP_MD *)0x0;
    local_98 = 0x40;
LAB_08097d0f:
    if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
      cnt = BIO_ctrl(*(BIO **)(param_1[0x16] + 0x178),3,0,&local_7c);
      if ((int)cnt < 1) {
        iVar5 = 0xbf7;
        iVar3 = 0x44;
      }
      else {
        iVar3 = EVP_DigestInit_ex((EVP_MD_CTX *)local_78,local_90,(ENGINE *)0x0);
        if (iVar3 != 0) {
          iVar3 = EVP_DigestUpdate((EVP_MD_CTX *)local_78,local_7c,cnt);
          if (iVar3 != 0) {
            iVar3 = 1;
            iVar5 = EVP_VerifyFinal((EVP_MD_CTX *)local_78,(uchar *)sigbuf,local_98,pubkey);
            if (0 < iVar5) goto LAB_08097dc7;
            iVar5 = 0xc08;
            iVar3 = 0x7b;
            goto LAB_08097f5c;
          }
        }
        iVar5 = 0xc01;
        iVar3 = 6;
      }
LAB_08097da4:
      ERR_put_error(0x14,0x88,iVar3,"s3_srvr.c",iVar5);
      uVar6 = 0x50;
      goto LAB_08097e36;
    }
    iVar3 = pubkey->type;
    if (iVar3 == 6) {
      iVar5 = RSA_verify(0x72,(uchar *)(param_1[0x16] + 0x1b4),0x24,(uchar *)sigbuf,local_98,
                         (pubkey->pkey).rsa);
      if (iVar5 < 0) {
        iVar5 = 0xc13;
        iVar3 = 0x76;
      }
      else {
        iVar3 = 1;
        if (iVar5 != 0) goto LAB_08097dc7;
        iVar5 = 0xc18;
        iVar3 = 0x7a;
      }
LAB_08097f5c:
      ERR_put_error(0x14,0x88,iVar3,"s3_srvr.c",iVar5);
      uVar6 = 0x33;
      goto LAB_08097e36;
    }
    if (iVar3 == 0x74) {
      iVar3 = 1;
      iVar5 = DSA_verify(pubkey->save_type,(uchar *)(param_1[0x16] + 0x1c4),0x14,(uchar *)sigbuf,
                         local_98,(DSA *)(pubkey->pkey).rsa);
      if (iVar5 < 1) {
        iVar5 = 0xc25;
        iVar3 = 0x70;
        goto LAB_08097f5c;
      }
    }
    else {
      if (iVar3 != 0x198) {
        if (1 < iVar3 - 0x32bU) {
          ERR_put_error(0x14,0x88,0x44,"s3_srvr.c",0xc56);
          uVar6 = 0x2b;
          goto LAB_08097e36;
        }
        ctx = EVP_PKEY_CTX_new(pubkey,(ENGINE *)0x0);
        if (ctx == (EVP_PKEY_CTX *)0x0) {
          iVar5 = 0xc3e;
          iVar3 = 0x41;
        }
        else {
          iVar3 = EVP_PKEY_verify_init(ctx);
          if (0 < iVar3) {
            if (local_98 != 0x40) {
              __fprintf_chk(stderr,1,"GOST signature length is %d",local_98);
            }
            puVar7 = local_60 + 0x3f;
            do {
              uVar1 = *(uchar *)sigbuf;
              puVar8 = puVar7 + -1;
              sigbuf = (ushort *)((int)sigbuf + 1);
              *puVar7 = uVar1;
              puVar7 = puVar8;
            } while (puVar8 != local_78 + 0x17);
            iVar5 = EVP_PKEY_verify(ctx,local_60,0x40,(uchar *)(param_1[0x16] + 0x1b4),0x20);
            iVar3 = 1;
            EVP_PKEY_CTX_free(ctx);
            if (iVar5 < 1) {
              iVar5 = 0xc52;
              goto LAB_08098098;
            }
            goto LAB_08097dc7;
          }
          EVP_PKEY_CTX_free(ctx);
          iVar5 = 0xc44;
          iVar3 = 0x44;
        }
        goto LAB_08097da4;
      }
      iVar3 = 1;
      iVar5 = ECDSA_verify(pubkey->save_type,(uchar *)(param_1[0x16] + 0x1c4),0x14,(uchar *)sigbuf,
                           local_98,(EC_KEY *)(pubkey->pkey).rsa);
      if (iVar5 < 1) {
        iVar5 = 0xc32;
LAB_08098098:
        iVar3 = 0x131;
        goto LAB_08097f5c;
      }
    }
  }
LAB_08097dc7:
  if (*(BIO **)(param_1[0x16] + 0x178) != (BIO *)0x0) {
    BIO_free(*(BIO **)(param_1[0x16] + 0x178));
    puVar2 = (uint *)param_1[0x16];
    *puVar2 = *puVar2 & 0xffffffdf;
    puVar2[0x5e] = 0;
  }
  EVP_MD_CTX_cleanup((EVP_MD_CTX *)local_78);
  EVP_PKEY_free(pubkey);
LAB_08097c3e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

