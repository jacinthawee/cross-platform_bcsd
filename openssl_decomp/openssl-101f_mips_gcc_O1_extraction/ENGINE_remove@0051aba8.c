
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ENGINE_remove(ENGINE *e)

{
  ENGINE *pEVar1;
  ENGINE *pEVar2;
  int iVar3;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x7b,0x43,"eng_list.c",0x12e);
    return 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_list.c",0x131);
  pEVar1 = engine_list_head;
  if (engine_list_head != (ENGINE *)0x0) {
    if (e == engine_list_head) {
LAB_0051ac6c:
      iVar3 = *(int *)(e + 0x6c);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(e + 0x68);
      }
      pEVar2 = *(ENGINE **)(e + 0x68);
      if (pEVar2 != (ENGINE *)0x0) {
        *(int *)(pEVar2 + 0x6c) = iVar3;
      }
      if (e == pEVar1) {
        engine_list_head = *(ENGINE **)(e + 0x6c);
      }
      if (e == engine_list_tail) {
        engine_list_tail = pEVar2;
      }
      iVar3 = 1;
      engine_free_util(e,0);
      goto LAB_0051acc0;
    }
    for (pEVar2 = *(ENGINE **)(engine_list_head + 0x6c); pEVar2 != (ENGINE *)0x0;
        pEVar2 = *(ENGINE **)(pEVar2 + 0x6c)) {
      if (e == pEVar2) goto LAB_0051ac6c;
    }
  }
  iVar3 = 0;
  ERR_put_error(0x26,0x79,0x69,"eng_list.c",0xae);
  ERR_put_error(0x26,0x7b,0x6e,"eng_list.c",0x135);
LAB_0051acc0:
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_list.c",0x138);
  return iVar3;
}

