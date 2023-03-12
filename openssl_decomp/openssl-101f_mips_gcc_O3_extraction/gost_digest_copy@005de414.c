
undefined4 gost_digest_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar7 = *(undefined4 **)(param_1 + 0xc);
  if (puVar7 != (undefined4 *)0x0) {
    puVar1 = *(undefined4 **)(param_2 + 0xc);
    puVar8 = puVar1 + 0x424;
    puVar2 = puVar7;
    if (puVar1 != (undefined4 *)0x0) {
      do {
        uVar6 = *puVar1;
        uVar5 = puVar1[1];
        uVar4 = puVar1[2];
        uVar3 = puVar1[3];
        puVar1 = puVar1 + 4;
        *puVar2 = uVar6;
        puVar2[1] = uVar5;
        puVar2[2] = uVar4;
        puVar2[3] = uVar3;
        puVar2 = puVar2 + 4;
      } while (puVar1 != puVar8);
      puVar7[2] = puVar7 + 0x1c;
    }
  }
  return 1;
}

