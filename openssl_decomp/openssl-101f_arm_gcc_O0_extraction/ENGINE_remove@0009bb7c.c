
int ENGINE_remove(ENGINE *e)

{
  ENGINE *pEVar1;
  int iVar2;
  ENGINE *pEVar3;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x7b,0x43,"eng_list.c",0x12e);
    return 0;
  }
  CRYPTO_lock(9,0x1e,"eng_list.c",0x131);
  pEVar1 = engine_list_head;
  pEVar3 = engine_list_head;
  if (e != engine_list_head && engine_list_head != (ENGINE *)0x0) {
    do {
      pEVar3 = *(ENGINE **)(pEVar3 + 0x6c);
    } while (e != pEVar3 && pEVar3 != (ENGINE *)0x0);
  }
  if (pEVar3 == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x79,0x69,"eng_list.c",0xae);
    ERR_put_error(0x26,0x7b,0x6e,"eng_list.c",0x135);
  }
  else {
    iVar2 = *(int *)(e + 0x6c);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(e + 0x68);
    }
    pEVar3 = *(ENGINE **)(e + 0x68);
    if (pEVar3 != (ENGINE *)0x0) {
      *(int *)(pEVar3 + 0x6c) = iVar2;
    }
    if (e == pEVar1) {
      engine_list_head = *(ENGINE **)(e + 0x6c);
    }
    if (e == engine_list_tail) {
      engine_list_tail = pEVar3;
    }
    pEVar3 = (ENGINE *)0x1;
    engine_free_util(e,0);
  }
  CRYPTO_lock(10,0x1e,"eng_list.c",0x138);
  return (int)pEVar3;
}

