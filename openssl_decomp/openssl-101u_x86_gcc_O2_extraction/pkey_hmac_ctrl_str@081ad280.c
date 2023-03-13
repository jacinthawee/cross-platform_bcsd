
uint pkey_hmac_ctrl_str(int param_1,byte *param_2,char *param_3)

{
  int iVar1;
  uchar *data;
  uint uVar2;
  byte *pbVar3;
  int in_GS_OFFSET;
  bool bVar4;
  bool bVar5;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 == (char *)0x0) {
    uVar2 = 0;
  }
  else {
    bVar4 = *param_2 < 0x6b;
    bVar5 = *param_2 == 0x6b;
    if (bVar5) {
      bVar4 = param_2[1] < 0x65;
      bVar5 = param_2[1] == 0x65;
      if (bVar5) {
        bVar4 = param_2[2] < 0x79;
        bVar5 = param_2[2] == 0x79;
        if (bVar5) {
          bVar4 = false;
          bVar5 = param_2[3] == 0;
          if (bVar5) {
            iVar1 = ASN1_OCTET_STRING_set((ASN1_STRING *)(*(int *)(param_1 + 0x14) + 4),param_3,-1);
            uVar2 = (uint)(iVar1 != 0);
            goto LAB_081ad2e0;
          }
        }
      }
    }
    iVar1 = 7;
    pbVar3 = (byte *)"hexkey";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_2 < *pbVar3;
      bVar5 = *param_2 == *pbVar3;
      param_2 = param_2 + 1;
      pbVar3 = pbVar3 + 1;
    } while (bVar5);
    uVar2 = (uint)(char)((!bVar4 && !bVar5) - bVar4);
    if (uVar2 == 0) {
      data = string_to_hex(param_3,&local_24);
      if (data != (uchar *)0x0) {
        if (-2 < local_24) {
          iVar1 = ASN1_OCTET_STRING_set((ASN1_STRING *)(*(int *)(param_1 + 0x14) + 4),data,local_24)
          ;
          uVar2 = (uint)(iVar1 != 0);
        }
        CRYPTO_free(data);
      }
    }
    else {
      uVar2 = 0xfffffffe;
    }
  }
LAB_081ad2e0:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

