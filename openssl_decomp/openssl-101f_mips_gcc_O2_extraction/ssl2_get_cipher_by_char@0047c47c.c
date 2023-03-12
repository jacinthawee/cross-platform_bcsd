
int * ssl2_get_cipher_by_char(byte *param_1)

{
  undefined *puVar1;
  int *piVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined auStack_3c [8];
  uint local_34;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar4 = ssl2_ciphers;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_34 = (uint)*param_1 << 0x10 | param_1[2] | 0x2000000 | (uint)param_1[1] << 8;
  piVar2 = (int *)(*(code *)PTR_OBJ_bsearch_ssl_cipher_id_006a90a0)(auStack_3c,ssl2_ciphers,7);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else if (*piVar2 == 0) {
    piVar2 = (int *)0x0;
  }
  if (local_c == *(int *)puVar1) {
    return piVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (puVar4 == (undefined *)0x0) {
    return (int *)0x3;
  }
  uVar3 = *(uint *)(local_c + 8);
  if ((uVar3 & 0xff000000) != 0x2000000) {
    return (int *)0x0;
  }
  puVar4[2] = (char)uVar3;
  *puVar4 = (char)(uVar3 >> 0x10);
  puVar4[1] = (char)(uVar3 >> 8);
  return (int *)0x3;
}

