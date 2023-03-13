
undefined4 gost_cipher_init(EVP_CIPHER_CTX *param_1,int param_2,void *param_3)

{
  int *piVar1;
  size_t sVar2;
  char *s;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = (int *)param_1->cipher_data;
  if (param_1->app_data == (void *)0x0) {
    s = (char *)get_gost_engine_param(0);
    if ((s == (char *)0x0) || (*s == '\0')) {
      piVar3 = (int *)(gost_cipher_list + 0xc);
      iVar5 = gost_cipher_list._12_4_;
      iVar6 = gost_cipher_list._16_4_;
    }
    else {
      iVar4 = OBJ_txt2nid(s);
      if (iVar4 == 0) {
        ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x97);
        return 0;
      }
      if (gost_cipher_list._4_4_ == 0) {
LAB_081db448:
        ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0xa0);
        return 0;
      }
      piVar3 = (int *)gost_cipher_list;
      iVar5 = gost_cipher_list._0_4_;
      iVar6 = gost_cipher_list._4_4_;
      while (iVar5 != iVar4) {
        iVar6 = piVar3[4];
        if (iVar6 == 0) goto LAB_081db448;
        iVar5 = piVar3[3];
        piVar3 = piVar3 + 3;
      }
    }
    iVar4 = piVar3[2];
    *piVar1 = iVar5;
    piVar1[1] = 0;
    piVar1[2] = iVar4;
    gost_init(piVar1 + 3,iVar6);
    param_1->app_data = param_1->cipher_data;
  }
  if (param_2 != 0) {
    gost_key(piVar1 + 3,param_2);
  }
  if (param_3 != (void *)0x0) {
    sVar2 = EVP_CIPHER_CTX_iv_length(param_1);
    memcpy(param_1->oiv,param_3,sVar2);
  }
  sVar2 = EVP_CIPHER_CTX_iv_length(param_1);
  memcpy(param_1->iv,param_1->oiv,sVar2);
  return 1;
}

