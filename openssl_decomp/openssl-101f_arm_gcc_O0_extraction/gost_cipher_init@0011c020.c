
undefined4 gost_cipher_init(EVP_CIPHER_CTX *param_1,int param_2,void *param_3)

{
  int *piVar1;
  size_t sVar2;
  char *s;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  
  piVar8 = (int *)param_1->cipher_data;
  if (param_1->app_data == (void *)0x0) {
    s = (char *)get_gost_engine_param();
    if ((s == (char *)0x0) || (*s == '\0')) {
      puVar5 = &DAT_00195a9c;
      iVar3 = DAT_00195a9c;
      puVar4 = PTR_Gost28147_CryptoProParamSetA_00195aa0;
    }
    else {
      iVar3 = OBJ_txt2nid(s);
      if (iVar3 == 0) {
        ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x90);
        return 0;
      }
      puVar5 = &gost_cipher_list;
      if (PTR_GostR3411_94_CryptoProParamSet_00195a94 == (undefined *)0x0) {
LAB_0011c0ca:
        ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0x9c);
        return 0;
      }
      puVar4 = PTR_GostR3411_94_CryptoProParamSet_00195a94;
      puVar7 = puVar5;
      if (iVar3 != gost_cipher_list) {
        do {
          puVar4 = (undefined *)puVar7[4];
          puVar5 = puVar7 + 3;
          if (puVar4 == (undefined *)0x0) goto LAB_0011c0ca;
          piVar1 = puVar7 + 3;
          puVar7 = puVar5;
        } while (iVar3 != *piVar1);
        if (puVar5 == (undefined4 *)0x0) {
          return 0;
        }
      }
    }
    iVar6 = puVar5[2];
    *piVar8 = iVar3;
    piVar8[1] = 0;
    piVar8[2] = iVar6;
    gost_init(piVar8 + 3,puVar4);
    param_1->app_data = param_1->cipher_data;
  }
  if (param_2 != 0) {
    gost_key(piVar8 + 3,param_2);
  }
  if (param_3 != (void *)0x0) {
    sVar2 = EVP_CIPHER_CTX_iv_length(param_1);
    memcpy(param_1->oiv,param_3,sVar2);
  }
  sVar2 = EVP_CIPHER_CTX_iv_length(param_1);
  memcpy(param_1->iv,param_1->oiv,sVar2);
  return 1;
}

