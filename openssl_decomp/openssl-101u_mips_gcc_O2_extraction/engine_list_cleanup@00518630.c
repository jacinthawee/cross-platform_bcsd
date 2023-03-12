
void engine_list_cleanup(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (engine_list_head != 0) {
    do {
      iVar1 = engine_list_head;
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_list.c",0x11a);
      iVar2 = engine_list_head;
      if (engine_list_head == 0) {
LAB_005186c4:
        ERR_put_error(0x26,0x79,0x69,"eng_list.c",0xa6);
        ERR_put_error(0x26,0x7b,0x6e,"eng_list.c",0x11c);
      }
      else {
        if (iVar1 != engine_list_head) {
          for (iVar3 = *(int *)(engine_list_head + 0x6c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x6c)
              ) {
            if (iVar1 == iVar3) goto LAB_0051874c;
          }
          goto LAB_005186c4;
        }
LAB_0051874c:
        iVar3 = *(int *)(iVar1 + 0x6c);
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(iVar1 + 0x68);
        }
        iVar4 = *(int *)(iVar1 + 0x68);
        if (iVar4 != 0) {
          *(int *)(iVar4 + 0x6c) = iVar3;
        }
        if (iVar1 == iVar2) {
          engine_list_head = *(int *)(iVar1 + 0x6c);
        }
        if (iVar1 == engine_list_tail) {
          engine_list_tail = iVar4;
        }
        engine_free_util(iVar1,0);
      }
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_list.c",0x11f);
    } while (engine_list_head != 0);
  }
  return;
}

