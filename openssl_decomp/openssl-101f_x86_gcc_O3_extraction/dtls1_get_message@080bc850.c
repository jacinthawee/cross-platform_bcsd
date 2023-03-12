
int dtls1_get_message(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     undefined4 param_5,int *param_6)

{
  short *psVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined uVar5;
  int iVar6;
  uint uVar7;
  undefined uVar8;
  undefined *puVar9;
  undefined4 *puVar10;
  byte bVar11;
  
  bVar11 = 0;
  iVar3 = param_1[0x16];
  if (*(int *)(iVar3 + 0x354) == 0) {
    iVar3 = param_1[0x17];
    puVar10 = (undefined4 *)(iVar3 + 0x28cU & 0xfffffffc);
    *(undefined4 *)(iVar3 + 0x288) = 0;
    *(undefined4 *)(iVar3 + 0x2b0) = 0;
    uVar7 = ((iVar3 + 0x288) - (int)puVar10) + 0x2cU >> 2;
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    do {
      iVar6 = dtls1_get_message_fragment(param_5,param_6);
    } while (iVar6 + 3U < 2);
    if ((0 < iVar6) || (*param_6 != 0)) {
      iVar6 = *(int *)(iVar3 + 0x28c);
      puVar9 = *(undefined **)(param_1[0xf] + 4);
      uVar5 = *(undefined *)(iVar3 + 0x288);
      uVar8 = (undefined)((uint)iVar6 >> 0x10);
      puVar9[1] = uVar8;
      puVar9[3] = (char)iVar6;
      *puVar9 = uVar5;
      uVar5 = (undefined)((uint)iVar6 >> 8);
      puVar9[2] = uVar5;
      puVar9[4] = *(undefined *)(iVar3 + 0x291);
      uVar2 = *(undefined2 *)(iVar3 + 0x290);
      puVar9[10] = uVar5;
      puVar9[6] = 0;
      puVar9[7] = 0;
      puVar9[8] = 0;
      puVar9[9] = uVar8;
      puVar9[0xb] = (char)iVar6;
      puVar9[5] = (char)uVar2;
      if (*param_1 == 0x100) {
        puVar9 = puVar9 + 0xc;
      }
      else {
        iVar6 = iVar6 + 0xc;
      }
      ssl3_finish_mac(param_1,puVar9,iVar6);
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(0,*param_1,0x16,puVar9,iVar6,param_1,param_1[0x1a]);
      }
      *(undefined4 *)(iVar3 + 0x288) = 0;
      *(undefined4 *)(iVar3 + 0x2b0) = 0;
      puVar10 = (undefined4 *)(iVar3 + 0x28cU & 0xfffffffc);
      uVar7 = ((iVar3 + 0x288) - (int)puVar10) + 0x2cU >> 2;
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar10 = 0;
        puVar10 = puVar10 + (uint)bVar11 * -2 + 1;
      }
      if (*(int *)(param_1[0x17] + 0x254) == 0) {
        psVar1 = (short *)(param_1[0x17] + 0x228);
        *psVar1 = *psVar1 + 1;
      }
      param_1[0x10] = *(int *)(param_1[0xf] + 4) + 0xc;
      return param_1[0x11];
    }
  }
  else {
    *(undefined4 *)(iVar3 + 0x354) = 0;
    if ((param_4 < 0) || (param_4 == *(int *)(iVar3 + 0x340))) {
      iVar4 = param_1[0xf];
      iVar6 = *(int *)(iVar3 + 0x33c);
      *param_6 = 1;
      iVar3 = *(int *)(iVar4 + 4);
      param_1[0x11] = iVar6;
      param_1[0x10] = iVar3 + 0xc;
    }
    else {
      ERR_put_error(0x14,0xfc,0xf4,"d1_both.c",0x1ae);
      ssl3_send_alert(param_1,2,10);
      *param_6 = 0;
      iVar6 = -1;
    }
  }
  return iVar6;
}

