
int enc_ctrl(BIO *param_1,int param_2,long param_3,int **param_4)

{
  BIO *bp;
  int iVar1;
  long lVar2;
  int *piVar3;
  int *outl;
  
  outl = (int *)param_1->ptr;
  if (param_2 == 0xc) {
    piVar3 = param_4[8];
    EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)(piVar3 + 5));
    iVar1 = EVP_CIPHER_CTX_copy((EVP_CIPHER_CTX *)(piVar3 + 5),(EVP_CIPHER_CTX *)(outl + 5));
    if (iVar1 != 0) {
      param_4[3] = (int *)0x1;
    }
  }
  else {
    if (param_2 < 0xd) {
      if (param_2 == 2) {
        if (outl[2] < 1) {
          return 1;
        }
        goto LAB_000ac8a2;
      }
      if (param_2 < 3) {
        if (param_2 == 1) {
          outl[4] = 1;
          outl[3] = 0;
          EVP_CipherInit_ex((EVP_CIPHER_CTX *)(outl + 5),(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                            (uchar *)0x0,(uchar *)0x0,outl[7]);
        }
        goto LAB_000ac8d2;
      }
      if (param_2 != 10) {
        if (param_2 == 0xb) {
          do {
            if (*outl == outl[1]) {
              do {
                if (outl[3] != 0) {
                  bp = param_1->next_bio;
                  param_2 = 0xb;
                  goto LAB_000ac8a4;
                }
                outl[3] = 1;
                outl[1] = 0;
                iVar1 = EVP_CipherFinal_ex((EVP_CIPHER_CTX *)(outl + 5),(uchar *)(outl + 0x28),outl)
                ;
                outl[4] = iVar1;
                if (iVar1 < 1) {
                  return iVar1;
                }
              } while (*outl == outl[1]);
            }
            iVar1 = enc_write(param_1,0,0);
            if (iVar1 < 0) {
              return iVar1;
            }
          } while( true );
        }
        goto LAB_000ac8d2;
      }
    }
    else {
      if (param_2 == 0x65) {
        BIO_clear_flags(param_1,0xf);
        lVar2 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
        BIO_copy_next_retry(param_1);
        return lVar2;
      }
      if (0x65 < param_2) {
        if (param_2 == 0x71) {
          return outl[4];
        }
        if (param_2 == 0x81) {
          *param_4 = outl + 5;
          param_1->init = 1;
          return 1;
        }
LAB_000ac8d2:
        iVar1 = BIO_ctrl(param_1->next_bio,param_2,param_3,param_4);
        return iVar1;
      }
      if (param_2 != 0xd) goto LAB_000ac8d2;
    }
    iVar1 = *outl - outl[1];
    if (iVar1 < 1) {
LAB_000ac8a2:
      bp = param_1->next_bio;
LAB_000ac8a4:
      iVar1 = BIO_ctrl(bp,param_2,param_3,param_4);
      return iVar1;
    }
  }
  return iVar1;
}

