
int enc_write(int param_1,uchar *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *outl;
  int iVar6;
  
  outl = *(int **)(param_1 + 0x20);
  (*(code *)PTR_BIO_clear_flags_006a8138)(param_1,0xf);
  iVar1 = outl[1];
  iVar5 = *outl - iVar1;
  while (0 < iVar5) {
    iVar1 = (*(code *)PTR_BIO_write_006a6e14)
                      (*(undefined4 *)(param_1 + 0x24),(int)outl + iVar1 + 0xa0,iVar5);
    iVar5 = iVar5 - iVar1;
    if (iVar1 < 1) {
      (*(code *)PTR_BIO_copy_next_retry_006a8434)(param_1);
      return iVar1;
    }
    iVar1 = iVar1 + outl[1];
    outl[1] = iVar1;
  }
  if ((param_2 != (uchar *)0x0) && (0 < param_3)) {
    outl[1] = 0;
    iVar1 = param_3;
    do {
      iVar5 = 0x1000;
      if (iVar1 < 0x1001) {
        iVar5 = iVar1;
      }
      iVar1 = iVar1 - iVar5;
      EVP_CipherUpdate((EVP_CIPHER_CTX *)(outl + 5),(uchar *)(outl + 0x28),outl,param_2,iVar5);
      iVar6 = *outl;
      outl[1] = 0;
      piVar4 = outl + 0x28;
      if (0 < iVar6) {
        while( true ) {
          iVar2 = (*(code *)PTR_BIO_write_006a6e14)(*(undefined4 *)(param_1 + 0x24),piVar4,iVar6);
          iVar6 = iVar6 - iVar2;
          if (iVar2 < 1) {
            (*(code *)PTR_BIO_copy_next_retry_006a8434)(param_1);
            if (param_3 == iVar1) {
              return iVar2;
            }
            return param_3 - iVar1;
          }
          iVar3 = outl[1];
          outl[1] = iVar2 + iVar3;
          if (iVar6 < 1) break;
          piVar4 = (int *)((int)outl + iVar2 + iVar3 + 0xa0);
        }
      }
      *outl = 0;
      outl[1] = 0;
      param_2 = param_2 + iVar5;
    } while (0 < iVar1);
    (*(code *)PTR_BIO_copy_next_retry_006a8434)(param_1);
    return param_3;
  }
  return 0;
}

