
void CRYPTO_gcm128_tag(int param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = *(uint *)(param_1 + 0x38);
  uVar7 = *(uint *)(param_1 + 0x30);
  puVar1 = (undefined4 *)(param_1 + 0x40);
  uVar2 = *(int *)(param_1 + 0x3c) << 3;
  uVar4 = uVar6 << 3;
  uVar3 = *(int *)(param_1 + 0x34) << 3;
  uVar8 = uVar7 << 3;
  if ((*(int *)(param_1 + 0x168) != 0) || (*(int *)(param_1 + 0x16c) != 0)) {
    gcm_gmult_4bit();
  }
  *(uint *)(param_1 + 0x40) =
       *(uint *)(param_1 + 0x40) ^
       (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
       (uVar3 | uVar7 >> 0x1d) << 0x18);
  *(uint *)(param_1 + 0x44) =
       *(uint *)(param_1 + 0x44) ^
       (uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar7 << 0x1b);
  *(uint *)(param_1 + 0x48) =
       *(uint *)(param_1 + 0x48) ^
       (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
       (uVar2 | uVar6 >> 0x1d) << 0x18);
  *(uint *)(param_1 + 0x4c) =
       *(uint *)(param_1 + 0x4c) ^
       (uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar6 << 0x1b);
  gcm_gmult_4bit();
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ *(uint *)(param_1 + 0x2c);
  uVar6 = 0x10;
  if (param_3 < 0x11) {
    uVar6 = param_3;
  }
  if (uVar6 < 4) {
    if ((uVar6 != 0) && (*(undefined *)param_2 = *(undefined *)puVar1, (uVar6 & 2) != 0)) {
      *(undefined2 *)((int)param_2 + (uVar6 - 2)) = *(undefined2 *)(param_1 + 0x3e + uVar6);
    }
  }
  else {
    *param_2 = *puVar1;
    *(undefined4 *)((int)param_2 + (uVar6 - 4)) = *(undefined4 *)(param_1 + 0x3c + uVar6);
    iVar5 = (int)param_2 - ((uint)(param_2 + 1) & 0xfffffffc);
    uVar6 = iVar5 + uVar6 & 0xfffffffc;
    if (3 < uVar6) {
      uVar7 = 0;
      do {
        *(undefined4 *)(((uint)(param_2 + 1) & 0xfffffffc) + uVar7) =
             *(undefined4 *)((int)puVar1 + (uVar7 - iVar5));
        uVar7 = uVar7 + 4;
      } while (uVar7 < uVar6);
    }
  }
  return;
}

