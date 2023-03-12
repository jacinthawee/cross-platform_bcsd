
int enc_write(BIO *param_1,uchar *param_2,int param_3)

{
  int *outl;
  int iVar1;
  int *data;
  int iVar2;
  int iVar3;
  int iVar4;
  
  outl = (int *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  iVar4 = outl[1];
  for (iVar3 = *outl - iVar4; 0 < iVar3; iVar3 = iVar3 - iVar2) {
    iVar2 = BIO_write(param_1->next_bio,(void *)((int)outl + iVar4 + 0xa0),iVar3);
    if (iVar2 < 1) {
      BIO_copy_next_retry(param_1);
      return iVar2;
    }
    iVar4 = outl[1] + iVar2;
    outl[1] = iVar4;
  }
  if ((param_2 != (uchar *)0x0) && (0 < param_3)) {
    outl[1] = 0;
    iVar4 = param_3;
    do {
      iVar3 = 0x1000;
      if (iVar4 < 0x1001) {
        iVar3 = iVar4;
      }
      iVar4 = iVar4 - iVar3;
      EVP_CipherUpdate((EVP_CIPHER_CTX *)(outl + 5),(uchar *)(outl + 0x28),outl,param_2,iVar3);
      param_2 = param_2 + iVar3;
      iVar3 = *outl;
      outl[1] = 0;
      data = outl + 0x28;
      if (0 < iVar3) {
        while( true ) {
          iVar2 = BIO_write(param_1->next_bio,data,iVar3);
          if (iVar2 < 1) {
            BIO_copy_next_retry(param_1);
            if (param_3 != iVar4) {
              iVar2 = param_3 - iVar4;
            }
            return iVar2;
          }
          iVar3 = iVar3 - iVar2;
          iVar1 = outl[1];
          outl[1] = iVar2 + iVar1;
          if (iVar3 < 1) break;
          data = (int *)((int)outl + iVar2 + iVar1 + 0xa0);
        }
      }
      *outl = 0;
      outl[1] = 0;
    } while (0 < iVar4);
    BIO_copy_next_retry(param_1);
    return param_3;
  }
  return 0;
}

