
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ENGINE_add(ENGINE *e)

{
  int iVar1;
  int reason;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (e == (ENGINE *)0x0) {
    reason = 0x43;
    iVar1 = 0x102;
LAB_00518ba0:
    ERR_put_error(0x26,0x69,reason,"eng_list.c",iVar1);
    return 0;
  }
  if ((*(int *)e == 0) || (*(int *)(e + 4) == 0)) {
    reason = 0x6c;
    iVar1 = 0x106;
    goto LAB_00518ba0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_list.c",0x109);
  if (engine_list_head == (undefined4 *)0x0) {
    if (engine_list_tail == (ENGINE *)0x0) {
      *(undefined4 *)(e + 0x68) = 0;
      engine_list_head = (undefined4 *)e;
      engine_cleanup_add_last(engine_list_cleanup);
LAB_00518c00:
      iVar1 = 1;
      engine_list_tail = e;
      *(undefined4 *)(e + 0x6c) = 0;
      *(int *)(e + 0x58) = *(int *)(e + 0x58) + 1;
      goto LAB_00518b54;
    }
    ERR_put_error(0x26,0x78,0x6e,"eng_list.c",0x7b);
  }
  else {
    uVar3 = *(undefined4 *)e;
    puVar2 = engine_list_head;
    do {
      iVar1 = (*(code *)PTR_strcmp_006a9b18)(*puVar2,uVar3);
      puVar2 = (undefined4 *)puVar2[0x1b];
      if (puVar2 == (undefined4 *)0x0) {
        if (iVar1 != 0) {
          if ((engine_list_tail != (ENGINE *)0x0) && (*(int *)(engine_list_tail + 0x6c) == 0)) {
            *(ENGINE **)(engine_list_tail + 0x6c) = e;
            *(ENGINE **)(e + 0x68) = engine_list_tail;
            goto LAB_00518c00;
          }
          ERR_put_error(0x26,0x78,0x6e,"eng_list.c",0x87);
          goto LAB_00518b2c;
        }
        break;
      }
    } while (iVar1 != 0);
    ERR_put_error(0x26,0x78,0x67,"eng_list.c",0x75);
  }
LAB_00518b2c:
  iVar1 = 0;
  ERR_put_error(0x26,0x69,0x6e,"eng_list.c",0x10b);
LAB_00518b54:
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_list.c",0x10e);
  return iVar1;
}

