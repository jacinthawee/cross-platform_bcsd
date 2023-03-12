
undefined4 gost_imit_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  puVar2 = *(undefined4 **)(param_2 + 0xc);
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  puVar7 = puVar2 + 0x410;
  do {
    uVar6 = *puVar2;
    uVar5 = puVar2[1];
    uVar4 = puVar2[2];
    uVar3 = puVar2[3];
    puVar2 = puVar2 + 4;
    *puVar1 = uVar6;
    puVar1[1] = uVar5;
    puVar1[2] = uVar4;
    puVar1[3] = uVar3;
    puVar1 = puVar1 + 4;
  } while (puVar2 != puVar7);
  return 1;
}

