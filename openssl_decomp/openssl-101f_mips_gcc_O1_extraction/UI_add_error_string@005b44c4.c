
int UI_add_error_string(UI *ui,char *text)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  
  if (text == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6d,0x43,"ui_lib.c",0x93);
  }
  else {
    piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x20,"ui_lib.c",0x9a);
    if (piVar2 != (int *)0x0) {
      piVar2[1] = (int)text;
      piVar2[3] = 0;
      piVar2[7] = 0;
      piVar2[2] = 0;
      iVar3 = *(int *)(ui + 4);
      *piVar2 = 5;
      if (iVar3 == 0) {
        iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
        *(int *)(ui + 4) = iVar3;
        if (iVar3 == 0) {
          if (((piVar2[7] & 1U) != 0) &&
             ((*(code *)PTR_CRYPTO_free_006a7f88)(piVar2[1]), *piVar2 == 3)) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2[4]);
            (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2[5]);
            (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2[6]);
          }
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2);
          return -1;
        }
      }
      puVar1 = PTR_sk_push_006a80a8;
      piVar2[4] = 0;
      piVar2[5] = 0;
      piVar2[6] = 0;
      iVar3 = (*(code *)puVar1)(iVar3,piVar2);
      return iVar3 - (uint)(iVar3 < 1);
    }
  }
  return -1;
}

