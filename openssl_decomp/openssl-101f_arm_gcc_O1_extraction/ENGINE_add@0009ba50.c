
int ENGINE_add(ENGINE *e)

{
  int iVar1;
  uint uVar2;
  char **ppcVar3;
  char *__s2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x69,0x43,"eng_list.c",0x114);
    return 0;
  }
  if ((*(int *)e == 0) || (*(int *)(e + 4) == 0)) {
    ERR_put_error(0x26,0x69,0x6c,"eng_list.c",0x11a);
  }
  CRYPTO_lock(9,0x1e,"eng_list.c",0x11c);
  if (engine_list_head == (char **)0x0) {
    if (engine_list_tail == (ENGINE *)0x0) {
      *(undefined4 *)(e + 0x68) = 0;
      engine_list_head = (char **)e;
      engine_cleanup_add_last(0x9bc59);
LAB_0009bafe:
      iVar1 = 1;
      engine_list_tail = e;
      *(undefined4 *)(e + 0x6c) = 0;
      *(int *)(e + 0x58) = *(int *)(e + 0x58) + 1;
      goto LAB_0009bae0;
    }
    iVar1 = 0x7d;
LAB_0009bab6:
    ERR_put_error(0x26,0x78,0x6e,"eng_list.c",iVar1);
  }
  else {
    __s2 = *(char **)e;
    ppcVar3 = engine_list_head;
    do {
      iVar1 = strcmp(*ppcVar3,__s2);
      ppcVar3 = (char **)ppcVar3[0x1b];
      uVar2 = count_leading_zeroes(iVar1);
    } while (iVar1 != 0 && ppcVar3 != (char **)0x0);
    if (uVar2 >> 5 == 0) {
      if ((engine_list_tail != (ENGINE *)0x0) && (*(int *)(engine_list_tail + 0x6c) == 0)) {
        *(ENGINE **)(engine_list_tail + 0x6c) = e;
        *(ENGINE **)(e + 0x68) = engine_list_tail;
        goto LAB_0009bafe;
      }
      iVar1 = 0x8d;
      goto LAB_0009bab6;
    }
    ERR_put_error(0x26,0x78,0x67,"eng_list.c",0x74);
  }
  iVar1 = 0;
  ERR_put_error(0x26,0x69,0x6e,"eng_list.c",0x120);
LAB_0009bae0:
  CRYPTO_lock(10,0x1e,"eng_list.c",0x123);
  return iVar1;
}

