
undefined4 ssl3_release_write_buffer(int param_1)

{
  undefined *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  
  puVar4 = *(uint **)(*(int *)(param_1 + 0x58) + 0xfc);
  if (puVar4 != (uint *)0x0) {
    iVar5 = *(int *)(param_1 + 0xe4);
    uVar6 = *(uint *)(*(int *)(param_1 + 0x58) + 0x100);
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0xc,"s3_both.c",0x2bf);
    puVar1 = PTR_CRYPTO_lock_006a8144;
    puVar2 = *(uint **)(iVar5 + 0x15c);
    if (((puVar2 == (uint *)0x0) ||
        (((uVar6 != *puVar2 && (*puVar2 != 0)) ||
         (uVar3 = puVar2[1], *(uint *)(iVar5 + 0x158) <= uVar3)))) || (uVar6 < 4)) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xc,"s3_both.c",0x2cc);
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0xfc) = 0;
    }
    else {
      *puVar2 = uVar6;
      *puVar4 = puVar2[2];
      puVar2[2] = (uint)puVar4;
      puVar2[1] = uVar3 + 1;
      (*(code *)puVar1)(10,0xc,"s3_both.c");
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0xfc) = 0;
    }
  }
  return 1;
}

