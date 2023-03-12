
void __regparm3 print_user_part_3(int param_1_00,BIO *param_2,int param_3,int param_1)

{
  char **ppcVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  
  ppcVar1 = (char **)sk_value(*(_STACK **)(*(int *)(param_1_00 + 4) + 4),param_3);
  if (**ppcVar1 != 'I') {
    if ((-1 < param_3) && (param_1 != 0)) {
      pvVar3 = sk_value(*(_STACK **)(*(int *)(param_1_00 + 4) + 4),param_3);
      BIO_printf(param_2,"%s \"%s\"\n","User entry",*(undefined4 *)((int)pvVar3 + 0xc));
      iVar2 = 0;
      do {
        iVar4 = iVar2 + 1;
        BIO_printf(bio_err,"  %d = \"%s\"\n",iVar2,*(undefined4 *)((int)pvVar3 + iVar2 * 4));
        iVar2 = iVar4;
      } while (iVar4 != 6);
    }
    iVar2 = get_index();
    if ((-1 < iVar2) && (param_1 != 0)) {
      pvVar3 = sk_value(*(_STACK **)(*(int *)(param_1_00 + 4) + 4),iVar2);
      BIO_printf(param_2,"%s \"%s\"\n","g N entry",*(undefined4 *)((int)pvVar3 + 0xc));
      iVar2 = 0;
      do {
        iVar4 = iVar2 + 1;
        BIO_printf(bio_err,"  %d = \"%s\"\n",iVar2,*(undefined4 *)((int)pvVar3 + iVar2 * 4));
        iVar2 = iVar4;
      } while (iVar4 != 6);
    }
  }
  return;
}

