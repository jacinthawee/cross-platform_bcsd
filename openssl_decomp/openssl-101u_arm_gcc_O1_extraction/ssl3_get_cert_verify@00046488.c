
void ssl3_get_cert_verify(int *param_1)

{
  uint uVar1;
  EVP_PKEY *pubkey;
  uint siglen;
  int iVar2;
  uint uVar3;
  size_t cnt;
  EVP_PKEY_CTX *ctx;
  uchar *sig;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  X509 *x;
  uchar *puVar7;
  EVP_MD *type;
  int local_88;
  void *local_84;
  EVP_MD_CTX EStack_80;
  uchar auStack_68 [64];
  uchar auStack_28 [4];
  int local_24;
  
  local_24 = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_80);
  pubkey = *(EVP_PKEY **)(param_1[0x30] + 0x9c);
  if (pubkey == (EVP_PKEY *)0x0) {
    siglen = 1;
  }
  else {
    siglen = (**(code **)(param_1[2] + 0x30))(param_1,0x21a0,0x21a1,0xf,0x4000,&local_88);
    if (local_88 == 0) goto LAB_000464d0;
    x = *(X509 **)(param_1[0x30] + 0x9c);
    pubkey = X509_get_pubkey(x);
    iVar2 = X509_certificate_type(x,pubkey);
    if (-1 < iVar2 << 0x1b) {
      ERR_put_error(0x14,0x88,0xdc,"s3_srvr.c",3000);
      uVar4 = 0x2f;
      goto LAB_000465cc;
    }
    puVar7 = (uchar *)param_1[0x10];
    if ((siglen == 0x40) && (pubkey->type - 0x32bU < 2)) {
      iVar2 = EVP_PKEY_size(pubkey);
      if (iVar2 < 0x40) {
LAB_000465dc:
        ERR_put_error(0x14,0x88,0x109,"s3_srvr.c",0xbed);
        uVar4 = 0x32;
      }
      else {
        type = (EVP_MD *)0x0;
LAB_0004653c:
        if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
          cnt = BIO_ctrl(*(BIO **)(param_1[0x16] + 0x178),3,0,&local_84);
          if ((int)cnt < 1) {
            iVar2 = 0xbf7;
            goto LAB_0004681e;
          }
          iVar2 = EVP_DigestInit_ex(&EStack_80,type,(ENGINE *)0x0);
          if ((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&EStack_80,local_84,cnt), iVar2 == 0)) {
            ERR_put_error(0x14,0x88,6,"s3_srvr.c",0xc01);
            uVar4 = 0x50;
          }
          else {
            iVar2 = EVP_VerifyFinal(&EStack_80,puVar7,siglen,pubkey);
            if (0 < iVar2) goto LAB_000466d4;
            ERR_put_error(0x14,0x88,0x7b,"s3_srvr.c",0xc08);
            uVar4 = 0x33;
          }
        }
        else {
          iVar2 = pubkey->type;
          if (iVar2 == 6) {
            iVar2 = RSA_verify(0x72,(uchar *)(param_1[0x16] + 0x1b4),0x24,puVar7,siglen,
                               (pubkey->pkey).rsa);
            if (iVar2 < 0) {
              ERR_put_error(0x14,0x88,0x76,"s3_srvr.c",0xc13);
              uVar4 = 0x33;
            }
            else {
              if (iVar2 != 0) goto LAB_000466d4;
              ERR_put_error(0x14,0x88,0x7a,"s3_srvr.c",0xc18);
              uVar4 = 0x33;
            }
          }
          else if (iVar2 == 0x74) {
            iVar2 = DSA_verify(pubkey->save_type,(uchar *)(param_1[0x16] + 0x1c4),0x14,puVar7,siglen
                               ,(DSA *)(pubkey->pkey).rsa);
            if (0 < iVar2) {
LAB_000466d4:
              siglen = 1;
              goto LAB_00046586;
            }
            ERR_put_error(0x14,0x88,0x70,"s3_srvr.c",0xc25);
            uVar4 = 0x33;
          }
          else if (iVar2 == 0x198) {
            iVar2 = ECDSA_verify(pubkey->save_type,(uchar *)(param_1[0x16] + 0x1c4),0x14,puVar7,
                                 siglen,(EC_KEY *)(pubkey->pkey).rsa);
            if (0 < iVar2) goto LAB_000466d4;
            iVar2 = 0xc32;
LAB_00046768:
            ERR_put_error(0x14,0x88,0x131,"s3_srvr.c",iVar2);
            uVar4 = 0x33;
          }
          else if (iVar2 - 0x32bU < 2) {
            ctx = EVP_PKEY_CTX_new(pubkey,(ENGINE *)0x0);
            if (ctx == (EVP_PKEY_CTX *)0x0) {
              ERR_put_error(0x14,0x88,0x41,"s3_srvr.c",0xc3e);
              uVar4 = 0x50;
            }
            else {
              iVar2 = EVP_PKEY_verify_init(ctx);
              if (0 < iVar2) {
                if (siglen != 0x40) {
                  __fprintf_chk(stderr,1,"GOST signature length is %d",siglen);
                }
                puVar7 = puVar7 + -1;
                sig = auStack_28;
                do {
                  puVar7 = puVar7 + 1;
                  sig = sig + -1;
                  *sig = *puVar7;
                } while (sig != auStack_68);
                iVar2 = EVP_PKEY_verify(ctx,sig,0x40,(uchar *)(param_1[0x16] + 0x1b4),0x20);
                EVP_PKEY_CTX_free(ctx);
                if (iVar2 < 1) {
                  iVar2 = 0xc52;
                  goto LAB_00046768;
                }
                goto LAB_000466d4;
              }
              EVP_PKEY_CTX_free(ctx);
              ERR_put_error(0x14,0x88,0x44,"s3_srvr.c",0xc44);
              uVar4 = 0x50;
            }
          }
          else {
            ERR_put_error(0x14,0x88,0x44,"s3_srvr.c",0xc56);
            uVar4 = 0x2b;
          }
        }
      }
    }
    else if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
      uVar6 = tls12_get_sigid(pubkey);
      if (uVar6 == 0xffffffff) {
        iVar2 = 0xbcc;
LAB_0004681e:
        ERR_put_error(0x14,0x88,0x44,"s3_srvr.c",iVar2);
        uVar4 = 0x50;
      }
      else if (puVar7[1] == uVar6) {
        siglen = siglen - 2;
        type = (EVP_MD *)tls12_get_hash(*puVar7);
        puVar7 = puVar7 + 2;
        if (type != (EVP_MD *)0x0) goto LAB_00046512;
        ERR_put_error(0x14,0x88,0x170,"s3_srvr.c",0xbd9);
        uVar4 = 0x32;
      }
      else {
        ERR_put_error(0x14,0x88,0x172,"s3_srvr.c",0xbd3);
        uVar4 = 0x32;
      }
    }
    else {
      type = (EVP_MD *)0x0;
LAB_00046512:
      uVar6 = siglen - 2;
      siglen = (uint)CONCAT11(*puVar7,puVar7[1]);
      if ((int)siglen <= (int)uVar6) {
        uVar3 = EVP_PKEY_size(pubkey);
        iVar2 = uVar6 - uVar3;
        uVar1 = uVar6;
        if ((int)uVar6 <= (int)uVar3) {
          iVar2 = siglen - uVar3;
          uVar1 = siglen;
        }
        if ((uVar1 != uVar3 && iVar2 < 0 == SBORROW4(uVar1,uVar3)) || ((int)uVar6 < 1))
        goto LAB_000465dc;
        puVar7 = puVar7 + 2;
        goto LAB_0004653c;
      }
      ERR_put_error(0x14,0x88,0x9f,"s3_srvr.c",0xbe6);
      uVar4 = 0x32;
    }
LAB_000465cc:
    ssl3_send_alert(param_1,2,uVar4);
    siglen = 0;
    param_1[0xd] = 5;
  }
LAB_00046586:
  if (*(BIO **)(param_1[0x16] + 0x178) != (BIO *)0x0) {
    BIO_free(*(BIO **)(param_1[0x16] + 0x178));
    puVar5 = (uint *)param_1[0x16];
    puVar5[0x5e] = 0;
    *puVar5 = *puVar5 & 0xffffffdf;
  }
  EVP_MD_CTX_cleanup(&EStack_80);
  EVP_PKEY_free(pubkey);
LAB_000464d0:
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(siglen);
  }
  return;
}

