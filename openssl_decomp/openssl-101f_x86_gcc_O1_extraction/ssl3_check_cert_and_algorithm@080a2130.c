
undefined4 ssl3_check_cert_and_algorithm(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  RSA *rsa;
  DH *dh;
  EVP_PKEY *pubkey;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  uVar2 = *(uint *)(iVar5 + 0x10);
  if (((uVar2 & 0x2c) != 0) || (uVar3 = *(uint *)(iVar5 + 0xc), (uVar3 & 0x100) != 0)) {
    return 1;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
  if (iVar5 == 0) {
    ERR_put_error(0x14,0x82,0x44,"s3_clnt.c",0xc71);
    return 0;
  }
  if (*(int *)(iVar5 + 4) == 5) {
    iVar5 = ssl_check_srvr_ecc_cert_and_alg(*(undefined4 *)(iVar5 + 0x48),param_1);
    if (iVar5 != 0) {
      return 1;
    }
    ERR_put_error(0x14,0x82,0x130,"s3_clnt.c",0xc85);
  }
  else {
    rsa = *(RSA **)(iVar5 + 0x6c);
    iVar1 = iVar5 + *(int *)(iVar5 + 4) * 0xc;
    dh = *(DH **)(iVar5 + 0x70);
    pubkey = X509_get_pubkey(*(X509 **)(iVar1 + 0xc));
    uVar4 = X509_certificate_type(*(X509 **)(iVar1 + 0xc),pubkey);
    EVP_PKEY_free(pubkey);
    if (((uVar2 & 1) == 0) || ((uVar4 & 0x11) == 0x11)) {
      if (((uVar2 & 2) == 0) || ((uVar4 & 0x12) == 0x12)) {
        if ((((uVar3 & 1) == 0) || ((uVar4 & 0x21) == 0x21)) || (rsa != (RSA *)0x0)) {
          if ((((uVar3 & 8) == 0) || ((uVar4 & 0x44) == 0x44)) || (dh != (DH *)0x0)) {
            if (((uVar3 & 2) == 0) || ((uVar4 & 0x104) == 0x104)) {
              if (((uVar3 & 4) == 0) || ((uVar4 & 0x204) == 0x204)) {
                if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 2) == 0) {
                  return 1;
                }
                if ((uVar4 & 0x1000) != 0) {
                  return 1;
                }
                if ((uVar3 & 1) == 0) {
                  if ((uVar3 & 0xe) == 0) {
                    ERR_put_error(0x14,0x82,0xfa,"s3_clnt.c",0xcd8);
                  }
                  else {
                    if ((dh != (DH *)0x0) &&
                       (iVar5 = DH_size(dh),
                       iVar5 * 8 <=
                       (int)((-(uint)((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20)
                                      & 8) == 0) & 0x200) + 0x200))) {
                      return 1;
                    }
                    ERR_put_error(0x14,0x82,0xa6,"s3_clnt.c",0xcd1);
                  }
                }
                else {
                  if ((rsa != (RSA *)0x0) &&
                     (iVar5 = RSA_size(rsa),
                     iVar5 * 8 <=
                     (int)((-(uint)((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) &
                                    8) == 0) & 0x200) + 0x200))) {
                    return 1;
                  }
                  ERR_put_error(0x14,0x82,0xa7,"s3_clnt.c",0xcc5);
                }
              }
              else {
                ERR_put_error(0x14,0x82,0xa2,"s3_clnt.c",0xcb7);
              }
            }
            else {
              ERR_put_error(0x14,0x82,0xa4,"s3_clnt.c",0xcb1);
            }
          }
          else {
            ERR_put_error(0x14,0x82,0xa3,"s3_clnt.c",0xcac);
          }
        }
        else {
          ERR_put_error(0x14,0x82,0xa9,"s3_clnt.c",0xca4);
        }
      }
      else {
        ERR_put_error(0x14,0x82,0xa5,"s3_clnt.c",0xc9c);
      }
    }
    else {
      ERR_put_error(0x14,0x82,0xaa,"s3_clnt.c",0xc96);
    }
  }
  ssl3_send_alert(param_1,2,0x28);
  return 0;
}

