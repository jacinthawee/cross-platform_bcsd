
int ENGINE_add(ENGINE *e)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x69,0x43,"eng_list.c",0x114);
    return 0;
  }
  if ((*(int *)e == 0) || (*(int *)(e + 4) == 0)) {
    ERR_put_error(0x26,0x69,0x6c,"eng_list.c",0x11a);
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_list.c",0x11c);
  if (engine_list_head == (undefined4 *)0x0) {
    if (engine_list_tail == (ENGINE *)0x0) {
      *(undefined4 *)(e + 0x68) = 0;
      engine_list_head = (undefined4 *)e;
      engine_cleanup_add_last(engine_list_cleanup);
LAB_0051ab0c:
      iVar1 = 1;
      engine_list_tail = e;
      *(undefined4 *)(e + 0x6c) = 0;
      *(int *)(e + 0x58) = *(int *)(e + 0x58) + 1;
      goto LAB_0051aa78;
    }
    ERR_put_error(0x26,0x78,0x6e,"eng_list.c",0x7d);
  }
  else {
    uVar3 = *(undefined4 *)e;
    puVar2 = engine_list_head;
    do {
      iVar1 = (*(code *)PTR_strcmp_006aac20)(*puVar2,uVar3);
      puVar2 = (undefined4 *)puVar2[0x1b];
      if (puVar2 == (undefined4 *)0x0) {
        if (iVar1 != 0) {
          if ((engine_list_tail == (ENGINE *)0x0) || (*(int *)(engine_list_tail + 0x6c) != 0)) {
            ERR_put_error(0x26,0x78,0x6e,"eng_list.c",0x8d);
            goto LAB_0051aa50;
          }
          *(ENGINE **)(engine_list_tail + 0x6c) = e;
          *(ENGINE **)(e + 0x68) = engine_list_tail;
          goto LAB_0051ab0c;
        }
        break;
      }
    } while (iVar1 != 0);
    ERR_put_error(0x26,0x78,0x67,"eng_list.c",0x74);
  }
LAB_0051aa50:
  iVar1 = 0;
  ERR_put_error(0x26,0x69,0x6e,"eng_list.c",0x120);
LAB_0051aa78:
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_list.c",0x123);
  return iVar1;
}

