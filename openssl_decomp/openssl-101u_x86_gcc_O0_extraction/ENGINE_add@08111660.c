
int __regparm1 ENGINE_add(ENGINE *e)

{
  char **ppcVar1;
  char **in_stack_00000004;
  int iVar2;
  int line;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (in_stack_00000004 == (char **)0x0) {
    line = 0x102;
    iVar2 = 0x43;
LAB_0811174f:
    ERR_put_error(0x26,0x69,iVar2,"eng_list.c",line);
    return 0;
  }
  if ((*in_stack_00000004 == (char *)0x0) || (in_stack_00000004[1] == (char *)0x0)) {
    line = 0x106;
    iVar2 = 0x6c;
    goto LAB_0811174f;
  }
  uVar5 = 0x109;
  pcVar4 = "eng_list.c";
  uVar3 = 0x1e;
  CRYPTO_lock((int)e,9,(char *)0x1e,(int)"eng_list.c");
  if (engine_list_head == (char **)0x0) {
    if (engine_list_tail == (char **)0x0) {
      in_stack_00000004[0x1a] = (char *)0x0;
      engine_list_head = in_stack_00000004;
      e = (ENGINE *)engine_cleanup_add_last(engine_list_cleanup,uVar3,pcVar4,uVar5);
LAB_0811178e:
      in_stack_00000004[0x16] = in_stack_00000004[0x16] + 1;
      engine_list_tail = in_stack_00000004;
      iVar2 = 1;
      in_stack_00000004[0x1b] = (char *)0x0;
      goto LAB_0811171d;
    }
    iVar2 = 0x7b;
LAB_081116ed:
    ERR_put_error(0x26,0x78,0x6e,"eng_list.c",iVar2);
  }
  else {
    pcVar4 = *in_stack_00000004;
    ppcVar1 = engine_list_head;
    do {
      e = (ENGINE *)strcmp(*ppcVar1,pcVar4);
      ppcVar1 = (char **)ppcVar1[0x1b];
      if (ppcVar1 == (char **)0x0) break;
    } while ((char **)e != (char **)0x0);
    if ((char **)e != (char **)0x0) {
      e = (ENGINE *)engine_list_tail;
      if ((engine_list_tail != (char **)0x0) && (engine_list_tail[0x1b] == (char *)0x0)) {
        engine_list_tail[0x1b] = (char *)in_stack_00000004;
        in_stack_00000004[0x1a] = (char *)engine_list_tail;
        goto LAB_0811178e;
      }
      iVar2 = 0x87;
      goto LAB_081116ed;
    }
    ERR_put_error(0x26,0x78,0x67,"eng_list.c",0x75);
  }
  iVar2 = 0;
  ERR_put_error(0x26,0x69,0x6e,"eng_list.c",0x10b);
LAB_0811171d:
  CRYPTO_lock((int)e,10,(char *)0x1e,(int)"eng_list.c");
  return iVar2;
}

