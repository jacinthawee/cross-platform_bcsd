
uchar * enc_write(BIO *param_1,uchar *param_2,uchar *param_3,int param_4)

{
  bool bVar1;
  uchar *puVar2;
  int iVar3;
  int *data;
  int *outl;
  int iVar4;
  uchar *puVar5;
  bool bVar6;
  bool bVar7;
  
  outl = (int *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  puVar5 = (uchar *)outl[1];
  iVar4 = *outl - (int)puVar5;
  while (0 < iVar4) {
    puVar5 = (uchar *)BIO_write(param_1->next_bio,puVar5 + 0xa0 + (int)outl,iVar4);
    iVar4 = iVar4 - (int)puVar5;
    if ((int)puVar5 < 1) {
      BIO_copy_next_retry(param_1);
      return puVar5;
    }
    param_4 = outl[1];
    puVar5 = puVar5 + param_4;
    outl[1] = (int)puVar5;
  }
  bVar7 = param_2 == (uchar *)0x0;
  puVar5 = param_2;
  if (!bVar7) {
    puVar5 = param_3;
  }
  bVar6 = (int)puVar5 < 0;
  bVar1 = param_3 == (uchar *)0x0;
  if ((bVar7 || bVar1) || bVar6) {
    param_4 = 1;
  }
  if ((!bVar7 && !bVar1) && !bVar6) {
    param_4 = 0;
  }
  if ((!bVar7 && !bVar1) && !bVar6) {
    outl[1] = param_4;
    puVar5 = param_3;
    do {
      puVar2 = (uchar *)0x1000;
      if ((int)puVar5 < 0x1001) {
        puVar2 = puVar5;
      }
      EVP_CipherUpdate((EVP_CIPHER_CTX *)(outl + 5),(uchar *)(outl + 0x28),outl,param_2,(int)puVar2)
      ;
      iVar4 = *outl;
      outl[1] = param_4;
      puVar5 = puVar5 + -(int)puVar2;
      param_2 = param_2 + (int)puVar2;
      data = outl + 0x28;
      while (0 < iVar4) {
        puVar2 = (uchar *)BIO_write(param_1->next_bio,data,iVar4);
        iVar4 = iVar4 - (int)puVar2;
        if ((int)puVar2 < 1) {
          BIO_copy_next_retry(param_1);
          if (param_3 == puVar5) {
            return puVar2;
          }
          return param_3 + -(int)puVar5;
        }
        iVar3 = outl[1];
        outl[1] = (int)(puVar2 + iVar3);
        data = (int *)((int)outl + (int)(puVar2 + iVar3 + 0xa0));
      }
      *outl = param_4;
      outl[1] = param_4;
    } while (0 < (int)puVar5);
    BIO_copy_next_retry(param_1);
    return param_3;
  }
  return (uchar *)0x0;
}

