
int ssl3_get_cert_verify(int *param_1)

{
  uchar uVar1;
  X509 *x;
  uint *puVar2;
  int iVar3;
  EVP_PKEY *pubkey;
  uint uVar4;
  undefined4 uVar5;
  EVP_PKEY_CTX *ctx;
  uchar *puVar6;
  uchar *puVar7;
  size_t cnt;
  ushort *sigbuf;
  int in_GS_OFFSET;
  int iVar8;
  uint local_98;
  EVP_MD *local_90;
  int local_80;
  void *local_7c;
  undefined local_78 [24];
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init((EVP_MD_CTX *)local_78);
  iVar3 = (**(code **)(param_1[2] + 0x30))(param_1,0x21a0,0x21a1,0xffffffff,0x204,&local_80);
  if (local_80 == 0) goto LAB_0809bb50;
  x = *(X509 **)(param_1[0x30] + 0x9c);
  if (x == (X509 *)0x0) {
    iVar8 = param_1[0x16];
    if (*(int *)(iVar8 + 0x340) == 0xf) {
      pubkey = (EVP_PKEY *)0x0;
      ERR_put_error(0x14,0x88,0xba,"s3_srvr.c",0xb88);
      uVar5 = 10;
      goto LAB_0809bba8;
    }
    *(undefined4 *)(iVar8 + 0x354) = 1;
    pubkey = (EVP_PKEY *)0x0;
LAB_0809bb0f:
    iVar3 = 1;
  }
  else {
    pubkey = X509_get_pubkey(x);
    uVar4 = X509_certificate_type(x,pubkey);
    iVar8 = param_1[0x16];
    if (*(int *)(iVar8 + 0x340) == 0xf) {
      if ((uVar4 & 0x10) == 0) {
        ERR_put_error(0x14,0x88,0xdc,"s3_srvr.c",0xb8f);
        uVar5 = 0x2f;
      }
      else {
        if (*(int *)(iVar8 + 0x180) != 0) {
          iVar8 = 0xb96;
          iVar3 = 0x85;
          goto LAB_0809bd42;
        }
        sigbuf = (ushort *)param_1[0x10];
        if ((iVar3 == 0x40) && (pubkey->type - 0x32bU < 2)) {
          iVar3 = EVP_PKEY_size(pubkey);
          if (0x3f < iVar3) {
            local_90 = (EVP_MD *)0x0;
            local_98 = 0x40;
LAB_0809bcb9:
            if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
              cnt = BIO_ctrl(*(BIO **)(param_1[0x16] + 0x178),3,0,&local_7c);
              if ((int)cnt < 1) {
                iVar8 = 0xbdd;
                iVar3 = 0x44;
              }
              else {
                iVar3 = EVP_DigestInit_ex((EVP_MD_CTX *)local_78,local_90,(ENGINE *)0x0);
                if (iVar3 != 0) {
                  iVar3 = EVP_DigestUpdate((EVP_MD_CTX *)local_78,local_7c,cnt);
                  if (iVar3 != 0) {
                    iVar3 = EVP_VerifyFinal((EVP_MD_CTX *)local_78,(uchar *)sigbuf,local_98,pubkey);
                    if (0 < iVar3) goto LAB_0809bee3;
                    iVar8 = 0xbf0;
                    iVar3 = 0x7b;
                    goto LAB_0809bf29;
                  }
                }
                iVar8 = 0xbe8;
                iVar3 = 6;
              }
LAB_0809c034:
              ERR_put_error(0x14,0x88,iVar3,"s3_srvr.c",iVar8);
              uVar5 = 0x50;
              goto LAB_0809bba8;
            }
            iVar3 = pubkey->type;
            if (iVar3 != 6) {
              if (iVar3 == 0x74) {
                iVar3 = DSA_verify(pubkey->save_type,(uchar *)(param_1[0x16] + 0x1c4),0x14,
                                   (uchar *)sigbuf,local_98,(DSA *)(pubkey->pkey).rsa);
                if (iVar3 < 1) {
                  iVar8 = 0xc14;
                  iVar3 = 0x70;
                  goto LAB_0809bf29;
                }
              }
              else if (iVar3 == 0x198) {
                iVar3 = ECDSA_verify(pubkey->save_type,(uchar *)(param_1[0x16] + 0x1c4),0x14,
                                     (uchar *)sigbuf,local_98,(EC_KEY *)(pubkey->pkey).rsa);
                if (iVar3 < 1) {
                  iVar8 = 0xc25;
LAB_0809bfad:
                  iVar3 = 0x131;
                  goto LAB_0809bf29;
                }
              }
              else {
                if (1 < iVar3 - 0x32bU) {
                  ERR_put_error(0x14,0x88,0x44,"s3_srvr.c",0xc42);
                  uVar5 = 0x2b;
                  goto LAB_0809bba8;
                }
                ctx = EVP_PKEY_CTX_new(pubkey,(ENGINE *)0x0);
                EVP_PKEY_verify_init(ctx);
                if (local_98 != 0x40) {
                  __fprintf_chk(stderr,1,"GOST signature length is %d",local_98);
                }
                puVar6 = local_60 + 0x3f;
                do {
                  uVar1 = *(uchar *)sigbuf;
                  puVar7 = puVar6 + -1;
                  sigbuf = (ushort *)((int)sigbuf + 1);
                  *puVar6 = uVar1;
                  puVar6 = puVar7;
                } while (puVar7 != local_78 + 0x17);
                iVar3 = EVP_PKEY_verify(ctx,local_60,0x40,(uchar *)(param_1[0x16] + 0x1b4),0x20);
                EVP_PKEY_CTX_free(ctx);
                if (iVar3 < 1) {
                  iVar8 = 0xc3c;
                  goto LAB_0809bfad;
                }
              }
LAB_0809bee3:
              iVar8 = param_1[0x16];
              iVar3 = 1;
              goto LAB_0809bb14;
            }
            iVar3 = RSA_verify(0x72,(uchar *)(param_1[0x16] + 0x1b4),0x24,(uchar *)sigbuf,local_98,
                               (pubkey->pkey).rsa);
            if (iVar3 < 0) {
              iVar8 = 0xbfe;
              iVar3 = 0x76;
            }
            else {
              if (iVar3 != 0) goto LAB_0809bee3;
              iVar8 = 0xc04;
              iVar3 = 0x7a;
            }
LAB_0809bf29:
            ERR_put_error(0x14,0x88,iVar3,"s3_srvr.c",iVar8);
            uVar5 = 0x33;
            goto LAB_0809bba8;
          }
LAB_0809bde0:
          iVar8 = 0xbd1;
          iVar3 = 0x109;
        }
        else if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
          uVar4 = tls12_get_sigid(pubkey);
          if (uVar4 == 0xffffffff) {
            iVar8 = 0xbad;
            iVar3 = 0x44;
            goto LAB_0809c034;
          }
          if (uVar4 == *(byte *)((int)sigbuf + 1)) {
            iVar3 = iVar3 + -2;
            local_90 = (EVP_MD *)tls12_get_hash(*(undefined *)sigbuf);
            sigbuf = sigbuf + 1;
            if (local_90 != (EVP_MD *)0x0) goto LAB_0809bc68;
            iVar8 = 0xbbb;
            iVar3 = 0x170;
          }
          else {
            iVar8 = 0xbb4;
            iVar3 = 0x172;
          }
        }
        else {
          local_90 = (EVP_MD *)0x0;
LAB_0809bc68:
          iVar3 = iVar3 + -2;
          local_98 = (uint)(ushort)(*sigbuf << 8 | *sigbuf >> 8);
          if ((int)local_98 <= iVar3) {
            iVar8 = EVP_PKEY_size(pubkey);
            if ((iVar8 < (int)local_98 || iVar8 < iVar3) || (sigbuf = sigbuf + 1, iVar3 < 1))
            goto LAB_0809bde0;
            goto LAB_0809bcb9;
          }
          iVar8 = 0xbc9;
          iVar3 = 0x9f;
        }
        ERR_put_error(0x14,0x88,iVar3,"s3_srvr.c",iVar8);
        uVar5 = 0x32;
      }
    }
    else {
      *(undefined4 *)(iVar8 + 0x354) = 1;
      if ((uVar4 & 0x10) == 0) goto LAB_0809bb0f;
      iVar8 = 0xb7f;
      iVar3 = 0xae;
LAB_0809bd42:
      ERR_put_error(0x14,0x88,iVar3,"s3_srvr.c",iVar8);
      uVar5 = 10;
    }
LAB_0809bba8:
    iVar3 = 0;
    ssl3_send_alert(param_1,2,uVar5);
    iVar8 = param_1[0x16];
  }
LAB_0809bb14:
  if (*(BIO **)(iVar8 + 0x178) != (BIO *)0x0) {
    BIO_free(*(BIO **)(iVar8 + 0x178));
    puVar2 = (uint *)param_1[0x16];
    *puVar2 = *puVar2 & 0xffffffdf;
    puVar2[0x5e] = 0;
  }
  EVP_MD_CTX_cleanup((EVP_MD_CTX *)local_78);
  EVP_PKEY_free(pubkey);
LAB_0809bb50:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

