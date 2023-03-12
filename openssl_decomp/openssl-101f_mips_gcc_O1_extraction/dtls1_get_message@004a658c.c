
int dtls1_get_message(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     undefined4 param_5,int *param_6)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  undefined uVar5;
  undefined *puVar6;
  
  iVar2 = param_1[0x16];
  if (*(int *)(iVar2 + 0x354) == 0) {
    iVar2 = param_1[0x17];
    (*(code *)PTR_memset_006aab00)(iVar2 + 0x288,0,0x2c);
    do {
      iVar3 = dtls1_get_message_fragment(param_1,param_2,param_3,param_5,param_6);
    } while (iVar3 + 3U < 2);
    if ((0 < iVar3) || (*param_6 != 0)) {
      iVar3 = *(int *)(iVar2 + 0x28c);
      puVar6 = *(undefined **)(param_1[0xf] + 4);
      *puVar6 = *(undefined *)(iVar2 + 0x288);
      uVar5 = (undefined)((uint)iVar3 >> 0x10);
      puVar6[1] = uVar5;
      uVar4 = (undefined)((uint)iVar3 >> 8);
      puVar6[2] = uVar4;
      puVar6[3] = (char)iVar3;
      puVar6[4] = (char)((ushort)*(undefined2 *)(iVar2 + 0x290) >> 8);
      uVar1 = *(undefined2 *)(iVar2 + 0x290);
      puVar6[6] = 0;
      puVar6[7] = 0;
      puVar6[8] = 0;
      puVar6[5] = (char)uVar1;
      puVar6[9] = uVar5;
      puVar6[10] = uVar4;
      puVar6[0xb] = (char)iVar3;
      if (*param_1 == 0x100) {
        puVar6 = puVar6 + 0xc;
      }
      else {
        iVar3 = iVar3 + 0xc;
      }
      ssl3_finish_mac(param_1,puVar6,iVar3);
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(0,*param_1,0x16,puVar6,iVar3,param_1,param_1[0x1a]);
      }
      (*(code *)PTR_memset_006aab00)(iVar2 + 0x288,0,0x2c);
      iVar2 = param_1[0x17];
      if (*(int *)(iVar2 + 0x254) == 0) {
        *(short *)(iVar2 + 0x228) = *(short *)(iVar2 + 0x228) + 1;
      }
      param_1[0x10] = *(int *)(param_1[0xf] + 4) + 0xc;
      return param_1[0x11];
    }
  }
  else {
    *(undefined4 *)(iVar2 + 0x354) = 0;
    if ((param_4 < 0) || (param_4 == *(int *)(iVar2 + 0x340))) {
      iVar3 = *(int *)(iVar2 + 0x33c);
      iVar2 = *(int *)(param_1[0xf] + 4);
      *param_6 = 1;
      param_1[0x11] = iVar3;
      param_1[0x10] = iVar2 + 0xc;
    }
    else {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xfc,0xf4,"d1_both.c",0x1ae);
      ssl3_send_alert(param_1,2,10);
      iVar3 = -1;
      *param_6 = 0;
    }
  }
  return iVar3;
}

