
void ssl3_get_cert_verify(int *param_1)

{
  uint uVar1;
  uint siglen;
  X509 *pubkey;
  int iVar2;
  uint uVar3;
  size_t cnt;
  EVP_PKEY_CTX *ctx;
  uchar *sig;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  EVP_MD *type;
  X509_CINF *pXVar7;
  X509 *pXVar8;
  uchar *puVar9;
  uint uVar10;
  int local_88;
  void *local_84;
  EVP_MD_CTX EStack_80;
  uchar auStack_68 [64];
  uchar auStack_28 [4];
  int local_24;
  
  local_24 = __TMC_END__;
  EVP_MD_CTX_init(&EStack_80);
  siglen = (**(code **)(param_1[2] + 0x30))(param_1,0x21a0,0x21a1,0xffffffff,0x204,&local_88);
  if (local_88 == 0) goto LAB_000498be;
  pXVar8 = *(X509 **)(param_1[0x30] + 0x9c);
  if (pXVar8 == (X509 *)0x0) {
    iVar4 = param_1[0x16];
    if (*(int *)(iVar4 + 0x340) == 0xf) {
      ERR_put_error(0x14,0x88,0xba,"s3_srvr.c",0xb88);
      uVar6 = 10;
      goto LAB_0004997e;
    }
    siglen = 1;
    *(undefined4 *)(iVar4 + 0x354) = 1;
  }
  else {
    pubkey = (X509 *)X509_get_pubkey(pXVar8);
    iVar2 = X509_certificate_type(pXVar8,(EVP_PKEY *)pubkey);
    iVar4 = param_1[0x16];
    pXVar8 = pubkey;
    if (*(int *)(iVar4 + 0x340) == 0xf) {
      if (iVar2 << 0x1b < 0) {
        type = *(EVP_MD **)(iVar4 + 0x180);
        if (type == (EVP_MD *)0x0) {
          puVar9 = (uchar *)param_1[0x10];
          if ((siglen == 0x40) &&
             ((undefined *)((int)&pubkey->cert_info[-0x10].subject + 1U) < (undefined *)0x2)) {
            iVar4 = EVP_PKEY_size((EVP_PKEY *)pubkey);
            if (iVar4 < 0x40) {
LAB_000499be:
              ERR_put_error(0x14,0x88,0x109,"s3_srvr.c",0xbd1);
              uVar6 = 0x32;
            }
            else {
LAB_0004991e:
              if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
                cnt = BIO_ctrl(*(BIO **)(param_1[0x16] + 0x178),3,0,&local_84);
                if ((int)cnt < 1) {
                  iVar4 = 0xbdd;
                  goto LAB_00049c3c;
                }
                iVar4 = EVP_DigestInit_ex(&EStack_80,type,(ENGINE *)0x0);
                if ((iVar4 == 0) || (iVar4 = EVP_DigestUpdate(&EStack_80,local_84,cnt), iVar4 == 0))
                {
                  ERR_put_error(0x14,0x88,6,"s3_srvr.c",0xbe8);
                  uVar6 = 0x50;
                }
                else {
                  iVar4 = EVP_VerifyFinal(&EStack_80,puVar9,siglen,(EVP_PKEY *)pubkey);
                  if (0 < iVar4) goto LAB_00049b50;
                  ERR_put_error(0x14,0x88,0x7b,"s3_srvr.c",0xbf0);
                  uVar6 = 0x33;
                }
              }
              else {
                pXVar7 = pubkey->cert_info;
                if (pXVar7 == (X509_CINF *)0x6) {
                  iVar4 = RSA_verify(0x72,(uchar *)(param_1[0x16] + 0x1b4),0x24,puVar9,siglen,
                                     ((_union_271 *)&pubkey->name)->rsa);
                  if (iVar4 < 0) {
                    ERR_put_error(0x14,0x88,0x76,"s3_srvr.c",0xbfe);
                    uVar6 = 0x33;
                  }
                  else {
                    if (iVar4 != 0) goto LAB_00049b50;
                    ERR_put_error(0x14,0x88,0x7a,"s3_srvr.c",0xc04);
                    uVar6 = 0x33;
                  }
                }
                else if (pXVar7 == (X509_CINF *)0x74) {
                  iVar4 = DSA_verify((int)pubkey->sig_alg,(uchar *)(param_1[0x16] + 0x1c4),0x14,
                                     puVar9,siglen,(DSA *)((_union_271 *)&pubkey->name)->rsa);
                  if (0 < iVar4) goto LAB_00049b50;
                  ERR_put_error(0x14,0x88,0x70,"s3_srvr.c",0xc14);
                  uVar6 = 0x33;
                }
                else if (pXVar7 == (X509_CINF *)0x198) {
                  iVar4 = ECDSA_verify((int)pubkey->sig_alg,(uchar *)(param_1[0x16] + 0x1c4),0x14,
                                       puVar9,siglen,(EC_KEY *)((_union_271 *)&pubkey->name)->rsa);
                  if (0 < iVar4) goto LAB_00049b50;
                  iVar4 = 0xc25;
LAB_00049bec:
                  ERR_put_error(0x14,0x88,0x131,"s3_srvr.c",iVar4);
                  uVar6 = 0x33;
                }
                else {
                  if ((undefined *)((int)&pXVar7[-0x10].subject + 1U) < (undefined *)0x2) {
                    ctx = EVP_PKEY_CTX_new((EVP_PKEY *)pubkey,(ENGINE *)0x0);
                    EVP_PKEY_verify_init(ctx);
                    if (siglen != 0x40) {
                      __fprintf_chk(stderr,1,"GOST signature length is %d",siglen);
                    }
                    puVar9 = puVar9 + -1;
                    sig = auStack_28;
                    do {
                      puVar9 = puVar9 + 1;
                      sig = sig + -1;
                      *sig = *puVar9;
                    } while (sig != auStack_68);
                    iVar4 = EVP_PKEY_verify(ctx,sig,0x40,(uchar *)(param_1[0x16] + 0x1b4),0x20);
                    EVP_PKEY_CTX_free(ctx);
                    if (iVar4 < 1) {
                      iVar4 = 0xc3c;
                      goto LAB_00049bec;
                    }
LAB_00049b50:
                    iVar4 = param_1[0x16];
                    siglen = 1;
                    goto LAB_00049896;
                  }
                  ERR_put_error(0x14,0x88,0x44,"s3_srvr.c",0xc42);
                  uVar6 = 0x2b;
                }
              }
            }
          }
          else if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
            uVar10 = tls12_get_sigid(pubkey);
            if (uVar10 == 0xffffffff) {
              iVar4 = 0xbad;
LAB_00049c3c:
              ERR_put_error(0x14,0x88,0x44,"s3_srvr.c",iVar4);
              uVar6 = 0x50;
            }
            else if (puVar9[1] == uVar10) {
              siglen = siglen - 2;
              type = (EVP_MD *)tls12_get_hash(*puVar9);
              puVar9 = puVar9 + 2;
              if (type != (EVP_MD *)0x0) goto LAB_000498f6;
              ERR_put_error(0x14,0x88,0x170,"s3_srvr.c",0xbbb);
              uVar6 = 0x32;
            }
            else {
              ERR_put_error(0x14,0x88,0x172,"s3_srvr.c",0xbb4);
              uVar6 = 0x32;
            }
          }
          else {
            type = (EVP_MD *)0x0;
LAB_000498f6:
            uVar10 = siglen - 2;
            siglen = (uint)CONCAT11(*puVar9,puVar9[1]);
            if ((int)siglen <= (int)uVar10) {
              uVar3 = EVP_PKEY_size((EVP_PKEY *)pubkey);
              iVar4 = uVar10 - uVar3;
              uVar1 = uVar10;
              if ((int)uVar10 <= (int)uVar3) {
                iVar4 = siglen - uVar3;
                uVar1 = siglen;
              }
              if ((uVar1 != uVar3 && iVar4 < 0 == SBORROW4(uVar1,uVar3)) || ((int)uVar10 < 1))
              goto LAB_000499be;
              puVar9 = puVar9 + 2;
              goto LAB_0004991e;
            }
            ERR_put_error(0x14,0x88,0x9f,"s3_srvr.c",0xbc9);
            uVar6 = 0x32;
          }
        }
        else {
          ERR_put_error(0x14,0x88,0x85,"s3_srvr.c",0xb96);
          uVar6 = 10;
        }
      }
      else {
        ERR_put_error(0x14,0x88,0xdc,"s3_srvr.c",0xb8f);
        uVar6 = 0x2f;
      }
    }
    else {
      siglen = 1;
      *(undefined4 *)(iVar4 + 0x354) = 1;
      if (-1 < iVar2 << 0x1b) goto LAB_00049896;
      ERR_put_error(0x14,0x88,0xae,"s3_srvr.c",0xb7f);
      uVar6 = 10;
    }
LAB_0004997e:
    ssl3_send_alert(param_1,2,uVar6);
    siglen = 0;
    iVar4 = param_1[0x16];
  }
LAB_00049896:
  if (*(BIO **)(iVar4 + 0x178) != (BIO *)0x0) {
    BIO_free(*(BIO **)(iVar4 + 0x178));
    puVar5 = (uint *)param_1[0x16];
    puVar5[0x5e] = 0;
    *puVar5 = *puVar5 & 0xffffffdf;
  }
  EVP_MD_CTX_cleanup(&EStack_80);
  EVP_PKEY_free((EVP_PKEY *)pXVar8);
LAB_000498be:
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(siglen);
}

