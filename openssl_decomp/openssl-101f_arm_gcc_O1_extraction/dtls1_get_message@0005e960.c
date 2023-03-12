
int dtls1_get_message(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     undefined4 param_5,int *param_6)

{
  undefined uVar1;
  undefined2 uVar2;
  undefined uVar3;
  undefined uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  
  iVar5 = param_1[0x16];
  if (*(int *)(iVar5 + 0x354) == 0) {
    iVar5 = param_1[0x17];
    memset((void *)(iVar5 + 0x288),0,0x2c);
    do {
      iVar7 = dtls1_get_message_fragment(param_1,param_2,param_3,param_5,param_6);
    } while (iVar7 + 3U < 2);
    if ((0 < iVar7) || (*param_6 != 0)) {
      iVar7 = *(int *)(iVar5 + 0x28c);
      uVar1 = *(undefined *)(iVar5 + 0x288);
      puVar8 = *(undefined **)(param_1[0xf] + 4);
      uVar3 = (undefined)((uint)iVar7 >> 0x10);
      puVar8[1] = uVar3;
      uVar4 = (undefined)((uint)iVar7 >> 8);
      puVar8[2] = uVar4;
      puVar8[3] = (char)iVar7;
      *puVar8 = uVar1;
      puVar8[4] = (char)((ushort)*(undefined2 *)(iVar5 + 0x290) >> 8);
      uVar2 = *(undefined2 *)(iVar5 + 0x290);
      puVar8[9] = uVar3;
      puVar8[10] = uVar4;
      puVar8[5] = (char)uVar2;
      puVar8[0xb] = (char)iVar7;
      puVar8[6] = 0;
      puVar8[7] = 0;
      puVar8[8] = 0;
      if (*param_1 == 0x100) {
        puVar8 = puVar8 + 0xc;
      }
      else {
        iVar7 = iVar7 + 0xc;
      }
      ssl3_finish_mac(param_1,puVar8,iVar7);
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(0,*param_1,0x16,puVar8,iVar7,param_1,param_1[0x1a]);
      }
      memset((void *)(iVar5 + 0x288),0,0x2c);
      iVar5 = param_1[0x17];
      if (*(int *)(iVar5 + 0x254) == 0) {
        *(short *)(iVar5 + 0x228) = *(short *)(iVar5 + 0x228) + 1;
      }
      param_1[0x10] = *(int *)(param_1[0xf] + 4) + 0xc;
      return param_1[0x11];
    }
  }
  else {
    *(undefined4 *)(iVar5 + 0x354) = 0;
    if ((param_4 < 0) || (*(int *)(iVar5 + 0x340) == param_4)) {
      iVar6 = param_1[0xf];
      iVar7 = *(int *)(iVar5 + 0x33c);
      *param_6 = 1;
      iVar5 = *(int *)(iVar6 + 4);
      param_1[0x11] = iVar7;
      param_1[0x10] = iVar5 + 0xc;
    }
    else {
      ERR_put_error(0x14,0xfc,0xf4,"d1_both.c",0x1ae);
      ssl3_send_alert(param_1,2,10);
      *param_6 = 0;
      iVar7 = -1;
    }
  }
  return iVar7;
}

