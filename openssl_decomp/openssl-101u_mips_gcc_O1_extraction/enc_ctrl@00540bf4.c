
int enc_ctrl(int param_1,int param_2,undefined4 param_3,int **param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *outl;
  int iVar3;
  int *piVar4;
  
  outl = *(int **)(param_1 + 0x20);
  if (param_2 == 0xc) {
    piVar4 = param_4[8];
    EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)(piVar4 + 5));
    iVar1 = EVP_CIPHER_CTX_copy((EVP_CIPHER_CTX *)(piVar4 + 5),(EVP_CIPHER_CTX *)(outl + 5));
    if (iVar1 != 0) {
      param_4[3] = (int *)0x1;
      return iVar1;
    }
    return 0;
  }
  if (param_2 < 0xd) {
    if (param_2 == 2) {
      iVar1 = 1;
      iVar3 = outl[2];
      goto joined_r0x00540f0c;
    }
    if (param_2 < 3) {
      if (param_2 == 1) {
        outl[4] = 1;
        outl[3] = 0;
        EVP_CipherInit_ex((EVP_CIPHER_CTX *)(outl + 5),(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                          (uchar *)0x0,outl[7]);
                    /* WARNING: Could not recover jumptable at 0x00540ebc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)(param_1 + 0x24),1,param_3,param_4);
        return iVar1;
      }
      goto LAB_00540ec4;
    }
    if (param_2 != 10) {
      if (param_2 == 0xb) {
        do {
          iVar1 = *outl;
          while( true ) {
            if (iVar1 == outl[1]) {
              do {
                param_2 = 0xb;
                if (outl[3] != 0) {
                  uVar2 = *(undefined4 *)(param_1 + 0x24);
                  goto LAB_00540de4;
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
            piVar4 = *(int **)(param_1 + 0x20);
            (*(code *)PTR_BIO_clear_flags_006a8138)(param_1,0xf);
            iVar1 = piVar4[1];
            iVar3 = *piVar4 - iVar1;
            if (0 < iVar3) break;
            iVar1 = *outl;
          }
          do {
            iVar1 = (*(code *)PTR_BIO_write_006a6e14)
                              (*(undefined4 *)(param_1 + 0x24),(int)piVar4 + iVar1 + 0xa0,iVar3);
            iVar3 = iVar3 - iVar1;
            if (iVar1 < 1) {
              (*(code *)PTR_BIO_copy_next_retry_006a8434)(param_1);
              if (iVar1 != 0) {
                return iVar1;
              }
              break;
            }
            iVar1 = iVar1 + piVar4[1];
            piVar4[1] = iVar1;
          } while (0 < iVar3);
        } while( true );
      }
      goto LAB_00540ec4;
    }
  }
  else {
    if (param_2 == 0x65) {
      (*(code *)PTR_BIO_clear_flags_006a8138)(param_1,0xf);
      iVar1 = (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)(param_1 + 0x24),0x65,param_3,param_4)
      ;
      (*(code *)PTR_BIO_copy_next_retry_006a8434)(param_1);
      return iVar1;
    }
    if (0x65 < param_2) {
      if (param_2 == 0x71) {
        return outl[4];
      }
      if (param_2 == 0x81) {
        *param_4 = outl + 5;
        *(undefined4 *)(param_1 + 0xc) = 1;
        return 1;
      }
LAB_00540ec4:
                    /* WARNING: Could not recover jumptable at 0x00540f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_BIO_ctrl_006a6e18)
                        (*(undefined4 *)(param_1 + 0x24),param_2,param_3,param_4);
      return iVar1;
    }
    if (param_2 != 0xd) goto LAB_00540ec4;
  }
  iVar1 = *outl - outl[1];
  iVar3 = iVar1;
joined_r0x00540f0c:
  if (iVar3 < 1) {
    return iVar1;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x24);
LAB_00540de4:
                    /* WARNING: Could not recover jumptable at 0x00540e0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_BIO_ctrl_006a6e18)(uVar2,param_2,param_3,param_4);
  return iVar1;
}

