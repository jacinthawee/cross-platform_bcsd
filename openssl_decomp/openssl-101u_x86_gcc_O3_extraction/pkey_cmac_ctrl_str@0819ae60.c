
uint pkey_cmac_ctrl_str(int param_1,byte *param_2,char *param_3)

{
  size_t keylen;
  uchar *key;
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int in_GS_OFFSET;
  bool bVar5;
  bool bVar6;
  EVP_CIPHER *cipher;
  ENGINE *impl;
  size_t local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 == (char *)0x0) {
LAB_0819af50:
    uVar2 = 0;
  }
  else {
    bVar5 = *param_2 < 0x6b;
    bVar6 = *param_2 == 0x6b;
    if (bVar6) {
      bVar5 = param_2[1] < 0x65;
      bVar6 = param_2[1] == 0x65;
      if (!bVar6) goto LAB_0819aec8;
      bVar5 = param_2[2] < 0x79;
      bVar6 = param_2[2] == 0x79;
      if (!bVar6) goto LAB_0819aec8;
      bVar5 = false;
      bVar6 = param_2[3] == 0;
      if (!bVar6) goto LAB_0819aec8;
      keylen = strlen(param_3);
      if ((int)keylen < 0) goto LAB_0819af50;
      impl = (ENGINE *)0x0;
      cipher = (EVP_CIPHER *)0x0;
    }
    else {
LAB_0819aec8:
      iVar1 = 7;
      pbVar3 = param_2;
      pbVar4 = (byte *)0x820374c;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pbVar3 < *pbVar4;
        bVar6 = *pbVar3 == *pbVar4;
        pbVar3 = pbVar3 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar6);
      if (!bVar6) {
        iVar1 = 7;
        pbVar3 = (byte *)"hexkey";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *param_2 < *pbVar3;
          bVar6 = *param_2 == *pbVar3;
          param_2 = param_2 + 1;
          pbVar3 = pbVar3 + 1;
        } while (bVar6);
        uVar2 = (uint)(char)((!bVar5 && !bVar6) - bVar5);
        if (uVar2 == 0) {
          key = string_to_hex(param_3,(long *)&local_24);
          if (key != (uchar *)0x0) {
            if (-1 < (int)local_24) {
              iVar1 = CMAC_Init(*(CMAC_CTX **)(param_1 + 0x14),key,local_24,(EVP_CIPHER *)0x0,
                                (ENGINE *)0x0);
              uVar2 = (uint)(iVar1 != 0);
            }
            CRYPTO_free(key);
          }
        }
        else {
          uVar2 = 0xfffffffe;
        }
        goto LAB_0819af24;
      }
      cipher = EVP_get_cipherbyname(param_3);
      if (cipher == (EVP_CIPHER *)0x0) goto LAB_0819af50;
      impl = *(ENGINE **)(param_1 + 4);
      keylen = 0;
      param_3 = (char *)0x0;
    }
    iVar1 = CMAC_Init(*(CMAC_CTX **)(param_1 + 0x14),param_3,keylen,cipher,impl);
    uVar2 = (uint)(iVar1 != 0);
  }
LAB_0819af24:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

