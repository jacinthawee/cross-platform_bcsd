
undefined4 dtls1_new(int param_1)

{
  int iVar1;
  undefined4 *ptr;
  pqueue p_Var2;
  uint uVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  iVar1 = ssl3_new(param_1);
  if (iVar1 != 0) {
    ptr = (undefined4 *)CRYPTO_malloc(0x2ec,"d1_lib.c",0x67);
    if (ptr != (undefined4 *)0x0) {
      *ptr = 0;
      ptr[0xba] = 0;
      puVar4 = (undefined4 *)((uint)(ptr + 1) & 0xfffffffc);
      for (uVar3 = (uint)((int)ptr + (0x2ec - (int)(undefined4 *)((uint)(ptr + 1) & 0xfffffffc))) >>
                   2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
      }
      p_Var2 = pqueue_new();
      ptr[0x8e] = p_Var2;
      p_Var2 = pqueue_new();
      ptr[0x90] = p_Var2;
      p_Var2 = pqueue_new();
      ptr[0x91] = p_Var2;
      p_Var2 = pqueue_new();
      ptr[0x92] = p_Var2;
      p_Var2 = pqueue_new();
      iVar1 = *(int *)(param_1 + 0x24);
      ptr[0x94] = p_Var2;
      if (iVar1 != 0) {
        ptr[0x81] = 0x100;
      }
      ptr[0x96] = 0;
      ptr[0x97] = 0;
      if ((pqueue)ptr[0x8e] != (pqueue)0x0) {
        if ((((ptr[0x90] != 0) && (ptr[0x91] != 0)) && (ptr[0x92] != 0)) && (p_Var2 != (pqueue)0x0))
        {
          *(undefined4 **)(param_1 + 0x5c) = ptr;
          (**(code **)(*(int *)(param_1 + 8) + 8))(param_1);
          return 1;
        }
        pqueue_free((pqueue)ptr[0x8e]);
      }
      if ((pqueue)ptr[0x90] != (pqueue)0x0) {
        pqueue_free((pqueue)ptr[0x90]);
      }
      if ((pqueue)ptr[0x91] != (pqueue)0x0) {
        pqueue_free((pqueue)ptr[0x91]);
      }
      if ((pqueue)ptr[0x92] != (pqueue)0x0) {
        pqueue_free((pqueue)ptr[0x92]);
      }
      if ((pqueue)ptr[0x94] != (pqueue)0x0) {
        pqueue_free((pqueue)ptr[0x94]);
      }
      CRYPTO_free(ptr);
    }
  }
  return 0;
}

