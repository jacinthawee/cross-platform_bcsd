
void print_user_part_4(int param_1,BIO *param_2,int param_3,uint param_4)

{
  char **ppcVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  char *__s1;
  
  ppcVar1 = (char **)sk_value(*(_STACK **)(*(int *)(param_1 + 4) + 4),param_3);
  if (**ppcVar1 != 'I') {
    if (param_4 != 0) {
      param_4 = 1;
    }
    if (param_3 < 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = param_4 & 1;
    }
    if (uVar4 != 0) {
      pvVar3 = sk_value(*(_STACK **)(*(int *)(param_1 + 4) + 4),param_3);
      puVar6 = (undefined4 *)((int)pvVar3 + -4);
      BIO_printf(param_2,"%s \"%s\"\n","User entry",*(undefined4 *)((int)pvVar3 + 0xc));
      iVar5 = 0;
      do {
        puVar6 = puVar6 + 1;
        iVar2 = iVar5 + 1;
        BIO_printf(bio_err,"  %d = \"%s\"\n",iVar5,*puVar6);
        iVar5 = iVar2;
      } while (iVar2 != 6);
    }
    __s1 = ppcVar1[4];
    iVar5 = 0;
    if (__s1 == (char *)0x0) {
      return;
    }
    while( true ) {
      iVar2 = sk_num(*(_STACK **)(*(int *)(param_1 + 4) + 4));
      if (iVar2 <= iVar5) {
        return;
      }
      ppcVar1 = (char **)sk_value(*(_STACK **)(*(int *)(param_1 + 4) + 4),iVar5);
      if ((**ppcVar1 == 'I') && (iVar2 = strcmp(__s1,ppcVar1[3]), iVar2 == 0)) break;
      iVar5 = iVar5 + 1;
    }
    if (iVar5 < 0) {
      param_4 = 0;
    }
    else {
      param_4 = param_4 & 1;
    }
    if (param_4 != 0) {
      pvVar3 = sk_value(*(_STACK **)(*(int *)(param_1 + 4) + 4),iVar5);
      puVar6 = (undefined4 *)((int)pvVar3 + -4);
      BIO_printf(param_2,"%s \"%s\"\n","g N entry",*(undefined4 *)((int)pvVar3 + 0xc));
      do {
        puVar6 = puVar6 + 1;
        iVar5 = iVar2 + 1;
        BIO_printf(bio_err,"  %d = \"%s\"\n",iVar2,*puVar6);
        iVar2 = iVar5;
      } while (iVar5 != 6);
    }
  }
  return;
}

