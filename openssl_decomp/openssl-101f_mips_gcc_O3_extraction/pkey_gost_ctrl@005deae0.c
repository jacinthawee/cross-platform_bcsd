
uint pkey_gost_ctrl(undefined4 param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = (uint *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)();
  if (param_2 != 7) {
    if (param_2 < 8) {
      if (param_2 != 2) {
        if (param_2 < 3) {
          if (param_2 == 1) {
            iVar2 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4);
            if (iVar2 != 0x329) {
              (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x7d,0x6c,"gost_pmeth.c",0x51);
              return 0;
            }
            puVar1[1] = param_4;
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
          uVar3 = 1;
          puVar1[3] = 1;
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
        uVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(param_3,"gost_pmeth.c",0x68);
        puVar1[2] = uVar3;
        (*(code *)PTR_memcpy_006aabf4)(uVar3,param_4,param_3);
        return 1;
      }
    }
  }
  return 1;
}

