
uint pkey_gost_ctrl(EVP_PKEY_CTX *param_1,int param_2,uint param_3,EVP_MD *param_4)

{
  uint *puVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  
  puVar1 = (uint *)EVP_PKEY_CTX_get_data(param_1);
  if (param_2 != 7) {
    if (param_2 < 8) {
      if (param_2 != 2) {
        if (param_2 < 3) {
          if (param_2 == 1) {
            iVar2 = EVP_MD_type(param_4);
            if (iVar2 != 0x329) {
              ERR_GOST_error(0x7d,0x6c,"gost_pmeth.c",0x52);
              return 0;
            }
            puVar1[1] = (uint)param_4;
            return 1;
          }
        }
        else if (param_2 < 6) {
          return 1;
        }
        return 0xfffffffe;
      }
      if (1 < param_3) {
        if (param_3 == 2) {
          uVar3 = puVar1[3];
        }
        else {
          if (param_3 != 3) {
            return 0xfffffffe;
          }
          puVar1[3] = 1;
          uVar3 = 1;
        }
        return uVar3;
      }
    }
    else {
      if (0xb < param_2) {
        if (param_2 != 0x1001) {
          return 0xfffffffe;
        }
        *puVar1 = param_3;
        return 1;
      }
      if (param_2 < 9) {
        __dest = CRYPTO_malloc(param_3,"gost_pmeth.c",0x69);
        puVar1[2] = (uint)__dest;
        memcpy(__dest,param_4,param_3);
        return 1;
      }
    }
  }
  return 1;
}

