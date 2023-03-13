
void int_free_ex_data(undefined4 param_1,undefined4 param_2,_STACK **param_3)

{
  int iVar1;
  int mode;
  void *ptr;
  void *pvVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  
  if (ex_data != 0) {
    iVar1 = def_get_class();
    if (iVar1 != 0) {
      CRYPTO_lock(iVar1,5,(char *)0x2,(int)"ex_data.c");
      mode = sk_num(*(_STACK **)(iVar1 + 4));
      if (mode < 1) {
        CRYPTO_lock(mode,6,(char *)0x2,(int)"ex_data.c");
      }
      else {
        ptr = CRYPTO_malloc(mode * 4,"ex_data.c",0x1fe);
        if (ptr == (void *)0x0) {
          CRYPTO_lock(0,6,(char *)0x2,(int)"ex_data.c");
          ERR_put_error(0xf,0x6b,0x41,"ex_data.c",0x207);
          return;
        }
        iVar5 = 0;
        do {
          pvVar2 = sk_value(*(_STACK **)(iVar1 + 4),iVar5);
          *(void **)((int)ptr + iVar5 * 4) = pvVar2;
          iVar5 = iVar5 + 1;
        } while (mode != iVar5);
        uVar7 = 0x205;
        iVar1 = 0;
        pcVar6 = "ex_data.c";
        CRYPTO_lock((int)pvVar2,6,(char *)0x2,(int)"ex_data.c");
        do {
          puVar4 = *(undefined4 **)((int)ptr + iVar1 * 4);
          if ((puVar4 != (undefined4 *)0x0) && (pcVar3 = (code *)puVar4[3], pcVar3 != (code *)0x0))
          {
            if (*param_3 == (_STACK *)0x0) {
              pvVar2 = (void *)0x0;
            }
            else {
              iVar5 = sk_num(*param_3);
              if (iVar1 < iVar5) {
                pvVar2 = sk_value(*param_3,iVar1);
                puVar4 = *(undefined4 **)((int)ptr + iVar1 * 4);
                pcVar3 = (code *)puVar4[3];
              }
              else {
                puVar4 = *(undefined4 **)((int)ptr + iVar1 * 4);
                pvVar2 = (void *)0x0;
                pcVar3 = (code *)puVar4[3];
              }
            }
            (*pcVar3)(param_2,pvVar2,param_3,iVar1,*puVar4,puVar4[1],pcVar6,uVar7);
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < mode);
        CRYPTO_free(ptr);
      }
      if (*param_3 != (_STACK *)0x0) {
        sk_free(*param_3);
        *param_3 = (_STACK *)0x0;
      }
    }
  }
  return;
}

