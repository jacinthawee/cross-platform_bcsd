
undefined4 ssl3_check_cert_and_algorithm(int param_1)

{
  EVP_PKEY *pubkey;
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  RSA *rsa;
  DH *dh;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  uVar4 = *(uint *)(iVar2 + 0x10);
  uVar5 = *(uint *)(iVar2 + 0xc);
  if (((uVar4 & 0x2c) != 0) || ((int)(uVar5 << 0x17) < 0)) {
    return 1;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
  if (iVar2 == 0) {
    ERR_put_error(0x14,0x82,0x44,"s3_clnt.c",0xc71);
    return 0;
  }
  rsa = *(RSA **)(iVar2 + 0x6c);
  dh = *(DH **)(iVar2 + 0x70);
  if (*(int *)(iVar2 + 4) == 5) {
    iVar2 = ssl_check_srvr_ecc_cert_and_alg(*(undefined4 *)(iVar2 + 0x48),param_1);
    if (iVar2 != 0) {
      return 1;
    }
    ERR_put_error(0x14,0x82,0x130,"s3_clnt.c",0xc85);
  }
  else {
    iVar2 = iVar2 + *(int *)(iVar2 + 4) * 0xc;
    pubkey = X509_get_pubkey(*(X509 **)(iVar2 + 0xc));
    uVar1 = X509_certificate_type(*(X509 **)(iVar2 + 0xc),pubkey);
    EVP_PKEY_free(pubkey);
    if (((int)(uVar4 << 0x1f) < 0) && ((uVar1 & 0x11) != 0x11)) {
      ERR_put_error(0x14,0x82,0xaa,"s3_clnt.c",0xc96);
    }
    else if (((int)(uVar4 << 0x1e) < 0) && ((uVar1 & 0x12) != 0x12)) {
      ERR_put_error(0x14,0x82,0xa5,"s3_clnt.c",0xc9c);
    }
    else if ((((uVar5 & 1) == 0) || ((uVar1 & 0x21) == 0x21)) || (rsa != (RSA *)0x0)) {
      if ((((int)(uVar5 << 0x1c) < 0) && ((uVar1 & 0x44) != 0x44)) && (dh == (DH *)0x0)) {
        ERR_put_error(0x14,0x82,0xa3,"s3_clnt.c",0xcac);
      }
      else if (((int)(uVar5 << 0x1e) < 0) && ((uVar1 & 0x104) != 0x104)) {
        ERR_put_error(0x14,0x82,0xa4,"s3_clnt.c",0xcb1);
      }
      else if (((int)(uVar5 << 0x1d) < 0) && ((uVar1 & 0x204) != 0x204)) {
        ERR_put_error(0x14,0x82,0xa2,"s3_clnt.c",0xcb7);
      }
      else {
        if (-1 < *(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) << 0x1e) {
          return 1;
        }
        if ((int)(uVar1 << 0x13) < 0) {
          return 1;
        }
        if ((uVar5 & 1) == 0) {
          if ((uVar5 & 0xe) == 0) {
            ERR_put_error(0x14,0x82,0xfa,"s3_clnt.c",0xcd8);
          }
          else {
            if (dh != (DH *)0x0) {
              iVar2 = DH_size(dh);
              if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) == 0) {
                iVar3 = 0x400;
              }
              else {
                iVar3 = 0x200;
              }
              if (iVar3 + iVar2 * -8 < 0 == SBORROW4(iVar3,iVar2 * 8)) {
                return 1;
              }
            }
            ERR_put_error(0x14,0x82,0xa6,"s3_clnt.c",0xcd1);
          }
        }
        else {
          if (rsa != (RSA *)0x0) {
            iVar2 = RSA_size(rsa);
            if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) == 0) {
              iVar3 = 0x400;
            }
            else {
              iVar3 = 0x200;
            }
            if (iVar3 + iVar2 * -8 < 0 == SBORROW4(iVar3,iVar2 * 8)) {
              return 1;
            }
          }
          ERR_put_error(0x14,0x82,0xa7,"s3_clnt.c",0xcc5);
        }
      }
    }
    else {
      ERR_put_error(0x14,0x82,0xa9,"s3_clnt.c",0xca4);
    }
  }
  ssl3_send_alert(param_1,2,0x28);
  return 0;
}

