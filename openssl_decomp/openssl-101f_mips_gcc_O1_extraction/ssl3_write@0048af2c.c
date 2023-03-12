
uint ssl3_write(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  puVar2 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  puVar4 = *(uint **)(param_1 + 0x58);
  *puVar2 = 0;
  if (((puVar4[0x65] != 0) && (puVar4[0x3e] == 0)) && (puVar4[0x42] == 0)) {
    uVar3 = (*(code *)PTR_SSL_state_006a88f4)(param_1);
    puVar4 = *(uint **)(param_1 + 0x58);
    if ((uVar3 & 0x3000) == 0) {
      uVar3 = puVar4[0x67];
      *(undefined4 *)(param_1 + 0x34) = 0x3004;
      puVar4[0x65] = 0;
      puVar4[0x67] = uVar3 + 1;
      puVar4[0x66] = puVar4[0x66] + 1;
    }
  }
  if (((*puVar4 & 4) != 0) && (iVar5 = *(int *)(param_1 + 0x10), iVar5 == *(int *)(param_1 + 0x14)))
  {
    if (puVar4[1] == 0) {
      uVar3 = ssl3_write_bytes(param_1,0x17,param_2,param_3);
      if ((int)uVar3 < 1) {
        return uVar3;
      }
      iVar5 = *(int *)(param_1 + 0x10);
      *(uint *)(*(int *)(param_1 + 0x58) + 4) = uVar3;
    }
    puVar1 = PTR_BIO_ctrl_006a7f18;
    *(undefined4 *)(param_1 + 0x18) = 2;
    uVar3 = (*(code *)puVar1)(iVar5,0xb,0,0);
    puVar1 = PTR_ssl_free_wbio_buffer_006a9024;
    if (0 < (int)uVar3) {
      *(undefined4 *)(param_1 + 0x18) = 1;
      (*(code *)puVar1)(param_1);
      puVar4 = *(uint **)(param_1 + 0x58);
      uVar3 = puVar4[1];
      puVar4[1] = 0;
      *puVar4 = *puVar4 & 0xfffffffb;
    }
    return uVar3;
  }
                    /* WARNING: Could not recover jumptable at 0x0048afc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x38))(param_1,0x17,param_2,param_3);
  return uVar3;
}

