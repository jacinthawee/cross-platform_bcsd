
int pkey_gost_mac_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,undefined4 *param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_1c;
  
  if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0')) {
    sVar1 = strlen((char *)param_3);
    if (sVar1 != 0x20) {
      ERR_GOST_error(0x81,0x6f,"gost_pmeth.c",0x204);
      return 0;
    }
    puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
    uVar7 = param_3[1];
    uVar6 = param_3[2];
    uVar5 = param_3[3];
    puVar3[2] = *param_3;
    puVar3[3] = uVar7;
    puVar3[4] = uVar6;
    puVar3[5] = uVar5;
    uVar7 = param_3[5];
    uVar6 = param_3[6];
    uVar5 = param_3[7];
    puVar3[6] = param_3[4];
    puVar3[7] = uVar7;
    puVar3[8] = uVar6;
    puVar3[9] = uVar5;
    *puVar3 = 1;
    return 1;
  }
  iVar2 = strcmp(param_2,"hexkey");
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)string_to_hex((char *)param_3,&local_1c);
    if (local_1c == 0x20) {
      puVar4 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
      uVar7 = puVar3[1];
      uVar6 = puVar3[2];
      uVar5 = puVar3[3];
      puVar4[2] = *puVar3;
      puVar4[3] = uVar7;
      puVar4[4] = uVar6;
      puVar4[5] = uVar5;
      uVar7 = puVar3[5];
      uVar6 = puVar3[6];
      uVar5 = puVar3[7];
      puVar4[6] = puVar3[4];
      puVar4[7] = uVar7;
      puVar4[8] = uVar6;
      puVar4[9] = uVar5;
      *puVar4 = 1;
      CRYPTO_free(puVar3);
      return 1;
    }
    ERR_GOST_error(0x81,0x6f,"gost_pmeth.c",0x211);
    CRYPTO_free(puVar3);
  }
  else {
    iVar2 = -2;
  }
  return iVar2;
}

