
char * pkey_rsa_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  BIGNUM *local_1c [2];
  
  if (param_3 == (char *)0x0) {
    ERR_put_error(4,0x90,0x93,"rsa_pmeth.c",600);
  }
  else {
    iVar1 = strcmp(param_2,"rsa_padding_mode");
    if (iVar1 == 0) {
      iVar1 = strcmp(param_3,"pkcs1");
      if (iVar1 == 0) {
        iVar1 = 1;
      }
      else {
        iVar1 = strcmp(param_3,"sslv23");
        if (iVar1 == 0) {
          iVar1 = 2;
        }
        else {
          iVar1 = strcmp(param_3,"none");
          if (iVar1 == 0) {
            iVar1 = 3;
          }
          else {
            iVar1 = strcmp(param_3,"oeap");
            if ((iVar1 == 0) || (iVar1 = strcmp(param_3,"oaep"), iVar1 == 0)) {
              iVar1 = 4;
            }
            else {
              iVar1 = strcmp(param_3,"x931");
              if (iVar1 == 0) {
                iVar1 = 5;
              }
              else {
                if ((((*param_3 != 'p') || (param_3[1] != 's')) || (param_3[2] != 's')) ||
                   (param_3[3] != '\0')) {
                  ERR_put_error(4,0x90,0x76,"rsa_pmeth.c",0x26f);
                  return (char *)0xfffffffe;
                }
                iVar1 = 6;
              }
            }
          }
        }
      }
      pcVar2 = (char *)EVP_PKEY_CTX_ctrl(param_1,6,-1,0x1001,iVar1,(void *)0x0);
      return pcVar2;
    }
    iVar1 = strcmp(param_2,"rsa_pss_saltlen");
    if (iVar1 == 0) {
      lVar3 = strtol(param_3,(char **)0x0,10);
      param_3 = (char *)EVP_PKEY_CTX_ctrl(param_1,6,0x18,0x1002,lVar3,(void *)0x0);
    }
    else {
      iVar1 = strcmp(param_2,"rsa_keygen_bits");
      if (iVar1 == 0) {
        lVar3 = strtol(param_3,(char **)0x0,10);
        param_3 = (char *)EVP_PKEY_CTX_ctrl(param_1,6,4,0x1003,lVar3,(void *)0x0);
      }
      else {
        local_1c[0] = (BIGNUM *)strcmp(param_2,"rsa_keygen_pubexp");
        if (local_1c[0] == (BIGNUM *)0x0) {
          param_3 = (char *)BN_asc2bn(local_1c,param_3);
          if ((param_3 != (char *)0x0) &&
             (param_3 = (char *)EVP_PKEY_CTX_ctrl(param_1,6,4,0x1004,0,local_1c[0]),
             (int)param_3 < 1)) {
            BN_free(local_1c[0]);
          }
        }
        else {
          param_3 = (char *)0xfffffffe;
        }
      }
    }
  }
  return param_3;
}

