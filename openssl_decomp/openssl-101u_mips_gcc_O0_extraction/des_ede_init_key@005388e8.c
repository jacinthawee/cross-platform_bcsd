
undefined4 des_ede_init_key(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  (*(code *)PTR_DES_set_key_unchecked_006a79e8)(param_2,*(undefined4 *)(param_1 + 0x60));
  (*(code *)PTR_DES_set_key_unchecked_006a79e8)(param_2 + 8,*(int *)(param_1 + 0x60) + 0x80);
  puVar1 = *(undefined4 **)(param_1 + 0x60);
  puVar2 = puVar1 + 0x40;
  puVar7 = puVar1 + 0x20;
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
  } while (puVar1 != puVar7);
  return 1;
}

