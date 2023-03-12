
int enc_read(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *outl;
  int *outm;
  int iVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  outl = *(int **)(param_1 + 0x20);
  if ((outl == (int *)0x0) || (iVar1 = *(int *)(param_1 + 0x24), iVar1 == 0)) {
    return 0;
  }
  if (*outl < 1) {
    if ((0 < param_3) && (iVar3 = 0, 0 < outl[2])) goto LAB_00543a98;
    (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
    (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
  }
  else {
    iVar3 = *outl - outl[1];
    if (param_3 <= iVar3) {
      iVar3 = param_3;
    }
    (*(code *)PTR_memcpy_006aabf4)(param_2,(int)outl + outl[1] + 0xa0,iVar3);
    param_2 = param_2 + iVar3;
    iVar1 = outl[1];
    param_3 = param_3 - iVar3;
    outl[1] = iVar3 + iVar1;
    if (iVar3 + iVar1 == *outl) {
      *outl = 0;
      outl[1] = 0;
    }
    iVar1 = iVar3;
    if ((0 < param_3) && (0 < outl[2])) {
      iVar1 = *(int *)(param_1 + 0x24);
LAB_00543a98:
      outm = outl + 0x28;
      do {
        iVar1 = (*(code *)PTR_BIO_read_006a85bc)(iVar1,outl + 0x38,0x1000);
        if (iVar1 < 1) {
          iVar2 = (*(code *)PTR_BIO_test_flags_006a8954)(*(undefined4 *)(param_1 + 0x24),8);
          if (iVar2 != 0) {
            if (iVar3 != 0) {
              (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
              (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
              return iVar3;
            }
            break;
          }
          outl[2] = iVar1;
          iVar1 = EVP_CipherFinal_ex((EVP_CIPHER_CTX *)(outl + 5),(uchar *)outm,outl);
          iVar2 = *outl;
          outl[4] = iVar1;
          outl[1] = 0;
LAB_00543aec:
          if (param_3 < iVar2) {
            (*(code *)PTR_memcpy_006aabf4)(param_2,outm,param_3);
            iVar1 = iVar3 + param_3;
            outl[1] = param_3;
            break;
          }
          param_3 = param_3 - iVar2;
          iVar1 = iVar3;
          if (iVar2 < 1) break;
          (*(code *)PTR_memcpy_006aabf4)(param_2,outm,iVar2);
          iVar3 = iVar3 + iVar2;
          outl[1] = iVar2;
          param_2 = param_2 + iVar2;
          iVar1 = iVar3;
          if ((param_3 < 1) || (outl[2] < 1)) break;
        }
        else {
          EVP_CipherUpdate((EVP_CIPHER_CTX *)(outl + 5),(uchar *)outm,outl,(uchar *)(outl + 0x38),
                           iVar1);
          iVar2 = *outl;
          outl[2] = 1;
          if (iVar2 != 0) goto LAB_00543aec;
        }
        iVar1 = *(int *)(param_1 + 0x24);
      } while( true );
    }
    (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
    (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return outl[2];
}

