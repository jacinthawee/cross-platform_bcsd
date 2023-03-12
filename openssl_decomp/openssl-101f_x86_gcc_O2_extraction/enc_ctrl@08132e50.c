
int enc_ctrl(bio_st *param_1,int param_2,long param_3,int **param_4)

{
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var1;
  int *outl;
  int *piVar2;
  int iVar3;
  long lVar4;
  
  outl = (int *)param_1->ptr;
  if (param_2 == 0xc) {
    piVar2 = param_4[8];
    EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)(piVar2 + 5));
    iVar3 = EVP_CIPHER_CTX_copy((EVP_CIPHER_CTX *)(piVar2 + 5),(EVP_CIPHER_CTX *)(outl + 5));
    if (iVar3 == 0) {
      return 0;
    }
    param_4[3] = (int *)0x1;
    return iVar3;
  }
  if (param_2 < 0xd) {
    if (param_2 == 2) {
      if (outl[2] < 1) {
        return 1;
      }
      param_2 = 2;
    }
    else if (param_2 < 3) {
      if (param_2 == 1) {
        outl[4] = 1;
        outl[3] = 0;
        EVP_CipherInit_ex((EVP_CIPHER_CTX *)(outl + 5),(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                          (uchar *)0x0,outl[7]);
        param_2 = 1;
        param_1 = param_1->next_bio;
        goto code_r0x08117ac0;
      }
    }
    else if (param_2 == 10) {
      if (0 < *outl - outl[1]) {
        return *outl - outl[1];
      }
      param_2 = 10;
    }
    else if (param_2 == 0xb) {
      do {
        if (*outl == outl[1]) {
          do {
            if (outl[3] != 0) {
              param_2 = 0xb;
              goto LAB_0813304c;
            }
            outl[3] = 1;
            outl[1] = 0;
            iVar3 = EVP_CipherFinal_ex((EVP_CIPHER_CTX *)(outl + 5),(uchar *)(outl + 0x28),outl);
            outl[4] = iVar3;
            if (iVar3 < 1) {
              return iVar3;
            }
          } while (*outl == outl[1]);
        }
        iVar3 = enc_write(param_1,0,0);
        if (iVar3 < 0) {
          return iVar3;
        }
      } while( true );
    }
  }
  else {
    if (param_2 == 0x65) {
      BIO_clear_flags(param_1,0xf);
      lVar4 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
      BIO_copy_next_retry(param_1);
      return lVar4;
    }
    if (param_2 < 0x66) {
      if (param_2 == 0xd) {
        if (0 < *outl - outl[1]) {
          return *outl - outl[1];
        }
        param_2 = 0xd;
      }
    }
    else {
      if (param_2 == 0x71) {
        return outl[4];
      }
      if (param_2 == 0x81) {
        *param_4 = outl + 5;
        param_1->init = 1;
        return 1;
      }
    }
  }
LAB_0813304c:
  param_1 = param_1->next_bio;
code_r0x08117ac0:
  if (param_1 == (bio_st *)0x0) {
    return 0;
  }
  if ((param_1->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = param_1->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    iVar3 = -2;
  }
  else {
    p_Var1 = param_1->callback;
    if (p_Var1 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08117b57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
      return iVar3;
    }
    iVar3 = (*p_Var1)(param_1,6,(char *)param_4,param_2,param_3,1);
    if (0 < iVar3) {
      lVar4 = (*param_1->method->ctrl)(param_1,param_2,param_3,param_4);
      iVar3 = (*p_Var1)(param_1,0x86,(char *)param_4,param_2,param_3,lVar4);
    }
  }
  return iVar3;
}

