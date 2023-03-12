
int pkey_gost_mac_ctrl_str(EVP_PKEY_CTX *param_1,byte *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  size_t sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  byte *pbVar6;
  int in_GS_OFFSET;
  bool bVar7;
  bool bVar8;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar7 = *param_2 < 0x6b;
  bVar8 = *param_2 == 0x6b;
  if (bVar8) {
    bVar7 = param_2[1] < 0x65;
    bVar8 = param_2[1] == 0x65;
    if (bVar8) {
      bVar7 = param_2[2] < 0x79;
      bVar8 = param_2[2] == 0x79;
      if (bVar8) {
        bVar7 = false;
        bVar8 = param_2[3] == 0;
        if (bVar8) {
          sVar2 = strlen((char *)param_3);
          if (sVar2 == 0x20) {
            puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
            puVar3[2] = *param_3;
            puVar3[3] = param_3[1];
            puVar3[4] = param_3[2];
            puVar3[5] = param_3[3];
            puVar3[6] = param_3[4];
            puVar3[7] = param_3[5];
            puVar3[8] = param_3[6];
            uVar1 = param_3[7];
            iVar5 = 1;
            *puVar3 = 1;
            puVar3[9] = uVar1;
          }
          else {
            iVar5 = 0;
            ERR_GOST_error(0x81,0x6f,"gost_pmeth.c",0x204);
          }
          goto LAB_081ab00e;
        }
      }
    }
  }
  iVar5 = 7;
  pbVar6 = (byte *)"hexkey";
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar7 = *param_2 < *pbVar6;
    bVar8 = *param_2 == *pbVar6;
    param_2 = param_2 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar8);
  iVar5 = (int)(char)((!bVar7 && !bVar8) - bVar7);
  if (iVar5 == 0) {
    puVar3 = (undefined4 *)string_to_hex((char *)param_3,&local_24);
    if (local_24 == 0x20) {
      iVar5 = 1;
      puVar4 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
      puVar4[2] = *puVar3;
      puVar4[3] = puVar3[1];
      puVar4[4] = puVar3[2];
      puVar4[5] = puVar3[3];
      puVar4[6] = puVar3[4];
      puVar4[7] = puVar3[5];
      puVar4[8] = puVar3[6];
      uVar1 = puVar3[7];
      *puVar4 = 1;
      puVar4[9] = uVar1;
      CRYPTO_free(puVar3);
    }
    else {
      ERR_GOST_error(0x81,0x6f,"gost_pmeth.c",0x211);
      CRYPTO_free(puVar3);
    }
  }
  else {
    iVar5 = -2;
  }
LAB_081ab00e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

